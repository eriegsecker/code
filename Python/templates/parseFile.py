import sys

filepath = sys.argv[1] if len(sys.argv)>1 else 'in.txt'

X = []
for line in open(filepath):
    
