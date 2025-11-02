#lang racket


#|Description:

The greatest common divisor (GCD) of two or more numbers is the greatest common factor that divides them, exactly.
 For example, the greatest common factor of 15 and 10 is 5, since both the numbers can be divided by 5
 and there is no number larger than 5 that divides 15 and 10, thus GCD(15, 10) = 5.

One way to find the greatest common divisor between two numbers - x and y is by using The Euclidean Algorithm.

The Euclidean Algorithm for finding GCD(x,y) is as follows:
If x = 0 then GCD(x,y)=y.
If y = 0 then GCD(x,y)=x.
Write x in quotient remainder form (x = A⋅y + R). Find GCD(y,R) (since GCD(x,y)=GCD(y,R)).
Define a procedure for calculating the GCD of two whole numbers.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Normally, you would use the built-in function gcd. This is the only time when you should not use it.
Guards are used for the implementation.|#

(define (my-gcd x y)
  (cond
    [(zero? x) y]
    [(zero? y) x]
    [else (my-gcd (remainder (max x y) (min x y))(min x y))]))

(= (my-gcd 5 13) 1)
(= (my-gcd 13 1235) 13)
(= (my-gcd 20 12) 4) ;my test