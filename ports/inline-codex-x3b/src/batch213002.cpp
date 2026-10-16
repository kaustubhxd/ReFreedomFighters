#include "ff.h"

// 0x5af040: stdcall(int sel) ret 4: map sel-3 (0..8) to a small code, default 8
u32 STDCALL fn_5af040(int sel) {
  u32 i = (u32)sel - 3;
  if (i > 8) return 8;
  switch (i) {
    case 0: return 0;
    case 1: return 6;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 5: return 4;
    case 6: return 8;
    case 7: return 7;
    default: return 5;
  }
}
PCREG(5af040, fn_5af040);

// 0x486bb0: thiscall(this, sel) ret 4: field by selector 1..7, else the assert hook [0x7003b0] (int3 when null)
u32 THISCALL fn_486bb0(u8 *self, int sel) {
  u32 i = (u32)sel - 1;
  if (i > 6) {
    typedef u32 (*Hook)();
    Hook h = G(Hook, 0x7003b0);
    if (!h) __builtin_trap();
    return h();
  }
  switch (i) {
    case 0: return *(u32 *)(self + 0x10);
    case 1: return *(u32 *)(self + 0x14);
    case 2: return *(u32 *)(self + 0x18);
    case 3: return *(u32 *)(self + 0x1c);
    case 4: return *(u32 *)(self + 0x24);
    case 5: return *(u32 *)(self + 0x20);
    default: return *(u32 *)(self + 0x28);
  }
}
PCREG(486bb0, fn_486bb0);
