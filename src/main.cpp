#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <errno.h> 


#define PORT_NUBMER 4090
#define MAX_QUEUE_LIST 10


int main (int argc, char *argv[]) 
{
  int sockfd, newfd, status ; 
  struct sockaddr_storage user_entry_point ; 
  struct sockaddr_in sock_address = {
      .sin_family = AF_INET, 
      .sin_port = htons( 4090 ), 
      .sin_addr = { .s_addr = inet_addr("127.0.0.1") },
      .sin_zero = { 0 } 
  };


  sockfd = socket( AF_INET , SOCK_STREAM, 0 ) ; 
  if( sockfd == -1 ){ 
    fprintf( stderr, "socket: %s\n", strerror( errno )) ; 
    exit(EXIT_FAILURE) ;
  }

  if( ( status = bind( sockfd, ( struct sockaddr* ) &sock_address, sizeof( sock_address ))) == -1 ) {
    fprintf( stderr, "bind: %s\n", strerror( errno )) ; 
    exit(EXIT_FAILURE) ;
  }

  if( listen( sockfd, MAX_QUEUE_LIST ) == -1 ) {
    fprintf( stderr, "listen: %s\n", strerror( errno )) ; 
    exit(EXIT_FAILURE) ;
  }

  socklen_t len = sizeof( struct sockaddr_storage ) ; 
  newfd = accept( sockfd, ( struct sockaddr* )  &user_entry_point ,  &len );

  if( newfd == -1 ) {
    fprintf( stderr, "accept: %s\n", strerror( errno )) ; 
    exit(EXIT_FAILURE) ;
  }

  char buffer[8] ; 
  int bytes = recv( newfd, buffer, sizeof( buffer ), 0 )  ;


  std::cout << bytes << std::endl ; 
  std::cout << buffer << std::endl ; 

  close( sockfd ) ; 
  close( newfd  ) ; 
  return 0;
}
