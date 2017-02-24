#pragma once

#include "vector_base.h"

namespace vec
{
	template<typename T, size_t sz>
	tvec_base<T, sz> operator +(const tvec_base<T, sz>& lhs, const tvec_base<T, sz>& rhs) 
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] + rhs[i];
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator -(const tvec_base<T, sz>& lhs, const tvec_base<T, sz>& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] - rhs[i];
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator *(const tvec_base<T, sz>& lhs, const tvec_base<T, sz>& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] * rhs[i];
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator /(const tvec_base<T, sz>& lhs, const tvec_base<T, sz>& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] / rhs[i];
		}
		return result;
	}

	template<typename T, size_t sz>
	tvec_base<T, sz> operator +(const tvec_base<T, sz>& lhs, const T& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] + rhs;
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator -(const tvec_base<T, sz>& lhs, const T& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] - rhs;
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator *(const tvec_base<T, sz>& lhs, const T& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] * rhs;
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator /(const tvec_base<T, sz>& lhs, const T& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs[i] / rhs;
		}
		return result;
	}

	template<typename T, size_t sz>
	tvec_base<T, sz> operator +(const T& lhs, const tvec_base<T, sz>& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs + rhs[i];
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator -(const T& lhs, const tvec_base<T, sz>& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs - rhs[i];
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator *(const T& lhs, const tvec_base<T, sz>& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs * rhs[i];
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator /(const T& lhs, const tvec_base<T, sz>& rhs)
	{
		tvec_base<T, sz> result;
		/* The loop should be easy for the compiler to
		optimize or vectorize as it has constant
		iterations. */
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = lhs / rhs[i];
		}
		return result;
	}

	template<typename T, size_t sz>
	tvec_base<T, sz> operator -(const tvec_base<T, sz>& v)
	{
		tvec_base<T, sz> result;
		for (size_t i = 0; i < sz; ++i)
		{
			result[i] = -v[i];
		}
		return result;
	}
	template<typename T, size_t sz>
	tvec_base<T, sz> operator +(const tvec_base<T, sz>& v)
	{
		return v;
	}
}
