list = [[int(x) for x in input().split()]for y in range(19)]
who_win = 0

for i in range(16):
    for j in range(16):
        if list[i][j] == 1:
            if list[i][j+1] == list[i][j+2] == list[i][j+3] == list[i][j+4] == 1:
                if j+5 <= 19:
                    if list[i][j+5] != 1:
                        x = i
                        y = j
                        who_win = 1
                        break
            elif list[i+1][j] == list[i+2][j] == list[i+3][j] == list[i+4][j] == 1:
                if i+5 <= 19:
                    if list[i+5][j] != 1:
                        x = i
                        y = j
                        who_win = 1
                        break
            elif list[i+1][j+1] == list[i+2][j+2] == list[i+3][j+3] == list[i+4][j+5] == 1:
                if j+5 <= 19 and i+5 <= 19:
                    if list[i+5][j+5] != 1:
                        x = i
                        y = j
                        who_win = 1
                        break
        elif list[i][j] == 2:
            if list[i][j+1] == list[i][j+2] == list[i][j+3] == list[i][j+4] == 2:
                if j+5 <= 19:
                    if list[i][j+5] != 2:
                        x = i
                        y = j
                        who_win = 2
                        break
            elif list[i+1][j] == list[i+2][j] == list[i+3][j] == list[i+4][j] == 2:
                if i+5 <= 19:
                    if list[i+5][j] != 2:
                        x = i
                        y = j
                        who_win = 2
                        break
            elif list[i+1][j+1] == list[i+2][j+2] == list[i+3][j+3] == list[i+4][j+5] == 2:
                if j+5 <= 19 and i+5 <= 19:
                    if list[i+5][j+5] != 2:
                        x = i
                        y = j
                        who_win = 2
                        break
print(who_win)
print(x, y)