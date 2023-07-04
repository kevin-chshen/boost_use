// cmake_app.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include "cmake_app.h"
#include "config.h"


#include "test_log.h"

int main(int, char*[])
{
    printf("hello world!!\n");

    std::cout << BOOST_LIB << "\n";

    test_log::run();

    return 0;
}
