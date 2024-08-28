#include "ros/ros.h"


int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_del_c");
    ros::NodeHandle nh;
    //删除deleteParam还有一个param：：del
    bool flag1 = nh.deleteParam("radius");
    if (flag1)
    {
        ROS_INFO("删除成功！");

        
    }else {
        ROS_INFO("删除失败！");

    }
    //删除deleteParam




    return 0;
}