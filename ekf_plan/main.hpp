#include "frontend.hpp"
#include "trackMap.hpp"
    


class mapping {
    public:
        constructor();
        deconstructor();
        
        //initiase ROS features
        create_publisher();
        create_subscriber();

    private:

        // class instances (objects) of frontend / backend class
        object frontend();

        // common code will come from a library
        object EKF_backend();
        object graph_backend();

        // a dedicated class that stores relevant SLAM data such as car position, cone position, respective covariance
        object trackMap();

        



    
    }

Class Frontend() {
    // see frontend.cpp

}

// for the noobs
Class EkfBackend() {


}

Class TrackMap() {


}

// for zain
class GraphBackend() {

    
}