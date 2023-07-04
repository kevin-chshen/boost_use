#pragma once

#include <iostream>
#include <filesystem>

class filesys_example
{
public:
    static void run()
    {
        std::cout << "filesys_example begin \n";

        std::filesystem::path();
        std::cout << "filesys_example end \n";
    }
};