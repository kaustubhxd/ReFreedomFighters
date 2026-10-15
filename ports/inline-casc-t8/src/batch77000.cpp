// batch77000.cpp - t8 cascade batch 77000: tier F functions
#include "ff.h"

typedef bool(THISCALL *en_check_t)(u32);
typedef char *(*strrchr_t)(const char *, int);
typedef long(*atol_t)(const char *);

// 0x420bb0, thiscall: permission checks, string/path manipulation via strrchr and atol
static void THISCALL fn420bb0(u8 *self) {
  if (self[0x1a9b] != 0) return;

  u8 *eng = *(u8 **)0x70039c;
  en_check_t check1 = (en_check_t)(*(u32 **)(eng))[0xd4/4];
  en_check_t check2 = (en_check_t)(*(u32 **)(eng))[0xd8/4];

  if (!check1(0x11) || !check2(0x7b)) return;

  // Copy string from this+0x2346 to global 0x6fd830
  u8 *src = self + 0x2346;
  u8 *dst = (u8 *)0x6fd830;
  while (*src) *dst++ = *src++;
  *dst = 0;

  // Call strrchr to find last '.'
  strrchr_t strrchr_fn = G(strrchr_t, 0x676258);
  char *dot = strrchr_fn((char *)0x6fd830, '.');
  if (!dot) return;

  // Store observable result
  *(u32 *)(self + 0x50) = (u32)(dot - (char *)0x6fd830);

  // Call a vtable function with output param at [ebp-4]
  u32 local = 0;
  typedef void(THISCALL *v_fn_t)(u8 *, u32 *, u32);
  u32 **vt = (u32 **)self;
  (*(v_fn_t)(*vt)[0x160/4])(self, &local, 0);

  // Call atol on adjusted string and store result
  atol_t atol_fn = G(atol_t, 0x6762e0);
  long val = atol_fn(dot - 4);
  *(u32 *)(self + 0xec) = val;
}
PCREG(420bb0, fn420bb0);
