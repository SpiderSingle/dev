#include "../IniFile/CIniFile.h"

using namespace spider;
int main(int argc, char** argv)
{
	double db = 20.0f;
	IniValue Value = db;
	Value = db;

	static_cast<int>(db);

	return 0;
}
