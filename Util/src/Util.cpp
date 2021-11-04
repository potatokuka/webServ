/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   Util.cpp                                          e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:37:28 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/04 15:27:08 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "Util.hpp"

std::string		skip_whitespace(std::string str) {
	int i = 0;
	while (str[i] == ' ') {
		i++;
	}
	str = str.substr(i, str.length());
	return str;
}
