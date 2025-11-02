#lang racket

#|Description:

Define a procedure that reverses a list using foldl.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
foldl is used to solve the task.|#

(define (my-reverse-foldl xs)
  (foldl (λ (x acc) (cons x acc)) null xs))

(equal? (my-reverse-foldl '(1 2 3 4 5)) '(5 4 3 2 1))
(equal? (my-reverse-foldl '(4 5 9 1)) '(1 9 5 4)) ; my test
(equal? (my-reverse-foldl '(11 2 3 8 5)) '(5 8 3 2 11))