import sys

filepath = sys.argv[1] if len(sys.argv)>1 else 'in.txt'

def countBits(B, i):
    ones = 0
    zeroes = 0
    for b in B:
        if b == '1':
            ones += 1
        else:
            zeroes += 1
    return ones, zeroes




X = [line.strip() for line in open(filepath)]

gamma = ''
epsilon = ''
for i in range(len(X[0])):
    B = [x[i] for x in X]
    ones, zeroes = countBits(B, i)
    if ones > zeroes:
        gamma += '1'
        epsilon += '0'
    else:
        gamma += '0'
        epsilon += '1'

gamma = int(gamma, 2)
epsilon = int(epsilon, 2)
print(gamma*epsilon)


