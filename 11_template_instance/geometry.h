#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

// 定义向量
// 任意维度的vec
template <size_t DIM, typename T> struct vec
{
	vec() { for (size_t i = DIM; i--; m_data[i] = T());}
	T& operator[](const size_t i) { assert(i < DIM); return m_data[i]; }
	const T& operator[](const size_t i) const { assert(i < DIM); return m_data[i]; }
private:
	T m_data[DIM];
};

// 特化
template <typename T> struct vec<2, T>
{
	T x, y;
	vec() :x(), y() {}
	vec(T X, T Y) : x(X), y(Y) {}
	vec<2, T>(const vec<2, T>& v);
	template <typename U> vec<2, T>(const vec<2, U>& v);
	T& operator[](const size_t i) { assert(i < 2); return i <= 0 ? x : y; }
	const T& operator[](const size_t i) const { assert(i < 2); return i <= 0 ? x : y; }
};

template <typename T, typename U> struct test
{

};

template <typename T> struct test<int, T>
{

};

typedef vec<2, int>		Vec2i;
typedef vec<2, float>   Vec2f;
