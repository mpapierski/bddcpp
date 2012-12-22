CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (bdd_test)

ADD_EXECUTABLE (bdd_test
	bdd.cpp)

ADD_TEST (bdd_test
	bdd_test)