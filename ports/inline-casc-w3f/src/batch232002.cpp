// batch232002.cpp - Sonnet-w3f, hand-written ports (read from the disassembly).
#include "ff.h"
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
extern "C" u32 THISCALL ext_517050_w3(u32, u32, u32, u32) __asm__("ext_517050");
extern "C" u32 THISCALL ext_5273b0_f0(u32) __asm__("ext_5273b0");
extern "C" u32 THISCALL ext_511c60_f0(u32) __asm__("ext_511c60");

// 0x51f3e0 thiscall(a, b, c) ret 0xc constructor returning this (SEH 0x66a2e8, state 0 after the base ctor)
extern "C" u32 THISCALL hand_51f3e0(u32 this_, u32 A1, u32 A2, u32 A3) {
  SEH_ENTER(0x66a2e8);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  ext_517050_w3(this_, A1, A2, A3);  // @h1_51f3e0
  reg.state = 0;  // @h2_51f3e0
  F32(this_, 0x0) = 0x69fb3c;  // @h3_51f3e0
  ext_5273b0_f0(this_ + 0x1684);  // @h4_51f3e0
  ext_511c60_f0(this_ + 0x16e5);  // @h5_51f3e0
  u32 sub = F32(this_, 0x1684);  // @h6_51f3e0
  F32(this_, 0x1654) = 0x0;  // @h7_51f3e0
  F32(this_, 0x1658) = 0x0;  // @h8_51f3e0
  F32(this_, 0x165c) = 0x0;  // @h9_51f3e0
  ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)sub))(this_ + 0x1684, 0x3f860a92, 0x3f5f66f3, 0x40c90fdb);  // @h10_51f3e0
  SEH_LEAVE();
  return this_;
#undef F32
}
PCREG(51f3e0, hand_51f3e0);

extern "C" u32 THISCALL ext_4cc630_t1(u32, u32) __asm__("ext_4cc630");
extern "C" u32 ext_634273_c2(u32, u32) __asm__("ext_634273");
// 0x4cbf30 thiscall(value) ret 4: this = itoa(value, 10) as a string-class assign (SEH 0x6691db, state 0 after the temporary string)
extern "C" u32 THISCALL hand_4cbf30(u32 this_, u32 a0) {
  SEH_ENTER(0x6691db);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u8 buf[0x80] __attribute__((aligned(4)));
  u8 Lb[0x110] __attribute__((aligned(4)));   // exe local string at ebp-0x110: pointer + inline buffer at +4
  u32 L = (u32)Lb;
  u32 e = ((u32(*)(u32, u32, u32))G(u32, 0x6762d0))(a0, (u32)buf, 10);  // @h1_4cbf30
  ext_4cc630_t1(L, e ? e : 0x677b5a);  // @h2_4cbf30
  reg.state = 0;  // @h3_4cbf30
  if (this_ != L) {  // @h4_4cbf30
    u32 p = F32(this_, 0);
    if (p != this_ + 4) ext_634273_c2(p, 1);  // @h5_4cbf30
    ext_4cc630_t1(this_, F32(L, 0));  // @h6_4cbf30
  }
  u32 p2 = F32(L, 0);
  if (p2 != L + 4) ext_634273_c2(p2, 1);  // @h7_4cbf30
  SEH_LEAVE();
  return this_;
#undef F32
}
PCREG(4cbf30, hand_4cbf30);

extern "C" u32 THISCALL ext_6014a0_t1(u32, u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_5f2d60_t2(u32, u32, u32) __asm__("ext_5f2d60");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
// 0x600d70 thiscall(cstr, val) ret 8: allocates a 0x18-byte node whose string member (node+0xc) gets an 8-byte buffer, stores it in *this, copies cstr in
extern "C" u32 THISCALL hand_600d70(u32 this_, u32 cstr, u32 val) {
  SEH_ENTER(0x66dc9f);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 node = ext_41e290_cdecl1((u32)0x18);  // @h1_600d70
  reg.state = 0;  // @h2_600d70
  if (node) {  // @h3_600d70
    u32 s = node + 0xc;
    F32(s, 0) = 0;  // @h4_600d70
    F32(s, 4) = 0;  // @h5_600d70
    F32(s, 8) = 0;  // @h6_600d70
    u32 b = ext_6014a0_t1(s, 8);  // @h7_600d70
    F32(s, 0) = b;  // @h8_600d70
    F32(s, 4) = b;  // @h9_600d70
    F32(s, 8) = b + 8;  // @h10_600d70
    if (b) *(volatile u8 *)b = 0;
    *(volatile u8 *)b = 0;  // @h11_600d70
  }
  reg.state = -1;  // @h12_600d70
  F32(this_, 0) = node;  // @h13_600d70
  u32 len = 0;
  while (*(volatile u8 *)(cstr + len)) len++;  // @h14_600d70
  ext_5f2d60_t2(node + 0xc, cstr, cstr + len);  // @h15_600d70
  F32(F32(this_, 0), 0) = 0;  // @h16_600d70
  F32(F32(this_, 0), 4) = val;  // @h17_600d70
  SEH_LEAVE();
  return this_;
#undef F32
}
PCREG(600d70, hand_600d70);

extern "C" u32 THISCALL ext_5fcc40_t2(u32, u32, u32) __asm__("ext_5fcc40");
extern "C" u32 THISCALL ext_5f10c0_t1(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fc2f0_t3(u32, u32, u32, u32) __asm__("ext_5fc2f0");
extern "C" u32 THISCALL ext_54f870_t2(u32, u32, u32) __asm__("ext_54f870");
// 0x5fb110 thiscall(key*) ret 4: map operator[] -> returns &value (node + 0x19); inserts when the lower bound is end or key < node key
extern "C" u32 THISCALL hand_5fb110(u32 M, u32 K) {
  SEH_ENTER(0x66da8e);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 it = 0;
  u32 kslot = K;
  u32 tmp[4] = {0, 0, 0, 0};
  ext_5fcc40_t2(M, (u32)&it, K);  // @h1_5fb110
  u32 esi = it;
  bool ins;
  if (esi == F32(M, 0)) {  // @h2_5fb110
    ins = true;
  } else {
    u32 nb = F32(esi, 0xd), ne = F32(esi, 0x11);
    s32 l1 = (s32)(ne - nb);
    u32 kb = F32(K, 0), ke = F32(K, 4);
    s32 l2 = (s32)(ke - kb);
    s32 n = (l1 >= l2) ? l2 : l1;  // @h3_5fb110
    s32 r = ((s32(*)(u32, u32, u32))G(u32, 0x676408))(kb, nb, (u32)n);  // @h4_5fb110
    if (r != 0) ins = r < 0;  // @h5_5fb110
    else ins = l2 < l1;  // @h6_5fb110
  }
  if (ins) {
    ext_5f10c0_t1((u32)tmp, K);  // @h7_5fb110
    tmp[3] = 0;
    reg.state = 0;  // @h8_5fb110
    ext_5fc2f0_t3(M, (u32)&kslot, esi, (u32)tmp);  // @h9_5fb110
    esi = kslot;
    u32 sz = tmp[2] - tmp[0];
    reg.state = 1;  // @h10_5fb110
    if (tmp[0] && sz) ext_54f870_t2((u32)tmp, tmp[0], sz);  // @h11_5fb110
  }
  SEH_LEAVE();
  return esi + 0x19;  // @h12_5fb110
#undef F32
}
PCREG(5fb110, hand_5fb110);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_4ccba0_t0(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_t0(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ce480_t1(u32, u32) __asm__("ext_4ce480");
extern "C" u32 THISCALL ext_4cf2d0_t1(u32, u32) __asm__("ext_4cf2d0");
// 0x496380 thiscall(bitmap) ret 4: clears the bits [A / 448, (A + B) / 448) of the bitmap for every {A, B} range of a REFTAB list
extern "C" u32 THISCALL hand_496380(u32 this_, u32 bm) {
  SEH_ENTER(0x66681b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  volatile u32 L[4];
  volatile u32 it[2];
  u32 Lp = (u32)(u32 *)L;
  ext_4ccba0_t0(Lp);  // @h1_496380
  reg.state = 0;  // @h2_496380
  u32 q = F32(F32(this_, 0x14), 0);  // @h3_496380
  ext_4ce480_t1(q, Lp);  // @h4_496380
  ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x4c))(Lp, (u32)it);  // @h5_496380
  u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x64))(Lp, (u32)it);  // @h6_496380
  while (r) {  // @h7_496380
    u32 esi = F32(r, 0);
    u32 bp = ext_4cf2d0_t1(Lp, (u32)it);  // @h8_496380
    u32 edi = F32(bp, 0) + esi;  // @h9_496380
    u32 h1 = (u32)(((unsigned long long)edi * 0x24924925ull) >> 32);
    edi = (((edi - h1) >> 1) + h1) >> 6;  // @h10_496380
    u32 h2 = (u32)(((unsigned long long)esi * 0x24924925ull) >> 32);
    esi = (((esi - h2) >> 1) + h2) >> 6;  // @h11_496380
    if (esi != edi) {  // @h12_496380
      do {
        volatile u8 *p = (volatile u8 *)(bm + (esi >> 3));
        *p = (u8)(*p & ~(1u << (esi & 7)));  // @h13_496380
        esi++;
      } while (esi != edi);  // @h14_496380
    }
    r = ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x64))(Lp, (u32)it);  // @h15_496380
  }
  u32 rv = ext_4ccf60_t0(Lp);  // @h16_496380
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return rv;
#undef F32
}
PCREG(496380, hand_496380);

