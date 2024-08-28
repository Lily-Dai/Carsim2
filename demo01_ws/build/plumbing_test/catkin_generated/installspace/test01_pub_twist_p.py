#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist

"""
    明确消息和话题是什么
     1.导包
     2.初始化ros节点
     3.创建发布者对象
     4.组织数据并且发布数据



"""

if __name__ == "__main__":
    #1.导包
    
    # 2.初始化ros节点
    rospy.init_node("my_control_p")
    # 3.创建发布者对象
    pub = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
    # 4.组织数据并且发布数据
    #循环发布：设置发布频率
    rate = rospy.Rate(10)

    #创建速度消息
    twist = Twist()
    twist.linear.x = 1.0
    twist.linear.y = 0.0
    twist.linear.z = 0.0

    twist.angular.x = 0.0
    twist.angular.y = 0.0
    twist.angular.z = 0.5

    # 循环发布
    while not rospy.is_shutdown():
        pub.publish(twist)
        rate.sleep()
        

    
