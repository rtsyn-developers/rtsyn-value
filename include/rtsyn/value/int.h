/**
 * @file rtsyn/value/int.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header file for the RTSyn Port Value for int.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_ABI_VALUE_I64_H
#define RTSYN_ABI_VALUE_I64_H
#include "rtsyn/value.h"

/**
 * @brief Constructor for the int RTSyn Port Value.
 *
 * @return A RTSyn Port Value.
 */
rtsyn_value_t *
rtsyn_value_create_i64();

/**
 * @brief Getter for RTSyn Port Value of type int.
 *
 * @param port_value The port value pointer.
 * @param out The int value pointer to be retrieved.
 *
 * @return true and the value inside out if its a valid pointer from this type, false otherwhise.
 */
bool
rtsyn_value_i64_get(const rtsyn_value_t *port_value, int *out);

/**
 * @brief Getter for RTSyn Port Value of type int.
 *
 * @param port_value The port value pointer.
 * @param new_value Pointer to the int value.
 *
 * @return true if setted, false otherwhise.
 */
bool
rtsyn_value_i64_set(rtsyn_value_t *port_value, int *new_value);

#endif /* RTSYN_ABI_VALUE_I64_H */
