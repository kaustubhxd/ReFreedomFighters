// batch67517.cpp - cascade s6 batch 67517: 0x49cbb0.
#include "ff.h"

extern "C" void THISCALL ext_4e6bf0(u8 *pool, u32 *node);   // ret 4: returns a list node to the pool

// 0x49cbb0, thiscall(bucket, value, remove) ret 0xc, returns bool: the bucket's list (head slots at [+0x1d] + bucket * 4) is a chain of nodes {slot0, slot1, slot2, next}. Walks it
// for `value`; no list or no match returns 1. A match without the remove flag returns 0. With it the slot is cleared and the following slots (also those of later nodes) are shifted
// down by one; a node left with three empty slots is unlinked (head slot cleared or the previous node's next pointer) and handed back to the pool at this+4. Returns 0.
static u32 THISCALL fn49cbb0(u8 *self, u32 bucket, u32 value, u8 remove) {
  u32 **head = (u32 **)(*(u8 **)(self + 0x1d) + bucket * 4);
  u32 *node = *head;
  u32 *prev = 0;
  u32 k = 0;
  if (!node) return 1;
  while (node) {
    if (node[0] == value) { k = 0; break; }
    if (node[1] == value) { k = 1; break; }
    if (node[2] == value) { k = 2; break; }
    prev = node;
    node = (u32 *)node[3];
  }
  if (!node) return 1;
  if (!remove) return 0;
  node[k] = 0;
  u32 *edi = &node[k];
  u32 *eax;
  u32 ecx;
  bool fin = false;
  if (k < 2) {
    eax = edi + 1;
    ecx = k + 1;
  } else {
    eax = (u32 *)node[3];
    ecx = 0;
    if (!eax) {
      fin = true;
    } else {
      prev = node;
      node = eax;
    }
  }
  while (!fin) {
    if (!eax) break;
    if ((s32)ecx < 3) {
      u32 cnt = 3 - ecx;
      do {
        *edi = *eax;
        edi = eax;
        eax++;
      } while (--cnt);
    }
    eax = (u32 *)*eax;
    ecx = 0;
    if (!eax) break;
    prev = node;
    node = eax;
  }
  *edi = 0;
  if (node[0] == 0 && node[1] == 0 && node[2] == 0) {
    if (!prev) *head = 0;
    else prev[3] = 0;
    ext_4e6bf0(self + 4, node);
  }
  return 0;
}
PCREG(49cbb0, fn49cbb0);
