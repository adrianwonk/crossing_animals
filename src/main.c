#include <stdio.h>
#include <stdbool.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"

int main(){
    student tender7 = {
        .student_id = 6,
        .student_name = "Stacy Wanker V2",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = lady
    };
    student tender6 = {
        .student_id = 13,
        .student_name = "Stacy Wanker",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = man
    };
    student tender5 = {
        .student_id = 8,
        .student_name = "Rick",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = man
    };
    student tender4 = {
        .student_id = 5,
        .student_name = "Stacy",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = lady,
        .sex_preference = man
    };
    student tender3 = {
        .student_id = 4,
        .student_name = "Robert",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = man,
        .sex_preference = lady
    };
    student tender2 = {
        .student_id = 1,
        .student_name = "Adrian!",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 3,

        .my_gender = man,
        .sex_preference = lady
    };
    student tender1 = {
        .student_id = 24,
        .student_name = "Adriana!",
        .loneliness_meter = 0,
        .sex_meter = 0, // bounded from 0 to 30
        .sex_acc = 0, // possibly increases sex_meter
        .sex_requirement = 5,

        .my_gender = lady,
        .sex_preference = man
    };
    student *tenders[7] = {&tender1, &tender2, &tender3, &tender4, &tender5, &tender6, &tender7};
    pub my_pub = { .load = 7 };

    void init_pub_values(pub *pub, size_t num_bartenders, student *bartenders[]), print_pub(pub *pub);

    init_pub_values(&my_pub, 7, tenders);
    print_pub(&my_pub);

    /* TODO: create a PUB, student bartenders, and initialise it! then print out the pub. No non-bartender students can go to a pub yet. */

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
#define MAX_SEX_INCR 10
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


