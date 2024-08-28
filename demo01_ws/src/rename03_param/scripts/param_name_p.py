#! /usr/bin/env python
import rospy

if __name__ == "__main__":

    rospy.init_node("hello")
    """
        设置不同类型的参数
    """

    # 全局
    rospy.set_param("radiusA",120)


    # 相对
    rospy.set_param("/radiusB",120)


    # 私有
    rospy.set_param("~radiusC",120)

    pass