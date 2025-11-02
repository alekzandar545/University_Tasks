#lang racket

#|Description:

By using recursion define a procedure that implements the list-ref procedure we discussed in class.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Parameter validation is done.|#

(define (my-list-ref xs i)
  (define (helper leftover index)
    (if(>= index i)
       (car leftover)
       (helper (cdr leftover) (add1 index))))
  (if (or (negative? i)(<= (length xs) i))
      (error "Invalid index~!")
      (helper xs 0)))

(= (my-list-ref '(1 2 3) 0) 1)
(= (my-list-ref '(1 2 3) 1) 2)
(equal? (my-list-ref '("Hello" 2 ("nested list")) 0) "Hello")
;(my-list-ref '(1 2 3) -100) ; error: Invalid index!
(my-list-ref '(1 2 3) 999) ; error: Invalid index! ;my test