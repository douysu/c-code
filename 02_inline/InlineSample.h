#ifndef NEILIANSAMPLE_H
#define NEILIANSAMPLE_H
class InlineSample
{
public:
	InlineSample();
	void setValue(float inValue);
	float value;
};
inline void InlineSample::setValue(float inValue) {
	value = inValue;
}
#endif 