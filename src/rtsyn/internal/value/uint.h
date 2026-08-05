/**
 * @file rtsyn/internal/value/uint.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Internal header file for the RTSyn Port Value for uint.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_INTERNAL_PORT_VALUE_UINT_H
#define RTSYN_INTERNAL_PORT_VALUE_UINT_H
#include "rtsyn/value/uint.h"

/**
 * @brief Constructor for the uint pointer.
 *
 * @return uint allocated in memory.
 */
uint64_t *
rtsyn_value_u64_create();

/**
 * @brief Destructor for the uint pointer.
 *
 * @param uint_value uint to be destroyed.
 */
void
rtsyn_value_u64_destroy(uint64_t *uint_value);

/**
 * @brief Getter for the size of the uint data.
 *
 * @return The size of the data type.
 */
size_t
rtsyn_value_u64_size_get();

#endif /* RTSYN_INTERNAL_PORT_VALUE_UINT_H */
