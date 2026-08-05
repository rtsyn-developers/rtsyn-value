#include <stdlib.h>

#include "rtsyn/internal/value.h"
#include "rtsyn/internal/value/uint.h"

rtsyn_value_t *
rtsyn_value_create_uint()
{
    return rtsyn_value_create(RTSYN_ABI_VALUE_U64);
}

uint64_t *
rtsyn_value_u64_create()
{
    return (uint64_t *)calloc(1, sizeof(uint64_t));
}

void
rtsyn_value_u64_destroy(uint64_t *uint_value)
{
    free(uint_value);
}

bool
rtsyn_value_u64_get(const rtsyn_value_t *port_value, uint64_t *out)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_U64) || !out)
    {
        return false;
    }

    *out = *(uint64_t *)port_value->value_data;
    return true;
}

size_t
rtsyn_value_u64_size_get()
{
    return sizeof(uint64_t);
}

bool
rtsyn_value_u64_set(rtsyn_value_t *port_value, uint64_t *new_value)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_U64)
        || !new_value)
    {
        return false;
    }

    *(uint64_t *)port_value->value_data = *new_value;
    return true;
}
