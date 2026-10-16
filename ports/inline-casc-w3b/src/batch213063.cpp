#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef u32(*Atoi)(u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_562c20(void *self, u32 a);
extern "C" u32 THISCALL ext_562b50(void *self, u32 a);
extern "C" u32 THISCALL ext_561be0(void *self);
extern "C" u32 THISCALL ext_561f10(void *self, u32 a);
extern "C" u32 THISCALL ext_563500(void *self);
extern "C" u32 THISCALL ext_5ad790(void *buf);
extern "C" u32 THISCALL ext_56e9d0(void *self, void *buf);
extern "C" u32 THISCALL ext_59ca50(void *self, u32 a);
extern "C" u32 THISCALL ext_5ae710(void *self, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static inline void log_error() {
  void *L = G(void *, 0x700390);
  typedef u32(THISCALL * LogNew)(void *, u32, u32);
  u8 *M = (u8 *)(*(LogNew *)(*(u8 **)L + 0x20))(L, 0x6a8bc4, 0x59);
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  asm volatile(
      "pushl %[f]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $8, %%esp"
      : "+a"(ra), "+c"(rc)
      : [f] "r"(0x6a8bec), [m] "r"(M)
      : "edx", "memory", "cc");
}

// 0x5732a0: thiscall(a) ret 4, returns bool in AL, /GS protected (4 KB of locals): command-state setup for the case number a.
// 0x562c20(this, a) true -> return 1. Then the engine value read "key" 0x6a7584 through slot 0x5c: when found and a < atoi(value) (IAT 0x6762d8) -> return 0.
// a in 2..10 selects a string constant (table 0x57346c) for 0x562b50; any other a logs an error through the [0x700390] manager (line 0x59) and returns 0.
// Then: 0x561be0 true -> engine slot 0xbc()->slot 0x64(0x6a8ba8, 1) and 0x561f10(this, 0); 0x563500; engine table [+0x9b] slot 0x134()->slot 0x68(0x6a75b0, 0, 0);
// a 0x3c0 byte stack record built by 0x5ad790 (its dword at +0x3ba replaced by [this->[0x94] + 0x411] when this->[0x180] is set) goes to 0x56e9d0(this->[0x94] + 0x57, rec),
// then 0x59ca50(this->[0x94], string) and 0x5ae710(this->[0x94] + 0x57, 0); returns 1.
extern "C" u8 THISCALL fn_5732a0(u8 *self, u32 a) {
  u8 buf[0x3c0];
  u32 val;
  if ((u8)ext_562c20(self, a)) {
    ext_633654(G(u32, 0x6f5630));
    return 1;
  }
  u8 *eng = G(u8 *, 0x70039c);
  if ((u8)(*(V2 *)(*(u8 **)eng + 0x5c))(eng, 0x6a7584, (u32)&val)) {
    u32 n = (*(Atoi *)0x6762d8)(val);
    if (a < n) {
      ext_633654(G(u32, 0x6f5630));
      return 0;
    }
  }
  static const u32 str[9] = {0x6a8540, 0x6a8548, 0x6a8550, 0x6a8558, 0x6a7810, 0x6a8560, 0x6a6e5c, 0x6a774c, 0x6a7818};
  u32 sel = a - 2;
  if (sel > 8) {
    log_error();
    ext_633654(G(u32, 0x6f5630));
    return 0;
  }
  u32 s = str[sel];
  ext_562b50(self, s);
  if ((u8)ext_561be0(self)) {
    u8 *e2 = G(u8 *, 0x70039c);
    void *x = (void *)(*(V0 *)(*(u8 **)e2 + 0xbc))(e2);
    (*(V2 *)(*(u8 **)x + 0x64))(x, 0x6a8ba8, 1);
    ext_561f10(self, 0);
  }
  ext_563500(self);
  u8 *e3 = G(u8 *, 0x70039c);
  void *tab = (void *)rd32u(e3 + 0x9b);
  void *y = (void *)(*(V0 *)(*(u8 **)tab + 0x134))(tab);
  (*(V3 *)(*(u8 **)y + 0x68))(y, 0x6a75b0, 0, 0);
  ext_5ad790(buf);
  if (self[0x180]) wr32u(buf + 0x3ba, rd32u((u8 *)rd32u(self + 0x94) + 0x411));
  u8 *w = (u8 *)rd32u(self + 0x94);
  ext_56e9d0(w + 0x57, buf);
  ext_59ca50((void *)rd32u(self + 0x94), s);
  ext_5ae710(w + 0x57, 0);
  ext_633654(G(u32, 0x6f5630));
  return 1;
}
PCREG(5732a0, fn_5732a0);
