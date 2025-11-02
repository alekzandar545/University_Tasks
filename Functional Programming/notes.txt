#lang racket

(define (check-empty xs)
  (zero? (apply + xs)))

(define (sum-predictions strategy all-data) ;all years (works on multiple lists)
  (define (sum-prediction strategy data) ;1 year
    ;------------------------------------
    (define (sum-line strategy xs)
      (define (helper leftover result)
        (if (< (length leftover) 2)
            result
            (helper (cdr leftover)(append result (list (- (second leftover) (car leftover)))))))
      (if (equal? strategy "backwards")
          (helper xs null)
          (map (λ (x) (* -1 x))(reverse (helper (reverse xs) null))) ;gotta flip the sign here
          ))
    ;-----------------------------------
    (define (calculate-up strategy xs leftover)
      (define (helper current leftover operation)
        (if (null? leftover)
            current
            (helper (operation (car leftover) current)(cdr leftover) operation)))
      (if (equal? strategy "backwards")
          (helper leftover xs -)
          (helper leftover xs +)
          ))
    ;-----------------------------------
    (define (helper results leftover)
      (cond
        [(check-empty leftover) (calculate-up strategy results 0)]
        [(= 1 (length leftover)) (calculate-up strategy results (car leftover))]
        [(equal? strategy "backwards") (helper (cons (car leftover) results) (sum-line "backwards" leftover)) ]
        [else (helper (cons (car (reverse leftover)) results) (sum-line "forwards" leftover))]))
    (helper null data))
  (cond
    [(not (or (equal? strategy "backwards") (equal? strategy "forwards"))) (error "Invalid strategy!")]
    [(null? all-data) 0]
    [else (+ (sum-prediction strategy (car all-data)) (sum-predictions strategy (cdr all-data)))]))

(= (sum-predictions "backwards" (list (list 10 13 16 21 30 45))) 5)
(= (sum-predictions "forwards" (list (list 7 9 12))) 16)
(= (sum-predictions "forwards" (list (list 10 13 16 21 30 45))) 68)
(= (sum-predictions "backwards" (list (list 7 9 12 16 21 27 34))) 6)
(= (sum-predictions "forwards" (list (list 7 9 12 16 21 27 34))) 42)
(= (sum-predictions "forwards" (list (list 7 9 12) (list 7 9 12 16) (list 7 9 12 16 21))) 64)
(= (sum-predictions "backwards" (list (list 21 30 45) (list 16 21 30 45) (list 13 16 21 30 45))) 41)
(= (sum-predictions "forwards" (list (list 0 3 6 9 12 15) (list 1 3 6 10 15 21) (list 10 13 16 21 30 45))) 114)
