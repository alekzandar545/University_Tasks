#lang racket

#|Description:

Define the procedure derive-n f n eps that returns the 
n
t
h
 order derivative of an unary procedure f with precision eps.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (apply-n f n)
  (if (zero? n)
      identity
      (λ (x) ((apply-n f (sub1 n)) (f x)))))

(define (derive f pr)
  (λ (x) (/ (- (f (+ x pr)) (f x)) pr))
 )
#|
(define (derive-n f n eps)
  (λ (x)
    (if (zero? n)
        (f x)
        ((derive-n (derive f eps) (sub1 n) eps) x)
        )
    )
  )
|#

(define (derive-n f n eps)
  ((apply-n (λ (f) (derive f eps)) n) f)
  )

(= ((derive (λ (x) (* 2 x x x)) 1e-3) 2) 24.0120019999992) ; my test
(= ((derive-n (λ (x) (* 2 x x x)) 3 1e-3) 2) 12.000015203739167)
