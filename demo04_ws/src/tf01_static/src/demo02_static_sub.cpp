#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"  //缓存的头文件
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

/* 
    订阅方：订阅发布的坐标系相对关系，传入一个坐标点，调用tf实现转换

    流程：
        1.包含头文件;
        2.编码、初始化、nodehandle
        3.创建订阅对象 ----->订阅坐标系的相对关系
        4.组织一个坐标的数据;
        5.转换算法，需要调用tf内置实现
    
*/
int main(int argc, char *argv[])
{
    // 2.编码、初始化、nodehandle
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tf_sub");
    ros::NodeHandle nh;
    // 3.创建订阅对象 ----->订阅坐标系的相对关系
    //  3.1 创建一个buffer缓存
    tf2_ros::Buffer buffer;
    //  3.2 再创建监听对象
    tf2_ros::TransformListener listener(buffer);
    // 4.组织一个坐标的数据;
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;
    //添加休眠
    // ros::Duration(2).sleep();


    // 5.转换算法，需要调用tf内置实现
    ros::Rate rate(10);
    while (ros::ok())
    {
      
        // 核心代码  -------将 ps 转换成相对于base_link的坐标点
        geometry_msgs::PointStamped ps_out;
        /*
            调用了buffer的转换函数 transform
            参数1：被转换的坐标点
            参数2：目标坐标系
            返回值：输出的坐标点
            ps1： 注意调用时，必须包含头文件   tf2_geometry_msgs/tf2_geometry_msgs.h
            ps2：运行时存在的问题：会抛出一个异常，base_link不存在
                原因：订阅数据是一个耗时操作，可能在调用transform转换函数时，坐标系的相对关系还没有订阅到
                解决：
                    方案1：在调用转换函数之前先休眠
                    方案2：进行异常处理!!(更建议)
        */



        try
        {
            ps_out = buffer.transform(ps, "base_link");
            // 6.最后输出
            ROS_INFO("转换后的坐标值：(%.2f,%.2f,%.2f),参考的坐标系：%s",
                     ps_out.point.x,
                     ps_out.point.y,
                     ps_out.point.z,
                     ps_out.header.frame_id.c_str()

            );
        }
        catch(const std::exception& e)
        {
            //std::cerr << e.what() << '\n';
            ROS_INFO("异常：%s",e.what());
        }

        rate.sleep();
        ros::spinOnce();
        /* code */
    }
    
    

    
    return 0;
}
