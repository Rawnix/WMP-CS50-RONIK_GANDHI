/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

 #define max 65535

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n<=0) return false;
    int l=0, r=n-1, mid=(l+r)/2;
    while(l!=r)
    {
        if(values[mid] == value) return true;
        else if(values[mid] > value)
        {
            r=mid-1;
            mid=(l+r)/2;
        }
        else
        {
            l=mid+1;
            mid=(l+r)/2;
        }
    }
    if(values[mid] == value) return true;
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int count[max+1] = {0};
    for(int i=0; i<n; i++)
    {
        count[values[i]]++;
    }
    int cursor=0;
    for(int i=0; i<=max; i++)
    {
        while(count[i]--)
        {
            values[cursor++] = i;
        }
    }
    return;
}
