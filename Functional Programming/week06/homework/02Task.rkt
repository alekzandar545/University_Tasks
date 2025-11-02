#lang racket

#|Description:

The depth of an atom x in a list xs is the number of times car
must be applied to xs in order to reach x. Define a procedure
that removes all atoms that are smaller than their depth.

Acceptance criteria:

All tests pass.|#

(require racket/trace)

(define (contains-list? xs)
    (and (not (null? xs)) (or (list? (car xs)) (contains-list? (cdr xs)))))


; null? xss => null
; (list? (car xss => (append (helper (car xss) (add1)) (helper (cdr leftover count)))
; >=

(define (deep-delete xss)
  (define (helper leftover count)
    (cond
      [(null? leftover) null]
      [(list? (car leftover)) (append (list (helper (car leftover) (add1 count))) (helper (cdr leftover) count))]
      [(>= (car leftover) count) (cons (car leftover) (helper (cdr leftover) count))]
      [else (helper (cdr leftover) count)]
      ))
  (helper xss 1)
  )

(define (deep-delete1 xs)
  (define (helper result leftover count)
    (cond
      [(null? leftover) result]
      [(and (list? (car leftover)) (contains-list? (car leftover)))
       (helper (append result (list (car leftover))) (cdr leftover) (add1 count))]
      [(list? (car leftover))
       (helper (append result (list (car leftover))) (cdr leftover) (add1 count)) ]
      [else (helper (append result (map (λ (x)
                                          (if(>= x count)
                                             x
                                             null)) (list (car leftover)))) (cdr leftover) (add1 count))]))
  (trace helper)
  (helper null xs 1))

; can reach "1" by applying "car" one time and "2" can be reached with "caadr".
(deep-delete '(1 (2 (2 4) 1) 0 (3 (1))))
(equal? (deep-delete '(1 (2 (2 4) 1) 0 (3 (1)))) '(1 (2 (4)) (3 ())))
(equal? (deep-delete '(3 ((1)) 1 ((((3)) 2) 42) 3 (6) 1 0 (3 1 (((9))) 0))) '(3 (()) 1 (((())) 42) 3 (6) 1 (3 (((9))))))