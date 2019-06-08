#include "un.h"


UN::UN(int num)
{
    parent = new int[num + 1];
    for (int i = 1; i <= num; i++)
                parent[i] = 0;
}

UN::~UN(){delete[]parent;}


int UN::Find(int element)
{
    while (parent[element]!=0)
            {
                element = parent[element];
            }
            return element;
}

void UN::Unite(int &rootA, int &rootB)
{
    parent[rootB]=rootA;
}
