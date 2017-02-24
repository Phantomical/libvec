#pragma once

#include "vector_base.h"
#include "operators.h"
#include "functions.h"

namespace vec
{
	template<typename T>
	using tvec2 = tvec_base<T, 2>;
	template<typename T>
	using tvec3 = tvec_base<T, 3>;
	template<typename T>
	using tvec4 = tvec_base<T, 4>;

	typedef tvec2<float> vec2;
	typedef tvec3<float> vec3;
	typedef tvec4<float> vec4;

	typedef tvec2<double> dvec2;
	typedef tvec3<double> dvec3;
	typedef tvec4<double> dvec4;
}
