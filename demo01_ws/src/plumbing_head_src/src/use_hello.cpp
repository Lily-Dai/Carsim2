#include "plumbing_head_src/hello.h"
#include "ros/ros.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_head_src");

    hello_ns::MyHello myHello;
    myHello.run();
    

    


    return 0;
}