#include "../IniFile/CIniFile.h"

using namespace spider;
int main(int argc, char** argv)
{
	std::string strFileName = "testIni.ini";
	CIniFile IniFile(strFileName);
	return 0;
}
