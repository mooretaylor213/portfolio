#lang racket
(define (volume radius height)
  (/(* pi radius radius height)1.0))

(volume 12.7 25.2)

