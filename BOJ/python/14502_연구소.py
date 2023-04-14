import sys
from collections import deque
from copy import deepcopy

input = sys.stdin.readline
N, M = map(int, input().split())

virus_loc=[]
board = []
for i in range(N):
    row = list(map(int, input().split()))
    for j, val in enumerate(row):
        if val == 2:
            virus_loc.append((i,j))
    board.append(row)
board_size = N*M

def inRange(x, y):
    return 0 <= x < N and 0 <= y < M

dx = [0,1,0,-1]
dy = [1,0,-1,0]
def spread(w1, w2, w3):

    w1_x, w1_y = w1//M, w1%M
    w2_x, w2_y = w2//M, w2%M
    w3_x, w3_y = w3//M, w3%M

    q = deque(virus_loc)
    tmp_board = deepcopy(board)
    tmp_board[w1_x][w1_y] = 1
    tmp_board[w2_x][w2_y] = 1
    tmp_board[w3_x][w3_y] = 1
    
    while q:
        x, y = q.popleft()
        tmp_board[x][y] = 2
        for dir in range(4):
            nx, ny = x + dx[dir], y + dy[dir]
            if inRange(nx, ny) and tmp_board[nx][ny] == 0:
                q.append((nx,ny))
    count = 0
    for i in range(N):
        for j in range(M):
            if tmp_board[i][j] == 0:
                count+=1
    return count
answer = -1

for w1 in range(board_size):
    w1_x, w1_y = w1//M, w1%M
    if board[w1_x][w1_y] in [1, 2]:
        continue
    for w2 in range(w1+1, board_size):
        w2_x, w2_y = w2//M, w2%M
        if board[w2_x][w2_y] in [1, 2]:
            continue
        for w3 in range(w2+1, board_size):
            w3_x, w3_y = w3//M, w3%M
            if board[w3_x][w3_y] in [1, 2]:
                continue
            answer = max(answer, spread(w1,w2,w3))
print(answer)

'''
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
'''