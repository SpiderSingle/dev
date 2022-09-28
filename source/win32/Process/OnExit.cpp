
#include <Windows.h>
#include <stdio.h>

int fun1(void)
{
	printf("exit");
	return 0;
}


int main(int argc,char **argv)
{



	_onexit(fun1);

    return 0;

}