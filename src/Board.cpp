#include <iostream>
#include "../includes/Board.hpp"


/**
 * @brief setToken on a case
 * 
 * @param t Token
 * @param case_id id of the case (beetween 0 and 8)
 * @return int[0 OK - 1 Case doesn't exist - 2 Case isn't empty]
 */
int Board::setTokenOnCase(Token t, int case_id)
{
    if(case_id < 9 && case_id >= 0) //if the case exist
    {
        if(this->board[case_id].isEmpty()) //if is empty
        {
            this->board[case_id].setToken(t);
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }

    return 0;    
}


/**
 * @brief Reset board for a new game
 * 
 */
void Board::reset()
{
    for(int i = 0 ; i < 9 ; i++)
    {
        this->board[i].setToken(VOID);
    }
}


/**
 * @brief Result of current game
 * 
 * @return Winner's Token or Token.VOID
 */
Token Board::result()
{
    for (int i = 0; i < 9; i+=3)
    {
        if(!this->board[i].isEmpty() && this->board[i].equal(this->board[i+1]) && this->board[i].equal(this->board[i+2]))
            return this->board[i].getToken();
    }
    for (int i = 0; i < 3; i++)
    {
        if(!this->board[i].isEmpty() && this->board[i].equal(this->board[i+3]) && this->board[i].equal(this->board[i+6]))
            return this->board[i].getToken();
    }
    if(!this->board[0].isEmpty() && this->board[0].equal(this->board[4]) && this->board[0].equal(this->board[8]))
        return this->board[0].getToken();

    if(!this->board[2].isEmpty() && this->board[2].equal(this->board[4]) && this->board[2].equal(this->board[6]))
        return this->board[2].getToken();
    
    return VOID;
}


/**
 * @brief Return true if every case is taken
 * 
 */
bool Board::isFull()
{
    for (int i = 0; i < 9; i++)
    {
        if(this->board[i].isEmpty())
            return false;
    }
    return true;
}


/**
 * @brief Print on std::cout the current board
 * 
 */
void Board::printBoard()
{

    std::cout << "\n\n\n";
    for (int i = 0; i <= 6; i+= 3)
    {
        std::cout << " " << i+1 << "\t";
        std::cout << " " << i+2 << "\t";
        std::cout << " " << i+3 << "\t";
        std::cout << "\n";

        std::cout << "[" << getSymbolOfToken(this->board[i].getToken()) << "]\t";
        std::cout << "[" << getSymbolOfToken(this->board[i+1].getToken()) << "]\t";
        std::cout << "[" << getSymbolOfToken(this->board[i+2].getToken()) << "]\t";
        std::cout << "\n" << std::endl;
    }
    
}