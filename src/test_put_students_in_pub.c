#include "pub_data_structures.h"
#include "student_data_structures.h"
#include <stdio.h>
#include <color_log.h>

void test_put_students_in_pub(FILE *before, FILE *after, size_t *num_studs, student **students, pub **mypub){
    student *test_students(FILE *fileptr);
    pub *test_pub();
    void add_student_to_pub(student *ps, pub *pub);
    void print_student(FILE *, student*);
    void print_pub(FILE *, pub*);
    int i;

    *students=test_students(before);
    *mypub=test_pub();

    fprint_col(before, HEADER, "students and pub entities prior to action");
    for (i=0; (*students)[i].student_id; i++)
        print_student(before, *students + i);
    *num_studs = i;

    print_pub(before, *mypub);
    fprint_col(before, TRAILER, "students and pub entities prior to action");

    for (i=0; (*students)[i].student_id; i++) {
        add_student_to_pub(*students+i, *mypub);
    }

    fprint_col(after, HEADER, "students and pub entities after adding to pub");
    for (i=0; (*students)[i].student_id; i++)
        print_student(after, *students + i);
    print_pub(after, *mypub);
    fprint_col(after, TRAILER, "students and pub entities after adding to pub");
}
