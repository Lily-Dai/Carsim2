#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"


int main(int argc, char *argv[])
{
    if (argc !=3)
    {
        /* code */
        ROS_INFO("提交的參數不對。");



    }
    

    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dabao");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    // client.waitForExistence();
    ros::service::waitForService("adiiInts");

    bool flag =client.call(ai);
    if (flag)
    {
        ROS_INFO("響應成功！");
        ROS_INFO("相應幾個： %d",ai.response.sum);




    }else{

        ROS_INFO("處理失敗---");
        
    }


    return 0;
}