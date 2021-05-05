# drawbot
This is the code for a self built drawing robot, I seriously doubt anyone could just use this code on a different robot and expect it to work right away. But maybe you can get some inspiration from it.

The drawing robot itself is basically a simple CNC machine. The Qt client uses OpenCV with edge detection to extract the lines which will be drawn.

The firmware of the drawing robot is written for a Arduino Board. The drawing robot uses three stepper motors for X,Y navigation and one for the Z axis.

At the time of writing this the server is basically just a python script which relays gcode instructions to the arduino board through a serial interface. 




## Qt Client Preview
![ClientPreview](docs/assets/edge_detection.gif)

You can use the slider to adjust the threshold of the edge detection algorithm. The different colors illustrate the different lines which will be drawn. Each color is one continous line without the need to lift up the Z-axis.


## Dependencies
- Qt5
- OpenCV
- Arduino libs
- gcc-arm

## How to build

```console
git clone https://github.com/mrom1/drawbot
cd drawbot
cmake -S. -Bbuild
cmake --build build
```

## ToDo
- [ ] Seperate Client, Server and Firmware into different repositories
- [ ] Add Github Actions
- [ ] Add documentation for the robot itself
- [ ] Build a real webserver that can run on a RaspberryPi
