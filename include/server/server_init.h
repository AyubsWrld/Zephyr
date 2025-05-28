#pragma once 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstddef>
#include <errno.h> 
#include <unistd.h> 
#include <iostream>
#include <string.h>
#include "events.h" 

#define    PORT_NUMBER     4090
#define    MAX_QUEUE       10
#define    BUFFER_SIZE     1024

#define ERRNO_CHECK( X ) {\
  static_assert( std::is_same<decltype(X), int>::value, "arg must be of type int");\
  if( X == -1 ){ fprintf(stderr, "\033[31m[ LINE: %i ] : %s \033[0m ", __LINE__, strerror( errno ));  exit(EXIT_FAILURE);}}


void server_init() ; 


