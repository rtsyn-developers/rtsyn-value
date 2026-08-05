#include <stdlib.h>

#include "rtsyn/internal/value.h"
#include "rtsyn/value/float.h"

rtsyn_value_t *
rtsyn_value_create_f32()
{
    return rtsyn_value_create(RTSYN_ABI_VALUE_F32);
}

float *
rtsyn_value_f32_create()
{
    return (float *)calloc(1, sizeof(float));
}

void
rtsyn_value_f32_destroy(float *float_value)
{
    free(float_value);
}

bool
rtsyn_value_f32_get(const rtsyn_value_t *port_value, float *out)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_F32) || !out)
    {
        return false;
    }

    *out = *(float *)port_value->value_data;
    return true;
}

size_t
rtsyn_value_f32_size_get()
{
    return sizeof(float);
}

bool
rtsyn_value_f32_set(rtsyn_value_t *port_value, float *new_value)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_F32)
        || !new_value)
    {
        return false;
    }

    *(float *)port_value->value_data = *new_value;
    return true;
}
