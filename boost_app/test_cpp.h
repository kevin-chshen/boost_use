#pragma once
#include <iostream>
#include <functional>
#include <utility>

class test
{
    class A
    {
        int _a;
    public:
        A()
        {
            std::cout << __FUNCTION__ << "\n";
        }
        ~A()
        {
            std::cout << __FUNCTION__ << "\n";
        }
        int get()
        {
            std::cout << __FUNCTION__ << "\n";
            return _a;
        }
    };
    struct B
    {
        std::string _s;
        B() = delete;

        B(const std::string& str)
            :_s(str)
        {
            //B(std::forward<std::string>(str));
            std::cout << "B copy constractor \n";
        }
        B(const std::string&& str)
            :_s(std::move(str))
        {
            std::cout << "B move constractor \n";
        }
        void operator=(const B& b)
        {
            _s = b._s;
            std::cout << "copy \n";
        }
        void operator=(const B&& b)
        {
            _s = b._s;
            std::cout << "move \n";
        }
        //void operator=(const std::string&& str)
        //{
        //    std::cout << "move \n";
        //}
    };
public:
    static void run()
    {
        test o;
        o.use_exchange();
    }

    void use_exchange()
    {
        B a("xxx");
        B b("1111");
        //std::exchange(a, b); //由于b时被直接&&，引擎这里编译报错了
        std::cout << "a " <<a._s << ", b "<< b._s <<"\n";
    }

    void use_invoke()
    {
        // 错误处理
        //try
        {
            A* a = new A();
            A* b = a;
            //std::invoke(&A::get, b);
            std::cout << "destory a \n";
            delete a;
            a = nullptr;

            if (a)
            {
                std::cout << "b->get() \n";
                a->get();
            }
            else
            {
                std::cout << "a nullptr ->get() \n";
                //a->get();
            }
            std::cout << "std::invoke(&A::get, b) \n";
            int n = std::invoke(&A::get, a);
            std::cout << "n " << n << "\n";
        }
        //catch (...)
        {
            std::cout << "error!!\n";
        }
    }

};