#if !defined(BDDCPP_AUX_EXPECT_INCLUDED_HPP_)
#define BDDCPP_AUX_EXPECT_INCLUDED_HPP_

#include <bddcpp/aux/matchers/tobe.hpp>

namespace bddcpp {

template <typename T>
struct expect_
{
	typedef expect_<T> this_type;

	T t_;

	tobe_<this_type> toBe;

	expect_(T t)
		: t_(t)
		, toBe(*this)
	{

	}
	T & operator()()
	{
		return t_;
	}
};


template <typename T>
expect_<T> expect(T t)
{
	return expect_<T>(t);
}

} /* /bddcpp */

#endif /* BDDCPP_AUX_EXPECT_INCLUDED_HPP_ */