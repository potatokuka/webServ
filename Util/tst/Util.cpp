/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   Util.cpp                                          e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:38:00 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/03 16:47:36 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "Util.hpp"
#include "gtest/gtest.h"

TEST(ExampleFunction, basic1) {
	ASSERT_EQ(skip_whitespace("          a"), "a");
}

TEST(ExampleFunction, basic2) {
	ASSERT_EQ(skip_whitespace("          a         "), "a         ");
}

TEST(ExampleFunction, noAction) {
	ASSERT_EQ(skip_whitespace("a          a"), "a          a");
}

TEST(ExampleFunction, inContext) {
	ASSERT_EQ(skip_whitespace("        / HTTP1.1"), "/ HTTP1.1");
}
