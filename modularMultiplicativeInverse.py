# Extended Euclidean algorithm in python.

# call mmi(a, m) to find the Modular multiplicative inverse of a (mod m).
# **Always the larger number is considered to be m.**

# call extEuc(a, b) to find the GCD g of a & b along with the 
# Bézout's coefficients, i.e., x and y of: ax+by = g

# extEuc returns a list (x, y, g) where x, y & g are what is specified above.

# if the multiplicative inverse doesn't exist, i.e., when gcd(a, m) is not 1, 
# then mmi(a, m) prints an error message and returns the list instead.
# else, it returns the multiplicative inverse.

# complexity of Euclidean algorithm is approximately O(lg(a)) where lg is 
# logarithm to the base of Golden Ratio (1+sqrt(5))/2.

def extEuc(a, mod):
	if mod == 0:
		return (1, 0, a)
	(x, y, g) = extEuc(mod, a%mod)
	return (y, x - y*(a/mod), g)

def mmi(a, mod):
	(a, mod) = (min(a,mod), max(a,mod))
	(x, y, g) = extEuc(a, mod)
	if g == 1:
		if x >= 0:
			return x
		else:
			return mod+x
	else:
		print "Modular Multiplicative Inverse Doesn't exist";
		return (x, y, g)

