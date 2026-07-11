//catalan
C0 = C1 = 1
Cn = sumof(k = 0 to n - 1) CkCn-1-k, n >=2
Cn = 2nCn - 2nCn-1 = (1 / n + 1) * 2nCn, n >= 0
//dearrangement
D(0) = D(1) = 0
D(n) = (n - 1) * { D(n - 1) + D(n - 2) }, n >= 2
