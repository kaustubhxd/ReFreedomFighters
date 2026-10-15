// batch46007.cpp - cascade t7 (Sonnet), tier G: 0x568dc0 (UI list item refresh: updates pending counters, logs, resizes a sound/text widget, flushes the pending list).
#include "ff.h"

extern "C" u8 *THISCALL ext_5af130(u8 *list, u32 key);                   // ret 4
extern "C" void THISCALL ext_5af5b0(u8 *self, u32 *k, u32 *amt, u32 flag);  // ret 0xc
extern "C" void THISCALL ext_5aedf0(u8 *list, u8 *rec);                   // ret 4
extern "C" void THISCALL ext_5af260(u8 *list, u8 *rec);                   // ret 4
extern "C" u8 *THISCALL ext_591f00(u8 *o);                                // plain
extern "C" u8 *THISCALL ext_591080(u8 *o);                                // plain
extern "C" void THISCALL ext_5aef10(u8 *o);                               // plain
extern "C" s32 THISCALL ext_4cc1d0(u8 *list);                             // plain
extern "C" u8 *THISCALL ext_5af0d0(u8 *list, u32 i);                      // ret 4
extern "C" void THISCALL ext_5aee20(u8 *o, u32 a, u32 b);                 // ret 8
extern "C" void THISCALL ext_5b0290(u8 *o);                               // plain
extern "C" void THISCALL ext_569260(u8 *self);                            // plain

static inline u32 &W(u8 *p, u32 off) { return *(u32 *)(p + off); }
static inline u8 *rd(u8 *p, u32 off) { return *(u8 **)(p + off); }
static inline u8 *T() { return *(u8 **)(*(u8 **)0x70039c + 0x9b); }
static inline u32 log114(u32 a, u32 line) { return (u16)vcall<u32>(T(), 0x114, a, (u32)0, (u32)0x6a73cc, line); }


extern "C" void THISCALL ext_59a580(u8 *, u32, u32, u32);
static inline u32 table4c(u32 a, u32 b, u32 c, u32 n) {
  if (n == 1) return vcall<u32>(T(), 0x4c, a);
  return vcall<u32>(T(), 0x4c, a, b, c);
}
static inline void callNameLookup(u8 *self, u32 str) {
  u32 v = vcall<u32>(rd(T(), 0xae4), 0, (u32)0x68899c, str);
  ext_59a580(rd(self, 0x28c), v, 0xffffffff, 0);
}

