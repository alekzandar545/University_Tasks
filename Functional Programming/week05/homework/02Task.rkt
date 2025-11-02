#lang racket

#|Description:

Define a procedure that accepts a list of numbers and a list of predicates and returns only the elements that satisfy all of the predicates.

Acceptance criteria:

All tests pass.|#

;1 line no recursion
;think bout thats
(define (where1 xs predicates)
  (filter (lambda (x) (andmap (curry equal? #t) (map (lambda (p) (p x)) predicates))) xs)
  )

;my take
(define (where xs predicates)
  (filter (λ (x) (andmap (λ (p) (and #t (p x))) predicates)) xs))
    
(where '(3 4 5 6 7 8 9 10) (list even? (lambda (x) (> x 5))))

(equal? (where '(3 4 5 6 7 8 9 10) (list even? (lambda (x) (> x 5)))) '(6 8 10)) ; all even numbers greater than 5
(equal? (where '(3 4 5 7) (list even? (lambda (x) (> x 5)))) '()) ; no numbers are even and greater than 5
(equal? (where '() (list odd? (λ (x) (> x 3)) (λ (x) (< x 20)))) '())
(equal? (where '(1 2 3 4 5 6 7 8 9 10 11 13 15) (list odd? (λ (x) (> x 3)) (λ (x) (< x 20)))) '(5 7 9 11 13 15))