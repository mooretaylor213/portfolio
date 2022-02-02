#lang racket

(define (listRemove atm a_list)
  (cond
    ((null? a_list)'())
    ((eq? atm (car a_list))
    (listRemove atm (cdr a_list)))
    (else (cons (car a_list)
                (listRemove atm (cdr a_list))))))

(listRemove '5 '(5 3 4 73 5 88 23))

