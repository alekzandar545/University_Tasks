#lang racket

#|Description:

Define a predicate that accepts a natural number n and returns whether 
n^2 ends in the digits of n.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
Parameter validation is performed.|#

(define (automorphic? x)
  (define (helper? leftover expon)
     (and
      (not (= leftover (expt x 2)))
      (or (= leftover x)
          (helper? (remainder (expt x 2) (expt 10 expon)) (add1 expon)))))
  (helper? 0 1))

(equal? (automorphic? 3)#f)
(equal? (automorphic? 10)#f)
(equal? (automorphic? 5)#t)
(equal? (automorphic? 25)#t)
(equal? (automorphic? 76)#t) 
(equal? (automorphic? 890625)#t) 
(equal? (automorphic? 625)#t) 
(equal? (automorphic? 36) #f)
(equal? (automorphic? 11) #f)
(equal? (automorphic? 121) #f) ;my test