#!/bin/bash

echo "=========================="
echo "Removing App okayestcontroller"


LIBPANDA_USER=$(cat /etc/libpanda.d/libpanda_usr)

# Disable the installed services:
echo " - Disabling startup scripts..."
systemctl disable okayestcontroller


# Here is where we remove scripts, services, etc.
echo " - Removing scripts..."
cd
if [ "x"`systemctl list-units | grep -c okayestcontroller.service` = "x1" ]; then
    echo "Uninstalling okayestcontroller.service"

    source /home/$LIBPANDA_USER/catkin_ws/devel/setup.bash
    rosrun robot_upstart uninstall okayestcontroller
fi

systemctl daemon-reload # if needed
