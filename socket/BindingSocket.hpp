#ifndef BindingSocket_HPP
#define BINDINGSOCKET_HPP

#include <stdio.h>
#include "simplesocket.hpp"

namespace hde {
    class BindingSocket: public SimpleSocket {
        public:
            BindingSocket(int domain, int service, int protocol,
                int port, u_long interface);
            int connect_to_network(int sock, struct sockaddr_in address); 
    };
}

#endif // binding socket hpp