#include "../includes/Player.hpp"

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param t Player's token
 */
Player::Player(Token t)
{
    this->t = t;
    this->score = 0;
}


/**
 * @brief Getter of token
 * 
 * @return Token 
 */
Token Player::getToken()
{
    return this->t;
}


/**
 * @brief Getter of score
 * 
 * @return int 
 */
int Player::getScore()
{
    return this->score;
}


/**
 * @brief When a player win
 * 
 */
void Player::win()
{
    this->score++;
}