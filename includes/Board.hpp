#ifndef __BOARD_H__
#define __BOARD_H__

#include "Case.hpp"
#include "Token.hpp"

class Board
{
    public:

        /**
         * @brief setToken on a case
         * 
         * @param t Token
         * @param case_id id of the case (beetween 0 and 8)
         * @return int[0 OK - 1 Case doesn't exist - 2 Case isn't empty]
         */
        int setTokenOnCase(Token t, int case_id);


        /**
         * @brief Reset board for a new game
         * 
         */
        void reset();


        /**
         * @brief Result of current game
         * 
         * @return Winner's Token or Token.VOID
         */
        Token result();


        /**
         * @brief Return true if every case is taken
         * 
         */
        bool isFull();


        /**
         * @brief Print on std::cout the current board
         * 
         */
        void printBoard();
 
    private:
        Case board[9];

};

#endif