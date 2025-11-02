#lang racket

#|A cubic prime number is a prime number that is the difference between two subsequent natural numbers. For example, 
61 is such a number because 
61 = 5^3−4^3
. Define a procedure that returns the 
n-th cubic prime number.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
Parameter validation is performed.|#

(require math/number-theory)

(define (find-cubic-difference x)
  (if(< x 2)
     (error "We need natural numbers :<")
     (- (expt x 3) (expt (sub1 x) 3))))

(define (nth-cubic x)
  (define (helper sum num count)
    (cond
      [(>= count x) sum]
      [(prime? (find-cubic-difference num)) (helper (find-cubic-difference num) (add1 num) (add1 count))]
      [else (helper sum (add1 num) count)]))
  (helper 0 2 0))

(= (nth-cubic 1) 7)
(= (nth-cubic 4) 61) ; 61 is the 4th cubic prime number
(= (nth-cubic 50) 55897) ; 55897 is the 50th cubic prime number
(= (nth-cubic 100) 283669)
(= (nth-cubic 200) 1570357)
(= (nth-cubic 2) 19) ;my test