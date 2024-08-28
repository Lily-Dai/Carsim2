#include "ros/ros.h"

//演示参数查询
/*
在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle
        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--提高变量获取效率

            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
*/

int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;
    double radius = nh.param("radius",0.5);
    ROS_INFO("RADIOUS = %.2f",radius);
    //getparam
    double radius2 = 0.0;
    bool result = nh.getParam("radius",radius2);
    
    if (result)
    {
        ROS_INFO("获取的半径是：%.2f",radius2);
        
    }else{
        ROS_INFO("被查询的变量不存在");
    }

    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("便利的元素是：%s",name.c_str());
    }


    //hasparam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radius222222");
    ROS_INFO("radius存在吗? %d",flag1);
    ROS_INFO("radius222222? %d",flag2);

    //serchparam
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索的结果是：%s",key.c_str());


    //ros::nodehandle
    double radius_param = ros::param::param("radius",100.4);
    ROS_INFO("radius_param= %.2f",radius_param);

    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);
    for (auto &&name : names_param)
    {

        ROS_INFO("键=%s",name.c_str());
    
    }










    return 0;
}