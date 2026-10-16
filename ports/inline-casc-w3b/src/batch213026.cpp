#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
extern "C" u32 THISCALL ext_4870b0(void *self, u32 v);

// 0x471ff0: thiscall(this, a, b) ret 8: looks b up through the engine table slot 0x58, then for a in 1..15 gets an object from this->[0x3ec](a),
// stores the lookup result in it (0x4870b0) unless a is 5, 6 or 9..15, and hands it to this->[0x3d8]; other a runs the assert hook and
// passes b itself to slot 0x3d8. Returns the slot 0x3d8 result.
u32 THISCALL fn_471ff0(u8 *self, u32 a, u32 b) {
  u8 *eng = G(u8 *, 0x70039c);
  void *tab = *(void **)(eng + 0x9b);
  u32 r = (*(V1 *)(*(u8 **)tab + 0x58))(tab, b);
  u32 i = a - 1;
  if (i > 0xe) {
    typedef u32 (*Hook)();
    Hook h = G(Hook, 0x7003b0);
    if (!h) __builtin_trap();
    h();
    return (*(V1 *)(*(u8 **)self + 0x3d8))(self, b);
  }
  u32 o = (*(V1 *)(*(u8 **)self + 0x3ec))(self, a);
  static const u8 setv[15] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
  if (setv[i]) ext_4870b0((void *)o, r);
  return (*(V1 *)(*(u8 **)self + 0x3d8))(self, o);
}
PCREG(471ff0, fn_471ff0);

typedef u32(THISCALL *V0)(void *);
extern "C" u32 THISCALL ext_565020(void *self, u32 a, u32 flag);
extern "C" u32 THISCALL ext_564600(void *self, u32 a);
extern "C" u32 THISCALL ext_565100(void *self, u32 a);
extern "C" u32 THISCALL ext_56c6a0(void *self);
extern "C" u32 THISCALL ext_56b460(void *self, u32 a);

// 0x56c5a0: thiscall(this, a, flag) ret 8: forwards to 0x565020, then with flag set reads the pointer-owner's state (slot 0x34 into +0xcea)
// and acts on the mode at +0xcee (0..5); without it finishes mode 1 and calls slot 0x104. Always returns with the low byte of eax cleared.
u32 THISCALL fn_56c5a0(u8 *self, u32 a, u32 flag) {
  u32 r;
  ext_565020(self, a, flag);
  if ((u8)flag) {
    void *o = *(void **)(self + 0xc5e);
    *(u32 *)(self + 0xcea) = (*(V0 *)(*(u8 **)o + 0x34))(o);
    u32 mode = *(u32 *)(self + 0xcee);
    switch (mode) {
      case 0: r = ext_564600(self, 8); break;
      case 1:
      case 2: r = ext_564600(self, 1); break;
      case 3: {
        void *o2 = *(void **)(self + 0xc5e);
        u32 x = (*(V0 *)(*(u8 **)o2 + 0x3c))(o2);
        r = (u8)x ? ext_564600(self, 8) : ext_564600(self, 0);
        break;
      }
      case 4: r = ext_565100(self, 0x15); break;
      case 5: r = ext_565100(self, 0x18); break;
      default: r = mode; break;
    }
    return r & ~0xffu;
  }
  if (*(u32 *)(self + 0xcee) == 1) {
    ext_56c6a0(self);
    ext_56b460(self, *(u32 *)(self + 0xce2));
  }
  r = (*(V0 *)(*(u8 **)self + 0x104))(self);
  return r & ~0xffu;
}
PCREG(56c5a0, fn_56c5a0);
