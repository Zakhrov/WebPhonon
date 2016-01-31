WebPhonon
=========
![Splash Screen](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/WebPhonon-Master-text2.png)

Phonon based Video Player written in Qt
----------------------------------------------- 

## Features:
* OpenGL Visualization
![Visualizer](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/visualizer.png)
* MySQL powered Media Library
* 10 band Equalizer (Linux Gstreamer backend Only)
![Equalizer](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/equalizer.png)
* Volume amplifier (can blow your speakers out!)

Screen Shots:
----------------
## Main Interface

## Database Manager


## Runtime Dependencies: 
Qt4, Phonon, kdelibs4 (linux only)
## Build Dependencies: 
cmake, Qt4-dev, Phonon-dev, kdebase4-dev
## Ubuntu build dependencies command:
apt-get install cmake libqt4-dev libphonon-dev kdelibs5-dev
## OpenSUSE command:
zypper in cmake libqt4-devel phonon-devel libkde4-devel

## OpenSUSE Repo
http://software.opensuse.org/package/WebPhonon

## Generic Binary Packages (RPM, DEB and win32 EXE)
http://sourceforge.net/projects/webphonon/

## Build from Source:
* git clone https://www.github.com/Zakhrov/WebPhonon.git
* Build Instructions:
* cd to the directory you cloned WebPhonon to
* mkdir build
* cd build
* cmake -DCMAKE_INSTALL_PREFIX=/usr ..
* make
* execute using ./WebPhonon or run sudo make install for systemwide install
