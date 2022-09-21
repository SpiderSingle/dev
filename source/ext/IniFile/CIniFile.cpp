#include <sstream>
#include "CIniFile.h"



namespace spider{



	IniValue::IniValue(const bool& bVlaue)
	{
		m_strValue = bVlaue == true ? "true" : "false";
	}
	IniValue::IniValue(const int&  nVlaue)
	{
		std::ostringstream os;
		os << nVlaue;
		m_strValue = os.str();

	}
	IniValue::IniValue(const float& fVlaue)
	{
		std::ostringstream os;
		os << fVlaue;
		m_strValue = os.str();
	}
	IniValue(const double& dbVlaue);
	IniValue(const char* dbVlaue);
	IniValue(const std::string& strVlaue);

}