extern "C" u32 ext_634273_c2b(u32, u32) __asm__("ext_634273");
// 0x45e710 thiscall() (plain ret): releases the sub-object at [this+0x10] (eax is the caller's junk on every path, the spec compares ret=None)
extern "C" u32 THISCALL hand_45e710(u32 this_) {
  SEH_ENTER(0x66d436);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  if (F32(this_, 0x10) != 0) {  // @h1_45e710
    ((u32(THISCALL *)(u32))VSLOT(this_, 8))(this_);  // @h2_45e710
    ((u32(THISCALL *)(u32))VSLOT(this_, 0x140))(this_);  // @h3_45e710
    u32 edx = F32(F32(this_, 0x10), 0xc);
    if (edx != 0) {  // @h4_45e710
      u32 ecx = F32(F32(G(u32, 0x70039c), 0x9b), 0x1c5d);
      bool fr;
      if (edx < ecx) fr = true;  // @h5_45e710
      else if (ecx == 0) fr = true;  // @h6_45e710
      else fr = !(edx < ((F32(ecx, (u32)-8) & 0x1fffffff) + ecx));  // @h7_45e710
      if (fr) ext_634273_c2b(edx, 0x18);  // @h8_45e710
    }
    u32 p = F32(F32(this_, 0x10), 0x10);
    if (p) ext_634273_c2b(p, 8);  // @h9_45e710
    u32 q = F32(F32(this_, 0x10), 0x1c);
    if (q) {  // @h10_45e710
      u32 r = F32(q, 4);
      if (r) {  // @h11_45e710
        u32 t = F32(r, 4);
        if (t) {  // @h12_45e710
          u32 eng = G(u32, 0x7003a4);
          ((u32(THISCALL *)(u32, u32))VSLOT(eng, 0x6c))(eng, t);  // @h13_45e710
        }
      }
      u32 edi = F32(F32(this_, 0x10), 0x1c);
      if (edi) {  // @h14_45e710
        u32 ebx = F32(edi, 4);
        if (ebx) {  // @h15_45e710
          reg.state = 0;  // @h16_45e710
          u32 eng = G(u32, 0x7003a4);
          if (eng) {  // @h17_45e710
            u32 d = F32(ebx, 0xc);
            if (d) ((u32(THISCALL *)(u32, u32))VSLOT(eng, 0x58))(eng, d);  // @h18_45e710
          }
          ext_634273_c2b(ebx, 0x10);  // @h19_45e710
          F32(edi, 4) = 0;  // @h20_45e710
        }
        ext_634273_c2b(edi, 8);  // @h21_45e710
      }
    }
    ext_634273_c2b(F32(this_, 0x10), 0x20);  // @h22_45e710
    F32(this_, 0x10) = 0;  // @h23_45e710
  }
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(45e710, hand_45e710);

extern "C" u32 THISCALL ext_5ab2e0_t1(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5aba60_t4(u32, u32, u32, u32, u32) __asm__("ext_5aba60");
extern "C" u32 THISCALL ext_5ac5d0_t1(u32, u32) __asm__("ext_5ac5d0");
extern "C" u32 THISCALL ext_5acac0_t1(u32, u32) __asm__("ext_5acac0");
extern "C" u32 THISCALL ext_5ac940_t1(u32, u32) __asm__("ext_5ac940");
extern "C" u32 THISCALL ext_5ac620_t2(u32, u32, u32) __asm__("ext_5ac620");
extern "C" u32 THISCALL ext_5ac640_t2(u32, u32, u32) __asm__("ext_5ac640");
// 0x5f0880 thiscall(a1, a2) ret 8: creates 28 UI widgets (0xa8-byte objects) in this+4..+0x74 laid out on a vertical line
extern "C" u32 THISCALL hand_5f0880(u32 this_, u32 a1, u32 a2) {
  SEH_ENTER(0x66cd42);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 sysobj = G(u32, 0x70039c);
  u32 ctx = F32(sysobj, 0x190f);
  s32 dc = (s32)((u32(THISCALL *)(u32))VSLOT(ctx, 0xdc))(ctx);  // @h1_5f0880
  s32 half = (dc - 0x1c0) / 2;  // @h2_5f0880
  *(volatile float *)(this_ + 0x8c) = (float)half;  // @h3_5f0880
  u32 last = 0;
  for (u32 i = 0; i < 0x1c; i++) {  // @h4_5f0880
    u32 node = ext_41e290_cdecl1((u32)0xa8);  // @h5_5f0880
    reg.state = 0;  // @h6_5f0880
    u32 obj = 0;
    if (node) obj = ext_5ab2e0_t1(node, 1);  // @h7_5f0880
    reg.state = -1;  // @h8_5f0880
    F32(this_, 4 + 4 * i) = obj;  // @h9_5f0880
    ext_5aba60_t4(obj, a1, a2, 0, 0);  // @h10_5f0880
    ext_5ac5d0_t1(F32(this_, 4 + 4 * i), 0xffffffffu);  // @h11_5f0880
    ext_5acac0_t1(F32(this_, 4 + 4 * i), 1);  // @h12_5f0880
    ext_5ac940_t1(F32(this_, 4 + 4 * i), 0x6b82d8);  // @h13_5f0880
    ext_5ac620_t2(F32(this_, 4 + 4 * i), 3, 0);  // @h14_5f0880
    double d = (double)(s32)i + G(double, 0x680aa0 + 8 * (i >> 31));  // @h15_5f0880
    volatile float f = (float)d;
    volatile float t = f * G(float, 0x6a60a0);  // @h16_5f0880
    volatile float rr = t + *(volatile float *)(this_ + 0x8c);  // @h17_5f0880
    last = ext_5ac640_t2(F32(this_, 4 + 4 * i), 1, (u32)(s32)rr);  // @h18_5f0880
  }
  F32(this_, 0x74) = 0;  // @h19_5f0880
  SEH_LEAVE();
  return last;
#undef F32
}
PCREG(5f0880, hand_5f0880);

extern "C" u32 THISCALL ext_5f2c60_t2(u32, u32, u32) __asm__("ext_5f2c60");
// 0x602290 thiscall(s1, s2, s3, s4) ret 0x10: constructor of four string members (this+0, +0xc, +0x18, +0x24), SEH 0x66d989
static inline void init_str_602290(u32 m) {
  *(volatile u32 *)(m + 0) = 0;
  *(volatile u32 *)(m + 4) = 0;
  *(volatile u32 *)(m + 8) = 0;
  u32 b = ext_6014a0_t1(m, 8);
  *(volatile u32 *)(m + 0) = b;
  *(volatile u32 *)(m + 4) = b;
  *(volatile u32 *)(m + 8) = b + 8;
  if (b) *(volatile u8 *)b = 0;
  *(volatile u8 *)b = 0;
}
static inline u32 len_602290(u32 p) { u32 n = 0; while (*(volatile u8 *)(p + n)) n++; return n; }
extern "C" u32 THISCALL hand_602290(u32 this_, u32 s1, u32 s2, u32 s3, u32 s4) {
  SEH_ENTER(0x66d989);
  init_str_602290(this_);  // @h1_602290
  reg.state = 0;  // @h2_602290
  init_str_602290(this_ + 0xc);  // @h3_602290
  reg.state = 1;  // @h4_602290
  init_str_602290(this_ + 0x18);  // @h5_602290
  reg.state = 2;  // @h6_602290
  init_str_602290(this_ + 0x24);  // @h7_602290
  reg.state = 3;  // @h8_602290
  if (s1) ext_5f2d60_t2(this_ + 0x18, s1, s1 + len_602290(s1));  // @h9_602290
  if (s2) ext_5f2d60_t2(this_ + 0x24, s2, s2 + len_602290(s2));  // @h10_602290
  if (s3) {  // @h11_602290
    ext_5f2d60_t2(this_, 0x67b1a0, 0x67b1a1);  // @h12_602290
    ext_5f2c60_t2(this_, s3, s3 + len_602290(s3));  // @h13_602290
    ext_5f2c60_t2(this_, 0x67b1a0, 0x67b1a1);  // @h14_602290
  }
  if (s4) {  // @h15_602290
    ext_5f2d60_t2(this_ + 0xc, 0x67b1a0, 0x67b1a1);  // @h16_602290
    ext_5f2c60_t2(this_ + 0xc, s4, s4 + len_602290(s4));  // @h17_602290
    ext_5f2c60_t2(this_ + 0xc, 0x67b1a0, 0x67b1a1);  // @h18_602290
  }
  SEH_LEAVE();
  return this_;
}
PCREG(602290, hand_602290);

extern "C" u32 THISCALL ext_57c910_t1(u32, u32) __asm__("ext_57c910");
extern "C" u32 FASTCALL ext_57d200_f(u32, u32) __asm__("ext_57d200");
extern "C" u32 THISCALL ext_4cbe80_s1(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbee0_s1(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbec0_s0(u32) __asm__("ext_4cbec0");
// 0x57d500 thiscall(obj, key) ret 8 -> bool (al): looks the key up and fills obj from a table entry (SEH 0x66b2ab, /GS cookie)
extern "C" u32 THISCALL hand_57d500(u32 this_, u32 a1, u32 a2) {
  SEH_ENTER(0x66b2ab);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 res = 0;
  u32 key = a2;
  if (key == 0) key = F32(F32(this_, 0), 0);  // @h1_57d500
  u32 c4 = F32(this_, 4);
  u32 r = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c4, 0x40))(c4, key, 0);  // @h2_57d500
  if (r) {  // @h3_57d500
    ext_57c910_t1(a1, r);  // @h4_57d500
    res = 1;
    goto done;
  }
  {
    u32 sysr = G(u32, 0x70039c);
    u32 rg = F32(sysr, 0x1907);
    u32 t = ((u32(THISCALL *)(u32, u32))VSLOT(rg, 0x60))(rg, 0x69c690);  // @h5_57d500
    if (t == 0) {  // @h6_57d500
      u32 mgr = F32(sysr, 0x9b);
      u32 dev = ((u32(THISCALL *)(u32))VSLOT(mgr, 0x138))(mgr);  // @h7_57d500
      volatile u32 out = 0;
      ((u32(THISCALL *)(u32, u32, u32))VSLOT(dev, 0x88))(dev, 0x6aad08, (u32)&out);  // @h8_57d500
      u32 lo = F32(this_, 8);
      u32 outv = out;
      u32 w = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(mgr, 0x114))(mgr, 0x6aacec, 0, 0x6aacc0, 0x109, 0);  // @h9_57d500
      ((u32(THISCALL *)(u32, u32, u32))VSLOT(lo, 0x12c))(lo, outv, w & 0xffff);  // @h10_57d500
      sysr = G(u32, 0x70039c);
      rg = F32(sysr, 0x1907);
      t = ((u32(THISCALL *)(u32, u32))VSLOT(rg, 0x60))(rg, 0x69c690);  // @h11_57d500
      if (t == 0) { res = 0; goto done; }  // @h12_57d500
    }
    u32 ho = F32(t, 0x15);
    u32 found = 0;
    u32 tbl = ((u32(THISCALL *)(u32))VSLOT(ho, 0))(ho);  // @h13_57d500
    u32 idx = 0;
    if (F32(tbl, 0) == 0) { res = 0; goto done; }  // @h14_57d500
    u32 e = tbl;
    do {
      s32 cmp = ((s32(*)(u32, u32))G(u32, 0x676414))(F32(e, 0), key);  // @h15_57d500
      if (cmp == 0) {  // @h16_57d500
        F32(a1, 0xa1) = F32(e, 4);  // @h17_57d500
        u8 tmp[0x80] __attribute__((aligned(16)));
        ext_4cbe80_s1((u32)tmp, key);  // @h18_57d500
        reg.state = 0;  // @h19_57d500
        ext_4cbee0_s1(a1, (u32)tmp);  // @h20_57d500
        reg.state = -1;  // @h21_57d500
        ext_4cbec0_s0((u32)tmp);  // @h22_57d500
        *(volatile u8 *)(a1 + 0xa0) = 1;  // @h23_57d500
        for (int k = 0; k < 16; k++) { *(volatile u8 *)(a1 + 0x90 + k) = 0xff; *(volatile u8 *)(a1 + 0x80 + k) = 0xff; }  // @h24_57d500
        if (F32(e, 0xc)) ext_57d200_f(F32(e, 0xc), a1 + 0x90);  // @h25_57d500
        if (F32(e, 8)) ext_57d200_f(F32(e, 8), a1 + 0x80);  // @h26_57d500
        F32(a1, 0xab) = F32(e, 0x14);  // @h27_57d500
        F32(a1, 0xa7) = F32(e, 0x10);  // @h28_57d500
        F32(a1, 0xaf) = 0;  // @h29_57d500
        found = 1;
      }
      idx++;
      e = tbl + idx * 28;  // @h30_57d500
    } while (F32(e, 0) != 0);  // @h31_57d500
    res = found;  // @h32_57d500
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return res;
#undef F32
}
PCREG(57d500, hand_57d500);

extern "C" u32 THISCALL ext_603500_t1(u32, u32) __asm__("ext_603500");
static inline void fatal_603a50() {
  u32 f = *(volatile u32 *)0x7003b0;
  if (f) ((void(STDCALL *)(void))f)();
  else __builtin_trap();
}
// 0x603a50 thiscall(src) ret 4: builds a new variant array (ctor 0x603500) from src's three nested vectors with bounds asserts ([0x7003b0] handler)
extern "C" u32 THISCALL hand_603a50(u32 this_, u32 src) {
  SEH_ENTER(0x66dc9f);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  u32 cnt = F32(this_, 0x14);
  u32 anode = ext_41e290_cdecl1((u32)0x18);  // @h1_603a50
  reg.state = 0;  // @h2_603a50
  u32 node = 0;
  if (anode) node = ext_603500_t1(anode, cnt);  // @h3_603a50
  reg.state = -1;  // @h4_603a50
  for (u32 i = 0; F32(this_, 0x14) > i; i++) {  // @h5_603a50
    u32 s1 = F32(src, 4);
    u32 eb;
    if (i < F32(s1, 8)) {  // @h6_603a50
      u32 b = F32(s1, 4) + i;
      u32 s2 = F32(s1, 0);
      if (!(b < F32(s2, 8))) fatal_603a50();  // @h7_603a50
      eb = F32(s2, 0) + b * 8;
    } else {
      fatal_603a50();  // @h8_603a50
      u32 s2 = F32(s1, 0);
      if (!(i < F32(s2, 8))) fatal_603a50();  // @h9_603a50
      eb = F32(s2, 0) + i * 8;
    }
    if (!(i < F32(node, 0x14))) fatal_603a50();  // @h10_603a50
    u32 ed = F32(node, 0xc) + i * 8;
    if (eb != ed) {  // @h11_603a50
      if (F8(ed, 4) == 4) {  // @h12_603a50
        u32 o = F32(ed, 0);
        ((u32(THISCALL *)(u32))VSLOT(o, 0x28))(o);  // @h13_603a50
      }
      u32 v;
      if (F8(eb, 4) == 4) {  // @h14_603a50
        u32 o = F32(eb, 0);
        v = ((u32(THISCALL *)(u32))VSLOT(o, 0x24))(o);  // @h15_603a50
      } else {
        v = F32(eb, 0);  // @h16_603a50
      }
      F32(ed, 0) = v;  // @h17_603a50
      F8(ed, 4) = F8(eb, 4);  // @h18_603a50
    }
  }
  u32 s3 = F32(src, 8);
  u32 es;
  if (F32(s3, 8) > 0) {  // @h19_603a50
    u32 b = F32(s3, 4);
    u32 s2 = F32(s3, 0);
    if (!(b < F32(s2, 8))) fatal_603a50();  // @h20_603a50
    es = F32(s2, 0) + b * 8;
  } else {
    fatal_603a50();  // @h21_603a50
    u32 s2 = F32(s3, 0);
    if (!(F32(s2, 8) > 0)) fatal_603a50();  // @h22_603a50
    es = F32(s2, 0);
  }
  u8 ty = F8(es, 4);
  bool doclone = true;
  if (ty != 0) {  // @h23_603a50
    if (ty != 4) doclone = false;  // @h24_603a50
    else {
      u32 o = F32(es, 0);
      ((u32(THISCALL *)(u32))VSLOT(o, 0x28))(o);  // @h25_603a50
    }
  }
  if (doclone) {
    u32 cl = ((u32(THISCALL *)(u32))VSLOT(node, 0x24))(node);  // @h26_603a50
    F32(es, 0) = cl;  // @h27_603a50
    F8(es, 4) = 4;  // @h28_603a50
  }
  u32 rv = ((u32(THISCALL *)(u32))VSLOT(node, 0x28))(node);  // @h29_603a50
  SEH_LEAVE();
  return rv;
#undef F32
#undef F8
}
PCREG(603a50, hand_603a50);

extern "C" u32 THISCALL ext_4da3a0_t0(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4cd540_t1(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4dc630_t2(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4cc1d0_t0(u32) __asm__("ext_4cc1d0");
// 0x45cd90 thiscall(flags, a2, a3, a4) ret 0x10: applies a2/a3 to every registered object of the owner's list that passes the flag filters (SEH 0x666733, /GS)
extern "C" u32 THISCALL hand_45cd90(u32 this_, u32 a1, u32 a2, u32 a3, u32 a4) {
  SEH_ENTER(0x666733);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  u32 res = 1;
  u32 fl = 0;
  volatile u32 Rb[0x70];
  volatile u32 it[2];
  u32 Rp = (u32)(u32 *)Rb;
  u8 tmp90[0x80] __attribute__((aligned(16)));
  u8 tmp110[0x80] __attribute__((aligned(16)));
  if (!(u8)ext_4da3a0_t0(F32(this_, 8))) goto done;  // @h1_45cd90
  ext_4ccba0_t0(Rp);  // @h2_45cd90
  reg.state = 0;  // @h3_45cd90
  {
    u32 lo = F32(F32(this_, 0x10), 8);
    if (lo) {  // @h4_45cd90
      ((u32(THISCALL *)(u32, u32))VSLOT(lo, 0x4c))(lo, (u32)it);  // @h5_45cd90
      u32 id = ((u32(THISCALL *)(u32, u32))VSLOT(lo, 0x5c))(lo, (u32)it);  // @h6_45cd90
      while (it[0] != 0) {  // @h7_45cd90
        u32 gm = G(u32, 0x70038c);
        u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(gm, 0xcc))(gm, id);  // @h8_45cd90
        if (ob == 0) {  // @h9_45cd90
          ((u32(THISCALL *)(u32, u32))VSLOT(lo, 0x44))(lo, (u32)it);  // @h10_45cd90
        } else {
          ext_4cd540_t1(Rp, id);  // @h11_45cd90
        }
        id = ((u32(THISCALL *)(u32, u32))VSLOT(lo, 0x5c))(lo, (u32)it);  // @h12_45cd90
      }
    }
  }
  {
    ((u32(THISCALL *)(u32, u32))VSLOT(Rp, 0x4c))(Rp, (u32)it);  // @h13_45cd90
    u32 id = ((u32(THISCALL *)(u32, u32))VSLOT(Rp, 0x5c))(Rp, (u32)it);  // @h14_45cd90
    while (it[0] != 0) {  // @h15_45cd90
      u32 gm = G(u32, 0x70038c);
      u32 s = ((u32(THISCALL *)(u32, u32))VSLOT(gm, 0xcc))(gm, id);  // @h16_45cd90
      if (s != 0) {  // @h17_45cd90
        u32 c1 = a1 & 1, c2 = a1 & 2;
        if (c1 && (F32(s, 4) & 4)) goto nxt;  // @h18_45cd90
        if (c2 && (F32(s, 4) & 8)) goto nxt;  // @h19_45cd90
        if (a1 == 4 && !(F8(s, 4) & 4)) goto nxt;  // @h20_45cd90
        {
          u32 e4 = F32(s, 4) & 4;
          bool p2 = (e4 != 0) || !(F8(s, 0x14) & 1) || a1 == 1;  // @h21_45cd90
          if (!p2) {
            u32 cs;
            if (a4) {  // @h22_45cd90
              u32 so = ((u32(THISCALL *)(u32, u32, u32))VSLOT(a4, 0x1d8))(a4, (u32)tmp90, 1);  // @h23_45cd90
              fl |= 1;
              reg.state = 1;  // @h24_45cd90
              cs = ext_4cc1d0_t0(so);  // @h25_45cd90
            } else {
              cs = 0x685178;  // @h26_45cd90
            }
            u32 lgo = G(u32, 0x700390);
            u32 lg = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lgo, 0x20))(lgo, 0x685054, 0x654);  // @h27_45cd90
            u32 so2 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(this_, 0x1d8))(this_, (u32)tmp110, 1);  // @h28_45cd90
            reg.state = 2;  // @h29_45cd90
            u32 r14 = ((u32(THISCALL *)(u32))VSLOT(s, 0x14))(s);  // @h30_45cd90
            u32 cs2 = ext_4cc1d0_t0(so2);  // @h31_45cd90
            ((u32(*)(u32, u32, u32, u32, u32))VSLOT(lg, 0x2c))(lg, 0x685180, cs2, r14, cs);  // @h32_45cd90
            ext_4cbec0_s0((u32)tmp110);  // @h33_45cd90
            reg.state = 0;  // @h34_45cd90
            if (fl & 1) {  // @h35_45cd90
              fl &= ~1u;
              ext_4cbec0_s0((u32)tmp90);  // @h36_45cd90
            }
            goto nxt;
          }
        }
        if (F32(s, 0x1c) != 0) goto nxt;  // @h37_45cd90
        {
          u32 ecx = F32(s, 0x14);
          if (!((a1 & ecx) || a1 == 4 || a1 == 0x20)) goto nxt;  // @h38_45cd90
          u32 e4 = F32(s, 4) & 4;
          if (e4 == 0 && (ecx & 1) && a1 != 1) {  // @h39_45cd90
            u32 lgo = G(u32, 0x700390);
            u32 lg = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lgo, 0x20))(lgo, 0x685054, 0x662);  // @h40_45cd90
            u32 so = ((u32(THISCALL *)(u32, u32, u32))VSLOT(this_, 0x1d8))(this_, (u32)tmp90, 1);  // @h41_45cd90
            reg.state = 3;  // @h42_45cd90
            u32 cs = ext_4cc1d0_t0(so);  // @h43_45cd90
            u32 r14 = ((u32(THISCALL *)(u32))VSLOT(s, 0x14))(s);  // @h44_45cd90
            ((u32(*)(u32, u32, u32, u32))VSLOT(lg, 0x2c))(lg, 0x6851c8, r14, cs);  // @h45_45cd90
            reg.state = 0;  // @h46_45cd90
            ext_4cbec0_s0((u32)tmp90);  // @h47_45cd90
            goto nxt;
          }
        }
        {
          u32 mgr = F32(G(u32, 0x70039c), 0x9b);
          u32 id2 = ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 0x4c))(mgr, this_);  // @h48_45cd90
          ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(s, 0x48))(s, a1, a3, a2);  // @h49_45cd90
          mgr = F32(G(u32, 0x70039c), 0x9b);
          u32 ok = ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 0x54))(mgr, id2);  // @h50_45cd90
          if (ok == 0) { res = 0; goto fin; }  // @h51_45cd90
          if (c1) F32(s, 4) |= 4;  // @h52_45cd90
          if (c2) F32(s, 4) |= 8;  // @h53_45cd90
          if (F8(s, 4) & 1) ((u32(THISCALL *)(u32, u32))VSLOT(s, 0x54))(s, this_);  // @h54_45cd90
        }
      }
    nxt:
      id = ((u32(THISCALL *)(u32, u32))VSLOT(Rp, 0x5c))(Rp, (u32)it);  // @h55_45cd90
    }
    if (a1 == 1) ext_4dc630_t2(F32(this_, 8), 0x800000, 0);  // @h56_45cd90
    res = 1;
  fin:
    ext_4ccf60_t0(Rp);  // @h57_45cd90
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return res;
#undef F32
#undef F8
}
PCREG(45cd90, hand_45cd90);

