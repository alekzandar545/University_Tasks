#lang racket

#|Description:

Define a linearly recursive function for calculating the sum of the digits of a whole number. Assume correct input.

Acceptance criteria:

All tests pass.|#

(define (sum-digits-rec n)
  (if (zero? n)
      0
      (+ (remainder n 10) (sum-digits-rec (quotient n 10)))))
 

(= (sum-digits-rec 123) 6)
(= (sum-digits-rec 12345) 15)
(= (sum-digits-rec 545) 14) ;my test