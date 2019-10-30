#include <stdio.h>
#include <memory.h>

// 米=0　÷=1　V=2　A=3

// 押されたら反映するやつ
void push(int *map, int point)
{
    if (point == 0)
    {
        map[0] += 1;
        map[1] += 1;
        map[2] += 1;
        map[3] += 1;
        map[6] += 1;
    }
    if (point == 1)
    {
        map[0] += 1;
        map[1] += 1;
        map[2] += 1;
        map[4] += 1;
        map[7] += 1;
    }
    if (point == 2)
    {
        map[0] += 1;
        map[1] += 1;
        map[2] += 1;
        map[5] += 1;
        map[8] += 1;
    }
    if (point == 3)
    {
        map[3] += 1;
        map[4] += 1;
        map[5] += 1;
        map[0] += 1;
        map[6] += 1;
    }
    if (point == 4)
    {
        map[3] += 1;
        map[4] += 1;
        map[5] += 1;
        map[1] += 1;
        map[7] += 1;
    }
    if (point == 5)
    {
        map[3] += 1;
        map[4] += 1;
        map[5] += 1;
        map[2] += 1;
        map[8] += 1;
    }
    if (point == 6)
    {
        map[6] += 1;
        map[7] += 1;
        map[8] += 1;
        map[0] += 1;
        map[3] += 1;
    }
    if (point == 7)
    {
        map[6] += 1;
        map[7] += 1;
        map[8] += 1;
        map[1] += 1;
        map[4] += 1;
    }
    if (point == 8)
    {
        map[6] += 1;
        map[7] += 1;
        map[8] += 1;
        map[2] += 1;
        map[5] += 1;
    }

    // オーバーしてたら戻すやつ
    for (int i = 0; i < 9; i++)
    {
        map[i] = map[i] % 4;
    }
}

// 目的と比べるやつ
int check(int *map, int goal)
{
    int clear = 1;
    for (int i = 0; i < 9; i++)
    {
        if (map[i] != goal)
            clear = 0;
    }
    return clear;
}

void printMap(int *map)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d", map[i * 3 + j]);
        }
        puts("");
    }
}


// 全通り試すやつ
void calc(int *map, int goal)
{
    int m[9];     // 足す数が入ってるやつ
    int after[9]; // コピー用配列

    for (m[0] = 0; m[0] < 4; m[0]+=1)
    {
        for (m[1] = 0; m[1] < 4; m[1]+=1)
        {
            for (m[2] = 0; m[2] < 4; m[2]+=1)
            {
                for (m[3] = 0; m[3] < 4; m[3]+=1)
                {
                    for (m[4] = 0; m[4] < 4; m[4]+=1)
                    {
                        for (m[5] = 0; m[5] < 4; m[5]+=1)
                        {
                            for (m[6] = 0; m[6] < 4; m[6]+=1)
                            {
                                for (m[7] = 0; m[7] < 4; m[7]+=1)
                                {
                                    for (m[8] = 0; m[8] < 4; m[8]+=1)
                                    {
                                        // afterの初期化
                                        memcpy(after, map, sizeof(after));

                                        // 各要素に対してpushを実行
                                        for (int i = 0; i < 9; i++)
                                        {
                                            // m[i]回、iを押す
                                            for (int j = 0; j < m[i]; j++)
                                            {
                                                push(after, i);
                                            }
                                        }

                                        // ゴールに達していたら
                                        if (check(after, goal))
                                        {
                                            printMap(m);
                                            printf("\n");
                                            printMap(after);
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(void)
{
    int test[9] = {1, 1, 0, 2, 2, 2, 1, 3, 0};
    int goal = 2;
    printMap(test);
    printf("\n\n");
    calc(test, goal);
    // printf("%d\n\n", check(test, goal));
}