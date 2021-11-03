/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   HTTPRequest.cpp                                   e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:02:17 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/03 13:11:53 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "HTTPRequest.hpp"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class HTTPRequestTest : public ::testing::Test {
	protected:
	// You can remove any or all of the following functions if their bodies would
	// be empty.

	HTTPRequestTest() {
		// You can do set-up work for each test here.
	}

	~HTTPRequestTest() override {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	void SetUp() override {
	}

	void TearDown() override {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Class members declared here can be used by all tests in the test suite
	// for Foo.
	HTTPRequest	_req;
};

TEST_F(HTTPRequestTest, EmptyConstructor) {
	_req = HTTPRequest();
	EXPECT_EQ(_req.getRequest(), "");
	EXPECT_EQ(_req.getMethod(), -1);
	EXPECT_EQ(_req.getURI(), "");
}

TEST_F(HTTPRequestTest, AssignedConstructor) {
	std::string		s = "testing";
	int				i = 27;
	std::string		s2 = "testing123";

	_req = HTTPRequest(s, i, s2);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), i);
	EXPECT_EQ(_req.getURI(), s2);
}

TEST_F(HTTPRequestTest, ParsedGETRequest) {
	std::string		s = "GET /\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), GET);
	EXPECT_EQ(_req.getURI(), "/");
}

TEST_F(HTTPRequestTest, ParsedGETRequestInvalid1) {
	std::string		s = "GET\n /\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), -1);
	EXPECT_EQ(_req.getURI(), "");
}

TEST_F(HTTPRequestTest, ParsedPOSTRequest) {
	std::string		s = "POST /\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), POST);
	EXPECT_EQ(_req.getURI(), "/");
}

TEST_F(HTTPRequestTest, ParsedDELETERequest) {
	std::string		s = "DELETE /\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), DELETE);
	EXPECT_EQ(_req.getURI(), "/");
}
