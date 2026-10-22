
#include "student_data_structures.h"
#include <stdio.h>
#include <color_log.h>
void print_student(FILE *fileptr, student *ps){
    fprint_col(fileptr, SUBHEADER, "STUDENT");
    fprint_col(fileptr, LABEL, "student_id:       ");
    fprint_col(fileptr, NUMBER, "%zu\n", ps->student_id);
    fprint_col(fileptr, LABEL, "student_name:     ");
    fprint_col(fileptr, STRING, "%s\n", ps->student_name);
    fprint_col(fileptr, LABEL, "loneliness_meter: ");
    fprint_col(fileptr, NUMBER, "%d\n", ps->loneliness_meter);
    fprint_col(fileptr, LABEL, "sex_meter:        ");
    fprint_col(fileptr, NUMBER, "%d\n", ps->sex_meter);
    fprint_col(fileptr, LABEL, "sex_acc:          ");
    fprint_col(fileptr, NUMBER, "%d\n", ps->sex_acc);
    fprint_col(fileptr, LABEL, "sex_requirement:  ");
    fprint_col(fileptr, NUMBER, "%d\n", ps->sex_requirement);
    fprint_col(fileptr, LABEL, "gender:           ");
    fprint_col(fileptr, STRING, "%s\n", 
        (ps->my_gender      == man) ? "man" : "lady");
    fprint_col(fileptr, LABEL, "sex_preference:   ");
    fprint_col(fileptr, STRING, "%s\n", 
        (ps->sex_preference == man) ? "man" : "lady");
    fprint_col(fileptr, SUBTRAILER, "student end");
}
