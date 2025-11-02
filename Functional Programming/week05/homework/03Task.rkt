#lang racket

#|Description:

Define a procedure that takes a list of numbers and returns a list of pairs in the form (xi . ni)
where xi spans the elements of xs and ni is the number of elements in xs that are greater than xi.

Acceptance criteria:

All tests pass.|#

;one line no helping funcs

(define (num-bigger-elements xs)
  (map (λ (x) (cons x (length (filter (curry < x) xs)))) xs))

(num-bigger-elements '(5 6 3 4)) '((5 . 1) (6 . 0) (3 . 3) (4 . 2))

(equal? (num-bigger-elements '(5 6 3 4)) '((5 . 1) (6 . 0) (3 . 3) (4 . 2)))
(equal? (num-bigger-elements '(1 1 1)) '((1 . 0) (1 . 0) (1 . 0)))