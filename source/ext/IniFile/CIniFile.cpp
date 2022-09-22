#include <sstream>
#include "CIniFile.h"



namespace spider{



	IniValue::IniValue(const bool& bVlaue)
	{
		*this = bVlaue;
	}
	IniValue::IniValue(const int&  nVlaue)
	{
		*this = nVlaue;

	}
	IniValue::IniValue(const float& fVlaue)
	{
		*this = fVlaue;
	}
	IniValue::IniValue(const double& dbVlaue)
	{
		*this = dbVlaue;
	}
	IniValue::IniValue(const char* szVlaue)
		:m_strValue(szVlaue)

	{
	
	}
	IniValue::IniValue(const std::string& str)
		:m_strValue(str)

	{

	}

	IniValue::~IniValue()
	{

	}
	IniValue& IniValue::operator=(const std::string& strVlaue)
	{
		m_strValue = strVlaue;
		return *this;
	}
	IniValue& IniValue::operator=(const char* szVlaue)
	{
		m_strValue = std::string(szVlaue);
		return *this;
	}
	IniValue& IniValue::operator=(const float& fVlaue)
	{
		std::ostringstream os;
		os << fVlaue;
		m_strValue = os.str();
		return *this;
	}
	IniValue& IniValue::operator=(const double& dbVlaue)
	{
		std::ostringstream os;
		os << dbVlaue;
		m_strValue = os.str();
		return *this;
	}
	IniValue& IniValue::operator=(const int& nVlaue)
	{
		std::ostringstream os;
		os << nVlaue;
		m_strValue = os.str();
		return *this;
	}
	IniValue& IniValue::operator=(const bool& bValue)
	{
		m_strValue = bValue == true ? "true" : "false";
		return *this;
	}

}