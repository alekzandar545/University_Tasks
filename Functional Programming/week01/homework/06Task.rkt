#lang racket

#|Description:

A leap year is a calendar year that contains an additional day compared to a common year.
The 366th day is added to keep the calendar year synchronized with the astronomical year or seasonal year.

There are two mathematically equivalent methods for checking whether a year is a leap year.

Method I: A year is leap year if it is a multiple of 400 or it is a multiple of 4 but not of 100.

Method II:
    if year is divisible by 400 then is_leap_year
    else if year is divisible by 100 then not_leap_year
    else if year is divisible by 4 then is_leap_year
    else not_leap_year 
Define two predicates - leap-year-one-line? and leap-year-guards?, that check whether a year is a leap year.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Parameter validation is performed only in leap-year-guards?.
Parameter validation is not performed in leap-year-one-line?.
leap-year-one-line? implements Method I.
leap-year-one-line? uses boolean logical operators.
leap-year-one-line? does not return #t or #f explicitly.
leap-year-guards? uses guards.|#

(define (leap-year-one-line? x)
  (or (= (remainder x 400) 0) (and (= (remainder x 4) 0) (not (= (remainder x 100) 0)))))

(define (leap-year-guards? x)
  (cond
    [(< x 0) #f]
    [(= (remainder x 400) 0) #t]
    [(= (remainder x 100) 0) #f]
    [(= (remainder x 4) 0) #t]
    [else #f]))

(equal? (leap-year-one-line? 2020) #t)
(equal? (leap-year-one-line? 1988) #t)
(equal? (leap-year-one-line? 1600) #t)
(equal? (leap-year-one-line? 2400) #t)
(equal? (leap-year-one-line? 2023) #f)
(equal? (leap-year-one-line? 1700) #f)
(equal? (leap-year-one-line? 1800) #f)
(equal? (leap-year-one-line? 2100) #f)
(equal? (leap-year-one-line? 2024) #t) ;my test

(equal? (leap-year-guards? 2020) #t)
(equal? (leap-year-guards? 1988) #t)
(equal? (leap-year-guards? 1600) #t)
(equal? (leap-year-guards? 2400) #t)
(equal? (leap-year-guards? 2023) #f)
(equal? (leap-year-guards? 1700) #f)
(equal? (leap-year-guards? 1800) #f)
(equal? (leap-year-guards? 2100) #f)
(equal? (leap-year-guards? 2024) #t) ;my test