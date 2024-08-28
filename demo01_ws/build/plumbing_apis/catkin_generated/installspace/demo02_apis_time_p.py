#!/usr/bin/env python3
import rospy

"""
    需求1：演示时间相关操作（获取当前时刻+）

    需求2：程序执行中停顿5s

    需求3：获取程序开始执行的时刻，且已知持续运行的时间，计算程序结束的时间

    需求4：创建定时器，实现类似于：ros::Rate 的功能（隔某个时间间隔执行某种操作）



"""


def doMsg(event):
    rospy.loginfo("-----")
    rospy.loginfo("调用回调函数的时刻：%.2f",event.current_real.to_sec())



if __name__ == "__main__":
    rospy.init_node("hello_time")
    #获取时刻
    right_now = rospy.Time.now() #将当前时刻获取并封装成对象
    rospy.loginfo("当前时刻：%.2f",right_now.to_sec())
    rospy.loginfo("当前时刻：%d",right_now.secs)

    #设置指定
    time1 = rospy.Time(100)  #将时间（1970年1月1日 00 00 00逝去100s）封装成Time对象
    time2 = rospy.Time(100,312345678) #将时间（1970年1月1日 00 00 00逝去100.3245678s）封装成Time对象
    rospy.loginfo("指定时刻1：%.2f",time1.to_sec())
    rospy.loginfo("指定时刻2：%.2f",time2.to_sec())

    #从某个时间值获取时间对象
    time3 = rospy.Time.from_sec(210.12)
    rospy.loginfo("指定时刻3：%.2f",time3.to_sec())

    # 需求2：程序执行中停顿5s
    rospy.loginfo("休眠前----------")

    # 1.封装一个持续时间对象 5s
    du = rospy.Duration(5)
    # 2.再将持续时间休眠
    rospy.sleep(du)
    rospy.loginfo("休眠后----------")

    # 需求3：获取程序开始执行的时刻，且已知持续运行的时间，计算程序结束的时间

    #1.获取一个时刻
    t1 = rospy.Time.now()

    #2.设置一个持续时间 t1
    du1 = rospy.Duration(5)
    #3.将t1 + du1 等于t2即结束时刻
    t2 = t1 + du1
    rospy.loginfo("开始时刻：%.2f",t1.to_sec())
    rospy.loginfo("结束时刻：%.2f",t2.to_sec())

    du2 = du + du1
    rospy.loginfo("持续时间：%.2f",du2.to_sec())

    #需求4：创建定时器，实现类似于：ros::Rate 的功能（隔某个时间间隔执行某种操作）
    """
        @param period: desired period between callbacks
        @type  period: rospy.Duration
        @param callback: callback to be called
        @type  callback: function taking rospy.TimerEvent
        @param oneshot: if True, fire only once, otherwise fire continuously until shutdown is called [default: False]
        @type  oneshot: bool
    """
    #true的话只会执行一次
    timer = rospy.Timer(rospy.Duration(1),doMsg)  #s创建一个定时器对象
    rospy.spin()








