#lang racket

#|Description:

Each day a plant is growing by up-speed meters. Each night that plant's height decreases by down-speed
meters due to the lack of sunlight. Initially, plant is 0 meters tall. We plant the seed at the beginning
of a day. We want to know when the height of the plant will reach a certain level.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
The parameters are named in accordance with the names given in the fourth test case.|#


(define (growing-plant up-speed down-speed desired-height)
   (define (helper days current-height)
     (if (>= (+ current-height up-speed) desired-height)
         days
         (helper (add1 days) (+ current-height (- up-speed down-speed)))
    ))
  (if (< up-speed down-speed)
      0
      (helper 1 0)))
      


(= (growing-plant 5 2 5) 1)
(= (growing-plant 5 2 6) 2)
(= (growing-plant 10 9 4) 1)
(= (growing-plant 100 10 910) 10) ; up-speed=100, down-speed=10, desired-height=910
(= (growing-plant 40 5 100) 3) ;my test
