#lang racket

#|Description:

Define a procedure that returns a list of pairs comprising the cartesian product of two sets.

Note: There is a built-in procedure (cartesian-product xs ys [zs ...]). This exercise is the only time you should not use it.

Acceptance criteria:

All tests pass.
The built-in procedure is not used.|#

;rename to kebap-case

(define (my-cartesian-product xs ys)
  (define (x-helper x-leftover result)
    (define (y-helper y-leftover y-result x-curr )
      (if (null? y-leftover)
          y-result
          (y-helper (cdr y-leftover) (append y-result (list (cons x-curr (car y-leftover)))) x-curr)))
    (if (null? x-leftover)
        result
        (x-helper (cdr x-leftover) (append result (y-helper ys null (car x-leftover))))
      ))
  (x-helper xs null))

(equal? (my-cartesian-product '(1 2) '(3 4)) '((1 . 3) (1 . 4) (2 . 3) (2 . 4)))
(equal? (my-cartesian-product '(1 2 3 4 5) '(6 7 8)) '((1 . 6) (1 . 7) (1 . 8) (2 . 6) (2 . 7) (2 . 8) (3 . 6) (3 . 7) (3 . 8) (4 . 6) (4 . 7) (4 . 8) (5 . 6) (5 . 7) (5 . 8)))