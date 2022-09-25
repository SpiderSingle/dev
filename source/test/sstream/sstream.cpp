/*
C++标准库的输入输出流
stringstream
ostringstream
istringstream
*/
#include <sstream>
#include <strstream>

int main(int argc, char **argv)
{
	std::stringstream  stream;   //输入输出流
	std::ostringstream os;
	std::wistringstream is;
	int a=10;
	is >> a;

	char sz;
	wchar_t sz2;
	wchar_t sz2 = 'A';

	std::wstring wss=is.str();

	stream.clear();


	return 0;
}