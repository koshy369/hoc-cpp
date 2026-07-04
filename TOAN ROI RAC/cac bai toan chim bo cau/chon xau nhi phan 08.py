print("Hello")
n,k=map(int,input().split())
tohop=1.0
tongthe=1

for i in range(n):
    tongthe*=2
for i in range(1,n+1):
    if (i>k): tohop*=i
for j in range(1,n-k+1):
    tohop/= j
print(tongthe-round(tohop)+1)
