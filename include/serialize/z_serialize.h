#pragma once 
#include <iostream>
#include <memory>
#include <tuple>


// Come back to this I think something valuable is here negl. 
template<typename... T>
struct Serializable
{
  std::tuple< T...> members ; 
};

void foo( int , char , int ) 
{
  std::cout << "Called foo" << std::endl ; 
}


template<typename... T>
std::tuple<T...> tied( T... args ) 
{
  std::tuple<T...> returnval ;
  std::apply( []( auto&... args){ (( args += 1 ) , ... ) ; } , returnval ) ; 
  return returnval ; 
}


// First 8 bytes give op code.
// From the op code we go to the function 
// Read the bytes from the stream 
// Store the value.
// Increment the blob_ptr by the sizeof(T)
// Remove cv-qualification 


template < typename F, typename... T> 
void invoke( F&& fptr , T... arguments ){ 
  
  // Pointer to byte stream 
  
  size_t blob_ptr{} ; 

  // 

  // Make the call to the function 
  std::apply( fptr, arguments... ) ; 
}

// Use this pattern for serializing and receiving . 
template<typename S, typename... P>
void call( S x , void ( *function)(P...))
{
  std::tuple<P...> args ; 

  size_t pool_ptr{} ; 

  auto y = std::reinterpret_pointer_cast<char*>(&x) ; 
  std::apply( [&]( auto&&... args ){ ( ([&]{ memcpy( &args, &x + pool_ptr , sizeof(args)) ; pool_ptr += sizeof(args) ; std::cout << "Hello" << std::endl; } ) , ... ) ; } , args ) ;

  std::apply( function, args ) ;
}


