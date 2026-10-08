/* Main entity for our game, which is a PUB.
 * Students are able to stay at a pub, where
 * they can date, have conversations, and relax.
*/ 

/* The functions of a pub struct is to 1) know who the bartenders are,
 * as well as 2) tracking which students are at the pub.
 * Further functionalities can then be built which modify their states.*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pub_data_structures.h"
#include "student_data_structures.h"

// implied that there is already a pub allocated. Why? i dunno!
void init_pub_values(pub *pubptr, size_t num_bartenders, student *bartenders[]){

    customer *drunk_bucket, **bartender_refs;

    size_t hash(student *s, size_t load_size);
    customer *insert_student(customer *bucket_lane_ptr, student *s);


    if ((drunk_bucket = calloc(pubptr->load, sizeof (customer))) == NULL){ /* initialise the drunk_bucket! */
        fprintf(stderr, "critical memory initialisation error while making drunk_bucket!\n");
        exit(1);
    }
    if ((bartender_refs = calloc(num_bartenders, sizeof(customer*))) == NULL) {
        fprintf(stderr, "critical memory initialisation error while making bartender_reference array!\n");
        exit(1);
    }

    int i; /* add the bartenders to drunk_bucket! */
    for (i=0; i<num_bartenders; i++) {
        size_t bucket_lane = hash(bartenders[i], pubptr->load);
        bartender_refs[i] = insert_student(&drunk_bucket[bucket_lane], bartenders[i]);
    }

    pubptr->num_bartenders = num_bartenders;
    pubptr->bartenders     = bartender_refs;
    pubptr->drunk_bucket   = drunk_bucket;
    /* default values */
    pubptr->next           = NULL;
    pubptr->num_ladies     = 0;
    pubptr->num_men        = 0;
}

inline size_t hash(student *s, size_t load_size){
    return (s->student_id) % load_size;
}

customer *insert_student(customer *bucket_lane_ptr, student *s){
    customer **mover = &bucket_lane_ptr;

    if (bucket_lane_ptr->student_id || bucket_lane_ptr->student_name[0] || bucket_lane_ptr->next){
        while (*mover) { /* navigate to nullptr */
            mover = &(*mover)->next;
        }
        if ((*mover=calloc(1,sizeof(customer))) == NULL){
            fprintf(stderr, "cannot allocate memory for pub customer records.\n");
            exit(1);
        }
    }

    strcpy((*mover)->student_name, s->student_name);
    (*mover)->student_id   = s->student_id;
    (*mover)->next         = NULL;
    return *mover;
}

void print_pub(pub *pub){
    printf("===pub=================================\n");
    printf("aggregates: %d ladies, %d men, %zu bartenders\n", pub->num_ladies, pub->num_men, pub->num_bartenders);

    int i; /* prints out each bucket */
    customer *mover; 
    for (i=0; mover=pub->drunk_bucket+i, i<pub->load; i++){

        printf("***bucket %-2d***************************\n", i);

        if (mover->student_name[0]=='\0' && !mover->student_id && !mover->next) continue;

        else while (mover){
            printf("address: %p, name id next_adr: %s %zu %p\n",
                (void *) mover,
                mover->student_name,
                mover->student_id,
                (void *)mover->next);
            mover = mover->next;
        }
    }

    printf("***bartenders *************************\n");
    for (i=0; mover=pub->bartenders[i], i<pub->num_bartenders; i++){
        printf("address: %p, name id next_adr: %s %zu %p\n",
            (void *) mover,
            mover->student_name,
            mover->student_id,
            (void *)mover->next);
    }
    printf("end\n");
}
