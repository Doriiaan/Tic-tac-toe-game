#include "../includes/Token.hpp"


/**
 * @brief Get the Symbol Of Token object
 * 
 * @param t Token
 * @return std::string 
 */
std::string getSymbolOfToken(Token t){

    std::string response;
    switch (t)
    {
        case CROSS:
            response = "X";
            break;
        
        case ROUND:
            response = "O";
            break;

        case VOID:
            response = " ";
            break;
    }

    return response;
}