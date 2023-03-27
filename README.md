# Zero Mass Detector DAQ


## Installation

Install the necessary packages (cmake, C++ compiler, the GTKmm and Boost libraries)

```bash
sudo apt install cmake gcc g++ libgtkmm-3.0-dev libboost1.74-dev
```

Create a build directory and compile the project using cmake and make

```bash
mkdir build
cd build
cmake ../
make
```

The software can be either run directly from the folder 

```bash
./zmdaq
```
(Note: when run locally on Raspberry Pi, the following variable needs to be set: `DISPLAY=:0.0`)

or it can be installed as a desktop application using the following command with root privileges
```bash
sudo make install
```

The application can be removed by running the following script with root privileges

```bash
sudo /usr/share/ZeroMassDAQ/uninstall.sh
```
