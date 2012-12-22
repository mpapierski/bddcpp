#if !defined(BDDCPP_AUX_DESCRIBE_INCLUDED_HPP_)
#define BDDCPP_AUX_DESCRIBE_INCLUDED_HPP_

#include <functional>
#include <bddcpp/aux/env.hpp>

namespace bddcpp {

void describe(const char * name, std::function<void()> && fn)
{
	env::getInstance().addSuite(suite(name, std::forward<std::function<void()>>(fn)));
}

} /* /bddcpp */

#endif /* BDDCPP_AUX_DESCRIBE_INCLUDED_HPP_ */