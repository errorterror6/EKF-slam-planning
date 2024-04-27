#include "TrackMap.cpp"

#define DYNAMIC -1
typedef Eigen::Matrix<double, DYNAMIC, DYNAMIC> CovMatrix;  // Covariance Matrix "p"
typedef Eigen::Matrix<double, DYNAMIC, 2> KalmanGain;     // Kalman Matrix "k"
typedef Eigen::Matrix<double, 3, DYNAMIC> Jacobian; // Jacobian Matrix "h"
typedef Eigen::Matrix<double, 3, 3> PredictionJacobian; // Jacobian of prediction "A"

class Backend {
    private:
        TrackMap &data;
        // DataAssociatorType DataAssociatorMethod;
        // DataAssociator DA;
        CovMatrix P;
        KalmanGain K;
        Jacobian H;
        PredictionJacobian A;


    public:
=       Backend(TrackMap database);  //should also call initialization methods for matrices.
        ~Backend();

        void initCovMatrix();
        void initKalmanMatrix();
        void initJacobianMatrix();
        void initPredictionJacobianMatrix();










        

    

