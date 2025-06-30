
def calculate_query2_sum(A:list, queries:list[list]):
    N = len(A)
    if N == 0: 
        return 0
    sum = 0
    for q in queries:
        if q[0] == 1:
            l = q[1]
            r = q[2]
            # operation = (i - l + 1)* A[l]
            for i in range(l, r+1):
                A[i] = (i-l+1)*A[l]
            print(A)
        elif q[0] == 2:
            l = q[1]
            r = q[2]
            for i in range(l, r+1):
                sum += A[i]
    return sum%(10**9+7)


A = [1, 4, 5, 1, 6, 7, 8] 
queries = [[1, 1, 6], [1, 1, 5], [2, 5, 5], [2, 3, 4], [2, 3, 3]]
print(calculate_query2_sum(A, queries))