extern "C" u32 THISCALL ext_57d950_t1(u32, u32) __asm__("ext_57d950");
extern "C" u32 THISCALL ext_57ee90_t0(u32) __asm__("ext_57ee90");
extern "C" u32 THISCALL ext_57d780_t0(u32) __asm__("ext_57d780");
extern "C" u32 THISCALL ext_4cbeb0_t0(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbe50_s1(u32, u32) __asm__("ext_4cbe50");
// 0x57e4f0 thiscall() plain ret (the spec compares ret=None): clears the active flags, finds the first set flag outside the reserved ranges, selects its object
extern "C" u32 THISCALL hand_57e4f0(u32 T) {
  SEH_ENTER(0x66b381);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  u8 S188[0x80] __attribute__((aligned(16)));
  u8 tmpA4[0x80] __attribute__((aligned(16)));
  u8 D4[0x80] __attribute__((aligned(16)));
  volatile u32 it[2];
  u32 cnt = 0;
  bool found = false;
  for (u32 e = 0; e < F32(T, 0x338); e++) {  // @h1_57e4f0
    if (F8(F32(T, 0x32c), e) != 0) F8(F32(T, 0x330), e) = 0;  // @h2_57e4f0
  }
  u32 B = F32(T, 0x330);
  if (F32(T, 0x338) == 0) goto done;  // @h3_57e4f0
  {
    u32 esi = 0;
    do {
      if (found) break;  // @h4_57e4f0
      if (F8(B, esi) != 0 && esi != 0x90) {  // @h5_57e4f0
        u32 eax;
        if (esi & 0xffff0000u) {
          eax = esi;  // @h6_57e4f0
        } else {
          u32 ed = F32(G(u32, 0x70039c), 0x190b);
          u32 idx = 0;
          if (ed == 0) {
            eax = 0xffffffffu;  // @h7_57e4f0
          } else {
            for (;;) {
              s32 st = (s32)F32(ed, 0);
              if (!(st > (s32)esi)) {  // @h8_57e4f0
                if ((s32)(F32(ed, 0xc) + st) > (s32)esi) { eax = (idx << 16) - st + esi; break; }  // @h9_57e4f0
              }
              idx++;
              ed += 0x10;  // @h10_57e4f0
            }
          }
        }
        u32 hi = eax >> 16;
        bool collect = false;
        if (hi == 1) {  // @h11_57e4f0
          u32 lo = eax & 0xffff;
          if (lo < 7 || lo > 10) collect = true;  // @h12_57e4f0
        } else if (hi == 0 && esi == 0) {  // @h13_57e4f0
          u32 o23 = T + 0x23c;
          u32 id = ((u32(THISCALL *)(u32, u32))VSLOT(o23, 0x30))(o23, F32(T, 0x33c) - 1);  // @h14_57e4f0
          u32 gm = G(u32, 0x70038c);
          u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(gm, 0xcc))(gm, id);  // @h15_57e4f0
          ext_57ee90_t0(ob);  // @h16_57e4f0
          ext_57d780_t0(T);  // @h17_57e4f0
          u32 sub = T + 0x190;
          ((u32(THISCALL *)(u32))VSLOT(sub, 0xc))(sub);  // @h18_57e4f0
          goto done;
        } else {
          collect = true;  // @h19_57e4f0
        }
        if (collect && eax != 0xffffffffu) {  // @h20_57e4f0
          cnt++;  // @h21_57e4f0
          ext_57d950_t1(T, esi);  // @h22_57e4f0
          found = true;  // @h23_57e4f0
        }
      }
      esi++;
    } while (esi < F32(T, 0x338));  // @h24_57e4f0
  }
  if (cnt == 0) goto done;  // @h25_57e4f0
  {
    u32 o23 = T + 0x23c;
    u32 id = ((u32(THISCALL *)(u32, u32))VSLOT(o23, 0x30))(o23, F32(T, 0x33c) - 1);  // @h26_57e4f0
    u32 gm = G(u32, 0x70038c);
    u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(gm, 0xcc))(gm, id);  // @h27_57e4f0
    ext_4cbeb0_t0((u32)S188);  // @h28_57e4f0
    reg.state = 0;  // @h29_57e4f0
    ext_4cbe80_s1((u32)tmpA4, F32(F32(ob, 0), 0));  // @h30_57e4f0
    reg.state = 1;  // @h31_57e4f0
    ext_4cbee0_s1((u32)S188, (u32)tmpA4);  // @h32_57e4f0
    reg.state = 0;  // @h33_57e4f0
    ext_4cbec0_s0((u32)tmpA4);  // @h34_57e4f0
    ext_4cbe50_s1((u32)D4, (u32)S188);  // @h35_57e4f0
    reg.state = 2;  // @h36_57e4f0
    ext_57c910_t1(ob + 0x2c, (u32)D4);  // @h37_57e4f0
    F8(ob, 0xdf) = 1;  // @h38_57e4f0
    ext_57ee90_t0(ob);  // @h39_57e4f0
    reg.state = 0;  // @h40_57e4f0
    ext_4cbec0_s0((u32)D4);  // @h41_57e4f0
    ext_57d780_t0(T);  // @h42_57e4f0
    u32 sub = T + 0x190;
    ((u32(THISCALL *)(u32))VSLOT(sub, 0xc))(sub);  // @h43_57e4f0
    u32 bl = 0;
    ((u32(THISCALL *)(u32, u32))VSLOT(o23, 0x4c))(o23, (u32)it);  // @h44_57e4f0
    u32 id2 = ((u32(THISCALL *)(u32, u32))VSLOT(o23, 0x5c))(o23, (u32)it);  // @h45_57e4f0
    while (it[0] != 0) {  // @h46_57e4f0
      u32 gm2 = G(u32, 0x70038c);
      u32 ob2 = ((u32(THISCALL *)(u32, u32))VSLOT(gm2, 0xcc))(gm2, id2);  // @h47_57e4f0
      if (ob2) {  // @h48_57e4f0
        bool all = true;
        for (u32 k = 0; k < 4; k++) if (F32(ob2, 0xac + 4 * k) != 0xffffffffu) { all = false; break; }  // @h49_57e4f0
        if (all) bl = 1;  // @h50_57e4f0
      }
      id2 = ((u32(THISCALL *)(u32, u32))VSLOT(o23, 0x5c))(o23, (u32)it);  // @h51_57e4f0
    }
    u32 mg = F32(G(u32, 0x70039c), 0x9b);
    u32 o2 = ((u32(THISCALL *)(u32, u32))VSLOT(mg, 0x58))(mg, F32(T, 0x188));  // @h52_57e4f0
    if (o2) {  // @h53_57e4f0
      if (bl) ((u32(THISCALL *)(u32))VSLOT(o2, 0x2dc))(o2);  // @h54_57e4f0
      else ((u32(THISCALL *)(u32))VSLOT(o2, 0x2d8))(o2);  // @h55_57e4f0
    }
    ext_4cbec0_s0((u32)S188);  // @h56_57e4f0
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef F8
}
PCREG(57e4f0, hand_57e4f0);

