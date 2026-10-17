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
#include "color_log.h"

/* assumed that there is already a pub allocated, with load_size affixed. */
void init_pub_values(pub *pubptr, size_t num_bartenders, student *bartenders[]){

    if (!pubptr->load) { fprintf(stderr, "pub does not have a valid load size.\n"); exit(1); }
    
    customer *drunk_bucket, **pbartenders_info;
    size_t hash_st_id(long student_id, size_t load_size);
    customer *add_to_drunk_bucket(customer *bucket_ptr, student *s);

    if ((drunk_bucket=calloc( pubptr->load, sizeof (customer) )) == NULL){ /* initialise the drunk_bucket! */
        fprintf(stderr, "critical memory initialisation error while making drunk_bucket!\n");
        exit(1);
    }
    if ((pbartenders_info=calloc( num_bartenders, sizeof (customer*) )) == NULL) { /* cache ptrs to bartenders in drunk_bucket! */
        fprintf(stderr, "critical memory initialisation error while making bartender_reference array!\n");
        exit(1);
    }

    int i; /* add the bartenders to drunk_bucket! */
    for (i=0; i<num_bartenders; i++) {
        size_t bucket_num  = hash_st_id(bartenders[i]->student_id, pubptr->load);
        customer *pb        = drunk_bucket + bucket_num;
        student *pr         = bartenders[i];

        pbartenders_info[i] = add_to_drunk_bucket(pb, pr);
    }

    /* link created resources */
    pubptr->num_bartenders = num_bartenders;
    pubptr->bartenders     = pbartenders_info;
    pubptr->drunk_bucket   = drunk_bucket;

    /* default values */
    pubptr->next           = NULL;
    pubptr->num_ladies     = 0;
    pubptr->num_men        = 0;
}

inline size_t hash_st_id(long student_id, size_t load_size){
    return student_id % load_size;
}

customer *add_to_drunk_bucket(customer *bucket_ptr, student *s){
    customer **mover = &bucket_ptr;

    if (bucket_ptr->student_id || bucket_ptr->student_name[0] || bucket_ptr->next){
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

void add_student_to_pub(student *ps, pub *pub){
    customer *add_to_drunk_bucket(customer *bucket_ptr, student *s);
    size_t hash_st_id(long student_id, size_t load_size);
    size_t bucket_num = hash_st_id(ps->student_id, pub->load);
    customer *bucket_ptr = pub->drunk_bucket + bucket_num;
    add_to_drunk_bucket(bucket_ptr, ps);

    (ps->my_gender == man) ? pub->num_men++: pub->num_ladies++;
}

void print_pub(FILE *fileptr, pub *pub){
    fprint_col(fileptr, HEADER, "pub");
    fprint_col(fileptr, DEFAULT, "aggregates: ");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_ladies);
    fprint_col(fileptr, LABEL, "ladies, ");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_men);
    fprint_col(fileptr, LABEL, "men and ");
    fprint_col(fileptr, NUMBER, "%d ", pub->num_bartenders);
    fprint_col(fileptr, LABEL, "bartenders\n");

    int i; /* prints out each bucket */
    customer *mover; 
    for (i=0; mover=pub->drunk_bucket+i, i<pub->load; i++){

        fprint_col(fileptr, SECTION, "bucket %-2d", i);

        if (mover->student_name[0]=='\0' && !mover->student_id && !mover->next) continue;

        else for (; mover; mover=mover->next){
            fprint_col(fileptr, LABEL, "address: ");
            fprint_col(fileptr, MEMORY, "%p",
                    (void*) mover);
            fprint_col(fileptr, LABEL, ", name id next_adr: ");
            fprint_col(fileptr, STRING, "%s ",
                    mover->student_name);
            fprint_col(fileptr, NUMBER, "%zu ", 
                    mover->student_id);
            fprint_col(fileptr, MEMORY, "%p\n", 
                    (void *)mover->next);
        }
    }

    fprint_col(fileptr, SECTION, "bartenders");
    for (i=0; mover=pub->bartenders[i], i<pub->num_bartenders; i++){
        fprint_col(fileptr, LABEL, "address: ");
        fprint_col(fileptr, MEMORY, "%p",
            (void *) mover);
        fprint_col(fileptr, LABEL, ", name id next_adr: ");
        fprint_col(fileptr, STRING, "%s ",
            mover->student_name);
        fprint_col(fileptr, NUMBER, "%zu ",
            mover->student_id);
        fprint_col(fileptr, MEMORY, "%p\n",
            (void *)mover->next);
    }
    fprint_col(fileptr,TRAILER,
        "end pub"
    );
}
