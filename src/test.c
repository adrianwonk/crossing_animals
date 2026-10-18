/* put me in the beginning of main method! */
#include <stdio.h>
#include <stdlib.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"
pub* test_pub();
student* test_students(FILE *fileptr);
void print_pub(FILE*, pub*);
void print_student(FILE*, student*);
void test_put_students_in_pub(FILE *before, FILE *after, student **students, pub **mypub);


void test(){

    pub* mypub        = test_pub();
    // student* students = test_students(stdout);
    print_pub(stdout, mypub);
    
    exit(0);
}
