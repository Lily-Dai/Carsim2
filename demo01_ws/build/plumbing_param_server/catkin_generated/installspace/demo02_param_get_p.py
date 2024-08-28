#! /usr/bin/env/python
import rospy

"""
    参数服务器操作之查询_Python实现:    
        get_param(键,默认值)
            当键存在时，返回对应的值，如果不存在返回默认值
        get_param_cached
            和get_param使用一致，只是效率更高
        get_param_names
            获取所有的参数的建的集合

        has_param
            判断是否包含某个建
        search_param
            查找某个参数的建，并返回完整的建名
"""


if __name__ == "__main__":
    rospy.init_node("get_param_p")

    #get_param
    radius = rospy.get_param("radius_p",0.3)
    radius2 = rospy.get_param("radius_pdddd",0.3)
    rospy.loginfo("readius = %.2f",radius)
    rospy.loginfo("readius2 = %.2f",radius2)

    #get_param_cached
    radius3 = rospy.get_param_cached("radius_p",0.3)
    radius4 = rospy.get_param_cached("radius_pdddd",0.3)
    rospy.loginfo("readius3 = %.2f",radius3)
    rospy.loginfo("readius4 = %.2f",radius4)

    #get_param_names
    names = rospy.get_param_names()
    for name in names:
        rospy.loginfo("name = %s",name)

    #has_param
    flag1 = rospy.has_param("radius_p")
    if flag1:
        rospy.loginfo("radius_p 存在")
    else:
        rospy.loginfo("radius_p 不存在")

    flag2 = rospy.has_param("radius_p_XXX")
    if flag2:
        rospy.loginfo("radius_pXXX 存在")
    else:
        rospy.loginfo("radius_pXXX 不存在")

    #search_param
    Key = rospy.search_param("radius_p")
    rospy.loginfo("key = %s", Key)




    
        






    




    pass
