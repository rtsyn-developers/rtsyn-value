#include <stdlib.h>

#include "rtsyn/internal/value.h"
#include "rtsyn/value/int.h"

rtsyn_value_t *
rtsyn_value_create_i64()
{
    return rtsyn_value_create(RTSYN_ABI_VALUE_U64);
}

int *
rtsyn_value_i64_create()
{
    return (int *)calloc(1, sizeof(int));
}

void
rtsyn_value_i64_destroy(int *int_value)
{
    free(int_value);
}

bool
rtsyn_value_i64_get(const rtsyn_value_t *port_value, int *out)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_I64) || !out)
    {
        return false;
    }

    *out = *(int *)port_value->value_data;
    return true;
}

size_t
rtsyn_value_i64_size_get()
{
    return sizeof(int);
}

bool
rtsyn_value_i64_set(rtsyn_value_t *port_value, int *new_value)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_I64)
        || !new_value)
    {
        return false;
    }

    *(int *)port_value->value_data = *new_value;
    return true;
}
