#lang racket

(define (kth-number xs)
  (λ (p? k)
    (if(> k (length (filter p? xs)))
       (error "No such number!")
       (last (take (filter p? (sort  xs >)) k))
     )
    ))
(= 1 ((kth-number (list 1 2 3 4 -5 6)) odd? 2))
(= -5 ((kth-number (list 1 2 3 4 -5 6)) negative? 1))
(= -5 ((kth-number (list 1 2 3 4 -5 -5 6)) negative? 2))
(= -5 ((kth-number (list 1 -4 2 3 4 -5 -5 6)) negative? 3)) ;този тест мисля, че е сгрешен в условието
(= 1 ((kth-number (list -1 0 -1 0 -2)) negative? 4)) ; error

