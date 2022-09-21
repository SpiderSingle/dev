#include <iostream>
#include <new>
using namespace std;




class A{

public:
	A(){
		std::cout << "构造函数A" << std::endl;
	}
    A(const A&) {
        std::cout << "拷贝构造函数A" << std::endl;
    }
    A& operator=(const A&) {
    
        std::cout << "Operator = " << std::endl;
        return *this;
    }
	~A(){
	
		std::cout << "析构函数A" << std::endl;
	}

};


int main(int argc, char** argv)
{
	//A* pA = new A();
 /*   std::allocator<A> alloctor;
    A* pArr = alloctor.allocate(3, (A*)0);
    new(pArr)A[40]();*/


	A A1;
	A A2 = A1;
    A2 = A1;
    


	system("pause");

	return 0;
}