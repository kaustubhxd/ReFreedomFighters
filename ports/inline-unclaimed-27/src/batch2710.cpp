#include "ff.h"
// batch2710.cpp - residue-07 entry 0x4a1a70 (GUESS FUN_4a1a70 in core-todo; not in any docs/20 file). Helpers are original code:
// 0x41e290 is cdecl (one argument, the caller cleans), returns a block; 0x4ccba0 is thiscall (ret 0) and returns eax.
extern "C" u8 *ext_41e290(u32 size);
extern "C" u8 *THISCALL ext_4ccba0(u8 *self);

// 0x4a1a70, FUN_4a1a70 (GUESS name; area 27 slice). Thiscall, no arguments, ret 0.
// Gets an object P from the global at 0x70039c (+0x9b, vtable slot +0x138) and asks P (slot +0x88, args 0x68f724 and &local)
// for a pointer x. If x is nonzero and the object K at 0x70038c accepts it (slot +0xcc returns nonzero), a static at 0x7002a8
// is created on first use (0x41e290 then 0x4ccba0, or 0). If this is nonzero and K's slot +0x20 returns zero: K+8 is
// called (thiscall, no arguments) when it is nonzero and K+0xc <= this < K+0x10 (unsigned); otherwise, when the dword at
// this-4 is zero, K's slot +0xac is called with this, and the dword at this-4 is taken. This is zero when this is zero or
// when slot +0x20 returned nonzero. Finally, the static's slot +4 is called with that value.
static void THISCALL zfn4a1a70(u8 *self) {
  typedef u8 *(THISCALL * s138_fn)(u8 *);
  typedef void(THISCALL * s88_fn)(u8 *, u32, u32 *);
  typedef u32(THISCALL * s1arg_fn)(u8 *, u32);
  typedef void(THISCALL * s1argv_fn)(u8 *, u32);
  typedef u32(THISCALL * noarg_fn)(u8 *);

  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *o9 = *(u8 **)(g + 0x9b);
  u8 *p = ((s138_fn)(*(u32 *)(*(u32 *)o9 + 0x138)))(o9);

  u32 local = 0;
  ((s88_fn)(*(u32 *)(*(u32 *)p + 0x88)))(p, 0x68f724u, &local);
  u8 *x = (u8 *)(unsigned long)local;
  if (x == 0) return;

  u8 *k = (u8 *)(unsigned long)G(u32, 0x70038c);
  if (((s1arg_fn)(*(u32 *)(*(u32 *)k + 0xcc)))(k, (u32)(unsigned long)x) == 0) return;

  if (G(u32, 0x7002a8) == 0) {
    u8 *m = ext_41e290(0xac);
    u8 *c = m ? ext_4ccba0(m) : 0;
    G(u32, 0x7002a8) = (u32)(unsigned long)c;
  }

  u32 edx;
  if (self == 0) {
    edx = 0;
  } else {
    k = (u8 *)(unsigned long)G(u32, 0x70038c);
    if (((s1arg_fn)(*(u32 *)(*(u32 *)k + 0x20)))(k, (u32)(unsigned long)self) != 0) {
      edx = 0;
    } else {
      k = (u8 *)(unsigned long)G(u32, 0x70038c);
      u32 fnp = *(u32 *)(k + 8);
      if (fnp != 0 && !(*(u32 *)(k + 0xc) > (u32)(unsigned long)self) && ((u32)(unsigned long)self < *(u32 *)(k + 0x10))) {
        edx = ((noarg_fn)fnp)(self);
      } else {
        if (*(u32 *)(self - 4) == 0) {
          ((s1argv_fn)(*(u32 *)(*(u32 *)k + 0xac)))(k, (u32)(unsigned long)self);
        }
        edx = *(u32 *)(self - 4);
      }
    }
  }

  u8 *s = (u8 *)(unsigned long)G(u32, 0x7002a8);
  ((s1argv_fn)(*(u32 *)(*(u32 *)s + 4)))(s, edx);
}
PCREG(4a1a70, zfn4a1a70);
