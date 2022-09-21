#include "cstring.h"

cstring::cstring()
{
    m_str_ = NULL;
    m_nSize_ = 0; 
}
cstring::cstring(const char *src)
{
    int nSrcLen = strlen(src);
    m_nSize_ = nSrcLen;
    m_str_ = (char*)malloc(nSrcLen+1);
    _ASSERT(m_str_);
    memset(m_str_,0, nSrcLen + 1);
    strncpy(m_str_, src, nSrcLen);
}
cstring::cstring(const cstring & str)
{
    m_str_ = (char*)malloc(str.m_nSize_+1);
    memset(m_str_, 0, str.m_nSize_ + 1);
    strncpy(m_str_, str.m_str_, str.m_nSize_ + 1);
}
cstring::~cstring()
{
    if (m_str_) {
        free(m_str_);
        m_str_ = NULL;
        m_nSize_ = 0;
    }
}

cstring& cstring::operator = (const cstring& str)
{
    if (this == &str) {
        return *this;  
    }
    if (m_str_) {
        free(m_str_);
    }
    if (0 == str.m_nSize_) {
        m_str_ = NULL;
        return *this;
    }
    m_str_ = (char*)malloc(str.m_nSize_+1);
    memset(m_str_,0,sizeof(str.m_nSize_ + 1));
    m_nSize_ = str.m_nSize_;
    strncpy(m_str_, str.m_str_, str.m_nSize_);
    return *this;
}