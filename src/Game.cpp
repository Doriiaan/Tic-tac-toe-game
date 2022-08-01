#include <iostream>
#include <string>
#include<limits> //for limits
#include <ios>   //for streamsize
#include "../includes/Game.hpp"


/**
 * @brief Master function of the game, just call it
 * 
 */
void Game()
{

    Player p1 = Player(CROSS);
    Player p2 = Player(ROUND);

    Player actual{p1};

    Board board;

    bool win{false};
    bool restart{true};
    std::string restart_response;


    while(restart)
    {

        //print score
        std::cout << "[Player - " << getSymbolOfToken(p1.getToken()) << "] Score "<< p1.getScore() << "\n";
        std::cout << "[Player - " << getSymbolOfToken(p2.getToken()) << "] Score "<< p2.getScore() << "\n";
        std::cout << std::endl;

        //loop for a game
        while(!win && !board.isFull())
        {
            oneTurn(board, actual);


            win = (board.result() != VOID);
            if(!win)
                actual = ((actual.getToken() == p1.getToken()) ? p2 : p1); //change player's round
        }

       
        //End Game 
        board.printBoard();
        if(win)
        {
            
            std::cout << "[Player - " << getSymbolOfToken(actual.getToken()) << "] WIN!\n" << std::endl;
            if(actual.getToken() == p1.getToken())
                p1.win();
            else
                p2.win();
        }
        else
        {
            
            std::cout << "No one won ...\n" << std::endl;
        }
        
        std::cout << "[Player - " << getSymbolOfToken(p1.getToken()) << "] Score "<< p1.getScore() << "\n";
        std::cout << "[Player - " << getSymbolOfToken(p2.getToken()) << "] Score "<< p2.getScore() << "\n";
        std::cout << std::endl;

        // Restart a Game
        do
        {
            std::cout << "Do you want restart a game ? (yes/no) : ";
            std::cin >> restart_response;
        } while (restart_response.compare("yes") && restart_response.compare("no"));
        
        restart = (restart_response.compare("yes")==0);
        if(restart)
        {
            board.reset();
            win = false;
        }
    }

}


/**
 * @brief Turn of a player
 * 
 * @param board reference to the board
 * @param actual reference to actual player
 */
void oneTurn(Board &board, Player &actual)
{
    int case_id{-1};
    int error{0};

    board.printBoard();
    //loop for error in the case
    do
    {
        //request choice
        std::cout << "[Player - " << getSymbolOfToken(actual.getToken()) << "] Give your choice (beetween 1 and 9) : ";
        while(!(std::cin >> case_id)) //loop for error in input
        {
            std::cout << "[Player - " << getSymbolOfToken(actual.getToken()) << "] Give your choice (beetween 1 and 9) : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        //treatment of the choice
        switch ((error = board.setTokenOnCase(actual.getToken(), case_id-1)))
        {
        case 1:
            std::cout << "This number of case doesn't exist";
            break;

        case 2:
            std::cout << "This case is already taken";
            break;
        }
    } while (error);

}