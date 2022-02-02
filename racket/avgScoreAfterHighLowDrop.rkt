#lang racket

(define (scores s1 s2 s3 s4 s5 s6 s7)
  (define maxVal(max s1 s2 s3 s4 s5 s6 s7))
  (define minVal(min s1 s2 s3 s4 s5 s6 s7))
  (define sumVals1(-(-(+ s1 s2 s3 s4 s5 s6 s7)minVal)maxVal))
  (define average (/ sumVals1 5))
  (print average))

(scores 7 6 3 8 7 10 9)

