#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define YES   1
#define NO   0
#define N 20
#define MAXLINE 1024 
int main(void)
{
    char* ptr, o, rr;  // ������� ������ �� ������
    char s[N]; // ����� �����
    char g[N];
    int flag;// ������� �����
    int cnt, i, d, j, f = 0, u;// ��������
    int found;   // ��������� ����, ��� ���������� ����������
    int  L; // ��������������� ����������
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

            FILE* fpin; // ��������� �� ��������� ���� FILE ��� �������� �����
            char line[MAXLINE]; // ������� ������ 
            fpin = fopen("in.txt", "rt");   // ������� ���� ��� ������ 
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
            while (!feof(fpin))  // ���� �� ����� ����� 
            {
                ptr = fgets(line, MAXLINE, fpin); // ������ ������ 
                if (ptr == NULL)
                {
                    printf("File pust");
                    break;
                }
                while (*ptr != '\0') // ���� �� ����� ������ 
                {
                    if (*ptr == ' ' || *ptr == '.' || *ptr == '\n' || *ptr == ',' || *ptr == '!' || *ptr == '?' || *ptr == ';' || *ptr == ':' || *ptr == '-' || *ptr == '"' || *ptr == '(' || *ptr == ')')
                    {
                        flag = YES;

                        if (flag == YES)
                        {
                            L = d;
                            for (int i = 1; i <= L; i++) {
                                if ((s[i] == g[i])&&(L==u))          // �������� �� ����������
                                    found = YES;
                                else {
                                    found = NO;
                                    i = L;
                                }
                            }
                            if (found == YES)      // ����� ���� ����������
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
                    else    // ������� �����
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
            fclose(fpin); // ������� ������� ���� 
            //return 0;
            printf("\n");
            system("pause");
        }
        else
            fls = 1;
    }
    return 0;
}
