#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"
#include "color_log.h"

int main() {
    color_table(stdout);

    void print_student(FILE*, student*),
         print_pub(FILE*, pub*);
    student *studs, *test_students(FILE*);
    pub *my_pub, *test_pub(FILE*);
    FILE *sink = fopen("/dev/null", "w");
    /* TODO */
    // printf( "After adding students to the pub, we want to "
    //         "alter the states of each student every tick.\n"
    //         "The state change is a function of the student, "
    //         "as well as the pub.\n"
    //         "More specifically, it depends on the male/female "
    //         "ratios as well as the students' sexual preference.\n"
    //         "formula: (student s1, pub) -> (student s2, pub)"
    //         "\n");

    // printf( "This terminal will print s2 details. Stderr will print "
    //         "pub with s1, as well as s1 details."
    //         "\n");

    studs = test_students(sink);
    my_pub = test_pub(sink);
    print_pub(stdout,my_pub);
    exit(0);

    void add_student_to_pub(student *ps, pub *pub);
    /* students to be added to the pub */
    printf("=== Students prior to be added to my_pub: ===\n");
    int i;
    for(i=0;studs[i].student_id;i++){
        print_student(stdout, studs+i);
        add_student_to_pub(studs+i, my_pub);
    }
    
    printf("=== my_pub prior to state change: ===\n");
    print_pub(stdout, my_pub);

    // state_change();

    fprintf(stderr,"=== my_pub after state change: ===\n");
    print_pub(stderr, my_pub);
    fprintf(stderr,"=== Students after state change: ===\n");
    for(i=0;studs[i].student_id;i++){
        print_student(stderr, studs+i);
    }

    fclose(sink);
    return 0;
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
// STUDENT* went_pub(STUDENT* ps, PUB* pb) {

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


