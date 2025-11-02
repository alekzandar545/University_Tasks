#lang racket

(require racket/trace)

(define (g-l-sum limit)
  (cons 1 (sub1 limit)));did i get this right? :D

;(combinations (range 1 (add1 14)) 2)

(equal? (g-l-sum 2) '(1 . 1))
(equal? (g-l-sum 14) '(6 . 4))