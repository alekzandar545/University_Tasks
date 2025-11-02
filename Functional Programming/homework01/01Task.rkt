#lang racket

(define (sum-digits x)
  (if (zero? x)
      0
      (+ (remainder x 10) (sum-digits (quotient x 10)))))

(define (find-length x)
  (if (zero? x)
      0
      (+ 1 (find-length (quotient x 10)))))

(define (min-endurance-max-length  a b)
  (define (find-endurance x)
    (define (helper leftover counter)
      (let ([result (sum-digits leftover)])
        (if (<= (find-length result) 1)
            counter
            (helper result (add1 counter)))))
  (if (<= (find-length x) 1)
      0
      (helper x 1)))
  ;-----------------------------
  (define (helper start end min)
    (cond
      [(> start end) min]
      [(or
        (< (find-endurance start) (find-endurance min))
        (and (= (find-endurance start) (find-endurance min)) (> (find-length start) (find-length min))))
       (helper (add1 start) end start)]
      [else (helper (add1 start) end min)]
      ))
  (helper (min a b) (max a b) (min a b)))

(= (min-endurance-max-length 333 1000) 1000)
(= (min-endurance-max-length 333 2000)  1000)
(= (min-endurance-max-length 356 460) 360)
(= (min-endurance-max-length 498 701)  500)
(= (min-endurance-max-length 583 889)  600)
(= (min-endurance-max-length 34 621)  100)
(= (min-endurance-max-length 234 651)  234)