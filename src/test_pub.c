#include "pub_data_structures.h"
#include "student_data_structures.h"
#include <stdio.h>
#include <stdlib.h>

pub* test_pub(FILE *fileptr){
    student tender7 = {
        .student_id = 6,
        .student_name = "Stacy Wanker V2",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = lady
    };
    student tender6 = {
        .student_id = 13,
        .student_name = "Stacy Wanker",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = man
    };
    student tender5 = {
        .student_id = 8,
        .student_name = "Rick",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = man
    };
    student tender4 = {
        .student_id = 5,
        .student_name = "Stacy",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = man
    };
    student tender3 = {
        .student_id = 4,
        .student_name = "Robert",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = man,
        .sex_preference = lady
    };
    student tender2 = {
        .student_id = 1,
        .student_name = "Adrian!",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = man,
        .sex_preference = lady
    };
    student tender1 = {
        .student_id = 24,
        .student_name = "Adriana!",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 5,

        .my_gender = lady,
        .sex_preference = man
    };
    student *tenders[7] = {&tender1, &tender2, &tender3, &tender4, &tender5, &tender6, &tender7};
    
    pub *my_pub; 
    if ((my_pub = malloc(sizeof (pub))) == NULL){ fprintf(stderr, "failed to malloc pub in test.\n"); exit(1);}
    my_pub->load = 7;

    void init_pub_values(pub *pub, size_t num_bartenders, student *bartenders[]), print_pub(FILE *fileptr, pub *pub);

    init_pub_values(my_pub, 7, tenders);
    print_pub(fileptr, my_pub);
    return my_pub;
}
