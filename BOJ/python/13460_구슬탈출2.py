from collections import deque

N, M = map(int, input().split())
board=[]
r_marvel = (0, 0)
b_marvel = (0, 0)
hole = (0, 0)
for i in range(N):
    l = input()
    if 'R' in l:
        r_marvel = (i, l.index('R'))
    if 'B' in l:
        b_marvel = (i, l.index('B'))
    if 'O' in l:
        hole = (i, l.index('O'))
    board.append(l)

dx = [1,-1,0,0]
dy = [0,0,-1,1]

# 기울이는 방향에 나란하게 존재하는지 확인
def isFirst(r_m, b_m, dir):
    rx, ry = r_m
    bx, by = b_m
    while board[rx][ry] != '#':
        if rx + dx[dir] == bx and ry + dy[dir] == by:
            return False
        rx += dx[dir]
        ry += dy[dir]
    return True

# 기울인 방향으로 구슬 옮김
def tilt(marvel, opponent, dir):
    x, y = marvel
    ox, oy = marvel
    if opponent:
        ox, oy = opponent
    
    nx, ny = x + dx[dir], y + dy[dir]
    while board[nx][ny] not in ['#'] :
        if nx == ox and ny == oy:
            break
        if board[nx][ny] == 'O':
            return None, True, True
        
        x, y = nx, ny
        nx, ny = x + dx[dir], y + dy[dir]

    return (x, y), False, marvel[0] == x and marvel[1] == y

def escape(r_m, b_m, count):
    q = deque()
    q.append((r_m, b_m, count))

    while q:
        r, b, c = q.popleft()
        if c > 10:
            continue
        for dir in range(4):
            if isFirst(r,b,dir):
                n_r, r_e, r_g = tilt(r, b, dir)
                n_b, b_e, b_g = tilt(b, n_r, dir)
            else:
                n_b, b_e, b_g = tilt(b, r, dir)
                n_r, r_e, r_g = tilt(r, n_b, dir)

            if b_e:
                continue
            if r_e:
                return c
            if r_g and b_g:
                continue
            q.append((n_r,n_b,c+1))

    return -1

print(escape(r_marvel, b_marvel, 1))