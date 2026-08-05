/**
 * @file rtsyn/internal/value/int.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Port Value for int.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_I64_H
#define RTSYN_INTERNAL_PORT_VALUE_I64_H
#include "rtsyn/value/int.h"

/**
 * @brief Constructor for the int pointer.
 *
 * @return int allocated in memory.
 */
int *
rtsyn_value_i64_create();

/**
 * @brief Destructor for the int pointer.
 *
 * @param int_value int to be destroyed.
 */
void
rtsyn_value_i64_destroy(int *int_value);

/**
 * @brief Getter for the size of the int data.
 *
 * @return The size of the data type.
 */
size_t
rtsyn_value_i64_size_get();

#endif /* RTSYN_INTERNAL_PORT_VALUE_I64_H */
