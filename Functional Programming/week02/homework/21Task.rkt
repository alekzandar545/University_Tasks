#lang racket

#|Description:

A number - x, is a pentagonal number if we can plot x poits in the form of a pentagon on a plain.

Define an iterative procedure that accepts a natural number - n, and returns the n-th pentagonal number.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
p is a linearly iterative procedure.|#

(define (p n)
  (define (helper sum curr)
    (cond
      [(> curr n) sum]
      [else (helper (+ sum (* 2 curr) (- curr 2)) (add1 curr))]))
  (helper 0 1))

(= (p 1) 1)
(= (p 2) 5)
(= (p 3) 12)
(= (p 4) 22)
(= (p 5) 35)
(= (p 6) 51)
(= (p 7) 70) ;my test