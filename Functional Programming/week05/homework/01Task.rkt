#lang racket

#|Define a procedure longest-ascending-sub xs that returns the longest sublist (sequence of consecutive elements) that is sorted in ascending order from xs.

Acceptance criteria:

All tests pass.|#

(require racket/trace)

(define (first-sorted-substr xs operator)
  (define (helper result leftover)
    (cond
      [(null? leftover) result]
      [(and (<= (length leftover) 1)) (append result (list (car leftover)))]
      [(operator (car leftover) (cadr leftover)) (helper (append result (list (car leftover))) (cdr leftover))]
      [else (append result (list (car leftover)))]))
  (helper null xs))

(define (longest-ascending-sub xs)
  (define (helper leftover result)
      (cond
        [(null? leftover) result]
        [(> (length (first-sorted-substr leftover <=)) (length result)) (helper (cdr leftover) (first-sorted-substr leftover <=))]
        [else (helper (cdr leftover) result)]))
  (helper xs null))

(equal? (longest-ascending-sub '(1 0 5)) '(0 5))
(equal? (longest-ascending-sub '(1 5 2 3 1 5 6 7 7 1 5)) '(1 5 6 7 7))
(equal? (longest-ascending-sub '(1 5 2 3 1 5 2 7 7 15)) '(2 7 7 15))
(equal? (longest-ascending-sub '(1 5 2 3 4 5 6 7 7 1 5)) '(2 3 4 5 6 7 7))
(equal? (longest-ascending-sub '(1 5 2 4 6 8 3 4 1)) '(2 4 6 8))