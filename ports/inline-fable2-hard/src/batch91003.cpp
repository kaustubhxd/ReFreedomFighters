// batch91003.cpp - hard-function trial (fable 2), batch 91003: 0x560580 "touch every game-object class once" (466 insns, 78 calls), no args, plain ret.
// Builds 37 stack temporaries, one per class, and destroys each at once: for 32 of them the derived destructor is inlined down to the ZGameObject
// base destructor (zero this+0x44 and this+0x30, vtable := 0x686874, then [eng+0x9b]->slot 0x34(this) = unregister); five keep a real dtor call.
// EH3 prologue with a state variable per temporary and a /GS cookie (0x633654): no exception path is ever taken, the port keeps only the cookie check.
#include "ff.h"

typedef void (THISCALL *v1_t)(void *, u32);
#define CTOR(a) extern "C" u8 *THISCALL ext_##a(void *)
CTOR(561020); CTOR(565840); CTOR(565870); CTOR(565b90); CTOR(566bc0); CTOR(566c90); CTOR(561160); CTOR(564460); CTOR(567720); CTOR(569380);
CTOR(5696b0); CTOR(569730); CTOR(56ad80); CTOR(56b2d0); CTOR(56c810); CTOR(56db70); CTOR(56e990); CTOR(56fea0); CTOR(571960); CTOR(572360);
CTOR(572e40); CTOR(573590); CTOR(574c60); CTOR(575d50); CTOR(5773f0); CTOR(577830); CTOR(578560); CTOR(578710); CTOR(57a100); CTOR(57a3b0);
CTOR(57a440); CTOR(57abc0); CTOR(57baa0); CTOR(43de70); CTOR(57bd90); CTOR(57c100); CTOR(57c460); CTOR(57c7c0); CTOR(4ccf60); CTOR(4cce40);
CTOR(57f1b0); CTOR(57aea0);
extern "C" u8 *THISCALL ext_573650(void *, u32, u32, u32);   // ret 0xc
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
// inlined ZGameObject::~ZGameObject on a derived temporary
static inline void base_dtor(u8 *o) {
  wr(o + 0x44, 0);
  wr(o + 0x30, 0);
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(o, 0x686874u);
  (*(v1_t **)t)[0x34 / 4](t, (u32)o);
}
#define TOUCH(a, o) do { ext_##a(o); base_dtor(o); } while (0)

static void fn560580(void) {
  u8 a[0x150], b[0x300], big[0x290];
  TOUCH(561020, a);
  ext_565840(b); ext_565870(b);
  TOUCH(565b90, b);
  ext_566bc0(a); ext_566c90(a);
  TOUCH(561160, a);
  TOUCH(564460, b);
  TOUCH(567720, b);
  TOUCH(569380, a);
  ext_5696b0(a); ext_569730(a);
  TOUCH(56ad80, b);
  TOUCH(56b2d0, b);
  TOUCH(56c810, a);
  TOUCH(56db70, a);
  TOUCH(56e990, b);
  TOUCH(56fea0, a);
  TOUCH(571960, a);
  TOUCH(572360, b);
  TOUCH(572e40, a);
  TOUCH(573590, a);
  TOUCH(574c60, b);
  TOUCH(575d50, a);
  TOUCH(5773f0, a);
  TOUCH(577830, a);
  ext_578560(a); ext_578710(a);
  TOUCH(57a100, b);
  TOUCH(57a3b0, a);
  TOUCH(57a440, a);
  TOUCH(57abc0, a);
  TOUCH(57baa0, b);
  ext_573650(b, 0, 0, 0); ext_43de70(b);
  TOUCH(57bd90, a);
  TOUCH(57c100, a);
  TOUCH(57c460, a);
  ext_57c7c0(big);
  ext_4ccf60(big + 0x264);   // member dtors of the big one (string / array members)
  ext_4cce40(big + 0x23c);
  ext_4ccf60(big + 0x190);
  base_dtor(big);
  TOUCH(57f1b0, a);
  TOUCH(57aea0, a);
  TOUCH(57c100, b);
  ext_633654(0);
}
PCREG(560580, fn560580);
