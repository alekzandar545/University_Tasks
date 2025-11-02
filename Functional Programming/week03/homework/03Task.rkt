#lang racket

#|Description:

Define a procedure that returns the first order derivative of an unary procedure f with precision eps.


Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (derive f pr)
  (λ (x) (/ (- (f (+ x pr)) (f x)) pr))
  )

(= ((derive (λ (x) (* 2 x x x)) 1e-3) 2) 24.0120019999992)
(= ((derive (λ (x) (* 2 x x x)) 1e-6) 2) 24.000012004421478)
(= ((derive (λ (x) (* 4 x x x)) 1e-6) 3) 108.00003602184916) ;my test