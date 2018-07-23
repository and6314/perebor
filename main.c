#include <stdio.h>
#include <malloc.h>
#include <ntdef.h>


BOOLEAN alg(int n,char *s2);
BOOLEAN rec(char *s1, int n1, int nj,char *s2);
BOOLEAN check(char *s1,char *s2);
int main() {
    if (alg(4,"0100"))
        printf("true\n");
    else
        printf("false\n");
    getchar();
    return 0;
}

//n - максимальное кол-во возможных зап.ног
//s2 - код кнопки
BOOLEAN alg(int n,char *s2)
{
    char *s1;
    int k = 13 - strlen(s2);
    s1 = (char*)malloc(k * sizeof(char));
    //char s1[9] = "FFFFFFFF";
    for (int i=0;i<k;++i)
        s1[i]='F';
    s1[k-1] = '\0';
    for (int i=1; i<=n;++i)
        if (rec(s1,0,i,s2))
        {
            printf("%s", s1);
            printf("%s\n", s2);
            return 1;
        }
    free(s1);
    return 0;
}

//BOOLEAN rec(char *s1, int n1, int nj) - нужно точно знать кол-во зап. ножек
//s1 - первый блок кода
// n1 - позиция с какой начинаем подставлять 1/0
// nj - запаянные ножки
BOOLEAN rec(char *s1, int n1, int nj,char *s2)
{
    for (int p=0;p<2;++p)
    {
        for (int i=n1; i<strlen(s1);++i)
        {
            s1[i] = p+'0';
            if (nj == 1)
            {
                if (check(s1,s2))
                    return 1;
                s1[i]='F';

            }
            else
            if (i!=strlen(s1)-1)
                if (rec(s1,i+1,nj-1, s2))
                    return 1;
            s1[i] = 'F';
        }
    }
    return 0;
}

BOOLEAN check(char *s1, char *s2)
{
    char s[13]="";
    for (int i=0; i<strlen(s1);++i)
        s[i] = s1[i];
    for (int i=strlen(s1); i<13;++i)
        s[i] = s2[i-strlen(s1)];
    if (strcmp(s,"F0F1FF0F0100") == 0)
        return 1;
    return 0;
}