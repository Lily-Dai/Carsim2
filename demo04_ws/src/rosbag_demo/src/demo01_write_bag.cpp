#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"
/*
    需求:使用rosbag向磁盘文件写出数据( 话题 + 消息 )
    流程:
        1.导包;
        2.初始化；
        3.创建rosbag对象
        4.打开文件流
        5.写数据
        6.关闭文件流

*/

int main(int argc, char *argv[])
{
        // 2.初始化；
        setlocale(LC_ALL,"");
        ros::init(argc,argv,"bag_write");
        ros::NodeHandle nh;

        // 3.创建rosbag对象
        rosbag::Bag bag;
        // 4.打开文件流;现在使用的是相对路径
        bag.open("hello.bag",rosbag::BagMode::Write);
        // 5.写数据
        std_msgs::String msg;
        msg.data = "hello xxxx";
        /*
            参数1 话题
            参数2 时间戳
            参数3 消息
        */
        bag.write("/chatter",ros::Time::now(),msg);
        bag.write("/chatter",ros::Time::now(),msg);
        bag.write("/chatter",ros::Time::now(),msg);

        // 6.关闭文件流
        bag.close();
    
    return 0;
}
