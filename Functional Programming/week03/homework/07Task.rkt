#lang racket

#|Description:

Define the recursive version of the accumulate procedure we defined in class (Task 6).

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#


(define (accumulate-rec f acc start end transform next)
  (if (> start end) ; I don't get this, don't we use recursion in the task 6 example anyway ;p? (OR did you mean linear recursion herE?)
      acc
      (f (f (transform start) acc) (accumulate-rec f acc (next start) end transform next))
      )
  )

; 1 + 2 + 3 + ... + 100
(= (accumulate-rec + 0 1 100 identity add1) 5050)

; 1 - (2 - (3 - (4 - 5)))
(= (accumulate-rec - 0 1 5 identity add1) 3)

; 1 * 2 * 3 * ... * 10
(= (accumulate-rec * 1 1 10 identity add1) 3628800)

; 1 * 3 * 5 * ... * 10
(= (accumulate-rec * 1 1 15 identity (curry + 2)) 2027025)

; 1^2 + 3^2 + 5^2 + ... + 100^2
(= (accumulate-rec + 0 1 100 (λ (x) (expt x 2)) add1) 338350)

(= (accumulate-rec + 0 1 2 (λ (x) (expt x 2)) add1) 5) ; my test