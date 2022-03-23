#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

// hostbyorder to network byte order(htons)using bit shifting
uint16_t htons(uint16_t hostshort)
{
    return (hostshort << 8) | (hostshort >> 8);
}