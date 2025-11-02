#lang racket

#|
Description:

Define two functions - even-if? and even-guards?, that check whether a whole number is even.

Acceptance criteria:

Add one new test case for each of the functions. Place a comment after it with the words my test.
All tests pass.
even-if? uses an if-else statement.
even-guards? uses guards.
|#

(define (even-if? x)
  (if (= (remainder x 2) 0)
      "Yes"
      "No"))

(define (even-guards? x)
  (cond
    [(= (remainder x 2) 0) "Yes"]
    [else "No"]))



(equal? (even-if? 2) "Yes")
(equal? (even-if? 15452) "Yes")
(equal? (even-if? 321) "No")
(equal? (even-if? 13124) "Yes") ;my test

(equal? (even-guards? 2) "Yes")
(equal? (even-guards? 15452) "Yes")
(equal? (even-guards? 321) "No")
(equal? (even-guards? 4141) "No") ;my test