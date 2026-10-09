#include "pub_data_structures.h"
#include "student_data_structures.h"
#include <stdio.h>

void test_put_students_in_pub(){
    student *students, *test_students(FILE *fileptr);
    pub *mypub, *test_pub(FILE *fileptr);
    void add_student_to_pub(student *ps, pub *pub);
    void print_pub(FILE *, pub*);

    mypub=test_pub(stderr);
    students=test_students(stdout);

    int i;
    for (i=0; students[i].student_id; i++)
        add_student_to_pub(students+i, mypub);

    print_pub(stdout, mypub);
}
