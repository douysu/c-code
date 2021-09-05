#include "geometry.h"
#include <iostream>


template <> template <> vec<2, int>::vec(const vec<2, float>& v){
	x = int(v.x + .5f);
	y = int(v.y + .5f);
	std::cout << "int and float" << std::endl;
}

template <> vec<2, int>::vec(const vec<2, int>& v) {
	std::cout << "int and int" << std::endl;
}

template <> template <> vec<2, float>::vec(const vec<2, int>& v){
	x = v.x;
	y = v.y;
	std::cout << "float and int" << std::endl;
}

template <> vec<2, float>::vec(const vec<2, float>& v) {
	std::cout << "float and float" << std::endl;
}

