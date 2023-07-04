// cmake_app.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

#include "log/test_log.h"
#include "test_cpp.h"
#include "test_string.h"

int main(int, char* [])
{
    printf("hello world!!\n");

	//test_log::run();

    //test::run();

    test_string::run();
    printf("hello world end!!\n");

    return 0;
}
