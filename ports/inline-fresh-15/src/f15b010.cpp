// f15b010.cpp - fresh slice 15, batch 10 (2026-10-12).
// 0x5f14f0 ZScriptDll::~ZScriptDll (deleting): vt 0x6b83bc; [this+0xc] -> 0x5f1370 + delete(p, 0xb8); byte [0x7143ac] = 0;
//          OpaqueString_t::clean, OpaqueUserType_t::clean; base dtor 0x4e66a0; flags&1 -> delete(this, 0x1014).
// 0x63afb0 ZDrawArray<ZTextureDrawEntry,...>::Add: walk the block ring at +8 for a block whose free index (+2) is not
//          0xffff (else 0x63b240 grows it); ++count +0xc; pop entry (idx+1)*16 from the block's free list, init it
//          (0, 0xffff1207, word 0, 0), ++block used byte; return the entry or 0.
// 0x4a3670 ZSoundMove::GetNextPos(float*): iterate the list at +0x78 (slot 0x4c begin, slot 0x5c next) to the
//          [+0x128]-th handle, resolve it (db slot 0x58) and GetPos (0x4db500) its geom +8; ++[+0x128] mod [+0x124].
// 0x5ffd70 (two-level map lookup)(k1, k2): lower_bound k1 in the tree at [this+0x121] (packed nodes: +1 root, +5 left,
//          +9 right, +0xd key, +0x11 value); value->find(k2) (0x5ff0f0), then find(0); found -> node +0xf; else
//          [0x7003b0]() (or int3).
// 0x607930 ZRenderGCDll::InstallPrimBuffer(p, n): this->slot 0x68(); [+0x18] == 0 -> new ZPrimControlGC(false);
//          render dev [[0x70039c]+0x190f] -> slot 0x294(); return ZRenderBaseDll::InstallPrimBuffer(p, n).
// 0x4c2570 ZSoundSegment::RemoveText: byte +0x72 set -> h from db slot 0x138 obj slot 0x88(0x68c070, &h); +0x78 =
//          db slot 0x58(h); +0x76 = db slot 0x114(0x692668, 0, 0x693c40, 0xbb1); +0x78 -> slot 0x130(o, r, 0); +0x72 = 0.
// 0x604d70 (script compare native)(a): x = arg 0, y = arg 1 (0x5003d0 on [a+4]); "!" op -> _stricmp(x.s, y.s), else
//          _stricmp(...) == 0 (each compare runs twice when non-zero); result 0x5003d0([a+8], 0)->0x50d7b0(&v).
// 0x4f42f0 (fastcall factory)(ecx, edx, a, b): p = 0x45c4f0(0xb4, ecx); 0x4ee1b0(p; edx, a, b), vt 0x699664,
//          +0xac = +0xb0 = 0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define X(a) ((void *)ext_##a)

extern "C" char ext_634273[], ext_5f1370[], ext_604d30[], ext_6038e0[], ext_4e66a0[], ext_63b240[], ext_4db500[],
    ext_5ff0f0[], ext_41e290[], ext_607c80[], ext_64fe80[], ext_5003d0[], ext_50d7b0[], ext_45c4f0[], ext_4ee1b0[];

typedef void (*Del)(void *, u32);
static inline void *db() { return AT(void *, G(u8 *, 0x70039c), 0x9b); }

extern "C" void *THISCALL f15_5f14f0(u8 *self, u32 flags) {
  void *e = AT(void *, self, 0xc);
  AT(u32, self, 0) = 0x6b83bcu;
  if (e) {
    ((void(THISCALL *)(void *))X(5f1370))(e);
    ((Del)X(634273))(e, 0xb8);
  }
  G(u8, 0x7143ac) = 0;
  ((void (*)())X(604d30))();
  ((void (*)())X(6038e0))();
  ((void(THISCALL *)(void *))X(4e66a0))(self);
  if (flags & 1) ((Del)X(634273))(self, 0x1014);
  return self;
}

static inline u8 *take(u8 *b) {
  u32 ix = AT(u16, b, 2);
  if (ix == 0xffff) return 0;
  u8 *e = b + (ix + 1) * 16;
  AT(u16, b, 2) = AT(u16, e, 0);
  AT(u32, e, 0) = 0;
  AT(u32, e, 4) = 0xffff1207u;
  AT(u16, e, 8) = 0;
  AT(u32, e, 0xc) = 0;
  b[0]++;
  return e;
}
extern "C" u8 *THISCALL f15_63afb0(u8 *self) {
  u8 *c = AT(u8 *, self, 8);
  if (c) {
    for (;;) {
      u8 *a = AT(u8 *, self, 8);
      if (AT(u16, a, 2) != 0xffff) {
        AT(u32, self, 0xc)++;
        return take(a);
      }
      a = AT(u8 *, a, 8);
      AT(u8 *, self, 8) = a;
      if (c == a || !a) break;
    }
  }
  if (!((u8(THISCALL *)(void *))X(63b240))(self)) return 0;
  u8 *b = AT(u8 *, self, 8);
  AT(u32, self, 0xc)++;
  return take(b);
}

