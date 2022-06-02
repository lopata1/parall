#include <stdio.h>
#include <string.h>
#include <convert.h>

char *colorCode(char *color, int bold)
{
    if (bold)
    {
        if (strcmp(color, "red") == 0)
        {
            return "\033[1;31m";
        }
        else if (strcmp(color, "black") == 0)
        {
            return "\033[1;30m";
        }
        else if (strcmp(color, "green") == 0)
        {
            return "\033[1;32m";
        }
        else if (strcmp(color, "yellow") == 0)
        {
            return "\033[1;33m";
        }
        else if (strcmp(color, "blue") == 0)
        {
            return "\033[1;34m";
        }
        else if (strcmp(color, "purple") == 0)
        {
            return "\033[1;35m";
        }
        else if (strcmp(color, "cyan") == 0)
        {
            return "\033[1;36m";
        }
        else if (strcmp(color, "white") == 0)
        {
            return "\033[1;37m";
        }
        else
        {
            // reset
            return "\033[0m";
        }
    }
    else
    {
        if (strcmp(color, "red") == 0)
        {
            return "\033[0;31m";
        }
        else if (strcmp(color, "black") == 0)
        {
            return "\033[0;30m";
        }
        else if (strcmp(color, "green") == 0)
        {
            return "\033[0;32m";
        }
        else if (strcmp(color, "yellow") == 0)
        {
            return "\033[0;33m";
        }
        else if (strcmp(color, "blue") == 0)
        {
            return "\033[0;34m";
        }
        else if (strcmp(color, "purple") == 0)
        {
            return "\033[0;35m";
        }
        else if (strcmp(color, "cyan") == 0)
        {
            return "\033[0;36m";
        }
        else if (strcmp(color, "white") == 0)
        {
            return "\033[0;37m";
        }
        else
        {
            // reset
            return "\033[0m";
        }
    }
}

int main(int argc, char *argv[])
{
    char *primarycolor, *secondarycolor, *aspace;
    if(argc < 2)
    {
        printf("USAGE: parall [size] (color) (secondary color) ({b}old or {s}oft color) ({s}quare)\n\n");
        return 0;
    }
    if(argc < 3)
    {
        primarycolor = colorCode("reset", 0);
        secondarycolor = colorCode("reset", 0);
    }
    else if (argc == 3)
    {
        primarycolor = colorCode(argv[2], 0);
        secondarycolor = primarycolor;
    }
    else if (argc == 4)
    {
        primarycolor = colorCode(argv[2], 0);
        secondarycolor = colorCode(argv[3], 0);
    }
    else if (argc == 5) 
    {
        int isBold = (strcmp(argv[4], "b") == 0) || (strcmp(argv[4], "bold") == 0);
        primarycolor = colorCode(argv[2], isBold);
        secondarycolor = colorCode(argv[3], isBold);
    }
    else 
    {
        int isBold = (strcmp(argv[4], "b") == 0) || (strcmp(argv[4], "bold") == 0);
        int isSquare = (strcmp(argv[5], "s") == 0) || (strcmp(argv[5], "square") == 0);
        if (isSquare)
        {
            aspace = " ";
        }
        primarycolor = colorCode(argv[2], isBold);
        secondarycolor = colorCode(argv[3], isBold);
    }
    const int PYRAMID_SIZE = charToInt(argv[1], strlen(argv[1]));
    int firsthalf, secondhalf;
    firsthalf = (int) PYRAMID_SIZE / 2 + 1;
    secondhalf = (int) PYRAMID_SIZE / 2;

    int firststar = 1;
    for (int i = 0; i < firsthalf; i++)
    {
        for(int j= 0; j < (secondhalf - i); j++)
        {
            printf(" %s", aspace);
        }
        for(int j = 0; j <= (i*2); j++)
        {
            if (firststar)
            {
                printf("%s*%s", primarycolor, aspace);
                firststar = 0;
            }
            else 
            {
                printf("%s*%s", secondarycolor, aspace);
                firststar = 1;
            }
        }
        printf("\n");
    }
    for (int i = 0; i < secondhalf; i++)
    {
        for(int j= 0; j <= i; j++)
        {
            printf(" %s", aspace);
        }
        for(int j = 0; j <= (secondhalf*2 - 2 - i*2); j++)
        {
            if (firststar)
            {
                printf("%s*%s", primarycolor, aspace);
                firststar = 0;
            }
            else 
            {
                printf("%s*%s", secondarycolor, aspace);
                firststar = 1;
            }
        }
        printf("\n");
    }
    printf("%s", colorCode("reset", 0));
    return 0;
}