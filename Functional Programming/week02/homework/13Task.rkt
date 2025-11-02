#lang racket

#|
Description:

Define an iterative procedure that accepts two numbers x and n and calculates the following sum: 
1+x+x^2+x^3+…+x^n.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
calculate-sum is a linearly iterative procedure.|#

(define (calculate-sum x n)
  (if (zero? n)
      1
      (+ (expt x n) (calculate-sum x (sub1 n)))))

(= (calculate-sum 5 0) 1)
(= (calculate-sum 5 1) 6)
(= (calculate-sum 4 2) 21) ;my test
(= (calculate-sum 10 1) 11)
(= (calculate-sum 1 11) 12)
(= (calculate-sum 2 11) 4095)