#ifndef _MY_STRING
#define _MY_STRING

#include <cstring>

class String
{
public:
	String(const char* other = 0); // �������죬֧��String s1("hello")���췽ʽ
	String(const String& other); // �������죬֧��String s1(s2)���췽ʽ
	String& operator=(const String& other); // ��ֵ���㣬����s1 = s2��ʽ 
	~String();

private:
	char* m_data; // ����
};

inline String::String(const char* other = 0)
{
	if (other) {
		m_data = new char[strlen(other) + 1];
		strcpy(m_data, other);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline String::String(const String& other)
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}

inline String::~String()
{
	delete[] m_data;
}

inline String& String::operator=(const String& other)
{
	if (this == &other) {
		return this;
	}

	delete[] m_data;
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	return *this;
}

#endif // !_MY_STRING
