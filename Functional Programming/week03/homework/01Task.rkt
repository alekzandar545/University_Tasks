#lang racket

#|Description:

Define a procedure that accepts an unary procedure f and a number y and returns an unary procedure that for every x returns:

y, if it is greater than or equal to the result of applying f to x;
the result of applying f to x, otherwise.
Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (upper-bound f y)
  (λ (x) (max (f x) y)))

(=((upper-bound (λ (x) (* 2 x)) 100) 50) 100)
(=((upper-bound (λ (x) (* 2 x)) 100.236) 500.002) 1000.004)
(=((upper-bound (λ (x) (* 2 x)) 80) 3) 80)
(=((upper-bound (λ (x) (* 2 x)) 70) 30) 70)
(=((upper-bound (λ (x) (* 2 x)) 30) 70) 140)
(=((upper-bound (λ (x) (* 2 x)) 100) 52) 104) ;my test

#|Tests:
If g is upper-bound (λ (x) (* 2 x)) 100
    then g 50 -> 100
If g is upper-bound (λ (x) (* 2 x)) 100.236
    then g 500.002 -> 1000.004
If g is upper-bound (λ (x) (* 2 x)) 80
    then g 3 -> 80
If g is upper-bound (λ (x) (* 2 x)) 70
    then g 30 -> 70
If g is upper-bound (λ (x) (* 2 x)) 30
    then g 70 -> 140|#