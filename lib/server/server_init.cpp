#include "server_init.h"



void server_init(){
  struct sockaddr_in default_sock = {
    .sin_family = AF_INET, 
    .sin_port   = htons( PORT_NUMBER ), 
    .sin_addr = { .s_addr = inet_addr("127.0.0.1")}, 
    .sin_zero = { 0 }
  };

  struct sockaddr_storage user_sock;
  int sockfd, newfd, rv ; 
  socklen_t sz_sockaddr_storage = sizeof( struct sockaddr_storage ) ; 
  char buffer[BUFFER_SIZE] ; 

  sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ; 
  ERRNO_CHECK( sockfd ) ; 

  rv = bind( sockfd, ( struct sockaddr* ) &default_sock, sizeof( struct sockaddr_in )) ;  
  ERRNO_CHECK( rv ) ; 

  rv = listen( sockfd, 10 )  ;
  ERRNO_CHECK( rv ) ; 

  while( true ){

    newfd = accept( sockfd , ( struct sockaddr* ) &user_sock, &sz_sockaddr_storage ) ; 
    ERRNO_CHECK( newfd ) ; 

    if( !fork() ) { 
      close(sockfd) ; 

      int bytes = recv( newfd, buffer, BUFFER_SIZE, 0) ; 
      ERRNO_CHECK( bytes ); 

      dispatch_request(buffer) ; 

      close(newfd) ; 
      exit(0) ; 
    }
    close(newfd) ; 
  }
}

