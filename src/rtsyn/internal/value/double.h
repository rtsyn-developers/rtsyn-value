/**
 * @file rtsyn/internal/value/double.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Port Value for double.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_F64_H
#define RTSYN_INTERNAL_PORT_VALUE_F64_H
#include "rtsyn/value/double.h"

/**
 * @brief Constructor for the double pointer.
 *
 * @return double allocated in memory.
 */
double *
rtsyn_value_f64_create();

/**
 * @brief Destructor for the double pointer.
 *
 * @param double_value double to be destroyed.
 */
void
rtsyn_value_f64_destroy(double *double_value);

/**
 * @brief Getter for the size of the double data.
 *
 * @return The size of the data type.
 */
size_t
rtsyn_value_f64_size_get();

#endif /* RTSYN_INTERNAL_PORT_VALUE_F64_H */
