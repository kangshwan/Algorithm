# 13:48 start
import sys
input = sys.stdin.readline


N, M, x, y, K = map(int, input().split())
board = []
for _ in range(N):
    board.append(list(map(int, input().split())))
order = list(map(int, input().split()))

#       top, right, front, left, rear, bottom
dice = [0 for _ in range(6)]

# roll  right, left, north,  south
dx = [0,0,0,-1,1]
dy = [0,1,-1,0,0]

def inRange(x,y):
    return 0 <= x < N and 0 <= y < M

def roll(dir):
    if dir == 1:
        # top -> right, right -> bottom, bottom -> left, left-> top
        dice[1], dice[5], dice[3], dice[0] = dice[0], dice[1], dice[5], dice[3]
    elif dir == 2:
        # top -> left, left -> bottom, bottom -> right, right -> top
        dice[3], dice[5], dice[1], dice[0] = dice[0], dice[3], dice[5], dice[1]
    elif dir == 3:
        # top -> front, front -> bottom, bottom -> rear, rear -> top
        dice[2], dice[5], dice[4], dice[0] = dice[0], dice[2], dice[5], dice[4]
    else:
        # top -> rear, rear -> bottom, bottom -> front, front -> top
        dice[4], dice[5], dice[2], dice[0] = dice[0], dice[4], dice[5], dice[2]

for dir in order:
    nx, ny = x + dx[dir], y + dy[dir]
    if inRange(nx, ny):
        roll(dir)
        if board[nx][ny] == 0:
            board[nx][ny] = dice[5]
        else:
            dice[5] = board[nx][ny]
            board[nx][ny] = 0
        print(dice[0])
        x, y = nx, ny
# 14:16 end

'''
3 3 0 0 16
0 1 2
3 4 5
6 7 8
4 4 1 1 3 3 2 2 4 4 1 1 3 3 2 2
'''
