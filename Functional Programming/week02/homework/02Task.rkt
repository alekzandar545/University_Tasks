#lang racket

#|Description:

Define a linearly iterative procedure for calculating the sum of the digits of a non-negative number.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
Parameter validation is performed.
A linearly iterative procedure is implemented.|#

(define (sum-digits-iter x)
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (+ result (remainder leftover 10)) (quotient leftover 10))))
  (if(negative? x)
     (error "Cant be negative!")
     (helper 0 x)
     )
 )

(= (sum-digits-iter 12345) 15)
(= (sum-digits-iter 123) 6)
(= (sum-digits-iter 545) 14) ;my test