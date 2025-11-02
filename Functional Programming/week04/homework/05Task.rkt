#lang racket

#|Description:

According to the fundamental theorem of arithmentics every natural number greater
 than 2 can be expressed as a product of prime numbers. Define a procedure that
 returns the sorted list of prime factors of a natural number.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Parameter validation is done.|#

(require math/number-theory)

(define (factorize x)
  (define (helper factors curr leftover)
    (cond
      [(= 1 leftover) factors]
      [(> curr (sqrt x)) (append factors (list leftover))]
      [(and (prime? curr) (divides? curr leftover)) (helper (append factors (list curr)) curr (/ leftover curr))]
      [else (helper factors (add1 curr) leftover)]))
  (helper null 2 x))

(equal? (factorize 2) '(2))
(equal? (factorize 10) '(2 5)) ;my test
(equal? (factorize 6) '(2 3))
(equal? (factorize 13) '(13))
(equal? (factorize 123) '(3 41))
(equal? (factorize 152) '(2 2 2 19))
(equal? (factorize 12356498) '(2 7 11 19 41 103))