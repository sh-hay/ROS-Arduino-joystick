#!/bin/bash
set -e

# sudo chmod 666 /dev/js*

# setup ros environment
source "/opt/ros/$ROS_DISTRO/setup.bash"
# source "/home/myUser/my_catkin_ws/devel/setup.bash"

exec "$@"