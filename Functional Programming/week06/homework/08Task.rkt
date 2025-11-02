#lang racket

;pretty matrix is when 1 is in the middle
;we can only swap row/columns
;what we gotta do is just find the coordinates

(define (find-coords xss)
  (define(find-row xss)
  (if (= 1 (apply + (car xss)))
      0
      (add1 (find-row (cdr xss)))))
  ;------------------------------------
  (define (find-col xs)
  (if (= 1 (car xs))
      0
      (add1 (find-col (cdr xs))))
  )
  ;-------------------------------------
  (cons (find-row xss) (find-col (list-ref xss (find-row xss))))
 )

(define (steps-bm xss)
  (+ (abs (- 2 (car (find-coords xss)))) (abs (- 2 (cdr (find-coords xss))))))


(= (steps-bm '((0 0 0 0 0)
               (0 0 0 0 1)
               (0 0 0 0 0)
               (0 0 0 0 0)
               (0 0 0 0 0))) 3)

(= (steps-bm '((0 0 0 0 0)
               (0 0 0 0 0)
               (0 1 0 0 0)
               (0 0 0 0 0)
               (0 0 0 0 0))) 1)

(= (steps-bm '((0 0 0 0 0)
               (0 0 0 0 0)
               (0 0 1 0 0)
               (0 0 0 0 0)
               (0 0 0 0 0))) 0)

(= (steps-bm '((0 0 0 0 0)
               (0 0 0 0 0)
               (0 0 0 0 0)
               (0 0 0 0 0)
               (0 0 0 0 1))) 4)