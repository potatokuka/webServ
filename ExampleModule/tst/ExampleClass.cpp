/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   ExampleClass.cpp                                  e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:02:17 by dries             *8*   8   *8*          */
/*   Updated: 2021/10/07 14:35:27 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "ExampleClass.hpp"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class ExampleClassTest : public ::testing::Test {
	protected:
	// You can remove any or all of the following functions if their bodies would
	// be empty.

	ExampleClassTest() {
		// You can do set-up work for each test here.
	}

	~ExampleClassTest() override {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	void SetUp() override {
		_e._wow = 5;
	}

	void TearDown() override {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Class members declared here can be used by all tests in the test suite
	// for Foo.
	ExampleClass	_e;
};

TEST_F(ExampleClassTest, DoesItWorkJeff) {
	EXPECT_EQ(_e.jeff(), _e._wow);
}

TEST_F(ExampleClassTest, DoesItWorkAlbert) {
	EXPECT_EQ(_e.albert(10), 20);
}

/* TEST_F(ExampleClassTest, WillNotPass) { */
/* 	EXPECT_EQ(_e.albert(10), 0); */
/* } */
