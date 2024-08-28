#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"


bool doNums(plumbing_server_client::AddInts::Request &request,
            plumbing_server_client::AddInts::Response &response){
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到的請求數據：num1 = %d, num2 = %d",num1, num2);
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("球和結果：sum =%d ",sum);


    return true;
}



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"heiShui");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addInts",doNums);
    ROS_INFO("服務器端啓動");

    ros::spin();


    return 0;
}