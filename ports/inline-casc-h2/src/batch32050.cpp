#include "ff.h"

// 0x5edc80: thiscall(this, end_ptr) ret 4 - swap/reverse elements from opposite ends
// Swaps elements from this pointer and end_ptr moving towards each other
void __thiscall sub_5edc80(int* ecx, int* edx) {
    int* start = ecx;
    int* end = edx;

    while (start < end) {
        end--;
        if (start >= end) break;

        // Swap values
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
    }
}
PCREG(5edc80, sub_5edc80);
