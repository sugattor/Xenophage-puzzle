#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 記号を0～3に変換するやつ
int conv(char c)
{
    if (c == '*')
        return 0;
    if (c == '=')
        return 1;
    if (c == 'V')
        return 2;
    if (c == 'A')
        return 3;
    return 0;
}

// ファイル(puzzle.txt)から盤面を読み込むやつ
int readText(int *symbol)
{
    char c;
    int i; // symbol[i]
    FILE *file;

    if ((file = fopen("puzzle.txt", "r")) == NULL)
    {
        printf("file open error\n");
        return -1;
    }

    i = 0;
    while ((c = fgetc(file)) != EOF || i < 9)
    {
        switch (c)
        {
        case '*':
        case '=':
        case 'V':
        case 'A':
            symbol[i] = conv(c);
            i++;
            break;
        }
    }
    fclose(file);

    return 0;
}

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

// 目的と比べるやつ goalとmapの各要素が一致していれば1
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

// 盤面の表示
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

// 全通り試して最適解をsolve[]に入れる
void calc(int *map, int goal, int *solve)
{
    int m[9];     // 足す数が入ってるやつ
    int after[9]; // コピー用配列
    int currentCount;
    int minCount = 27;

    for (m[0] = 0; m[0] < 4; m[0] += 1)
    {
        for (m[1] = 0; m[1] < 4; m[1] += 1)
        {
            for (m[2] = 0; m[2] < 4; m[2] += 1)
            {
                for (m[3] = 0; m[3] < 4; m[3] += 1)
                {
                    for (m[4] = 0; m[4] < 4; m[4] += 1)
                    {
                        for (m[5] = 0; m[5] < 4; m[5] += 1)
                        {
                            for (m[6] = 0; m[6] < 4; m[6] += 1)
                            {
                                for (m[7] = 0; m[7] < 4; m[7] += 1)
                                {
                                    for (m[8] = 0; m[8] < 4; m[8] += 1)
                                    {
                                        memcpy(after, map, sizeof(after)); // afterの初期化
                                        currentCount = 0;                  // 押す回数の初期化

                                        // 各要素に対してpushを実行
                                        for (int i = 0; i < 9; i++)
                                        {
                                            // m[i]回、iを押す
                                            for (int j = 0; j < m[i]; j++)
                                            {
                                                push(after, i);
                                                currentCount++;
                                            }
                                        }

                                        // ゴールに達していたら
                                        if (check(after, goal))
                                        {
                                            if (currentCount < minCount)
                                            { // 押す回数がより少ない場合
                                                minCount = currentCount;
                                                memcpy(solve, m, sizeof(m));
                                                // printMap(m);printf("\n");
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
}

int main(void)
{
    int solve[9]; // 解が入る配列
    int test[9];
    int goal = 0;

    // 目標値を設定させる
    printf("揃える記号を入力(*,=,V,A)\n");
    fflush(stdout);
    goal = conv(getchar());

    // テキストを読み込む
    readText(test);

    // 盤面表示
    // printMap(test);

    printf("\n押す回数は以下の通りです\n\n");
    calc(test, goal, solve);
    printMap(solve);

    return 0;
}
