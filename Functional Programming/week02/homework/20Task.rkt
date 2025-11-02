#lang racket

#|Description:

Define a recursive procedure (sum-divisible-numbers start finish k) that returns the sum of all
numbers from the interval [start, finish] whose digits sum up to a number that is evenly divisible by k.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(require math/number-theory)

(define (sum-digits x)
  (if (zero? x)
      0
      (+ (remainder x 10) (sum-digits (quotient x 10)))))

(define (sum-divisible-numbers a b k)
  (define (helper start finish current sum)
    (cond
      [(= current finish) sum]
      [(divides? k (sum-digits current))(helper start finish (add1 current) (+ sum current))]
      [else (helper start finish (add1 current) sum)]))
  (helper (min a b) (max a b) (min a b) 0)
  )

(= (sum-divisible-numbers 0 10 5) 5)
(= (sum-divisible-numbers 0 100 5) 990)
(= (sum-divisible-numbers 100 0 5) 990)
(= (sum-divisible-numbers 95 0 5) 894) ;my test