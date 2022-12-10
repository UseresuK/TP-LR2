#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define YES   1
#define NO   0
#define N 20
#define MAXLINE 1024 
int main(void)
{
    char* ptr, o, rr;  // текущий символ из потока
    char s[N]; // буква слова
    char g[N];
    int flag;// признак слова
    int cnt, i, d, j, f = 0, u;// счётчики
    int found;   // индикатор того, что совпадение обнаружено
    int  L; // вспомогательные переменные
    int fls=0;
   
    while (fls == 0) {
        system("cls");
        printf("1 - Poisk slova\n2 - Exit\n");
        scanf("%c", &rr);

        if (rr == '1') {
            cnt = 0;
            flag = NO;
            found = NO;
            d = 0;
            i = 1;
            j = 1;
            u = 0;
            scanf("%*c");

            FILE* fpin; // указатель на структуру типа FILE для входного файла
            char line[MAXLINE]; // текущая строка 
            fpin = fopen("in.txt", "rt");   // открыть файл для чтения 
            if (fpin == NULL)
                return;
            printf("Slovo\n");
            while ((o = getchar()) != '\n') {
                u++;
                if (o != '\n') {
                    g[j] = o;
                    j++;

                }
            }
            printf("\nIz faila\n");
            while (!feof(fpin))  // цикл до конца файла 
            {
                ptr = fgets(line, MAXLINE, fpin); // чтение строки 
                if (ptr == NULL)
                {
                    printf("File pust");
                    break;
                }
                while (*ptr != '\0') // цикл до конца строки 
                {
                    if (*ptr == ' ' || *ptr == '.' || *ptr == '\n' || *ptr == ',' || *ptr == '!' || *ptr == '?' || *ptr == ';' || *ptr == ':' || *ptr == '-' || *ptr == '"' || *ptr == '(' || *ptr == ')')
                    {
                        flag = YES;

                        if (flag == YES)
                        {
                            L = d;
                            for (int i = 1; i <= L; i++) {
                                if ((s[i] == g[i])&&(L==u))          // проверка на совпадение
                                    found = YES;
                                else {
                                    found = NO;
                                    i = L;
                                }
                            }
                            if (found == YES)      // слово было обнаружено
                            {
                                cnt = cnt + 1;
                                d = 0;
                                i = 1;
                                f++;
                            }
                            else
                            {
                                i = 1;
                                d = 0;
                            }
                        }
                        flag = NO;
                        found = NO;
                    }
                    else    // найдена буква
                    {
                        d++;
                        s[i] = *ptr;
                        i++;
                    }
                    if (*ptr != '\n')
                        printf("%c", *ptr);
                    *ptr++;
                }
                printf("  %d\n", cnt);
                cnt = 0;
            }
            // printf("number of slov vsego= %d\n", f);
            fclose(fpin); // закрыть входной файл 
            //return 0;
            printf("\n");
            system("pause");
        }
        else
            fls = 1;
    }
    return 0;
}
