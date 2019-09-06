# blum blum shub algorithm
# Xn+1 = (Xn ^ 2) Mod M, where M is a large prime number
import sympy
from time import time
import random
# super secret large number
x = 3 * 10 * 200
y = 4 * 10 * 200
seed = 5 * 10 ** 2
def next_usable_prime(x):
     # Find the next prime congruent to 3 mod 4 following x
    p = sympy.nextprime(x)
    while p % 4 != 3:
        p = sympy.nextprime(p)

    return p

def generate_random_M():
    p = next_usable_prime(x)
    q = next_usable_prime(y)
    M = p*q

    assert(1 < seed < M)
    assert(seed % p != 0)
    assert(seed % q != 0)
    return M


def blum_blum_shub(xn,M):
    return (xn ** 2) % M

if __name__ == "__main__":
    rn = []
    M = generate_random_M()
    n = int(input("How many numbers do you want? "))
    x = sympy.nextprime(random.randint(0,(int(time()))))
    for _ in range(n):
        x = blum_blum_shub(x,M)
        rn.append(x)

    max = max(rn)
    print("integers:", rn)
    norm = [a/max for a in rn]
    print("normalised:",norm)
