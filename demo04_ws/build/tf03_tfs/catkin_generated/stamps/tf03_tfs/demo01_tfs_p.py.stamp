#! /usr/bin/env python

import rospy
import tf2_ros
from tf2_geometry_msgs import tf2_geometry_msgs
from geometry_msgs.msg import TransformStamped

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
        ps.header.frame_id = "son1"
        ps.point.x = 1.0
        ps.point.y = 2.0
        ps.point.z = 3.0

        # 5.转换逻辑实现，调用TF封装的算法
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            try:
                # 需要计算son1想对于son2的坐标关系
                ts = buffer.lookup_transform("son2","son1",rospy.Time(0))
                rospy.loginfo("son1 相对于 son2 的信息:父级:%s,子级:%s, 偏移量(%.2f,%.2f,%.2f)",
                              ts.header.frame_id,
                              ts.child_frame_id,
                              ts.transform.translation.x,
                              ts.transform.translation.y,
                              ts.transform.translation.z
                              )
                # 转换实现，数据已经寸进了buffer
                
                ps_out = buffer.transform(ps,"son2")
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
                  
                  


          
