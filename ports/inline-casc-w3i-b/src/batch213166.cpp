#include "ff.h"

extern "C" void THISCALL ext_5aee60(void *self, u32 v);
extern "C" void THISCALL ext_5b04a0(void *self, void *a, void *b);
extern "C" void THISCALL ext_5b04c0(void *self, void *a, void *b);
extern "C" u32 THISCALL ext_5adda0(void *self);
extern "C" u32 THISCALL ext_5aef80(void *self, u32 id);
extern "C" void THISCALL ext_5b07d0(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_5b07f0(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_567930(void *self, void *arg);
extern "C" u32 THISCALL ext_5af230(void *self, u32 id);
extern "C" u32 THISCALL ext_5aefc0(void *self, u32 id);
extern "C" u32 THISCALL ext_5af130(void *self, u32 id);
extern "C" void THISCALL ext_5aedf0(void *self, void *node);
extern "C" void THISCALL ext_5afc10(void *self);
extern "C" void THISCALL ext_5afce0(void *self, void *out);
extern "C" void THISCALL ext_5af2a0(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_5b04e0(void *self, u32 a, u32 b, u32 c, u32 d, u32 e);
extern "C" void THISCALL ext_5af260(void *self, void *node);
extern "C" void THISCALL ext_5aef10(void *self);
extern "C" u32 THISCALL ext_4cc1d0(void *self);
extern "C" u32 THISCALL ext_5af0d0(void *self, u32 i);
extern "C" void THISCALL ext_5aee20(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_569260(void *self);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

#define EBP (fr + 0xb0)
#define P(off) (EBP - (off))

// 0x568350: thiscall() plain ret, /GS, void. Rebuilds the "slot" bookkeeping of the 0x94 object (obj90 = [this+0x94] + 0x57) from its sub-objects: the manager names
// 0x681320 (this+0x90), 0x6a7374 (this+0x180 list) and 0x6a738c (this+0x1d4 list) feed 5aee60; the kind byte [[this+0x94]+0x4a] - 0x32 (0..6) picks one of 5
// follow-ups through a jump table (the AL result of 0x5adda0 matters for kind 0x35), 0x567930 refreshes this+0x228, ids {3,5,6,7,8,0xb,4,0xa} that the C container
// (obj90+0xe44) knows are moved into the this+0x1d4 list, ids {0xd,0xc,0xe,0x10,0xf} missing there are added to a state struct handed by value to 0x5b04e0, the two
// ranges reported by 0x5b04a0 / 0x5b04c0 are clamped against the entity's slot 0x354, finally this[0x3ee..0x426] copies the table entries of the ids that are still absent.
static void body_568350(u8 *edi) {
  u8 fr[0xb8];
  __builtin_memset(fr, 0xcc, sizeof fr);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *T = (u8 *)R32(eng + 0x9b);
  W32(P(0x94), (u32)edi);
  u8 *X = vcall<u8 *>(T, 0x138);
  W32(P(0x7c), 0);
  vcall<u32>(X, 0x88, 0x681320u, P(0x7c));
  T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
  W32(edi + 0x90, vcall<u32>(T, 0x58, R32(P(0x7c))));
  T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
  X = vcall<u8 *>(T, 0x138);
  W32(P(0x7c), 0);
  vcall<u32>(X, 0x88, 0x6a7374u, P(0x7c));
  u8 *e180 = edi + 0x180;
  W32(P(0x84), (u32)e180);
  ext_5aee60(e180, R32(P(0x7c)));
  T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
  X = vcall<u8 *>(T, 0x138);
  W32(P(0x7c), 0);
  vcall<u32>(X, 0x88, 0x6a738cu, P(0x7c));
  u8 *ebx = edi + 0x1d4;
  ext_5aee60(ebx, R32(P(0x7c)));
  u8 *obj90 = (u8 *)R32(edi + 0x94) + 0x57;
  W32(P(0x90), (u32)obj90);
  u8 *esi = obj90 + 0xe18;
  ext_5b04a0(esi, P(0x8c), P(0xa0));
  ext_5b04c0(esi, P(0x88), P(0xa0));
  u8 al = (u8)ext_5adda0(obj90);
  u8 *o94 = (u8 *)R32(edi + 0x94);
  if (o94) {
    s32 k = (s32)(s8)o94[0x4a] - 0x32;
    bool step3 = false, step557 = false;
    // each case ends in the shared tails 0x568550 (5b07d0), 0x568557 (test -0x88), 0x568560 / 0x568570 (5b07f0)
    enum { T_END, T_557, T_560, T_570 } next = T_END;
    if ((u32)k <= 6) {
      switch (k) {
        case 0:
          if (R32(P(0x88)) == 0) {
            ext_5b07f0(esi, 4, ext_5aef80(e180, 3));
          }
          break;
        case 1:
        case 5:
          if (R32(P(0x8c)) == 0) ext_5b07d0(esi, 5, ext_5aef80(e180, 5));
          next = T_557;
          break;
        case 2:
          if (R32(P(0x8c)) == 0) ext_5b07d0(esi, 6, ext_5aef80(e180, 6));
          next = T_557;
          break;
        case 3:
          if (al) {
            ext_5b07d0(esi, 8, ext_5aef80(e180, 8));
            next = T_560;
          } else {
            if (R32(P(0x8c)) == 0) ext_5b07d0(esi, 8, ext_5aef80(e180, 8));
            next = T_557;
          }
          break;
        case 4:
          break;
        case 6:
          if (R32(P(0x8c)) == 0) ext_5b07d0(esi, 7, ext_5aef80(e180, 7));
          next = T_557;
          break;
      }
      (void)step3;
      (void)step557;
      if (next == T_557) {
        if (R32(P(0x88)) == 0) next = T_560;
        else next = T_END;
      }
      if (next == T_560) ext_5b07f0(esi, 3, ext_5aef80(e180, 3));
    }
  }
  ext_567930(edi, edi + 0x228);
  static const u32 listA[9] = {3, 5, 6, 7, 8, 0xb, 4, 0xa, 0};
  static const u32 listB[6] = {0xd, 0xc, 0xe, 0x10, 0xf, 0};
  for (int i = 0; i < 9; i++) W32(P(0x40) + 4 * i, listA[i]);
  u8 *C = obj90 + 0xe44;
  W32(P(0x80), 0);
  W32(P(0x7c), (u32)C);
  u32 id = 3;
  for (;;) {
    if (ext_5af230(C, id) != 0) {
      u32 r1 = ext_5aefc0(C, id);
      W32(P(0x84), r1);
      if (ext_5af130(ebx, id) == 0 && ext_5af130(ebx, id) == 0 && id != 0) {
        u8 *n = (u8 *)ext_5af130(e180, id);
        if (n) {
          W32(n + 4, R32(P(0x84)));
          n[0x14] = 1;
          ext_5aedf0(ebx, n);
        }
      }
    }
    u32 j = R32(P(0x80)) + 1;
    W32(P(0x80), j);
    id = R32(P(0x40) + 4 * j);
    if (id == 0) break;
  }
  ext_5afc10(P(0x78));
  ext_5afce0(P(0x78), P(0x54));
  for (int i = 0; i < 6; i++) W32(P(0x1c) + 4 * i, listB[i]);
  W32(P(8), 0);
  W32(P(0x80), 0);
  id = 0xd;
  for (;;) {
    u32 r = ext_5af130(ebx, id);
    if (r == 0) ext_5af2a0(P(0x54), id, 0);
    u32 j = R32(P(0x80)) + 1;
    W32(P(0x80), j);
    id = R32(P(0x1c) + 4 * j);
    if (id == 0) break;
  }
  esi = (u8 *)R32(P(0x90)) + 0xe18;
  ext_5b04e0(esi, R32(P(0x54)), R32(P(0x50)), R32(P(0x4c)), R32(P(0x48)), R32(P(0x44)));
  ext_5b04a0(esi, P(0x9c), P(0xa8));
  ext_5b04c0(esi, P(0x98), P(0xa4));
  for (u32 e = 0; e < 2; e++) {
    u32 idx = R32(P(0x9c) + 4 * e);
    u8 *n = (u8 *)ext_5af130(ebx, idx);
    if (n && n[0x14] != 0) {
      u8 *obj = (u8 *)R32(n);
      W32(P(0x84), (u32)obj);
      W32(n + 4, R32(n + 4) + R32(P(0xa8) + 4 * e));
      u32 lim = vcall<u32>(obj, 0x354) + R32(n + 0xc);
      if (R32(n + 4) > lim) W32(n + 4, vcall<u32>((u8 *)R32(P(0x84)), 0x354) + R32(n + 0xc));
      u8 *ec = (u8 *)R32(P(0x90)) + 0xe18;
      if (e != 0) ext_5b07f0(ec, R32(P(0x9c) + 4 * e), R32(n + 4));
      else ext_5b07d0(ec, R32(P(0x9c)), R32(n + 4));
      ext_5af260(ebx, n);
    }
  }
  ext_5aef10((u8 *)R32(P(0x7c)));
  u32 cnt = ext_4cc1d0(ebx);
  W32(P(0x84), cnt);
  if (cnt) {
    u8 *Cc = (u8 *)R32(P(0x7c));
    for (u32 i = 0; i < cnt; i++) {
      u8 *n = (u8 *)ext_5af0d0(ebx, i);
      if (n[0x14] != 0) ext_5aee20(Cc, R32(n + 0x10), R32(n + 4));
    }
  }
  vcall<u32>(edi, 0x64, 0x10u);
  W32(P(0x80), 0);
  id = 3;
  for (;;) {
    u8 *n = (u8 *)ext_5af130(ebx, id);
    if (n && n[0x14] == 0) {
      static const u32 pairs[8][2] = {{0x3f2, 0x3ee}, {0x3fa, 0x3f6}, {0x402, 0x3fe}, {0x40a, 0x406}, {0x412, 0x40e}, {0x41a, 0x416}, {0x422, 0x41e}, {0x42a, 0x426}};
      for (int p = 0; p < 8; p++)
        if (R32(edi + pairs[p][0]) == id) W32(edi + pairs[p][1], R32(edi + id * 12 + 0x326));
    }
    u32 j = R32(P(0x80)) + 1;
    W32(P(0x80), j);
    id = R32(P(0x40) + 4 * j);
    if (id == 0) break;
  }
  ext_569260(edi);
}
extern "C" void THISCALL fn_568350(u8 *self);
extern "C" void THISCALL fn_568350(u8 *self) {
  body_568350(self);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(568350, fn_568350);
