# BFS를 사용할 것이므로, queue import
from queue import Queue

def solution(board):
    # dx,dy technique 사용을 위한 선언
    dx=[0,1,0,-1]
    dy=[1,0,-1,0]
    
    N = len(board)
    
    # 로봇이 가로 방향일 때와, 세로 방향일 때 두 가지에 대해서 visited 배열 채워넣기 <<= 이게 핵심 같다!
    visited = [[[False for _ in range(N)] for _ in range(N)] for _ in range(2)]
    
    def inRange(x, y):
        return 0 <= x < len(board) and 0 <= y < len(board)

    def canMove(x1, y1, x2, y2):
        '''
            x1, y1, x2, y2가 범위 안에 존재하고, 두 위치 모두 방문하지 않았고, board상에서 0인 경우
        '''
        # 각 로봇이 수직인지 수평인지 확인하여 visited 판별
        if x1 == x2:
            return inRange(x1, y1) and inRange(x2, y2) and not (visited[0][x1][y1] and visited[0][x2][y2]) \
                and not (board[x1][y1] or board[x2][y2])
        else:
            return inRange(x1, y1) and inRange(x2, y2) and not (visited[1][x1][y1] and visited[1][x2][y2]) \
                and not (board[x1][y1] or board[x2][y2])
        
    def canRotate(x1, y1, x2, y2, point, rot):
        '''
            Rotate 하는 함수
            x1, y1, x2, y2 : 현재 로봇의 위치
            rot : 회전방향 (0: 상, 좌 1: 하, 우)
            point : 중심점 위치 (0: x1, y1, 1: x2, y2)
            
            return:
                Rotate가 가능하면 Rotate 한 이후 좌표를 반환
                그렇지 않다면 None 반환
        '''
        # 로봇이 수평인 경우
        if x1 == x2:
            # 중심점이 (x1, y1)
            if point == 0:
                # 위로 회전
                if rot == 0:
                    tmp_x, tmp_y = x1-1, y2
                    nx1, ny1, nx2, ny2 = x1, y1, x1-1, y1
                    if inRange(nx2, ny2) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
                # 아래로 회전
                else:
                    tmp_x, tmp_y = x1+1, y2
                    nx1, ny1, nx2, ny2 = x1, y1, x1+1, y1
                    if inRange(nx2, ny2) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
            # 중심점이 (x2, y2)
            else:
                # 위로 회전
                if rot == 0:
                    tmp_x, tmp_y = x2-1, y1
                    nx1, ny1, nx2, ny2 = x2-1, y2, x2, y2
                    if inRange(nx1, ny1) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
                # 아래로 회전
                else:
                    tmp_x, tmp_y = x2+1, y1
                    nx1, ny1, nx2, ny2 = x2+1, y2, x2, y2
                    if inRange(nx1, ny1) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
        # 로봇이 수직인 경우
        else:
            # 중심점이 (x1, y1)
            if point == 0:
                # 좌로 회전
                if rot == 0:
                    tmp_x, tmp_y = x2, y1-1
                    nx1, ny1, nx2, ny2 = x1, y1, x1, y1-1
                    if inRange(nx2, ny2) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
                # 우로 회전
                else:
                    tmp_x, tmp_y = x2, y1+1
                    nx1, ny1, nx2, ny2 = x1, y1, x1, y1+1
                    if inRange(nx2, ny2) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
            # 중심점이 (x2, y2)
            else:
                # 좌로 회전
                if rot == 0:
                    tmp_x, tmp_y = x1, y2-1
                    nx1, ny1, nx2, ny2 = x2, y2-1, x2, y2
                    if inRange(nx1, ny1) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
                # 우로 회전
                else:
                    tmp_x, tmp_y = x1, y2+1
                    nx1, ny1, nx2, ny2 = x2, y2+1, x2, y2
                    if inRange(nx1, ny1) and not board[tmp_x][tmp_y]:
                        return nx1, ny1, nx2, ny2
        return None, None, None, None
                    
    que = Queue()
    visited[0][0][0] = visited[0][0][1] = True
    que.put( (0, 0, 0, 1, 0) )
    while not que.empty():
        x1, y1, x2, y2, cnt = que.get()
        print(x1, y1, x2, y2, cnt)
        if x1 == y1 == N-1 or x2 == y2 == N-1:
            return cnt
        
        # move first
        for p_dir in range(4):
            nx1, ny1, nx2, ny2 = x1+dx[p_dir], y1+dy[p_dir], x2+dx[p_dir], y2+dy[p_dir]
            if canMove(nx1, ny1, nx2, ny2):
                if nx1 == nx2:
                    visited[0][nx1][ny1] = visited[0][nx2][ny2] = True
                else:
                    visited[1][nx1][ny1] = visited[1][nx2][ny2] = True
                que.put((nx1, ny1, nx2, ny2, cnt+1))
            
        # rotate next
        for point in range(2):
            for rot in range(2):
                nx1, ny1, nx2, ny2 = canRotate(x1, y1, x2, y2, point, rot)
                if nx1 != None:
                    if canMove(nx1, ny1, nx2, ny2):
                        if nx1 == nx2:
                            visited[0][nx1][ny1] = visited[0][nx2][ny2] = True
                        else:
                            visited[1][nx1][ny1] = visited[1][nx2][ny2] = True
                        que.put((nx1, ny1, nx2, ny2, cnt+1))


'''
로봇의 크기는 2x1
0은 빈공간, 1은 벽.
앞, 뒤 구분 없이 움직일 수 있다.
회전할 때 벽이 있다면 회전할 수 없음.

board 길이 : 5 이상 100 이하
(1,1), (1,2)는 항상 0

움직이는 물체가 2칸이 아니고 1칸이라 가정할 때 100x100에서 BFS할 경우 걸리는 시간 : 
O(V+E) = O(100x100 + 100*198)
대충, 미로찾기와 유사한 문제기 때문에 bfs로 나타낼 수 있다고 생각한다.
또한, BFS로 탐색을 진행하는 중 (N,N)지점에 도착한다면, 그때의 이동 횟수가 바로 정답이다!(BFS기 때문)

풀이까지 걸린 시간: 64분
'''