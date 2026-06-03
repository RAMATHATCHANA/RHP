#include <stdio.h>

int main()
{
    char str[1000001];
    scanf("%s", str);

    int flag = 0;

    for(int i = 0; str[i]; i++)
    {
        // Check digits 1 to 9
        if(str[i] >= '1' && str[i] <= '9')
        {
            flag = flag | (1 << (str[i] - '1'));
        }
    }

    if(flag == (1 << 9) - 1)
        printf("Yes");
    else
        printf("No");

    return 0;
}
