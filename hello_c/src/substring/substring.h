//
// Created by Annick on 2020-01-17.
//

#ifndef HELLO_C_SUBSTRING_H
#define HELLO_C_SUBSTRING_H

/** \brief finds a substring in a string using a dynamic programming approach, with a maximum number
 *         of editing
 *
 * @param string
 * @param substring
 * @param editing_distance the maximum number of modification needed for the string to
 *        match the substring
 * @return index of the found substring or -1
 */
int find_fragment(char const *string, char const *substring, int editing_distance, int* resulting_index);

#endif //HELLO_C_SUBSTRING_H
