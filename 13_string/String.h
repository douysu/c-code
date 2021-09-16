#ifndef _MY_STRING
#define _MY_STRING
class String
{
public:
	String(const char * cstr=0);//满足 String s1("hellow")的构造方式
	String(const String& str);//满足 String s1(s2)的构造方式
	String& operator = (const String& str);//满足 s1=s2的方式 
	~String();
private:
	char * m_data;//自己的数据数组
};
#include <cstring>
inline String::String(const char * cstr)//构造函数，满足 String s1("hellow")的构造方式
{
	if (cstr) {//判断是不是0
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}else {
		m_data = new char[1];
		*m_data = '\0';
	}
}
inline String::String(const String& str)//构造函数，满足 String s1(s2)的构造方式
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}
inline String::~String()
{
	delete[]  m_data;
}
inline String& String::operator =(const String& str){
	if(this==&str){//检测自我赋值 
		return *this;
	}
	delete[] m_data;
	m_data = new char[ strlen(str.m_data) + 1 ];
   	strcpy(m_data, str.m_data);
   	return *this;
}
#endif //_MY_STRING

