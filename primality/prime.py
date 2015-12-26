#! /usr/bin/python

import math, random

def prime_det(num):	
	if num <= 1 or num%2 == 0:
		print "Composite"
		return False
	
	i = 3
	sq = int(math.sqrt(num))
	
	while i <= sq:
		if num%i == 0:
			print i, 'X', num/i, '=', num 
			print "Composite"
			return False
		i = i+2;
	
	print "Prime"
	return True

# non deterministic primality testing using the Miller-Rabin Algorithm:
# how it works:
# Backgound:
# Any positive odd integer n >= 3 can be expressed as: n-1 = (2^k)q where k > 0 and q is odd.
# Properties of prime numbers:
# 1. If p is prime and a is a positive integer less than p, then a^2 mod p = 1 if and only if either
# 	 a mod p = 1 or a mod p = -1 mod p = p-1.
# 2. Let p be a prime number greater than 2. We can write p-1 = (2^k)q where k > 0 and q is odd.
# 	 Let a be any integer such that 1 < a < p-1. Then one of the following conditions is true:
#	 i. a^q is congruent to 1 mod p.
# 	 ii. one of the numbers a^q, a^(2q), a^(4q) ... a ^(2^(k-1)q) is congruent to -1 modulo p. I.e., 
#	 there is some number j ( 1 <= j <= k) such that a^(2^(j-1))q = -1 modulo p = p-1.

# Referring to Knuth, D. "The Art of Computer Programming, Volume 2: Seminumerical Algorithms." Reading, MA: Addison Wesley, 1998
# Given an odd number n that is not prime, the probability that this algorithm will fail to detect that n is not prime
# is less than 1/4.

def prime_nondet(num, acc):
	(k, q, err, f) = (0, num-1, 1, False)
	while q%2 == 0:
		k = k+1
		q = q/2

	random.seed()
	while err > acc:
		a = random.randint(2, num-2)
		if pow(a, q, num) == 1:
			f = True
		for j in range(k):
			if pow(a, pow(2, j)*q, num) == num-1:
				f = True
				break
		if f:					#inconclusive
			err = err*1/4
		else:
			print "Composite"
			return False
	print "Prime"
	return True
		
		
	
