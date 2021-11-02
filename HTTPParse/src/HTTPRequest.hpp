/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   HTTPRequest.hpp                                   e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:04:40 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/02 14:21:11 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define DEBUG		true
#define print_debug(message) {if (DEBUG) {std::cout << message << std::endl;}}

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

		int				parseRequest(std::string request) {
			int				pos;
			std::string		rmethod;
			std::string		methods[] = {"GET", "POST", "DELETE"};

			print_debug("parent");
			pos = request.find(" ");
			rmethod = request.substr(0, pos);
			for (unsigned long i = 0; i < methods->length(); i++) {
				if (methods[i].compare(rmethod) == 0) {
					_method = i;
					request = request.substr(pos + 1, request.length());
					print_debug("method: 	" << _method 
							<< "\nrequest: \t'" << request 
							<< "'\nraw: \t'" << _request << "'")
					break;
				}
			}
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
