#! /usr/bin/env python
import rospy
from plumbing_pub_sub.msg import Person



def doPerson(p):
    rospy.loginfo("小豁子的數據：%s,%d,%.2f",p.name,p.age,p.height)


if __name__ == "__main__":
    rospy.init_node("daye")
    sub = rospy.Subscriber("jiaoshetou",Person,doPerson)
    rospy.spin()
