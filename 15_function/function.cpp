// #define FUNCTION_POINT
// #define STD_FUNCTION
#define BIND_FUNCTION

#ifdef FUNCTION_POINT
#include <cstdio>
// ���ͣ�http://c.biancheng.net/view/228.html
int Max(int, int);  //��������

int main(void)
{
    int(*p)(int, int);  //����һ������ָ��
    int a, b, c;
    p = Max;  //�Ѻ���Max����ָ�����p, ʹpָ��Max����
    printf("please enter a and b:");
    scanf_s("%d %d", &a, &b);
    c = (*p)(a, b);  //ͨ������ָ�����Max����
    printf("a = %d\nb = %d\nmax = %d\n", a, b, c);
    return 0;
}

int Max(int x, int y)  //����Max����
{
    int z;
    if (x > y)
    {
        z = x;
    }
    else
    {
        z = y;
    }
    return z;
}
#endif // FUNCTION_PINT

#ifdef STD_FUNCTION

#include <iostream>
#include <functional>

// ���ͣ�https://c-cpp.com/cpp/utility/functional/function.html

struct Foo
{
    Foo(int num) : m_num(num) {}
    void print_add(int i) const
    {
        std::cout << m_num + i << '\n';
    }
    int m_num;
};

void print_num(int i)
{
    std::cout << i << '\n';
}

struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main()
{
    // �洢���ɺ���
    std::function<void(int)> f_display = print_num;
    f_display(-9);

    // �洢 lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();

    // �洢�� std::bind ���õĽ��
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();

    // �洢����Ա�����ĵ���
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);

    // �洢�����ݳ�Ա�������ĵ���
    std::function<int(Foo const&)> f_num = &Foo::m_num;
    std::cout << "m_num: " << f_num(foo) << '\n';

    // �洢����Ա����������ĵ���
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1);
    f_add_display2(2);

    // �洢����������ĵ���
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
}

#endif // STD_FUNCTION

#ifdef BIND_FUNCTION
#include <iostream>  
#include <functional>  

using namespace std;
using namespace placeholders;

int main()
{
    auto fun = [](int* array, int n, int num) {
        for (int i = 0; i < n; i++)
        {
            if (array[i] > num)
                cout << array[i] << ends;
        }
        cout << endl;
    };

    int array[] = { 1, 3, 5, 7, 9 };
    auto new_fun = bind(fun, _1, _2, 5);
    new_fun(array, sizeof(array) / sizeof(*array)); // ����ֻ��Ҫ2��������
}


#endif // BIND_FUNCTION
