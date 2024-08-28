#! /usr/bin/env python

import rospy
import tf2_ros
from tf2_geometry_msgs import tf2_geometry_msgs
"""
    订阅方：订阅坐标变换消息，传入被转换的坐标点，调用转换算法

    流程
        1.导包
        2.初始化 ROS 节点
        3.创建 TF 订阅对象
        4.创建一个 radar 坐标系中的坐标点
        5.调研订阅对象的 API 将 4 中的点坐标转换成相对于 world 的坐标
        6.spin
"""

if __name__ == "__main__":

        # 1.导包
        # 2.初始化 ROS 节点
        rospy.init_node("static_sub_p")
        # 3.创建 TF 订阅对象
        # 3.1 创建缓存对象
        buffer = tf2_ros.Buffer()
        # 3.2 创建订阅对象
        sub = tf2_ros.TransformListener(buffer)
        # 4.组织被转换的坐标点
        ps = tf2_geometry_msgs.PointStamped()
        # 时间戳 --0
        ps.header.stamp = rospy.Time(0)
        # 坐标系
        ps.header.frame_id = "turtle1"
        ps.point.x = 2.0
        ps.point.y = 3.0
        ps.point.z = 5.0

        # 5.转换逻辑实现，调用TF封装的算法
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            try:
                # 转换实现，数据已经寸进了buffer
                """
                    参数1：被转换的坐标点
                    参数2：目标坐标系
                    返回值：转换后的坐标点

                    PS：
                    问题：还是抛出base_link不存在
                    原因：转换函数调用时 ，肯呢个还没有订阅到
                    解决：使用try
                
                """
                ps_out = buffer.transform(ps,"world")
                rate.sleep()
                # 6.输出
                rospy.loginfo("转换后的坐标：（%.2f,%.2f,%.2f）,参考的坐标系：%s",
                          ps_out.point.x,
                          ps_out.point.y,
                          ps_out.point.z,
                          ps_out.header.frame_id

                          )
            except Exception as e:
                rospy.logwarn("错误提示：%s",e)

            rate.sleep()
                  
                  


          
