def min_initial_oil(N:int, C:int, A: list):
    min_oil_required = 0
    curr_oil = 0
    print(A)
    for order in A:
        if order == -1: # Buy
            curr_oil -= 1
            if curr_oil < 0:
                min_oil_required += 1
                curr_oil = 0
        else:   # Sell
            curr_oil += 1
            if curr_oil > C:
                curr_oil = C
    
    return min_oil_required


N = 3
C = 2
A = [-1, -1, 1]

print(min_initial_oil(N, C, A))