extern "C" void THISCALL f15_4a3670(u8 *self, float *out) {
  u32 n = 0;
  u8 *l = self + 0x78;
  if (l) {
    u32 it[3];
    vcall<void>(l, 0x4c, it);
    u32 h = vcall<u32>(l, 0x5c, it);
    while (it[0]) {
      u8 *o = vcall<u8 *>(db(), 0x58, h);
      if (n == AT(u32, self, 0x128)) {
        ((void(THISCALL *)(void *, float *))X(4db500))(AT(void *, o, 8), out);
        break;
      }
      n++;
      h = vcall<u32>(l, 0x5c, it);
    }
  }
  if (++AT(u32, self, 0x128) >= AT(u32, self, 0x124)) AT(u32, self, 0x128) = 0;
}

typedef u8 **(THISCALL *Find)(void *, u8 **, u32 *);
extern "C" u32 THISCALL f15_5ffd70(u8 *self, u32 k1, u32 k2) {
  u8 *head = AT(u8 *, self, 0x121);
  u8 *y = head;
  for (u8 *x = AT(u8 *, head, 1); x;) {
    if (AT(u32, x, 0xd) >= k1) {
      y = x;
      x = AT(u8 *, x, 5);
    } else {
      x = AT(u8 *, x, 9);
    }
  }
  if (y == head || k1 < AT(u32, y, 0xd)) y = head;
  if (y != head) {
    u8 *m = AT(u8 *, y, 0x11);
    u8 *r;
    ((Find)X(5ff0f0))(m, &r, &k2);
    u8 *end = AT(u8 *, m, 0);
    if (r != end) return AT(u32, r, 0xf);
    k2 = 0;
    r = *((Find)X(5ff0f0))(m, &r, &k2);
    if (r != end) return AT(u32, r, 0xf);
  }
  typedef u32 (*Fail)();
  Fail f = G(Fail, 0x7003b0);
  if (!f) __builtin_trap();
  return f();
}

extern "C" u32 THISCALL f15_607930(u8 *self, void *p, u32 n) {
  vcall<void>(self, 0x68);
  if (!AT(u32, self, 0x18)) {
    void *o = ((void *(*)(u32))X(41e290))(4);
    if (o) o = ((void *(THISCALL *)(void *, u32))X(607c80))(o, 0);
    AT(void *, self, 0x18) = o;
  }
  void *r = AT(void *, G(u8 *, 0x70039c), 0x190f);
  if (r) vcall<void>(r, 0x294);
  return ((u32(THISCALL *)(void *, void *, u32))X(64fe80))(self, p, n);
}

extern "C" void THISCALL f15_4c2570(u8 *self) {
  if (!AT(u8, self, 0x72)) return;
  void *o = vcall<void *>(db(), 0x138);
  u32 h = 0;
  vcall<void>(o, 0x88, 0x68c070u, &h);
  AT(u32, self, 0x78) = vcall<u32>(db(), 0x58, h);
  u32 r = vcall<u32>(db(), 0x114, 0x692668u, 0u, 0x693c40u, 0xbb1u);
  void *c = AT(void *, self, 0x78);
  AT(u16, self, 0x76) = (u16)r;
  if (c) vcall<void>(c, 0x130, c, r, 0u);
  AT(u8, self, 0x72) = 0;
}

typedef u32 **(THISCALL *Arg)(void *, u32);
typedef s32 (*Cmp)(u32, u32);
#define STRICMP (*(Cmp *)0x676414)
extern "C" void STDCALL f15_604d70(u8 *a) {
  u32 *x = *((Arg)X(5003d0))(AT(void *, a, 4), 0);
  u32 *y = *((Arg)X(5003d0))(AT(void *, a, 4), 1);
  s32 v;
  if (*AT(u8 *, a, 0) == '!') {
    v = STRICMP(x[3], y[3]);
    if (v) v = STRICMP(x[3], y[3]);
  } else {
    v = STRICMP(x[3], y[3]);
    if (!v) v = 1;
    else v = STRICMP(x[3], y[3]) == 0;
  }
  void *o = ((Arg)X(5003d0))(AT(void *, a, 8), 0);
  ((void(THISCALL *)(void *, s32 *))X(50d7b0))(o, &v);
}

extern "C" void *FASTCALL f15_4f42f0(u32 ecx, u32 edx, u32 a, u32 b) {
  u8 *p = ((u8 * (*)(u32, u32)) X(45c4f0))(0xb4, ecx);
  if (!p) return 0;
  ((void(THISCALL *)(void *, u32, u32, u32))X(4ee1b0))(p, edx, a, b);
  AT(u32, p, 0) = 0x699664u;
  AT(u32, p, 0xac) = 0;
  AT(u32, p, 0xb0) = 0;
  return p;
}

PCREG(5f14f0, f15_5f14f0);
PCREG(63afb0, f15_63afb0);
PCREG(4a3670, f15_4a3670);
PCREG(5ffd70, f15_5ffd70);
PCREG(607930, f15_607930);
PCREG(4c2570, f15_4c2570);
PCREG(604d70, f15_604d70);
PCREG(4f42f0, f15_4f42f0);
