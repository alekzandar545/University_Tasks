#lang racket

#|Description:

Define a procedure that takes a single argument procedure and returns it applied 
n
 times.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (apply-n f n)
   (λ (x) (if (zero? n)
           x
           ((apply-n f (sub1 n)) (f x)))))

(= ((apply-n (λ (x) (* 2 x)) 5) 2) 64)
(= ((apply-n (λ (x) (quotient x 10)) 2) 100) 1)
(= ((apply-n (λ (x) (+ 2 x)) 5) 0) 10) ;my test