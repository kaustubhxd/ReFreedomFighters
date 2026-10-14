// u69_24.cpp - area 69, group 24 (slice 8). Small leaves: a void setter, a stdcall or-with-1, and a one-step list pop. No callees.
#include "ff.h"

static void THISCALL clearDwordAtC(u8 *self) { *(u32 *)(self + 0xc) = 0; }
PCREG(4d2900, clearDwordAtC);

static u32 STDCALL orOne4e6900(u32 v) { return v | 1; }
PCREG(4e6900, orOne4e6900);

// Pops the head of the list at self+0x2c: returns (and stores) head->next, or 0 for an empty list (the head is not stored then).
static u32 THISCALL popHead41ef40(u8 *self) {
  u32 head = *(u32 *)(self + 0x2c);
  if (!head) return head;
  u32 next = *(u32 *)(head + 4);
  *(u32 *)(self + 0x2c) = next;
  return next;
}
PCREG(41ef40, popHead41ef40);
