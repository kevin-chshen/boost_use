#include "filesys_error.h"

namespace filesys
{
    filesys_error::filesys_error()
    {
    }
    filesys_error::filesys_error(const filesys_error&)
    {
    }
    filesys_error::filesys_error(const std::string& what_arg, std::system_error ec)
    {
    }
    filesys_error::filesys_error(const std::string& what_arg, const path& p1, std::system_error ec)
    {
    }
    filesys_error::filesys_error(const std::string& what_arg, const path& p1, const path& p2, std::system_error ec)
    {
    }
    const path& filesys_error::path1() const
    {
        // TODO: 在此处插入 return 语句
    }
    const path& filesys_error::path2() const
    {
        // TODO: 在此处插入 return 语句
    }
    const char* filesys_error::what() const
    {
        return nullptr;
    }
}