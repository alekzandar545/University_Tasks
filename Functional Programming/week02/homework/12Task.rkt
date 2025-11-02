#lang racket

#|Description:

Write a procedure that accepts three whole numbers - a, b and n (assume n > 3) and returns the sum of the last three numbers from the following sequence.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(define(find-sum a b n)
  (define (next-sum sum b counter)
    (+ sum (* b (expt 2 counter))))
  (define (helper sum counter output)
    (cond
      [(= counter  n) output]
      [(>= counter (- n 3)) (helper (next-sum sum b counter) (add1 counter) (+ a (next-sum sum b counter) output))]
      [else (helper (+ sum (* b (expt 2 counter))) (add1 counter) output)]
      ))
  (if (<= n 3)
      (error "Invalid value for n")
      (helper 0 0 0)))

(= (find-sum 0 2 10) 3578) ; 510 + 1022 + 2046
(= (find-sum 5 3 5) 174) ; 26 + 50 + 98
(= (find-sum 0 3 4)  75) ; my test
