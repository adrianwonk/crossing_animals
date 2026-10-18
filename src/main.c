#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"
#include <color_log.h>

int main() {
    void test_put_students_in_pub(FILE *before, FILE *after, student **students, pub **mypub);
    void test();
    test();

    void print_student(FILE*, student*),
         print_pub(FILE*, pub*);
    student *studs, *test_students(FILE*);
    pub *my_pub, *test_pub(FILE*);
    FILE *sink, *before, *after;
    int i;

    void tick(pub*);

    sink = fopen("/dev/null", "w");
    before = stdout;
    after  = stderr;

    fprint_col(before, HEADER ,"entities before processing");
    test_put_students_in_pub(before, sink, &studs, &my_pub);
    fprint_col(before, TRAILER ,"entities before processing");
    tick(my_pub);
    fprint_col(after, HEADER ,"entities after processing");
    for(i=0; studs[i].student_id; i++){
        print_student(after,studs+i);
    }
    print_pub(after,my_pub);
    fprint_col(before, TRAILER ,"entities after processing");

    fclose(sink);
    return 0;
}

void tick(pub* my_pub){
    student *stud, *student_from_id(uint64_t id);
    int i, id;
    customer *mover;
    for (i=0; i<my_pub->load; i++){
        for (mover=my_pub->drunk_bucket; mover; 
            mover=mover->next){
            id = mover->student_id;
            stud = student_from_id(id);
            stud->sex_meter += 1;
        }
    }
}

student *student_from_id(uint64_t id){
}


/*******************************************/
/*  Going to the pub increases sex meter   */
/*  and loneliness meter of students.      */
/*  Since students have a max sex_meter of */
/*  10, going to the pub should be bounded */
/*  too.                                   */
/*  Bound increase from 0 to 10.           */
/*                                         */
/*******************************************/

/** legacy code **/
// STUDENT* tick(STUDENT* ps, PUB* pb) {

//     int num_women = pb->total_ladies;
//     int num_men = pb->total_men;

//     int sex_meter_incr = 1;

//     if (num_women > 0 && num_men > 0) {

//         int divisor = gcd(num_women, num_men);
//         int parts_women = num_women / divisor;
//         int parts_men = num_men / divisor;
//         if (ps->sex_preference == man && parts_men > parts_women) {
//             sex_meter_incr += parts_men - parts_women;
//         }
//         else if (ps->sex_preference == lady && parts_women > parts_men) {
//             sex_meter_incr += parts_women - parts_men;
//         }

//     } else { // extreme ends case
//         bool prefer_woman_available = (ps->sex_preference == lady && num_women > 0);
//         bool prefer_man_available   = (ps->sex_preference == man  && num_men   > 0);
//         sex_meter_incr = (prefer_woman_available || prefer_man_available) ? MAX_SEX_INCR : 0;
//     }

//     if (sex_meter_incr > MAX_SEX_INCR) sex_meter_incr = MAX_SEX_INCR;
//     ps->sex_acc += sex_meter_incr;
//     if (ps->sex_acc >= ps->sex_requirement) {ps->sex_meter++; ps->sex_acc = 0;}

//     return ps;
// }


