# nest

Noble Element Simulation Technique (nest) is used to simulate noble-element energy deposition microphysics.

These instructions refer only to the PETALO application. For a full README, go to the [NEST repository] (https://github.com/NESTCollaboration/nest).


### Table of Contents

1. [ Getting the Repository ](#get)
2. [ Building NEST ](#build)
	* [ Prerequisites ](#prereq)
	* [ Running CMake ](#config)
	* [ Compiling NEST ](#compile)


<a name="get"></a>
## Getting the Repository

In the terminal, one can clone this repository by typing the command:

`git clone https://github.com/petalo-project/nest.git`

This uses the HTTPS protocol.


<a name="build"></a>
## Building NEST

<a name="prereq"></a>
### Prerequisites

In order to compile and run NEST, the following are required:

* CMake 3.8 (or higher: tested with 3.17.5 on Linux CentOS 7 and 3.21.3 on Mac OSX 10.14.6)
* gcc (with C++17 support or at the very least C++11, with GCC 5 or higher; tested with 8.3.1-9.4.0 on Linux and Apple LLVM version 10.0.1, clang-1001.0.46.4)

For the PETALO application, GEANT4 is also required:

* GEANT4 (version >= Geant4.11.1.1 is recommended)


<a name="config"></a>
### Running CMake

1. Make empty build and install directories somewhere outside the NEST source code directory, 
	and go to the build directory. 

	For example, from the source code directory: 

	```
	mkdir ../build; mkdir ../install; cd ../build
	```

2. From within the build directory, configure CMake. On systems where the C compiler/C++ compiler 
	paths are already specified, one can simply do (sometimes not cmake but cmake3 e.g. on Kitware on CentOS 7):


	```
	cmake -DG4=ON -DCMAKE_INSTALL_PREFIX=[path to install directory] ../relative/path/nest -DCMAKE_CXX_STANDARD=17 
	```

If CMake throws errors, it is likely that either your environment variables are not set correctly 
or you do not have the necessary prerequisites installed.

<a name="compile"></a>
### Compiling NEST

From within the build directory (where the CMake commands were executed), one can now compile NEST.

To generate the NEST library, execNEST executable (***THE MOST IMPORTANT, SWISS-ARMY KNIFE TOOLBOX***), and various tools (bareNEST, rootNEST): 

```	
make; make install
```

The compiled executables and libraries, and all the headers, should now be present in the install 
directory ("../install" if next to the build directory). 

After changes to the source code, one should do a clean make for good measure:

```
make clean; make; make install
```