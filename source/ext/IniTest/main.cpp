#include "../IniFile/CIniFile.h"

using namespace spider;
int main(int argc, char** argv)
{
	double db = 20.999f;
	IniValue Value = db;
	Value = db;

	int a = Value;
	static_cast<int>(db);

	return 0;
}
