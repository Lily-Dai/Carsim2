#include "ros/ros.h"
#include "turtlesim/Pose.h"

void dePose(const turtlesim::Pose::ConstPtr &pose)
{


    ROS_INFO("小乌龟的威子信息：坐标（%.2f, %.2f）,朝向：%.2f,线速度：%.2f，角速度：%.2f",
            pose->x, pose->y, pose->theta,pose->linear_velocity,pose->angular_velocity);
}


int main(int argc, char *argv[])
{

    //1.包含头文件

    //2.初始化ros节点
        //解决中文乱码问题
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_pose");


    //2.创建节点句柄
    ros::NodeHandle nh;

    //4.创建订阅对象
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,dePose);

    //5.处理订阅到的数据（回调函数）
    //6.spin()
    ros::spin();
    return 0;
}