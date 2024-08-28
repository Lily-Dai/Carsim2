#!/usr/bin/env python3
import rospy
from plumbing_server_client.srv import AddInts,AddIntsRequest,AddIntsResponse
import sys
"""
優化實現




"""
if __name__ == "__main__":
    
    if len(sys.argv) != 3:
        rospy.logerr("傳入的參數個數不對")
        sys.exit(1)


    rospy.init_node("erHei")
    client = rospy.ServiceProxy("addInts",AddInts)
    rospy.loginfo("客戶端對象創建")
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[1])
    #等待服務啓動命令：
    #有兩種方案，一種需要話題，一種不需要話題
    #client.wait_for_service()
    rospy.wait_for_service("addInts")

    response = client.call(num1,num2)
    rospy.loginfo("打印的字段：%d",response.sum)
    pass