static void THISCALL fn568dc0(u8 *self) {
  if (W(self, 0x291) == 0) return;
  vcall<void>(rd(self, 0x90), 0x3dc);
  vcall<void>(rd(self, 0x90), 0x4dc, (u32)0, (u32)1);
  u8 *rec0 = ext_5af130(self + 0x180, W(self, 0x291));
  u32 flag = W(rec0, 0x19) == 1 ? 1 : 0;
  u32 L4 = 0xcccccccc, Lc = 0xcccccccc;
  ext_5af5b0(self + 0x27c, &L4, &Lc, flag);
  if (L4 != 0) {
    u8 *e = ext_5af130(self + 0x1d4, L4);
    if (e) {
      if (e[0x14]) W(e, 4) += Lc;
    } else {
      u32 key = L4, amt = Lc;
      if (ext_5af130(self + 0x1d4, key) == 0 && key != 0) {
        u8 *f = ext_5af130(self + 0x180, key);
        if (f) {
          W(f, 4) = amt;
          f[0x14] = 1;
          ext_5aedf0(self + 0x1d4, f);
        }
      }
    }
    u8 *esi = ext_5af130(self + 0x1d4, L4);
    u32 edi = log114(0x688968, 0x218);
    if (esi && W(esi, 0)) {
      u32 k = W(esi, 0);
      u32 r = vcall<u32>(rd(self, 0x288), 0x98, k, (u32)0);
      W(esi, 0x15) = r;
      u8 *p = vcall<u8 *>(T(), 0x58, r);
      if (p) {
        u8 *o = vcall<u8 *>(rd(self, 0x90), 0x55c, (u32)p);
        if (o) vcall<void>(o, 0x324, (u32)0);
      }
      vcall<void>(rd(self, 0x288), 0x44, edi, W(esi, 0x15));
      u8 *x = ext_591f00(rd(self, 0x90));
      if (x) {
        u32 r2 = vcall<u32>(x, 0x2e8);
        if (r2 == W(esi, 0)) {
          u8 *y = ext_591080(rd(self, 0x90));
          if (vcall<u8>(y, 0x1e0, (u32)0x1007d2)) {
            vcall<void>(y, 0x320);
            W(esi, 0x15) = 0;
          }
        }
      }
    }
  }
  vcall<void>(rd(self, 0x90), 0x3f4, W(rd(self, 0x90), 0xf12));
  u8 *edi = ext_5af130(self + 0x180, W(self, 0x291));
  u32 L8 = log114(0x688984, 0x23f);
  if (edi && W(edi, 0)) {
    u32 esi = W(edi, 0);
    if (W(edi, 0x15)) {
      vcall<void>(rd(self, 0x288), 0x44, L8, W(edi, 0x15));
    } else {
      u32 r = table4c(esi, 0, 0, 1);
      vcall<void>(rd(self, 0x288), 0x44, L8, r);
      u32 r3 = vcall<u32>(rd(self, 0x288), 0x98, W(edi, 0), (u32)0);
      W(edi, 0x15) = r3;
    }
    u8 *s = vcall<u8 *>(T(), 0x58, W(edi, 0x15));
    if (s && vcall<u8>(s, 0x1e0, (u32)0x1007d2)) {
      vcall<void>(rd(self, 0x90), 0x4dc, (u32)s, (u32)1);
      u8 *r4 = vcall<u8 *>(s, 0x2e8);
      u32 str = 0x67c8e8;
      u32 f = W(r4, 4);
      if (f) str = f;
      callNameLookup(self, str);
      if (W(edi, 0x10) == 0xb) {
        vcall<void>(s, 0x360, W(edi, 4));
      } else {
        u8 *s2 = vcall<u8 *>(T(), 0x58, W(edi, 0x15));
        if (vcall<u8>(s2, 0x1e0, (u32)0x1007d2) && vcall<u32>(s2, 0x328)) {
          L8 = W(edi, 4);
          u32 L10 = vcall<u32>(s2, 0x364);
          if (L10 > L8) {
            vcall<void>(s2, 0x360, L8);
          } else {
            vcall<void>(s2, 0x360, L10);
            L8 -= L10;
            if (L8 != 0) {
              u8 *ed = vcall<u8 *>(rd(self, 0x90), 0x55c, (u32)s2);
              if (!ed) {
                u8 *e3 = vcall<u8 *>(s2, 0x328);
                u32 r6 = vcall<u32>(rd(self, 0x90), 0x20, (u32)0x4954454d);
                u8 *r7 = vcall<u8 *>(e3, 0x2c4, r6);
                u32 r8 = table4c((u32)rd(self, 0x90), 0, 1, 3);
                vcall<void>(r7, 0x2f0, r8);
                ed = r7;
              }
              vcall<void>(ed, 0x324, L8);
            }
          }
        }
      }
    }
  }
  if (edi[0x14]) {
    ext_5af260(self + 0x1d4, edi);
    W(edi, 4) = 0;
  }
  u8 *o = rd(self, 0x94) + 0xe9b;
  ext_5aef10(o);
  u8 *lst = self + 0x1d4;
  s32 n = ext_4cc1d0(lst);
  for (s32 i = 0; i < n; i++) {
    u8 *it = ext_5af0d0(lst, (u32)i);
    if (it[0x14]) ext_5aee20(o, W(it, 0x10), W(it, 4));
  }
  ext_5b0290(rd(self, 0x28c));
  ext_569260(self);
}
PCREG(568dc0, fn568dc0);
