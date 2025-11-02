#lang racket

#|Description:

A digital root is the recursive sum of all the digits in a number. Given n,
take the sum of the digits of n. If that value has more than one digit,
continue reducing in this way until a single-digit number is produced.
This is only applicable to the natural numbers.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#
(define (sum-numbers x)
  (if (zero? x)
      0
      (+ (remainder x 10) (sum-numbers (quotient x 10)))))

(define (digital-root x)
  (if (zero? (quotient x 10))
      (sum-numbers x)
      (digital-root (sum-numbers x))))

(= (digital-root 16) 7)
; => 1 + 6
; => 7
(= (digital-root 942) 6)
; => 9 + 4 + 2
; => 15
; => 1 + 5
; => 6
(= (digital-root 132189) 6)
(= (digital-root 493193) 2)
(= (digital-root 12341) 2) ;my test