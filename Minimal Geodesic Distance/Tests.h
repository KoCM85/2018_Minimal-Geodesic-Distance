#ifndef TESTS_H
#define TESTS_H

#include <tuple>

// Singleton
class test
{
	test() {}
	test(const test &) = delete;
	test & operator=(const test &) = delete;
public:
	// return instance of class
	static test & getInstance();

	// runs test for function degreesToRadians(const double &)
	void test_degreesToRadians();

	// runs test for function degreesMinutesSecondsToDegrees(const double &, const double &, const double &, const char &)
	void test_degreesMinutesSecondsToDegrees();

	// runs test for function computeDistance(const coordinate &, const coordinate &, double &)
	void test_computeDistance();

	// runs test for function computeShorterDistance(const setCoordinates &, const setCoordinates &, double &)
	void test_computeShorterDistance();

	// runs all tests
	void testAll();
};

#endif //TESTS_H