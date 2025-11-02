#lang racket

#|Description:

Define a procedure that accepts a list of nested lists and
returns a list containing only one level with all the elements from all lists.

Acceptance criteria:

All tests pass.|#

(define (contains-list? xs)
    (and (not (null? xs)) (or (list? (car xs)) (contains-list? (cdr xs)))))

(define (my-flatten xs)
  (define (helper result leftover)
    (cond
      [(null? leftover) result]
      [(and (list? (car leftover)) (contains-list? (car leftover)))
       (helper (append result (my-flatten (car leftover))) (cdr leftover))]
      [(list? (car leftover))
       (helper (append result (car leftover)) (cdr leftover))]
      [else (helper (append result (list (car leftover))) (cdr leftover))]))
  (helper null xs))

;(contains-list? '(1 2 3 4 5 6 7 8 9 10 11 12))
(my-flatten '((1 2 3) (4 5 6) ((7 8) (9 10 (11 (12))))))
(equal? (my-flatten '((1 2 3) (4 5 6) ((7 8) (9 10 (11 (12)))))) '(1 2 3 4 5 6 7 8 9 10 11 12))
(equal? (my-flatten '(422 22 ((((11))) 33) (131 31 121 12121 11 (12555 555)))) '(422 22 11 33 131 31 121 12121 11 12555 555))