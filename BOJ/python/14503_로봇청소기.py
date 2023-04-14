import sys
input = sys.stdin.readline

N, M = map(int, input().split())
r,c,d = map(int, input().split())
room = []
for _ in range(N):
    room.append(list(map(int, input().split())))

# 0 N, 1 E, 2 S, 3 W
dx = [-1,0,1,0]
dy = [0,1,0,-1]

def checkClean(x, y):
    for dir in range(4):
        nx, ny = x + dx[dir], y + dy[dir]
        # nx, ny가 범위를 벗어나지 않고 청소가 안된 경우
        if room[nx][ny] == 0:
            return False
    return True

answer = 0

while True:
    if room[r][c] == 0:
        room[r][c] = 2
        answer += 1

    if checkClean(r, c):
        go_back = (d+2)%4
        nr, nc = r + dx[go_back], c + dy[go_back]
        if room[nr][nc] != 1:
            r, c = nr, nc
            continue
        print(answer)
        break
    else:
        d = (d+3)%4
        nr, nc = r + dx[d], c + dy[d]
        if room[nr][nc] == 0:
            r, c = nr, nc