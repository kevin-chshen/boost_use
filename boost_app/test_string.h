#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <chrono>

class test_string
{
public:
    static void run()
    {
        test_string o;
        o.base();
        //o.test_split();
        //o.tolower();
        //std::string str = "hello world example";
        //int begin = 7;
        //int len = 5;
        //auto start = std::chrono::high_resolution_clock::now();
        //for (size_t i = 0; i < 1000000; i++)
        //{
        //    //o.sub1(str, begin, len);
        //    //o.sub2(str, begin, len);
        //    o.sub3(str, begin, len);
        //}
        //auto end = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> duration = end - start;
        //std::cout << "sub time elapsed: " << duration.count() << "\n";
    }

    void base()
    {
        std::string a("test");
        std::cout << "a " << a << " len " << a.size() << "\n";

        std::string b = a;
        std::cout << "b " << b << "\n";
        b = "tt";
        if (b == "tt")
        {
            std::cout << "b " << b << "\n";
        }
        else
        {
            std::cout << "b != tt " << b << "\n";
        }

        size_t pos = a.find('x');
        if (pos == std::string::npos)
        {
            std::cout << "a " << a << "\n";
        }
        else
        {
            std::cout << "pos " << pos << "\n";
        }

        std::string c = "hello world!!";
        c.insert(3, "test");
        std::cout << "c " << c << std::endl;
    }

    void test_split()
    {
        std::string content = "hello world example";
        auto list = test_string::split(content, ' ');
        /*std::vector<std::string> v2;
        std::copy<std::vector<std::string>::iterator>(list.begin(), list.end(),
            std::back_inserter(v2));*/
        for (auto& itr : list)
        {
            std::cout << itr << std::endl;
        }
    }
    static std::vector<std::string> split(const std::string& str, char delimiter)
    {
        std::vector<std::string> words;
        std::stringstream ss(str);
        std::string word;

        while (std::getline(ss, word, delimiter))
        {
            words.push_back(word);
        }

        return words;
    }

    void sub1(const std::string& str, int start, int length)
    {
        // 100W 次 sub time elapsed: 1.07844
        std::string sub2 = str.substr(start, length); // 从索引为 7 的位置开始截取 5 个字符

        //std::cout << "sub2: " << sub2 << std::endl; // 输出: World
    }

    void sub2(const std::string& str, int start, int length)
    {
        // 100W 次 sub time elapsed: 1.63022
        std::string sub;

        for (int i = start; i < start + length && i < str.size(); i++) {
            sub += str[i];
        }

        //std::cout << "sub: " << sub << std::endl; // 输出: World
    }

    void sub3(const std::string& str, int start, int length)
    {
        // 100W 次 sub time elapsed: 2.79284
        std::string::const_iterator begin = str.cbegin() + start; // 从索引为 7 的位置开始
        std::string::const_iterator end = begin + length;
        std::string sub1(begin, end); // 从索引为 7 的位置开始截取到末尾

        //std::cout << "sub1: " << sub1 << std::endl; // 输出: World!
    }

    void tolower()
    {
        std::string str = "HeLLO, World!";

        // 将字符串转换为小写
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
            });
        std::cout << "Lowercase: " << str << std::endl; // 输出：hello, world!

        // 将字符串转换为大写
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::toupper(c);
            });
        std::cout << "Uppercase: " << str << std::endl; // 输出：HELLO, WORLD!
    }
};