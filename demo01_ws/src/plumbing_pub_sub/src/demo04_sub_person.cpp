#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"



void doPerson(const plumbing_pub_sub::Person::ConstPtr& person)
{

    ROS_INFO("订阅的人信息:%s, %d, %.2f", person->name.c_str(), person->age, person->height);
}




int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("訂閱方實現");
    ros::init(argc,argv,"jiaZhang");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("liaotian",10,doPerson);
    ros::spin();








    return 0;


}