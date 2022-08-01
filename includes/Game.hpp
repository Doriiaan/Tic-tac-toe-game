#ifndef __GAME_H__
#define __GAME_H__

#include "Player.hpp"
#include "Board.hpp"


/**
 * @brief Master function of the game, just call it
 * 
 */
void Game();


/**
 * @brief Turn of a player
 * 
 * @param board reference to the board
 * @param actual reference to actual player
 */
void oneTurn(Board& board, Player& actual);

#endif