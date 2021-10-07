#ifndef CONNECTINGSOCKET_HPP
#define CONNECTINGSOCKET_HPP

#include <stdio.h>
#include "simplesocket.hpp"

namespace hde {
    class ConnectingSocket: public SimpleSocket {
        public:
            ConnectingSocket(int domain, int service, int protocol,
                int port, u_long interface);
            int connect_to_network(int sock, struct sockaddr_in address); 
    };
}
#endif //connecting socket