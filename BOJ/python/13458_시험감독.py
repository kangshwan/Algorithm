# N개의 시험장
# 총감독: 1 시험장당 B명 감독 (1인 1시험장, 필수)
# 부감독: 1 시험장당 C명 감독 (제한X)

N = int(input())
A = map(int, input().split())
B, C = map(int, input().split())

answer = 0
for std in A:
    std -= B
    if std > 0:
        if std % C == 0:
            answer += std//C
        else:
            answer += std//C + 1
    answer += 1

print(answer)