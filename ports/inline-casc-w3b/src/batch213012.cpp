#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" u32 THISCALL ext_663a40(void *self, u32 a);
extern "C" u32 THISCALL ext_663520(void *self, u32 a);
extern "C" u32 THISCALL ext_6639a0(void *self, u32 a);
extern "C" u32 THISCALL ext_5adea0(void *self);
extern "C" u32 THISCALL ext_663250(void *self, u32 a);
extern "C" u32 THISCALL ext_5af350(void *self, u32 a);
extern "C" u32 THISCALL ext_5af1d0(void *self, u32 a);
extern "C" u32 THISCALL ext_5af5b0(void *self, u32 *a, u32 *b, u32 c);
extern "C" u32 THISCALL ext_563610(void *self, u32 a);
extern "C" u32 THISCALL ext_563750(void *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_563510(void *self, u32 a);

static inline u32 rd32u(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x663300: thiscall(this, sel, x) ret 8: dispatch on sel 0..8
u32 THISCALL fn_663300(u8 *self, u32 sel, u32 x) {
  if (sel <= 8) {
    switch (sel) {
      case 0: case 8: return ext_663a40(self, x);
      case 1: return ext_663520(self, 1);
      case 2: return ext_663520(self, 0);
      case 3: return ext_663250(self, ext_5adea0(*(void **)(self + 0x12104)));
      case 4: return ext_6639a0(self, x);
      case 5: {
        u8 *eng = G(u8 *, 0x70039c);
        void *tab = *(void **)(eng + 0x9b);
        u32 r = (*(V1 *)(*(u8 **)tab + 0x20))(tab, 1);
        return (r & ~0xffu) | 1;
      }
      default: break;
    }
  }
  void *L = G(void *, 0x700390);
  u8 *M = (u8 *)(*(V2 *)(*(u8 **)L + 0x20))(L, 0x6c4ab4, 0x7b);
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  asm volatile(
      "pushl $0x6c4b30\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $8, %%esp"
      : "+a"(ra), "+c"(rc)
      : [m] "r"(M)
      : "edx", "memory", "cc");
  return ra & ~0xffu;
}
PCREG(663300, fn_663300);

// 0x5afe20: thiscall(this, sel) ret 4: sel 0..0x10 through a byte map
u32 THISCALL fn_5afe20(u8 *self, u32 sel) {
  if (sel > 0x10) return 1;
  static const u8 map[17] = {0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 2, 2, 3, 3, 3, 3, 3};
  switch (map[sel]) {
    case 0: return 1;
    case 1:
    case 2: {
      volatile u32 s = sel;
      u32 tmp;
      ext_5af5b0(self + 0x18, (u32 *)&s, &tmp, map[sel] == 2);
      return s == 0;
    }
    default: {
      u32 b = ext_5af350(self + 0x18, sel);
      u32 v = ext_5af1d0(self, sel);
      if (b >= v) return 0;
      return ext_5af1d0(self, sel) - b;
    }
  }
}
PCREG(5afe20, fn_5afe20);

// 0x56a140: thiscall(this): reset a UI state object
void THISCALL fn_56a140(u8 *self) {
  if (self[0x87] == 0) {
    void *p = *(void **)(self + 0x5c);
    if (p) (*(V0 *)(*(u8 **)p + 0x28))(p);
  }
  u32 sel = *(u32 *)(self + 0x1b8);
  if (sel <= 5) {
    static const u32 args[6] = {0, 0x6a76f8, 0x6a7704, 0x6a6500, 0x6a6c1c, 0x6a7710};
    ext_563610(self, args[sel]);
  }
  ext_563750(self, 3, 1);
  *(u32 *)(self + 0x1b4) = 0xffffffffu;
  ext_563510(self, rd32u(self + 0x1bd));
  if (rd32u(self + 0x1c1) != 0) {
    u8 *eng = G(u8 *, 0x70039c);
    void *tab = *(void **)(eng + 0x9b);
    u8 *o = (u8 *)(*(V0 *)(*(u8 **)tab + 0x138))(tab);
    u8 *vt = *(u8 **)o;
    u8 *eng2 = G(u8 *, 0x70039c);
    void *tab2 = *(void **)(eng2 + 0x9b);
    u32 r = (*(V2 *)(*(u8 **)tab2 + 0x4c))(tab2, *(u32 *)(self + 0x44), 0x10);
    (*(V2 *)(vt + 0x60))(o, rd32u(self + 0x1c1), r);
  }
}
PCREG(56a140, fn_56a140);
