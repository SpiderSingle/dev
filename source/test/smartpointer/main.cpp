#pragma warning(disable : 4996)
#include <iostream>
#include <memory>
#include <new>
#include <mutex>
#include <vector>
#include <array>

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class Base {
public:
    Base() {
        std::cout << "Base ()" << std::endl;
    };
	Base(const Base& base) {
		std::cout << "Base拷贝构造 ()" << std::endl;
	};
	Base& operator=(const Base& b)
	{
		std::cout << "Base赋值" << std::endl;
		return *this;
	}
    ~Base() {};
    virtual void  fun1() {
        std::cout << "base fun1" << std::endl;
    }
    virtual void  fun1(int x) {
        std::cout << "base fun1 int " << std::endl;
    }
    virtual void  fun2(int x) {
        std::cout << "base fun2 int " << std::endl;
    }
};


class Derived : public  Base
{

    using Base::fun1;

public:
    Derived() {
        std::cout << "Derived ()" << std::endl;
    };
    ~Derived() {};
    virtual void  fun1() {
        std::cout << "Derived fun1" << std::endl;
    }
    virtual void  fun2(int x) {
        std::cout << "Derived fun2 int " << std::endl;
    }
	friend  Derived operator*(Derived& lhs, Derived& rhs)
	{
		std::cout << "operator *" << std::endl;
		return lhs;
	}
	Derived(const Derived& base) {
		Base::Base(base);
		std::cout << "Derived拷贝构造 ()" << std::endl;
	};
	Derived& operator=(const Derived& b)
	{
		std::cout << "Derived赋值" << std::endl;
		return *this;
	}

	void test() const {
	
		
	}

	void  test_n()  
	{
		std::cout << "test_n" << std::endl;
	}
	const int& getValue() const
	{
		return 10;
	}

};

class CTest{
public:
	CTest(Derived& e):d(e){

	
	};
	~CTest(){}; 
private:
	Derived d;

};



int main1(void){
	return 0;
}


template<typename T,size_t _size,char ch>
class A{
public:
	A(){
	
		_arr = new T[ch];
	
	}
	~A(){};
private:
	T*  _arr;
};




int main(int argc, char** argv)
{

	//static const int a = 7;
	//static int const b = 9;
	//std::unique_ptr<Base> tetsInt(new Derived());

 //   std::shared_ptr<Base> shared;

	//std::weak_ptr<Base> weak;

	//Derived c1;
	//
	//Derived c2;
	//Derived c3;
	//Derived c4 = c1*c2;
	//c4 = c3;


	//Derived d;


	//CTest t(d);
	int a = 10;


	const std::shared_ptr<Derived> dd(new Derived());

	dd = new Derived();
	const int& Value = dd->getValue();

	dd->test_n();

	const Derived d3;
	d3.test_n();

	A<int, 10, 'c'> ch;

	std::array<int, 6> arr = {1,2,3,4,5,6};
	arr[0];
	std::array<int, 6>::iterator iter = arr.begin();


	std::array<char, 128> szBuff = { "hello world" };







	szBuff.data();

	sprintf(szBuff.data(),"hhe");



  /*  *tetsInt;

    tetsInt->fun1();
    tetsInt->fun1(1);
    tetsInt->fun2(1);*/

    system("pause");

	return 0;
}