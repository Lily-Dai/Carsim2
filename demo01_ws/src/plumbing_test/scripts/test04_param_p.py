#！ /usr/bin/env python
import rospy
"""
"""
if __name__ == "__main__":
    rospy.init_node("chang_bgcolor_p")
    rospy.set_param("/turtlesim/background_r",252)
    rospy.set_param("/turtlesim/background_g",156)
    rospy.set_param("/turtlesim/background_b",157)
    
                    