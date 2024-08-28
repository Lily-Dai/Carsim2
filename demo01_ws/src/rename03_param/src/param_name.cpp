#include "ros/ros.h"

int main(int argc, char *argv[])
{

    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;

    // 1.全局
    ros::param::set("/radiusA",100);

    // 2.相对
    ros::param::set("radiusB",100);
    // 3.私有
    ros::param::set("~radiusC",100);
    /*
        
        使用nodehanle设置参数

    
    */

    //全局
    nh.setParam("/radius_nh_A",1000);
    //相对
    nh.setParam("radius_nh_B",1000);

    //私有
    ros::NodeHandle nh_private("~");
    //nh.
    nh_private.setParam("radius_nh_c",1000);
    return 0;



    return 0;
}