#lang racket

#|
Define the following procedures:

- `min-if`, `min-guard`, `min-built-in`: return the smaller of two numbers;
- `last-digit`: returns the last digit of a number;
- `quotient-whole`: returns the
       quotient of the division of two numbers;
- `div-whole`: returns the
       quotient and remainder of the division of two numbers;
- `remove-last-digit`: returns a whole number without its last digit;
- `avg-whole`: returns the average of two whole numbers;
- `round-two-dig`: return the number rounded to the second digit after the decimal point.

**Acceptance criteria:**

1. All tests pass.
2. `min-if` uses an if-else statement.
3. `min-guard` uses guards.
4. `min-built-in` uses built-in functions.
|#

#|
(define (min-if x y) 
  (if (< x y)
    x
    y
  )
)
(define (min-guard x y) 
  (cond
    [(< x y) x]
    [(= x y) x]
    [else y]
  )
)
(define (min-built-in x y) 
  (min x y)
)
(define (last-digit x) 
  (remainder x 10)
)
(define (quotient-whole x y) #|celochisleno delenie|#
  (quotient x y) 
)
(define (div-whole x y) 
  (/ x y)
)
(define (remove-last-digit x) 
  (quotient x 10)
)
(define (average-whole x y) 
  (/ 2 (+ x y))
)
(define (round-two-digit x) 
  (/ 100 (round (* 100 x)))
)


(= (min-if -60 -15) -60)
(= (min-if 15 60) 15)
(= (min-if 60 15) 15)

(= (min-guard 15 60) 15)
(= (min-guard 60 15) 15)

(= (min-built-in 5 6) 5)

(= (last-digit 154) 4)

(= (quotient-whole 64 2) 32)

(div-whole 154 17) ; 9 1/17

(= (remove-last-digit 154) 15)

(= (average-whole 5 1542) 773.5)

(= (round-two-digit pi) 3.14)

------------------------------------------------------------------|#

#|
Define two functions - `fact-rec` and `fact-iter`,
that return the factorial of a `non-negative` number.

**Acceptance criteria:**

1. All tests pass.
2. Parameter validation is performed.
3. `fact-rec` creates a linearly recursive process.
4. `fact-iter` creates a linearly iterative process.
|#
#|
(define (fact-rec n)
  (cond
   [(zero? n) 1]
   [(negative? n) (error "N is negative")]
   [else (* n (fact-rec (sub1 n)))]
  )
)
(define (fact-iter n)
  (define(fact-helper n res)
     (if (zero? n)
        res
        (fact-helper (sub1 n) (* n res))
      )
   )
  (if (negative? n)
      (error "N is negative")
      (fact-helper n 1)
   )
)
; (fact-rec -1)
(= (fact-rec 0) 1)
(= (fact-rec 1) 1)
(= (fact-rec 11) 39916800)

(= (fact-iter 0) 1)
(= (fact-iter 1) 1)
(= (fact-iter 11) 39916800)|#

#|---------------------------------------------------------------
The first few numbers of the Fibonacci sequence are:
`0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 ...` and so on.
Define two functions `fib-rec` and `fib-iter`
that return the number at the $i^{th}$ index.

**Acceptance criteria:**

1. All tests pass.
2. Parameter validation is performed.
3. `fib-rec` creates a linearly recursive process.
4. `fib-iter` creates a linearly iterative process.
5. Demonstrate the difference in execution time between iterative and recursive processes.
|#
#|
(define (fib-rec n)
  (cond
    [(negative? n) (error "N is negative")]
    [(< n 2) n]
    [else ( + (fib-rec(sub1 n)) (fib-rec(- n 2)))]
  )
)

(define (fib-iter n)
  (define(fib-iter-helper n a b)
    (if(zero? n)
       a
       (fib-iter-helper (sub1 n) b (+ a b))
     )

  )
  (if (negative? n)
    (error "N is negative")
    (fib-iter-helper n 0 1)
  )
)

(fib-iter 50)

(= (fib-rec 11) 89)
(= (fib-iter 11) 89)
|#

#|----------------------------------------
Define the following functions:

- `not-equal-one-line?`, `not-equal-guards?`: return whether two floating point numbers are different from each other;
- `inside?`: returns whether a whole number `x` is between two whole numbers - `start` and `finish`.

**Acceptance criteria:**

1. All tests pass.
2. `not-equal-one-line?` is defined on a single line.
3. `not-equal-one-line?` is defined **without** the use of `if-else`.
4. `not-equal-guards?` is defined using guards.
5. `inside?` is defined on a single line.
6. `inside?` is defined **without** the
          use of `if-else`.
|#
(define (not-equal-one-line? x y)
  (not (equal? x y))
)

(define (not-equal-guards? x y) #|guards znachi che ima cond|#
  (cond
    [(= x y) #f]
    [else #t]
  )
)
(define (inside? a b x) 
  ;(and (<= (min a b) x) (<= x (max a b)))
  (<= (min a b) x (max a b))
)


(equal? (not-equal-one-line? 5 2) #t)
(equal? (not-equal-one-line? 5 5) #f)

(equal? (not-equal-guards? 5 2) #t)
(equal? (not-equal-guards? 5 5) #f)

(equal? (inside? 1 5 4) #t) ; start = 1, finish = 5, x = 4
(equal? (inside? 5 1 4) #t)
(equal? (inside? 10 50 20) #t)
(equal? (inside? 10 50 1) #f)