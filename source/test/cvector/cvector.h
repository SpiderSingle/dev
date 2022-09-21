#pragma once

#include <iostream>
#include <vector>

template<typename T>
class cvetor {
public:
    cvetor(int nSize);
    cvetor(int c,T const & );
    cvetor();
    ~cvetor();
private:
    T*  m_elem_;
    int m_size_;
    int m_capactity_;



};