#lang racket

#|Description:

A number is a palindrome if and only if it is the same number from right to left as well as from left to right.
 Define a predicate that checks whether a non-negative number is a palindrome.

Acceptance criteria:

All tests pass.
Parameter validation is performed.|#
; gonna use code from last task


(define (palindrome? n)
  (= n (rev n))
)

(define (rev n)
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (+ (* result 10) (remainder leftover 10)) (quotient leftover 10))
  ))
  (if (negative? n)
      (error "Only non-negative!")
      (helper 0 n)))

(equal? (palindrome? 1) #t)
(equal? (palindrome? 6) #t)
(equal? (palindrome? 1010) #f)
(equal? (palindrome? 505) #t)
(equal? (palindrome? 123321) #t)
(equal? (palindrome? 654) #f)
(equal? (palindrome? 121) #t)
(equal? (palindrome? 12) #f)
(equal? (palindrome? 120) #f)
(equal? (palindrome? 12321) #t)
(equal? (palindrome? 1221) #t)
(equal? (palindrome? 545) #t) ; my test\sssss