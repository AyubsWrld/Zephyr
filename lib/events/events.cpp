#include "events.h"
#include <iostream>

Status routine_one()
{
  std::cout << "Routine One" << std::endl ; 
  return Status::S_OK ;
}

Status routine_two()
{
  std::cout << "Routine Two" << std::endl ; 
  return Status::S_ERROR ;
}


void dispatch_request( const char* buffer ) 
{
  std::cout << "Handling Dispatch\n"  ; 
  Opcode x ; 
  memcpy(&x , buffer, sizeof(Opcode));

  if ( (int) x  <= 2 ) {
    std::cout << "Can handle" << std::endl ; 
    (*request_handler_array[ ( int ) x ])(); 
  }else 
  {
    std::cout << "Cannot handle: " << ( int ) x  << std::endl ; 
  }

}

