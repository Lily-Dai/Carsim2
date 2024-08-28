#!/usr/bin/env python3

import rospy

if __name__ == "__main__":
    rospy.init_node("del_param_p")
    #防止报异常
    try:

        rospy.delete_param("radius_p")
    except Exception as e:
        rospy.loginfo("被删除的参数不存在")



    pass