WebPhonon
=========

Simple Phonon based Video Player written in QT

Runtime Dependencies: Qt4, Phonon, kdelibs4 (linux only)
Build Dependencies: cmake, Qt4-dev, Phonon-dev, kdebase4-dev
Download:
git clone https://www.github.com/Zakhrov/WebPhonon.git
Build Instructions:
cd to the directory you cloned WebPhonon to
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr ..
make
execute using ./WebPhonon or run sudo make install for systemwide install
