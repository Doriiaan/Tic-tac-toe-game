#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

enum Token{CROSS, ROUND, VOID};


/**
 * @brief Get the Symbol Of Token object
 * 
 * @param t Token
 * @return std::string 
 */
std::string getSymbolOfToken(Token t);

#endif