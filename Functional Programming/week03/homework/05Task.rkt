#lang racket

#|Description:

Define the procedures derive-x f eps and derive-y f eps
that correspondingly return the first order derivative of a binary procedure f with precision eps.
Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (derive-x f eps)
  (λ (x y) (/ (-(f (+ x eps) y) (f x y)) eps)))

(define (derive-y f eps)
  (λ (x y) (/ (-(f x (+ y eps)) (f x y)) eps)))

(define (g x y) (+ (* x x x) (* x y) (* y y)))
(= ((derive-x g 0.0001) 2 3) 15.000600010033338)
(= ((derive-y g 0.0001) 2 3) 8.00009999998963)
(= ((derive-y g 0.0001) 3 4) 11.00009999994711) ; my test