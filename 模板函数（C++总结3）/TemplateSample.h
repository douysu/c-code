template <typename T>
class TemplateSample
{
public:
	TemplateSample(T widthIn, T heightIn)
		: width(widthIn),height(heightIn)
	{
	}
	T CalculateArea() {//计算面积
		return width*height;
	}
private:
	T width;//宽度
	T height;//高度
};

