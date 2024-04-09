# C Library

This is a collection of C code that I frequently use in projects.

## Build Commands

- **./build test \[name]:** Compiles with debug flags and runs test. The test name is the directory name of the source.
- **./build debug:** Compiles with debug flags.
- **./build clean:** Removes ./out (build) directory.

## Container Packages

- vim
- gcc
- gdb
- make
- cmake
- googletest

## Setup

- Install Docker
- Add user to docker group
    - sudo usermod -aG docker $USER
- VScode Extensions
    - Dev Containers (Microsoft)
    - C/C++ (Microsoft)
- Remote Explorer, "open folder in container".
    - First run takes longer because environment needs to be set up.
    - C/C++ Extension should automatically install on the remote.