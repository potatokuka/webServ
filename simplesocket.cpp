#include "simplesocket.hpp"

// default constructor
hde::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface) {
    // define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    // establish socket
    int sock = socket(domain, service, protocol);
    test_connection(sock);
    // establish network connection
    connection = connect_to_network(sock, address);
    test_connection(connection);
}

// test connection virtual function
void hde::SimpleSocket::test_connection(int item_to_test){
    // confirm that either sock or connection has been properly established
    if (item_to_test < 0) {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
}


// getter functions
struct sockaddr_in hde::SimpleSocket::get_address(){
    return address;
}

int hde::SimpleSocket::get_sock() {
    return sock;
}

int hde::SimpleSocket::get_connection() {
    return connection;
}
