/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   Util.hpp                                          e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:36:47 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/04 15:27:05 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
#define UTIL_HPP
#include <string>
#include <sstream>
#include <iostream>

#define DEBUG		true
#define print_debug_m(message, debug, w) {\
	if (DEBUG) {\
		std::stringstream 	buf; \
		std::string			str; \
		char				escs[2] = {'\r', '\n'}; \
		std::string			litr[2] = {"\\r", "\\n"}; \
		bool				flag; \
		/*Assemble string to print */\
		str = message; \
		buf << str; \
		for (int i = str.length(); i < w; i++) { \
			buf << " "; \
		} \
		buf << "'" << debug << "'"; \
		str = buf.str(); \
		/*Print string */\
		for (unsigned int i = 0; i < str.length(); i++) { \
			/*Literal print escaped characters */\
			flag = false; \
			for (int c = 0; c < 2; c++) { \
				if(str[i] == escs[c]) { \
					std::cout << litr[c]; \
					flag = true; \
					break; \
				} \
			} \
			/*Print non-escaped characters */\
			if (!flag) \
				std::cout << str[i]; \
		} \
		std::cout << std::endl;\
	}}
 
std::string		skip_whitespace(std::string str);

template<class debug_type>
void 			print_debug(std::string message, debug_type debug, int w) {
	if (DEBUG) {
		std::stringstream 	buf; 
		std::string			str; 
		char				escs[2] = {'\r', '\n'}; 
		std::string			litr[2] = {"\\r", "\\n"}; 
		bool				flag; 
		/*Assemble string to print */
		str = message;
		buf << str; 
		for (int i = str.length(); i < w; i++) { 
			buf << " "; 
		} 
		buf << "'" << debug << "'"; 
		str = buf.str(); 
		/*Print string */
		for (unsigned int i = 0; i < str.length(); i++) { 
			/*Literal print escaped characters */
			flag = false; 
			for (int c = 0; c < 2; c++) { 
				if(str[i] == escs[c]) { 
					std::cout << litr[c]; 
					flag = true; 
					break; 
				} 
			} 
			/*Print non-escaped characters */
			if (!flag) 
				std::cout << str[i]; 
		} 
		std::cout << std::endl;
	}
}
#endif
