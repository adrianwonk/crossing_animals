# Current Architecture:
Pub structure allows quick queries for the exact bartender(s) working at the pub (a student). It also allows quick queries for who is at the pub, depending on the load size defined for the pub.

A pub has a drunk_bucket, which hashes student_id to the load_size defined for the pub.

# Concept: Point to pointers
Pointer to pointers are an important concept, as this second order concept allow functions to modify the resources which a pointer points to. Most evidently, this concept is useful when manipulating nodes in a linked list, as we allocate resources for the first pointer that points to NULL. As we directly modify the value of a pointer away from NULL/0, we must have a pointer to the pointer.

# Game implementation:
A hash bucket is used to store customer entries for a pub, allowing for random lookups of students based on their id. Pointer to pointers allow code to express the allocation of new memory for new customers *explicitly at the location where the pointer chain terminates (is NULL)*, improving **readability** and **logic accuracy**.

# Tweakables:
Based on what we *use* to lookup students at a pub, we can change out the **hash function**. For example, **hash** by first 4 letters of student name.
