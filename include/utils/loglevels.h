#pragma once 


/*
 *@signature  :
 *@purpose    :
 *@param      :
 *@return     :
*/

enum LogLevel{
  TRACE,
  DEBUG,
  INFO,
  WARN,
  ERROR
};

/*
 *@signature  :
 *@purpose    :
 *@param      :
 *@return     :
*/

void log( LogLevel level , const std::string& message );