extern "C" u32 THISCALL ext_5f9680_t1(u32, u32) __asm__("ext_5f9680");
extern "C" u32 THISCALL ext_5f9dd0_t1(u32, u32) __asm__("ext_5f9dd0");
extern "C" u32 THISCALL ext_5fa090_t1(u32, u32) __asm__("ext_5fa090");
extern "C" u32 THISCALL ext_5fc590_t3(u32, u32, u32, u32) __asm__("ext_5fc590");
extern "C" u32 THISCALL ext_5f3480_t3(u32, u32, u32, u32) __asm__("ext_5f3480");
extern "C" u32 THISCALL ext_5f37f0_t2(u32, u32, u32) __asm__("ext_5f37f0");
extern "C" u32 THISCALL ext_5f4680_t2(u32, u32, u32) __asm__("ext_5f4680");
extern "C" u32 THISCALL ext_5fbe50_t3(u32, u32, u32, u32) __asm__("ext_5fbe50");
extern "C" u32 THISCALL ext_5f98a0_t0(u32) __asm__("ext_5f98a0");
extern "C" u32 THISCALL ext_5f4630_t0(u32) __asm__("ext_5f4630");
extern "C" u32 ext_41e2c0_c1(u32) __asm__("ext_41e2c0");
static inline void fatal_5fbbe0() {
  u32 f = *(volatile u32 *)0x7003b0;
  if (f) ((void(STDCALL *)(void))f)();
  else __builtin_trap();
}
// 0x5fbbe0 thiscall(list) ret 4: appends one node per list entry to the container at this+0x18 (SEH 0x66d51c)
extern "C" u32 THISCALL hand_5fbbe0(u32 this_, u32 list) {
  SEH_ENTER(0x66d51c);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  u8 H[0x40] __attribute__((aligned(16)));
  volatile float f20;
  volatile u32 cnt = 0, o24 = 0, v10 = 0, o2c = 0;
  ext_5f9680_t1((u32)H, 0xdac);  // @h1_5fbbe0
  reg.state = 0;  // @h2_5fbbe0
  ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x64))(list, (u32)&f20);  // @h3_5fbbe0
  if (!(f20 == G(float, 0x680140))) fatal_5fbbe0();  // @h4_5fbbe0
  ext_5f9dd0_t1((u32)H, list);  // @h5_5fbbe0
  ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x5c))(list, (u32)&cnt);  // @h6_5fbbe0
  if (cnt != 0) {  // @h7_5fbbe0
    u32 i = 0;
    do {
      ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x5c))(list, (u32)&o24);  // @h8_5fbbe0
      ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x60))(list, (u32)&v10);  // @h9_5fbbe0
      u32 edi;
      if ((s32)v10 < 0) {  // @h10_5fbbe0
        u32 r = ext_5fa090_t1((u32)H, o24);  // @h11_5fbbe0
        u32 cl = F8(this_, 0x40);
        if (F8(F32(this_, 4), 0) != 0) {  // @h12_5fbbe0
          edi = 0;
          F32(edi, 4) = this_;
        } else {
          u32 res = ext_5fc590_t3(F32(this_, 4), r, 0, cl);  // @h13_5fbbe0
          u32 al = ext_41e290_cdecl1((u32)0xad2);  // @h14_5fbbe0
          reg.state = 1;  // @h15_5fbbe0
          if (al) edi = ext_5f3480_t3(al, res + 0x3c, 0, 0);  // @h16_5fbbe0
          else edi = 0;
          reg.state = 0;  // @h17_5fbbe0
          F32(edi, 4) = this_;  // @h18_5fbbe0
        }
      } else {
        ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x5c))(list, (u32)&o2c);  // @h19_5fbbe0
        u32 al = ext_41e290_cdecl1((u32)0xad2);  // @h20_5fbbe0
        reg.state = 2;  // @h21_5fbbe0
        if (al) {
          u32 b = v10;
          if (!(b < F32(this_, 0x20))) fatal_5fbbe0();  // @h22_5fbbe0
          u32 src = F32(F32(this_, 0x18), b * 4);
          edi = ext_5f37f0_t2(al, src, o2c);  // @h23_5fbbe0
        } else {
          edi = 0;
        }
        F32(edi, 4) = this_;  // @h24_5fbbe0
        u32 b2 = v10;
        reg.state = 0;  // @h25_5fbbe0
        if (!(b2 < F32(this_, 0x20))) fatal_5fbbe0();  // @h26_5fbbe0
        u32 eb = F32(F32(this_, 0x18), b2 * 4);
        if (!(F32(eb, 0x60) < F32(eb, 0x5c))) ext_5f4630_t0(eb + 0x58);  // @h27_5fbbe0
        F32(F32(eb, 0x58), F32(eb, 0x60) * 4) = edi;  // @h28_5fbbe0
        F32(eb, 0x60) = F32(eb, 0x60) + 1;  // @h29_5fbbe0
      }
      ext_5f4680_t2(edi, list, (u32)H);  // @h30_5fbbe0
      ext_5fbe50_t3(F32(this_, 4), edi, list, (u32)H);  // @h31_5fbbe0
      u32 cap = F32(this_, 0x1c);
      if (!(F32(this_, 0x20) < cap)) {  // @h32_5fbbe0
        u32 nc = cap * 2;
        u32 old = F32(this_, 0x18);
        unsigned long long sz = (unsigned long long)nc * 4ull;
        u32 sz32 = (sz >> 32) ? 0xffffffffu : (u32)sz;  // @h33_5fbbe0
        u32 np = ext_41e290_cdecl1(sz32);  // @h34_5fbbe0
        F32(this_, 0x18) = np;
        for (u32 j = 0; j < F32(this_, 0x1c); j++) F32(np, j * 4) = F32(old, j * 4);  // @h35_5fbbe0
        ext_41e2c0_c1(old);  // @h36_5fbbe0
        F32(this_, 0x1c) = nc;  // @h37_5fbbe0
      }
      F32(F32(this_, 0x18), F32(this_, 0x20) * 4) = edi;  // @h38_5fbbe0
      F32(this_, 0x20) = F32(this_, 0x20) + 1;  // @h39_5fbbe0
      i++;
    } while (i < cnt);  // @h40_5fbbe0
  }
  u32 rv = ext_5f98a0_t0((u32)H);  // @h41_5fbbe0
  SEH_LEAVE();
  return rv;
