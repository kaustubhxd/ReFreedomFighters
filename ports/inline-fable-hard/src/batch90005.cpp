// batch90005.cpp - hard-function trial (fable), batch 90005: 0x552b50 script binding: look up a placement record by 3 ints and fill 12 results (446 insns).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *list, u32 idx);    // ret 4 (verified): typed value slot idx of a value list {dword value, byte type}
extern "C" u8 *THISCALL ext_5002f0(void *slot, u32 v);      // ret 4 (verified): set int (type 1), logs when the slot type is not 0/1
extern "C" void THISCALL ext_602cd0(void *slot, void *pf);  // ret 4 (verified): set float from pointer (type 2), logs when not 0/2
extern "C" s32 STDCALL ext_5873a0(u32 a, u32 b, u32 c);     // ret 0xc (verified, hooked): find the record, -1 when none

typedef void (*c3_t)(void *, u32, u32);
static inline void logerr(u32 line) {   // the inlined assert: log (file 0x69c8e0, line) then the assert hook
  u8 *lg = G(u8 *, 0x700390);
  u8 *lo = vcall<u8 *>(lg, 0x20, 0x69c8e0u, line);
  (*(c3_t **)lo)[0x2c / 4](lo, 0x69c6b0u, 0x69c938u);
  u32 h = G(u32, 0x7003b0);
  if (h) ((void (*)())h)();
  else __builtin_trap();
}
static inline u32 getint(void *list, u32 i) {   // slot type must be 0 or 1
  u8 *s = ext_5003d0(list, i);
  if (s[4] != 0 && s[4] != 1) logerr(0x104);
  return *(u32 *)s;
}
static inline void setf0(void *list, u32 i, u32 bits) {   // slot type must be 0 or 2; becomes float `bits`
  u8 *s = ext_5003d0(list, i);
  if (s[4] != 0 && s[4] != 2) logerr(0x104);
  s[4] = 2;
  *(u32 *)s = bits;
}

// 0x552b50, stdcall(rec) ret 4. args = rec[4], results = rec[8]. a0..a2 = int args 0..2. results 0,1,2 := 0.0f; 3 := -1; 4,5,6 := 0; 7,8,9 := 0.0f;
// 10 := 0; 11 := 1.0f. mgr = [[0x7003b8]+0x2c1d]; if mgr: i = 0x5873a0(a0, a1, a2); i >= 0: R = mgr[0x5f] + i*72: results 0,1,2 := floats R+0x10/0x14/0x18;
// 3 := i; 4 := flags R[0x34] bit0 -> 0, bit1 -> 1, bit2 -> 2, else assert and 0; 5 := bit3; 6 := bit4; 7,8,9 := floats R+0x28/0x2c/0x30; 10 := [[0x7003b8]+0x2c25].
static void STDCALL fn552b50(u8 *rec) {
  void *args = *(void **)(rec + 4);
  void *res = *(void **)(rec + 8);
  u32 a0 = getint(args, 0);
  u32 a1 = getint(args, 1);
  u32 a2 = getint(args, 2);
  setf0(res, 0, 0);
  setf0(res, 1, 0);
  setf0(res, 2, 0);
  ext_5002f0(ext_5003d0(res, 3), 0xffffffff);
  ext_5002f0(ext_5003d0(res, 4), 0);
  ext_5002f0(ext_5003d0(res, 5), 0);
  ext_5002f0(ext_5003d0(res, 6), 0);
  setf0(res, 7, 0);
  setf0(res, 8, 0);
  setf0(res, 9, 0);
  ext_5002f0(ext_5003d0(res, 10), 0);
  setf0(res, 11, 0x3f800000);
  u8 *mgr = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c1d);
  if (!mgr) return;
  s32 i = ext_5873a0(a0, a1, a2);
  if (i < 0) return;
  u8 *R = *(u8 **)(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c1d) + 0x5f) + i * 72;
  ext_602cd0(ext_5003d0(res, 0), R + 0x10);
  ext_602cd0(ext_5003d0(res, 1), R + 0x14);
  ext_602cd0(ext_5003d0(res, 2), R + 0x18);
  ext_5002f0(ext_5003d0(res, 3), (u32)i);
  u32 fl = *(u32 *)(R + 0x34);
  u32 kind;
  if (fl & 1) kind = 0;
  else if (fl & 2) kind = 1;
  else if (fl & 4) kind = 2;
  else {
    u32 h = G(u32, 0x7003b0);
    if (h) ((void (*)())h)();
    else __builtin_trap();
    kind = 0;
  }
  ext_5002f0(ext_5003d0(res, 4), kind);
  ext_5002f0(ext_5003d0(res, 5), (*(u32 *)(R + 0x34) >> 3) & 1);
  ext_5002f0(ext_5003d0(res, 6), (*(u32 *)(R + 0x34) >> 4) & 1);
  ext_602cd0(ext_5003d0(res, 7), R + 0x28);
  ext_602cd0(ext_5003d0(res, 8), R + 0x2c);
  ext_602cd0(ext_5003d0(res, 9), R + 0x30);
  ext_5002f0(ext_5003d0(res, 10), *(u32 *)(G(u8 *, 0x7003b8) + 0x2c25));
}
PCREG(552b50, fn552b50);
