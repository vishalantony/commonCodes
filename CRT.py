#chinese remainder theorem

# CRT is used to reconstruct integers in a certain range from a given set of residues modulo
# relatively prime numbers.

# example:
# Take some relatively prime numbers, say, 2,5,7,9
# Now, let the residues be 1,3,4,5
# i.e., for some number N, N = 1(mod 2) = 3(mod 5) = 4(mod 7) = 5(mod 9)
# then we can reconstruct the number N from these residues using the Chinese Remainder Theorem.

## Assertions: 
## 1. The mapping from N to the set of residues is one to one. N <-> (r1,r2,...) is a bijection.
## 2. Operations on N can be performed instead on the set of residues (r1,r2,...).

# Algorithm:
# input: 
# 1. set of pairwise coprime numbers : (n_1,n_2,n_3,...n_p) 
# 2. set of residues (N mod n_i) : (a_1, a_2, a_3,...a_p)
# Output:
# A number N in the range [0, M-1] where M = n_1 * n_2 * ... * n_p

# procedure:
# 1. Find M = n_1 * n_2 * ... * n_p.
# 2. For each n_i, find M_i where M_i = M/n_i.
# 3. For each M_i, find C_i where C_i = M_i * (M_i ^ -1 (mod n_i)). Use Extended Euclidean Algorithm to find modular inverse of M_i
#    modulo n_i.
# 4. Find N = (a_1*C_1 + a_2*C_2 + a_3*C_3 + ... + a_p*C_p) (mod M).

#############################################################

#Euclidean GCD function
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

# Extended Euclidean function to find bezout's coefficients
def extEuc(a, mod):
	if mod == 0:
		return (1, 0, a)
	(x, y, g) = extEuc(mod, a%mod)
	return (y, x - y*(a/mod), g)

# mmi(a, mod) returns the modular multiplicative inverse of a modulo mod ( if it exists)
def mmi(a, mod):
	(x, y, g) = extEuc(a, mod)
	if g == 1:
		if x < 0 :
			return x+mod
		return x
	else:
		print "Modular Multiplicative Inverse Doesn't exist";
		return (x, y, g)

###########################################################

coprime_list = []
residue_list = []

print "Enter list of pairwise coprime numbers (-1 to stop):"
while True:
	j = int(input())
	if j == -1:
		break
	i = 0
	while i < len(coprime_list):
		if gcd(coprime_list[i], j) != 1:
			print j, ' ', coprime_list[i], ' are not coprime', '\nTerminating.'
			exit(1)
		i = i+1
	coprime_list.append(j)

print "\nEnter the corresponding residues:"
for i in range(len(coprime_list)):
	j = int(input())
	if j >= coprime_list[i]:
		print "residue cannot be greater than mod value. \nTerminating."
		exit(1)
	residue_list.append(j)

M = 1
for i in coprime_list:
	M = M * i
M_ilist = []
for i in coprime_list:
	M_ilist.append(M/i)
i = 0
N = 0
while i < len(residue_list):
	inv = mmi(M_ilist[i], coprime_list[i])
	ci = M_ilist[i] * inv
	N = N + ci*residue_list[i]
	N = N % M
	i = i+1
print '\nAnswer: ', N
