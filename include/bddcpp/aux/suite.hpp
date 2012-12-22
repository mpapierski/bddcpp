#if !defined(BDDCPP_AUX_SUITE_INCLUDED_HPP_)
#define BDDCPP_AUX_SUITE_INCLUDED_HPP_

#include <functional>
#include <cassert>

namespace bddcpp {

struct suite
{
	const char * name_;
	std::function<void()> function_;
	suite(const char * name, std::function<void()> fn)
		: name_(name)
		, function_(fn)
	{
	}
	void operator()()
	{
		assert(function_ && "Unable to call invalid function.");
		function_();
	}
	inline const char * name() const
	{
		return name_;
	}
};

} /* /bddcpp */

#endif /* BDDCPP_AUX_SUITE_INCLUDED_HPP_ */