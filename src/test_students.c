
#include "student_data_structures.h"
#include <stdio.h>
#include <stdlib.h>
student* test_students(FILE *fileptr){
    static int student_number = 100;
    student *students;
    if ((students=calloc( 5, sizeof(student) )) == NULL) {
        fprintf(stderr, "cannot alloc memory for test students.\n");
        exit(1);
    }

    students[0] = (student) {
        .student_id = student_number++,
        .student_name = "Billy",
        .loneliness_meter = 10,
        .sex_meter = 0,
        .sex_acc = 0, 
        .sex_requirement = 3,
        .my_gender = man,
        .sex_preference = lady
    };
    students[1] = (student) {
        .student_id = student_number++,
        .student_name = "Samantha",
        .loneliness_meter = 0,
        .sex_meter = 0,
        .sex_acc = 0, 
        .sex_requirement = 10,
        .my_gender = lady,
        .sex_preference = man
    };

    int i;
    for (i=0; students[i].student_id; i++) {}
    fprintf(fileptr, " === made %d students ============\n", i);
    return students;
}
