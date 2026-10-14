// batch36000.cpp - cascade s4 batch 36000: 0x435c90, 0x427900, 0x41f8f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *vcall1_t)(void *, u32);

// 0x435c90, thiscall(no args): three loops over pointer arrays, each calling slot 0x24 of the element with a byte from the engine object.
// The pushed argument is a stack dword whose low byte is the engine byte and whose upper bytes are the original ECX (this) upper bytes.
//   [this+0xc] elems at this+4 use eng[0x6e]; [this+0x1c] elems at this+0x10 use eng[0x6d]; [this+0x60] elems at this+0x20 use eng[0x6c].
static void THISCALL fn435c90(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u32 hi = (u32)self & 0xffffff00u;
  u32 n = *(u32 *)(self + 0xc);
  u32 arg = hi | eng[0x6e];
  for (u32 i = 0; i < n; i++) {
    void *o = *(void **)(self + 4 + 4 * i);
    (*(vcall1_t **)o)[0x24 / 4](o, arg);
    n = *(u32 *)(self + 0xc);
  }
  arg = hi | eng[0x6d];
  n = *(u32 *)(self + 0x1c);
  for (u32 i = 0; i < n; i++) {
    void *o = *(void **)(self + 0x10 + 4 * i);
    (*(vcall1_t **)o)[0x24 / 4](o, arg);
    n = *(u32 *)(self + 0x1c);
  }
  arg = hi | eng[0x6c];
  n = *(u32 *)(self + 0x60);
  for (u32 i = 0; i < n; i++) {
    void *o = *(void **)(self + 0x20 + 4 * i);
    (*(vcall1_t **)o)[0x24 / 4](o, arg);
    n = *(u32 *)(self + 0x60);
  }
}
PCREG(435c90, fn435c90);

typedef void(THISCALL *vcall3_t)(void *, void *, u32, u32);
typedef u32(THISCALL *vcall2r_t)(void *, u32, u32);
typedef u32(THISCALL *vcall4_t)(void *, void *, u32, u32, u32, u32);
typedef u8 *(THISCALL *vcall2o_t)(void *, u32, u32);

// 0x427900, thiscall(a, b, c) ret 0xc, returns bool in al.
// buf[0x400]; this->slot 0x144(buf, b, c); i = this->slot 0xe0(b, c); if i == -1 return 0;
// r = [0x700394]->slot 0x60(buf, a, i, 0, 0); if r == -1: log through [0x700390] (slot 0x20 (file 0x6789ac, line 0x3e6) then slot 0x2c cdecl); return r != -1.
static u8 THISCALL fn427900(u8 *self, u32 a, u32 b, u32 c) {
  u8 buf[0x400];
  (*(vcall3_t **)self)[0x144 / 4](self, buf, b, c);
  u32 i = (*(vcall2r_t **)self)[0xe0 / 4](self, b, c);
  if (i == 0xffffffffu) return 0;
  u8 *e2 = G(u8 *, 0x700394);
  u32 r = (*(vcall4_t **)e2)[0x60 / 4](e2, buf, a, i, 0, 0);
  if (r == 0xffffffffu) {
    u8 *db = G(u8 *, 0x700390);
    u8 *o = (*(vcall2o_t **)db)[0x20 / 4](db, 0x6789acu, 0x3e6u);
    void **vt2 = *(void ***)o;
    void *fn = *(void **)((u8 *)vt2 + 0x2c);
    __asm__ volatile("pushl %[s]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                     : "+c"(vt2)
                     : [s] "i"(0x678d10), [o] "r"(o), [f] "r"(fn)
                     : "eax", "edx", "memory", "cc");
    return 0;
  }
  return 1;
}
PCREG(427900, fn427900);

typedef u32(STDCALL *isbad_t)(u32, u32);
typedef void(*vcall6c_t)(void *, u8 *, u32, u32, u32, u32);

// 0x41f8f0, stdcall(a: char*, b: u8*) ret 8: s = a ++ the 42 bytes at 0x677460 (stack buffer 0x204);
// if IsBadReadPtr(b[8], 8): engine([0x700390])->slot 0x34 cdecl(eng, s, 0x67748c, b[0xc], b[0x14], b[0x18] & 0x1fffffff), else the same with b[8] for 0x67748c.
static void STDCALL fn41f8f0(const u8 *a, u8 *b) {
  u8 buf[0x204];
  u8 *d = buf;
  while ((*d = *a) != 0) { d++; a++; }
  const u8 *s = (const u8 *)0x677460;
  for (int k = 0; k < 42; k++) d[k] = s[k];
  u32 bad = G(isbad_t, 0x6760d0)(*(u32 *)(b + 8), 8);
  u8 *eng = G(u8 *, 0x700390);
  void **vt = *(void ***)eng;
  vcall6c_t fn = (vcall6c_t)vt[0x34 / 4];
  u32 x = bad ? 0x67748cu : *(u32 *)(b + 8);
  fn(eng, buf, x, *(u32 *)(b + 0xc), *(u32 *)(b + 0x14), *(u32 *)(b + 0x18) & 0x1fffffffu);
}
PCREG(41f8f0, fn41f8f0);
