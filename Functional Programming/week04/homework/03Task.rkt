#lang racket

#|Description:

Define procedures that accept a list of digits and return the number that is build by traversing
the list from right to left. Create two versions - rev-fold that utilizes folding,
and rev-lin-iter that creates recursion.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
rev-fold uses folding.
rev-lin-iter uses recursion.|#

(define (rev-fold xs)
  (foldr (λ (x acc) (+ (* 10 acc) x)) 0 xs))

(define (rev-lin-iter xs)
  (define (helper leftover result count)
    (if (null? leftover)
      result
      (helper (cdr leftover) (+ (* (expt 10 count) (car leftover)) result) (add1 count))))
  (helper xs 0 0))

; using folding
(= (rev-fold '(1 2 3)) 321)
(= (rev-fold '(9 1 3)) 319) ;my test
(= (rev-fold '(1 2 3 4 5 6 7 8 9)) 987654321)

; using a linearly iterative procedure
(= (rev-lin-iter '(1 2 3)) 321)
(= (rev-lin-iter '(9 1 3)) 319) ;my test
(= (rev-lin-iter '(1 2 3 4 5 6 7 8 9)) 987654321)