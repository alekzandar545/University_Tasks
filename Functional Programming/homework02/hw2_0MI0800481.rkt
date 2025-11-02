#lang racket

(define (cell-connections cell)
  (cond
    [(equal? cell "|") '((-1 . 0) (1 . 0))]
    [(equal? cell "-") '((0 . -1) (0 . 1))]
    [(equal? cell "L") '((-1 . 0) (0 . 1))]
    [(equal? cell "J") '((-1 . 0) (0 . -1))]
    [(equal? cell "7") '((0 . -1) (1 . 0))]
    [(equal? cell "F") '((1 . 0) (0 . 1))]
    [(equal? cell "S") '((0 . -1) (0 . 1) (-1 . 0) (1 . 0))]
    [else '()]))

(define (find-start xss)
  (define (find-row leftover num)
    (cond
      [(null? leftover) (error "element not in matrix")]
      [(member "S" (car leftover)) num]
      [else (find-row (cdr leftover) (add1 num))]))
   ;----------------------------
   (define (find-col leftover num)
     (cond
       [(null? leftover) (error "element not in matrix")]
       [(equal? "S" (car leftover)) num]
       [else (find-col (cdr leftover) (add1 num))]))
  (cons (find-row xss 0) (find-col (list-ref xss (find-row xss 0))0))
)

(define (find-next prev-coords from-coords matrix)
  (car (filter (λ (x) (not(equal? x prev-coords))) (find-neighbours from-coords matrix)))) ;here we limit ourselves going only 1 way

(define (find-neighbours coords matrix) ;show all options
  (filter (λ (y) (valid-position? (car y) (cdr y) (length matrix)  (length (car matrix))))
          (map (λ (x) (cons (+ (car coords)(car x)) (+ (cdr coords)(cdr x))))(cell-connections (get-value coords matrix))))
)

(define (get-value coords matrix)
  (list-ref (list-ref matrix (car coords)) (cdr coords)))

(define (valid-position? x y rows cols)
  (and (>= x 0) (< x rows) (>= y 0) (< y cols)))


;to find a cycle means find nondot element and just cruise next-next-next then length

(define (find-start-way matrix)
  (car(filter (λ (x) (not(equal? (get-value x matrix) "."))) (find-neighbours (find-start matrix) matrix))))

(define (num-steps-farthest-away matrix)
  (define (helper prev curr num)
    (cond
      [(equal? (get-value (find-next prev curr matrix) matrix) "S") (/(add1 num) 2)]
      [else (helper curr (find-next prev curr matrix) (add1 num))]))
  (helper (find-start matrix) (find-start-way matrix) 1));making 1 step with find-start-way thats why num is 1 initially

;could use some composition to remove the need to have matrix as a parameter everywhere but its 23:51PM

(=(num-steps-farthest-away '(("7" "-" "F" "7" "-")
                           ("." "F" "J" "|" "7")
                           ("S" "J" "L" "L" "7")
                           ("|" "F" "-" "-" "J")
                           ("L" "J" "." "L" "J"))) 8)
(=(num-steps-farthest-away '(("-" "." "|" "F" "7")
                           ("." "S" "-" "7" "|")
                           ("L" "|" "7" "|" "|")
                           ("-" "L" "-" "J" "|")
                           ("L" "|" "-" "J" "F"))) 4)
(=(num-steps-farthest-away '(("F" "-" "-" "7")
                           ("|" "F" "-" "7")
                           ("." "S" "." "|")
                           ("|" "L" "-" "J")
                           ("L" "-" "-" "J")))4)
              
                
