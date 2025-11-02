#lang racket

(require math/number-theory)

(define (primes-prod x)
  (define (helper count result)
    (cond
      [(> count (sqrt x)) result] 
      [(prime? count)(helper (add1 count) (* result count))]
      [else (helper (add1 count) result)]))

  (helper 1 1))

(primes-prod 49)

(= (primes-prod 12) 6)
(= (primes-prod 49) 210)
(= (primes-prod 1200) 200560490130)
