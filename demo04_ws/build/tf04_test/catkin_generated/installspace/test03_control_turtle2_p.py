#!/usr/bin/env python3

import rospy
import tf2_ros
from tf2_geometry_msgs import tf2_geometry_msgs
from geometry_msgs.msg import TransformStamped,Twist
import math

if __name__ == "__main__":

        # 1.导包
        # 2.初始化 ROS 节点
        rospy.init_node("static_sub_p")
        # 3.创建 TF 订阅对象
        # 3.1 创建缓存对象
        buffer = tf2_ros.Buffer()
        # 3.2 创建订阅对象
        sub = tf2_ros.TransformListener(buffer)

        # 创建速度消息发布对象
        pub = rospy.Publisher("/turtle2/cmd_vel",Twist,queue_size=100)

        # 4.组织被转换的坐标点
        ps = tf2_geometry_msgs.PointStamped()
        # 时间戳 --0
        ps.header.stamp = rospy.Time(0)
        # 坐标系
        ps.header.frame_id = "son1"
        ps.point.x = 1.0
        ps.point.y = 2.0
        ps.point.z = 3.0

        # 5.转换逻辑实现，调用TF封装的算法
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            try:
                # 需要计算son1想对于son2的坐标关系
                ts = buffer.lookup_transform("turtle2","turtle1",rospy.Time(0))
                rospy.loginfo("son1 相对于 son2 的信息:父级:%s,子级:%s, 偏移量(%.2f,%.2f,%.2f)",
                              ts.header.frame_id,
                              ts.child_frame_id,
                              ts.transform.translation.x,
                              ts.transform.translation.y,
                              ts.transform.translation.z
                              )
                # 组织twist消息
                twist = Twist()
                twist.linear.x = 0.5 * math.sqrt(math.pow(ts.transform.translation.x,2)+math.pow(ts.transform.translation.y,2))
                twist.angular.z = 4 * math.atan2(ts.transform.translation.y,ts.transform.translation.x)

                # 发布消息
                pub.publish(twist)
               
            except Exception as e:
                rospy.logwarn("错误提示：%s",e)

            rate.sleep()
                  
                  


          
