#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Token.hpp"

class Player
{
    private:
        Token t;
        int score;

    public:

        /**
         * @brief Construct a new Player:: Player object
         * 
         * @param t Player's token
         */
        Player(Token t);


        /**
         * @brief Getter of token
         * 
         * @return Token 
         */
        Token getToken();


        /**
         * @brief Getter of score
         * 
         * @return int 
         */
        int getScore();


        /**
         * @brief When a player win
         * 
         */
        void win();
        
};

#endif