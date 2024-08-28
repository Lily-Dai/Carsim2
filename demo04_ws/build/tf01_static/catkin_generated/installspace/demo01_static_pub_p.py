#!/usr/bin/env python3

import rospy
import tf.transformations
import tf2_ros
from geometry_msgs.msg import TransformStamped
import tf_conversions

"""
    发布方：发布两个坐标系的相对关系（车辆底盘---baselink 和雷达---laser)
    流程：
        1.导包
        2.初始化 ROS 节点
        3.创建 静态坐标广播器
        4.创建并组织被广播的消息
        5.广播器发送消息
        6.spin
"""

if __name__ == "__main__":

    #     2.初始化 ROS 节点
    rospy.init_node("static_pub_p")

    #     3.创建 静态坐标广播器
    pub = tf2_ros.StaticTransformBroadcaster()

    #     4.创建并组织被广播的消息
    ts = TransformStamped()
    # header
    ts.header.stamp = rospy.Time.now()
    ts.header.frame_id = "base_link"

    # child frame
    ts.child_frame_id ="laser"
    # 相对关系（偏移 与 四元数）
    ts.transform.translation.x = 2.0
    ts.transform.translation.y = 0.0
    ts.transform.translation.z = 0.5
    # 4-1.先从欧拉角转换成四元数
    qtn = tf.transformations.quaternion_from_euler(0,0,0)
    # 4-2.再设置四元数
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.x = qtn[1]
    ts.transform.rotation.x = qtn[2]
    ts.transform.rotation.x = qtn[3]

    #     5.广播器发送消息
    pub.sendTransform(ts)
    #     6.spin
    rospy.spin()