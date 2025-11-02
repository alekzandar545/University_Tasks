#lang racket

#|
Description:

Define a procedure that returns the average of the sum of the squares of two whole numbers.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
|#

(define (sq-avg x y)
  (/ (+ (* x x) (* y y)) 2))

(= (sq-avg 5 0) 12.5)
(= (sq-avg 10 13) 134.5)
(= (sq-avg 2 4) 10) ;my test