#if !defined(BDDCPP_RUNNER_INCLUDED_HPP_)
#define BDDCPP_RUNNER_INCLUDED_HPP_

namespace bddcpp {

struct runner
{
	virtual void suiteStart(const char * name)
	{
	}
	virtual void suiteStop(const char * name)
	{
	}
	virtual void testFinished(bool successOrFailure)
	{
	}
};

} /* /bddcpp */

#endif /* BDDCPP_RUNNER_INCLUDED_HPP_ */