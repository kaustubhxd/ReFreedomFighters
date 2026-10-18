#include "ff.h"

extern "C" u32 THISCALL ext_4f9680(void *self, u32 a);
extern "C" u32 THISCALL ext_5ab230(void *self, u32 a);
extern "C" u32 THISCALL ext_5ab2a0(void *self, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x5e9b70: thiscall(this): reads the mode dword at P+0x3c2 (P = [this+0x1d0f]) and, per mode 0..8, one of the pointer-like fields of the 0x45-byte block
// at P+0x37d (copied to a local first), notifying through 0x5ab230(P, arg) / 0x5ab2a0(P, 0x677b5a); stores the mode at this+0x1d47 and returns the field
u32 THISCALL fn_5e9b70(u8 *self) {
  u8 *P = *(u8 **)(self + 0x1d0f);
  u8 loc[0x45];
  __builtin_memcpy(loc, P + 0x37d, 0x45);
  u32 m0 = rd32u(P + 0x3c2);
  if (m0 != rd32u(self + 0x1d47) && m0 != 8) ext_4f9680((void *)0x700e24, 0);
  P = *(u8 **)(self + 0x1d0f);
  u32 m = rd32u(P + 0x3c2);
  u32 esi = 0;
  bool none = false;   // true: finish through the 0x5ab2a0 notification
  bool call = false;   // true: finish through the 0x5ab230 notification with arg
  u32 arg = 0;
  if (m > 8) {
    none = true;
  } else {
    switch (m) {
      case 0:
        arg = rd32u(loc + 4);
        if (arg == 0) { none = true; break; }
        esi = rd32u(loc + 0x29);
        call = true;
        break;
      case 1: esi = rd32u(loc + 0x35); none = true; break;
      case 2:
        esi = rd32u(loc + 0x3d);
        if (esi == 0) { none = true; break; }
        arg = rd32u(loc + 0x15);
        call = true;
        break;
      case 3:
        esi = rd32u(loc + 0x25);
        if (esi == 0) { none = true; break; }
        arg = rd32u(loc + 0);
        call = true;
        break;
      case 4:
        arg = rd32u(loc + 0xc);
        if (arg == 0) { none = true; break; }
        esi = rd32u(loc + 0x31);
        call = true;
        break;
      case 5: esi = rd32u(loc + 0x41); none = true; break;
      case 6:
        esi = rd32u(loc + 0x39);
        if (esi == 0) { none = true; break; }
        if (rd32u(loc + 0x1d) == 2) { none = true; break; }
        arg = rd32u(loc + 0x19);
        call = true;
        break;
      case 7:
        esi = rd32u(loc + 0x2d);
        if (esi == 0) { none = true; break; }
        arg = rd32u(loc + 8);
        call = true;
        break;
      default:
        ext_5ab2a0(P, 0x677b5a);
        return 0;
    }
  }
  if (call) ext_5ab230(P, arg);
  else if (none) ext_5ab2a0(P, 0x677b5a);
  P = *(u8 **)(self + 0x1d0f);
  *(u32 *)(self + 0x1d47) = rd32u(P + 0x3c2);
  return esi;
}
PCREG(5e9b70, fn_5e9b70);
