//
// Created by Annick on 2020-01-14.
//

#ifndef HELLO_C_SPACECHANGE_H
#define HELLO_C_SPACECHANGE_H


/** \brief compute spare change with dynamic programming
 *
 * Use a Dynamic programming approach to tell the number of coins needed to
 * produce the value n, given an array of coins with specific values
 *
 * @param n the value we want to the coins to add up to
 * @param coin_values ptr to the array of coins
 * @param coin_number number of elements in the array
 */
int compute_spare_change(int n, int const coin_values[], int coin_number);

/** \brief compute spare change with dynamic programming, returning the optimal coin list
 *
 * @param n
 * @param coin_values
 * @param coin_number
 * @param solution_list
 * @return
 */
int compute_spare_change_with_list(int n,
                                   int const coin_values[],
                                   size_t coin_number,
                                   int solution_list[]);
#endif //HELLO_C_SPACECHANGE_H
