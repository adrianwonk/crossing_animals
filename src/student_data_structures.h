#pragma once
#include <stdint.h>
#include "name.h"
typedef enum gender_enum gender;
enum gender_enum {
    man,
    lady
};

typedef struct student_struct student;
struct student_struct {
    uint64_t student_id;
    name student_name;
    int loneliness_meter;
    // int hunger_meter;
    int sex_meter; // bounded from 0 to 30
    int sex_acc; // possibly increases sex_meter
    int sex_requirement;

    gender my_gender;
    gender sex_preference;
};
