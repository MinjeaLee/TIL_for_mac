# 1) generate_superinc_knapsack(n): it takes a parameter n and returns a list of super-increasing knapsack elements a = [a_1, a_2, ..., a_n] and a modulus m such that m > 2 * a_n.
def generate_superinc_knapsack(n):
    a = []
    m = 1
    for i in range(n):
        a.append(m)
        m = m * 2
    return a, m + 1

# 2) knapsack_genkey(n): it takes a parameter n and returns a private key sk and a public key pk. Note that it runs generate_superinc_knapsack algorithm.
def knapsack_genkey(n):
    sk, m = generate_superinc_knapsack(n)
    
    pk = [(sk[i] * 31) % m for i in range(n)]

    pk.append(m)

    sk = pow(31, -1, m), m

    return sk, pk
    
# 3) knapsack_encrypt(p, pk): it takes an integer message p and a public key pk and outputs an  integer ciphertext c. Note that p should be converted into a binary value in the encryption process.
def knapsack_encrypt(p, pk):
    p = bin(p)[2:]
    padding = '0' * ((len(pk)-1) - len(p))
    p = padding + p

    c = 0
    for i in range(len(p)):
        c += int(p[i]) * pk[i]
    c = c % pk[-1]
    return c

# 4) knapsack_decrypt(c, sk): it takes an integer ciphertext c and a private key sk, and outputs a integer message p.
def knapsack_decrypt(c, sk):
    n = c * sk[0] % sk[1]

    p = bin(n)[2:]
    p = "0b" + str(p[::-1])
    p = int(p, 2)
    return p

n = int(input("Enter the number of elements in the knapsack: "))
sk, pk = knapsack_genkey(n)
print("sk = {}".format(sk))
print("pk = {}".format(pk))
p = int(input("Enter the message to be encrypted: "))
print("p = {}".format(p))
c = knapsack_encrypt(p, pk)
print("c = {}".format(c))
p = knapsack_decrypt(c, sk)
print("p = {}".format(p))
