#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Separation series hash table
// Write a hash table program that inputs multiple key values in a hash table with size M, and stores it using a separate chain.

// implementation conditions
// 1. Hash table is dynamically assigned to an array of M size
// 2. Input key is natural without duplicate
// 3.Use hash function H (x) = x % m for key x.
// 4. If a collision occurs when insertion occurs, make a separate chain and insert it in front of the chain.
// 5. if the first key is deleted, the second key is moved to the first key.

// input
// 1. Receive the size M of the hash table.
// 2. Insert (i), search (S), deletion (D), and print (P) commands are repeated input regardless of the order.
// 2 - 1) i <x>: Insert key x into a hash table
// 2 - 2) s <x> : Navigating whether key X exists in the hash table
// 2 - 3) d <x> : Delete when key X exists at the hash table
// 2 - 4) p : Print the keys stored on the hash table in order
// 2 - 5) e : End the program

// output
// 1. No output when inserting a key
// 2. When searching or deleting, if the key is present, the list ranking that the key is stored is printed in the list (starting from 1) and if the key is not present, printed 0 (significant to printing the list in the list, not the address of the hash table)
// 3. When printing a hash table, printed the keys stored while traveling from address 0 to the last address.

int M;

int main()
{
    scanf("%d", &M);
    // Hash table is dynamically assigned to an array of M size
    int *hash_table = (int *)malloc(sizeof(int) * M);
    memset(hash_table, -1, sizeof(int) * M);

    while (1)
    {
        char command;
        int key;
        scanf(" %c", &command);
        if (command == 'e')
            break;
        else if (command == 'i')
        {
            scanf("%d", &key);
            // Use hash function H (x) = x % m for key x.
            int hash = key % M;
            // If a collision occurs when insertion occurs, make a separate chain and insert it in front of the chain.
            if (hash_table[hash] == -1)
                hash_table[hash] = key;
            else
            {
                int temp = hash_table[hash];
                hash_table[hash] = key;
                key = temp;
                while (1)
                {
                    hash = (hash + 1) % M;
                    if (hash_table[hash] == -1)
                    {
                        hash_table[hash] = key;
                        break;
                    }
                    else
                    {
                        temp = hash_table[hash];
                        hash_table[hash] = key;
                        key = temp;
                    }
                }
            }
        }
        else if (command == 's')
        {
            scanf("%d", &key);
            // Use hash function H (x) = x % m for key x.
            int hash = key % M;
            int count = 0;
            while (1)
            {
                if (hash_table[hash] == key)
                {
                    printf("%d\n", count + 1);
                    break;
                }
                else if (hash_table[hash] == -1)
                {
                    printf("0\n");
                    break;
                }
                else
                {
                    hash = (hash + 1) % M;
                    count++;
                }
            }
        }
        else if (command == 'd')
        {
            scanf("%d", &key);
            // Use hash function H (x) = x % m for key x.
            int hash = key % M;
            int count = 0;
            while (1)
            {
                if (hash_table[hash] == key)
                {
                    printf("%d\n", count + 1);
                    hash_table[hash] = -1;
                    // if the first key is deleted, the second key is moved to the first key.
                    while (1)
                    {
                        hash = (hash + 1) % M;
                        if (hash_table[hash] == -1)
                            break;
                        else
                        {
                            int temp = hash_table[hash];
                            hash_table[hash] = -1;
                            key = temp;
                            hash = key % M;
                            while (1)
                            {
                                if (hash_table[hash] == -1)
                                {
                                    hash_table[hash] = key;
                                    break;
                                }
                                else
                                {
                                    temp = hash_table[hash];
                                    hash_table[hash] = key;
                                    key = temp;
                                    hash = (hash + 1) % M;
                                }
                            }
                        }
                    }
                    break;
                }
                else if (hash_table[hash] == -1)
                {
                    printf("0\n");
                    break;
                }
                else
                {
                    hash = (hash + 1) % M;
                    count++;
                }
            }
        }
        else if (command == 'p')
        {
            for (int i = 0; i < M; i++)
            {
                if (hash_table[i] != -1)
                    printf("%d ", hash_table[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

/*
13
i 34
i 23
i 26
i 21
s 36
s 26
s 34
s 21
p
d 21
s 34
d 8
e
*/