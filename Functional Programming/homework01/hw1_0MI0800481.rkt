#lang racket

;TASK 01-------------------------------------------------

(define (sum-digits x)
  (if (zero? x)
      0
      (+ (remainder x 10) (sum-digits (quotient x 10)))))

(define (find-length x)
  (if (zero? x)
      0
      (+ 1 (find-length (quotient x 10)))))

(define (min-endurance-max-length  a b)
  (define (find-endurance x)
    (define (helper leftover counter)
      (let ([result (sum-digits leftover)])
        (if (<= (find-length result) 1)
            counter
            (helper result (add1 counter)))))
  (if (<= (find-length x) 1)
      0
      (helper x 1)))
  ;-----------------------------
  (define (helper start end min)
    (cond
      [(> start end) min]
      [(or
        (< (find-endurance start) (find-endurance min))
        (and (= (find-endurance start) (find-endurance min)) (> (find-length start) (find-length min))))
       (helper (add1 start) end start)]
      [else (helper (add1 start) end min)]
      ))
  (helper (min a b) (max a b) (min a b)))

(println  "Task 01 tests:")
(= (min-endurance-max-length 333 1000) 1000)
(= (min-endurance-max-length 333 2000)  1000)
(= (min-endurance-max-length 356 460) 360)
(= (min-endurance-max-length 498 701)  500)
(= (min-endurance-max-length 583 889)  600)
(= (min-endurance-max-length 34 621)  100)
(= (min-endurance-max-length 234 651)  234)

;TASK 02-------------------------------------------

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

(println  "Task 02 tests:")
(= (sum-predictions "backwards" (list (list 10 13 16 21 30 45))) 5)
(= (sum-predictions "forwards" (list (list 7 9 12))) 16)
(= (sum-predictions "forwards" (list (list 10 13 16 21 30 45))) 68)
(= (sum-predictions "backwards" (list (list 7 9 12 16 21 27 34))) 6)
(= (sum-predictions "forwards" (list (list 7 9 12 16 21 27 34))) 42)
(= (sum-predictions "forwards" (list (list 7 9 12) (list 7 9 12 16) (list 7 9 12 16 21))) 64)
(= (sum-predictions "backwards" (list (list 21 30 45) (list 16 21 30 45) (list 13 16 21 30 45))) 41)
(= (sum-predictions "forwards" (list (list 0 3 6 9 12 15) (list 1 3 6 10 15 21) (list 10 13 16 21 30 45))) 114)
