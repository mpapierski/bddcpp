#if !defined(BDDCPP_RUNNERS_CONSOLE_INCLUDED_HPP_)
#define BDDCPP_RUNNERS_CONSOLE_INCLUDED_HPP_

#include <iostream>
#include <bddcpp/aux/runner.hpp>

namespace bddcpp { namespace runners { 

struct console: runner
{
	unsigned int level_;
	console()
		: level_(0)
	{
	}
	void indent(int offset = 0)
	{
		for (int i = 0; i < offset + level_; i++)
		{
			std::cout << " ";
		}
	}
	void suiteStart(const char * name)
	{
		indent();
		std::cout << name << std::endl;
		level_++;
	}
	void suiteStop(const char * name)
	{
		std::cout << std::endl;
		level_--;
	}
	void testFinished(bool successOrFailure)
	{
		const char * message = successOrFailure ? "." : "F";
		std::cout << message;
	}
};

}} /* /bddcpp/runners */

#endif /* BDDCPP_RUNNERS_CONSOLE_INCLUDED_HPP_ */