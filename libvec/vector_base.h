#pragma once

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
		template<typename T, size_t sz>
		struct tvec_base_info
		{
			static constexpr size_t length = sz;
			typedef T value_type;
		};
	}

	template<typename T, size_t sz>
	struct tvec_base : detail::tvec_base_info<T, sz>
	{
		value_type m[sz];

		value_type& operator[](size_t l)
		{
			// If this triggers then you accessed a vector out of bounds
			LIBVEC_ASSERT(l < sz);
			return m[l];
		}
		const value_type& operator[](size_t l) const
		{
			// If this triggers then you accessed a vector out of bounds
			LIBVEC_ASSERT(l < sz);
			return m[l];
		}
	};

	template<typename T>
	struct tvec_base<T, 3> : detail::tvec_base_info<T, 3>
	{
		union
		{
			value_type m[3];
			struct
			{
				value_type x;
				value_type y;
				value_type z;
			};
		};

		value_type& operator[](size_t l)
		{
			// If this triggers then you accessed a vector out of bounds
			LIBVEC_ASSERT(l < sz);
			return m[l];
		}
		const value_type& operator[](size_t l) const
		{
			// If this triggers then you accessed a vector out of bounds
			LIBVEC_ASSERT(l < sz);
			return m[l];
		}

		template<typename U>
		tvec_base(const U& v) :
			m({ v[0], v[1], v[2] })
		{

		}
		tvec_base(
			const value_type& x,
			const value_type& y,
			const value_type& z) :
			x(x), y(y), z(z)
		{

		}
	};

	template<typename T>
	struct tvec_base<T, 2> : detail::tvec_base_info<T, 2>
	{
		union
		{
			value_type m[2];
			struct
			{
				value_type x;
				value_type y;
			};
		};

		value_type& operator[](size_t l)
		{
			// If this triggers then you accessed a vector out of bounds
			LIBVEC_ASSERT(l < sz);
			return m[l];
		}
		const value_type& operator[](size_t l) const
		{
			// If this triggers then you accessed a vector out of bounds
			LIBVEC_ASSERT(l < sz);
			return m[l];
		}

		template<typename U>
		tvec_base(const U& v) :
			m({ v[0], v[1] })
		{

		}
		tvec_base(
			const value_type& x,
			const value_type& y) :
			x(x), y(y)
		{

		}
	};

	template<typename T, size_t sz>
	T* begin(tvec_base<T, sz>& v)
	{
		return v.m;
	}
	template<typename T, size_t sz>
	T* end(tvec_base<T, sz>& v)
	{
		return v.m + sz;
	}

	template<typename T, size_t sz>
	const T* begin(const tvec_base<T, sz>& v)
	{
		return v.m;
	}
	template<typename T, size_t sz>
	const T* end(const tvec_base<T, sz>& v)
	{
		return v.m + sz;
	}
}
