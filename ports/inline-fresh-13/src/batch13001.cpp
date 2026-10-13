// batch13001.cpp - fresh slice 13, batch 1 (docs/20-fresh-13.md), 2026-10-12. Two script-interface method registrations.
//
// 0x604710 OpaqueString_t::addMethodDefinitions(OpaqueMethodList_t&) (name map low). Thiscall, one stack argument (ret 4).
// Eleven methods. For each: OpaqueMethodList_t add 0x5f9940 (thiscall on the list, three pointer arguments, ret 0xc); then,
// while the list's flag byte +0xc is set, the native's address goes into the table at 0x724770[count] (count at 0x724768,
// at most 50); at 50 or more the hook at 0x7003b0 is called (int3 when it is null). Finally the flag is cleared and
// 0x5f9b80(this, list) runs (thiscall, ret 4).
//
// 0x50d190 ZScriptItemInterface_t::addMethodDefinitions(OpaqueMethodList_t&) (name map high). Thiscall, ret 4. Twenty
// natives; before each one, a cleared flag (+0xc) returns at once. The native goes into 0x7012d0[count] (count 0x7012c8,
// at most 50); at 50 or more this->vtbl[+0x44](0x69d408) (one argument) and then the hook at 0x7003b0 (int3 when null).
#include "ff.h"

extern "C" char ext_5f9940[], ext_5f9b80[];
typedef void(THISCALL *Add3)(void *list, u32 a, u32 b, u32 c);
typedef void(THISCALL *Tail1)(void *self, void *list);
typedef void(THISCALL *Warn1)(void *self, u32 msg);
typedef void (*Hook0)(void);

static inline void callHook() {
  u32 h = G(u32, 0x7003b0);
  if (!h)
    __builtin_debugtrap();
  ((Hook0)h)();
}

static void THISCALL opaqueStringAddMethods(u8 *self, u8 *list) {
  static const u32 kM[11][4] = {
      {0x6b9c88, 0x6b9c7c, 0x677b5a, 0x6057d0}, {0x6b9c98, 0x6b9c90, 0x6b9c7c, 0x605630},
      {0x6b9ca4, 0x6b9c90, 0x6b9c7c, 0x605150}, {0x6b9cb0, 0x6b9c90, 0x6b9c7c, 0x605010},
      {0x6b9cbc, 0x677b5a, 0x677b5a, 0x604f50}, {0x6b9cc4, 0x677b5a, 0x677b5a, 0x6058d0},
      {0x6b9ccc, 0x677b5a, 0x677b5a, 0x604e10}, {0x6b9058, 0x677b5a, 0x677b5a, 0x604a60},
      {0x6b9cd4, 0x677b5a, 0x677b5a, 0x604d70}, {0x6b9cd8, 0x677b5a, 0x677b5a, 0x604d70},
      {0x6b9c20, 0x677b5a, 0x677b5a, 0x604a60}};
  for (u32 k = 0; k < 11; k++) {
    ((Add3)(void *)ext_5f9940)(list, kM[k][0], kM[k][1], kM[k][2]);
    if (list[0xc]) {
      u32 n = G(u32, 0x724768);
      if (n < 50) {
        G(u32, 0x724770 + 4 * n) = kM[k][3];
        G(u32, 0x724768) = n + 1;
      } else {
        callHook();
      }
    }
  }
  list[0xc] = 0;
  ((Tail1)(void *)ext_5f9b80)(self, list);
}
PCREG(604710, opaqueStringAddMethods);

static void THISCALL scriptItemAddMethods(u8 *self, u8 *list) {
  static const u32 kFn[20] = {0x50bd00, 0x50bf60, 0x50c610, 0x50c360, 0x50bbb0, 0x50cbc0, 0x50c450,
                              0x50cd60, 0x50bab0, 0x50c030, 0x50b9b0, 0x50b860, 0x50c900, 0x50cfd0,
                              0x50cb40, 0x50c290, 0x50c540, 0x50b7f0, 0x50bef0, 0x50c200};
  for (u32 k = 0; k < 20; k++) {
    if (!list[0xc])
      return;
    u32 n = G(u32, 0x7012c8);
    if (n < 50) {
      G(u32, 0x7012d0 + 4 * n) = kFn[k];
      G(u32, 0x7012c8) = n + 1;
    } else {
      ((Warn1)(*(u32 *)(*(u32 *)self + 0x44)))(self, 0x69d408);
      callHook();
    }
  }
}
PCREG(50d190, scriptItemAddMethods);
