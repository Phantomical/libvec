#pragma once

#include <cmath>
#include <numeric>
#include <type_traits>

#ifdef LIBVEC_USE_ASSERTS
#include <assert.h>
#define LIBVEC_ASSERT(x) assert(x)
#else
#define LIBVEC_ASSERT(x)
#endif

namespace vec
{
	namespace detail
	{
		template<typename T>
		using elem_t = decltype(std::declval<T>()[0]);

		template<typename T, typename Fx>
		T map(const T& a, const T& b, const Fx& func)
		{
			const T result;
			LIBVEC_ASSERT(a.size() == b.size());
			
			for (size_t i = 0; i < a.size(); ++i)
			{
				result[i] = func(a[i], b[i]);
			}

			return result;
		}
	}

	template<typename T>
	detail::elem_t<T> dot(const T& lhs, const T& rhs)
	{
		using std::begin;
		using std::end;

		const T r = lhs * rhs;

		return std::accumulate(begin(r), end(r), detail::elem_t<T>(0.0));
	}

	template<typename T>
	detail::elem_t<T> length2(const T& v)
	{
		return dot(v, v);
	}
	template<typename T>
	detail::elem_t<T> length(const T& v)
	{
		using std::sqrt;

		return sqrt(dot(v, v));
	}

	template<typename T>
	T min(const T& a, const T& b)
	{
		return detail::map(a, b, 
			[](const auto& rhs, const auto& lhs) {
			return rhs < lhs ? rhs : lhs;
		});
	}
	template<typename T>
	T max(const T& a, const T& b)
	{
		return detail::map(a, b,
			[](const auto& rhs, const auto& lhs) {
			return rhs > lhs ? rhs : lhs;
		});
	}

	template<typename T>
	T normalize(const T& v)
	{
		auto q = T(1.0) / 
	}

	template<typename T>
	T lerp(const T& a, const T& b, const detail::elem_t<T>& f)
	{
		return a * (T(1.0) - f) + b * f;
	}

	template<typename T>
	T cross(const T& a, const T& b)
	{
		static_assert(T::length == 3, "Cross product is only valid for vectors of length 3.");
		LIBVEC_ASSERT(a.size() == b.size() && a.size() == 3);

		return {
			a[1] * b[2] - a[2] * b[1],
			a[2] * b[0] - a[0] * b[2],
			a[0] * b[1] - a[1] * b[0]
		};
	}
}

#undef LIBVEC_ASSERT
