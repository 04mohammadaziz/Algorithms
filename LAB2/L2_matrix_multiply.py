import numpy as np
import time

N = 4

a = np.zeros((N,N))
b = np.zeros((N,N))
c = np.zeros((N,N))

def matrix_multiply():
    """Compute C = C + (A * B), where A, B, and C are n x n matrices."""

    for i in range(N):
        for j in range(N):
            for k in range(N):
                c[i, j] += a[i, k] * b[k, j]

matrix_multiply()
print(c)