#include <stdlib.h>

#include "rtsyn/internal/value.h"
#include "rtsyn/internal/value/double.h"

rtsyn_value_t *
rtsyn_value_create_f64()
{
    return rtsyn_value_create(RTSYN_ABI_VALUE_F64);
}

double *
rtsyn_value_f64_create()
{
    return (double *)calloc(1, sizeof(double));
}

void
rtsyn_value_f64_destroy(double *double_value)
{
    free(double_value);
}

bool
rtsyn_value_f64_get(const rtsyn_value_t *port_value, double *out)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_F64) || !out)
    {
        return false;
    }

    *out = *(double *)port_value->value_data;
    return true;
}

size_t
rtsyn_value_f64_size_get()
{
    return sizeof(double);
}

bool
rtsyn_value_f64_set(rtsyn_value_t *port_value, double *new_value)
{
    if (!port_value || !rtsyn_value_is_type(port_value, RTSYN_ABI_VALUE_F64)
        || !new_value)
    {
        return false;
    }

    *(double *)port_value->value_data = *new_value;
    return true;
}
