// batch882.cpp - area 50 (residue-09 file row): 0x4abf90 [132 instr, thiscall, two stack args (a record, a name), ret 8, returns
// bool; GUESS "walk the record's list (+0x50, next +0x60): for each entry with flag bit 0x100000 in its info, match the name, then
// run the manager's slot 0x4c / the entry's slot 0x340 / the Z sub-object's slots 0x4c and 0x5c (loop over the manager's lookup
// 0x58), or call the entry's slot 0x88 on the stale this"]. The exe's 0x4acf30 is an SEH-framed routine: stood in (its result is
// unused). Two notes from the disassembly, kept on purpose: (1) the exe reuses EBX as the result of the entry's 0x340 call, so a
// later branch calls slot 0x88 on that value (stale this, modelled by the `ebx` variable); (2) the Z object is this+0x11a (its
// vtable pointer is stored there).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_4db9a0(void *obj, u32 flag);     // predicate (stood in); ret 4
extern "C" void THISCALL ext_4acf30(void *obj, u32 v);        // SEH-framed routine (stood in); ret 4

// 0x4abf90 (name GUESS).
static bool THISCALL Walk4abf90(u8 *self, u8 *p, u32 a2) {
  u8 *ebx = self;                 // the exe's EBX (this, later reused for a result)
  u32 loc = 0;                    // [ebp-0x10]
  u8 *S = (u8 *)FP(p, 0x50);
  for (; S; S = (u8 *)FP(S, 0x60)) {
    u32 flags = (FP(S, 0x54) ? U32(FP(FP(S, 0x54), 0xc), 0x23) : 0x200002u);
    if (!(flags & 0x100000u)) return false;
    if (ext_4db9a0(S, 0x1007d3u)) {
      u8 *t = (u8 *)FP(S, 0x54);
      const char *name = FP(t, 4) ? (const char *)FP(t, 4) : (const char *)0x67c8e8;
      int cmp = ((int (*)(const char *, const char *))G(u32, 0x676414))(name, (const char *)a2);
      if (cmp != 0) continue;
      u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
      u32 r0 = vcall<u32>(mgr, 0x4c, t);
      ext_4acf30(ebx, r0);
      if (!ext_4db9a0(S, 0x1007d4u)) return true;
      u32 r = vcall<u32>(t, 0x340, 0u);
      ebx = (u8 *)r;
      u8 *Z = self + 0x11a;
      if (Z != 0) {                       // add edi,0x11a / je: a zero address skips the loop
        vcall<void>(Z, 0x4c, (void *)&loc);
        u32 e = vcall<u32>(Z, 0x5c, (void *)&loc);
        while (loc) {
          u8 *T = vcall<u8 *>(mgr, 0x58, e);
          if (T) {
            bool ok = vcall<bool>(T, 0x1e0, 0x1007d8u);
            if (ok && vcall<u32>(T, 0x2e8) == (u32)ebx) return true;
          }
          e = vcall<u32>(Z, 0x5c, (void *)&loc);
        }
      }
      u32 r2 = vcall<u32>(mgr, 0x4c, ebx);
      ext_4acf30(self, r2);
      return true;
    } else {
      if (ext_4db9a0(S, 0x100001u)) vcall<void>(ebx, 0x88, FP(S, 0x54), a2);
    }
  }
  return false;
}
PCREG(4abf90, Walk4abf90);
