# Current Architecture:

Pub structure allows quick queries for the exact bartender(s) working at the pub (a student). It also allows quick queries for who is at the pub, depending on the load size defined for the pub.

A pub has a drunk_bucket, which hashes student_id to the load_size defined for the pub.
