#include <iostream>
#include "lib/eigen-3.4.0/eigen-3.4.0/Eigen/Dense"

#define DYNAMIC -1

//definition: matrix<type, cols, rows>
typedef Eigen::Matrix<double, DYNAMIC, 1> StateMatrix
typedef Eigen::Matrix<double, DYNAMIC, 3> BufferMatrix
typedef Eigen::Matrix<double, 1, 3> CarPoseMatrix
typedef Eigen::Matrix<double, 1, 2> ConePosMatrix

Class TrackMap () {

    constructor();
    deconstructor();

    //definition: matrix<type, cols, rows>
    //these are typedefs, e.g. typedef Eigen::Matrix<double, DYNAMIC, 1> StateMatrix
    Eigen::Matrix<double, DYNAMIC, 1> state_matrix; //see SLAM for dummies p.30 for what this looks like. {car_x, car_y, car_heading, cone_x, y, x, y ....}
    Eigen::Matrix<double, DYNAMIC, 3> buffer = {x, y}; //buffer to hold potential cones

    //get and update state matrix
    StateMatrix get_state_matrix();

    // returns cone and car position as row vector
    get_car_pose();

    //formula for getting cones is 3+2n, where n is the index of the cone. formula is 2 + 2n, as indexes start from 0.
    get_cone_pos(int index);

    // iterator components for getting cones from the state matrix.
    //internal pointer to current cone
    int currentConeIndex = 0;

    //get next cone
    ConePosMatrix forward();
    //seeks the internal to different points of the iterator
    void start();
    void end();
    void seek(int index);
    int numCones();
    //returns true if there are cones in the state matrix
    bool hasCones();

    //the buffer will have similar code as above, but the formula is simply 2*n, as the buffer only holds cones. -1 for 0 index.
    ConePosMatrix bufferForward();
    void bufferStart();
    void bufferEnd();
    void bufferSeek(int index);
    int numBufferCones();
    bool hasBufferCones();
}

TrackMap::TrackMap()
{
    //constructor
}

TrackMap::~TrackMap()
{
    //deconstructor
}

ConePosMatrix TrackMap::forward()
{
    int num_cones = this.numCones();

    //some error checking regarding index.
    if (num_cones == 0) {
        ConePosMatrix cone = {0, 0};
        fprintf(stderr, "Warning: no cones in state matrix of size %d.\n", this.state_matrix.size());
        return cone;
    }
    if (currentConeIndex >= num_cones) {
        this.currentConeIndex = 0;
    }
    //check if this has to be malloc'd or whatever (hopefully not as remembering to free could be pain)
    ConePosMatrix cone = {this.state_matrix(2 + 2*this.currentConeIndex), this.state_matrix(2 + 2*this.currentConeIndex + 1)};
    this.currentConeIndex++;
    return cone;
}

int TrackMap::numCones()
{
    int size = this.state_matrix.size();

    //special cases and errors
    if (size <= 3) {
        return 0;
    } else if ((size % 2) == 0) {
        fprintf(stderr, "Error: state matrix is incorrectly formed. Size is of unexpected number\n");
        exit(1);
    } 
    return (size - 3) / 2;
    
}