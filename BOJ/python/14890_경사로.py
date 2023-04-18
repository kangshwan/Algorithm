import sys
input = sys.stdin.readline
N, L = map(int, input().split())
board = []
for _ in range(N):
    board.append(list(map(int, input().split())))

def inRange(x, y):
    return 0 <= x < N and 0 <= y < N

def checkPossibleRow(idx):
    cur_height = board[idx][0]
    cur_idx = 0
    placed = [False for _ in range(N)]

    for col in range(1, N):
        if board[idx][col] == cur_height:
            cur_idx = col
            continue

        if abs(cur_height - board[idx][col]) > 1:
            return False
        if cur_height > board[idx][col]:
            base_height = board[idx][col]
            for check_idx in range(col, col+L):
                if not inRange(idx, check_idx) or base_height != board[idx][check_idx] or placed[check_idx]:
                    return False
                placed[check_idx] = True
            cur_height = base_height
            cur_idx =  cur_idx + L

        if cur_height < board[idx][col]:
            base_height = cur_height
            for check_idx in range(cur_idx, cur_idx-L, -1):
                if not inRange(idx, check_idx) or base_height != board[idx][check_idx] or placed[check_idx]:
                    return False
                placed[check_idx] = True
            cur_height = board[idx][col]
            cur_idx = col
        
    return True
        

def checkPossibleCol(idx):
    cur_height = board[0][idx]
    cur_idx = 0
    placed = [False for _ in range(N)]

    for row in range(N):
        if board[row][idx] == cur_height:
            cur_idx = row
            continue
        
        if abs(cur_height - board[row][idx]) > 1:
            return False
        if cur_height > board[row][idx]:
            base_height = board[row][idx]
            for check_idx in range(row, row+L):
                if not inRange(check_idx, idx) or base_height != board[check_idx][idx] or placed[check_idx]:
                    return False
                placed[check_idx] = True
            cur_height = base_height
            cur_idx =  cur_idx + L
        if cur_height < board[row][idx]:
            base_height = cur_height
            for check_idx in range(cur_idx, cur_idx-L, -1):
                if not inRange(check_idx, idx) or base_height != board[check_idx][idx] or  placed[check_idx]:
                    return False
                placed[check_idx] = True
            cur_height = board[row][idx]
            cur_idx = row
    return True

answer = 0 
for idx in range(N):
    # check idx in row
    if checkPossibleRow(idx):
        answer += 1
    # check idx in column
    if checkPossibleCol(idx):
        answer += 1
print(answer)