#! /usr/bin/env python
import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse
"""
    需求：向服务器发送请求生成一只乌龟
        话题：/spawn
        消息：turtlesim/Spawn
        导包
        初始化ros节点
        创建订阅对象
        组织数据并发送请求
        使用回调函数处理订阅信息


"""

if __name__ == "__main__":
    #初始化ros节点
    rospy.init_node("service_call_p")

    #创建订阅对象
    client = rospy.ServiceProxy("/spawn",Spawn)
    #组织数据并发送请求，发送前要判断服务器状态

    request = SpawnRequest()
    request.x =  4.5
    request.y = 2.0
    request.theta = -3
    request.name = "turtle2"
    # 判断服务器状态 并发送
    client.wait_for_service()
    

    #处理相应结果
    try:
        response = client.call(request)
        rospy.loginfo("生成乌龟的名字叫：%s",response.name)
    except Exception as e:
        rospy.loginfo("请求异常！")


    
    



    pass