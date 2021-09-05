#include <iostream>

using namespace std;

#define DEAFAULT_CAPACITY 4
template <typename T> class vector
{
public:
	vector(int cap = 4)
	{
		m_elem = new T[cap];
		m_capacity = cap;
		m_size = 0;
	}
	
	vector(int rank, T elem)
	{
		m_elem = new T[rank * 2];
		for (int i = 0; i < rank; i++)
		{
			m_elem[i] = elem;
		}
		m_size = rank;
		m_capacity = rank * 2;
	}

	vector()
	{

	}

	~vector()
	{
		delete[] m_elem;
	}

	int size() const { return m_size; }

	int capacity() const { return m_capacity; }

	T get(int rank) const { return m_elem[rank]; }

	int find(T elem, int left, int right)
	{
		if (left >= right || left < 0 || right > m_size)
		{
			return -1;
		}

		for (int i = right - 1; i >= left; i--)
		{
			if (elem == m_elem[i])
			{
				return i;
			}
		}

		return -1;
	}

	int push_back(T elem)
	{
		expand();
		m_elem[m_size] = elem;
		m_size++;
		return m_size;
	}

	void push(T elem)
	{
		expand();
		for (int i = m_size; i > 0; i--)
		{
			m_elem[i] = m_elem[i - 1];
		}

		m_elem[0] = elem;
		m_size++;
	}

	void put(int rank, T elem)
	{
		if (rank < 0 || rank >= m_size)
			return;
		m_elem[rank] = elem;
	}

	void insert(int rank, T elem)
	{
		if (rank < 0 || rank > m_size)
		{
			return;
		}
		expand();
		for (int i = m_size; i > rank; i--)
		{
			m_elem[i] = m_elem[i - 1];
		}

		m_elem[rank] = elem;
		m_size++;
	}

	int find(T elem) const { return find(elem, 0, m_size); }

	T& operator[](int i) { return m_elem[i]; }
	T operator[](int i) const { return m_elem[i]; }
	friend ostream& operator<<(ostream& out, vector<T>& vec);

private:
	int m_size;
	int m_capacity;
	T* m_elem;

	// 扩展函数
	bool expand()
	{
		if (m_size < m_capacity)
		{
			return false;
		}

		T* temp = m_elem;
		m_elem = new T[m_capacity * 2];
		for (int i = 0; i < m_size; i++)
		{
			m_elem[i] = temp[i];
		}
		m_capacity *= 2;
		delete[] temp;
		return true;
	}

	bool shrink()
	{
		if (m_size * 4 > m_capacity)
		{
			return false;
		}

		T* temp = m_elem;
		m_elem = new T[m_capacity / 2];
		for (int i = 0; i < m_size; i++)
		{
			m_elem[i] = temp[i];
		}

		m_capacity /= 2;
		delete[] temp;
		return true;
	}
};

template <typename T>
ostream& operator<<(ostream& out, vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.m_elem[i] << " ";
	}

	return out;
}