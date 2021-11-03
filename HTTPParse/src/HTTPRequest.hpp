/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   HTTPRequest.hpp                                   e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:04:40 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/03 13:14:00 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#define DEBUG		true
#define print_debug(message, debug, w) {\
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

#define UNSET		-1
#define GET			0
#define POST		1
#define DELETE		2

class HTTPRequest {
	public:
		HTTPRequest() : _request(""), _method(-1), _URI("") {};
		HTTPRequest(std::string request, int method, std::string URI) : _request(request), _method(method), _URI(URI) {};
		HTTPRequest(std::string request) : _request(request), _method(-1), _URI("") {
			parseRequest(_request);
		};
		~HTTPRequest() {};

		//Parse an HTTP request
		int				parseRequest(std::string request) {
			print_debug("raw", _request, 10);
			if (parseMethod(&request))
				return 1;
			if (parseURI(&request))
				return 1;
			return 0;
		}

		//Find and identify method, removes from string
		int				parseMethod(std::string *request) {
			unsigned long	pos;
			std::string		rmethod;
			std::string		methods[] = {"GET", "POST", "DELETE"};

			pos = request->find(" ");
			if (pos == -1u || pos > request->find("\n"))
				return 1;
			rmethod = request->substr(0, pos);
			for (unsigned long i = 0; i < methods->length(); i++) {
				if (methods[i].compare(rmethod) == 0) {
					_method = i;
					*request = request->substr(pos + 1, request->length());
					print_debug("method", _method, 10); 
					print_debug("request", *request, 10); 
					break;
				}
			}
			return 0;
		}
		
		//Find and identify method, removes from string
		int				parseURI(std::string *request) {//TODO test this pls
			unsigned long	pos;
			std::string		rURI;
			std::string		methods[] = {"GET", "POST", "DELETE"};

			pos = request->find(" ");
			if (pos == -1ul)
				pos = request->find("\r");
			if (pos == -1ul)
				return 1;
			print_debug("pos", pos, 10); 
			_URI = request->substr(0, pos);
			*request = request->substr(pos + 1, request->length());
			print_debug("URI", _URI, 10); 
			print_debug("request", *request, 10);
			return 0;
		}


		std::string		getRequest() { return _request; };
		void			setRequest(std::string r) { _request = r; };
		int				getMethod() { return _method; };
		void			setMethod(int m) { _method = m; };
		std::string		getURI() { return _URI; };
		void			setURI(std::string u) { _URI = u; };

	protected:
		std::string		_request;
		int				_method;
		std::string		_URI;
};


/* class GETRequest : public HTTPRequest { */
/* 	public: */
/* 		GETRequest() : HTTPRequest(), _path("") {}; */
/* 		GETRequest(std::string request, int method, std::string path) : HTTPRequest(request, method), _path(path) {}; */
/* 		GETRequest(std::string request) : HTTPRequest(request), _path("") { */
/* 			parseRequest(_request); */
/* 		}; */
/* 		~GETRequest() {}; */
/* 		int				parseRequest(std::string request) { */
/* 			(void)request; */
/* 			print_debug("child"); */
/* 			return 0; */
/* 		} */
/* 	private: */
/* }; */
