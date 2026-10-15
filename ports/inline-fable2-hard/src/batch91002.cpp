// batch91002.cpp - hard-function trial (fable 2), batch 91002: 0x46c1e0 ZWeapon-like item Init (zitem.cpp, 462 insns, 81 calls), thiscall, no args.
// EH3 prologue (fs:[0] frame, /GS cookie checked through 0x633654) guards three local string temporaries built by this->slot 0x1d8(&s, 1)
// and destroyed by 0x4cbec0; no exception is ever raised, so the port only keeps the cookie check call.
#include "ff.h"

typedef u8 *(THISCALL *v0o_t)(void *);
typedef u32 (THISCALL *v0u_t)(void *);
typedef u32 (THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef void (THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void (THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v4o_t)(void *, u32, u32, u32, u32);
typedef void (*log3_t)(void *, u32, u32);
typedef void (*log5_t)(void *, u32, u32, u32, u32);

extern "C" u8 *THISCALL ext_4cc1d0(void *s);                  // ret 0 (verified collision): string data pointer [s] (real code runs)
extern "C" void THISCALL ext_4cbec0(void *s);                 // ret 0 (verified unclaimed-68): string dtor, frees [s] unless inline (real code runs)
extern "C" void THISCALL ext_456b70(void *e, u8 *a, u8 *b);  // ret 8 (verified casc-h3, hooked)
extern "C" void THISCALL ext_4dbe30(void *q, u32);            // ret 4 (hooked)
extern "C" void THISCALL ext_4dc440(void *q, u32);            // ret 4 (hooked)
extern "C" void THISCALL ext_4dc630(void *q, u32, u32);       // ret 8 (verified collision, hooked)
extern "C" void THISCALL ext_46f240(void *B);                 // ret 0 (verified casc-h1, hooked)
extern "C" void FASTCALL ext_633654(u32 cookie);              // /GS check (hooked)

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *table() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *vslot(void *o, u32 off) { return *(u8 **)(*(u8 **)o + off); }
#define VC(T, o, off) ((T)vslot(o, off))

static inline u8 *weapon(u8 *B) { return VC(v0o_t, B, 0x350)(B); }
static inline u8 *logobj(u32 line) {   // [0x700390]->slot 0x20(file, line)
  u8 *lg = G(u8 *, 0x700390);
  return VC(v2o_t, lg, 0x20)(lg, 0x6887c4u, line);
}
static inline u32 handle(void *o) { u8 *t = table(); return VC(v1u_t, t, 0x4c)(t, (u32)o); }
// this->slot 0x1d8(&s, 1) builds a string temporary in s and returns it; 0x4cc1d0 gives its char data, 0x4cbec0 destroys it.
static inline u8 *namestr(u8 *B, u8 *s) { return ext_4cc1d0(VC(v2o_t, B, 0x1d8)(B, (u32)s, 1)); }

static void THISCALL fn46c1e0(u8 *B) {
  u8 s[0x84];
  u32 cur[3];
  if (rd(B + 0x60) == 0) {
    u8 *lo = logobj(0x955);
    u8 *cs = namestr(B, s);
    ((log3_t)vslot(lo, 0x2c))(lo, 0x688c60u, (u32)cs);   // "<debug message>"
    ext_4cbec0(s);
    VC(v1_t, B, 0x210)(B, 1);
    ext_633654(0);
    return;
  }
  VC(v0u_t, B, 0x2fc)(B);
  u8 *w = weapon(B);
  u8 *x = VC(v1o_t, w, 0x340)(w, 0);
  VC(v1_t, B, 0x324)(B, (u32)x);
  w = weapon(B);
  wr(B + 0xd5, VC(v1u_t, w, 0x358)(w, 0));
  B[0xbf] = 0;
  w = weapon(B);
  u8 *it = VC(v0o_t, w, 0x364)(w);
  if (it) {
    VC(v1_t, it, 0x4c)(it, (u32)cur);
    u32 el = VC(v1u_t, it, 0x5c)(it, (u32)cur);
    while (cur[0] != 0) {
      u8 *t = table();
      u8 *tmpl = VC(v1o_t, t, 0x58)(t, el);
      if (tmpl) {
        u8 *o = VC(v4o_t, B, 0x394)(B, (u32)tmpl, (u32)tmpl, (u32)B, 1);
        u8 *p = *(u8 **)(B + 0xd9);
        u8 *vt = *(u8 **)p;
        u32 h = handle(o);
        p = *(u8 **)(B + 0xd9);
        ((v1_t) * (u8 **)(vt + 4))(p, h);
      }
      el = VC(v1u_t, it, 0x5c)(it, (u32)cur);
    }
  }
  w = weapon(B);
  u8 *pb = VC(v2o_t, w, 0x25c)(w, 0x688860u, 0);   // "PosBox_Hand"
  u32 h = pb ? handle(pb) : handle(B);
  VC(v1_t, B, 0x2d8)(B, h);
  w = weapon(B);
  if (VC(v0u_t, w, 0x328)(w) & 0xff) {
    if (rd(B + 0xba) == 0xffffffffu) {
      w = weapon(B);
      if (w) wr(B + 0xba, VC(v0u_t, B, 0x364)(B));
    }
    u32 n = VC(v0u_t, B, 0x364)(B);
    if (n != 0xffffffffu && (s32)rd(B + 0xba) > (s32)n) {
      u8 *lo = logobj(0x994);
      u8 *cs = namestr(B, s);
      ((log5_t)vslot(lo, 0x2c))(lo, 0x688ca4u, (u32)cs, rd(B + 0xba), n);   // "<debug message>"
      ext_4cbec0(s);
    }
    w = weapon(B);
    u8 *e = VC(v0o_t, w, 0x368)(w);
    if (e && (VC(v1u_t, e, 0x1e0)(e, 0x2000e5) & 0xff)) ext_456b70(e, B + 0xdd, B + 0xe1);
    w = weapon(B);
    e = VC(v0o_t, w, 0x36c)(w);
    if (e && (VC(v1u_t, e, 0x1e0)(e, 0x2000e5) & 0xff)) ext_456b70(e, B + 0xdd, B + 0xe5);
    w = weapon(B);
    x = VC(v1o_t, w, 0x340)(w, 0);
    e = VC(v0o_t, x, 0x338)(x);
    if (e && (VC(v1u_t, e, 0x1e0)(e, 0x2000e5) & 0xff)) ext_456b70(e, B + 0xdd, B + 0xe9);
    w = weapon(B);
    u8 *pl = VC(v2o_t, w, 0x25c)(w, 0x688cdcu, 0);   // "PosBox_Light"
    if (pl) {
      w = weapon(B);
      u8 *li = VC(v0o_t, w, 0x370)(w);
      if (li) {
        u8 *d = *(u8 **)(pl + 8);
        wr(B + 0xf1, rd(d + 0x24));
        wr(B + 0xf5, rd(d + 0x28));
        wr(B + 0xf9, rd(d + 0x2c));
        u8 *o = VC(v4o_t, B, 0x394)(B, (u32)li, (u32)pl, rd(table() + 0xadc), 0);
        if (o) {
          VC(v1_t, o, 0x224)(o, 1);
          ext_4dbe30(*(u8 **)(o + 8), 1);
          ext_4dc440(*(u8 **)(o + 8), 1);
          wr(B + 0xed, handle(o));
          u8 *q = *(u8 **)(o + 8);
          u8 *a = *(u8 **)(q + 0x54);
          u32 f = a ? rd(*(u8 **)(a + 0xc) + 0x23) : 0x200002u;
          if (!(f & 0x100000)) ext_4dc630(q, 0x8000, 0);
          ext_4dc630(q, 0x2000000, 0);
        } else {
          wr(B + 0xed, 0);
        }
      }
    }
    w = weapon(B);
    if (VC(v0u_t, w, 0x324)(w) & 0xff) {
      w = weapon(B);
      u8 *sl = VC(v2o_t, w, 0x25c)(w, 0x688cecu, 0);   // "Slide"
      if (sl) {
        u8 *o = VC(v4o_t, B, 0x394)(B, (u32)sl, (u32)sl, (u32)B, 1);
        wr(B + 0xfd, handle(o));
      }
      w = weapon(B);
      u8 *cl = VC(v2o_t, w, 0x25c)(w, 0x688cf4u, 0);   // "Clip"
      if (cl) {
        u8 *o = VC(v4o_t, B, 0x394)(B, (u32)cl, (u32)cl, (u32)B, 1);
        wr(B + 0x101, handle(o));
      }
    }
  }
  u8 *t = table();
  VC(v0u_t, t, 0x6c)(t);
  VC(v0u_t, B, 0)(B);
  t = table();
  VC(v0u_t, t, 0x68)(t);
  VC(v3_t, B, 0x2f0)(B, rd(B + 0x64), 0, 1);
  if ((rd(*(u8 **)(B + 8) + 0x3c) >> 10) & 1) {
    u8 *lo = logobj(0x9eb);
    u8 *cs = namestr(B, s);
    ((log3_t)vslot(lo, 0x30))(lo, 0x688cfcu, (u32)cs);   // "<debug message>"
    ext_4cbec0(s);
  }
  ext_46f240(B);
  ext_633654(0);
}
PCREG(46c1e0, fn46c1e0);
