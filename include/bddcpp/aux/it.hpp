#if !defined(BDDCPP_AUX_IT_INCLUDED_HPP_)
#define BDDCPP_AUX_IT_INCLUDED_HPP_

#include <functional>
#include <bddcpp/aux/env.hpp>

namespace bddcpp {

void it(const char * name, std::function<void()> fn)
{
	assert(fn && "Unable to call invalid function object.");
	env::getInstance().testRunner()->suiteStart(name);
	fn();
	env::getInstance().testRunner()->suiteStop(name);
}

} /* /bddcpp */

#endif /* BDDCPP_AUX_IT_INCLUDED_HPP_ */