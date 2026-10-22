/* put me in the beginning of main method! */
#include <color_log.h>
#include <stdio.h>
#include <stdlib.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"
pub* test_pub();
student* test_students(FILE *fileptr);
void print_pub(FILE*, pub*);
void print_student(FILE*, student*);
void test_put_students_in_pub(FILE *before, FILE *after, size_t *num_studs, student **students, pub **mypub);


void test(){
    // pub* mypub        = test_pub();
    // student* students = test_students(stdout);
    pub* mypub;
    student* students;
    size_t n;
    test_put_students_in_pub(stdout, stderr, &n, &students, &mypub);
    fprint_col(stdout, HEADER, "resulting states:");
    fprint_col(stdout, LABEL, "mypub ptr: ");
    fprint_col(stdout, MEMORY, "%p\n", mypub);
    fprint_col(stdout, LABEL, "students ptr: ");
    fprint_col(stdout, MEMORY, "%p\n", students);
    fprint_col(stdout, LABEL, "n: ");
    fprint_col(stdout, NUMBER, "%d\n", n);
    fprint_col(stdout, TRAILER, "resulting states:");
    
    exit(0);
}

void pub_functionality_test(){
    pub* mypub;
    mypub=test_pub();
    print_pub(stdout, mypub);
    exit(0);
}
