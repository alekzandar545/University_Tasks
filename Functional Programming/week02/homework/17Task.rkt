#lang racket

#|Description:

Define a procedure that removes the first occurrence of a digit in a number by going from right to left.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#


(define (remove-first-occurrence x num)
  (define (helper position leftover accumulation)
    (cond
      [(zero? leftover) x]
      [(= (remainder leftover 10) num)(+ (*(quotient leftover 10)(expt 10  position)) accumulation)]
      [else (helper (add1 position) (quotient leftover 10) (+ accumulation (* (expt 10 position) (remainder leftover 10))))]
      ))
  (helper 0 x 0))

(= (remove-first-occurrence 15365 5) 1536)
(= (remove-first-occurrence 15360 0) 1536)
(= (remove-first-occurrence 15300 0) 1530)
(= (remove-first-occurrence 15365 1) 5365)
(= (remove-first-occurrence 35365 3) 3565)
(= (remove-first-occurrence 1212 1) 122)
(= (remove-first-occurrence 1212 2) 121)
(= (remove-first-occurrence 4242 2) 424) ; my test