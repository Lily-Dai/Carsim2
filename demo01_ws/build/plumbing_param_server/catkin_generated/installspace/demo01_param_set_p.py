#!/usr/bin/env python3

import rospy

"""

演示参数的新增和修改

"""

if __name__ == "__main__":
    #初始化ros节点
    rospy.init_node("param_set_p")
    #新增参数
    
    rospy.set_param("type_p","xiaohuangche")
    rospy.set_param("radius_p",0.15)
    #修改参数
    rospy.set_param("radius_p",0.5)




    pass