#undef F32
#undef F8
}
PCREG(5fbbe0, hand_5fbbe0);

extern "C" u32 THISCALL ext_4ccbe0_t2(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4cdd40_t0(u32) __asm__("ext_4cdd40");
extern "C" u32 THISCALL ext_4ce5b0_t1(u32, u32) __asm__("ext_4ce5b0");
extern "C" u32 THISCALL ext_4cdb90_t0(u32) __asm__("ext_4cdb90");
extern "C" u32 THISCALL ext_4ccfe0_t0(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4e0a10_t0(u32) __asm__("ext_4e0a10");
extern "C" u32 THISCALL ext_4e0d00_t1(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 FASTCALL ext_441940_f(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_43e920_f(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 ext_634273_c2c(u32, u32) __asm__("ext_634273");
static inline double absd_450980(float f) {
  double d = (double)f;
  unsigned long long b;
  __builtin_memcpy(&b, &d, 8);
  b &= 0x7fffffffffffffffull;
  __builtin_memcpy(&d, &b, 8);
  return d;
}
// 0x450980 thiscall(flag) ret 4: builds per-node weights, collision-free index lists and the node tables of the path graph (SEH 0x6662e8, /GS)
extern "C" u32 THISCALL hand_450980(u32 T, u32 a1) {
  SEH_ENTER(0x6662e8);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define FF(base, off) (*(volatile float *)((base) + (off)))
  volatile u32 V34[4], V6c[4], v1c[4], v28[4];
  u8 Rb[0x60] __attribute__((aligned(16)));
  u32 Rp = (u32)Rb;
  F32(T, 0xcc) = 0;  // @h1_450980
  F32(T, 0xb4) = 0;  // @h2_450980
  F32(T, 0xb8) = 0;  // @h3_450980
  F32(T, 0xbc) = 0;  // @h4_450980
  if (F32(T, 0x44) != 0) {  // @h5_450980
    u32 off = 0;
    for (u32 i = 0; i < F32(T, 0x44); i++) {
      ext_4e0a10_t0((u32)V34);  // @h6_450980
      ext_4e0d00_t1((u32)V34, 0x3dcccccdu);  // @h7_450980
      ext_441940_f(F32(T, 0x58) + off, (u32)V34);  // @h8_450980
      off += 0xc;
      FF(F32(T, 0x60), i * 4) = 1.0f;  // @h9_450980
      float q = G(float, 0x678858);
      q = q / FF(F32(T, 0x60), i * 4);  // @h10_450980
      FF(F32(T, 0x64), i * 4) = q;  // @h11_450980
    }
  }
  ext_4ccbe0_t2(Rp, 0x20, 0);  // @h12_450980
  reg.state = 0;  // @h13_450980
  if (F32(T, 0x44) != 0) {  // @h14_450980
    u32 off = 0;
    for (u32 i = 0; i < F32(T, 0x44); i++) {
      u32 p = F32(T, 0x58) + off;
      *(volatile float *)&v1c[0] = FF(p, 0);  // @h15_450980
      *(volatile float *)&v1c[1] = FF(p, 4);
      *(volatile float *)&v1c[2] = FF(p, 8);
      ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)v1c);  // @h16_450980
      for (u32 j = 0; j < F32(T, 0x74); j++) {  // @h17_450980
        u32 node = F32(F32(T, 0x78), j * 4);
        v28[0] = v1c[0]; v28[1] = v1c[1]; v28[2] = v1c[2];
        ((u32(THISCALL *)(u32, u32))VSLOT(node, 0x8c))(node, (u32)v28);  // @h18_450980
        u32 q = F32(node, 8);
        ext_43e920_f((u32)V6c, (u32)v28, q + 0x30);  // @h19_450980
        if (!((double)FF(q, 0x40) >= absd_450980(*(volatile float *)&V6c[0]))) continue;  // @h20_450980
        if (!((double)FF(q, 0x44) >= absd_450980(*(volatile float *)&V6c[1]))) continue;  // @h21_450980
        if (!((double)FF(q, 0x48) >= absd_450980(*(volatile float *)&V6c[2]))) continue;  // @h22_450980
        F32(F32(T, 0x60), i * 4) = 0x72fc6f7cu;  // @h23_450980
        F32(F32(T, 0x64), i * 4) = 0;  // @h24_450980
      }
      for (u32 j = 0; j < F32(T, 0x80); j++) {  // @h25_450980
        u32 node = F32(F32(T, 0x84), j * 4);
        v28[0] = v1c[0]; v28[1] = v1c[1]; v28[2] = v1c[2];
        ((u32(THISCALL *)(u32, u32))VSLOT(node, 0x8c))(node, (u32)v28);  // @h26_450980
        u32 q = F32(node, 8);
        ext_43e920_f((u32)V34, (u32)v28, q + 0x30);  // @h27_450980
        if (!((double)FF(q, 0x40) >= absd_450980(*(volatile float *)&V34[0]))) continue;  // @h28_450980
        if (!((double)FF(q, 0x44) >= absd_450980(*(volatile float *)&V34[1]))) continue;  // @h29_450980
        if (!((double)FF(q, 0x48) >= absd_450980(*(volatile float *)&V34[2]))) continue;  // @h30_450980
        u32 cur = p;
        bool dup = false;
        for (u32 k = 0; (s32)k < (s32)ext_4cdd40_t0(Rp); k++) {  // @h31_450980
          u32 idx = ext_4ce5b0_t1(Rp, k);  // @h32_450980
          u32 o = F32(T, 0x58) + idx * 12;
          volatile float d0 = FF(cur, 0) - FF(o, 0);  // @h33_450980
          if (!(G(double, 0x6785f8) > absd_450980(d0))) continue;
          volatile float d1 = FF(cur, 4) - FF(o, 4);  // @h34_450980
          if (!(G(double, 0x6785f8) > absd_450980(d1))) continue;
          volatile float d2 = FF(cur, 8) - FF(o, 8);  // @h35_450980
          if (G(double, 0x6785f8) > absd_450980(d2)) { dup = true; break; }
        }
        if (!dup) ext_4cd540_t1(Rp, i);  // @h36_450980
      }
      off += 0xc;
    }
  }
  if (F32(T, 0x48) != 0) {  // @h37_450980
    u32 es = 0;
    for (u32 j = 0; j < F32(T, 0x48); j++) {
      u32 e = F32(T, 0x4c) + es;
      float a = FF(F32(T, 0x60), (u32)*(volatile u16 *)(e + 2) * 4);  // @h38_450980
      float b = FF(F32(T, 0x60), (u32)*(volatile u16 *)(e + 0) * 4);  // @h39_450980
      volatile float sum = b + a;  // @h40_450980
      FF(e, 4) = a / sum;  // @h41_450980
      es += 0x10;
    }
  }
  {
    u8 flag = (u8)a1;
    F32(T, 0x7c) = 0;  // @h42_450980
    F32(T, 0xa0) = F32(F32(T, 8), 0x6c);  // @h43_450980
    if (flag != 0) {  // @h44_450980
      u32 cnt = ext_4cdd40_t0(Rp);
      unsigned long long sz = (unsigned long long)cnt * 2ull;
      F32(T, 0x8c) = ext_41e290_cdecl1((u32)((sz >> 32) ? 0xffffffffu : (u32)sz));  // @h45_450980
      F32(T, 0x88) = ext_4cdd40_t0(Rp);  // @h46_450980
      for (u32 k = 0; (s32)k < (s32)ext_4cdd40_t0(Rp); k++) {  // @h47_450980
        u32 v = ext_4ce5b0_t1(Rp, k);  // @h48_450980
        *(volatile u16 *)(F32(T, 0x8c) + k * 2) = (u16)v;  // @h49_450980
      }
      ext_4cdb90_t0(Rp);  // @h50_450980
      u32 mgr = F32(G(u32, 0x70039c), 0x9b);
      u32 dev = ((u32(THISCALL *)(u32))VSLOT(mgr, 0x138))(mgr);  // @h51_450980
      volatile u32 out = 0;
      ((u32(THISCALL *)(u32, u32, u32))VSLOT(dev, 0x88))(dev, 0x681320, (u32)&out);  // @h52_450980
      u32 ov = out;
      F32(T, 0x94) = ov;  // @h53_450980
      if (ov != 0) {  // @h54_450980
        u32 mg2 = F32(G(u32, 0x70039c), 0x9b);
        u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(mg2, 0x58))(mg2, ov);  // @h55_450980
        u32 rv = ((u32(THISCALL *)(u32))VSLOT(ob, 0x20))(ob);  // @h56_450980
        F32(T, 0x98) = rv;  // @h57_450980
      }
      u32 o2 = ((u32(THISCALL *)(u32))VSLOT(T, 0x20))(T);  // @h58_450980
      u32 rr = ((u32(THISCALL *)(u32, u32, u32))VSLOT(o2, 0x25c))(o2, 0x681330, 0);  // @h59_450980
      F32(T, 0xc8) = rr;  // @h60_450980
      if (rr != 0) {  // @h61_450980
        u32 ch = F32(rr, 0x50);
        while (ch != 0) {  // @h62_450980
          u32 ob2 = F32(ch, 0x54);
          if (ob2 != T) {  // @h63_450980
            u32 b = ((u32(THISCALL *)(u32, u32))VSLOT(ob2, 0x1e0))(ob2, 0x200002);  // @h64_450980
            if ((u8)b) F32(T, 0xa8) = F32(T, 0xa8) + 1;  // @h65_450980
          }
          ch = F32(ch, 0x60);
        }
      }
    }
  }
  {
    unsigned long long sz = (unsigned long long)F32(T, 0xa8) * 0x3cull;
    F32(T, 0xb0) = ext_41e290_cdecl1((u32)((sz >> 32) ? 0xffffffffu : (u32)sz));  // @h66_450980
    F32(T, 0xc0) = 0xbf800000u;  // @h67_450980
    ext_634273_c2c(F32(T, 0x78), 4);  // @h68_450980
    ext_634273_c2c(F32(T, 0x84), 4);  // @h69_450980
  }
  u32 rv = ext_4ccfe0_t0(Rp);  // @h70_450980
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return rv;
#undef F32
#undef FF
}
PCREG(450980, hand_450980);

extern "C" u32 FASTCALL ext_441970_f3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_446ee0_f3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_4e0d80_f3(u32, u32, u32) __asm__("ext_4e0d80");
extern "C" u32 FASTCALL ext_4de040_f3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4e29c0_f6(u32, u32, u32, u32, u32, u32) __asm__("ext_4e29c0");
extern "C" float FASTCALL ext_4e2bb0_f2(u32, u32) __asm__("ext_4e2bb0");
extern "C" u32 THISCALL ext_453a50_w1(u32, u32) __asm__("ext_453a50");
extern "C" u32 THISCALL ext_4db7c0_w1(u32, u32) __asm__("ext_4db7c0");
// 0x453390 thiscall() plain ret: first object of kind 0x200015 (other than this) that the swept box overlaps: returns it or 0 (SEH 0x66635b, /GS)
extern "C" u32 THISCALL hand_453390(u32 T) {
  SEH_ENTER(0x66635b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define FLT(a) (*(volatile float *)(a))
  volatile u32 R218[8], it238[2];
  // the exe's locals from ebp-0xe8 to ebp-0x10 form ONE area (vslot 0x80 writes 48 bytes into both Ve8 and Vc4, which overlap): keep that layout
  volatile float L[54], V250[4], V25c[4], V268[4], V10c[16], V244[4], V16c[16];
#define Ve8 (L + 0)
#define Vc4 (L + 9)
#define Vb8 (L + 12)
#define VAC (L + 15)
#define VA (L + 18)
#define V70 (L + 30)
#define V64 (L + 33)
#define V58 (L + 36)
#define V28 (L + 48)
#define V1c (L + 51)
  u32 pR = (u32)(u32 *)R218, pVe8 = (u32)(float *)Ve8, pVc4 = (u32)(float *)Vc4, p1c = (u32)(float *)V1c;
  u32 res = 0;
  if (*(volatile u8 *)(T + 0x20) == 0) goto done;  // @h1_453390
  ext_4ccba0_t0(pR);  // @h2_453390
  reg.state = 0;  // @h3_453390
  ext_4db7c0_w1(F32(T, 8), p1c);  // @h4_453390
  {
    u32 si = 0;
    if (V1c[0] > V1c[1]) si = 1;  // @h5_453390
    if (V1c[si] > V1c[2]) si = 2;  // @h6_453390
    V1c[si] = 5.0f;  // @h7_453390
  }
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(T, 0x80))(T, pVe8, pVc4);  // @h8_453390
  ext_441970_f3((u32)(float *)V250, F32(T, 8) + 0x30, pVe8);  // @h9_453390
  ext_441940_f(pVc4, (u32)(float *)V250);  // @h10_453390
  {
    u32 p = ((u32(THISCALL *)(u32))VSLOT(T, 0x244))(T);  // @h11_453390
    V64[0] = FLT(p); V64[1] = FLT(p + 4); V64[2] = FLT(p + 8);  // @h12_453390
    ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V64);  // @h13_453390
    {
      u32 sy = G(u32, 0x70039c);
      u32 m = F32(sy, 0x9b);
      u32 oa = F32(m, 0xadc);
      ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))VSLOT(oa, 0x2dc))(oa, 2, pR, pVe8, pVc4, p1c, 0x400000, 0xffffffff, 0);  // @h14_453390
    }
    for (u32 k = 0; k < 12; k++) *(volatile u32 *)((u32)(float *)V58 + 4 * k) = F32(p, 4 * k);  // @h15_453390
    ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58);  // @h16_453390
    ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58 + 12);  // @h17_453390
    ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58 + 24);  // @h18_453390
    ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58 + 36);  // @h19_453390
    ext_43e920_f((u32)(float *)V25c, (u32)(float *)V58 + 12, (u32)(float *)V58);  // @h20_453390
    ext_43e920_f((u32)(float *)V268, (u32)(float *)V58 + 24, (u32)(float *)V58);  // @h21_453390
    ext_446ee0_f3((u32)(float *)Vb8, (u32)(float *)V268, (u32)(float *)V25c);  // @h22_453390
    ext_4e0d80_f3((u32)(float *)Vb8, 0, 0x3f800000);  // @h23_453390
    ext_4de040_f3((u32)(float *)V10c, (u32)(float *)Vb8, 0);  // @h24_453390
    {
      u32 sy = G(u32, 0x70039c);
      u32 m = F32(sy, 0x9b);
      ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x4c))(m, T);  // @h25_453390
    }
    float f228 = ((float(THISCALL *)(u32))VSLOT(T, 0x214))(T);  // @h26_453390
    ext_453a50_w1(T, (u32)(float *)V28);  // @h27_453390
    ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x4c))(pR, (u32)(u32 *)it238);  // @h28_453390
    u32 elem = ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x5c))(pR, (u32)(u32 *)it238);  // @h29_453390
    if (it238[0] != 0) {  // @h30_453390
      do {
        u32 sy = G(u32, 0x70039c);
        u32 m = F32(sy, 0x9b);
        u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, elem);  // @h31_453390
        if (ob == 0) goto nextl;  // @h32_453390
        if (F32(F32(ob, 0xc), 0x23) != 0x200015) goto nextl;  // @h33_453390
        if (ob == T) goto nextl;  // @h34_453390
        if (*(volatile u8 *)(ob + 0x20) == 0) goto nextl;  // @h35_453390
        ext_453a50_w1(ob, (u32)(float *)VAC);  // @h36_453390
        {
          float t0 = V28[1] * VAC[1];  // @h37_453390
          float t1 = V28[0] * VAC[0];
          t1 = t1 + t0;  // @h38_453390
          float t2 = V28[2] * VAC[2];
          t1 = t1 + t2;  // @h39_453390
          if (t1 > *(volatile float *)0x681dd0) goto nextl;  // @h40_453390
        }
        {
          u32 p230 = ((u32(THISCALL *)(u32))VSLOT(ob, 0x244))(ob);  // @h41_453390
          V70[0] = FLT(p230); V70[1] = FLT(p230 + 4); V70[2] = FLT(p230 + 8);  // @h42_453390
          ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)V70);  // @h43_453390
          ext_43e920_f((u32)(float *)V244, (u32)(float *)V70, (u32)(float *)V64);  // @h44_453390
          float u0 = V244[1] * V28[1];  // @h45_453390
          float u1 = V244[0] * V28[0];
          u1 = u1 + u0;  // @h46_453390
          float u2 = V244[2] * V28[2];
          u1 = u1 + u2;  // @h47_453390
          float ab = (float)__builtin_fabs((double)u1);  // @h48_453390
          if (ab > *(volatile float *)0x681dc8) goto nextl;  // @h49_453390
          u32 a = ((u32(THISCALL *)(u32))VSLOT(ob, 0x20))(ob);  // @h50_453390
          u32 b = ((u32(THISCALL *)(u32))VSLOT(T, 0x20))(T);  // @h51_453390
          if (a == b) {  // @h52_453390
            u32 lg = G(u32, 0x700390);
            u32 lo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x681d70, 0x1aa);  // @h53_453390
            u32 n1 = F32(ob, 4); if (n1 == 0) n1 = 0x67c8e8;  // @h54_453390
            u32 x = ((u32(THISCALL *)(u32))VSLOT(ob, 0x20))(ob);  // @h55_453390
            u32 xn = F32(x, 4); if (xn == 0) xn = 0x67c8e8;  // @h56_453390
            u32 tn = F32(T, 4); if (tn == 0) tn = 0x67c8e8;  // @h57_453390
            u32 y = ((u32(THISCALL *)(u32))VSLOT(T, 0x20))(T);  // @h58_453390
            u32 yn = F32(y, 4); if (yn == 0) yn = 0x67c8e8;  // @h59_453390
            ((u32(*)(u32, u32, u32, u32, u32, u32))VSLOT(lo, 0x2c))(lo, 0x681d98, yn, tn, xn, n1);  // @h60_453390
            goto nextl;
          }
          float f224 = ((float(THISCALL *)(u32))VSLOT(ob, 0x214))(ob);  // @h61_453390
          float sc = *(volatile float *)0x681dcc;
          float m0 = f228 * sc;  // @h62_453390
          if (f224 > m0) goto nextl;  // @h63_453390
          float m1 = f224 * sc;  // @h64_453390
          if (f228 > m1) goto nextl;  // @h65_453390
          for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 36 + 4 * k) = F32(p230, 4 * k);  // @h66_453390
          for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 24 + 4 * k) = F32(p230, 12 + 4 * k);  // @h67_453390
          for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 12 + 4 * k) = F32(p230, 24 + 4 * k);  // @h68_453390
          for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 0 + 4 * k) = F32(p230, 36 + 4 * k);  // @h69_453390
          ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA);  // @h70_453390
          ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA + 12);  // @h71_453390
          ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA + 24);  // @h72_453390
          ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA + 36);  // @h73_453390
          u32 es = ext_4e29c0_f6((u32)(float *)V16c, (u32)(float *)VA, 4, (u32)(float *)V58, 4, (u32)(float *)Vb8);  // @h74_453390
          float g1 = ext_4e2bb0_f2((u32)(float *)V58, 4);  // @h75_453390
          float g2 = ext_4e2bb0_f2((u32)(float *)VA, 4);  // @h76_453390
          float g3 = ext_4e2bb0_f2((u32)(float *)V16c, es);  // @h77_453390
          float mn = (g2 < g1) ? g2 : g1;  // @h78_453390
          mn = mn * *(volatile float *)0x681dc4;  // @h79_453390
          if (!(mn > g3)) { res = ob; break; }  // @h80_453390
        }
      nextl:
        elem = ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x5c))(pR, (u32)(u32 *)it238);  // @h81_453390
      } while (it238[0] != 0);  // @h82_453390
    }
  }
  ext_4ccf60_t0(pR);  // @h83_453390
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return res;
#undef Ve8
#undef Vc4
#undef Vb8
#undef VAC
#undef VA
#undef V70
#undef V64
#undef V58
#undef V28
#undef V1c
#undef F32
#undef FLT
}
PCREG(453390, hand_453390);

