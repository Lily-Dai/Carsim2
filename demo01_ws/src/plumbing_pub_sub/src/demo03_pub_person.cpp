#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("這是消息的發布方");

    ros::init(argc,argv,"banzhuren");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("liaotian",10);
    plumbing_pub_sub::Person person;
    person.name = "張三";
    person.age = 1;
    person.height = 1.73;
    ros::Rate rate(1);
    while (ros::ok()){
        /* code */
        person.age += 1;
        pub.publish(person);
        ROS_INFO("發布的消息：%s,%d,%.2f",person.name.c_str(),person.age,person.height);

        rate.sleep();
        ros::spinOnce();

    }
    


    return 0;



}

