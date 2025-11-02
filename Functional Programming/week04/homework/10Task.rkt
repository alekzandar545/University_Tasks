#lang racket

#|Description:

Define two procedures - concat-proc and concat-rec, that concatenate two lists.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
concat-proc uses a predefined procedure.
concat-rec uses a linearly iterative process.|#

(define (concat-proc xs ys)
  (append xs ys)
  )

(define (concat-rec xs ys) ;reversing the first list so i use cons instead of append
  (define (helper result leftover)
    (if (null? leftover)
        result
        (helper (cons (car leftover) result) (cdr leftover))))
   (helper ys (reverse xs)))

; using a predefined procedure
(equal? (concat-proc '(1 2 3) '(4 5 6)) '(1 2 3 4 5 6))

; using a linearly iterative process
(equal? (concat-rec '(1 2 3) '(4 5 6)) '(1 2 3 4 5 6))
(equal? (concat-rec '(1 2 3 4 5) '(4 5 6)) '(1 2 3 4 5 4 5 6)) ; my test