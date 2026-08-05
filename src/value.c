/**
 * @file value.c
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Compile unit for the RTSyn Runtime Port Value
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "rtsyn/internal/value.h"
#include "rtsyn/internal/value/double.h"
#include "rtsyn/internal/value/float.h"
#include "rtsyn/internal/value/int.h"
#include "rtsyn/internal/value/str.h"
#include "rtsyn/internal/value/uint.h"

static const rtsyn_value_initializer_t
    RTSYN_PORT_VALUE_INITIALIZER_TABLE[RTSYN_ABI_VALUE_COUNT] = {
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_ABI_VALUE_F32, rtsyn_value_f32_create, rtsyn_value_f32_destroy,
            rtsyn_value_f32_get, rtsyn_value_f32_size_get, rtsyn_value_f32_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_ABI_VALUE_F64, rtsyn_value_f64_create, rtsyn_value_f64_destroy,
            rtsyn_value_f64_get, rtsyn_value_f64_size_get, rtsyn_value_f64_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_ABI_VALUE_I64, rtsyn_value_i64_create, rtsyn_value_i64_destroy,
            rtsyn_value_i64_get, rtsyn_value_i64_size_get, rtsyn_value_i64_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_ABI_VALUE_U64, rtsyn_value_u64_create, rtsyn_value_u64_destroy,
            rtsyn_value_u64_get, rtsyn_value_u64_size_get, rtsyn_value_u64_set),
        RTSYN_PORT_VALUE_INITIALIZER_TBL_ENTRY(
            RTSYN_ABI_VALUE_STRING, rtsyn_value_str_create, rtsyn_value_str_destroy,
            rtsyn_value_str_get, rtsyn_value_str_size_get, rtsyn_value_str_set),
};

rtsyn_value_t *
rtsyn_value_create(rtsyn_abi_value_type_t value_type)
{
    if (!rtsyn_abi_value_is_valid(value_type))
    {
        return nullptr;
    }

    rtsyn_value_t *port_value = (rtsyn_value_t *)malloc(sizeof(rtsyn_value_t));

    if (!port_value)
    {
        return nullptr;
    }

    port_value->value_type = value_type;

    port_value->value_data = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_constructor();
    port_value->data_destructor = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_destructor;
    port_value->data_setter = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_setter;
    port_value->data_getter = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_getter;
    port_value->data_size = RTSYN_PORT_VALUE_INITIALIZER_TABLE[value_type].data_size_getter();

    if (!port_value->value_data)
    {
        free(port_value);
        return nullptr;
    }

    return port_value;
}

void
rtsyn_value_destroy(rtsyn_value_t *port_value)
{
    if (!port_value)
    {
        return;
    }

    port_value->data_destructor(port_value->value_data);
    free(port_value);
}

rtsyn_abi_value_type_t
rtsyn_value_type_get(const rtsyn_value_t *port_value)
{
    if (!port_value)
    {
        return RTSYN_ABI_VALUE_INVALID;
    }
    return port_value->value_type;
}

bool
rtsyn_value_is_type(const rtsyn_value_t *port_value,
                         rtsyn_abi_value_type_t value_type)
{
    return (port_value->value_type == value_type);
}

bool
rtsyn_value_get(const rtsyn_value_t *port_value, void *contained_value)
{
    if (!port_value || !contained_value)
    {
        return false;
    }

    return port_value->data_getter(port_value, contained_value);
}

size_t
rtsyn_value_size_get(const rtsyn_value_t *port_value)
{
    if (!port_value)
    {
        return 0;
    }

    return port_value->data_size;
}

bool
rtsyn_value_set(rtsyn_value_t *port_value, void *new_value)
{
    if (!port_value || !new_value)
    {
        return false;
    }

    return port_value->data_setter(port_value, new_value);
}

bool
rtsyn_value_copy(rtsyn_value_t *destination, const rtsyn_value_t *source)
{
    if (!destination || !source || destination->value_type != source->value_type)
    {
        return false;
    }

    switch (source->value_type)
    {
        case RTSYN_ABI_VALUE_F32:
        {
            float value;
            return rtsyn_value_f32_get(source, &value)
                   && rtsyn_value_f32_set(destination, &value);
        }
        case RTSYN_ABI_VALUE_F64:
        {
            double value;
            return rtsyn_value_f64_get(source, &value)
                   && rtsyn_value_f64_set(destination, &value);
        }
        case RTSYN_ABI_VALUE_I64:
        {
            int value;
            return rtsyn_value_i64_get(source, &value)
                   && rtsyn_value_i64_set(destination, &value);
        }
        case RTSYN_ABI_VALUE_U64:
        {
            uint64_t value;
            return rtsyn_value_u64_get(source, &value)
                   && rtsyn_value_u64_set(destination, &value);
        }
        case RTSYN_ABI_VALUE_STRING:
        {
            char value[RTSYN_PORT_VALUE_STRING_MAX_SIZE];
            return rtsyn_value_str_get(source, value)
                   && rtsyn_value_str_set(destination, value);
        }
        default:
            return false;
    }
}
