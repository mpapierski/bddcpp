#if !defined(BDDCPP_AUX_MATCHERS_TOBE_INCLUDED_HPP_)
#define BDDCPP_AUX_MATCHERS_TOBE_INCLUDED_HPP_

#include <bddcpp/aux/env.hpp>

namespace bddcpp {

template <typename T>
struct tobe_
{
	T & expectation_;
	tobe_(T & expectation)
		: expectation_(expectation)
	{

	}
	template <typename F>
	void operator()(F f)
	{
		bool result = expectation_() == f;
		env::getInstance().testRunner()->testFinished(result);
	}
};

} /* /bddcpp */

#endif /* BDDCPP_AUX_MATCHERS_TOBE_INCLUDED_HPP_ */