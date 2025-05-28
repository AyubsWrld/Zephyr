#include <cstring>
#include <iostream>
#include <bit>


struct Member 
{

};


namespace z_details 
{
  template <typename... Types>
  struct TypeList {};

  template <std::size_t Index, typename List>
  struct TypeAt;
  
  template <std::size_t Index, typename Head, typename... Tail>
  struct TypeAt<Index, TypeList<Head, Tail...>> : TypeAt<Index - 1, TypeList<Tail...>> {};
  
  template <typename Head, typename... Tail>
  struct TypeAt<0, TypeList<Head, Tail...>> {
      using type = Head;
  };
  
}


int main (int argc, char *argv[]) 
{
  using MyList = z_details::TypeList<int, float, char>;
  using SecondType = z_details::TypeAt<1, MyList>::type;  

  std::cout << sizeof(SecondType) << std::endl ; 
  return 0;
}

