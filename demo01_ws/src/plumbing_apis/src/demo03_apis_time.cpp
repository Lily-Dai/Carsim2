#include "ros/ros.h"
/*
    需求：演示时间相关操作（获取当前时刻，设置指定时刻）
    实现：
        1.准备（头文件、及诶但初始化、node）
        2.获取当前时刻
        3.设置指定时刻
    需求2：程序执行中停顿5s
    实现：
        1.创建持续时间对象
        2.创建停顿时间
    需求3：已知程序开始运行的时刻，和程序运行的时间，求运行结束的时刻
    实现：
        1.获取开始执行的时刻
        2.模拟运行时间（N秒）
        3.计算结束时刻= 开始+持续时间
    注意：
        1.时刻与持续时间之间可以执行加减
        2.持续时间之间可以加减
        3.时刻之间可以相减，不能相加
    需求4： 要求每隔1s在控制台输出一段文本。
    实现：
        策略1：ros::Rate()
        策略2：定时器
    注意：
        创建：nh.creatimer()
        参数1：时间间隔
        参数2：毁掉函数（时间事件 timeevent）
        参数3：是否只执行一次
        参数4：是否自动启动，当为false时，需要手动调用timer.start()
        


*/

//编回调函数
void cb(const ros::TimerEvent& event)
{
    ROS_INFO("---");
    ROS_INFO("函数被调用的时刻：%.2f",event.current_real.toSec());
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc, argv,"hello_time");
    ros::NodeHandle nh;  //注意，必须这么做，否则会导致API调用失败
    //获取当前时刻
    //now函数会将当前时刻封装并返回
    //当前时刻：now被调用执行的时刻
    //参考系：1970年1月1日 00：00：00
    ros::Time right_now = ros::Time::now();

    ROS_INFO("当前时刻：%.2f",right_now.toSec());
    ROS_INFO("当前时刻：%d",right_now.sec);
    //设置指定时间
    ros::Time t1(100.35);
    ROS_INFO("t1=%.2f",t1.toSec());
    
    //-----------------------------------------------------------------
    ROS_INFO("-------------------持续时间-----------------------");
    ros::Time start = ros::Time::now();
    ROS_INFO("开始休眠:%.2f",start.toSec());

    ros::Duration du(4.6);
    du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("休眠结束:%.2f",end.toSec());

    //-----------------------------------------------------------------
    ROS_INFO("----------------------时间运算---------------------------");
    // 1.获取开始执行的时刻
    ros::Time begin = ros::Time::now();
    
    //     2.模拟运行时间（N秒）
    ros::Duration du1(5);
    //     3.计算结束时刻= 开始+持续时间
    ros::Time stop = begin + du1;
    ROS_INFO("开始时刻:%.2f",begin.toSec());
    ROS_INFO("结束时刻:%.2f",stop.toSec());

    //时刻与时刻运算
    // ros::Time sum = begin + stop;  //不可以相加
    ros::Duration du2 = begin -stop;
    ROS_INFO("时刻之间的相减：%.2f",du2.toSec());
    //持续时间与持续时间的运算
    ros::Duration du3 = du1 + du2;
    ros::Duration du4 = du1 - du2;
    ROS_INFO("du1+du2：%.2f",du3.toSec());
    ROS_INFO("du1-du2：%.2f",du4.toSec());
    //-----------------------------------------------------------------
    ROS_INFO("----------------------定时器---------------------------");
    /*
        ros::Timer createTimer(ros::Duration period, // 时间间隔
                     const ros::TimerCallback &callback, //回调函数
                     bool oneshot = false,                  //是否是一次性
                     bool autostart = true) const           //自动启动
    
    */

    ros::Timer time = nh.createTimer(ros::Duration(1),cb,false,false);
    time.start();//手动启动
    ros::spin();//需要回旋





    
   






    return 0;
}