#include<stdio.h>
#include<math.h>

int gcd1(int a, int b, int *count) //Euclid's Algorithm
{
    while(a * b != 0)
    {
        (*count)++;
        if(a > b)
        {
            (*count)++;
            a = a % b;
        }

        else
        {
            (*count)++;
            b = b % a;
        }
        (*count)++;
    }

    (*count)++;
    if(a == 0)
    {
        (*count)++;
        return b;
    }

    (*count)++;
    return a;
}

int gcd2(int a, int b, int *count) //Consecutive Integer Checking Algorithm
{
    int t;
    (*count)++;
    t = (a<b) ? a : b;
    (*count)++;
    while((a%t != 0) || (b%t != 0))
    {
        (*count)++; //for every condition check which returns true
        t--;
        (*count)++;
    }
    (*count)++; //for the last condition check
    (*count)++;
    return t;
}

int gcd3(int a, int b, int *count) //Middle School Method using sieve of Eratosthenes to find primes
{
    int min, i, j, temp_a, temp_b, gcd=1;
    (*count)++;

    //Sieve of Eratosthenes
    min = (a<b) ? a : b; //As GCD will always be less than or equal to minimum of the two values
    (*count)++;
    int primes[min+1];
    (*count)++;
    primes[0] = primes[1] = 0; //As 0 and 1 are not prime
    (*count)++;

    for(i=2; i<=min; i++) //sets all numbers from 2 onwards as prime unless specified otherwise
    {
        primes[i] = 1;
        (*count)++;
    }
    (*count) += i-1;

    for(i=2; i<min; i++) //sieves out the prime numbers
    {
        if(primes[i])
        {
            for(j=i*i; j<=min; j += i)
            {
                primes[j] = 0;
                (*count)++;
            }
            (*count) += j;
        }
        (*count)++; //if statement condition checking
    }
    (*count) += i-1;

    //Middle school method
    //We can take advantage of the primes[] array itself to store the powers of the prime factors
    for(i=2; i<=min; i++)
    {
        if(primes[i])
        {
            temp_a = a;
            (*count)++;
            temp_b = b;
            (*count)++;
            primes[i] = 0; //Since we are counting powers now, we can ignore any prime that doesn't divide a or b
            (*count)++;
            while( (temp_a%i == 0) && (temp_b%i == 0) ) //Keep counting while both are divisible by the next power
            {
                (*count)++; //for every condition check which returns true
                primes[i]++;
                (*count)++;
                temp_a = temp_a/i; //Divide the number by the prime as much as possible, and count powers
                (*count)++;
                temp_b = temp_b/i;
                (*count)++;
            }
            (*count)++; //For the last check in the while loop
        }
        (*count)++; //if statement condition checking
    }
    (*count) += i-1;

    for(i=2; i<=min; i++)
    {
        gcd = gcd * pow(i, primes[i]);
        (*count)++;
    }
    (*count) += i-1;
    //Alternatively, we could have multiplied and calculated the gcd in the previous loop itself,
    //but since the method used in middle school involved calculating it at the end, that's what has been done.

    (*count)++;
    return gcd;
}

int main()
{
    int a, b, i, check1, check2, check3, count1=0, count2=0, count3=0;
    for(i=0; i<6; i++)
    {
        count1 = count2 = count3 = 0;
        printf("Enter 2 numbers\n");
        scanf("%d%d", &a, &b);
        check1 = gcd1(a, b, &count1);
        check2 = gcd2(a, b, &count2);
        check3 = gcd3(a, b, &count3);

        printf("Checks\t: %d\t%d\t%d\n", check1, check2, check3);
        printf("Steps\t: %d\t%d\t%d\n", count1, count2, count3);
    }
    
    return 0;
}