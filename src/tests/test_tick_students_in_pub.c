
#include "pub_data_structures.h"
#include "student_data_structures.h"
#include <color_log.h>
#include <stdio.h>
void test_tick_students_in_pub(FILE* before, FILE* after){
    void test_put_students_in_pub(FILE *before, FILE *after, size_t *num_studs, student **students, pub **mypub);

    /* monitoring helpers */
    void print_student(FILE*, student*),
         print_pub(FILE*, pub*);
    pub *my_pub;
    FILE *sink;
    int i;

    /* changes student state! */
    void tick(pub*);

    /* setup monitoring */
    sink = fopen("/dev/null", "w");
    before = stdout;
    after  = stderr;

    fprint_col(before, HEADER ,"entities before processing");
    test_put_students_in_pub(before, sink, &num_studs, &studs, &my_pub);
    fprint_col(before, TRAILER ,"entities before processing");

    tick(my_pub);

    fprint_col(after, HEADER ,"entities after processing");
    for(i=0; studs[i].student_id; i++){
        print_student(after,studs+i);
    }
    print_pub(after,my_pub);
    fprint_col(after, TRAILER ,"entities after processing");

    fclose(sink);
    exit(0);
}
