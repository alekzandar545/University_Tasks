#lang racket

#|Description:

Define a recursive procedure that returns the sum of all prime divisors of a given number.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(require math/number-theory)

(define (sum-prime-divs-rec x)
  (define (helper result counter)
    (cond
      [(>= counter  x) result]
      [(and (divides? counter x) (prime? counter)) (helper (+ result counter) (add1 counter))]
      [else (helper result (add1 counter))]))
  (if (prime? x)
      (+ (helper 0 2) x)
      (helper 0 2)))

(= (sum-prime-divs-rec 0) 0)
(= (sum-prime-divs-rec 6) 5) ; 2 + 3
(= (sum-prime-divs-rec 18) 5) ; 2 + 3
(= (sum-prime-divs-rec 19) 19)
(= (sum-prime-divs-rec 45136) 53)
(= (sum-prime-divs-rec 4) 2) ;my test