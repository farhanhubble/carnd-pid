# PID Control for Autonomous Car

This repository contains code for controlling the steering and throttle of an autonomous car inside a simulator using a PID update loop.
![PID control loop animation](res/output.gif)

---

## PID Control
PID stands for proportional, integral and derivative. A PID is a simple algorithm that tries to minimize the difference `e` between a desired value `v` and another value `u` by repeatedly updating `u` as 
```
u = u - Kp*e - Kd*e' - Kd*∫e 
```  
where `e'` is the derivate of `e` and `∫e` its integral. These terms are known as proportional(P), integral(I) and derivative(D),hence the name PID.

## PID Implementation.
The PID loop for this project controls the steering angle based on the cross track error (CTE). The code is contained in PID.cpp.
The file main.cpp communicates with the simulator via uWebSockets. More information about installing the simulator and cloning the code and setting up uWebSockets is given in the Installation section below. 

## Tuning the coefficients
The coefficients Kp,Kd and Ki for this project were tuned manually by trial and error. First the best value for Kp was selected while holding Kd and Ki at zero. The car was able to steer around most turns but would sometime go outside the track or swerve sharply. The car also osciallated wildly as it overshot the desired position on the track. To counter this effect the value of Kd was gradually inscreased in steps of 0.1 until the car started moving smoothly. After this the value of Ki was increased until the car stopped overshooting the side lanes. This was done in steps of 0.001. Since the integral term can grow very rapidly, the ideal value for Ki was kept about much smaller than Kp.

The final values of the coefficients were:

|Coefficient | Value  |
|:----------:|:------:| 
| Kp         | 0.1    |
| Ki         | 0.003  |
| Kd         | 1.1    |
---

## Results 
The GIF at the top of this page shows the car driving around the track for one complete lap without any glitches. A better resolution video is available on [Youtube](https://youtu.be/7BDjsNOwHsM).

## Improvements
The best values of the coefficients can be found using online SGD (Stochastic Gradient Descent). The branch `sgd` has some code for SGD but the gradient was waxing and waning alternativly. This could be due to the way the code function has been defined. It will be fixed soon.


## Installation
* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* [Simulator](https://github.com/udacity/self-driving-car-sim/releases).

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.
5. Run the simulator and start Project 4 environment.