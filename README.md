# C/C++ Common Code Library

This is a common code library written in C for C/C++ projects, it is linked as a static library in c-base by default.

## Build Commands

- **./build test:** Compiles with debug flags and runs tests.
- **./build debug:** Compiles with debug flags.
- **./build release:** Compiles without debug flags.
- **./build run:** Runs compiled program.
- **./build clean:** Removes ./out (build) directory.

## External Libraries

- gtest
- pthread

## Ubuntu Packages

```bash
sudo apt install build-essential libc6-dev-i386 gdb cmake
```
