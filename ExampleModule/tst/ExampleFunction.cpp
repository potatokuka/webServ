/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   ExampleFunction.cpp                               e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:38:00 by dries             *8*   8   *8*          */
/*   Updated: 2021/10/07 14:41:34 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "ExampleFunction.hpp"
#include "gtest/gtest.h"

TEST(ExampleFunction, DoesItMultiply) {
	ASSERT_EQ(times_3(3), 9);
}
