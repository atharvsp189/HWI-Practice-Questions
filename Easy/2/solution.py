from collections import defaultdict

def max_good_subarray_sum(A:list, k:int):
    n = len(A)
    if n == 0:
        return 0
    
    left = 0
    curr_Sum = 0
    max_sum = 0
    freq = defaultdict(int)
    
    for right in range(n):
        freq[A[right]] += 1
        curr_Sum += A[right]

        while len(freq) > k:
            freq[A[left]] -= 1
            curr_Sum -= A[left]

            if freq[A[left]] == 0:
                del freq[A[left]]
            left += 1
        max_sum = max(max_sum, curr_Sum)

    return max_sum

A = [1, 2, 2, 3, 2, 3, 5, 1, 2, 1, 1]
k = 2
print(max_good_subarray_sum(A, k)) # output: 12