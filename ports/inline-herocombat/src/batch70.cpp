// batch70.cpp - sewer entry helpers, inline session batch 70: ZFFHERO::RestoreItem (0x594590) and SetTempItem
// (0x595010), mmtmul (0x4de4b0), the in-place matrix-by-transposed-matrix product 0x4de4f0 and COpenSewer::ActivateMenu
// (0x5c3860).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u32(THISCALL *vcallUUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVUP)(void *self, u32 a, void *b);
typedef u32(THISCALL *regFn)(void *self, u32 name, u32 a, u32 file, u32 line);
typedef void(THISCALL *sendHFn)(void *self, u32 target, u32 cmd, void *data);    // ZGEOM::SendCommand(handle, cmd, data)
typedef void(THISCALL *sendGFn)(void *self, void *target, u32 cmd, void *data);  // ZGEOM::SendCommand(geom, cmd, data)
typedef void *(*logFn)(void *log, u32 fmt);                                       // cdecl, variadic in the exe
typedef void (*voidFn)();

extern "C" u32 THISCALL ext_591e50(u8 *hero, u32 type);                          // ZFFHERO::GetItem (batch 49)
extern "C" void FASTCALL ext_459fc0(float *dst, const float *v, const float *m);  // vmtmul(dst, v, m)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                    // vmtmul(v, m) in place

static u8 *sys() { return G(u8 *, 0x70039c); }
static u8 *rmgr() { return *(u8 **)(sys() + 0x9b); }

// 0x594590 ZFFHERO::RestoreItem(), thiscall. With a temporary item active (flag 0x20 of +0x836): the saved item
// (+0x832) goes back into the hand (drop the link action, slot 0x3dc, then slot 0x480) and is forgotten. With none
// saved, a hand item (slot 0x504) is replaced by nothing the same way. The flag is cleared either way.
static void THISCALL restoreItem(u8 *self) {
  if (!(*(u32 *)(self + 0x836) & 0x20))
    return;
  if (*(u32 *)(self + 0x832)) {
    ((vcallV0)VT(self, 0x3dc))(self);
    ((vcallVU)VT(self, 0x480))(self, *(u32 *)(self + 0x832));
    *(u32 *)(self + 0x836) &= ~0x20u;
    *(u32 *)(self + 0x832) = 0;
    return;
  }
  if (((vcallU0)VT(self, 0x504))(self)) {
    ((vcallV0)VT(self, 0x3dc))(self);
    ((vcallVU)VT(self, 0x480))(self, *(u32 *)(self + 0x832));
  }
  *(u32 *)(self + 0x836) &= ~0x20u;
}
PCREG(594590, restoreItem);

// 0x595010 ZFFHERO::SetTempItem(EFFItemType type), thiscall, ret 4. A second temporary item logs "Already has temp
// item" (ZFFHero.cpp line 0x552) and calls the assert hook at [0x7003b0] (int3 without one). When the hand item
// (slot 0x504) is not the hero's item of that type (GetItem), the hand item's handle (render manager slot 0x4c) is
// saved at +0x832, the link action is dropped and the new item's handle goes into the hand (slot 0x480); flag 0x20 of
// +0x836 marks it.
static void THISCALL setTempItem(u8 *self, u32 type) {
  if (*(u32 *)(self + 0x832)) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *l = (u8 *)((vcallUUU)VT(lg, 0x20))(lg, 0x6ac6d0u, 0x552);
    ((logFn)VT(l, 0x2c))(l, 0x6ac9ecu);
    voidFn f = G(voidFn, 0x7003b0);
    if (f)
      f();
    else
      __builtin_trap();
  }
  u32 cur = ((vcallU0)VT(self, 0x504))(self);
  u32 it = ext_591e50(self, type);
  if (cur != it) {
    u8 *rm = rmgr();
    *(u32 *)(self + 0x832) = ((vcallUU)VT(rm, 0x4c))(rm, cur);
    ((vcallV0)VT(self, 0x3dc))(self);
    void **vt = *(void ***)self;
    rm = rmgr();
    u32 h = ((vcallUU)VT(rm, 0x4c))(rm, it);
    ((vcallVU)vt[0x480 / 4])(self, h);
    *(u32 *)(self + 0x836) |= 0x20;
  }
}
PCREG(595010, setTempItem);

// 0x4de4b0 mmtmul(float *dst, const float *a, const float *m), fastcall, ret 4. Each row of a (from the last) times the
// transpose of m (vmtmul), into dst.
static void FASTCALL mmtmul(float *dst, const float *a, const float *m) {
  ext_459fc0(dst + 6, a + 6, m);
  ext_459fc0(dst + 3, a + 3, m);
  ext_459fc0(dst, a, m);
}
PCREG(4de4b0, mmtmul);

// 0x4de4f0 (m, n), fastcall. m = m times the transpose of n, row by row from the last (vmtmul in place).
static void FASTCALL mmtmulInPlace(float *m, const float *n) {
  ext_441a60(m + 6, n);
  ext_441a60(m + 3, n);
  ext_441a60(m, n);
}
PCREG(4de4f0, mmtmulInPlace);

// 0x5c3860 COpenSewer::ActivateMenu(unsigned arg), thiscall, ret 4. The sewer lid (geometry +0x44) sends
// "Msg_SaveHeroPosMat" (OpenSewer.cpp line 0x50) to the "LevelController" with arg as data. The "rSEWERMENU" object's
// window (slot 0x2c4, the embedded object at +0xcb, its slot 0x14) is opened when it is not open already: render
// manager slot 0xb4(1), sound system slot 0x138(1), and the lid sends "Msg_OpenWindow" (line 0x59) to the menu
// (SendCommand(geom, cmd, 0)).
static void THISCALL activateMenu(u8 *self, u32 arg) {
  u8 *rm = rmgr();
  u8 *db = (u8 *)((vcallU0)VT(rm, 0x138))(rm);
  u32 h = 0;
  ((vcallVUP)VT(db, 0x88))(db, 0x6a5c48u, &h);
  void **vt = **(void ****)(self + 0x44);
  rm = rmgr();
  u16 id = (u16)((regFn)VT(rm, 0x114))(rm, 0x6add3cu, 0, 0x6b3e68u, 0x50);
  ((sendHFn)vt[0x12c / 4])(*(u8 **)(self + 0x44), h, id, (void *)arg);
  rm = rmgr();
  db = (u8 *)((vcallU0)VT(rm, 0x138))(rm);
  u32 v = 0;
  ((vcallVUP)VT(db, 0x88))(db, 0x6a86e0u, &v);
  rm = rmgr();
  u8 *menu = (u8 *)((vcallUU)VT(rm, 0x58))(rm, v);
  u8 *x = (u8 *)((vcallU0)VT(menu, 0x2c4))(menu);
  u8 *w = x + 0xcb;
  if (!((vcallU0)VT(w, 0x14))(w)) {
    rm = rmgr();
    ((vcallVU)VT(rm, 0xb4))(rm, 1);
    u8 *ss = *(u8 **)(sys() + 0x1a9f);
    if (ss)
      ((vcallVU)VT(ss, 0x138))(ss, 1);
    vt = **(void ****)(self + 0x44);
    rm = rmgr();
    id = (u16)((regFn)VT(rm, 0x114))(rm, 0x6a6698u, 0, 0x6b3e68u, 0x59);
    ((sendGFn)vt[0x130 / 4])(*(u8 **)(self + 0x44), menu, id, 0);
  }
}
PCREG(5c3860, activateMenu);
