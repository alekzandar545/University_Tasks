#lang racket

;gotta derrive the smallest pralindrome from n

(define (n-to-list n)
  (define (helper result leftover)
    (if (zero? leftover)
        (sort (reverse result) <)
        (helper (append result (list (remainder leftover 10))) (quotient leftover 10))))
  (helper null n))

(define (palindromize n)
  (define (helper leftover result counter)
  (if (null? leftover)
      result
      (helper (cddr leftover) (+ result
                                 (* (car leftover)(expt 10 (+ (length leftover) (sub1 counter))))
                                 (* (car leftover) (expt 10 counter))) (add1 counter))))
  (helper (n-to-list n) 0 0))

(= 11 (palindromize 11))
(= 3457887543  (palindromize 3354457878))
(= 13457899875431 (palindromize 11335445789789))