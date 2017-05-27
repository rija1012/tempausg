#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Temperature.h"
void subscriber_callback(const sensor_msgs::Temperature::ConstPtr& receivedMsg) //Funktion, die Temperatur aufruft
{

 if ("[%f]", receivedMsg->temperature < 35.5){
  ROS_INFO("Temperatur: %f Grad C", receivedMsg->temperature);// Ausgabe [%f] Typ float  receivedMsg muss in das temperature-Format geändert werden
}
 else if ("[%f]", receivedMsg->temperature > 35.5){
   ROS_INFO("Temperatur: %f Grad C - kritisch", receivedMsg->temperature);}

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener_node");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("temperature", 1, subscriber_callback);  //ruft Funktion auf und übergibt topic "temperature"

  ros::spin();

  return 0;
}
