// batch525.cpp - weapons thread, batch 525: ZLNKWHANDS::AddNearItem (items in reach for pickup).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);
extern "C" void *ext_41e290(u32 size);                              // operator new (cdecl)
extern "C" void *THISCALL ext_4ccbe0(void *t, u32 n, u32 z);        // REFTAB::REFTAB(int, int), returns this

// 0x4720f0 AddNearItem(handle): creates the near-items list on first use (a 0x1c-byte REFTAB(4, 0)); an object whose
// geom is inactive (bit 10 of flags) is refused with "Trying to add inactive object %s" (zlnkwhands.cpp line 0x14e);
// otherwise the handle is added (list slot 0x4).
static void THISCALL addNearItem(u8 *s, u32 h) {
  if (!*(u32 *)(s + 0x3b7)) {
    void *p = ext_41e290(0x1c);
    *(u32 *)(s + 0x3b7) = p ? (u32)ext_4ccbe0(p, 4, 0) : 0;
  }
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *g = (u8 *)((vUU)VT(rm, 0x58))(rm, h);
  if ((*(u32 *)(*(u8 **)(g + 8) + 0x3c) >> 10) & 1) {
    u8 *l = G(u8 *, 0x700390);
    void *st = ((vLogLine)VT(l, 0x20))(l, (const char *)0x68961c, 0x14e);
    const char *nm = *(const char **)(g + 4);
    ((logPrintf)VT(st, 0x2c))(st, (const char *)0x68977c, nm ? nm : (const char *)0x67c8e8);
    return;
  }
  u8 *lst = *(u8 **)(s + 0x3b7);
  ((vUU)VT(lst, 4))(lst, h);
}
PCREG(4720f0, addNearItem);
