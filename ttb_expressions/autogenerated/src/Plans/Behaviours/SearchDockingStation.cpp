using namespace std;
#include "Plans/Behaviours/SearchDockingStation.h"

/*PROTECTED REGION ID(inccpp1414681429307) ENABLED START*/ //Add additional includes here
#include <kdl_conversions/kdl_msg.h>

/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1414681429307) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    SearchDockingStation::SearchDockingStation() :
            DomainBehaviour("SearchDockingStation")
    {
        /*PROTECTED REGION ID(con1414681429307) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    SearchDockingStation::~SearchDockingStation()
    {
        /*PROTECTED REGION ID(dcon1414681429307) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void SearchDockingStation::run(void* msg)
    {
        /*PROTECTED REGION ID(run1414681429307) ENABLED START*/ //Add additional options here
    	shared_ptr<geometry::CNPosition> ownPos = wm->rawSensorData.getOwnPosition();
    	shared_ptr<geometry::CNVelocity2D> pwnVel = wm->rawSensorData.getOwnVelocityMotion();

    	nav_msgs::Odometry odom;
//    	odom.pose.pose.position.x = ownPos

    	KDL::Rotation rot;
        /*PROTECTED REGION END*/
    }
    void SearchDockingStation::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1414681429307) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1414681429307) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
