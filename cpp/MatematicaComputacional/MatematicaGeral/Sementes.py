F, R = map(int, input().split() )
gota = map(int, input().split() )
gota = list(gota)
dias = 0

for i in range (len(gota) ):
    if(i == 0):
        dias = max(gota[i] - 1, F - gota[R - 1])
    else:
        dias = max(dias, int( (gota[i] - gota[i - 1]) / 2) )

print(dias)
