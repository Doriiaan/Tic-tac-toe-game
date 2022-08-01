#include "../includes/Case.hpp"


/**
 * @brief Construct a new Case:: Case object
 * 
 * @param id of case
 */
Case::Case()
{
    this->t = Token::VOID;
}


/**
 * @brief Getter of token
 * 
 * @return Token 
 */
Token Case::getToken()
{
    return this->t;
}


/**
 * @brief Setter of Token
 * 
 * @param st 
 */
void Case::setToken(Token st)
{
    this->t = st;
}


/**
 * @brief  Is it an empty case ?
 * 
 * @return true 
 * @return false 
 */
bool Case::isEmpty()
{
    return (this->t == Token::VOID);
}


/**
 * @brief Compare two symbol of case
 * 
 * @param c other case
 * @return true 
 * @return false 
 */
bool Case::equal(Case c)
{
    return this->t == c.t;
}