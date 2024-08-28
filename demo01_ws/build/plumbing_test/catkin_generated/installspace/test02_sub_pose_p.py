#!/usr/bin/env python3
import rospy
from  turtlesim.msg import Pose

def doPose(pose):
    rospy.loginfo("p->乌龟的位子信息：坐标（%.2f, %.2f）,朝向：%.2f,线速度：%.2f，角速度：%.2f",
                  pose.x, pose.y, pose.theta,pose.linear_velocity,pose.angular_velocity)



if __name__ == "__main__":
    """
        导包
        初始化ros节点
        创建订阅对象
        使用回调函数处理订阅信息
    """

    rospy.init_node("sub_pose_p")
    sub = rospy.Subscriber("/turtle1/pose", Pose, doPose, queue_size= 100)
    rospy.spin()





    pass