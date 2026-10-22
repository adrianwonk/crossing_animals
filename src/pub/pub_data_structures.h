#pragma once
#include <stddef.h>
#include <stdint.h>
#include "name.h"

typedef struct pub_node pub;
typedef struct customer_record_node customer;

struct customer_record_node {
    uint64_t student_id;
    customer *next;
};

struct pub_node {
    size_t num_ladies;
    size_t num_men;

    size_t num_male_bartenders;
    size_t num_lady_bartenders;

    uint64_t *bartenders;

    size_t load;
    name pub_name;
    customer *drunk_bucket;

    pub* next;
};
