#pragma once
#include <system_error>
#include <string>

namespace filesys
{
    class path;

    class filesys_error : public std::system_error
    {
    private:

    public:
        filesys_error();
        filesys_error(const filesys_error&);
        filesys_error(const std::string& what_arg, std::system_error ec);
        filesys_error(const std::string& what_arg, const path& p1, std::system_error ec);
        filesys_error(const std::string& what_arg, const path& p1, const path& p2, std::system_error ec);

        // ��ȡ·������
        const path& path1() const;
        const path& path2() const;

        // ������Ϣ
        const char* what() const;
    };
}