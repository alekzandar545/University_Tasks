#lang racket

#|Description:

Define two functions - sum-cubes-pow and sum-cubes-no-pow, that return the sum of the cubes of two whole numbers.

Acceptance criteria:

Add one new test case for each of the functions. Place a comment after it with the words my test.
All tests pass.
sum-cubes-pow is defined using the built-in power procedure.
sum-cubes-no-pow is defined without using the built-in power procedure.|#

(define (sum-cubes-pow x y)
   (+ (expt x 3) (expt y 3)))
  
(define (sum-cubes-no-pow x y)
  (+ (* x x x) (* y y y)))



(= (sum-cubes-pow 5 1) 126)
(= (sum-cubes-pow 10 50) 126000)
(= (sum-cubes-pow 2 4) 72) ;my test

(= (sum-cubes-no-pow 5 1) 126)
(= (sum-cubes-no-pow 10 50) 126000)
(= (sum-cubes-no-pow 2 4) 72) ;my test