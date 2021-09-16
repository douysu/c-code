#ifndef _MY_STRING
#define _MY_STRING
class String
{
public:
	String(const char * cstr=0);//���� String s1("hellow")�Ĺ��췽ʽ
	String(const String& str);//���� String s1(s2)�Ĺ��췽ʽ
	String& operator = (const String& str);//���� s1=s2�ķ�ʽ 
	~String();
private:
	char * m_data;//�Լ�����������
};
#include <cstring>
inline String::String(const char * cstr)//���캯�������� String s1("hellow")�Ĺ��췽ʽ
{
	if (cstr) {//�ж��ǲ���0
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}else {
		m_data = new char[1];
		*m_data = '\0';
	}
}
inline String::String(const String& str)//���캯�������� String s1(s2)�Ĺ��췽ʽ
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}
inline String::~String()
{
	delete[]  m_data;
}
inline String& String::operator =(const String& str){
	if(this==&str){//������Ҹ�ֵ 
		return *this;
	}
	delete[] m_data;
	m_data = new char[ strlen(str.m_data) + 1 ];
   	strcpy(m_data, str.m_data);
   	return *this;
}
#endif //_MY_STRING

