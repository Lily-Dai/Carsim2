#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    //导入头文件


    //1,初始化ros节点
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"service_call");
    //3.创建节点句柄
    ros::NodeHandle nh;
    //4.创建客户端对象
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    //5.组织数据并发布
        //组织数据
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
        //发送数据
            //判断服务器状态
    //ros::service::waitForService("/spawn");
    client.waitForExistence();
    bool flag = client.call(spawn);  //flag 接受响应状态

    if (flag)
    {
        ROS_INFO("乌龟生成成功，新乌龟叫：%s",spawn.response.name.c_str());


    }else{
        ROS_INFO("请求失败！！！");
    }




}