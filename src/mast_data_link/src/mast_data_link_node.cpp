#include <ros/ros.h>

//ROS libraries

//ROS messages
#include <std_msgs/String.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>

#include <iostream>
using namespace std;
//Publishers
ros::Publisher linkStatusPublisher;

//Subscribers
ros::Subscriber roverPoseSubcriber;
ros::Subscriber uavPoseSubcriber;
void roverPoseHandler(const nav_msgs::Odometry::ConstPtr& message);
void uavPoseHandler(const nav_msgs::Odometry::ConstPtr& message);
void publishStatus(void);
geometry_msgs::Pose roverPose;
geometry_msgs::Pose uavPose;

int main(int argc, char **argv) {
    ros::init(argc, argv, "data_link", ros::init_options::NoSigintHandler);
    ros::NodeHandle mNH;

    uavPoseSubcriber = mNH.subscribe("/uav/ground_truth/state", 
			1, roverPoseHandler);
    roverPoseSubcriber = mNH.subscribe("/swarmie/odom", 
			1, uavPoseHandler);
		linkStatusPublisher = mNH.advertise<std_msgs::String>("data_link_status",
			1,true);
	ros::spin();
	return 0;
}

void roverPoseHandler(const nav_msgs::Odometry::ConstPtr& message)
{
	roverPose = message->pose.pose;
	publishStatus();
}
void uavPoseHandler(const nav_msgs::Odometry::ConstPtr& message)
{
	uavPose = message->pose.pose;
	publishStatus();
}
void publishStatus(void)
{
	geometry_msgs::Point p1=roverPose.position;
	geometry_msgs::Point p2=uavPose.position;
	float d = sqrt( (p1.x-p2.x)*(p1.x-p2.x) + 
 (p1.y-p2.y)*(p1.y-p2.y) + 
 (p1.z-p2.z)*(p1.z-p2.z)); 
	ostringstream os;
	os << "Distance: "<<d;
	//<<" Rover "<<roverPose<<" uav " <<uavPose;
	std_msgs::String msg;
	msg.data = os.str();
	linkStatusPublisher.publish(msg);
}