extern "C" u32 STDCALL ext_634123_s5b(u32, u32, u32, u32, u32) __asm__("ext_634123");
// 0x588a00 thiscall() plain ret: config object constructor (generated from the disassembly: 38 "read option, atof, else default" blocks), SEH 0x66b6a4
extern "C" u32 THISCALL hand_588a00(u32 edi) {
  SEH_ENTER(0x66b6a4);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define RD(nm, dflt, off) { u32 sy = G(u32, 0x70039c); bool ok = (u8)((u32(THISCALL *)(u32, u32, u32))VSLOT(sy, 0x5c))(sy, (nm), (u32)&out); float f; if (ok) { double dd = ((double(*)(u32))G(u32, 0x6762d4))(out); f = (float)dd; } else { f = G(float, (dflt)); } *(volatile float *)&out = f; *(volatile float *)(edi + (off)) = f; }
  volatile u32 out = 0;
  F32(edi, 4) = 0; F32(edi, 0x408) = 0; F32(edi, 0x41c) = 0; F32(edi, 0x4a0) = 0; F32(edi, 0x4a4) = 0; F32(edi, 0x4a8) = 0; F32(edi, 0x4b0) = 0; F32(edi, 0x8b4) = 0; F32(edi, 0x4ac) = 0;  // @h1_588a00
  *(volatile u8 *)(edi + 0xab8) = 0;  // @h2_588a00
  F32(edi, 0) = 0x6abbdc;  // @h3_588a00
  reg.state = 0;  // @h4_588a00
  F32(edi, 0xb55) = 0; F32(edi, 0xb59) = 0; F32(edi, 0xb5d) = 0;  // @h5_588a00
  u32 esi = edi + 0xd8d;
  F32(edi, 0xb61) = 0; F32(edi, 0xbe5) = 0;  // @h6_588a00
  reg.state = 1;  // @h7_588a00
  F32(edi, 0xc69) = 0;  // @h8_588a00
  out = esi;
  ext_634123_s5b(esi + 4, 0xf4, 0x20, 0x5897d0, 0x4690b0);  // @h9_588a00
  F32(esi, 0) = 0;  // @h10_588a00
  F32(edi, 0x2c15) = 0; F32(edi, 0x2c19) = 0; F32(edi, 0x2c4d) = 0; F32(edi, 0x2c51) = 0; F32(edi, 0x2c55) = 0; F32(edi, 0x2c3d) = 0; F32(edi, 0x2c2d) = 0; F32(edi, 0x2c41) = 0; F32(edi, 0x2c31) = 0; F32(edi, 0x2c45) = 0; F32(edi, 0x2c35) = 0; F32(edi, 0x2c49) = 0; F32(edi, 0x2c39) = 0;  // @h11_588a00
  reg.state = 2;  // @h12_588a00
  RD(0x6abbe8, 0x680a68, 0xb49);  // @r0_588a00
  RD(0x6abbf8, 0x685280, 0xb4d);  // @r1_588a00
  RD(0x6abc04, 0x67c1a8, 0xab9);  // @r2_588a00
  RD(0x6abc1c, 0x683768, 0xabd);  // @r3_588a00
  RD(0x6abc34, 0x680a5c, 0xac1);  // @r4_588a00
  RD(0x6abc4c, 0x694d0c, 0xac5);  // @r5_588a00
  RD(0x6abc68, 0x679544, 0xac9);  // @r6_588a00
  RD(0x6abc80, 0x67a6ac, 0xacd);  // @r7_588a00
  RD(0x6abc98, 0x680a68, 0xad1);  // @r8_588a00
  RD(0x6abcb4, 0x680a80, 0xad9);  // @r9_588a00
  RD(0x6abcc4, 0x67da24, 0xad5);  // @r10_588a00
  RD(0x6abcd8, 0x678858, 0xadd);  // @r11_588a00
  RD(0x6abcec, 0x6ac048, 0xae1);  // @r12_588a00
  RD(0x6abd00, 0x680a68, 0xae5);  // @r13_588a00
  RD(0x6abd14, 0x680a64, 0xae9);  // @r14_588a00
  RD(0x6abd2c, 0x680a74, 0xaed);  // @r15_588a00
  RD(0x6abd40, 0x67c1a8, 0xaf1);  // @r16_588a00
  RD(0x6abd54, 0x67da1c, 0xaf5);  // @r17_588a00
  RD(0x6abd6c, 0x679544, 0xafd);  // @r18_588a00
  RD(0x6abd78, 0x680a70, 0xaf9);  // @r19_588a00
  RD(0x6abd88, 0x694d0c, 0xb01);  // @r20_588a00
  RD(0x6abda0, 0x6ac04c, 0xb05);  // @r21_588a00
  RD(0x6abdb8, 0x6ac054, 0xb09);  // @r22_588a00
  RD(0x6abdd0, 0x6ac050, 0xb0d);  // @r23_588a00
  RD(0x6abdec, 0x680a80, 0xb11);  // @r24_588a00
  RD(0x6abe04, 0x678858, 0xb15);  // @r25_588a00
  RD(0x6abe1c, 0x679544, 0xb19);  // @r26_588a00
  RD(0x6abe34, 0x680a68, 0xb21);  // @r27_588a00
  RD(0x6abe44, 0x6ac058, 0xb1d);  // @r28_588a00
  RD(0x6abe58, 0x680a60, 0xb25);  // @r29_588a00
  RD(0x6abe6c, 0x680a60, 0xb29);  // @r30_588a00
  RD(0x6abe80, 0x67da1c, 0xb2d);  // @r31_588a00
  RD(0x6abe94, 0x680a60, 0xb31);  // @r32_588a00
  RD(0x6abeac, 0x6a60a0, 0xb35);  // @r33_588a00
  RD(0x6abec0, 0x678858, 0xb39);  // @r34_588a00
  RD(0x6abed4, 0x681dc8, 0xb3d);  // @r35_588a00
  RD(0x6abeec, 0x680a60, 0xb45);  // @r36_588a00
  RD(0x6abef8, 0x679544, 0xb41);  // @r37_588a00
  F32(edi, 0x2c21) = 0; F32(edi, 0x2c1d) = 0; F32(edi, 0x2c25) = 0; F32(edi, 0x2c29) = 0;  // @h13_588a00
  *(volatile u8 *)(edi + 0x2c89) = 0;  // @h14_588a00
  F32(edi, 0x2c8a) = 0;  // @h15_588a00
  SEH_LEAVE();
  return edi;
#undef F32
#undef RD
}
PCREG(588a00, hand_588a00);

