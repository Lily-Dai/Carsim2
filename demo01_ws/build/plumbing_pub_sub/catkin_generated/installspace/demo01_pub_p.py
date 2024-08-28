#!/usr/bin/env python3
"""
    需求: 实现基本的话题通信，一方发布数据，一方接收数据，
         实现的关键点:
         1.发送方
         2.接收方
         3.数据(此处为普通文本)

         PS: 二者需要设置相同的话题


    消息发布方:
        循环发布信息:HelloWorld 后缀数字编号

    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据


"""
#1.导包 
import os
import sys
import rospy
from std_msgs.msg import String
#设置临时环境变量
# 路径写死，影响了代码的可移植性
# sys.path.insert(0,"/home/cwkj/demo01_ws/src/plumbing_pub_sub/scripts")
# 优化：可以动态获取
path = os.path.abspath(".")
sys.path.insert(0,path + "/src/plumbing_pub_sub/scripts")
import tools


if __name__ == "__main__":
    #2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("talker_p")
    
    # path = os.path.abspath(".")
    # rospy.loginfo("执行时参考的路径：%s",path)
    rospy.loginfo("num = %d",tools.num)
    #3.实例化 发布者 对象
    pub = rospy.Publisher("chatter",String,queue_size=10)
    #4.组织被发布的数据，并编写逻辑发布数据
    msg = String()  #创建 msg 对象
    msg_front = "hello 你好"
    count = 0  #计数器 
    # 设置循环频率
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():

        #拼接字符串
        msg.data = msg_front + str(count)

        pub.publish(msg)
        rate.sleep()
        rospy.loginfo("写出的数据:%s",msg.data)
        count += 1
