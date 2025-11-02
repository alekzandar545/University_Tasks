#lang racket

#|Description:

Define a recursive and an iterative procedure that returns the number of palindromes in the interval [a, b].

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.
num-palindromes-rec is a linearly recursive procedure.
num-palindromes-iter is a linearly iterative procedure.|#

(define (palindrome? n)
  (= n (rev n))
)

(define (rev n) ;wanted to make this one liearly recursive but couldn't
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (+ (* result 10) (abs (remainder leftover 10))) (quotient leftover 10))
  ))
      (helper 0 n))

(define (num-palindromes-rec a b)
  (define (helper start finish)
    (cond
      [(> start finish) 0]
      [(palindrome? start) (add1 (helper (add1 start) finish))]
      [else (helper (add1 start) finish)]))
  (helper (min a b) (max a b)))


(define (num-palindromes-iter a b)
  (define (helper result current)
    (cond
      [(> current (max a b)) result]
      [(palindrome? current) (helper (add1 result) (add1 current))]
      [else (helper result (add1 current))]))
  (helper 0 (min a b)))


(= (num-palindromes-rec 1 101) 19)
(= (num-palindromes-rec 1 100) 18)
(= (num-palindromes-rec 100 1) 18)
(= (num-palindromes-rec 200 100) 10) ;my test

(= (num-palindromes-iter 1 101) 19)
(= (num-palindromes-iter 1 100) 18)
(= (num-palindromes-iter 100 1) 18)
(= (num-palindromes-rec 200 100) 10) ;my test