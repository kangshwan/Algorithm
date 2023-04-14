import sys
input = sys.stdin.readline
N = int(input())
v_table = []
for _ in range(N):
    v_table.append(list(map(int, input().split())))

visited=[False for _ in range(N)]

answer = 1001
def makeTeam(s_num, idx):
    global answer
    if s_num == N//2:
        s_val = 0
        l_val = 0
        for i in range(N):
            for j in range(i+1, N):
                if visited[i] and visited[j]:
                    s_val += v_table[i][j] + v_table[j][i]
                if not visited[i] and not visited[j]:
                    l_val += v_table[i][j] + v_table[j][i]
        answer = min(answer, abs(s_val - l_val))

    # backTracking에서 반복 횟수를 줄일 방법을 잊지말자.
    # visited를 애용하자. 애용!
    for i in range(idx, N):
        if not visited[i]:
            visited[i] = True
            makeTeam(s_num+1, i)
            visited[i] = False
makeTeam(0,0)
print(answer)