#include <sstream>
#include <fstream>
#include "CIniFile.h"



namespace spider{


	IniValue::IniValue()
	{

	}

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
		load(strFileName);
	}

	CIniFile::~CIniFile()
	{

	}

	bool CIniFile::save(const std::string &strFileName)
	{
		return true;
	}

	void CIniFile::show()
	{

	}

	void CIniFile::clear()
	{

	}

	spider::IniValue CIniFile::get(const std::string& section, const std::string& key,IniValue DefaultValue)
	{
		//判断是否存在section
		std::map<std::string, Section>::iterator iter= m_mapSection.find(section);
		if (iter == m_mapSection.end())
			return DefaultValue;
		//判断该section下是否存在Key
		Section::iterator it = iter->second.find(key);
		if (it == iter->second.end())
			return DefaultValue;
		return  it->second;		
	}

	std::string CIniFile::trim(std::string& str)
	{
		//去除前后的空格
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
		m_mapSection.clear();
		std::ifstream is(strFileName);
		//if(is.fail())
		if (!is.is_open())
			return false;
		std::string strReadLine;
		std::string strline;
		std::string strSection;
		while (std::getline(is, strReadLine)){
			strline = trim(strReadLine);
			if (strline.empty())
				continue;
			if ('#'==strline[0])
				continue;
			if ('[' == strline[0]){
				std::string::size_type npos = strline.find_last_of("]");
				if (std::string::npos == npos)
					continue;
				strSection = strline.substr(1, npos-1);
				m_mapSection[strSection] = Section();
			}
			else{
				std::string::size_type npos = strline.find_first_of("=");
				if (std::string::npos == npos)
					continue;
				std::string strKey = trim(strline.substr(0, npos));
				std::string strValue = trim(strline.substr(npos+1));
				m_mapSection[strSection][strKey] = strValue;	
			}
		}
		is.close();
		return m_mapSection.size() == 0 ? false : true;
	}
	
}