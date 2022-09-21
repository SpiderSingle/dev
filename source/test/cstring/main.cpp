#include "cstring.h"
#include <cstdio>
int main(int argc, char **argv)
{

    cstring str1("hello");
    const cstring str2("world");
    str1 = str2;
    system("pause");
    return 0;
}