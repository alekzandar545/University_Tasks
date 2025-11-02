#lang racket

#|Description:

Define a procedure (insert-at x i xs) that inserts an element at a given index in a list.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Parameter validation is done.|#

(define (insert-at x i xs)
  (define (helper leftover result index)
    (if (<= i index)
        (append result (list x) leftover)
        (helper (cdr leftover) (append result (list (car leftover))) (add1 index))))
  (if (not (<= 0 i (sub1 (length xs))))
      (error "Invalid index input!")
      (helper xs null 0)))

(equal? (insert-at 1 0 '()) '(1))
(equal? (insert-at 1 0 '(2)) '(1 2))
(equal? (insert-at 10 1 '(1 2 3)) '(1 10 2 3))
(equal? (insert-at 1 0 '()) '(1))
(equal? (insert-at 1 0 '(2)) '(1 2))
(equal? (insert-at 10 1 '(1 2 3)) '(1 10 2 3))
(equal? (insert-at 7 0 '(1 2 3)) '(7 1 2 3))
(equal? (insert-at 7 1 '(1 2 3)) '(1 7 2 3))
(equal? (insert-at 7 3 '(1 2 3)) '(1 2 3 7))
(equal? (insert-at 7 -1 '(1 2 3)) '(1 2 3 7)) ; error "Invalid index input!" ;my test