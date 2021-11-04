/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   HTTPRequest.cpp                                   e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:02:17 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/04 15:53:35 by dries               **ee8ee**            */
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
	bool			v = false;
	std::string		s = "testing";
	int				i = 27;
	std::string		s2 = "testing123";
	int				i2 = 1;

	_req = HTTPRequest(v, s, i, s2, i2);
	EXPECT_EQ(_req.getValid(), v);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), i);
	EXPECT_EQ(_req.getURI(), s2);
	EXPECT_EQ(_req.getHTTPver(), i2);
}

TEST_F(HTTPRequestTest, ParseGETRequest) {
	std::string		s = "GET / HTTP/1.1\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), true);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), GET);
	EXPECT_EQ(_req.getURI(), "/");
	EXPECT_EQ(_req.getHTTPver(), 1);
}

TEST_F(HTTPRequestTest, ParseGETRequestHTTP1_0) {
	std::string		s = "GET / HTTP/1.0\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), true);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), GET);
	EXPECT_EQ(_req.getURI(), "/");
	EXPECT_EQ(_req.getHTTPver(), 1);
}

TEST_F(HTTPRequestTest, ParseGETNoHTTPver) {
	std::string		s = "GET /\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), true);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), GET);
	EXPECT_EQ(_req.getURI(), "/");
	EXPECT_EQ(_req.getHTTPver(), 0);
}

TEST_F(HTTPRequestTest, ParseGETNoHTTPverWhitespace) {
	std::string		s = "GET /  \r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), true);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), GET);
	EXPECT_EQ(_req.getURI(), "/");
	EXPECT_EQ(_req.getHTTPver(), 0);
}

TEST_F(HTTPRequestTest, ParseGETRequestInvalid1) {
	std::string		s = "GET\n / HTTP/1.1\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), false);
	EXPECT_EQ(_req.getRequest(), s);
	/* EXPECT_EQ(_req.getMethod(), -1); */
	/* EXPECT_EQ(_req.getURI(), ""); */
	/* EXPECT_EQ(_req.getHTTPver(), 0); */
}

TEST_F(HTTPRequestTest, ParseGETRequestWhitespace) {
	std::string		s = "GET       /             HTTP/1.1\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), true);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), 0);
	EXPECT_EQ(_req.getURI(), "/");
	EXPECT_EQ(_req.getHTTPver(), 1);
}

TEST_F(HTTPRequestTest, ParsePOSTRequest) {
	std::string		s = "POST /login.php HTTP/1.1\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), true);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), POST);
	EXPECT_EQ(_req.getURI(), "/login.php");
	EXPECT_EQ(_req.getHTTPver(), 1);
}

TEST_F(HTTPRequestTest, ParseDELETERequest) {
	std::string		s = "DELETE /mynudes.jpg HTTP/1.1\r\n\r\n";

	_req = HTTPRequest(s);
	EXPECT_EQ(_req.getValid(), true);
	EXPECT_EQ(_req.getRequest(), s);
	EXPECT_EQ(_req.getMethod(), DELETE);
	EXPECT_EQ(_req.getURI(), "/mynudes.jpg");
	EXPECT_EQ(_req.getHTTPver(), 1);
}
