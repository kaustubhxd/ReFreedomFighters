// batch307.cpp - ZGROUP::GetStaticLights(ZBaseGeom **out, ZBaseGeom **end) (area 43, 2026-10-12). 0x440c20.
// GC 80163 2c4 (name map, high). thiscall (this = ECX), two stack arguments, ret 8, returns the cursor (eax).
// The iterator T = {node, cur, marker} is filled by 0x440ce0 (original exe code, thiscall, one stack argument: the head
// at this+0x48). Entries are 8-byte pairs (value, flags) starting at cur; a pair is copied to the output when the low
// three bits of flags are 2 (both words masked with ~7). The chain advances through nodes whose flag byte has bit 0 set
// (next pointer at +0xc, entries from +0x10); a node with bit 0 clear ends the walk.
// Frame: none beyond the iterator (the exe's [ebp+8] slot is reused as the marker; the port keeps it in a variable).
#include "ff.h"

#define AT(a) ((u8 *)(unsigned long)(a))
#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U8(p, off) (*(u8 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_440ce0(u32 *t, u32 head);   // iterator setup (ecx = T, stack head, ret 4)

static u32 *THISCALL zgroupGetStaticLights(u8 *self, u32 *out, u32 end) {
  u32 t[3];
  ext_440ce0(t, U32(self, 0x48));
  u32 esi = (u32)(unsigned long)out;
  u32 edx = t[1];
  if (edx == 0)
    return (u32 *)(unsigned long)esi;
  u32 ecx = t[0];
  u32 marker = t[2];
  for (;;) {
    u32 edi = U32(AT(edx), 4);
    u32 al = edi & 7;
    u32 ebx = U32(AT(edx), 0) & ~7u;
    edx += 8;
    if (al == 2) {
      if (end <= esi)
        return (u32 *)(unsigned long)esi;
      edi &= ~7u;
      U32(AT(esi), 0) = ebx;
      U32(AT(esi), 4) = edi;
      esi += 8;
    }
    if (edx == marker) {
      if (ecx == 0)
        return (u32 *)(unsigned long)esi;
      if (!(U8(AT(ecx), 8) & 1))
        return (u32 *)(unsigned long)esi;
      for (;;) {
        ecx = U32(AT(ecx), 0xc);
        if (ecx == 0)
          return (u32 *)(unsigned long)esi;
        if (U8(AT(ecx), 8) >= 2)
          break;
        if (!(U8(AT(ecx), 8) & 1))
          return (u32 *)(unsigned long)esi;
      }
      u32 flag = U8(AT(ecx), 8);
      u32 ed = ecx + 0xc;
      if (flag & 1)
        ed += 4;
      marker = ecx + (flag + 3) * 4;
      edx = ed;
    }
    if (edx == 0)
      return (u32 *)(unsigned long)esi;
  }
}
PCREG(440c20, zgroupGetStaticLights);
