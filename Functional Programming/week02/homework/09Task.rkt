#lang racket

#|Description:

Given a divisor d and a bound b, find the largest integer N, such that:

N is divisible by d
and N is less than or equal to b
and N is greater than 0.
Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(require math/number-theory)

(define (max-multiple d b)
  (cond
    [(< b 1) (error "Only > 0")]
    [(= b 1) -1] ;if d == 1 then the function would instatly output b
    [(divides? d b) b]
    [else (max-multiple d (sub1 b))])) 

(= (max-multiple 2 7) 6)
(= (max-multiple 3 10) 9)
(= (max-multiple 7 17) 14)
(= (max-multiple 10 50) 50)
(= (max-multiple 37 200) 185)
(= (max-multiple 7 100) 98)
(= (max-multiple 101 100) -1) ;my test
(= (max-multiple 1 100) 100) ;my test