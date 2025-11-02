#lang racket

(require racket/trace)

(define (n-to-list n)
  (define (helper result leftover)
    (if (zero? leftover)
        (reverse result)
        (helper (append result (list (remainder leftover 10))) (quotient leftover 10))))
  (helper null n))

(define (fib n)
  (define (helper a b count)
    (if (= count n)
      b
      (helper b (+ a b) (add1 count))))
  (helper 1 0 0))

(define (split num k) ;splits the number into segments of length k
  (define (helper leftover result)
    (cond
      [(null? leftover) result]
      [(>= (length leftover) k) (helper (drop leftover k) (append result (list (take leftover k))))]
      [else (append result (list (take leftover (length leftover))))]))
  (helper (n-to-list num) null))



(define (around-fib num)
  (define (find-max-pair xs)
  (define (helper leftover currCount currNum  maxCount maxNum)
    (cond
      [(null? leftover) (cons maxNum maxCount)]
      [(and (> (car leftover) currNum)
            (> currCount maxCount))
       (helper (cdr leftover) 1 (car leftover) currCount currNum)]
      [(and (> (car leftover) currNum)) (helper (cdr leftover) 1 (car leftover) maxCount maxNum)]
      [else (helper (cdr leftover) (add1 currCount) currNum maxCount maxNum)]))
  (helper (sort xs <) 0 (car (sort xs <)) 0 (car (sort xs <))))
  ;---------------------------------------------------------------
  (λ (x)
    (define (helper leftover result)
      (if (null? leftover)
          result
          (helper (cdr leftover) (append result (list (find-max-pair (car leftover)))))))
    (helper (split (fib num) x) null)))

(equal? ((around-fib 100) 25) '((1 . 3)))
(equal? ((around-fib 180) 25) '((1 . 5) (7 . 3)))
;this 2 long for me to copy lol (equal? ((around-fib 1700) 25) '((1 . 3) (2 . 5) (0 . 6)........))
(equal? ((around-fib 500) 42) '((0 . 6) (2 . 7) (2 . 6)))
(equal? ((around-fib 6000) 242) '((5 . 31) (8 . 33) (8 . 31) (7 . 35) (7 . 31) (4 . 7)))