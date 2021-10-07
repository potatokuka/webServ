#ifndef SIMPLESOCKET_HPP
#define SIMPLESOCKET_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace hde {
    class SimpleSocket {
        private:
        struct sockaddr_in address;
            int sock;
            int connection;
        public:
            // constructor
            SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
            // virtual function to connect to a network
            virtual int  connect_to_network(int sock, struct sockaddr_in) = 0;
            // function to test socks and connection
            void test_connection(int);
            // getter functions
            struct sockaddr_in get_address();
            int get_sock();
            int get_connection();
    };
}


#endif
