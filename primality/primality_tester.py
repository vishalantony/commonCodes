#! /usr/bin/python

import sys, os, math, prime

#expecting number and accuracy(optional)
if len(sys.argv) == 1:
	print "Usage: <program name> <number> [<accuracy>]"
	sys.exit(1)


num = long(sys.argv[1]) 	# number to test for primality
acc = float(0.001)			# accuracy
method = "deterministic"	# deterministic method will ignore accuracy. For numbers less than or equal to 1000000000000

if num < 0:
	print "Error: number has to be a positive integer"
	sys.exit(1)

if len(sys.argv) > 2:
	acc = float(sys.argv[2])

if num > 10**20:	
	method = 'non-deterministic';

if method == 'deterministic':
	sys.exit(prime.prime_det(num))

sys.exit(prime.prime_nondet(num, acc))
