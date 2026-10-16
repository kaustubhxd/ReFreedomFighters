#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);
extern "C" u32 THISCALL ext_562c20(void *self, u32 sel);
extern "C" u32 THISCALL ext_56d280(void *self);

// 0x56cef0: thiscall(this, sel) ret 4: state change request; 2/4 -> slot 0x9c(0x103), 3 -> 0x56d280, 5 -> engine slot 0x114 lookup and
// notifications unless [this+0x1be] == 3; always ends in 0x562c20(this, sel) unless slot 0xd8 says busy
u32 THISCALL fn_56cef0(u8 *self, u32 sel) {
  u8 *vt = *(u8 **)self;
  u32 busy = (*(V0 *)(vt + 0xd8))(self);
  if ((u8)busy) return busy & ~0xffu;
  switch (sel) {
    case 2:
    case 4:
      (*(V1 *)(*(u8 **)self + 0x9c))(self, 0x103);
      return ext_562c20(self, sel);
    case 3:
      ext_56d280(self);
      return ext_562c20(self, sel);
    case 5:
      if (*(u32 *)(self + 0x1be) != 3) {
        u8 *o = *(u8 **)(self + 0x44);
        u8 *ovt = *(u8 **)o;
        u8 *eng = G(u8 *, 0x70039c);
        void *tab = *(void **)(eng + 0x9b);
        u32 r = (*(V5 *)(*(u8 **)tab + 0x114))(tab, 0x6a6ffc, 0, 0x6a8040, 0xbe, (u32)(self + 0x1be));
        (*(V2 *)(ovt + 0x12c))(o, *(u32 *)(self + 0x188), (u16)r);
        (*(V1 *)(*(u8 **)self + 0xd0))(self, *(u32 *)(self + 0x188));
      }
      return ext_562c20(self, sel);
    default:
      return ext_562c20(self, sel);
  }
}
PCREG(56cef0, fn_56cef0);
