#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_59b0a0(void *self);
extern "C" u32 THISCALL ext_5adeb0(void *self, u32 s);
extern "C" void THISCALL ext_5ae930(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_5b1250(void *self, u32 a);
extern "C" u32 THISCALL ext_5acfb0(void *self);
extern "C" void THISCALL ext_5ad000(void *self, u32 a);
extern "C" void THISCALL ext_59b3c0(void *self);
extern "C" void THISCALL ext_59c4a0(void *self);
extern "C" void *THISCALL ext_589c20(void *self, u32 a);
extern "C" void THISCALL ext_596d00(void *self, u32 a);
extern "C" void THISCALL ext_596d30(void *self, u32 a);
extern "C" void THISCALL ext_596940(void *self, u32 a, u32 b, u32 c, u32 d);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *eng() { return G(u8 *, 0x70039c); }
static inline u8 *tab() { return (u8 *)rd32u(eng() + 0x9b); }

// Looks the entry named by string `str` up through the object table: table slot 0x138 -> object slot 0x88(str, &id), then table slot 0x58(id).
static inline u8 *lookup(u32 str) {
  u8 *T = tab();
  u8 *X = (u8 *)(*(V0 *)(vt(T) + 0x138))(T);
  u32 id = 0;
  (*(V2 *)(vt(X) + 0x88))(X, str, (u32)&id);
  T = tab();
  return (u8 *)(*(V1 *)(vt(T) + 0x58))(T, id);
}
static inline void notify(u32 str, u32 slot) {
  u8 *R = lookup(str);
  if (R != 0) (*(V0 *)(vt(R) + slot))(R);
}
static inline bool query(u32 str) {
  u8 *T = tab();
  u8 *Y = (u8 *)(*(V0 *)(vt(T) + 0x134))(T);
  u8 flag = 0;
  (*(V2 *)(vt(Y) + 0x90))(Y, str, (u32)&flag);
  return flag != 0;
}

// 0x59b820: per-frame update of a pending mission/prompt object (thiscall(), void, /GS).
extern "C" void THISCALL fn_59b820(u8 *self) {
  u8 buf[0x14];
  u8 buf2[0x14];
  u8 *g = G(u8 *, 0x7003b8);
  wr32u(g + 0x2c8a, rd32u(self + 0x1044));
  if (rd32u(self + 0x1044) == 3 && self[0x103c] != 0) notify(0x6adbb4, 0x28);
  {
    u8 *E = eng();
    if ((u8)(*(V2 *)(vt(E) + 0x5c))(E, 0x679bd0, 0)) notify(0x6adbc4, 0x2c);
  }
  ext_59b0a0(self);
  if (self[0x4a] == 0x38 && self[0x4b] == 0x45) {
    bool bl;
    if (ext_5adeb0(self + 0x57, 0x6adbd4) == 0) bl = false;
    else if (ext_5adeb0(self + 0x57, 0x6adbe4) == 0) bl = false;
    else if (ext_5adeb0(self + 0x57, 0x6adbf4) == 0) bl = false;
    else if (ext_5adeb0(self + 0x57, 0x6adc04) == 0) bl = false;
    else bl = true;
    u8 *E = eng();
    u32 al = (u8)(*(V2 *)(vt(E) + 0x5c))(E, 0x6adc14, 0);
    if (al != 0 || bl) {
      u8 *ebx = lookup(0x6adc20);
      u8 *o44 = (u8 *)rd32u(self + 0x44);
      u8 *edi = vt(o44);
      u8 *K = tab();
      u32 ax = (*(V5 *)(vt(K) + 0x114))(K, 0x682e18, 0, 0x6adc28, 0x122, 0);
      (*(V2 *)(edi + 0x130))(o44, (u32)ebx, (u16)ax);
    }
  }
  if (self[0x103c] != 0) {
    ext_59c4a0(self);
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  if (query(0x6a757c)) {
    wr32u(self + 0x41b, 0);
    wr32u(self + 0x41f, 3);
  }
  if (query(0x6a776c)) {
    wr32u(self + 0x41b, 0x32);
    wr32u(self + 0x41f, 6);
    ext_5ae930(self + 0x57, 0x6adc60, 1);
    wr32u(G(u8 *, 0x7003b8) + 0xc69, 0);
    if (rd32u(self + 0x1044) == 2) notify(0x6adc70, 0x28);
    if (rd32u(self + 0x1044) == 1) ext_5b1250(self + 0x50f, 0x6adc80);
  } else {
    notify(0x6a663c, 0x28);
  }
  if (self[0x103f] == 0) {
    u8 *ebx = (u8 *)ext_589c20(G(u8 *, 0x7003b8), 0);
    ext_596d00(ebx, rd32u(self + 0x41b));
    ext_596d30(ebx, rd32u(self + 0x41f));
    const u8 *a = (const u8 *)rd32u(self + 0x4d);
    const u8 *b = (const u8 *)0x6a9280;
    int diff = 0;
    for (;;) {
      u8 c = *a;
      if (c != *b) { diff = 1; break; }
      if (c == 0) break;
      u8 c2 = a[1];
      if (c2 != b[1]) { diff = 1; break; }
      a += 2;
      b += 2;
      if (c2 == 0) break;
    }
    if (diff) {
      int n = (int)ext_5acfb0(self + 0x3b1);
      while (n > 0) {
        ext_596940(ebx, 0, (u32)buf, 0, 0xffffffff);
        n--;
      }
      if (self[0x41a] != 0) {
        ext_596940(ebx, 1, (u32)buf, 0, 0xffffffff);
        const u8 *nm = (const u8 *)rd32u(self + 0x4d);
        __builtin_memcpy(buf2, (const void *)0x6adc8c, 16);
        __builtin_memcpy(buf2 + 16, (const void *)0x6adc9c, 4);
        buf2[2] = nm[0];
        buf2[3] = nm[1];
        ext_5ae930(self + 0x57, (u32)buf2, 1);
      }
      int ch = (int)(signed char)((const u8 *)rd32u(self + 0x4d))[1] - 0x41;
      u32 v = (u32)ch > 3 ? 4 : (u32)ch;
      ext_5ad000(self + 0x3b1, v);
    }
    ext_59b3c0(self);
    self[0x41a] = 0;
    wr32u(self + 0x423, 0);
  }
  if (self[0x103e] == 0) {
    u8 al = self[0x4a] - 0x34;
    if (al <= 2) G(u8 *, 0x7003b8)[0xab8] = 1;
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(59b820, fn_59b820);
