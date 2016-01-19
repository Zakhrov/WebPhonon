WebPhonon
=========

Simple Phonon based Video Player written in Qt
WebPhonon now features a full media library that can be deployed on a MySQL server along with an OpenGL Visualization widget for audio.
the visualizer doesnt change with audio (YET) and is just a spinning textured cube

Runtime Dependencies: Qt4, Phonon, kdelibs4 (linux only)
Build Dependencies: cmake, Qt4-dev, Phonon-dev, kdebase4-dev
Ubuntu build dependencies command:
apt-get install cmake libqt4-dev libphonon-dev kdelibs5-dev
OpenSUSE command:
zypper in cmake libqt4-devel phonon-devel libkde4-devel

Download:
git clone https://www.github.com/Zakhrov/WebPhonon.git
Build Instructions:
cd to the directory you cloned WebPhonon to
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr ..
make
execute using ./WebPhonon or run sudo make install for systemwide install