// 0x4acf30 thiscall(id) ret 4: resolves the object for id and runs its select / hint notifications (SEH 0x668781, /GS cookie)
extern "C" u32 THISCALL hand_4acf30(u32 T, u32 a1) {
  SEH_ENTER(0x668781);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define V0(o, off) ((u32(THISCALL *)(u32))VSLOT(o, off))
#define V1(o, off) ((u32(THISCALL *)(u32, u32))VSLOT(o, off))
#define V2(o, off) ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, off))
  u8 tmp90[0x80] __attribute__((aligned(16)));
  u8 tmp110[0x80] __attribute__((aligned(16)));
  volatile u32 out120 = 0;
  u32 res = 0;
  u32 idv = a1;
  u32 mg = F32(G(u32, 0x70039c), 0x9b);
  u32 B = V1(mg, 0x58)(mg, a1);  // @h1_4acf30
  if (B == 0) {  // @h2_4acf30
    u32 lgo = G(u32, 0x700390);
    u32 L = V2(lgo, 0x20)(lgo, 0x6909a4, 0x243);  // @h3_4acf30
    u32 P = F32(T, 0x44);
    u32 S = V2(P, 0x1d8)(P, (u32)tmp90, 1);  // @h4_4acf30
    reg.state = 0;  // @h5_4acf30
    u32 cs = ext_4cc1d0_t0(S);  // @h6_4acf30
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x690b78, cs);  // @h7_4acf30
    ext_4cbec0_s0((u32)tmp90);  // @h8_4acf30
    goto done;
  }
  if (!(u8)V1(B, 0x1e0)(B, 0x1007d1)) {  // @h9_4acf30
    if (!(u8)V1(B, 0x1e0)(B, 0x1007d3)) {  // @h10_4acf30
      u32 lgo = G(u32, 0x700390);
      u32 L = V2(lgo, 0x20)(lgo, 0x6909a4, 0x248);  // @h11_4acf30
      u32 P = F32(T, 0x44);
      u32 S2 = V2(P, 0x1d8)(P, (u32)tmp110, 1);  // @h12_4acf30
      reg.state = 1;  // @h14_4acf30
      u32 S3 = V2(B, 0x1d8)(B, (u32)tmp90, 1);  // @h13_4acf30
      reg.state = 2;  // @h15_4acf30
      u32 c2 = ext_4cc1d0_t0(S2);  // @h16_4acf30
      u32 c3 = ext_4cc1d0_t0(S3);  // @h17_4acf30
      ((u32(*)(u32, u32, u32, u32))VSLOT(L, 0x2c))(L, 0x690bb0, c3, c2);  // @h18_4acf30
      ext_4cbec0_s0((u32)tmp90);  // @h19_4acf30
      ext_4cbec0_s0((u32)tmp110);  // @h20_4acf30
      goto done;
    }
  }
  {
    u32 esi = B;
    if ((u8)V1(B, 0x1e0)(B, 0x1007d1)) esi = V0(B, 0x2e8)(B);  // @h21_4acf30
    u32 P = F32(T, 0x44);
    if ((u8)V1(P, 0x1e0)(P, 0x80200014)) {  // @h22_4acf30
      u32 sp = F32(esi, 4);
      if (sp == 0) sp = 0x67c8e8;  // @h23_4acf30
      s32 cmpv = ((s32(*)(u32, u32))G(u32, 0x676414))(0x690bf4, sp);  // @h24_4acf30
      if (cmpv == 0) {  // @h25_4acf30
        u32 mg1 = F32(G(u32, 0x70039c), 0x9b);
        u32 w = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))VSLOT(mg1, 0x114))(mg1, 0x690c00, 0, 0x6909a4, 0x252, 0x32, 0);  // @h26_4acf30
        V1(P, 0x128)(P, w & 0xffff);  // @h27_4acf30
        u32 mg2 = F32(G(u32, 0x70039c), 0x9b);
        u32 dev = V0(mg2, 0x138)(mg2);  // @h28_4acf30
        out120 = 0;
        V2(dev, 0x88)(dev, 0x690c14, (u32)&out120);  // @h29_4acf30
        u32 mg3 = F32(G(u32, 0x70039c), 0x9b);
        u32 ob = V1(mg3, 0x58)(mg3, out120);  // @h30_4acf30
        if (ob) V1(ob, 0xbc)(ob, 0);  // @h31_4acf30
        if ((u8)V1(B, 0x1e0)(B, 0x1007d1)) V1(B, 0x210)(B, 1);  // @h32_4acf30
        res = 0;
        goto done;
      }
    }
  }
  {
    u32 X = B;
    if ((u8)V1(B, 0x1e0)(B, 0x1007d3)) {  // @h33_4acf30
      u32 mgq = F32(G(u32, 0x70039c), 0x9b);
      u32 q = V1(B, 0x2c4)(B, F32(mgq, 0xadc));  // @h34_4acf30
      u32 mgb = F32(G(u32, 0x70039c), 0x9b);
      u32 id = V2(mgb, 0x4c)(mgb, q, 0x4954454d);  // @h35_4acf30
      idv = id;
      if (id == 0) { res = 0; goto done; }  // @h36_4acf30
      u32 mgc = F32(G(u32, 0x70039c), 0x9b);
      u32 obj2 = V1(mgc, 0x58)(mgc, id);  // @h37_4acf30
      X = obj2;
      V2(obj2, 0x2d0)(obj2, 1, 0);  // @h38_4acf30
      if ((u8)V1(B, 0x1e0)(B, 0x1007d5)) {  // @h39_4acf30
        u32 r31c = V0(B, 0x31c)(B);  // @h40_4acf30
        V1(obj2, 0x328)(obj2, r31c);  // @h41_4acf30
      } else {
        u32 P2 = F32(T, 0x44);
        u32 mgd = F32(G(u32, 0x70039c), 0x9b);
        u32 r20 = V1(P2, 0x20)(P2, 0);  // @h42_4acf30
        u32 id2 = V2(mgd, 0x4c)(mgd, P2, r20);  // @h43_4acf30
        V1(obj2, 0x2f0)(obj2, id2);  // @h44_4acf30
      }
    }
    if ((u8)V1(X, 0x1e0)(X, 0x1007d8)) {  // @h45_4acf30
      u32 r2e8 = V0(X, 0x2e8)(X);  // @h46_4acf30
      u32 r98 = V2(T, 0x98)(T, r2e8, 0);  // @h47_4acf30
      u32 mge = F32(G(u32, 0x70039c), 0x9b);
      u32 obj3 = V1(mge, 0x58)(mge, r98);  // @h48_4acf30
      if (obj3) {  // @h49_4acf30
        u32 r320 = V0(X, 0x320)(X);  // @h50_4acf30
        V1(obj3, 0x328)(obj3, r320);  // @h51_4acf30
        res = obj3;
        goto done;
      }
    }
    {
      u32 sub = T + 0x11a;
      V1(sub, 4)(sub, idv);  // @h52_4acf30
      u32 eid = F32(T, 0x6a);
      if (eid) {  // @h53_4acf30
        u32 mgf = F32(G(u32, 0x70039c), 0x9b);
        u32 o4 = V1(mgf, 0x58)(mgf, eid);  // @h54_4acf30
        ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(o4, 0x128))(o4, (u32)F16(T, 0x48), idv, 0);  // @h55_4acf30
      }
      res = X;
    }
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return res;
#undef F32
#undef F16
#undef V0
#undef V1
#undef V2
}
PCREG(4acf30, hand_4acf30);

