#include "ff.h"

extern "C" void THISCALL ext_561400(void *t);
extern "C" u32 THISCALL ext_563400(void *t);
extern "C" void THISCALL ext_5618b0(void *t, void *e, void *next);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u32 kind_of(void *e) { return vcall<u32>(e, 0x310); }
static bool str_eq(const char *a, const char *b) {
  while (*a == *b) {
    if (*a == 0) return true;
    a++; b++;
  }
  return false;
}
static void query_flag(const char *name, u8 *flag) {
  u8 *eng = G(u8 *, 0x70039c);
  void *tbl = (void *)rd32u(eng + 0x9b);
  void *r = vcall<void *>(tbl, 0x134);
  vcall<void>(r, 0x90, (u32)name, (u32)flag);
}

// 0x5698b0: thiscall(this) with /GS. Gathers up to 6 entities (this+0x19c + 4i through engine table slot 0x58) into a[1..n]; unless 0x563400 says otherwise,
// entities whose kind is 0xff0000-masked or whose [e+8][0x3c] bit 10 is set are dropped (vt 0xbc(1)); two table flags / three mode names decide whether the first
// kind-0x378 entity is dropped too; the survivors are chained ring-wise (vt 0x31c prev/next, vt 0xbc(0), 0x5618b0) and the owner [this+0x44] is told (vt 0x2e4) when its
// current (vt 0x2e0) is not in the list.
extern "C" void THISCALL fn_5698b0(u8 *self);
static void THISCALL body_5698b0(u8 *self) {
  u32 a[8];
  ext_561400(self);
  for (int k = 0; k < 8; k++) a[k] = 0;
  int n = 0;
  {
    u8 *eng = G(u8 *, 0x70039c);
    do {
      void *tbl = (void *)rd32u(eng + 0x9b);
      u32 r = vcall<u32>(tbl, 0x58, rd32u(self + 0x19c + 4 * n));
      a[n + 1] = r;
      if (r == 0) break;
      n++;
    } while (n < 6);
  }
  if ((u8)ext_563400(self) == 0 && n > 1) {
    int i = 1;
    while (i <= n) {
      u8 *e = (u8 *)a[i];
      bool drop = (kind_of(e) & 0xffff0000) == 0xff0000 || ((rd32u((u8 *)rd32u(e + 8) + 0x3c) >> 10) & 1);
      if (drop) {
        vcall<void>(e, 0xbc, 1);
        n--;
        if (i <= n)
          for (int k = 0; k <= n - i; k++) a[i + k] = a[i + 1 + k];
      }
      i++;
    }
  }
  u8 flag = 0;
  query_flag((const char *)0x6a757c, &flag);
  if (flag == 0) {
    flag = 0;
    query_flag((const char *)0x6a776c, &flag);
    flag = flag != 0;
  } else {
    flag = 1;
  }
  const char *s = (const char *)(rd32u(self + 0x94) + 0x48);
  if (flag || str_eq(s, (const char *)0x6a7808) || str_eq(s, (const char *)0x6a7810) || str_eq(s, (const char *)0x6a7818)) {
    for (int i = 1; i <= n; i++) {
      if (kind_of((void *)a[i]) == 0x378) {
        vcall<void>((void *)a[i], 0xbc, 1);
        n--;
        if (i <= n)
          for (int k = 0; k <= n - i; k++) a[i + k] = a[i + 1 + k];
        break;
      }
    }
  }
  if (n < 2) return;
  a[0] = a[n];
  a[n + 1] = a[1];
  for (int i = 1; i <= n; i++) {
    void *e = (void *)a[i];
    vcall<void>(e, 0x31c, a[i - 1], 1);
    vcall<void>(e, 0x31c, a[i + 1], 2);
    vcall<void>(e, 0xbc, 0);
    if (i < n) ext_5618b0(self, e, (void *)a[i + 1]);
  }
  void *own = (void *)rd32u(self + 0x44);
  u32 cur = vcall<u32>(own, 0x2e0);
  for (int k = 0; k < 8; k++)
    if (a[k] == cur) return;
  own = (void *)rd32u(self + 0x44);
  vcall<void>(own, 0x2e4, (u32)own);
  own = (void *)rd32u(self + 0x44);
  vcall<void>(own, 0x2e4, a[1]);
}
extern "C" void THISCALL fn_5698b0(u8 *self) {
  body_5698b0(self);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5698b0, fn_5698b0);
