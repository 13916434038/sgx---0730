#!/bin/bash

# 编译并运行项目
mkdir -p build
cd build
cmake ..
make
./FactoryPattern
