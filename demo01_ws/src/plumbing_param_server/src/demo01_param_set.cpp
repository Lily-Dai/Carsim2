#include "ros/ros.h"


int main(int argc, char *argv[])
{
    //初始化ros节点
    ros::init(argc,argv,"set_param_c");


    //创建ROS节点句柄
    ros::NodeHandle nh;
    //参数增---------------
    //方案 1：nh
    nh.setParam("type","xiaohuang");
    nh.setParam("radius",0.15);
    //方案2：ros::param
    ros::param::set("type_param","xiaobai");
    ros::param::set("radius_param",0.15);

    nh.setParam("radius",0.3);
    ros::param::set("radius_param",0.4);


    //参数改---------------






    return 0;
}