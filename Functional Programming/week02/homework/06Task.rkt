#lang racket

#|Description:

Define a procedure sum-special-primes n d that returns the sum of the first n prime numbers that contain the digit d.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(require math/number-theory)

(define (contains? x num)
  (and (not (zero? x))
       (or (= (remainder x 10) num) (contains? (quotient x 10) num))))

(define (sum-special-primes x num)
  (define (helper sum current counter)
    (cond
      [(>= counter x) sum]
      [(and (prime? current) (contains? current num)) (helper (+ sum current) (add1 current) (add1 counter))]
      [else (helper sum (add1 current) counter)]))
  (helper 0 0 0))

(= (sum-special-primes 5 2) 392)
(= (sum-special-primes 5 3) 107)
(= (sum-special-primes 10 3) 462)
(= (sum-special-primes 2 2) 25) ;my test