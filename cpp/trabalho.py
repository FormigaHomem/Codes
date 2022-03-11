#Exponentiation
def myPow(base, power):
    result = base
    power -= 1
    while(power > 0):
        result *= base
        power -= 1
    return result

#Future Value
def FV(VP, n, i):
    Vf = [0] * n
    
    #finding future values
    for k in range(n):
        Vf[k] = VP * myPow(1 + i, n - k)
        print(f"Vf {k} = {VP} * (1 + {i}) {n} - {k} -> Vf {k} = {VP} * ({1 + i}) {n - k} -> Vf {k} ~~ {VP} * {myPow(1 + i, n - k)} -> Vf {k} = {VP * myPow(1 + i, n - k)} \n\n")

    print("VF =", end=" ")
    for k in range(n):
        print(f"Vf {k} +", end=" ")

    print("\n\nVF =", end=" ") 
    print(*Vf, sep=" + ")

    print(f"\n\nVF = {sum(Vf)}")
    #finding future value by summing future values
    VF = round(sum(Vf), 2)
    print(f"VF equals to {VF}")

#Present Value
def PV(P, n, i):
    Vp = [0] * (n + 1); Vf = list(map(int, input().split() ) )
    
    #finding present values
    for k in range(1, n + 1, 1):
        Vp[k] = Vf[k] / myPow(1 + i, k)
        print(f"Vp {k} = Vf {k} / (1 + {i}) {k} -> Vp {k} = Vf {k} / ({1 + i}) {k} -> Vp {k} ~~ {Vf[k]} / {myPow(1 + i, k)} -> Vp {k} = {Vf[k] / myPow(1 + i, k)} \n\n")

    print("VP =", end=" ")
    for k in range(1, n + 1, 1):
        print(f"Vp {k} +", end=" ")

    print("\n\nVP =", end=" ") 
    print(*Vp, sep=" + ")

    print(f"\n\nVP = {sum(Vp)}")
    #finding present value by summing present values
    VP = round(sum(Vp), 2)
    print(f"VP equals to {VP}")

#Future Value Installment
def FVI(VF, n, i):
    P = (VF * i) / (myPow(1 + i, n + 1) - (1 + i) )
    print(round(P, 2), P)

#Present Value Installment
def PVI(VP, n, i):
    P = (VP * myPow(1 + i, n) * i) / (myPow(1 + i, n) - 1)
    print(round(P, 2), P)

#Future Value from Installment
def FVfI(P, n, i):
    VF = (P * (myPow(1 + i, n + 1) - (1 + i) ) ) / i
    print(round(VF, 2), VF)

#Present Value from Installment
def PVfI(P, n, i):
    VP = (P * (myPow(1 + i, n) - 1) ) / (myPow(1 + i, n) * i)
    print(round(VP, 2), VP)

Type = input(); Value = float(input() ); n = int(input() ); i = float(input() ) 

if Type == "Future Value": 
    FV(Value, n, i)

elif Type == "Present Value":
    PV(Value, n, i)

elif Type == "Future Value Installment":
    FVI(Value, n, i)
    
elif Type == "Present Value Installment":
    PVI(Value, n, i)
    
elif Type == "Future Value from Installment":
    FVfI(Value, n, i)
    
elif Type == "Present Value from Installment":
    PVfI(Value, n, i)    