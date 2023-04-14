import sys
input = sys.stdin.readline
N = int(input())
T = []
P = []
for _ in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)
dp = [0 for _ in range(30)]
for day in range(N):
    dp[day + T[day]] = max(dp[day + T[day]], dp[day] + P[day])
    dp[day+1] = max(dp[day], dp[day+1])
print(dp[N])