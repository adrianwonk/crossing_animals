#include <stdio.h>
#include <stdbool.h>
#include "math_func.h"

int main(){
    printf("hello world!\n");
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


