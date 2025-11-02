#lang racket

#|Description:

Define a recursive procedure that takes two arguments - start and finish,
and returns the sum of all numbers in the interval [start, finish] whose digits are ordered in a decreasing order.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
sum-numbers is a linearly recursive procedure.
|#

(define (sum-numbers a b)
  (define(is-decreasing? x num)
    (cond
      [(zero? x) #t]
      [(> num (remainder x 10)) #f]
      [else (is-decreasing? (quotient x 10) (remainder x 10))]))
  (define (helper start end current sum)
    (cond
      [(> current end) sum]
      [(is-decreasing? current (remainder current 10)) (helper start end (add1 current) (+ current sum))]
      [else (helper start end (add1 current) sum)]))
  (helper (min a b) (max a b) (min a b) 0)
  )

(= (sum-numbers 1 9) 45)
(= (sum-numbers 199 203) 200)
(= (sum-numbers 219 225) 663)
(= (sum-numbers 225 219) 663)
(= (sum-numbers 10 20) 41);my test