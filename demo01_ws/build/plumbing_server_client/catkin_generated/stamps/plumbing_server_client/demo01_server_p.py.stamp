#! /usr/bin/env python
import rospy
from plumbing_server_client.srv import AddInts,AddIntsRequest,AddIntsResponse
#參數：封裝了請求數據
def doNum(request):

    #解析提交的兩個整數
    num1 = request.num1
    num2 =request.num2
    sum = num1 + num2
    #將結果封裝進響應對象
    response = AddIntsResponse()
    response.sum = sum
    rospy.loginfo("服務器解析的數據num1 = %d,num2 = %d,響應的結果:sum = %d", num1, num2, sum)
    return response



if __name__ == "__main__":
    rospy.init_node("heiShui")
    server = rospy.Service("addInts",AddInts,doNum)

    rospy.loginfo("服務器已經啓動了")
    rospy.spin()





