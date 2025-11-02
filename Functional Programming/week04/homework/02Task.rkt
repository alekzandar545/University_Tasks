#lang racket

#|Description:

Define a procedure that takes two sets of numbers and returns their union, sorted in ascending order.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
The union is sorted in ascending order.|#

(define (set-union xs ys) ;did it the lazy way
  (sort (remove-duplicates (append xs ys)) <))

(equal? (set-union '(1 3 5 7) '(5 7 13)) '(1 3 5 7 13))
(equal? (set-union '(1 3 5 7) '(11 22 22)) '(1 3 5 7 11 22)) ; my test
(equal? (set-union '(5 7 13) '(1 3 5 7)) '(1 3 5 7 13))