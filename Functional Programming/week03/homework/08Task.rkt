#lang racket

#|Description:

Using accumulate define a procedure that:

for a given n (assume n > 2) calculates the expression 2^3 + 5^3 + 8^3 + ... + n^3;
checks whether a number in an interval passes a predicate p?;
calculates the factorial of a number;
checks whether a number is prime.
Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(require math/number-theory)

(define (accumulate f acc start end transform next)
  (if (> start end) 
      acc
      (accumulate f (f (transform start) acc) (next start) end transform next)
      )
 )

(define (cubed-interval-till n)
  (accumulate + 0 2 n (λ (x) (expt x 3)) (λ (x) (+ x 3))))

(define (fact-accum n)
  (accumulate * 1 1 n identity add1))

(define (any? start end f?)
  (accumulate (λ (x y) (or x y)) #f start end f? add1))

(define (prime-accum? n)
  (not (or (= n 1) (any? 2 (sqrt n) (λ (x) (divides? x n)))))
 )

(equal? (any? 1001 1500 (λ (x) (< x 1000))) #f)
(equal? (any? 1 100 odd?) #t)
(equal? (any? 2 2 odd?) #f) ; my test


(= (cubed-interval-till 11) 1976)
(= (cubed-interval-till 15) 4720)

(= (fact-accum 5) 120)
(= (fact-accum 8) 40320)

(equal? (prime-accum? 1) #f)
(equal? (prime-accum? 2) #t)
(equal? (prime-accum? 3) #t)
(equal? (prime-accum? 6) #f)
(equal? (prime-accum? 42) #f)
(equal? (prime-accum? 61) #t)