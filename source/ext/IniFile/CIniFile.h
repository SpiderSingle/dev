#pragma  once
/*
@desc:   读取INI配置文件的对象
@author: chengguo
*/
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

		//operator 运算符重载
		IniValue& operator=(const bool& bValue);
		IniValue& operator=(const int&  nVlaue);
		IniValue& operator=(const float& fVlaue);
		IniValue& operator=(const double& dbVlaue);
		IniValue& operator=(const char* szVlaue);
		IniValue& operator=(const std::string& strVlaue);

		//operator类型转换函数:将类类型的值转换为其他的数值类型
		
		/*
		(1)转换函数是用户定义的成员函数，但它要是非静态的。
		(2)转换函数的不可以有返回值。（意思是声明中不可以有返回值）
		(3)转换函数也不带任何参数。
		(4)转换函数函数还不能定义为友元函数。

		类型转换函数的特征：
		1）  类型转换函数定义在源类中；
		2）  须由 operator 修饰，函数名称是目标类型名或目标类名；
		3）  函数没有参数，没有返回值，但是有return语句，在return语句中返回目标类型数据或调用目标类的构造函数。
		*/
		operator bool();
		operator int();
		operator double();
		operator float();
		operator std::string();
		operator const char*();

	private:
		std::string  m_strValue;
	};


	class CIniFile{

		typedef std::map<std::string, IniValue> Section;

	public:
		CIniFile(const std::string &strFileName);
		~CIniFile();

		bool    save(const std::string &strFileName);
		void    show();
		void    clear();

		IniValue& get(const std::string& section, const std::string& key);
	private:
		std::string  trim(std::string& str);
		bool         load(const std::string& strFileName);

		std::map<std::string, Section>        m_mapSectionIni;
	
	};


}