#include <sstream>
#include <fstream>
#include "CIniFile.h"



namespace spider{



	IniValue::IniValue(const bool& bVlaue)
	{
		//进入构造函数的时候 已经存在this指针了
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
	IniValue::operator bool()
	{
		return m_strValue == "true" ? true : false;
	}
	IniValue::operator int()
	{
		return ::atoi(m_strValue.c_str());
	}
	IniValue::operator double()
	{
		return ::atof(m_strValue.c_str());
	}
	IniValue::operator float()
	{
		return static_cast<float>(::atof(m_strValue.c_str()));
	}
	IniValue::operator std::string()
	{
		return m_strValue;
	}
	IniValue::operator const char*()
	{
		return m_strValue.c_str();
	}

	CIniFile::CIniFile(const std::string &strFileName)
	{
		

	}

	CIniFile::~CIniFile()
	{

	}

	bool CIniFile::save(const std::string &strFileName)
	{

	}

	void CIniFile::show()
	{

	}

	void CIniFile::clear()
	{

	}

	spider::IniValue& CIniFile::get(const std::string& section, const std::string& key)
	{

	}

	std::string CIniFile::trim(std::string& str)
	{
		if (str.empty())
			return str;
		str.erase(0, str.find_first_not_of(" \r\n\t"));
		str.erase(str.find_last_not_of(" \r\n\t") + 1);
		return str;
	}

	bool CIniFile::load(const std::string& strFileName)
	{
		/*
		[server]
		ip=
		port
		
		*/
		m_mapSectionIni.clear();
		std::ifstream is(strFileName);
		if (!is.is_open())
			return false;
		std::string strReadLine;
		std::string strline;
		std::string strSection;
		while (std::getline(is, strReadLine)){
		
			

			





		
		}
	}
}