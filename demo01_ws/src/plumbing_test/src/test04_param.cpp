#include "ros/ros.h"

/*
    需求：修改背景颜色


*/

int main(int argc, char *argv[])
{
    //初始化ros节点
    ros::init(argc,argv ,"change_bgColor");
    //不一定需要创建节点句柄
    //nodehandle其实就相当与是一级话题
    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r",252);
    nh.setParam("background_g",156);
    nh.setParam("background_b",157);


    //修改参数
    //如果调用ros::param不需要创建节点句柄
    //ros::param::set("/turtlesim/background_r",252);
    //ros::param::set("/turtlesim/background_g",156);
    //ros::param::set("/turtlesim/background_b",157);




    return 0;
}