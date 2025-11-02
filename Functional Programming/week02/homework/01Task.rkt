#lang racket

#|Description:

Define a recursive and an iterative procedure for calculating the number of digits of a non-negative number.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
count-digits-iter is a linearly iterative procedure.
count-digits-rec is a linearly recursive procedure.
Parameter validation is performed for both procedures.|#

(define (count-digits-iter x)
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (add1 result) (quotient leftover 10))))
  (if(negative? x)
     (error "Only non-negative!")
     (helper 0 x)))

(define (count-digits-rec x)
  (cond
    [(negative? x) (error "Only non-negative")]
    [(zero? x) 0]
    [else (add1 (count-digits-rec (quotient x 10)))]))

(= (count-digits-iter 12345) 5)
(= (count-digits-iter 123) 3)
(= (count-digits-iter 1241551412) 10) ;my test

(= (count-digits-rec 12345) 5)
(= (count-digits-rec 123) 3)
(= (count-digits-rec 1241551412) 10) ;my test