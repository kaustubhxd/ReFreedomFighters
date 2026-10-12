// batch6223.cpp - unclaimed-62 claim 16 (larger, 100 instructions): 0x4d9090 [thiscall, two arguments, ret 8].
// SEH frame not reproduced (the exe's fs:[0] try frame around the body).
// Helper 0x4d8db0 (stdcall, two arguments) gives r. Slot 0x34 of this's object (with r) gives esi. If esi is 0: a 0x28-byte block is
// allocated (0x41e290, cdecl) and 0x4cca60 (thiscall, 4 then 2) initialises it; the object's slot 0x2c gets (r, esi); the result is
// slot 4 of esi (with 0) minus 4. If esi is not 0: 0x4d8ef0 (thiscall, esi, p1, p2) gives edi; edi 0 -> slot 4 of esi (with 0) minus 4;
// otherwise, when this+4 is 0, edi's pointee is freed (0x634273, cdecl, size 0), the pointee is set to 0 and edi is returned.
#include "ff.h"

extern "C" u32 STDCALL ext_4d8db0(u32 a, u32 b);                              // exe: two stack arguments (stdcall)
extern "C" u32 THISCALL ext_4d8ef0(void *self, u32 a, u32 b, u32 c);          // exe: three stack arguments (ret 0xc)
extern "C" u32 THISCALL ext_4cca60(void *self, u32 a, u32 b);                 // exe: two stack arguments (ret 8)
extern "C" void *ext_41e290(u32 size);                                        // exe: operator new (cdecl)
extern "C" void ext_634273(void *p, u32 size);                                // exe: sized free (cdecl)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u32 THISCALL fn4d9090(u8 *self, u32 p1, u32 p2) {
  u32 r = ext_4d8db0(p1, p2);
  u32 esi = vcall<u32>(rdp(self), 0x34, r);
  if (esi == 0) {
    void *np = ext_41e290(0x28);
    u32 blk = np ? ext_4cca60(np, 4, 2) : 0;
    vcall<void>(rdp(self), 0x2c, r, blk);
    return vcall<u32>((u8 *)blk, 4, (u32)0) - 4;
  }
  u32 edi = ext_4d8ef0(self, esi, p1, p2);
  if (edi == 0) return vcall<u32>((u8 *)esi, 4, edi) - 4;
  if (self[4] == 0) ext_634273((void *)rd32u((const u8 *)edi), 0);
  wr32u((u8 *)edi, 0);
  return edi;
}
PCREG(4d9090, fn4d9090);
