#! /bin/sh
set -evx
if [ -z "$1" ]; then
  echo "need one argument"
  exit 1
fi

dirname=$1
mkdir $dirname
touch $dirname/main.cxx

echo "
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

" >> $dirname/main.cxx

echo "

cmake_minimum_required(VERSION 3.17)
project(leetcode_solutions)

set(CMAKE_CXX_STANDARD 17)

add_executable($dirname main.cxx)
" >$dirname/CMakeLists.txt

echo "

add_subdirectory($dirname)
" >>CMakeLists.txt
