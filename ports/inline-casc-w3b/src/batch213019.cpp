#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V2p)(void *, const char *, volatile u32 *);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, volatile u32 *);
extern "C" u32 THISCALL ext_562c20(void *self, u32 sel);
extern "C" u32 THISCALL ext_5f5620(void *self, u32 a);
extern "C" u32 THISCALL ext_5fa1e0(void *self, u32 a);

// 0x562c90: thiscall(this, sel) ret 4: sibling of 0x56cef0: busy check, then engine slot 0x138 object's slot 0x88(str, &out), and for sel 1..4
// the engine slot 0x114 lookup (writes a code 0..3) with the sub-object notifications; always returns al = 1 there, else 0x562c20(this, sel)
u32 THISCALL fn_562c90(u8 *self, u32 sel) {
  u32 busy = (*(V0 *)(*(u8 **)self + 0xd8))(self);
  if ((u8)busy) return busy & ~0xffu;
  u8 *eng = G(u8 *, 0x70039c);
  void *tab = *(void **)(eng + 0x9b);
  u8 *o = (u8 *)(*(V0 *)(*(u8 **)tab + 0x138))(tab);
  volatile u32 out = 0;
  (*(V2p *)(*(u8 **)o + 0x88))(o, (const char *)0x6a6860, &out);
  u32 i = sel - 1;
  if (i > 3) return ext_562c20(self, sel);
  volatile u32 code = i;
  u8 *o44 = *(u8 **)(self + 0x44);
  u8 *ovt = *(u8 **)o44;
  u8 *eng2 = G(u8 *, 0x70039c);
  void *tab2 = *(void **)(eng2 + 0x9b);
  u32 r = (*(V5 *)(*(u8 **)tab2 + 0x114))(tab2, 0x6a6868, 0, 0x6a64b4, 0x731, &code);
  (*(V2 *)(ovt + 0x12c))(o44, out, (u16)r);
  u32 d = (*(V1 *)(*(u8 **)self + 0xd0))(self, out);
  return (d & ~0xffu) | 1;
}
PCREG(562c90, fn_562c90);

// 0x605940: thiscall(this, a, b, c) ret 0xc: reads a kind byte from object a (slot 0x5c with an out slot), stores it at this+4 and acts on it
u32 THISCALL fn_605940(u8 *self, u8 *a, u32 b, u32 c) {
  volatile u32 slot = (u32)a;
  (*(V1 *)(*(u8 **)a + 0x5c))(a, (u32)&slot);
  u32 k = (u8)slot;
  self[4] = (u8)slot;
  switch (k) {
    case 0: *(u32 *)self = 0; return 0;
    case 1: return (*(V1 *)(*(u8 **)a + 0x60))(a, (u32)self);
    case 2: return (*(V1 *)(*(u8 **)a + 0x64))(a, (u32)self);
    case 3: {
      (*(V1 *)(*(u8 **)a + 0x5c))(a, (u32)&slot);
      if (c) {
        u32 r = ext_5f5620((void *)c, slot);
        *(u32 *)self = r;
        return r;
      }
      typedef u32 (*Hook)();
      Hook h = G(Hook, 0x7003b0);
      if (!h) __builtin_trap();
      return h();
    }
    case 4: {
      (*(V1 *)(*(u8 **)a + 0x5c))(a, (u32)&slot);
      u32 r = ext_5fa1e0((void *)b, slot);
      *(u32 *)self = r;
      return r;
    }
    default: return k;
  }
}
PCREG(605940, fn_605940);
