#ifndef CLASSTEMPLATE
#define CLASSTEMPLATE
template <class T>
class ClassTemplate
{
public:
	ClassTemplate(T const& widthIn, T const& heightIn)
		: width(widthIn), height(heightIn)
	{
	}
	T const& CalculateArea();
private:
	T width;
	T height;
};

template <class T>
T const&  ClassTemplate<T>::CalculateArea() {
	return width * height;
}
#endif // !CLASSTEMPLATE


