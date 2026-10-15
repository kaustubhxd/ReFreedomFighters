// batch94000.cpp - hard trial opus 4: 0x570cb0, a mission-select handler with a 9-way jump table.
#include "ff.h"

extern "C" u8 THISCALL ext_5b1000(void *, const char *);    // thiscall, ret 4: test on the profile block (+0x50f)
extern "C" u8 THISCALL ext_5b1440(void *, void *);          // thiscall, ret 4
extern "C" void THISCALL ext_59cb60(void *, const char *);  // thiscall, ret 4: select level by name
extern "C" void THISCALL ext_4947c0(void *, int);           // thiscall, ret 4
extern "C" u8 THISCALL ext_561be0(void *);
extern "C" void THISCALL ext_562bc0(void *);

// 0x570cb0 (thiscall, no args, /GS frame). this+0x94 = game/profile block; block[0x4a] = mission digit ('1'..'9').
// If neither profile check passes, load "C09R" with its third character replaced by the digit (unless it is '8').
// Otherwise the digit picks a level name from a jump table ('9' = MENU, plus 0x4947c0(6) on the engine table object).
// Then, unless 0x561be0 says so, notify the engine table (slot 0xb4), the optional object at engine+0x1a9f (slot 0x138) and call 0x562bc0.
static void THISCALL MissionSelect_570cb0(u8 *self) {
  u8 *blk = *(u8 **)(self + 0x94);
  if (!ext_5b1000(blk + 0x50f, (const char *)0x6a7924)) {
    u8 *b2 = *(u8 **)(self + 0x94);
    if (!ext_5b1440(b2 + 0x50f, b2 + 0x48)) {
      volatile char name[5];
      *(volatile u32 *)name = G(u32, 0x6a774c);   // "C09R"
      name[4] = G(u8, 0x6a7750);
      u8 d = blk[0x4a];
      if (d != 0x38)
        name[2] = d;
      ext_59cb60(*(void **)(self + 0x94), (const char *)name);
      goto tail;
    }
  }
  switch ((s8)blk[0x4a]) {
  case '1': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87bc); break;   // "MC01B"
  case '2': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87c4); break;   // "MC02"
  case '3': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87cc); break;   // "MC03"
  case '4': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87d4); break;   // "MC05"
  case '5': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87dc); break;   // "RB06"
  case '6': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87e4); break;   // "MC06"
  case '7': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87ec); break;   // "MC07"
  case '8': ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a87f4); break;   // "MC10"
  case '9':
    ext_59cb60(*(void **)(self + 0x94), (const char *)0x6a7744);                 // "MENU"
    ext_4947c0(*(void **)((u8 *)g_pSysInterface + 0x9b), 6);
    break;
  }
tail:
  if (!ext_561be0(self)) {
    vcall<void>(*(void **)((u8 *)g_pSysInterface + 0x9b), 0xb4, 0);
    void *o = *(void **)((u8 *)g_pSysInterface + 0x1a9f);
    if (o)
      vcall<void>(o, 0x138, 0);
    ext_562bc0(self);
  }
}
PCREG(570cb0, MissionSelect_570cb0);
