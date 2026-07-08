<h1 align="center">YOLOs-CPP</h1>
<h3 align="center">Production-Ready YOLO Inference Engine for C++</h3>

<p align="center">
  <a href="https://github.com/Geekgineer/YOLOs-CPP/blob/main/LICENSE"><img src="https://img.shields.io/badge/license-AGPL--3.0-ef4444?style=flat-square" alt="License"/></a>
</p>

<p align="center">
  <a href="https://github.com/Geekgineer/YOLOs-CPP">Original from Geekgineer</a> · 
</p>

---
This fork of [**YOLOs-CPP**](https://github.com/Geekgineer/YOLOs-CPP) keeps only the "main" library files. I did this as I am downloading it to some devices with terribly slow internet connection, and which build slowly.

I have also changed the construction of the models, to add basic support for TensorRT, though there is no compile-time checks for whether this is available.

> `yoloe` and `classification` do not work at the moment - I made some modifications to be able to use the TensorRT backend, and have not applied these to those modules yet.

### Minimum Requirements
- C++ 17
- CMake 3.16
- ONNX Runtime 1.16

### CMake
Easiest as a subdirectory:

```cmake
cmake_add_subdirectory(YOLOs-CPP)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE yolos::yolos)
```