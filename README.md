# Current Architecture:
Pub structure allows quick queries for the exact bartender(s) working at the pub (a student). It also allows quick queries for who is at the pub, depending on the load size defined for the pub.

A pub has a drunk_bucket, which hashes student_id to the load_size defined for the pub.

# Concept: Point to pointers
Pointer to pointers are an important concept, as this second order concept allow functions to modify the resources which a pointer points to. Most evidently, this concept is useful when manipulating nodes in a linked list, as we allocate resources for the first pointer that points to NULL. As we directly modify the value of a pointer away from NULL/0, we must have a pointer to the pointer.

# Game implementation:
A hash bucket is used to store customer entries for a pub, allowing for random lookups of students based on their id. Pointer to pointers allow code to express the allocation of new memory for new customers *explicitly at the location where the pointer chain terminates (is NULL)*, improving **readability** and **logic accuracy**.

# Tweakables:
Based on what we *use* to lookup students at a pub, we can change out the **hash function**. For example, **hash** by first 4 letters of student name.

# Concept: Hashing
Hashing allows us to quantify anything into an index, with different calculations to ensure random spread with fast hashing calculations.

# Implementation:
The hash of each student currently uses student_id, however depending on the require "key" of the system, we can move to hash names based on the first n letters of the name. This can be optimised by exploiting CPU pipelines to load calculate and store separate sums, however since names have a small constant size, this is not necessary.

# Functionality: add_student_to_pub()
Using pointers to 2 resources: student and a pub, the system **creates a customer record** on the pubs **drunk_bucket**; hashed by the students **id**. **Gender counters** of the pub are updated too.

# Functionality: print_student()
Prints **all attributes** of a struct student to the chosen **fileptr**.

# Functionality: print_pub()
Prints **all aggregates** of a struct pub to the chosen **fileptr**, as well as **customer record locations on the drunk_bucket**. Also lists all **bartenders**.

