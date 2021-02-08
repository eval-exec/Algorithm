#! /bin/sh
set -e
if [ 1 -ne "$#" ]; then
  echo "need one argument"
  exit 1
fi

dirname=$1
mkdir $dirname
touch $dirname/main.cxx

echo "#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;






struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

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
echo init $1 success
