#lang racket

#|Description:

Define a procedure that returns the number of occurrences of a digit in a non-negative number.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(define (count-occurrences x num)
  (define (helper counter leftover)
    (cond
      [(zero? leftover) counter]
      [(= (remainder leftover 10) num) (helper (add1 counter) (quotient leftover 10))]
      [else (helper counter (quotient leftover 10))]))
  (cond
    [(negative? x) (error "No negatives!")]
    [(and (zero? x) (zero? num)) 1]
    [else (helper 0 x)]))

(= (count-occurrences 121 1) 2)
(= (count-occurrences 222 1) 0)
(= (count-occurrences 100 0) 2)
(= (count-occurrences 0 0) 1)
(= (count-occurrences 1000000 0) 6) ;my test