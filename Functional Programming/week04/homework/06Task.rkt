#lang racket

#|Description:

Define a procedure that accepts a list of numbers and returns an unary procedure of a natural number - 
k
, such that the result from a call to it (the new procedure) is the 
kth
 largest negative number in the list.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Parameter validation is done.|#

(define (kth-max-min xs)
  (λ (k)
    (define sorted-xs (filter negative? (sort (remove-duplicates xs) <)))
    (define (helper curr leftover)
      (if (>= curr k)
          (car leftover)
          (helper (add1 curr) (cdr leftover))))
    (if(< (length sorted-xs) k)
       (error "error: No such number!")
       (helper 1 sorted-xs))))

(= ((kth-max-min '(-1)) 1) -1)
(= ((kth-max-min '(-1 -5 -6 -6 -6 -6)) 2) -5)
(= ((kth-max-min '(-1 -1 -5 -6 -6 -6 -6)) 2) -5)
(= ((kth-max-min '(1 2 3 4 -5 6 7 -2 -1 0)) 2) -2)
(= ((kth-max-min '(1 2 3 4 -5 6 7 -2 -1 0)) 3) -1) ; my test
((kth-max-min '(-1 0 -1 0 -2 3 1 -1)) 3) ; error: No such number!