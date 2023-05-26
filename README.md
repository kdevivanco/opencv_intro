# Project Set Up 
## Requirements - Mac: 
- C++ 
- opencv -> brew install opencv
- cmake -> brew install cmake
- gcc -> brew install gcc

# Instruction to create files: 
 - Link for reference: https://www.youtube.com/watch?v=Ozc3zWJ_NhQ&t=254s
1. Create CMaketxt File 
```
touch CMakeLists.txt
// Paste this text into text file: 

cmake_minimum_required(VERSION 3.10)
project(MyProject)
find_package(OpenCV REQUIRED)
add_executable(MyProject webcamtest.cpp)
target_link_libraries(MyProject ${OpenCV_LIBS})

```
2. Create Build Directory
```
mkdir build
```
3. Move to build
```
cd build
```
4. Generate cmake project
```
cmake ..
```
5. Create your test.cpp 

6. Compile 
``` 
cd build
make 
```

7. Run 
```
./MyProject
``` 


## Just run instructions:
```
cd build
make
./MyProject
```
Dont forget to change the file name in CMakeLists.txt to run your test!
