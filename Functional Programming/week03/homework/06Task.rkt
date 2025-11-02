#lang racket

#|Description:

Define a higher order procedure repeater str that accepts a string and returns a
linearly recursive procedure of two arguments - count (number) and glue (string).
The result from a call to the result of repeater should be a string that is str
repeated count times with glue being put between every two str instances.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.|#

(define (repeater str)
  (λ (count glue)
  (if (= 1 count)
       str
       (string-append str glue ((repeater str)(sub1 count) glue)))
   )
  )
 
(equal? ((repeater "I love Racket") 3 " ") "I love Racket I love Racket I love Racket")
(equal? ((repeater "Quack") 5 "!") "Quack!Quack!Quack!Quack!Quack")
(equal? ((repeater "hello") 2 ":)") "hello:)hello") ;my test