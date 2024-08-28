#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc,char *argv[])
{
    ros::init(argc,argv,"hello");
    // ros::NodeHandle nh;
    //核心：设置不同类型的话题
    //1.全局 ---话题名称需要以 / 开头，这种情况和节点的命名空间以及名称没有关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);

    //2.相对 ---以非 / 开头
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);
    //
    //3.私有 ---需要创建特定的nodehandle
    ros::NodeHandle nh("~");
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);





    while (ros::ok())
    {
        /* code */
    }
    

    return 0;
}