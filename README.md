[TOC]

# Binary To Ternary Encoding

This repo implements a library that encodes binary to ternary following this [TIP](https://github.com/iotaledger/tips/blob/main/tips/TIP-0005/tip-0005.md)

## Installing the library 

### From source code
```
git clone https://github.com/EddyTheCo/Qb1t6.git 

mkdir build
cd build
qt-cmake -G Ninja -DCMAKE_INSTALL_PREFIX=installDir -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF -DBUILD_DOCS=OFF ../Qb1t6

cmake --build . 

cmake --install . 
```
where `installDir` is the installation path.
One can choose to build or not the tests and the documentation with the `BUILD_TESTING` and `BUILD_DOCS` variables.

### From GitHub releases
Download the releases from this repo. 

## Adding the libraries to your CMake project 

```CMake
include(FetchContent)
FetchContent_Declare(
	Qtb1t6	
	GIT_REPOSITORY https://github.com/EddyTheCo/Qb1t6.git
	GIT_TAG v0.1.0 
	FIND_PACKAGE_ARGS 0.1 CONFIG  
	)
FetchContent_MakeAvailable(Qtb1t6)
target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> Qtb1t6::qb1t6)
```

## API reference

You can read the [API reference](https://eddytheco.github.io/Qb1t6/) here, or generate it yourself like
```
cmake -DBUILD_DOCS=ON ../Qb1t6/
cmake --build . --target doxygen_docs
```

## Contributing

We appreciate any contribution!


You can open an issue or request a feature.
You can open a PR to the `develop` branch and the CI/CD will take care of the rest.
Make sure to acknowledge your work, and ideas when contributing.
