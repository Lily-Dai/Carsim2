# Carsim2
主要用于存放仿真代码。完全按照赵虚左老师的教学顺序来定义顺序。使用教程请看:http://www.autolabor.com.cn/book/ROSTutorials/di-2-zhang-ros-jia-gou-she-ji.html

如果大家在学习过程中写不出来可以参考一下,但是需要自己照着敲一遍,这样学得更多。如果大家使用没有问题的话,可以点个star吗:blush::blush::blush:~嘿嘿感谢大家:kissing_closed_eyes::kissing_closed_eyes::kissing_closed_eyes:~

# 坐标变换
使用TF坐标变换,运用静态坐标变换和动态坐标变换。

![如下图所示](https://github.com/Lily-Dai/Carsim2/blob/master/1.gif)
# 建模
使用URDF和XACRO文件,创建带有雷达和摄像头的两轮差速机器人，并在gazebo中渲染。

![如下图所示](https://github.com/Lily-Dai/Carsim2/blob/master/5.png)
# 运动
使用Arbotix包：提供一个差速控制器，通过接受速度控制指令更新机器人的 joint 状态，从而实现机器人在rviz 中的运动。

![如下图所示](https://github.com/Lily-Dai/Carsim2/blob/master/3.gif)
# 地图定位
运用gazebo搭建仿真环境,使用gmapping保存栅格地图,启动键盘控制节点遍历地图,并且使用amcl进行定位机器人位置。
AMCL(adaptive Monte Carlo Localization) 是用于2D移动机器人的概率定位系统，它实现了自适应（或KLD采样）蒙特卡洛定位方法，可以根据已有地图使用粒子滤波器推算机器人位置。

![如下图所示](https://github.com/Lily-Dai/Carsim2/blob/master/2.gif)
# 导航
使用move_base包对机器人进行导航,该包全局规划：用的是A*和D*算法,局部规划用的是DWA。move_base功能包提供了基于动作(action)的路径规划实现，move_base 可以根据给定的目标点，控制机器人底盘运动至目标位置，并且在运动过程中会连续反馈机器人自身的姿态与目标点的状态信息。

![如下图所示](https://github.com/Lily-Dai/Carsim2/blob/master/4.gif)


