#lang racket

(define (shuffle-merge xs ys)
  (define (helper leftoverX leftoverY result)
    (cond
      [(and (null? leftoverX) (null? leftoverY)) result]
      [(null? leftoverX) (helper leftoverX (cdr leftoverY) (append result (list (car leftoverY))))]
      [(null? leftoverY)(helper (cdr leftoverX) leftoverY (append result (list (car leftoverX))))]
      [else (helper (cdr leftoverX) (cdr leftoverY) (append result (list (car leftoverX) (car leftoverY))) )]))
  (helper xs ys null))


(shuffle-merge '(1) '())
(equal? (shuffle-merge '(1) '()) '(1))
(equal? (shuffle-merge '(3 4 5) '(2)) '(3 2 4 5))
(equal? (shuffle-merge '(3 4 5) '(9 2)) '(3 9 4 2 5))
(equal? (shuffle-merge '(3 2 8) '(5 6 1 9 11)) '(3 5 2 6 8 1 9 11))