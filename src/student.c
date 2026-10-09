
#include "student_data_structures.h"
#include <stdio.h>
void print_student(FILE *fileptr, student *ps){
    fprintf(fileptr,
        "===STUDENT==================\n"
        "student_id:       %zu\n"
        "student_name:     %s\n"
        "loneliness_meter: %d\n"
        "sex_meter:        %d\n"
        "sex_acc:          %d\n"
        "sex_requirement:  %d\n"
        "gender:           %s\n"
        "sex_preference:   %s\n"
        "===end=====================\n"
        , ps->student_id, ps->student_name,
        ps->loneliness_meter, ps->sex_meter,
        ps->sex_acc, ps->sex_requirement,
        (ps->my_gender      == man) ? "man" : "lady",
        (ps->sex_preference == man) ? "man" : "lady"
    );
}
