/*************************************************/
/* Main entity for our game, which is a PUB.     */
/* Students are able to stay at a pub, where     */ 
/* they can date, have conversations, and relax. */
/*                                               */ 
/*************************************************/ 

/***********************************************************************/
/* The functions of a pub struct is to 1) know who the bartenders are, */
/* as well as 2) tracking which students are at the pub.               */
/* Further functionalities can then be built which modify their states.*/
/*                                                                     */
/***********************************************************************/

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"
#include <color_log.h>

/* assumed that there is already a pub allocated, with load_size affixed. */
void init_pub_values(pub *pubptr, size_t num_bartenders, const student *bartenders[]){

    if (!pubptr->load) { fprintf(stderr, "pub does not have a valid load size.\n"); exit(1); }
    
    customer *drunk_bucket;
    uint64_t *bartender_ids;
    size_t num_male_bartenders, num_lady_bartenders;
    num_male_bartenders=0;
    num_lady_bartenders=0;

    if ((drunk_bucket=calloc( pubptr->load, sizeof(customer) )) == NULL){ /* initialise the drunk_bucket! */
        fprintf(stderr, "critical memory initialisation error while making drunk_bucket!\n");
        exit(1);
    }
    if ((bartender_ids=calloc( num_bartenders, sizeof(uint64_t) )) == NULL) { /* cache ids of bartenders! */
        fprintf(stderr, "critical memory initialisation error while making bartender_reference array!\n");
        exit(1);
    }

    int i;
    for (i=0; i<num_bartenders; i++) {
        bartender_ids[i] = bartenders[i]->student_id;
        (bartenders[i]->my_gender == man) ?
            num_male_bartenders++ : num_lady_bartenders++;
    }

    /* link created resources */
    pubptr->num_male_bartenders = num_male_bartenders;
    pubptr->num_lady_bartenders = num_lady_bartenders;
    pubptr->bartenders     = bartender_ids;
    pubptr->drunk_bucket   = drunk_bucket;

    /* default values */
    pubptr->next           = NULL;
    pubptr->num_ladies     = 0;
    pubptr->num_men        = 0;
}

size_t hash_st_id(uint64_t student_id, size_t load_size){
    return student_id % load_size;
}

customer *add_to_drunk_bucket(customer *bucket_ptr, student *s){
    customer **mover;
    for (mover=&bucket_ptr; *mover; mover=&(*mover)->next);
    if ((*mover=calloc(1,sizeof(customer))) == NULL){
        fprintf(stderr, "cannot allocate memory for pub customer records.\n");
        exit(1);
    }
    (*mover)->student_id   = s->student_id;
    (*mover)->next         = NULL;
    return *mover;
}

void add_student_to_pub(student *ps, pub *pub){
    customer *add_to_drunk_bucket(customer *bucket_ptr, student *s);
    size_t bucket_num;
    customer *bucket_ptr;

    bucket_num = hash_st_id(ps->student_id, pub->load);
    bucket_ptr = pub->drunk_bucket + bucket_num;
    add_to_drunk_bucket(bucket_ptr, ps);

    (ps->my_gender == man) ? pub->num_men++: pub->num_ladies++;
}

void print_pub(FILE *fileptr, pub *pub){
    fprint_col(fileptr, SUBHEADER, "pub");
    fprint_col(fileptr, DEFAULT, "aggregates: ");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_ladies);
    fprint_col(fileptr, LABEL, "ladies, ");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_men);
    fprint_col(fileptr, LABEL, "men, ");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_male_bartenders);
    fprint_col(fileptr, LABEL, "male bartenders and \n");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_lady_bartenders);
    fprint_col(fileptr, LABEL, "lady bartenders\n");

    int i; /* prints out each bucket */
    customer *mover; 
    uint64_t bartender_id;
    for (i=0; mover=pub->drunk_bucket+i, i<pub->load; i++){
        fprint_col(fileptr, SECTION, "bucket %-2d", i);
        for (; mover; mover=mover->next){
            fprint_col(fileptr, LABEL, "address: ");
            fprint_col(fileptr, MEMORY, "%p ",
                    (void*) mover);
            fprint_col(fileptr, LABEL, "id next_adr: ");
            fprint_col(fileptr, NUMBER, "%zu ", 
                    mover->student_id);
            fprint_col(fileptr, MEMORY, "%p\n", 
                    (void *)mover->next);
        }
    }

    fprint_col(fileptr, SECTION, "bartenders");
    for (i=0; bartender_id=pub->bartenders[i], 
    i<(pub->num_lady_bartenders + pub->num_male_bartenders); i++){
        fprint_col(fileptr, LABEL, "id: ");
        fprint_col(fileptr, NUMBER, "%zu\n", bartender_id);
    }
    fprint_col(fileptr,SUBTRAILER,
        "end pub"
    );
}

void tick(pub* my_pub){
    void process_student_in_pub(student*, pub*);
    student *stud, *student_from_id(uint64_t id);
    int i, id;
    customer *mover;
    for (i=0; i<my_pub->load; i++){
        for (mover=my_pub->drunk_bucket[i].next; mover; 
            mover=mover->next){
            id = mover->student_id;
            stud = student_from_id(id);
            if (!stud) {fprintf(stderr, "no %d\n", id); exit(1);}
            process_student_in_pub(stud, my_pub);
        }
    }
}

#define MAX_SEX_INCR 10
void process_student_in_pub(student* st, pub* pb){
    int gcd(int, int);
    int num_women, num_men, sex_meter_incr;
    num_women = pb->num_ladies + pb->num_lady_bartenders;
    num_men = pb->num_men + pb->num_male_bartenders;
    sex_meter_incr = 1;

    if (num_women > 0 && num_men > 0) {
        int divisor, parts_women, parts_men;
        divisor = gcd(num_women, num_men);
        parts_women = num_women / divisor;
        parts_men = num_men / divisor;
        if (st->sex_preference == man && parts_men > parts_women) {
            sex_meter_incr += parts_men - parts_women;
        }
        else if (st->sex_preference == lady && parts_women > parts_men) {
            sex_meter_incr += parts_women - parts_men;
        }

    } else { // extreme ends case
        bool prefer_woman_available = 
            (st->sex_preference == lady && num_women > 0);
        bool prefer_man_available   =
            (st->sex_preference == man  && num_men   > 0);
        sex_meter_incr = (prefer_woman_available || prefer_man_available) ? MAX_SEX_INCR : 0;
    }

    if (sex_meter_incr > MAX_SEX_INCR) sex_meter_incr = MAX_SEX_INCR;
    st->sex_acc += sex_meter_incr;
    if (st->sex_acc >= st->sex_requirement) {
        st->sex_meter++; st->sex_acc = 0;
    }
}
