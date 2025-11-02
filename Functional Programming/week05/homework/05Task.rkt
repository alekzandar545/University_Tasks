#lang racket

;fix cases

(define (right-max xs)
  (define (helper leftover result curr-max)
    (cond
      [(null? leftover) result]
      [(> curr-max (car leftover)) (helper (cdr leftover) (append result (list curr-max)) curr-max)]
      [else (helper (cdr leftover) (append result (list (car leftover))) (car leftover))]))
  (reverse (helper (reverse xs) null (last xs))))

(equal? (right-max (list 1 2 3 4 -5 6 7 -2 -1 0)) (list 7 7 7 7 7 7 7 0 0 0))
(equal? (right-max (list 5 8 9 12)) (list 12 12 12 12))
(equal? (right-max (list 4 3 2 1 0)) (list 4 3 2 1 0))

