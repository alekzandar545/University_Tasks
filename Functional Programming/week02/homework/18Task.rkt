#lang racket

#|Description:

By using find-max and remove-first-occurrence, define a procedure that sorts a number in descending order.

Acceptance criteria:

All tests pass.
Add one new test case. Place a comment after it with the words my test.|#

(define (remove-first-occurrence x num)
  (define (helper position leftover accumulation)
    (cond
      [(zero? leftover) x]
      [(= (remainder leftover 10) num)(+ (*(quotient leftover 10)(expt 10  position)) accumulation)]
      [else (helper (add1 position) (quotient leftover 10) (+ accumulation (* (expt 10 position) (remainder leftover 10))))]
      ))
  (helper 0 x 0))

(define (find-max x)
  (define (helper leftover current-max)
    (cond
      [(zero? leftover) current-max]
      [(> (remainder leftover 10) current-max) (helper (quotient leftover 10)(remainder leftover 10))]
      [else (helper (quotient leftover 10) current-max)]))
  (helper x (remainder x 10)))

(define (sort-n x)
  (define (helper new leftover zeroes)
    (cond
      [(zero? leftover) (* new (expt 10 zeroes))]
      [(zero? (remainder leftover 10)) (helper new (quotient leftover 10) (add1 zeroes))];gotta handle this annying case :c
      [else (helper (+ (* new 10) (find-max leftover)) (remove-first-occurrence leftover (find-max leftover)) zeroes)]))
  (helper 0 x 0))

(sort-n 1234500)
(= (sort-n 1714) 7411)
(= (sort-n 123450) 543210)
(= (sort-n 123405) 543210)
(= (sort-n 123045) 543210)
(= (sort-n 120345) 543210)
(= (sort-n 102345) 543210)
(= (sort-n 8910) 9810)
(= (sort-n 321) 321)
(= (sort-n 29210) 92210)
(= (sort-n 1230) 3210)
(= (sort-n 55345) 55543)
(= (sort-n 14752) 75421)
(= (sort-n 329450) 954320)
(= (sort-n 9125) 9521)
(= (sort-n 1234) 4321) ;my test