// batch939.cpp - vehicles thread, batch 939: ZTank::ClassInit2() (0x520670), thiscall, no arguments.
// The vehicle class init (0x515620) runs first. With a turret geom (+0x25d1): its child lookup (slot 0x25c with
// "*" name 0x6a05c0), the message-forwarding flags (as ZCar::ClassInit, batch 938), then the hull's slot 0x4c and the
// render manager's slot 0x4c on the vehicle, stored at the child's +0x48. Without a turret: an error line
// ("...", line 0xf8) and the hook at 0x7003b0.
// Then, when the turret's flags (+0xc object, +0x23 bit 0x100000) say so: the cannon group (+0x25d5) and the
// machine-gun group (+0x25d9) get weapons (ZMoveOnSpline::CreateWeapon, slot 0x328); the cannon's class 0xb sets +0x260a.
// Finally the undercarriage Init (0x527ee0, stood in), InitTankPosDir (0x520f20, stood in).
// Stood in: 0x515620, 0x527ee0, 0x520f20, 0x512940 (CreateWeapon) and the debug/hook globals.
#include "ff.h"

extern "C" void THISCALL ext_515620(void *self);
extern "C" void THISCALL ext_527ee0(void *uc, void *grp, float f, u32 zero, u32 flag);  // CUnderCarriageTank::Init
extern "C" void THISCALL ext_520f20(void *self, u32 forward);                            // ZTank::InitTankPosDir (stood in)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x520670 ZTank::ClassInit2().
static void THISCALL tankClassInit2(u8 *s) {
  ext_515620(s);
  u32 turret = *(u32 *)(s + 0x25d1);
  if (turret) {
    u8 *t = (u8 *)vcall<u32>((void *)turret, 0x25c, 0x6a05c0u, 0u);
    u8 *y = (u8 *)vcall<u32>(t, 0x10c, 0x68f47cu, 0xffffffffu);
    u8 *edi = y;
    if (!(y[4] & 1)) {
      vcall<void>(y, 8);
      y[4] |= 4;
    }
    if (y[4] & 1) {
      vcall<void>(y, 0x4c);
      vcall<void>(y, 0x54, *(u32 *)(y + 0x30));
      *(u32 *)(y + 4) |= 0x100;
      edi = 0;
    }
    u32 r = vcall<u32>(*(void **)(sysp() + 0x9b), 0x4c, (u32)s);
    if (edi)
      *(u32 *)(edi + 0x48) = r;
    else
      *(u32 *)0x48 = r;   // the exe writes through the null pointer here (never reached with a valid child)
  } else {
    void *dbg = *(void **)0x700390;
    typedef void *(THISCALL * at)(void *, const char *, u32);
    typedef void(CDECL_FN)(void *, const char *, const char *);
    void *o = (*(at *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x6a04a8, 0xf8u);
    u32 nm = *(u32 *)(s + 4);
    ((CDECL_FN *)(*(u32 **)o)[0x2c / 4])(o, (const char *)0x6a05c8, nm ? (const char *)nm : (const char *)0x67c8e8);
    void (*hook)(void) = *(void (**)(void))0x7003b0;
    if (!hook)
      __builtin_trap();
    hook();
  }
  u8 *T = (u8 *)*(u32 *)(s + 0x25d1);
  u8 *flags = *(u8 **)(T + 0xc);
  if (*(u32 *)(flags + 0x23) & 0x100000) {
    if (*(u32 *)(s + 0x25d5))
      *(u32 *)(s + 0x25dd) = vcall<u32>(s, 0x328, *(u32 *)(s + 0x25d5), (u32)T, 0x5447756eu);
    if (*(u32 *)(s + 0x25d9))
      *(u32 *)(s + 0x25e1) = vcall<u32>(s, 0x328, *(u32 *)(s + 0x25d9), *(u32 *)(s + 0x25d1), 0x5443616eu);
    u32 w = *(u32 *)(s + 0x25e1);
    if (w) {
      u32 cls = vcall<u32>((void *)vcall<u32>((void *)w, 0x350), 0x330);
      if (cls == 0xb)
        s[0x260a] = 1;
    }
  }
  ext_527ee0(s + 0x2fd, s, F(s, 0x25cd), 0u, (u32)s[0x133]);
  ext_520f20(s, 1u);
}
PCREG(520670, tankClassInit2);
