/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   main.cpp                                          e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:46:50 by dries             *8*   8   *8*          */
/*   Updated: 2021/10/07 14:48:06 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "ExampleClass.hpp"
#include "ExampleFunction.hpp"

int		main(void) {
	ExampleClass e;

	e._wow = 5;

	std::cout << "testing some random functions if they run" << std::endl;
	std::cout << e.albert(5) << std::endl;
	std::cout << e.jeff() << std::endl;
	std::cout << times_3(5) << std::endl;
}
