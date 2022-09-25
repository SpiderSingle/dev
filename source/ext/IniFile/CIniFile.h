#pragma  once
/*
@desc:   ��ȡINI�����ļ��Ķ���
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

		//operator ���������
		IniValue& operator=(const bool& bValue);
		IniValue& operator=(const int&  nVlaue);
		IniValue& operator=(const float& fVlaue);
		IniValue& operator=(const double& dbVlaue);
		IniValue& operator=(const char* szVlaue);
		IniValue& operator=(const std::string& strVlaue);

		//operator����ת������:�������͵�ֵת��Ϊ��������ֵ����
		
		/*
		(1)ת���������û�����ĳ�Ա����������Ҫ�ǷǾ�̬�ġ�
		(2)ת�������Ĳ������з���ֵ������˼�������в������з���ֵ��
		(3)ת������Ҳ�����κβ�����
		(4)ת���������������ܶ���Ϊ��Ԫ������

		����ת��������������
		1��  ����ת������������Դ���У�
		2��  ���� operator ���Σ�����������Ŀ����������Ŀ��������
		3��  ����û�в�����û�з���ֵ��������return��䣬��return����з���Ŀ���������ݻ����Ŀ����Ĺ��캯����
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