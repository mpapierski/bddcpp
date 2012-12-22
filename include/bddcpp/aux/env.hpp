#if !defined(BDDCPP_AUX_ENV_INCLUDED_HPP_)
#define BDDCPP_AUX_ENV_INCLUDED_HPP_

#include <list>
#include <bddcpp/aux/runner.hpp>
#include <bddcpp/aux/runners/console.hpp>

namespace bddcpp {

class env
{
	std::list<suite> suites_;
	runner * test_runner_;
	env()
		: test_runner_(0)
	{
	}
	env(env const &)
	{

	}
	env & operator=(env const &)
	{
		return *this;
	}
public:
	~env()
	{
		if (!test_runner_)
		{
			// Set up default test runner
			test_runner_ = new bddcpp::runners::console();
		}
		for(auto test : suites_)
		{
			test_runner_->suiteStart(test.name());
			test();
			test_runner_->suiteStop(test.name());
		}
		if (test_runner_)
			delete test_runner_;
	}
	static env & getInstance()
	{
		static env instance_;
		return instance_;
	}

	void addSuite(suite && newSuite)
	{
		suites_.emplace_back(std::forward<suite>(newSuite));
	}

	inline runner * testRunner()
	{
		assert(test_runner_ && "No test runner configured!");
		return test_runner_;
	}
};

} /* /bddcpp */

#endif /* BDDCPP_AUX_ENV_INCLUDED_HPP_ */