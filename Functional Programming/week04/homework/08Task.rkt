#lang racket

#|Description:

By using num-to-xs and xs-to-num define a procedure that sorts a number in descending order.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (num-to-xs n)
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (cons (remainder leftover 10) result) (quotient leftover 10))
     )
    )
  (helper null n)
  )

(define (xs-to-num xs)
  (foldl
   (λ (digit acc) (+ (* acc 10) digit))
   0
   xs
   )
  )

(define (sort-n x)
  (xs-to-num (sort (num-to-xs x) >))
  )

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
(= (sort-n 12340) 43210) ;my test