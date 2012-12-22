#include <bddcpp/bddcpp.hpp>

int main()
{
	using namespace bddcpp;

	describe("A suite", []() {
		it("contains spec with an expectation", []() {
			expect(true).toBe(true);
		});
	});

	describe("A suite is just a function", []() {
		bool a;
		it("and so is a spec", [&a]() {
			a = true;
			expect(a).toBe(true);
		});
	});
}