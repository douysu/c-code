#include <iostream>

using namespace std;

// #define PRACTICE14
#ifdef PRACTICE14

int main()
{
    auto func = [](int a, int b) { return a + b; };
    
    cout << func(1, 2) << endl;
    return 0;
}

#endif

// #define PRACTICE15
#ifdef PRACTICE15

int main()
{
    int x = 10;
    auto func = [x](int a) { return x + a; };

    cout << func(1) << endl;
    return 0;
}

#endif

#define PRACTICE16
#ifdef PRACTICE16

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// elimdups the same value
void elimdups(std::vector<std::string>& vs)
{
	std::sort(vs.begin(), vs.end());
	auto new_end = std::unique(vs.begin(), vs.end());
	vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string>& vs, std::size_t sz)
{
	elimdups(vs);
	stable_sort(vs.begin(), vs.end(), [](string const& lhs, string const& rhs)
		{return lhs.size() < rhs.size(); });

	auto wc = find_if(vs.begin(), vs.end(), [sz](string const& s) { return s.size() >= sz; });

	for_each(wc, vs.end(), [](const string& s) { cout << s << " "; });
}

int main()
{
	std::vector<std::string> v { "1234", "1234", "1234", "hi~", "alan", "alan", "cp" };
	std::cout << "ex10.16: ";
	biggies(v, 3);
	std::cout << std::endl;

	return 0;
}

#endif