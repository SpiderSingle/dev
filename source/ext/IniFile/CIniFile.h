#pragma  once
#pragma waring(disable: 4996)


#include <string>
#include <map>

namespace spider{

	class   IniValue{
	public:
		IniValue(const bool& bVlaue);
		IniValue(const int&  nVlaue);
		IniValue(const float& fVlaue);
		IniValue(const double& dbVlaue);
		IniValue(const char* dbVlaue);
		IniValue(const std::string& strVlaue);
		~IniValue();
	private:
		std::string  m_strValue;
	};









}