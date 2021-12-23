#include <iostream>
#include <vector>
#include <string>
#include <xutility>
#include <typeinfo>

using namespace std;

// 右值是C++11新特性

class MyString
{
public:
	static size_t DCtor;	// 累计default-ctor呼叫次数
	static size_t Ctor;		// 累计ctor呼叫次数
	static size_t CCtor;	// 累计copy-ctor呼叫次数
	static size_t MCtor;	// 累计move-ctor呼叫次数
	static size_t CAsgn;	// 累计copy-asgn呼叫次数
	static size_t MAsgn;	// 累计move-asgn呼叫次数
	static size_t Dtor;		// 累计dtor呼叫次数

private:
	char* m_Data;
	size_t m_Len;
	void InitData(const char* s)
	{
		m_Data = new char[m_Len + 1];
		memcpy(m_Data, s, m_Len);
		m_Data[m_Len] = '\0';
	}
public:

	// default constructor
	MyString() : m_Data(nullptr), m_Len(0) { ++DCtor; }
	
	// constructor
	MyString(const char* p) : m_Len(strlen(p))
	{
		++Ctor;
		InitData(p);
	}

	// copy constructor
	MyString(const MyString& str) : m_Len(str.m_Len)
	{
		++CCtor;
		InitData(str.m_Data);
	}

	// move constructor, with "noexcept"
	MyString(MyString&& str) noexcept
		: m_Data(str.m_Data), m_Len(str.m_Len)
	{
		++MCtor;
		str.m_Len = 0;
		str.m_Data = nullptr;
	}

	// copy assignment
	MyString& operator=(const MyString& str)
	{
		++CAsgn;
		if (this != &str)
		{
			if (m_Data)
				delete m_Data;
			m_Len = str.m_Len;
			InitData(str.m_Data);
		}

		return *this;
	}

	// move assignment
	MyString& operator=(MyString&& str) noexcept
	{
		++MAsgn;
		if (this != &str)
		{
			if (m_Data)
				delete m_Data;

			m_Len = str.m_Len;
			m_Data = str.m_Data;
			str.m_Len = 0;
			str.m_Data = nullptr;
		}

		return *this;
	}

	virtual ~MyString()
	{
		++Dtor;
		if (m_Data)
			delete m_Data;
	}

	bool operator<(const MyString& rhs) const
	{
		return std::string(this->m_Data) < std::string(rhs.m_Data);
	}

	bool operator==(const MyString& rhs) const
	{
		return std::string(this->m_Data) == std::string(rhs.m_Data);
	}

	char* get() const
	{
		return m_Data;
	}
};

size_t MyString::DCtor	= 0;	// 累计default-ctor呼叫次数
size_t MyString::Ctor	= 0;	// 累计ctor呼叫次数
size_t MyString::CCtor	= 0;	// 累计copy-ctor呼叫次数
size_t MyString::MCtor	= 0;	// 累计move-ctor呼叫次数
size_t MyString::CAsgn	= 0;	// 累计copy-asgn呼叫次数
size_t MyString::MAsgn	= 0;	// 累计move-asgn呼叫次数
size_t MyString::Dtor	= 0;	// 累计dtor呼叫次数

class MyStringNoMove
{
public:
	static size_t DCtor;	// 累计default-ctor呼叫次数
	static size_t Ctor;		// 累计ctor呼叫次数
	static size_t CCtor;	// 累计copy-ctor呼叫次数
	static size_t MCtor;	// 累计move-ctor呼叫次数
	static size_t CAsgn;	// 累计copy-asgn呼叫次数
	static size_t MAsgn;	// 累计move-asgn呼叫次数
	static size_t Dtor;		// 累计dtor呼叫次数

private:
	char* m_Data;
	size_t m_Len;
	void InitData(const char* s)
	{
		m_Data = new char[m_Len + 1];
		memcpy(m_Data, s, m_Len);
		m_Data[m_Len] = '\0';
	}
public:

	// default constructor
	MyStringNoMove() : m_Data(nullptr), m_Len(0) { ++DCtor; }

	// constructor
	MyStringNoMove(const char* p) : m_Len(strlen(p))
	{
		++Ctor;
		InitData(p);
	}

	// copy constructor
	MyStringNoMove(const MyStringNoMove& str) : m_Len(str.m_Len)
	{
		++CCtor;
		InitData(str.m_Data);
	}

	// copy assignment
	MyStringNoMove& operator=(const MyStringNoMove& str)
	{
		++CAsgn;
		if (this != &str)
		{
			if (m_Data)
				delete m_Data;
			m_Len = str.m_Len;
			InitData(str.m_Data);
		}

		return *this;
	}

	virtual ~MyStringNoMove()
	{
		++Dtor;
		if (m_Data)
			delete m_Data;
	}

	bool operator<(const MyStringNoMove& rhs) const
	{
		return std::string(this->m_Data) < std::string(rhs.m_Data);
	}

	bool operator==(const MyStringNoMove& rhs) const
	{
		return std::string(this->m_Data) == std::string(rhs.m_Data);
	}

	char* get() const
	{
		return m_Data;
	}
};

size_t MyStringNoMove::DCtor = 0;	// 累计default-ctor呼叫次数
size_t MyStringNoMove::Ctor = 0;	// 累计ctor呼叫次数
size_t MyStringNoMove::CCtor = 0;	// 累计copy-ctor呼叫次数
size_t MyStringNoMove::MCtor = 0;	// 累计move-ctor呼叫次数
size_t MyStringNoMove::CAsgn = 0;	// 累计copy-asgn呼叫次数
size_t MyStringNoMove::MAsgn = 0;	// 累计move-asgn呼叫次数
size_t MyStringNoMove::Dtor = 0;	// 累计dtor呼叫次数

template<typename T>
void OutputStaticData(const T& myStr)
{
	cout << typeid(myStr).name() << "--" << endl;
	cout << " copy constructor = " << T::CCtor << endl;
	cout << " move constructor = " << T::MCtor << endl;
	cout << " copy assignment = " << T::CAsgn << endl;
	cout << " move assignment = " << T::MAsgn << endl;
	cout << " default constructor = " << T::DCtor << endl;
	cout << " constructor  = " << T::Ctor << endl;
	cout << " destruct  = " << T::Dtor << endl;
}

template <typename M>
void TestMoveable(M c1, long value)
{
	char buf[10];

	// test moveable
	typedef typename std::iterator_traits<typename M::iterator>::value_type V1type;
	clock_t timeStart = clock();
	for (long i = 0; i < value; i++)
	{
		snprintf(buf, 10, "%d", rand());
		auto ite = c1.end();
		c1.insert(ite, V1type(buf));
	}

	std::cout << "construction, milli-seconds" << (clock() - timeStart) << endl;
	std::cout << "size() = " << c1.size() << std::endl;
	OutputStaticData(*(c1.begin()));
}

int main()
{
	TestMoveable(vector<MyString>(), 3000000L);
	TestMoveable(vector<MyStringNoMove>(), 3000000L);
	return 0;
}