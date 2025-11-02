#lang racket

#|Description:

Take 2 strings s1 and s2 including only letters from a to z. Return a new sorted string,
 the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (longest str1 str2)
  (list->string
   (sort
    (remove-duplicates
     (append (string->list str1)(string->list str2)))
    char<?))) ;not sure if im supposed to use those built-in procedures


(equal? (longest "xyaabbbccccdefww" "xxxxyyyyabklmopq") "abcdefklmopqwxy")
(equal? (longest "abcdefghijklmnopqrstuvwxyz" "abcdefghijklmnopqrstuvwxyz") "abcdefghijklmnopqrstuvwxyz")
(equal? (longest "xyz" "abczyx") "abcxyz") ; my test
