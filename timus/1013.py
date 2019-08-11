def matmulmod(a, b, mod):
    n = len(a)
    m = len(a[0])
    p = len(b[0])

    c = [[0 for i in range(p)] for j in range(n)]
    for i in range(n):
        for j in range(m):
            for k in range(p):
                c[i][k] = (c[i][k] + a[i][j] * b[j][k]) % mod
    return c

def matpowmod(a, n, mod):
    res = [[1, 0], [0, 1]]
    while n > 0:
        if n % 2 == 1:
            res = matmulmod(res, a, mod)
        a = matmulmod(a, a, mod)
        n = n // 2
    return res

def fast(n, k, mod):
    M = [[k, 1], [-1, -1]]
    a = [[k - 1, 0]]
    return matmulmod(a, matpowmod(M, n - 1, mod), mod)[0][0]

def main():
    n = int(input())
    k = int(input())
    mod = int(input())

    print(fast(n, k, mod))

if __name__ == '__main__':
    main()

"""
C is const = k

(a, b) * M = (a * C - b, a - b)

M is 2x2 =>
    w | x
    -----
    y | z

(a, b) * M = (w * a + y * b,    x * a + z * b)
           = (C * a + (-1) * b, 1 * a + (-1) * b)

M =  C | 1
    -1 | -1
"""
