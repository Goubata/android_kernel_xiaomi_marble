#!/bin/bash
clear
export ARCH=arm64
export PLATFORM_VERSION=12
export ANDROID_MAJOR_VERSION=s
ln -s /usr/bin/python2.7 $HOME/python
export PATH=$HOME/:$PATH

ARGS='
CC=$HOME/Toolchains/clang/bin/clang
CROSS_COMPILE=$HOME/Toolchains/gcc/aarch64-4.9/bin/aarch64-linux-android-
CLANG_TRIPLE=aarch64-linux-gnu-
ARCH=arm64
'
make -C $(pwd) O=$(pwd)/out1 ${ARGS} clean && make -C $(pwd) O=$(pwd)/out1 ${ARGS} mrproper #to clean the source
make -C $(pwd) O=$(pwd)/out1 ${ARGS} marble_defconfig #making your current kernel config
make -C $(pwd) O=$(pwd)/out1 ${ARGS} -j$(nproc) #to compile the kernel
