if __name__ == "__main__":
    
    N, M = map(int, input().split())

    max_profit = 0
    left = 0
    right = 0

    hotels = list(map(int, input().split()))  

    curr = 0

    while left < N:
        if (right < N  and  curr + hotels[right] <= M):
            curr += hotels[right]
            right += 1

            if (curr > max_profit):
                max_profit = curr

        else:
            curr -= hotels[left]
            left += 1


    print(max_profit)

