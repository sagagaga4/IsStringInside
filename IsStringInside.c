#include <stdio.h>
#include <string.h>

int BubbleSort(char *str,int n)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(str[j] < str[i])
            {
                int temp = str[j];
                str[j] = str[i];
                str[i] = temp;
            }
        }
    }
    return 0;
}

int IsStringInside(char*  str, char* pattern)
{
    if(str == NULL || pattern == NULL)
    {
        return -1;
    }

    int length_str = strlen(str);
    int length_pattern = strlen(pattern);
    int count = 0;

    BubbleSort(str, length_str);

    char temp[] = "";
    int index_temp = 0;

    for(int i = 0; i < length_str;i++)
    {
        if(str[i] != str[i+1])
        {
            temp[index_temp++] = str[i];
        }
        temp[index_temp] = '\0';
    }

    printf("%s\n",temp);
    int temp_length = strlen(temp);

    for(int i = 0; i < temp_length; i++)
    {
        for(int j = 0; j < length_pattern; j++)
        {
            if(pattern[j] == temp[i])
            {
                count++;
            }
        }
    }

    if(count == length_pattern)
    {
        printf("MATCH CONFIRMED :^)\n");
        return 1;
    }
    printf("MATCH IS NOT CONFIRMED!!!!!\n");

    return 0;
}

int main()
{
    char str1[] = "aaaaaabcd";
    char str2[] = "abcd";
    IsStringInside(str1,str2);

    return 0;
}