#! /usr/bin/env python
import rospy
import rosbag
if __name__ == "__main__":
    rospy.init_node("read_bag_p")
    bag = rosbag.Bag("hello_p.bag","r")
    msgs = bag.read_messages("/liaotian")

    for topic,msg,time in msgs:
        rospy.loginfo("话题:%s,消息:%s,时间:%s",topic,msg.data,time)
    bag.close()