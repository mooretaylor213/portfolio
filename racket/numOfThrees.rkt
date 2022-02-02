#lang racket

(define (member atm a_list count)
  (cond
    ((null? a_list) count)
    ((eq? atm (car a_list))
    (member atm (cdr a_list) (+ 1 count)))
    (else (member atm (cdr a_list) count))))

(member '3 '(7 3 87 3 -8 44 3) 0)

