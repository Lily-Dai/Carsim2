execute_process(COMMAND "/home/cwkj/demo05_ws/build/arbotix_ros/arbotix_sensors/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/cwkj/demo05_ws/build/arbotix_ros/arbotix_sensors/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
