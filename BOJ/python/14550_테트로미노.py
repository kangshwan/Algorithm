import sys
input = sys.stdin.readline
N, M = map(int, input().split())
board = []
for _ in range(N):
    board.append(list(map(int, input().split())))

tet_dict = {
    # 직선
    0: [[0,0,0,0],[0,1,2,3]],
    1: [[0,1,2,3],[0,0,0,0]],
    # 정사각
    2: [[0,0,1,1],[0,1,0,1]],
    # L type
    3:[[0,1,2,2],[0,0,0,1]],
    4:[[0,0,1,2],[0,1,0,0]],
    5:[[0,1,2,2],[0,0,0,-1]],
    6:[[0,0,1,2],[-1,0,0,0]],
    7:[[0,0,0,-1],[0,1,2,2]],
    8:[[0,0,0,1],[0,1,2,2]],
    9:[[0,1,1,1],[0,0,1,2]],
    10:[[0,1,0,0],[0,0,1,2]],
    # ㄱㄴ type
    11:[[0,0,1,1],[0,1,1,2]],
    12:[[0,1,1,2],[0,0,-1,-1]],
    13:[[0,0,-1,-1],[0,1,1,2]],
    14:[[0,1,1,2],[0,0,1,1]],
    # ㅗtype
    15:[[0,0,1,0],[0,1,1,2]],
    16:[[0,0,-1,0],[0,1,1,2]],
    17:[[0,1,1,2],[0,0,-1,0]],
    18:[[0,1,1,2],[0,0,1,0]]
}

def inRange(x, y):
    return 0 <= x < N and 0 <=  y < M

def isPossible(x, y, tet):
    dx, dy = tet_dict[tet]
    for i in range(4):
        if not inRange(x+dx[i], y+dy[i]):
            return False
    return True

def getSum(x, y, tet):
    dx, dy = tet_dict[tet]
    r_val = 0
    for i in range(4):
        if not inRange(x+dx[i], y+dy[i]):
            return -1
        r_val += board[x+dx[i]][y+dy[i]]
    return r_val
answer = -1
for x in range(N):
    for y in range(M):
        for t in range(19):
            answer = max(answer, getSum(x,y,t))
print(answer)

# 대충 30분 걸림