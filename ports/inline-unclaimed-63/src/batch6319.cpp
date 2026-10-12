// batch6319.cpp - unclaimed-63 batch 19 (docs/20-unclaimed-63.md): GUESS FUN_4ae220 at 0x4ae220 (no GC name). An insertion-sort
// pass over 0x35-byte records, keyed by the float at offset 0. Fastcall: ECX = begin, EDX = end, one stack argument (unused),
// ret 4. The record before begin is a sentinel (its key is smaller than every key), so the shift loop stops. For each record X
// from begin to end: if the key of the record before X's slot is greater than X's key, the records are shifted up (copy, then
// step back, while the record before is greater than X); then X is copied into the slot. Copies are the 0x35 bytes of the record
// (movups x3, dword at +0x30, byte at +0x34). Nothing is returned (eax untouched).
#include "ff.h"

// 0x4ae220 (GUESS FUN_4ae220).
static void FASTCALL unnamed4ae220(u8 *begin, u8 *end, u32 unused) {
  (void)unused;
  u8 *esi = begin;
  while (esi != end) {
    u8 X[0x35];
    for (u32 i = 0; i < 0x35; i++)
      X[i] = esi[i];
    float xk = *(float *)X;
    u8 *ecx = esi - 0x35;
    u8 *edx = esi;
    float pk = *(float *)ecx;
    if (pk > xk) {
      do {
        for (u32 i = 0; i < 0x35; i++)
          edx[i] = ecx[i];
        edx = ecx;
        ecx = ecx - 0x35;
        pk = *(float *)ecx;
      } while (pk > xk);
    }
    for (u32 i = 0; i < 0x35; i++)
      edx[i] = X[i];
    esi += 0x35;
  }
}
PCREG(4ae220, unnamed4ae220);
