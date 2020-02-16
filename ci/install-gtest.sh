#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for license information.
#
# Name: install-gtest.sh - Version 1.0.0
# Author: cdrisko
# Date: 02/01/2020-11:17:26
# Description: Install googletest for unit testing

mkdir ~/GoogleTest && cd ~/GoogleTest

git clone https://github.com/google/googletest.git

mkdir build && cd build

cmake ../googletest/. -Dgtest_disable_pthreads=ON -DCMAKE_CXX_FLAGS=-std=c++11

make && sudo make install
