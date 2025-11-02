#lang racket

#|Description:

Define two procedures - remove-all-no-proc and remove-all-proc, that remove an element from a list.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
remove-all-no-proc is defined without using built-in procedures for removing elements from lists.
remove-all-proc is defined using built-in procedures for removing elements from lists.|#

(define (remove-all-no-proc x xs)
  (define (helper leftover result)
    (cond
      [(null? leftover) result]
      [(equal? (car leftover) x) (helper (cdr leftover) result)]
      [else (helper (cdr leftover) (append result (list (car leftover))))]
      ))
  (helper xs null)
  )

(define (remove-all-proc x xs)
  (remove* (list x) xs)
  )

; without using a predefined procedure
(equal? (remove-all-no-proc 1 '(1 1 1 2)) '(2))
(equal? (remove-all-no-proc 1 '(2 5 6)) '(2 5 6))
(equal? (remove-all-no-proc 1 '(1)) '())
(equal? (remove-all-no-proc 1 '(1 2 1 1)) '(2))
(equal? (remove-all-no-proc "RNN" '("CNN" "RNN" "GAN" "RNN")) '("CNN" "GAN"))
(equal? (remove-all-no-proc "hello there" '("hello" "there" "hello there" "hello there")) '("hello" "there"));my test

; using a predefined procedure
(equal? (remove-all-proc 1 '(1 1 1 2)) '(2))
(equal? (remove-all-proc 1 '(2 5 6)) '(2 5 6))
(equal? (remove-all-proc 1 '(1)) '())
(equal? (remove-all-proc 1 '(1 2 1 1)) '(2))
(equal? (remove-all-proc "RNN" '("CNN" "RNN" "GAN" "RNN")) '("CNN" "GAN"))
(equal? (remove-all-proc "hello there" '("hello" "there" "hello there" "hello there")) '("hello" "there"));my test