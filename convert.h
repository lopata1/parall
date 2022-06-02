#pragma once

int charToInt(char *cnumber, int size)
{
    int number = 0;
    for(int i = 0; i < size; i++)
    {
        int pwt = 1;
        int digit = (cnumber[i] - 48);
        for(int j = 0; j < (size - i - 1); j++)
        {
            pwt*=10;
        }
        number += digit * pwt;
    }
    return number;
}