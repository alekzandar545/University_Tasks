#lang racket

#|Description:

Define a predicate that accepts two non-negative inputs - x and y, and checks whether x is a sub-number of y.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(define (find-length x)
  (define (helper leftover)
    (if (zero? leftover)
        0
        (+ 1 (helper (quotient leftover 10)))))
   (if (zero? x)
      1
      (helper x)))

(define (sub-num? small big)
  (define (helper leftover length)
    (cond
      [(zero? leftover) #f]
      [(= (remainder leftover (expt 10 length)) small) #t]
      [else (helper (quotient leftover 10) length)]))
  (if (zero? big)
      (zero? small)
      (helper big (find-length small))))

(equal? (sub-num? 123 5123783) #t)
(equal? (sub-num? 0 0) #t)
(equal? (sub-num? 10 101) #t)
(equal? (sub-num? 101 101) #t)
(equal? (sub-num? 10 0) #f)
(equal? (sub-num? 1253 5123783) #f)
(equal? (sub-num? 12 0) #f)
(equal? (sub-num? 21 22312131) #t) ;my test