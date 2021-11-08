/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   HTTPRequest.hpp                                   e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/10/07 14:04:40 by dries             *8*   8   *8*          */
/*   Updated: 2021/11/08 14:21:51 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP
#include <iostream>
#include <string>
#include <sstream>
#include "Util.hpp"

#define UNSET		-1
#define GET			0
#define POST		1
#define DELETE		2

class HTTPRequest {
	public:
		HTTPRequest() : _valid(false), _request(""), _method(-1), _URI(""), _HTTPver(0) {};
		HTTPRequest(bool valid, std::string request, int method, std::string URI, int HTTPver) : _valid(valid), _request(request), _method(method), _URI(URI), _HTTPver(HTTPver) {};
		HTTPRequest(std::string request) : _valid(true), _request(request), _method(-1), _URI(""), _HTTPver(0) {
			parseRequestLine(_request);
		};
		~HTTPRequest() {};

		int				parseRequestLine(std::string request) {
			print_debug("raw", _request, 10);
			if (parseMethod(&request))
				return invalid();
			if (parseURI(&request))
				return invalid();
			if (parseHTTPver(&request))
				return invalid();
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
					/* print_debug("request", *request, 10);  */
					break;
				}
			}
			return 0;
		}
		
		//Find and identify method, removes from string
		int				parseURI(std::string *request) {//TODO test this pls
			unsigned long	pos;

			*request = skip_whitespace(*request);
			pos = request->find(" ");
			if (pos == -1ul)
				pos = request->find("\r");
			if (pos == -1ul)
				return 1;
			/* print_debug("pos", pos, 10);  */
			_URI = request->substr(0, pos);
			*request = request->substr(pos + 1, request->length());
			print_debug("URI", _URI, 10); 
			/* print_debug("request", *request, 10); */
			return 0;
		}

		//Find and identify method, removes from string
		int				parseHTTPver(std::string *request) {//TODO test this pls
			unsigned long	pos;
			std::string		rHTTPver;
			std::string		methods[] = {"GET", "POST", "DELETE"};

			*request = skip_whitespace(*request);
			pos = request->find(" ");
			if (pos == -1ul)
				pos = request->find("\r");
			if (pos == -1ul)
				return 1;
			/* print_debug("pos", pos, 10);  */
			rHTTPver = request->substr(0, pos);
			if (rHTTPver.compare("HTTP/1.1") == 0)
				_HTTPver = 1;
			if (rHTTPver.compare("HTTP/1.0") == 0)
				_HTTPver = 1;
			*request = request->substr(pos + 1, request->length());
			/* print_debug("rHTTPver", rHTTPver, 10);  */
			print_debug("HTTPver", _HTTPver, 10); 
			/* print_debug("request", *request, 10); */
			return 0;
		}

		bool			getValid() { return _valid; };
		void			setValid(bool v) { _valid = v; };
		int				invalid() { _valid = false; return 1; };
		std::string		getRequest() { return _request; };
		void			setRequest(std::string r) { _request = r; };
		int				getMethod() { return _method; };
		void			setMethod(int m) { _method = m; };
		std::string		getURI() { return _URI; };
		void			setURI(std::string u) { _URI = u; };
		int				getHTTPver() { return _HTTPver; };
		void			setHTTPver(int h) { _HTTPver = h; };

	protected:
		bool			_valid;
		std::string		_request;
		int				_method;
		std::string		_URI;
		int				_HTTPver;
};
#endif
