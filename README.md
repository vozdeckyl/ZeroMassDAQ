# Zero Mass Detecotr DAQ


## Installation

Install the necessary packages (cmake, c++ compiler, the GTKmm and Boost libraries)

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

or it can be installed as a desktop application using the following command with root privlidges
```bash
sudo make install
```

The application can be removed by running the following script with root privlidges

```bash
sudo /usr/share/ZeroMassDAQ/uninstall.sh
```