extern "C" u32 THISCALL ext_5ed460_t0(u32) __asm__("ext_5ed460");
extern "C" u32 THISCALL ext_5ec720_t1(u32, u32) __asm__("ext_5ec720");
extern "C" u32 THISCALL ext_5edd80_t1(u32, u32) __asm__("ext_5edd80");
extern "C" u32 THISCALL ext_5f0020_t0(u32) __asm__("ext_5f0020");
extern "C" u32 THISCALL ext_5ebae0_t1(u32, u32) __asm__("ext_5ebae0");
extern "C" u32 THISCALL ext_5eec40_t0(u32) __asm__("ext_5eec40");
extern "C" u32 THISCALL ext_5efd10_t0(u32) __asm__("ext_5efd10");
extern "C" u32 THISCALL ext_5ef080_t0(u32) __asm__("ext_5ef080");
extern "C" u32 THISCALL ext_5fe3b0_t2(u32, u32, u32) __asm__("ext_5fe3b0");
// 0x5a6980 thiscall() plain ret: builds the widget set of a window (SEH 0x66c176, /GS cookie): about 60 widgets allocated, constructed, stored in
// fields and appended to a vector, followed by 5 lookups of key strings in the global text [0x6ed270] that set 5 field pointers
extern "C" u32 THISCALL hand_5a6980(u32 edi) {
  SEH_ENTER(0x66c176);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  volatile u32 tmpv = 0;
#define PB(vec, v) { u32 _e = F32((vec), 4); reg.state = -1; tmpv = (v); if (_e == F32((vec), 8)) { ext_5fe3b0_t2((vec), _e, (u32)&tmpv); } else { if (_e) F32(_e, 0) = tmpv; F32((vec), 4) = F32((vec), 4) + 4; } }
#define BLK(SIZE, ST, CTOR, OFF, VEC) { u32 a = ext_41e290_cdecl1((u32)(SIZE)); reg.state = (ST); u32 o = a ? (CTOR) : 0; F32(edi, (OFF)) = o; PB((VEC), o); }
  u32 esi;
  if (*(volatile u8 *)(edi + 0x658) == 0) {  // @h1_5a6980
    esi = edi + 0x659;
    BLK(0xf7, 0, ext_5ed460_t0(a), 0x438, esi);  // @b1_5a6980
    BLK(0xd7, 1, ext_5ec720_t1(a, 1), 0x43c, esi);  // @b2_5a6980
    BLK(0x84, 2, ext_5edd80_t1(a, 3), 0x638, esi);  // @b3_5a6980
  } else {
    esi = edi + 0x665;
    BLK(0x84, 3, ext_5edd80_t1(a, 1), 0x63c, esi);  // @b4_5a6980
    BLK(0xdb, 4, ext_5f0020_t0(a), 0x8a7, esi);  // @b5_5a6980
    BLK(0xdb, 5, ext_5f0020_t0(a), 0x8ab, esi);  // @b6_5a6980
  }
  esi = edi + 0x671;
  static const u32 tblA[18] = {0x434, 0x478, 0x4ac, 0x4a8, 0x4a4, 0x4a0, 0x49c, 0x498, 0x494, 0x490, 0x48c, 0x480, 0x484, 0x488, 0x4b0, 0x4b4, 0x689, 0x430};
  static const u32 tblB[11] = {0x5f8, 0x5fc, 0x600, 0x604, 0x608, 0x60c, 0x610, 0x614, 0x618, 0x620, 0x61c};
  for (u32 k = 0; k < 0x12; k++) {  // @l1_5a6980
    u32 a = ext_41e290_cdecl1((u32)0xd7); reg.state = 6; u32 o = a ? ext_5ec720_t1(a, 1) : 0;  // @l1a_5a6980
    F32(edi, tblA[k]) = o; PB(esi, o);
  }
  for (u32 k = 0; k < 0xb; k++) {  // @l2_5a6980
    u32 a = ext_41e290_cdecl1((u32)0xa7); reg.state = 7; u32 o = a ? ext_5ebae0_t1(a, 0xc) : 0;  // @l2a_5a6980
    F32(edi, tblB[k]) = o; PB(esi, o);
  }
  BLK(0xa7, 8, ext_5ebae0_t1(a, 0x100), 0x624, esi);  // @b7_5a6980
  for (u32 k = 0; k < 0xc; k++) {  // @l3_5a6980
    u32 a = ext_41e290_cdecl1((u32)0xd7); reg.state = 9; u32 o = a ? ext_5ec720_t1(a, 1) : 0;  // @l3a_5a6980
    F32(edi, 0x440 + 4 * k) = o; PB(esi, o);
  }
  BLK(0xf7, 0xa, ext_5ed460_t0(a), 0x470, esi);  // @b8_5a6980
  BLK(0xa8, 0xb, ext_5ab2e0_t1(a, 1), 0x640, esi);  // @b9_5a6980
  BLK(0xa8, 0xc, ext_5ab2e0_t1(a, 6), 0x644, esi);  // @b10_5a6980
  BLK(0xa8, 0xd, ext_5ab2e0_t1(a, 1), 0x648, esi);  // @b11_5a6980
  BLK(0x21, 0xe, ext_5eec40_t0(a), 0x62c, esi);  // @b12_5a6980
  BLK(0xf7, 0xf, ext_5ed460_t0(a), 0x628, esi);  // @b13_5a6980
  BLK(0xf7, 0x10, ext_5ed460_t0(a), 0x474, esi);  // @b14_5a6980
  BLK(0x99, 0x11, ext_5efd10_t0(a), 0x634, esi);  // @b15_5a6980
  BLK(0xa8, 0x12, ext_5ab2e0_t1(a, 3), 0x630, esi);  // @b16_5a6980
  BLK(0xc7, 0x13, ext_5ef080_t0(a), 0x64c, esi);  // @b17_5a6980
  for (u32 k = 0; k < 0x18; k++) {  // @l4_5a6980
    u32 a = ext_41e290_cdecl1((u32)0xd7); reg.state = 0x14; u32 o = a ? ext_5ec720_t1(a, 1) : 0;  // @l4a_5a6980
    F32(edi, 0x4cc + 4 * k) = o; PB(esi, o);
  }
  static const u32 keys[5] = {0x6afec4, 0x6afed0, 0x6afed8, 0x6afee4, 0x6afeec};
  static const u32 offs[5] = {0x4b8, 0x4bc, 0x4c0, 0x4c4, 0x4c8};
  u32 fld = 0;
  for (u32 q = 0; q < 5; q++) {  // @t1_5a6980
    u32 p = ((u32(*)(u32, u32))G(u32, 0x67625c))(G(u32, 0x6ed270), keys[q]);  // @t2_5a6980
    u32 S = G(u32, 0x6ed270);
    u32 n = p - S;
    if (S > p) n = 0;  // @t3_5a6980
    u32 cnt = 0;
    for (u32 j = 0; j < n; j++) if (*(volatile u8 *)(S + j) == 0x3b) cnt++;  // @t4_5a6980
    fld = edi + (cnt + 2) * 12;  // @t5_5a6980
    F32(edi, offs[q]) = fld;
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return fld;
#undef F32
#undef PB
#undef BLK
}
PCREG(5a6980, hand_5a6980);
