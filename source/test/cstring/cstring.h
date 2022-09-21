#pragma once

#include <cstring>
#include <cstdlib>


class cstring {
public:
    cstring();
    cstring(const char *src);
    cstring(const cstring & str);
    ~cstring();

    cstring& operator = (const cstring& str);

private:
    char* m_str_;
    int   m_nSize_;   //有效字符长度
};


