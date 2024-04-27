#include "TrackMap.hpp"

#define DYNAMIC -1



class Frontend {

    private:
        TrackMap &data;
        DataAssociatorType DataAssociatorMethod;
        DataAssociator DA;

        // position already transformed into correct frame of reference
        Eigen::Matrix<double, 1, 3> car_estimated_position;
        Eigen::Matrix<double, DYNAMIC, 3> new_cones_position;

    public:
        Frontend(TrackMap database);
        ~Frontend();

        //set data associator type
        void setDataAssociatorType();

        //READ SENSOR DATA AND TRANSFORM INTO STANDARD FRAME OF REFERENCE
        Eigen::Matrix<double, 1, 3> pull_and_process_car_data();
        Eigen::Matrix<double, DYNAMIC, 3> pull_and_process_cone_data();

        //run EKF step on cones if applicable
        void run_EKF_on_cones();    //see definition below for pseudocode


}


Frontend::Frontend(TrackMap database)
{
    data = database;
}

Frontend::~Frontend()
{

}

void Frontend::run_EKF_on_cones()
{
    //pseudocode
    for (cone in this.new_cones_track_frame_data) {
        // associate new sensor data with old data
        associate_output = DA.associate(this.new_cones_track_Frame_data, this.data);

        // check how many times the cone has been seen (previous times stored in trackMap.buffer) to verify "new" cone is indeed a cone.
        if (associate_output = true) {
            EKF_update_function(this.data, cone)
        } else {
            this.data.buffer.append(cone);
        }
        
    }
}