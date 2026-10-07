#pragma once
#include <stddef.h>
#include <stdint.h>
#include "name.h"

typedef struct pub_node pub;
typedef struct customer_record_node customer;

struct customer_record_node {
    name student_name;
    uint64_t student_id;
    customer *next;
};

struct pub_node {
    int num_ladies;
    int num_men;

    size_t num_bartenders;
    customer **bartenders;

    const size_t load;
    name pub_name;
    customer *drunk_bucket;

    pub* next;
};
