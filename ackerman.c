// Author : HARSHIT GARG
// DATE  : FEBRUARY 6, 2014
// STATUS : COMPLETED
//          CORRECT


#include <stdio.h>
#include <math.h>

//_________funcrion definitions

//_________function declarations

long int AckermanFunction(long int, long int);
//_________main function

int main()
{
    printf("\nThis function is about Ackermann function.");

    FILE *f,    //for ip file
          *f1;  //for op file

    int counter = 0,    //counter
        counter1 = 0,
         cases = -1;    //total number of cases
    int m,n,    // ip variables
        result;
    f = fopen("acerman.txt", "r");
    if(!f)
    {
            perror("\nThe following error occured.");
            return 0;
    }
    f1 = fopen("Ackermanop.txt", "w");
    if(!f1)
    {
            perror("\nThe following error occured.");
            return 0;
    }

    fscanf(f,"%d", &cases);
    if(cases < 1)
    {
        return 0; // invalid number of cases
    }
    while(counter < cases)
    {
        fscanf(f,"%d %d", &m, &n);
        result = AckermanFunction(m,n);
        if( result != -1)
        {
            printf("\nThe value of Ackerman Function is %d", result);
            fprintf(f1, "Case : %d : %d %d %d\n", counter + 1, m, n, result);
        }
        else
        {
            printf("\nWrong input");
            fprintf(f1, "Case : %d : %d %d Negative value in input\n", counter + 1, m, n);
        }
        counter++;
    }
    fclose(f);
    fclose(f1);

    //Ackerman
    //Ackerman
    {
        printf("\nThis ");
        FILE *f2 = fopen("myackerman.txt", "w");
        fprintf(f2, "This is list of values:");
        counter = 0;
        int counter2 = 0;
        while(counter < 5)
        {
             counter1 = 0;

             while(counter1 < 2)
            {
                fprintf(f2, "\n%ld : %ld %ld %ld", counter2 , counter , counter1, AckermanFunction(counter, counter1));
                counter1++;
                counter2++;
            }
            counter++;
        }
        fclose(f2);
    }

    //printf("final = %ld", AckermanFunction(5, 5));
    return 0;
}
//Output :  -1 if wrogn input
//          correect value of fucntions
long int AckermanFunction(long int m, long int n)
{
    if(m < 0 || n < 0)
        return -1;
    if(m == 0)
        return n+1;
        else
            if( n == 0)
                return AckermanFunction(m-1, 1);
            else
                return AckermanFunction(m-1, AckermanFunction(m, n-1));
}
