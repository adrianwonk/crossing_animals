#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"
#include <color_log.h>

typedef struct student_storage student_storage;

struct student_storage{
    student student;
    student_storage* next;
};

#define STORE_SIZE 100
int main() {
    // TODO:
    // make a storage for student objects

    student_storage* store;
    if(
    ( store = calloc(STORE_SIZE,sizeof(student_storage)) )
        == NULL
    ) {
        fprintf(stderr, "cannot make student store\n");
        exit(1);
    }
    /* made student store, which stores data as well as next node */


}

size_t get_key(uint64_t id){
    return id % STORE_SIZE;
}

void add_student(student_storage* store, student s){
    size_t key = get_key(s.student_id);
    student_storage* bucket = store + key;

    /* get to the last element first! */
    for(;bucket->next; bucket = bucket->next){ }
    
    /* empty bucket has head as last element! */
    /* in which case, student_id will be 0!   */
    if (!bucket->student.student_id){
        bucket->student = s;
    }
    else {
        if /* allocate new memory for conflict! */
        ( !( bucket->next = calloc(1, sizeof(student_storage)) ) ){
            fprintf(stderr, "cannot allocate next student storage at key: %zu\n", key);
            exit(1);
        }
        bucket = bucket->next;
        bucket->student = s;
    }
}


student *student_from_id(student_storage* store, uint64_t id){
    size_t key;
    key = get_key(id);

    student_storage* bucket = store+key;
    for (; bucket->student.student_id != id || bucket->next; bucket = bucket->next){}

    return (bucket->student.student_id == id) ? (student*)bucket : NULL;
}

void fprint_store(FILE* fileptr, student_storage* store){
    void print_student(FILE*,student*);
    int i;
    student_storage* runner;
    for (i=0; i<STORE_SIZE; i++){
        fprint_col(fileptr, SUBHEADER, "bucket %d", i);
        for (runner = store+i; runner; runner = runner->next){
            fprint_col(fileptr, SECTION, "student %zu", runner->student.student_id);
            print_student(fileptr, (student*)runner);
            fprint_col(fileptr, LABEL, "next: ");
            fprint_col(fileptr, MEMORY, "%p\n", runner->next);
        }
    }
}



/** legacy code **/
/*******************************************/
/*  Going to the pub increases sex meter   */
/*  and loneliness meter of students.      */
/*  Since students have a max sex_meter of */
/*  10, going to the pub should be bounded */
/*  too.                                   */
/*  Bound increase from 0 to 10.           */
/*                                         */
/*******************************************/
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


