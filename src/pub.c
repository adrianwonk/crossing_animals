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
    }

    /* link created resources */
    pubptr->num_bartenders = num_bartenders;
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
    fprint_col(fileptr, LABEL, "men and ");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_bartenders);
    fprint_col(fileptr, LABEL, "bartenders\n");

    int i; /* prints out each bucket */
    customer *mover; 
    uint64_t bartender_id;
    for (i=0; mover=pub->drunk_bucket+i, i<pub->load; i++){
        fprint_col(fileptr, SECTION, "bucket %-2d", i);
        for (; mover; mover=mover->next){
            fprint_col(fileptr, LABEL, "address: ");
            fprint_col(fileptr, MEMORY, "%p",
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
    i<pub->num_bartenders; i++){
        fprint_col(fileptr, LABEL, "id: ");
        fprint_col(fileptr, NUMBER, "%zu\n", bartender_id);
    }
    fprint_col(fileptr,SUBTRAILER,
        "end pub"
    );
}
