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
Many exsisting worlds have been developed for ROS.  
install gazebo_ros or hector demo to use their models
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
[the web page](https://www.blender.org/download/).  World files are a pie of .dae for the mesh and .jpg for the texture (image) so you need both. 
The installed models for ros can be found under /opt/ros/indigo/share/hector_gazebo_worlds/Media/models and similar locations.
#Launching
To launch an exsisting model 
```
roslaunch hector_gazebo_worlds rolling_hills_120m.launch
```
or replace hector_gazebo_worlds with another package like gazebo_ros and change th elaunch file name
#Quadrotor
Currently use the hector UAV which is a distrubuted ROS package
[here](http://wiki.asctec.de/display/AR/CAD+Models#CADModels-AscTecHummingbird) is a page with hummingbird moedl and data which we may try to integrate.

