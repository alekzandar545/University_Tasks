#lang racket

#|Description:

Define a function that reverses a non-negative number.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Parameter validation is performed.
The function implements a linearly iterative process.|#

(define (rev n)
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (+ (* result 10) (remainder leftover 10)) (quotient leftover 10))
  ))
  (if (negative? n)
      (error "Only non-negative!")
      (helper 0 n)))


(= (rev 1) 1)
(= (rev 123) 321)
(= (rev 987654321) 123456789)
(= (rev 42) 24) ; my test