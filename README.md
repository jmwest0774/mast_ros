# mast_ros
#Installation
Clone this repo into your home directory.
```
git clone https://github.com/jmwest0774/mast_ros.git
```
should have new directory mast_ros
```
cd ~/mast_ros
catkin_make
```
#Gazebo worlds
Many exsisting worlds have been developed for ROS 
#Quadcopter
Ros has a package for generic quadcopters:
```
sudo apt-get install ros-indigo-hector-quadrotor-demo
```
see wiki.ros.org for details
#World Model files
World models are in Collada (.dae) format.
They can be viewed with meshlab (sudo apt-get install meshlab) and edited with Blender.
The ubuntu Blender does not support dae, so get Blender directly from 
[the web page](https://www.blender.org/download/).
