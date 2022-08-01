#ifndef __CASE_H__
#define __CASE_H__

#include "Token.hpp"

class Case
{
    private:
        Token t;

    public:

        /**
         * @brief Construct a new Case:: Case object
         * 
         * @param id of case
         */
        Case();


        /**
         * @brief Getter of token
         * 
         * @return Token 
         */
        Token getToken();

        
        /**
         * @brief Setter of Token
         * 
         * @param st 
         */
        void setToken(Token st);

        
        /**
         * @brief  Is it an empty case ?
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty();


        /**
         * @brief Compare two symbol of case
         * 
         * @param c other case
         * @return true 
         * @return false 
         */
        bool equal(Case c);
};

#endif