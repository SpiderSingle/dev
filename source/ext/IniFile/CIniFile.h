#pragma  once

#include <string>
#include <map>

namespace spider{

	class   IniValue{
	public:
		IniValue(const bool& bVlaue);
		IniValue(const int&  nVlaue);
		IniValue(const float& fVlaue);
		IniValue(const double& dbVlaue);
		IniValue(const char* szVlaue);
		IniValue(const std::string& strVlaue);
		~IniValue();

		IniValue& operator=(const bool& bValue);
		IniValue& operator=(const int&  nVlaue);
		IniValue& operator=(const float& fVlaue);
		IniValue& operator=(const double& dbVlaue);
		IniValue& operator=(const char* szVlaue);
		IniValue& operator=(const std::string& strVlaue);

		operator int();

	private:
		std::string  m_strValue;
	};
}