// batch250000.cpp - Sonnet-w3i: /GS-protected thiscall that formats into a 0x68-byte local through the object at [0x724270] and then calls the handler [0x7003b0]
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);  // /GS check

// 0x5f9260: thiscall(this): o = [0x724270] (0x5fa630); o->slot 0x14 (cdecl, 5 args: o, buf, 0x6b8e80, this[0x82], this[0xac6]);
// then the handler [0x7003b0]() (int3 when null); cookie check.
static void THISCALL fn5f9260(u8 *self) {
  u8 loc[0x68];
  u8 *o = G(u8 *, 0x724270);
  typedef u32 (*Slot)(u8 *, void *, u32, u32, u32);
  u32 a4 = *(u32 *)(self + 0xac6);  // @5f9260_a
  u32 a3 = *(u32 *)(self + 0x82);  // @5f9260_b
  (*(Slot *)(*(u8 **)o + 0x14))(o, loc, 0x6b8e80, a3, a4);  // @5f9260_c
  typedef u32 (*Hook)();
  Hook h = G(Hook, 0x7003b0);
  if (!h) __builtin_trap();
  h();  // @5f9260_d
  ext_633654(0);
}
PCREG(5f9260, fn5f9260);

// ---------------------------------------------------------------------------------------------------------------
// 0x43f2b0: thiscall(this) -- bounding box of an object list (this+0x50, next at +0x60) into this+0x18/0x24 and the
// box object [this+8]. /GS esp-frame (and esp,-8; sub esp,0x64). Frame model: u32 F[] is the exe's 0x64 byte block B
// (cookie at B+0x60 not modelled; the check is a recorder call). Offsets: V0=B+0xc V1=B+0x18 V2=B+0x24 V3=B+0x30
// P=B+0x3c Q=B TA=B+0x48 TB=B+0x54.
extern "C" u32 FASTCALL ext_43e8e0_fc3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fc3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_4e08d0_fc2(u32, u32) __asm__("ext_4e08d0");
extern "C" u32 FASTCALL ext_4e0900_fc2(u32, u32) __asm__("ext_4e0900");
extern "C" u32 THISCALL ext_4e0d00(u8 *, u32);
extern "C" u32 THISCALL ext_4dc5d0(u8 *, u32, u32, u32);
extern "C" u32 THISCALL ext_4dc600(u8 *, u32);
extern "C" u32 THISCALL ext_4dce50(u8 *, u32);
extern "C" u32 THISCALL ext_4dd060(u8 *, u32);
extern "C" u8 THISCALL ext_4daa00(u8 *);
extern "C" const u8 *THISCALL ext_4dc110(u8 *);
extern "C" u8 THISCALL ext_4db460(u8 *, u32, u32);
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");

static inline float asf(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 asu(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

static void THISCALL fn43f2b0(u8 *self) {
  u32 F[0x1c];
  for (int i = 0; i < 0x1c; i++) F[i] = 0;
  u32 *Q = F, *V0 = F + 3, *V1 = F + 6, *V2 = F + 9, *V3 = F + 12, *P = F + 15, *TA = F + 18, *TB = F + 21;
  typedef u32 (THISCALL *Slot)(u8 *);
  V0[0] = V0[1] = V0[2] = 0xfe967699;
  V1[0] = V1[1] = V1[2] = 0x7e967699;
  V2[0] = V2[1] = V2[2] = 0xfe967699;
  V3[0] = V3[1] = V3[2] = 0x7e967699;
  u32 r = (*(Slot *)(*(u8 **)self + 0x20))(self);  // @43f2b0_a
  if (r == 0 && (self[0x14] & 1)) {  // @43f2b0_b
    V0[0] = 0x451c4000; V0[1] = r; V0[2] = 0x451c4000;  // @43f2b0_c
    V1[0] = 0xc51c4000; V1[1] = r; V1[2] = 0xc51c4000;  // @43f2b0_d
  }
  for (u8 *n = *(u8 **)(self + 0x50); n; n = *(u8 **)(n + 0x60)) {
    if (ext_4daa00(n)) continue;
    const u8 *s = ext_4dc110(n);
    const u8 *t = (const u8 *)0x67cd0c;
    int cmp;
    for (;;) {
      u8 c = s[0];
      if (c != t[0]) { cmp = (c < t[0]) ? -1 : 1; break; }
      if (c == 0) { cmp = 0; break; }
      c = s[1];
      if (c != t[1]) { cmp = (c < t[1]) ? -1 : 1; break; }
      s += 2; t += 2;
      if (c == 0) { cmp = 0; break; }
    }
    if (cmp == 0) continue;  // @43f2b0_e
    if (!ext_4db460(n, (u32)P, (u32)Q)) continue;
    ext_43e8e0_fc3((u32)TA, (u32)P, (u32)Q);  // TA = P + Q
    ext_43e920_fc3((u32)TB, (u32)P, (u32)Q);  // TB = P - Q
    ext_4e08d0_fc2((u32)V0, (u32)TA);  // @43f2b0_f
    ext_4e0900_fc2((u32)V1, (u32)TB);  // @43f2b0_g
    ext_4e08d0_fc2((u32)V2, (u32)TA);  // @43f2b0_h
    ext_4e0900_fc2((u32)V3, (u32)TB);  // @43f2b0_i
  }
  u8 *box = *(u8 **)(self + 8);
  if (asf(V0[0]) == G(float, 0x67cd48)) {  // @43f2b0_j
    ext_4dc5d0(box, 0, 0, 0);
    Q[0] = Q[1] = Q[2] = 0;
    ext_4dd060(box, (u32)Q);
    ext_4dce50(box, 0);
  } else {
    ext_43e8e0_fc3((u32)Q, (u32)V0, (u32)V1);  // Q = V0 + V1
    ext_4e0d00((u8 *)Q, 0x3f000000);  // @43f2b0_k
    ext_4dc600(box, (u32)Q);
    ext_43e920_fc3((u32)Q, (u32)V0, (u32)Q);  // Q = V0 - Q (half extents)
    ext_4dd060(box, (u32)Q);
    float x = asf(Q[0]), y = asf(Q[1]), z = asf(Q[2]);
    float sq = y * y;
    float sx = x * x;
    sx = sx + sq;
    float sz = z * z;
    sx = sx + sz;
    float rad = (float)ext_634d7c_dbl((double)sx) + G(float, 0x678858);  // @43f2b0_l
    ext_4dce50(box, asu(rad));
  }
  if (asf(V2[0]) == G(float, 0x67cd48)) {  // @43f2b0_m
    for (int i = 0x18; i <= 0x2c; i += 4) *(u32 *)(self + i) = 0;
  } else {
    ext_43e8e0_fc3((u32)(self + 0x24), (u32)V2, (u32)V3);  // this+0x24 = V2 + V3
    ext_4e0d00(self + 0x24, 0x3f000000);  // @43f2b0_n
    ext_43e920_fc3((u32)(self + 0x18), (u32)V2, (u32)(self + 0x24));  // this+0x18 = V2 - this+0x24
  }
  ext_633654(0);
}
PCREG(43f2b0, fn43f2b0);

// ---------------------------------------------------------------------------------------------------------------
// 0x5de550: thiscall(this) /GS esp-frame: weighted blend of this+0x4c .. (count this[0x48], stride 0x28) around the
// position W filled by slot 0x84 of [this+0x114]; smoothed value this[0x12c]; writes two fog parameters through slot 0x58
// of the object returned by [[0x70039c]+0x9b] slot 0x138 and packs a 3 byte colour into [this[0x130]+0x152].
// Frame B: A0=B+4 A1=B+8 A2=B+0xc A3=B+0x10 f=B+0x14 dist=B+0x18 t=B+0x1c W=B+0x20..0x28 RGB=B+0x2c..0x34.
extern "C" float FASTCALL ext_4e0870_f(u32, u32) __asm__("ext_4e0870");
extern "C" double VECTORCALL ext_634db8_dbl(double) __asm__("ext_634db8");
// 0x633910 (xmm0 -> eax) reads more than the low float of xmm0: pass a clean vector (upper lanes zero) like the exe does
typedef float v4sf_t __attribute__((vector_size(16)));
extern "C" s32 VECTORCALL ext_633910_i(v4sf_t f) __asm__("ext_633910");

static void THISCALL fn5de550(u8 *self) {
  float W[3] = {0, 0, 0};
  float A0 = 0, A1 = 0, A2 = 0, A3 = 0;
  typedef u32 (THISCALL *Slot1)(u8 *, void *);
  u8 *o114 = *(u8 **)(self + 0x114);
  (*(Slot1 *)(*(u8 **)o114 + 0x84))(o114, W);  // @5de550_a
  u8 *e = self + 0x4c;
  for (; e != self + 0x4c + 0x28 * *(u32 *)(self + 0x48); e += 0x28) {
    float f = G(float, 0x678858);
    float dist = ext_4e0870_f((u32)W, (u32)e);
    s32 dt = (s32)G(u32, *(u32 *)0x70039c + 0x40) - *(s32 *)(e + 0xc);
    float t = (float)dt * G(float, 0x6785e4);  // @5de550_b
    double sq = ext_634d7c_dbl((double)t);
    float r = (float)(sq * (double)(*(float *)(e + 0x10) * G(float, 0x680a68)));  // @5de550_c
    if (dist > r) continue;
    float r2 = r * G(float, 0x67a6ac);
    if (dist > r2) f = (r - dist) / r2;  // @5de550_d
    float x = t * G(float, 0x6b724c) / *(float *)(e + 0x14);  // @5de550_e
    double p = ext_634db8_dbl((double)x);
    float g = (float)(p * (double)*(float *)(e + 0x18) * (double)f);  // @5de550_f
    float d1 = (*(float *)(e + 0x1c) - *(float *)(self + 0x120)) * g + A1;  // @5de550_g
    float d2 = (*(float *)(e + 0x20) - *(float *)(self + 0x124)) * g + A2;  // @5de550_h
    float d3 = (*(float *)(e + 0x24) - *(float *)(self + 0x128)) * g;
    A1 = d1; A2 = d2;
    float n0 = g + A0;  // @5de550_i
    float n3 = d3 + A3;  // @5de550_j
    A0 = n0; A3 = n3;
  }
  u32 n = *(u32 *)(*(u8 **)(self + 0x134) + 0x20);
  double dn = (double)(s32)n;
  static const u32 *tbl = (const u32 *)0x680aa0;
  dn += *(const double *)((u8 *)tbl + (n >> 31) * 8);  // @5de550_k
  float q = (float)dn / G(float, 0x68af18);
  double sq2 = ext_634d7c_dbl((double)q);
  float u = (float)(sq2 * G(double, 0x68d450));  // @5de550_l
  float step = G(float, *(u32 *)0x70039c + 0x48) * G(float, 0x680a6c);  // @5de550_m
  float cur = *(float *)(self + 0x12c);
  if (cur > u) {
    cur = cur - step;
    *(float *)(self + 0x12c) = cur;
    if (u > cur) *(float *)(self + 0x12c) = u;  // @5de550_n
  } else if (u > cur) {
    cur = cur + step;
    *(float *)(self + 0x12c) = cur;
    if (cur > u) *(float *)(self + 0x12c) = u;  // @5de550_o
  }
  cur = *(float *)(self + 0x12c);
  float c0 = *(float *)(self + 0x120), c1 = *(float *)(self + 0x124), c2 = *(float *)(self + 0x128);
  float R = c0 + (A1 - cur * c0);
  float Gc = c1 + (A2 - cur * c1);
  float Bc = c2 + (A3 - cur * c2);
  float s = cur + A0;
  float K = G(float, 0x6972d0);
  float fogv;
  if (K > s) fogv = K;  // @5de550_p
  else { float K2 = G(float, 0x67a6ac); fogv = (K2 < s) ? K2 : s; }
  typedef u8 *(THISCALL *Slot0)(u8 *);
  typedef u32 (THISCALL *Slot3)(u8 *, u32, u32, u32);
  u8 *tab = *(u8 **)(*(u32 *)0x70039c + 0x9b);
  u8 *ob = (u8 *)(*(Slot0 *)(*(u8 **)tab + 0x138))(tab);  // @5de550_q
  (*(Slot3 *)(*(u8 **)ob + 0x58))(ob, 0x6954e8, asu(*(float *)(self + 0x118) - fogv), 3);  // @5de550_r
  tab = *(u8 **)(*(u32 *)0x70039c + 0x9b);
  ob = (u8 *)(*(Slot0 *)(*(u8 **)tab + 0x138))(tab);
  (*(Slot3 *)(*(u8 **)ob + 0x58))(ob, 0x6954f8, asu(*(float *)(self + 0x11c) - fogv), 3);  // @5de550_s
  float rgb[3] = {R, Gc, Bc};
  u32 col = 0;
  for (int i = 0; i < 3; i++) {
    float v = rgb[i] * G(float, 0x6b7248);  // @5de550_t
    float a = 0.0f;
    if (!(0.0f > v)) { float K3 = G(float, 0x68af18); a = (K3 < v) ? K3 : v; }
    col = (col << 8) | (u32)ext_633910_i((v4sf_t){a, 0.0f, 0.0f, 0.0f});
  }
  *(u32 *)(*(u8 **)(self + 0x130) + 0x152) = col;  // @5de550_u
  ext_633654(0);
}
PCREG(5de550, fn5de550);

// ---------------------------------------------------------------------------------------------------------------
// 0x4e3630: thiscall(node, obj, size, x, y, z) ret 0x14, /GS: recursive ray walk of an octree. node = {u16 hdr (octant | count<<3 |
// 0x8000 last), u16 child group index, u16 record offset}. Leaf records (16 bytes) are tested with the ray box test 0x4e2800 and
// reported through the callback obj[4](ecx=record, edx=obj); child boxes are tested the same way and pushed on a heap
// (0x4e3190 push, 0x4e31f0 pop, 9 byte elements {t, node, octant}); the nearest ones are walked first while obj[0] > t.
// 0x4e2800 / 0x4e3190 / 0x4e31f0 are verified rows and run as real exe code.
extern "C" u8 THISCALL ext_4e2800(float *, float, float, float, float, float, float, float, float, float, float, float, float);
extern "C" u32 FASTCALL ext_4e3190_fc(u8 *, s32, u8 *) __asm__("ext_4e3190");
extern "C" u8 *FASTCALL ext_4e31f0_fc(u8 *, s32, u8 *) __asm__("ext_4e31f0");

static u8 THISCALL fn4e3630(u8 *node, u8 *obj, s32 s, s32 x, s32 y, s32 z) {
  u8 heap[8 * 9 + 8];
  u8 elem[12];
  u8 outb[12];
  u8 bl = 0;
  const float *pe = *(const float **)(obj + 0x34), *ps = *(const float **)(obj + 0x30);
  float dx = pe[0] - ps[0], dy = pe[1] - ps[1], dz = pe[2] - ps[2];  // @4e3630_a
  u32 cnt = (*(u16 *)node >> 3) & 0xfff;
  if (cnt) {
    u8 *rec = *(u8 **)(obj + 0x10) + ((u32) * (u16 *)(node + 4) << 4);  // @4e3630_b
    do {
      const float *st = *(const float **)(obj + 0x30);
      float t = -1.0f;
      u8 hit = ext_4e2800(&t, (float)*(u16 *)(rec + 4), (float)*(u16 *)(rec + 6), (float)*(u16 *)(rec + 8), (float)*(u16 *)(rec + 0xa),
                          (float)*(u16 *)(rec + 0xc), (float)*(u16 *)(rec + 0xe), st[0], st[1], st[2], dx, dy, dz);  // @4e3630_c
      if (hit && G(float, (u32)obj) > t) {  // @4e3630_d
        typedef u8(FASTCALL * Cb)(u8 *, u8 *);
        Cb cb = *(Cb *)(obj + 4);
        bl |= cb(rec, obj);  // @4e3630_e
      }
      rec += 0x10;
    } while (--cnt);
  }
  s32 n = 0;  // (the exe keeps bl in a stack slot across the child loop because it reuses bl for the octant; the port has no such clobber)
  u32 n2 = *(u16 *)(node + 2);
  u8 *ch = n2 ? *(u8 **)(obj + 0xc) + 6 * n2 : 0;
  if (ch) {
    s32 half = s >> 1, q = s >> 2;
    for (;;) {
      u32 oc = *(u16 *)ch & 7;
      s32 X = (oc & 1) ? x + q : x - q;  // @4e3630_f
      s32 Y = (oc & 2) ? y + q : y - q;
      s32 Z = (oc & 4) ? z + q : z - q;
      const float *st = *(const float **)(obj + 0x30);
      float t2 = -1.0f;
      u8 hit = ext_4e2800(&t2, (float)(X - half), (float)(Y - half), (float)(Z - half), (float)(X + half), (float)(Y + half), (float)(Z + half),
                          st[0], st[1], st[2], dx, dy, dz);  // @4e3630_g
      if (hit) {
        __builtin_memcpy(elem, &t2, 4);
        __builtin_memcpy(elem + 4, &ch, 4);
        elem[8] = (u8)oc;  // @4e3630_h
        ext_4e3190_fc(heap, n, elem);
        n++;
      }
      u32 hdr = *(u16 *)ch;
      ch += 6;
      if (hdr & 0x8000) break;
    }
  }
  u8 bh = 0;
  s32 rem = n;
  for (s32 i = 0; i < n && !bh; i++, rem--) {
    u8 *p = ext_4e31f0_fc(heap, rem, outb);
    float t;
    u8 *cn;
    __builtin_memcpy(&t, p, 4);
    __builtin_memcpy(&cn, p + 4, 4);
    u8 cl = p[8];
    if (G(float, (u32)obj) > t) {  // @4e3630_i
      s32 qq = s >> 2;
      s32 X = (cl & 1) ? x + qq : x - qq;  // @4e3630_j
      s32 Y = (cl & 2) ? y + qq : y - qq;
      s32 Z = (cl & 4) ? z + qq : z - qq;
      bl |= fn4e3630(cn, obj, s >> 1, X, Y, Z);  // @4e3630_k
    } else {
      bh = 1;
    }
  }
  ext_633654(0);
  return bl;
}
PCREG(4e3630, fn4e3630);

// ---------------------------------------------------------------------------------------------------------------
// 0x5a4120: thiscall(this) per-frame update of a four-slot message/timer widget (no /GS). Engine object [0x70039c], its table object
// T = [engine+0x9b]: slot 0x114 (string lookup, 6 stack args, returns ax), W = this[0x44]: slot 0x128 (show string id).
// Callees 0x5a4f70 (this, P, index), 0x589c20 (object by id), 0x59a5e0 (trigger id) are verified rows and are hooked by the spec.
// Float compares follow comiss: `a > b` is the "not jbe" arm, NaN takes the jbe/jb arm.
extern "C" u32 THISCALL ext_5a4f70(u8 *, u32, u32);
extern "C" u32 THISCALL ext_589c20(u8 *, s32);
extern "C" u32 THISCALL ext_59a5e0(u8 *, u32);

static inline u32 vslot(u8 *o, u32 off) { return *(u32 *)(*(u8 **)o + off); }

// T.slot 0x114(str, 0, 0x6af0cc, line, a4, 0) -> ax ; W.slot 0x128(ax)
static void msg5a4120(u8 *self, u32 str, u32 line, u32 a4) {
  u8 *T = *(u8 **)(*(u32 *)0x70039c + 0x9b);
  u8 *W = *(u8 **)(self + 0x44);
  u8 *Wv = *(u8 **)W;
  typedef u32 (THISCALL *S6)(u8 *, u32, u32, u32, u32, u32, u32);
  typedef u32 (THISCALL *S1)(u8 *, u32);
  u32 ax = (u16)(*(S6 *)(*(u8 **)T + 0x114))(T, str, 0, 0x6af0cc, line, a4, 0);  // @5a4120_m
  (*(S1 *)(Wv + 0x128))(W, ax);  // @5a4120_n
}

static void THISCALL fn5a4120(u8 *self) {
  if (*(u32 *)(self + 0x10b)) {
    u8 *P = *(u8 **)(self + 0x11b);
    if (P) {
      float v = G(float, *(u32 *)0x70039c + 0x48) + *(float *)(self + 0x127);  // @5a4120_a
      float lim = *(float *)(self + 0x113);
      *(float *)(self + 0x127) = v;
      if (v > lim) {  // @5a4120_b
        u8 *Q = *(u8 **)(P + 0x18);
        typedef s32 (THISCALL *S0)(u8 *);
        s32 n = (*(S0 *)(*(u8 **)Q + 0x14))(Q);
        n = n - (n >> 31);
        s32 half = n >> 1;
        typedef u32 (*Rand)();
        s32 rr = (s32)(*(Rand *)0x67644c)();
        *(u32 *)(self + 0x127) = 0;
        *(s32 *)(self + 0x12b) = rr % half;  // @5a4120_c
      }
    }
    ext_5a4f70(self, *(u32 *)(self + 0x11b), *(u32 *)(self + 0x12b));  // @5a4120_d
  }
  if (*(u8 *)(self + 0x58)) {
    u8 *e = self + 0x6f;
    for (int k = 0; k < 4; k++, e += 0x12) {
      if (e[-0xe]) {  // @5a4120_e
        float tmr = *(float *)e - G(float, *(u32 *)0x70039c + 0x48);
        *(float *)e = tmr;
        u8 *obj = (u8 *)ext_589c20((u8 *)G(u32, 0x7003b8), 0);
        s32 sec = __builtin_ia32_cvttss2si((v4sf_t){*(float *)e, 0.0f, 0.0f, 0.0f});
        u32 id = 0;
        if (sec == 5) { if (!self[0x60]) { self[0x60] = 1; id = 0xa; } }
        else if (sec == 0x1e) { if (!self[0x5f]) { self[0x5f] = 1; id = 9; } }
        else if (sec == 0x3c) { if (!self[0x5e]) { self[0x5e] = 1; id = 8; } }
        if (id) ext_59a5e0(obj, id);  // @5a4120_f
        if (*(float *)e <= 0.0f) {  // @5a4120_g
          *(float *)e = 0;
          if (!self[0x109]) {
            msg5a4120(self, 0x6af12c, 0x23a, 1);
            self[0x109] = 1;
          }
        }
      } else {
        float t = *(float *)e, lo = *(float *)(self + 0x4c);
        if (t >= lo) *(float *)e = lo;  // @5a4120_h
        else *(float *)e = G(float, *(u32 *)0x70039c + 0x48) / G(float, 0x680a68) + t;  // @5a4120_i
      }
    }
  }
  if (*(u8 *)(self + 0x59)) {
    float f = *(float *)(self + 0x50) - G(float, *(u32 *)0x70039c + 0x48);  // @5a4120_j
    *(float *)(self + 0x50) = f;
    if (f < 0.0f) {  // @5a4120_k
      *(u32 *)(self + 0x50) = 0;
      if (!self[0x109]) {
        msg5a4120(self, 0x6af12c, 0x25b, 0);
        self[0x109] = 1;
      }
    }
    u8 *obj = (u8 *)ext_589c20((u8 *)G(u32, 0x7003b8), 0);
    s32 sec = __builtin_ia32_cvttss2si((v4sf_t){*(float *)(self + 0x50), 0.0f, 0.0f, 0.0f});
    u32 id = 0;
    if (sec == 5) { if (!self[0x60]) { self[0x60] = 1; id = 0xa; } }
    else if (sec == 0x1e) { if (!self[0x5f]) { self[0x5f] = 1; id = 9; } }
    else if (sec == 0x3c) { if (!self[0x5e]) { self[0x5e] = 1; id = 8; } }
    if (id) ext_59a5e0(obj, id);  // @5a4120_l
  }
  static const u32 offA[4] = {0x63, 0x75, 0x87, 0x99}, offB[4] = {0x67, 0x79, 0x8b, 0x9d}, flg[4] = {0x62, 0x74, 0x86, 0x98};
  if (self[0x5a]) {
    u32 any = 0;
    for (int k = 0; k < 4; k++)
      if (*(s32 *)(self + offA[k]) >= *(s32 *)(self + 0x54)) { self[flg[k]] = 1; any = 1; }  // @5a4120_o
    if (!self[0x10a] && any) { msg5a4120(self, 0x6af1b8, 0x291, G(u32, 0x7142f4)); self[0x10a] = 1; }
  }
  if (self[0x5b]) {
    u32 any = 0;
    for (int k = 0; k < 4; k++)
      if (*(s32 *)(self + offB[k]) >= *(s32 *)(self + 0x54)) { self[flg[k]] = 1; any = 1; }  // @5a4120_p
    if (!self[0x10a] && any) { msg5a4120(self, 0x6af1b8, 0x2ac, G(u32, 0x6ed238)); self[0x10a] = 1; }
  }
  if (self[0x5c] && !self[0x5d]) {
    u8 *T = *(u8 **)(*(u32 *)0x70039c + 0x9b);
    typedef u32 (THISCALL *S1)(u8 *, u32);
    typedef u8 *(THISCALL *S0o)(u8 *);
    typedef u32 (THISCALL *S2)(u8 *, u32, u32);
    typedef u32 (THISCALL *S5)(u8 *, u32, u32, u32, u32, u32);
    (*(S1 *)(*(u8 **)T + 0xb4))(T, 1);  // @5a4120_q
    T = *(u8 **)(*(u32 *)0x70039c + 0x9b);
    u8 *Y = (*(S0o *)(*(u8 **)T + 0x138))(T);
    u32 loc = 0;
    (*(S2 *)(*(u8 **)Y + 0x88))(Y, 0x6a82d0, (u32)&loc);  // @5a4120_r
    u8 *W = *(u8 **)(self + 0x44);
    u32 val = loc;
    u8 *Wv = *(u8 **)W;
    T = *(u8 **)(*(u32 *)0x70039c + 0x9b);
    u32 ax = (u16)(*(S5 *)(*(u8 **)T + 0x114))(T, 0x6a6698, 0, 0x6af0cc, 0x2b7, 0);  // @5a4120_s
    (*(S2 *)(Wv + 0x12c))(W, val, ax);  // @5a4120_t
    self[0x5d] = 1;
  }
}
PCREG(5a4120, fn5a4120);

// ---------------------------------------------------------------------------------------------------------------
// 0x457d50: thiscall(this), /GS: (re)initialises N particles (N = this[0x34]; 0x30 byte records at this[0xcc], 0x10 byte records at this[0xd0])
// with engine random numbers (slot 0x1bc of [0x70039c], 2 stack args), builds the 8 corners of the box object this[8] (+0x40..0x48) into
// this+0x5c..0x88 / 0x8c..0xb0 via the vector helper 0x43e920 and runs the particle step 0x459c40(1.0) 100 times.
// 0x457760 and 0x459c40 are verified rows (hooked by the spec); 0x43e920 / 0x633910 run as real code.
extern "C" u32 THISCALL ext_457760(u8 *, u32);
extern "C" u32 THISCALL ext_459c40(u8 *, u32);

static inline s32 rnd457d50() {
  u8 *eng = (u8 *)G(u32, 0x70039c);
  typedef s32 (THISCALL * S2)(u8 *, u32, u32);
  return (*(S2 *)(*(u8 **)eng + 0x1bc))(eng, 0x683734, 0x43a);  // @457d50_r
}
static inline float rf457d50(s32 r) { return (float)r / G(float, 0x683774) - G(float, 0x678858); }  // @457d50_s
static inline s32 ftolN457d50(u8 *self, float mult) {
  u32 N = *(u32 *)(self + 0x34);
  double d = (double)(s32)N + *(const double *)(0x680aa0 + (N >> 31) * 8);
  return ext_633910_i((v4sf_t){(float)d * mult, 0.0f, 0.0f, 0.0f});
}

static void THISCALL fn457d50(u8 *self) {
  float F = 0.0f;
  float f98 = *(float *)(self + 0x38);
  u8 *P1 = *(u8 **)(self + 0xd0);
  float f18 = *(float *)(self + 0x18);
  if (f18 == 0.0f) {  // @457d50_a
    u8 *pp = *(u8 **)(self + 0xcc);
    if (*(u32 *)(self + 0x34) != 0) {
      u32 i = 0;
      do {
        ext_457760(self, (u32)P1);
        *(float *)(pp + 0xc) = f98;
        float F2 = F + G(float, 0x67a288);  // @457d50_b
        *(float *)(pp + 0x10) = F + 0.0f;
        *(float *)(pp + 0x14) = F2;
        F = F2;
        if (F2 >= G(float, 0x678858)) F = 0.0f;  // @457d50_c
        *(u32 *)(pp + 0x18) = 0;
        *(u32 *)(pp + 0x1c) = 0;
        float a1 = rf457d50(rnd457d50());
        float a2 = rf457d50(rnd457d50());
        float a3 = rf457d50(rnd457d50());
        *(float *)(pp + 0) = __builtin_fabsf(a3);
        *(float *)(pp + 4) = __builtin_fabsf(a2);
        *(float *)(pp + 8) = __builtin_fabsf(a1);
        pp += 0x20;
        *(u32 *)(P1 + 0xc) = 0;
        P1 += 0x10;
        i++;
      } while (i != *(u32 *)(self + 0x34));
    }
  } else {
    u8 *P0 = *(u8 **)(self + 0xcc);
    u32 N = *(u32 *)(self + 0x34);
    u32 m = 0;
    s32 T = ftolN457d50(self, G(float, 0x67c19c));  // @457d50_d
    if (N) {
      u32 i = 0;
      do {
        if (i > (u32)T) {  // @457d50_e
          m = (m < 3) ? m + 1 : m;
          T = ftolN457d50(self, G(float, 0x683780 + 4 * m));  // @457d50_f
          float s = F + G(float, 0x67a288);
          float one = G(float, 0x678858);
          F = (one < s) ? one : s;  // @457d50_g
        }
        ext_457760(self, (u32)P1);
        u8 *pe = P0 + 0x28;
        *(float *)(pe - 0x1c) = f98;
        *(float *)(pe - 0x18) = F + G(float, 0x6785d0);
        *(u32 *)(pe - 0x10) = 0;
        *(u32 *)(pe - 0xc) = 0;
        *(float *)(pe - 0x14) = F + G(float, 0x67a288);
        float a1 = rf457d50(rnd457d50());
        float a2 = rf457d50(rnd457d50());
        float a3 = rf457d50(rnd457d50());
        *(float *)(P0 + 0) = __builtin_fabsf(a3);
        *(float *)(pe - 0x24) = __builtin_fabsf(a2);
        *(float *)(pe - 0x20) = __builtin_fabsf(a1);
        *(u32 *)(pe - 8) = 0;
        *(u32 *)(pe - 4) = 0;
        *(u32 *)pe = 0;
        P0 += 0x30;
        *(u32 *)(P1 + 0xc) = 0;
        P1 += 0x10;
        i++;
      } while (i != *(u32 *)(self + 0x34));
    }
  }
  u8 *O = *(u8 **)(self + 8);
  *(u32 *)(self + 0xbc) = 0x7fffffff;
  u32 X = *(u32 *)(O + 0x40), Y = *(u32 *)(O + 0x44), Z = *(u32 *)(O + 0x48);
  u32 nX = X ^ 0x80000000, nY = Y ^ 0x80000000, nZ = Z ^ 0x80000000;
  u32 C[24] = {X, Y, Z, X, nY, Z, nX, nY, Z, nX, Y, Z, X, Y, nZ, X, nY, nZ, nX, nY, nZ, nX, Y, nZ};  // @457d50_h
  *(u32 *)(self + 0x5c) = nX;
  *(u32 *)(self + 0x60) = nY;
  *(u32 *)(self + 0x64) = nZ;
  ext_43e920_fc3((u32)(self + 0x8c), (u32)&C[6], (u32)&C[18]);  // @457d50_i
  *(u32 *)(self + 0x68) = C[15]; *(u32 *)(self + 0x6c) = C[16]; *(u32 *)(self + 0x70) = C[17];
  ext_43e920_fc3((u32)(self + 0x98), (u32)&C[3], (u32)&C[15]);  // @457d50_j
  *(u32 *)(self + 0x74) = C[21]; *(u32 *)(self + 0x78) = C[22]; *(u32 *)(self + 0x7c) = C[23];
  ext_43e920_fc3((u32)(self + 0xa4), (u32)&C[9], (u32)&C[21]);  // @457d50_k
  *(u32 *)(self + 0x80) = C[12]; *(u32 *)(self + 0x84) = C[13]; *(u32 *)(self + 0x88) = C[14];
  ext_43e920_fc3((u32)(self + 0xb0), (u32)&C[0], (u32)&C[12]);  // @457d50_l
  for (int k = 0; k < 100; k++) ext_459c40(self, 0x3f800000);  // @457d50_m
  ext_633654(0);
}
PCREG(457d50, fn457d50);

// ---------------------------------------------------------------------------------------------------------------
// 0x485110: thiscall(this), /GS, 0x154 byte frame: per-frame sweep of the manager list [0x7003b8]+0x4b4.. (count at +0x4b0): for every item
// it asks the item's owner object (slot 0x20 of [item+4]) and updates positions through slot 0x7c/0x80 of that object, running a
// sphere/ray query (slot 0x2e0 of [[[0x70039c]+0x9b]+0xadc]) and the vector helpers (all verified rows, real code):
// 0x4e64a0 / 0x4e1b60 (struct init), 0x443ef0 0x43e8e0 0x43e920 0x441940 0x4e0d00 (vector math), 0x44c840 / 0x44e630 (normalise),
// 0x4856f0 (all-zero test), 0x4e65e0 (interval pair), 0x4e64b0 (sweep). Frame model: u8 L[0x154], ebp-OFF == L + 0x154 - OFF.
extern "C" u32 THISCALL ext_4e64a0(u8 *);
extern "C" u32 THISCALL ext_4e1b60(u8 *);
extern "C" u32 FASTCALL ext_443ef0_fc(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_441940_fc(u32, u32) __asm__("ext_441940");
extern "C" u8 THISCALL ext_4856f0(u8 *);
extern "C" float THISCALL ext_44c840_f(u8 *) __asm__("ext_44c840");
extern "C" float FASTCALL ext_44e630_f(u32, u32) __asm__("ext_44e630");
extern "C" u8 THISCALL ext_4e65e0(u8 *, u32, u32);
extern "C" u32 THISCALL ext_4e64b0(u8 *, u32, u32, u32, u32);

#define LF(off) ((float *)(L + 0x154 - (off)))
#define LU(off) ((u32 *)(L + 0x154 - (off)))
#define LP(off) ((u32)(L + 0x154 - (off)))

static void THISCALL fn485110(u8 *self) {
  u8 L[0x154];
  for (u32 i = 0; i < sizeof L; i++) L[i] = 0;
  typedef u32 (THISCALL * V2)(u8 *, u32, u32);
  typedef u32 (THISCALL * V1)(u8 *, u32);
  typedef u8 *(THISCALL * V0)(u8 *);
  ext_4e64a0(L + 0x154 - 0x148);
  (*(V2 *)(*(u8 **)self + 0x59c))(self, LP(0x70), LP(0x28));  // @485110_a
  (*(V1 *)(*(u8 **)self + 0x5c4))(self, LP(0x34));  // @485110_b
  float scale = G(float, *(u32 *)0x70039c + 0x48) * G(float, 0x67885c);  // @485110_c
  ext_443ef0_fc(LP(0x154), LP(0x28), LP(0x34), *(u32 *)&scale);
  u8 *O = *(u8 **)(self + 8);
  *(u32 *)(self + 0x4f1) = 0;
  u8 *M = (u8 *)G(u32, 0x7003b8);
  float a = *(float *)(O + 0x34) + *LF(0x150);  // @485110_d
  float o44 = *(float *)(O + 0x44);
  float hi = o44 + a;  // @485110_e
  float lo = a - o44;
  *LF(0x12c) = hi;
  *LF(0x130) = lo;
  u32 *iter = (u32 *)(M + 0x4b4);
  u32 *end = (u32 *)(M + (*(u32 *)(M + 0x4b0) + 0x12d) * 4);
  if (iter != end) {
    do {
      u8 *esi = (u8 *)*iter;
      u8 *edi = (*(V0 *)(*(u8 **)*(u8 **)(esi + 4) + 0x20))(*(u8 **)(esi + 4));  // @485110_f
      typedef u32 (THISCALL * V7c)(u8 *, u32, u32);
      u32 pos = (u32)(esi + 8), rec14 = (u32)(esi + 0x14);
      if (*(u32 *)(*(u8 **)(edi + 8) + 0x3c) & 0x800) {  // @485110_g
        (*(V7c *)(*(u8 **)edi + 0x7c))(edi, rec14, pos);
      } else if (!*(u8 *)(esi + 0x4c) || !*(u8 *)(self + 0x5ff) || (*(u8 *)(*(u8 **)(*(u8 **)(esi + 4) + 0x1c) + 4) & 2)) {  // @485110_h
        (*(V7c *)(*(u8 **)edi + 0x7c))(edi, rec14, pos);
      } else {
        (*(V2 *)(*(u8 **)edi + 0x80))(edi, LP(0x94), LP(0x1c));  // @485110_i
        ext_43e920_fc3(LP(0x10), pos, LP(0x154));
        *LU(0xc) = 0;
        float x2 = *LF(0x10) * *LF(0x10);
        float r = *(float *)(esi + 0x38) + G(float, 0x684cf0);  // @485110_j
        x2 = x2 + 0.0f;
        float z2 = *LF(8) * *LF(8);
        float r2 = r * r;
        float d2 = x2 + z2;
        bool in_range = false;
        if (r2 > d2) {  // @485110_k
          u8 *O2 = *(u8 **)(edi + 8);
          float c = *(float *)(O2 + 0x34) + *LF(0x18);
          float e44 = *(float *)(O2 + 0x44);
          float c0 = c - e44;
          if (*LF(0x12c) > c0) {  // @485110_l
            float c1 = e44 + c;
            if (c1 > *LF(0x130)) in_range = true;  // @485110_m
          }
        }
        if (!in_range) {
          u32 *sysi = (u32 *)(*(u32 *)0x70039c + 0x40);
          u32 *mine = (u32 *)(esi + 0x4d);
          if (*(s32 *)sysi > *(s32 *)mine) {  // @485110_n
            *mine = *sysi;
            (*(V7c *)(*(u8 **)edi + 0x7c))(edi, rec14, pos);
          }
        } else {
          if (*(float *)(esi + 0x3c) >= G(float, 0x67ff1c)) {  // @485110_o
            s32 cnt = *(s32 *)(self + 0x4f1);
            if (cnt < 4) {
              *(u32 *)(self + cnt * 4 + 0x4e1) = (u32)esi;
              *(s32 *)(self + 0x4f1) = cnt + 1;
            } else {
              u8 *lg = (u8 *)G(u32, 0x700390);
              typedef u8 *(THISCALL * L20)(u8 *, u32, u32);
              typedef void (*L30)(u8 *, u32);
              u8 *ob = (*(L20 *)(*(u8 **)lg + 0x20))(lg, 0x68bcbc, 0x5bc);
              (*(L30 *)(*(u8 **)ob + 0x30))(ob, 0x68c040);  // @485110_p
            }
            *LU(0x10) = ((u32 *)pos)[0];
            *LU(0xc) = ((u32 *)pos)[1];
            *LU(8) = ((u32 *)pos)[2];
          } else {
            ext_43e920_fc3(LP(0x10), pos, LP(0x28));
            *LU(0xc) = 0;
            ext_43e920_fc3(LP(0x40), pos, LP(0x1c));
            ext_4e65e0(L + 0x154 - 0x148, *(u32 *)(self + 0x4dd), *(u32 *)(esi + 0x3c));  // @485110_q
            ext_4e64b0(L + 0x154 - 0x148, LP(0x34), LP(0x40), LP(0x10), 0);  // @485110_r
            ext_43e8e0_fc3(LP(0x10), LP(0x1c), LP(0x40));
            ext_43e920_fc3(LP(0x140), LP(0x10), LP(0x28));
            *LU(0x13c) = 0;
            float lim = *(float *)(esi + 0x38) + G(float, 0x67da20);  // @485110_s
            *LF(0x10c) = lim;
            float ln = ext_44c840_f(L + 0x154 - 0x140);
            *LF(0x134) = ln;
            if (*LF(0x10c) > *LF(0x134)) {  // @485110_t
              if (!ext_4856f0(L + 0x154 - 0x140)) {
                ext_443ef0_fc(LP(0x10), LP(0x28), LP(0x140), *LU(0x10c));
                *LU(0xc) = *(u32 *)(esi + 0xc);
              } else {
                *LU(0x10) = *LU(0x1c); *LU(0xc) = *LU(0x18); *LU(8) = *LU(0x14);
              }
            }
            ext_4e1b60(L + 0x154 - 0x104);
            *LU(0x11c) = ((u32 *)pos)[0];
            *LF(0x118) = *(float *)(esi + 0xc) + G(float, 0x678858);  // @485110_u
            *LU(0x114) = *(u32 *)(esi + 0x10);
            *LU(0x128) = *LU(0x10);
            *LF(0x124) = *LF(0xc) + G(float, 0x678858);
            *LU(0x120) = *LU(8);
            ext_43e920_fc3(LP(0xf8), LP(0x128), LP(0x11c));
            if (!ext_4856f0(L + 0x154 - 0xf8)) {  // @485110_v
              *LU(0x104) = *LU(0x11c); *LU(0x100) = *LU(0x118); *LU(0xfc) = *LU(0x114);
              ext_44e630_f(LP(0x4c), LP(0xf8));
              ext_4e0d00(L + 0x154 - 0x4c, *(u32 *)(esi + 0x38));
              ext_441940_fc(LP(0xf8), LP(0x4c));
              u8 *V = *(u8 **)(*(u8 **)(*(u32 *)0x70039c + 0x9b) + 0xadc);
              typedef u8 (THISCALL * Q6)(u8 *, u32, u32, u32, s32, u32, u32);
              u8 q1 = (*(Q6 *)(*(u8 **)V + 0x2e0))(V, LP(0x104), 0, 0x20, -1, 1, 0);  // @485110_w
              if (q1) { *LU(0x10) = *LU(0x1c); *LU(0xc) = *LU(0x18); *LU(8) = *LU(0x14); }
              *LU(0x104) = *LU(0x128); *LU(0x100) = *LU(0x124);
              *LU(0xd0) = 0x3f800000;
              *LU(0xfc) = *LU(0x120);
              *LU(0xf8) = 0; *LU(0xf4) = 0xc0000000; *LU(0xf0) = 0;
              V = *(u8 **)(*(u8 **)(*(u32 *)0x70039c + 0x9b) + 0xadc);
              u8 q2 = (*(Q6 *)(*(u8 **)V + 0x2e0))(V, LP(0x104), 0, 0x20, -1, 1, 0);  // @485110_x
              if (!q2) { *LU(0x10) = *LU(0x1c); *LU(0xc) = *LU(0x18); *LU(8) = *LU(0x14); }
            }
          }
          u32 *sysi = (u32 *)(*(u32 *)0x70039c + 0x40);
          u32 *mine = (u32 *)(esi + 0x4d);
          if (mine != sysi) *mine = *sysi;  // @485110_y
          (*(V7c *)(*(u8 **)edi + 0x7c))(edi, rec14, LP(0x10));  // @485110_z
        }
      }
      M = (u8 *)G(u32, 0x7003b8);
      iter++;
      end = (u32 *)(M + (*(u32 *)(M + 0x4b0) + 0x12d) * 4);
    } while (iter != end);
  }
  ext_633654(0);
}
PCREG(485110, fn485110);

// ---------------------------------------------------------------------------------------------------------------
// 0x58c450: thiscall(this, a0, a1, a2, a3) ret 0x10, /GS, six-way switch on a0[0x48] (jump table 0x58ca94: 0,1,2,3,4,5 -> 58c48e 58c588 58c5f9
// 58c6fc 58c900 58c717), E = a0[0x44]. Proximity / overlap tests between this and E returning al. Esp-frame: F[] is the exe's 0x100 byte
// block B (aligned esp after `and esp,-8; sub esp,0x100`), offsets below are B-relative, derived from the esp deltas of every pending
// push (body esp = B-8 after `push esi; push edi`). Slots 0x3a0 then 0x398 are called as a pair: 0x3a0 leaves its argument on the stack
// (no pop, the exe merges the cleanup), 0x398 pops 8 (its own argument and the leftover one): asm block below.
// Helpers 0x4de420 0x43e920 0x441940 0x441970 0x4419f0 0x441a60 0x4daf90 0x4db7c0 0x4e0870 0x4e1b60 0x4df330 (verified rows) run as real code;
// 0x58c150 and 0x41e680 are recorders.
extern "C" u32 FASTCALL ext_4de420_fc(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_441a60_fc(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4419f0_fc(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441970_fc3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 THISCALL ext_4daf90(u8 *, u32);
extern "C" u32 THISCALL ext_4db7c0(u8 *, u32);
extern "C" u32 THISCALL ext_41e680(u8 *);
extern "C" u8 THISCALL ext_58c150(u8 *, u32, u32, u32);
extern "C" u8 FASTCALL ext_4df330_fc(u32, u32, u32, u32, u32, u32) __asm__("ext_4df330");

#define FB(off) ((float *)(F + (off)))
#define FU(off) ((u32 *)(F + (off)))
#define FP(off) ((u32)(F + (off)))

// slot 0x3a0 (arg ptr; caller keeps the stack word) followed by slot 0x398 (value, and the kept word): net stack effect zero
static inline void slot_pair_3a0_398(u8 *obj, u8 *vt, u32 ptr) {
  __asm__ volatile(
      "pushl %[p]\n\t"
      "movl %[o], %%ecx\n\t"
      "call *0x3a0(%[v])\n\t"
      "pushl %%eax\n\t"
      "movl %[o], %%ecx\n\t"
      "call *0x398(%[v])\n\t"
      :
      : [p] "r"(ptr), [o] "r"(obj), [v] "r"(vt)
      : "eax", "ecx", "edx", "memory", "cc");
}

static u8 THISCALL fn58c450(u8 *self, u8 *a0, u8 *a1, u8 *a2, u32 a3) {
  u8 F[0x120];
  for (u32 i = 0; i < sizeof F; i++) F[i] = 0;
  u8 *E = *(u8 **)(a0 + 0x44);
  u32 sel = *(u32 *)(a0 + 0x48);
  u8 res = 1;
  typedef u32 (THISCALL * S2)(u8 *, u32, u32);
  typedef u32 (THISCALL * S1)(u8 *, u32);
  u8 *vtE = *(u8 **)E, *vtT = *(u8 **)self;
  if (sel > 5) { ext_633654(0); return 1; }
  switch (sel) {
    case 0: {
      if ((u8)a3) {
        *FU(0x7c) = ((u32 *)a2)[0];  // @58c450_a
        *FU(0x80) = ((u32 *)a2)[1];
        *FU(0x84) = ((u32 *)a2)[2];
        ext_4de420_fc(FP(0xb4), (u32)a1);
      } else {
        if (!ext_58c150(self, (u32)a0, FP(0xb4), FP(0x7c))) { res = 0; break; }  // @58c450_b
      }
      ext_43e920_fc3(FP(0x88), FP(0x7c), (u32)self + 0x886);  // @58c450_c
      ext_441a60_fc(FP(0x88), (u32)self + 0x892);  // @58c450_d
      float dy = *FB(0x8c);
      if (!(dy > G(float, 0x689d24))) { res = 0; break; }  // @58c450_e
      if (!(G(float, 0x67da2c) > dy)) { res = 0; break; }  // @58c450_f
      float dx = *FB(0x88), dz = *FB(0x90);
      float s = dx * dx;
      float z2 = dz * dz;
      s = s + G(float, 0x6785d0);
      s = s + z2;
      res = (G(float, 0x6abbac) > s) ? 1 : 0;  // @58c450_g
      break;
    }
    case 1: {
      (*(S2 *)(vtE + 0x80))(E, FP(0xd8), FP(0xa8));  // @58c450_h
      (*(S2 *)(vtT + 0x80))(self, FP(0xb4), FP(0x9c));  // @58c450_i
      float len = ext_4e0870_f(FP(0x9c), FP(0xa8));  // @58c450_j
      *FB(4) = len;
      res = (G(float, 0x67cd40) > *FB(4)) ? 1 : 0;  // @58c450_k
      break;
    }
    case 2:
    case 3: {
      if (sel == 2) { *FB(0x88) = 30.0f; *FU(0x90) = 0x42200000; }  // @58c450_l
      else { *FU(0x88) = 0x42b40000; *FU(0x90) = 0x42b40000; }
      *FU(0x8c) = 0x42200000;  // compiler quirk: the exe stores 40.0 through a second (esp-shifted) address, = F+0x8c
      (*(S2 *)(vtE + 0x80))(E, FP(0xb4), FP(0xa8));  // @58c450_m
      u8 *E8 = *(u8 **)(E + 8);
      ext_4daf90(E8, FP(0x7c));  // @58c450_n
      ext_4db7c0(E8, FP(0x9c));
      *FB(0xa0) = *FB(0xa0) + G(float, 0x67da20);  // @58c450_o
      ext_4419f0_fc(FP(0x7c), FP(0xb4));  // @58c450_p
      ext_441940_fc(FP(0xa8), FP(0x7c));
      (*(S2 *)(vtT + 0x384))(self, FP(0xd8), FP(0x7c));  // @58c450_q
      u8 r = ext_4df330_fc(FP(0xd8), FP(0x7c), FP(0x88), FP(0xb4), FP(0xa8), FP(0x9c));  // @58c450_r
      res = (r != 0) ? 1 : 0;
      break;
    }
    case 5: {
      (*(S2 *)(vtE + 0x80))(E, FP(0xd8), FP(0x9c));  // @58c450_s
      (*(S2 *)(vtT + 0x384))(self, FP(0xb4), FP(0x7c));  // @58c450_t
      float len = ext_4e0870_f(FP(0x7c), FP(0x9c));
      *FB(0x88) = len;
      if (!(G(float, 0x6abba4) > *FB(0x88))) { res = 0; break; }  // @58c450_u
      slot_pair_3a0_398(self, vtT, FP(0x7c));  // @58c450_v
      (*(S1 *)(vtT + 0x84))(self, FP(0x7c));  // @58c450_w
      typedef u8 (THISCALL * S1b)(u8 *, u32);
      if ((*(S1b *)(vtE + 0x1e0))(E, 0x200027)) {  // @58c450_x
        slot_pair_3a0_398(E, vtE, FP(0x9c));
        (*(S1 *)(vtE + 0x84))(E, FP(0x9c));  // @58c450_y
      }
      ext_43e920_fc3(FP(0x88), FP(0x9c), FP(0x7c));
      ext_4e1b60(F + 8);
      *FU(0x8) = *FU(0x7c); *FU(0xc) = *FU(0x80); *FU(0x10) = *FU(0x84);  // @58c450_z
      *FU(0x14) = *FU(0x88); *FU(0x18) = *FU(0x8c); *FU(0x1c) = *FU(0x90);
      F[0x74] = 0;
      *FU(0x4c) = 0;
      u8 *V = *(u8 **)(*(u8 **)(*(u32 *)0x70039c + 0x9b) + 0xadc);
      typedef u32 (THISCALL * Q6)(u8 *, u32, u32, u32, s32, u32, u32);
      (*(Q6 *)(*(u8 **)V + 0x2e0))(V, FP(0x8), 0, 0x10, -1, 1, 0);  // @58c450_aa
      u8 *R = (u8 *)G(u32, 0x70038c);
      (*(S1 *)(*(u8 **)R + 0xcc))(R, *FU(0x4c));  // @58c450_ab
      if (*FU(0x4c) == 0) { res = 1; break; }
      u32 id = ext_41e680(E);
      res = (*FU(0x4c) == id) ? 1 : 0;  // @58c450_ac
      break;
    }
    case 4: {
      (*(S2 *)(vtE + 0x80))(E, FP(0xd8), FP(0x9c));  // @58c450_ad
      ext_441970_fc3(FP(0x7c), *(u32 *)(E + 8) + 0x30, FP(0xd8));  // @58c450_ae
      ext_441940_fc(FP(0x9c), FP(0x7c));
      (*(S2 *)(vtT + 0x80))(self, FP(0xb4), FP(0xa8));  // @58c450_af
      ext_441970_fc3(FP(0x7c), *(u32 *)(self + 8) + 0x30, FP(0xb4));
      ext_441940_fc(FP(0xa8), FP(0x7c));
      ext_43e920_fc3(FP(0x7c), FP(0x9c), FP(0xa8));  // @58c450_ag
      float x2 = *FB(0x7c) * *FB(0x7c);
      *FU(0x80) = 0;
      x2 = x2 + 0.0f;
      float z2 = *FB(0x84) * *FB(0x84);
      x2 = x2 + z2;
      float d = (float)ext_634d7c_dbl((double)x2);  // @58c450_ah
      if (G(float, 0x680a84) > d) { res = 1; break; }
      u32 id = ext_41e680(E);
      typedef double (THISCALL * D1)(u8 *, u32);
      double w = (*(D1 *)(vtT + 0x194))(self, id);  // @58c450_ai
      if (!(G(double, 0x6ad200) > __builtin_fabs(w))) { res = 0; break; }
      float len = ext_4e0870_f(FP(0xa8), FP(0x9c));
      *FB(0x88) = len;
      res = (G(float, 0x68c74c) > *FB(0x88)) ? 1 : 0;  // @58c450_aj
      res = res ? 1 : 0;
      break;
    }
  }
  ext_633654(0);
  return res;
}
PCREG(58c450, fn58c450);

// ---------------------------------------------------------------------------------------------------------------
// 0x47b290: thiscall(this, str) ret 4, /GS, frame 0x48 (ebp-relative model): when the global float [0x6ffa18] != 0 and this+0x10 / this+8
// pass their checks, projects the entity position (slots 0x3a0/0x398 pair, 0x84, camera object from the table slots 0x138 / 0x88 / 0x58,
// slots 0x8c, 0x240, 0x248 (float on the x87 stack) of the camera) to screen coordinates and draws up to three strings through slot
// 0x184 (cdecl) of the object from sys slot 0x190: an optional name from the string table [0x7003a4] slot 0x9c, the text pointed to by
// this[0x412] and the argument string, each centred by half its length. ceil comes from the CRT (0x634da6, cdecl, double on the stack,
// result on the x87 stack). Helpers 0x4cc5f0 (strlen of *ptr) and 0x4cc1d0 (*ptr) are verified rows run as real code.
extern "C" double ext_634da6_ceil(double) __asm__("ext_634da6");
extern "C" u32 THISCALL ext_4cc5f0(u8 *);
extern "C" u32 THISCALL ext_4cc1d0(u8 *);

#define NF(off) ((float *)(F + 0x48 - (off)))
#define NU(off) ((u32 *)(F + 0x48 - (off)))
#define NP(off) ((u32)(F + 0x48 - (off)))

static inline s32 trunc47(float x) { return __builtin_ia32_cvttss2si((v4sf_t){x, 0.0f, 0.0f, 0.0f}); }
static inline u32 strlen47(const u8 *p) { u32 n = 0; while (p[n]) n++; return n; }
static inline float halflen47(u32 n) {
  double d = (double)(s32)n + *(const double *)(0x680aa0 + (n >> 31) * 8);
  return (float)d;
}

static void THISCALL fn47b290(u8 *self, u8 *a0) {
  u8 F[0x4c];
  for (u32 i = 0; i < sizeof F; i++) F[i] = 0;
  *NU(0x48) = (u32)a0;
  typedef u32 (THISCALL * S1)(u8 *, u32);
  typedef u32 (THISCALL * S2)(u8 *, u32, u32);
  typedef u8 *(THISCALL * S0)(u8 *);
  typedef s32 (THISCALL * I0)(u8 *);
  typedef void (*Draw6)(u8 *, s32, s32, u32, u32, u32);
  typedef void (*Draw4)(u8 *, s32, s32, u32);
  if (!(G(float, 0x6ffa18) == 0.0f)) {  // @47b290_a
    u8 *P = *(u8 **)(self + 0x10);
    if (*(u32 *)(P + 0x1c) != 0) {
      u8 *Q = *(u8 **)(self + 8);
      if (*(u32 *)(Q + 0x3c) & 0x1000) {  // @47b290_b
        slot_pair_3a0_398(self, *(u8 **)self, NP(0x10));
        (*(S1 *)(*(u8 **)self + 0x84))(self, NP(0x10));
        *NF(0xc) = *NF(0xc) + G(float, 0x67da24);  // @47b290_c
        u8 *sys = (u8 *)G(u32, 0x70039c);
        u8 *T = *(u8 **)(sys + 0x9b);
        u8 *Y = (*(S0 *)(*(u8 **)T + 0x138))(T);
        *NU(0x28) = 0;
        (*(S2 *)(*(u8 **)Y + 0x88))(Y, 0x685a0c, NP(0x28));  // @47b290_d
        sys = (u8 *)G(u32, 0x70039c);
        T = *(u8 **)(sys + 0x9b);
        u8 *Z = (u8 *)(*(S1 *)(*(u8 **)T + 0x58))(T, *NU(0x28));  // @47b290_e
        (*(S1 *)(*(u8 **)Z + 0x8c))(Z, NP(0x10));
        if (*NF(8) > 0.0f) {  // @47b290_f
          (*(S1 *)(*(u8 **)Z + 0x240))(Z, NP(0x20));
          float x = *(float *)(Z + 0x58) * *NF(0x10);
          x = x / *NF(8);
          x = x + G(float, 0x67a6ac);
          x = x * *NF(0x18);  // @47b290_g
          x = x + *NF(0x20);
          *NF(0x30) = x;
          typedef double (THISCALL * D0)(u8 *);
          double sq = (*(D0 *)(*(u8 **)Z + 0x248))(Z);
          sys = (u8 *)G(u32, 0x70039c);
          u8 *U = *(u8 **)(sys + 0x190f);
          float a2 = *(float *)(Z + 0x58) * *NF(0xc);
          float y0h = *NF(0x1c) + *NF(0x14);
          a2 = a2 / *NF(8);
          float onem = G(float, 0x678858) - y0h;
          a2 = a2 * *(float *)(Z + 0x40);
          *NF(0x2c) = (float)((double)*NF(0x14) / sq);  // @47b290_h
          a2 = a2 - G(float, 0x67a6ac);
          a2 = a2 * *NF(0x2c);  // @47b290_i
          a2 = a2 + onem;
          *NF(0x2c) = a2;
          s32 W = (*(I0 *)(*(u8 **)U + 0xec))(U);
          *NF(0x44) = (float)ext_634da6_ceil((double)((float)W * *NF(0x30)));  // @47b290_j
          sys = (u8 *)G(u32, 0x70039c);
          U = *(u8 **)(sys + 0x190f);
          s32 H = (*(I0 *)(*(u8 **)U + 0xf0))(U);
          H = -H;
          *NF(0x40) = (float)ext_634da6_ceil((double)((float)H * *NF(0x2c)));  // @47b290_k
          u8 *R = *(u8 **)(*(u8 **)(self + 0x10) + 0x1c);
          u8 *nm = *(u8 **)(R + 4);
          if (nm) {
            u8 *so = (u8 *)G(u32, 0x7003a4);
            (*(u32(THISCALL **)(u8 *, u32, u32, u32))(*(u8 **)so + 0x9c))(so, *(u32 *)(nm + 4), NP(0x34), NP(0x30));  // @47b290_l
            u8 *str = (u8 *)*NU(0x30);
            float f1 = *NF(0x44), f2 = *NF(0x40);
            *NF(0x28) = f1;
            *NF(0x24) = f2;
            float hl = *str ? halflen47(strlen47(str)) : 0.0f;
            hl = hl * G(float, 0x67a6ac);  // @47b290_m
            float xx = f1 - hl;
            *NF(0x2c) = xx;
            if (xx >= 0.0f) {
              sys = (u8 *)G(u32, 0x70039c);
              U = *(u8 **)(sys + 0x190f);
              if ((float)(*(I0 *)(*(u8 **)U + 0xec))(U) > *NF(0x2c)) {  // @47b290_n
                if (f2 >= 0.0f) {
                  sys = (u8 *)G(u32, 0x70039c);
                  U = *(u8 **)(sys + 0x190f);
                  if ((float)(*(I0 *)(*(u8 **)U + 0xec))(U) > f2) {
                    u8 *so2 = (u8 *)G(u32, 0x70039c);
                    u8 *D = (*(S0 *)(*(u8 **)so2 + 0x190))(so2);
                    ((Draw6)(*(u32 *)(*(u8 **)D + 0x184)))(D, trunc47(*NF(0x2c)), trunc47(f2), 0x68aa08, *NU(0x30), *NU(0x34));  // @47b290_o
                  }
                }
              }
            }
          } else {
            *NF(0x24) = *NF(0x40);
            *NF(0x28) = *NF(0x44);
          }
          u8 *ebx = self + 0x412;
          u32 len = ext_4cc5f0(ebx);
          if (len != 0) {  // @47b290_p
            *NF(0x24) = *NF(0x24) - G(float, 0x678858);
            u8 *s2 = (u8 *)ext_4cc1d0(ebx);
            float hl2 = halflen47(strlen47(s2)) * G(float, 0x67a6ac);
            float x1 = *NF(0x28) - hl2;  // @47b290_q
            *NF(0x28) = x1;
            if (x1 >= 0.0f) {
              sys = (u8 *)G(u32, 0x70039c);
              U = *(u8 **)(sys + 0x190f);
              if ((float)(*(I0 *)(*(u8 **)U + 0xec))(U) > *NF(0x28)) {
                if (*NF(0x24) >= 0.0f) {
                  sys = (u8 *)G(u32, 0x70039c);
                  U = *(u8 **)(sys + 0x190f);
                  if ((float)(*(I0 *)(*(u8 **)U + 0xec))(U) > *NF(0x24)) {
                    u8 *so2 = (u8 *)G(u32, 0x70039c);
                    u8 *D = (*(S0 *)(*(u8 **)so2 + 0x190))(so2);
                    u8 *vtD = *(u8 **)D;
                    u8 *pp = (u8 *)ext_4cc1d0(ebx);
                    ((Draw4)(*(u32 *)(vtD + 0x184)))(D, trunc47(*NF(0x28)), trunc47(*NF(0x24)), (u32)pp);  // @47b290_r
                  }
                }
              }
            }
          }
          if (a0) {
            *NF(0x24) = *NF(0x24) - G(float, 0x678858);  // @47b290_s
            float hl3 = halflen47(strlen47(a0)) * G(float, 0x67a6ac);
            float x2 = *NF(0x28) - hl3;
            *NF(0x28) = x2;
            if (x2 >= 0.0f) {
              sys = (u8 *)G(u32, 0x70039c);
              U = *(u8 **)(sys + 0x190f);
              if ((float)(*(I0 *)(*(u8 **)U + 0xec))(U) > *NF(0x28)) {
                if (*NF(0x24) >= 0.0f) {
                  sys = (u8 *)G(u32, 0x70039c);
                  U = *(u8 **)(sys + 0x190f);
                  if ((float)(*(I0 *)(*(u8 **)U + 0xec))(U) > *NF(0x24)) {
                    u8 *so2 = (u8 *)G(u32, 0x70039c);
                    u8 *D = (*(S0 *)(*(u8 **)so2 + 0x190))(so2);
                    ((Draw4)(*(u32 *)(*(u8 **)D + 0x184)))(D, trunc47(*NF(0x28)), trunc47(*NF(0x24)), (u32)a0);  // @47b290_t
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ext_633654(0);
}
PCREG(47b290, fn47b290);

// ---------------------------------------------------------------------------------------------------------------
// 0x44ff60: thiscall(this), /GS, 0x11c byte esp-frame (B = esp after `and esp,-8; sub esp,0x11c`, body esp = B-12): per-frame update of a
// cloth / rope object: allocates a simulation slot (this[0x5c] slots of 0x10 bytes, this[0x7c] = current slot, slot[0] = vertex array A),
// copies the vertices, integrates (0x44ef80 / 0x44f0f0), relaxes the distance constraints (this[0x4c], 16 byte records {u16 a, u16 b, k, eps,
// rest}), re-pins vertices, runs the mode-1/2 collision queries (slot 0x38 of [[sys+0x1aa3]+0x1c], 0x44f8b0), copies the edge list and
// finally registers the slots with [sys+0x1aa3]. Helpers 0x4419f0 0x441a60 0x441940 0x441970 0x43e920 0x43e960 0x4de4f0 0x4de7a0 0x4e0d00 0x4e0d40
// (verified rows) run as real code; 0x44ef80 0x44f0f0 0x44f550 0x44f8b0 0x450fc0 0x4db9a0 (verified rows) are recorders in the spec.
extern "C" u32 THISCALL ext_44ef80(u8 *, u32, u32, u32, u32);
extern "C" u32 THISCALL ext_44f0f0(u8 *, u32, u32);
extern "C" u32 THISCALL ext_44f550(u8 *);
extern "C" u32 THISCALL ext_44f8b0(u8 *, u32, u32, u32);
extern "C" u32 THISCALL ext_450fc0(u8 *, u32, u32);
extern "C" u8 THISCALL ext_4db9a0(u8 *, u32);
extern "C" u32 FASTCALL ext_4de4f0_fc(u32, u32) __asm__("ext_4de4f0");
extern "C" u32 THISCALL ext_4de7a0(u8 *);
extern "C" u32 FASTCALL ext_43e960_fc(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_4e0d40_fc(u32, u32, u32) __asm__("ext_4e0d40");

#define CF(off) ((float *)(F + (off)))
#define CU(off) ((u32 *)(F + (off)))
#define CP(off) ((u32)(F + (off)))

static inline void log47(u8 *sysp, u32 line) {
  typedef u64 (THISCALL * L1c8)(u8 *, u32, u32);
  typedef u32 (THISCALL * L178)(u8 *, u32, u32, u32);
  if (!(*(float *)(sysp + 0x9c7) == 0.0f) && !(*(float *)(sysp + 0x9c3) == 0.0f)) {  // @44ff60_log
    u64 r = (*(L1c8 *)(*(u8 **)sysp + 0x1c8))(sysp, 0x67a7f8, line);
    u8 *s2 = (u8 *)G(u32, 0x70039c);
    (*(L178 *)(*(u8 **)s2 + (line == 0x259 ? 0x178 : 0x17c)))(s2, (u32)r, (u32)(r >> 32), 0x68133c);
  }
}

static void THISCALL fn44ff60(u8 *self) {
  u8 F[0x130];
  for (u32 i = 0; i < sizeof F; i++) F[i] = 0;
  typedef u32 (THISCALL * S1)(u8 *, u32);
  typedef u32 (THISCALL * S2)(u8 *, u32, u32);
  typedef u8 (THISCALL * B0)(u8 *);
  u8 *sys = (u8 *)G(u32, 0x70039c);
  u8 *T = *(u8 **)(sys + 0x9b);
  if ((*(B0 *)(*(u8 **)T + 0xb8))(T)) { ext_633654(0); return; }  // @44ff60_a
  (*(S2 *)(*(u8 **)self + 0x80))(self, CP(0xd0), CP(0x60));
  *CU(0x24) = 0; *CU(0x28) = 0xbf800000; *CU(0x2c) = 0;
  (*(S1 *)(*(u8 **)self + 0x90))(self, CP(0x24));  // @44ff60_b
  const float K0 = G(float, 0x6785e4);
  sys = (u8 *)G(u32, 0x70039c);
  bool search_done = false;
  if (*(u32 *)(self + 0x7c) == 0) {
    float tv = **(float **)(self + 0x9c) * G(float, 0x678620);  // @44ff60_c
    s32 tt = trunc47(tv);
    if (!(tt > *(s32 *)(sys + 0x44))) {
      for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) {
        u8 *sl = *(u8 **)(self + 0x5c) + 0x10 * i;
        u8 *eb = *(u8 **)(sl + 8);
        if (eb) {
          s32 t2 = trunc47(*(float *)(sl + 0xc) * G(float, 0x678620));  // @44ff60_d
          if (t2 < *(s32 *)(sys + 0x44)) {
            *(u32 *)(eb + 0x7c) = 0;
            *(u32 *)(*(u8 **)(self + 0x5c) + 0x10 * i + 8) = 0;
            sys = (u8 *)G(u32, 0x70039c);
          }
        }
      }
      **(float **)(self + 0x9c) = (float)*(s32 *)(sys + 0x40) * K0;  // @44ff60_e
      sys = (u8 *)G(u32, 0x70039c);
    }
    u32 n = *(u32 *)(self + 0x1c);
    if (n) {
      u8 *base = *(u8 **)(self + 0x5c);
      for (u32 idx = 0; idx < n; idx++) {
        if (*(u32 *)(base + 0x10 * idx + 8) == 0) {  // @44ff60_f
          u8 *slot = base + (idx << 4);
          *(u8 **)(self + 0x7c) = slot;
          *(u8 **)(slot + 8) = self;
          sys = (u8 *)G(u32, 0x70039c);
          *(float *)(*(u8 **)(self + 0x7c) + 0xc) = (float)*(s32 *)(sys + 0x40) * K0;
          ext_450fc0(self, idx, CP(0x24));  // @44ff60_g
          u8 *Q = *(u8 **)(self + 8);
          *(u32 *)(Q + 0x3c) = (*(u32 *)(Q + 0x3c) & 0xfeffffff) | 0x1000000;
          ext_633654(0);
          return;
        }
      }
    }
  }
  (void)search_done;
  u8 *S = *(u8 **)(self + 0x7c);
  if (!S) { ext_633654(0); return; }
  *(float *)(S + 0xc) = (float)*(s32 *)(sys + 0x40) * K0;  // @44ff60_h
  sys = (u8 *)G(u32, 0x70039c);
  log47(sys, 0x259);
  ext_4de7a0(F + 0xf4);
  u8 *O = *(u8 **)(self + 8);
  *CU(0xc) = *(u32 *)(O + 0x30); *CU(0x10) = *(u32 *)(O + 0x34); *CU(0x14) = *(u32 *)(O + 0x38);
  ext_4419f0_fc(CP(0xc), CP(0xd0));  // @44ff60_i
  ext_441940_fc(CP(0xc), CP(0x60));
  O = *(u8 **)(self + 8);
  u8 *esi = self + 0xb4;
  *CU(0x48) = *CU(0x4c) = *CU(0x50) = *(u32 *)(O + 0x4c);
  if (*(float *)esi == 0.0f && *(float *)(self + 0xb8) == 0.0f && *(float *)(self + 0xbc) == 0.0f) {  // @44ff60_j
    ((u32 *)esi)[0] = *CU(0xc); ((u32 *)esi)[1] = *CU(0x10); ((u32 *)esi)[2] = *CU(0x14);
  }
  ext_43e920_fc3(CP(0x18), CP(0xc), (u32)esi);
  ((u32 *)esi)[0] = *CU(0xc); ((u32 *)esi)[1] = *CU(0x10); ((u32 *)esi)[2] = *CU(0x14);
  ext_441a60_fc(CP(0x18), CP(0xd0));  // @44ff60_k
  float y2 = *CF(0x1c) * *CF(0x1c);
  float x2 = *CF(0x18) * *CF(0x18);
  x2 = x2 + y2;
  float z2 = *CF(0x20) * *CF(0x20);
  x2 = x2 + z2;
  u8 *A;
  if (x2 > G(float, 0x67ff1c)) {  // @44ff60_l
    u32 N = *(u32 *)(self + 0x44);
    *CU(0x18) = 0; *CU(0x1c) = 0; *CU(0x20) = 0;
    A = *(u8 **)(*(u8 **)(self + 0x7c));
    if (N != 0) {
      for (u32 i = 0; i < *(u32 *)(self + 0x44); i++) {
        const u32 *src = (const u32 *)(*(u8 **)(self + 0x58) + 12 * i);
        ((u32 *)A)[3 * i] = src[0]; ((u32 *)A)[3 * i + 1] = src[1]; ((u32 *)A)[3 * i + 2] = src[2];  // @44ff60_m
        const u32 *src2 = (const u32 *)(*(u8 **)(self + 0x58) + 12 * i);
        u32 d = 3 * (*(u32 *)(self + 0x44) + i);
        ((u32 *)A)[d] = src2[0]; ((u32 *)A)[d + 1] = src2[1]; ((u32 *)A)[d + 2] = src2[2];  // @44ff60_n
      }
    }
  } else {
    u32 sbits;
    if (x2 > G(float, 0x68137c)) {  // @44ff60_o
      double sq = ext_634d7c_dbl((double)x2);
      double q = G(double, 0x678610) / sq;
      float fq = (float)q;
      sbits = *(u32 *)&fq;
    } else {
      sbits = 0x3d888889;
    }
    ext_4e0d00(F + 0x18, sbits);  // @44ff60_p
    A = *(u8 **)(*(u8 **)(self + 0x7c));
  }
  if (*(u32 *)(self + 0x24) == 3) ext_4e0d40_fc((u32)(self + 0x28), CP(0x18), 0x3e000000);  // @44ff60_q
  A = *(u8 **)(*(u8 **)(self + 0x7c));
  if (*(u8 *)(self + 0xd0)) *(float *)(self + 0xcc) = G(float, *(u32 *)0x70039c + 0x48) + *(float *)(self + 0xcc);  // @44ff60_r
  else *(u32 *)(self + 0xcc) = 0x3c888889;
  const float K3 = G(float, 0x681378);
  if (*(float *)(self + 0xcc) >= K3) {  // @44ff60_s
    do {
      bool m3 = (*(u32 *)(self + 0x24) == 3);
      *(float *)(self + 0xcc) = *(float *)(self + 0xcc) - K3;  // @44ff60_t
      ext_44ef80(self, (u32)A, CP(0x24), m3 ? 0 : CP(0x18), 0x3d088889);  // @44ff60_u
      ext_44f0f0(self, (u32)A, 0x3d088889);  // @44ff60_v
      for (u32 k = 0; k < *(u32 *)(self + 0x18); k++) {
        const u8 *rec = *(u8 **)(self + 0x4c);
        for (u32 j = 0; j < *(u32 *)(self + 0x48); j++, rec += 0x10) {
          u32 a3 = 3u * *(u16 *)rec, b3 = 3u * *(u16 *)(rec + 2);
          float *pa = (float *)A + a3, *pb = (float *)A + b3;
          float dx = pb[0] - pa[0];  // @44ff60_w
          float dy = pb[1] - pa[1];
          float dz = pb[2] - pa[2];
          float kk = *(float *)(rec + 4);
          float l2 = dy * dy + dx * dx;  // @44ff60_x
          l2 = l2 + dz * dz;
          float r0 = *(float *)(rec + 0xc);
          l2 = l2 + *(float *)(rec + 8);
          float t = G(float, 0x678858) - r0 / l2;  // @44ff60_y
          t = t * *(float *)(self + 0x34);
          float kt = kk * t;  // @44ff60_z
          pa[0] = dx * kt + pa[0];
          pa[1] = dy * kt + pa[1];
          float zc = dz * kt;
          kt = kt - t;
          zc = zc + pa[2];
          dy = dy * kt; dz = dz * kt;
          pa[2] = zc;
          dy = dy + pb[1];
          dz = dz + pb[2];
          float xc = dx * kt;
          pb[1] = dy;
          xc = xc + pb[0];
          pb[2] = dz;
          pb[0] = xc;
        }
        const u32 *vs = (const u32 *)*(u8 **)(self + 0x58);
        const u32 *pins = (const u32 *)*(u8 **)(self + 0x64);
        for (u32 i = 0; i < *(u32 *)(self + 0x44); i++) {
          if (pins[i] == 0) { ((u32 *)A)[3 * i] = vs[3 * i]; ((u32 *)A)[3 * i + 1] = vs[3 * i + 1]; ((u32 *)A)[3 * i + 2] = vs[3 * i + 2]; }  // @44ff60_aa
        }
      }
      u32 mode = *(u32 *)(self + 0x20);
      if (mode == 2) {
        sys = (u8 *)G(u32, 0x70039c);
        u8 *W = *(u8 **)(sys + 0x1aa3);
        u8 *R = *(u8 **)(W + 0x1c);
        typedef u32 (THISCALL * Q10)(u8 *, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
        u32 n = (*(Q10 *)(*(u8 **)R + 0x38))(R, CP(0x6c), CP(0x7c), 0, CP(0xf4), CP(0xc), CP(0x48), 2, 0, 1, 1);  // @44ff60_ab
        (void)n;
        *CU(4) = n;
        for (u32 i = 0; i < n; i++) {
          u8 *ob = (u8 *)*CU(0x6c + 4 * i);
          if (ext_4db9a0(ob, 0x200002)) {  // @44ff60_ac
            u8 *sub = *(u8 **)(ob + 0x54);
            if (sub) {
              (*(S2 *)(*(u8 **)sub + 0x80))(sub, CP(0x7c), CP(0x30));
              (*(S2 *)(*(u8 **)self + 0x80))(self, CP(0xac), CP(0xa0));
              O = *(u8 **)(self + 8);
              float r = *(float *)(O + 0x4c) + G(float, 0x67da24);
              *CF(4) = r;
              ext_43e960_fc(CP(0x30), CP(0xa0));
              float dd = *CF(0x30) * *CF(0x30);
              dd = dd + 0.0f;
              float zz = *CF(0x38) * *CF(0x38);
              dd = dd + zz;
              float rr = r * r;
              *CF(0) = dd; *CF(4) = rr;
              if (!((s32)*CU(0) > (s32)*CU(4))) {  // @44ff60_ad
                ext_441a60_fc(CP(0x30), CP(0xac));
                ext_4de4f0_fc(CP(0x7c), CP(0xac));
                ext_44f8b0(self, CP(0x7c), CP(0x30), 0x41f00000);  // @44ff60_ae
              }
            }
          }
        }
      } else if (mode == 1) {
        u8 *E = *(u8 **)(self + 0x98);
        if (E) {
          (*(S2 *)(*(u8 **)E + 0x80))(E, CP(0xac), CP(0x3c));  // @44ff60_af
          (*(S2 *)(*(u8 **)self + 0x80))(self, CP(0x7c), CP(0x54));
          O = *(u8 **)(self + 8);
          float r = *(float *)(O + 0x4c) + G(float, 0x67da24);
          *CF(4) = r;
          ext_43e960_fc(CP(0x3c), CP(0x54));
          float dd = *CF(0x3c) * *CF(0x3c);
          dd = dd + 0.0f;
          float zz = *CF(0x44) * *CF(0x44);
          dd = dd + zz;
          float rr = r * r;
          *CF(0) = dd; *CF(4) = rr;
          if (!((s32)*CU(0) > (s32)*CU(4))) {  // @44ff60_ag
            ext_441a60_fc(CP(0x3c), CP(0x7c));
            ext_4de4f0_fc(CP(0xac), CP(0x7c));
            ext_44f8b0(self, CP(0xac), CP(0x3c), 0x41f00000);  // @44ff60_ah
          }
        }
      }
      ext_44f550(self);  // @44ff60_ai
      for (u32 e = 0; e < *(u32 *)(self + 0x54); e += 2) {
        const u16 *el = (const u16 *)*(u8 **)(self + 0x50);
        u32 a3 = 3u * el[e], b3 = 3u * el[e + 1];
        ((u32 *)A)[b3] = ((u32 *)A)[a3]; ((u32 *)A)[b3 + 1] = ((u32 *)A)[a3 + 1]; ((u32 *)A)[b3 + 2] = ((u32 *)A)[a3 + 2];  // @44ff60_aj
      }
    } while (*(float *)(self + 0xcc) >= K3);
  }
  {
    u8 *S1p = *(u8 **)(self + 0x7c);
    u32 hnd = *(u32 *)(S1p + 4);
    if (*(u32 *)(self + 0x40) != 0) {
      for (u32 b = 0; b < *(u32 *)(self + 0x40); b++) {
        sys = (u8 *)G(u32, 0x70039c);
        u8 *W = *(u8 **)(sys + 0x1aa3);
        u8 *lst = *(u8 **)(self + 0x68);
        u32 idx = *(u32 *)(lst + b * 8), val = *(u32 *)(lst + b * 8 + 4);
        u8 *C = *(u8 **)(W + 0x18);
        typedef u32 (THISCALL * C4)(u8 *, u32, u32, u32, u32);
        (*(C4 *)(*(u8 **)C + 0x70))(C, hnd, 1, (u32)(*(u8 **)(*(u8 **)(self + 0x7c)) + idx * 4), val);  // @44ff60_ak
        sys = (u8 *)G(u32, 0x70039c);
        W = *(u8 **)(sys + 0x1aa3);
        C = *(u8 **)(W + 0x18);
        hnd = (*(S2 *)(*(u8 **)C + 0x60))(C, hnd, 1);  // @44ff60_al
      }
    }
  }
  if (*(u32 *)(self + 0x90) != 0) {
    for (u32 i = 0; i < *(u32 *)(self + 0x88); i++) {
      u32 ix = 3u * ((const u16 *)*(u8 **)(self + 0x8c))[i];
      ext_441970_fc3(CP(0x54), (u32)(A + ix * 4), CP(0xd0));  // @44ff60_am
      ext_441940_fc(CP(0x54), CP(0x60));
      ext_4de7a0(F + 0x7c);
    }
  }
  {
    u8 *Q = *(u8 **)(self + 8);
    *(u32 *)(Q + 0x3c) = (*(u32 *)(Q + 0x3c) & 0xfeffffff) | 0x1000000;  // @44ff60_an
  }
  sys = (u8 *)G(u32, 0x70039c);
  log47(sys, 0x260);
  ext_633654(0);
}
PCREG(44ff60, fn44ff60);

// ---------------------------------------------------------------------------------------------------------------
// 0x599040: thiscall(this), /GS, ebp frame 0x30 (922 insns): per-frame update of the HUD / UI controller. (1) while this[0x22e3] (a float)
// is > 0: 28 text messages are looked up in the string table (T = [[0x70039c]+0x9b] slot 0x114, six stack args, returns ax) and shown by
// the widget this[0x1d0b] (slot 0x128): the first, a ladder on the float (> 4.5 / 3.5 / 2.5 / 1.5 / 0.5) and 21 unconditional ones; the float
// is then cleared. (2) profiling log call (sys slots 0x1c8 -> u64 -> 0x178), (3) UI object this[0x1d0f] refreshes (0x5a58a0 0x5a5f40 0x5eac90),
// widget reset, 0x59a8f0, a walk of this[0x1da2..0x1da6], a ref-table walk (this[0x5c] slots 0x4c / 0x5c / 0x44, 0x5b7d40 on item+0xc/0x10/0x14),
// two id lists (this[0x1dae].. count [0x1fae]; this[0xe6].. count [0x2e6]) classified through 0x59ffc0 with two six-way jump tables (values > 5
// go to the assert handler [0x7003b0], int3 when null), counters feeding 0x5a5f00, camera / HUD helpers, markers (0x5a57a0) for this[0x50f..]
// and the manager list [0x7003b8]+0x8b8.., the effect timers this[0x1fce..] (count [0x22c2], eleven-way jump table) and a final log call.
// All callees are verified rows and recorders in the spec (0x4daf90 / 0x633910 run as real code).
extern "C" u32 THISCALL ext_5a58a0(u8 *);
extern "C" u32 THISCALL ext_5a5f40(u8 *);
extern "C" u32 THISCALL ext_5eac90(u8 *);
extern "C" u32 THISCALL ext_59a8f0(u8 *);
extern "C" u8 THISCALL ext_5b7d40(u8 *, u32);
extern "C" u32 THISCALL ext_597e00(u8 *, u32);
extern "C" u32 THISCALL ext_59ffc0(u8 *);
extern "C" u32 THISCALL ext_5a5f00(u8 *, u32);
extern "C" u32 THISCALL ext_5e0df0(u8 *);
extern "C" u32 THISCALL ext_5b0220(u8 *);
extern "C" u32 THISCALL ext_5ea960(u8 *);
extern "C" u32 THISCALL ext_5ea870(u8 *, u32);
extern "C" u32 THISCALL ext_4690b0(u8 *);
extern "C" u32 THISCALL ext_5a5e90(u8 *, u32);
extern "C" u32 THISCALL ext_5a57a0(u8 *, u32, u32, u32, u32);
extern "C" u32 THISCALL ext_5aaaf0(u8 *);
extern "C" u32 THISCALL ext_5aab10(u8 *, u32);

#define HF(off) ((float *)(F + 0x30 - (off)))
#define HU(off) ((u32 *)(F + 0x30 - (off)))
#define HP(off) ((u32)(F + 0x30 - (off)))

static inline void msg599040(u8 *self, u32 a0, u32 line, u32 s4) {
  typedef u32 (THISCALL * M6)(u8 *, u32, u32, u32, u32, u32, u32);
  typedef u32 (THISCALL * M1)(u8 *, u32);
  u8 *W = *(u8 **)(self + 0x1d0b);
  u8 *vtW = *(u8 **)W;
  u8 *sys = (u8 *)G(u32, 0x70039c);
  u8 *T = *(u8 **)(sys + 0x9b);
  u32 ax = (u16)(*(M6 *)(*(u8 **)T + 0x114))(T, a0, 0, 0x6ad784, line, s4, 0);  // @599040_m
  (*(M1 *)(vtW + 0x128))(*(u8 **)(self + 0x1d0b), ax);  // @599040_n
}

static inline void log599040(u8 *sysp, u32 line, u32 slot) {
  typedef u64 (THISCALL * L1c8)(u8 *, u32, u32);
  typedef u32 (THISCALL * L17)(u8 *, u32, u32, u32);
  if (!(*(float *)(sysp + 0x9c7) == 0.0f) && !(*(float *)(sysp + 0x9c3) == 0.0f)) {  // @599040_log
    u64 r = (*(L1c8 *)(*(u8 **)sysp + 0x1c8))(sysp, 0x67a7f8, line);
    u8 *s2 = (u8 *)G(u32, 0x70039c);
    (*(L17 *)(*(u8 **)s2 + slot))(s2, (u32)r, (u32)(r >> 32), 0x6ad590);
  }
}

static inline void assert599040() {
  typedef void (*H)();
  H h = G(H, 0x7003b0);
  if (h) h(); else __builtin_trap();
}

static void THISCALL fn599040(u8 *self) {
  u8 F[0x34];
  for (u32 i = 0; i < sizeof F; i++) F[i] = 0xa5;   // the exe leaves the frame uninitialised: poison it so a read of an unset local shows up
  typedef u32 (THISCALL * S1)(u8 *, u32);
  typedef u8 (THISCALL * B0)(u8 *);
  typedef u8 *(THISCALL * P1)(u8 *, u32);
  u8 *sys;
  float f22 = *(float *)(self + 0x22e3);  // @599040_a
  if (f22 > 0.0f && *(u8 **)(self + 0x1d0b) != 0) {
    msg599040(self, 0x690a14, 0x270, 0);
    f22 = *(float *)(self + 0x22e3);
    if (f22 > G(float, 0x6ad9e0)) {  // @599040_b
      msg599040(self, 0x690ac0, 0x275, 0x6ad838);
      msg599040(self, 0x690ac0, 0x276, 0x6ad84c);
    } else if (f22 > G(float, 0x6ad9dc)) {
      msg599040(self, 0x690ac0, 0x27a, 0x6ac9a0);
      msg599040(self, 0x690ac0, 0x27b, 0x6ad84c);
    } else if (f22 > G(float, 0x680a64)) {
      msg599040(self, 0x690ac0, 0x27f, 0x6ad858);
      msg599040(self, 0x690ac0, 0x280, 0x6ad84c);
    } else if (f22 > G(float, 0x680a5c)) {
      msg599040(self, 0x690ac0, 0x284, 0x6ad870);
      msg599040(self, 0x690ac0, 0x285, 0x6ad884);
    } else if (f22 > G(float, 0x67a6ac)) {
      msg599040(self, 0x690ac0, 0x289, 0x6ad894);
      msg599040(self, 0x690ac0, 0x28a, 0x6ad884);
    }
    static const u16 L1[] = {0x28e, 0x28f, 0x290, 0x291};
    for (int i = 0; i < 4; i++) msg599040(self, 0x690ac0, L1[i], 0x690aec);  // @599040_c
    static const u16 L2[] = {0x292, 0x293, 0x294, 0x295};
    for (int i = 0; i < 4; i++) msg599040(self, 0x690ac0, L2[i], 0x690af4);
    static const u16 L3[] = {0x296, 0x297, 0x298};
    for (int i = 0; i < 3; i++) msg599040(self, 0x690ac0, L3[i], 0x6ad8a0);
    for (u32 ln = 0x299; ln <= 0x2a0; ln++) msg599040(self, 0x690ac0, ln, 0x6acb04);  // @599040_d
    msg599040(self, 0x690ac0, 0x2a1, 0x6ad8a8);
    msg599040(self, 0x690ac0, 0x2a2, 0x6ad8b4);
    *(u32 *)(self + 0x22e3) = 0;  // @599040_e
  }
  sys = (u8 *)G(u32, 0x70039c);
  log599040(sys, 0x259, 0x178);
  u8 *U = *(u8 **)(self + 0x1d0f);
  if (U) {
    ext_5a58a0(U);
    ext_5a5f40(*(u8 **)(self + 0x1d0f));  // @599040_f
    ext_5eac90(*(u8 **)(self + 0x22d7));
  }
  if (*(u32 *)(self + 0x1d0b) != 0) {
    u32 *v = (u32 *)(self + 0x1d50);
    v[0] = 0; v[1] = 0; v[2] = 0;
    u8 *W = *(u8 **)(self + 0x1d0b);
    (*(S1 *)(*(u8 **)W + 0x84))(W, (u32)v);  // @599040_g
  }
  ext_59a8f0(self);
  {
    u8 **it = *(u8 ***)(self + 0x1da2), **end = *(u8 ***)(self + 0x1da6);
    while (it != end) {  // @599040_h
      u8 *e = *(u8 **)(*(u8 **)it + 4);
      it = (*(u32 *)(e + 0x54) == 0) ? it : it + 1;
    }
  }
  u8 *X = *(u8 **)(self + 0x5c);
  if (X) {
    (*(S1 *)(*(u8 **)X + 0x4c))(X, HP(0x30));  // @599040_i
    X = *(u8 **)(self + 0x5c);
    u8 *item = (*(P1 *)(*(u8 **)X + 0x5c))(X, HP(0x30));
    if (*HU(0x30) != 0) {
      do {
        U = *(u8 **)(self + 0x1d0f);
        if (!ext_5b7d40(*(u8 **)(item + 0xc), (u32)U) && !ext_5b7d40(*(u8 **)(item + 0x10), (u32)U) && !ext_5b7d40(*(u8 **)(item + 0x14), (u32)U)) {  // @599040_j
          X = *(u8 **)(self + 0x5c);
          (*(S1 *)(*(u8 **)X + 0x44))(X, HP(0x30));
        }
        X = *(u8 **)(self + 0x5c);
        item = (*(P1 *)(*(u8 **)X + 0x5c))(X, HP(0x30));
      } while (*HU(0x30) != 0);
    }
  }
  u32 c0 = 0, c1 = 0, c2 = 0, c3 = 0;
  *HU(0x24) = 0; *HU(0x20) = 0; *HU(0x1c) = 0; *HU(0x18) = 0; *HU(0x14) = 0;
  if (*(u32 *)(self + 0x1fae) != 0) {
    u32 *idp = (u32 *)(self + 0x1dae);
    u32 i = 0;
    do {
      sys = (u8 *)G(u32, 0x70039c);
      u8 *T = *(u8 **)(sys + 0x9b);
      u8 *obj = (u8 *)(*(S1 *)(*(u8 **)T + 0x58))(T, *idp);  // @599040_k
      if ((*(B0 *)(*(u8 **)obj + 0x438))(obj)) {  // @599040_l
        ext_597e00(self, *idp);
      } else {
        u32 k = ext_59ffc0(obj);
        if (k > 5) assert599040();
        else switch (k) { case 1: c2++; break; case 2: c0++; break; case 3: c1++; break; case 5: c3++; break; default: break; }  // @599040_o
        k = ext_59ffc0(obj);
        U = *(u8 **)(self + 0x1d0f);
        if (k > 5) assert599040();
        else switch (k) { case 1: ext_5a5f00(U, 1); break; case 2: ext_5a5f00(U, 0); break; case 3: ext_5a5f00(U, 2); break; case 5: ext_5a5f00(U, 4); break; default: break; }  // @599040_p
      }
      i++; idp++;
    } while (i < *(u32 *)(self + 0x1fae));
  }
  {
    s32 b = 0;
    if ((s32)*(u32 *)(self + 0x2e6) > b) {  // @599040_q
      u32 *sp = (u32 *)(self + 0xe6);
      do {
        sys = (u8 *)G(u32, 0x70039c);
        u8 *T = *(u8 **)(sys + 0x9b);
        u8 *obj = (u8 *)(*(S1 *)(*(u8 **)T + 0x58))(T, *sp);
        if ((*(B0 *)(*(u8 **)obj + 0x438))(obj)) {
          ext_597e00(self, *sp);
          *(u32 *)(self + 0x2e6) = *(u32 *)(self + 0x2e6) - 1;  // @599040_r
          *sp = *(u32 *)(self + *(u32 *)(self + 0x2e6) * 4 + 0xe6);
          *(u32 *)(self + *(u32 *)(self + 0x2e6) * 4 + 0xe6) = 0;
          if (*(u32 *)(self + 0x2ea) == *(u32 *)(self + 0x2e6)) *(u32 *)(self + 0x2ea) = 0;  // @599040_s
        }
        b++; sp++;
      } while (b < (s32)*(u32 *)(self + 0x2e6));
    }
  }
  if (*(u32 *)(self + 0x1d0f) != 0) {
    u32 n = *(u32 *)(self + 0x1fba) - c3 - c2 - c1 - c0;  // @599040_t
    if (n != 0) {
      u32 i = 0;
      do {
        ext_5a5f00(*(u8 **)(self + 0x1d0f), 3);
        n = *(u32 *)(self + 0x1fba) - c3 - c2 - c1 - c0;
        i++;
      } while (i < n);
    }
  }
  if (*(u8 *)(self + 0x1d4f) != 0 && *(u32 *)(self + 0x4f3) != 0) {  // @599040_u
    ext_5e0df0(self);
    ext_5b0220(self);
    ext_5ea960(self);
    ext_5ea870(self, *(u32 *)(self + 0x1d13));
  }
  ext_4690b0(self);
  U = *(u8 **)(self + 0x1d0f);
  if (U) ext_5a5e90(U, *(u32 *)(self + 0x1fb6));  // @599040_v
  if (*(u32 *)(self + 0x1d0f) != 0) {
    u32 cnt = *(u32 *)(self + 0x1cff);
    if (cnt != 0) {
      u8 *sp = self + 0x50f;
      for (u32 b = 0; b < *(u32 *)(self + 0x1cff); b++, sp += 0x18) {
        ext_5a57a0(*(u8 **)(self + 0x1d0f), (u32)(sp - 0x10), *(u32 *)(sp - 4), *(u32 *)sp, *(u32 *)(sp + 4));  // @599040_w
      }
    }
    sys = (u8 *)G(u32, 0x70039c);
    if (*(u32 *)(sys + 0x1b5d) == 1) {  // @599040_x
      u8 *M = (u8 *)G(u32, 0x7003b8);
      u32 *bp = (u32 *)(M + 0x8b8);
      u32 *endp = (u32 *)(M + (*(u32 *)(M + 0x8b4) + 0x22e) * 4);
      while (bp != endp) {
        u8 *esi = (u8 *)*bp;
        *HU(8) = 0; *HU(0xc) = 0; *HU(0x10) = 0;
        ext_4daf90(*(u8 **)(esi + 8), HP(0x10));  // @599040_y
        (*(S1 *)(*(u8 **)esi + 0x84))(esi, HP(0x10));
        *HF(0xc) = *HF(0xc) + G(float, 0x680a84);  // @599040_z
        ext_5a57a0(*(u8 **)(self + 0x1d0f), HP(0x10), 0xb, 0x3fc00000, 0x80ffffff);  // @599040_aa
        M = (u8 *)G(u32, 0x7003b8);
        bp++;
        endp = (u32 *)(M + (*(u32 *)(M + 0x8b4) + 0x22e) * 4);
      }
    }
  }
  {
    u32 K = *(u32 *)(self + 0x22c2);
    *(u32 *)(self + 0x1cff) = 0;
    if (K != 0 && *(u32 *)(self + 0x1d0f) != 0) {
      u32 i = 0;
      u32 id = 0;
      u8 *sp = self + 0x1fce;
      do {
        u32 ev = *(u32 *)(sp + 8);
        if (ev > 10) id = 0;
        else switch (ev) { case 0: case 4: case 9: id = 0xc; break; case 1: break; case 2: case 3: case 5: case 6: case 7: case 10: id = 7; break; default: id = 0; break; }  // @599040_ab
        sys = (u8 *)G(u32, 0x70039c);
        float fv = G(float, (u32)sys + 0x48) * G(float, 0x680a84);
        fv = fv + *(float *)sp;
        *(float *)sp = fv;
        float fr = *(float *)(sp - 8) / *(float *)(sp - 0xc);  // @599040_ac
        fr = fr * G(float, 0x68af18);
        u32 al = (u32)ext_633910_i((v4sf_t){fr, 0.0f, 0.0f, 0.0f});
        if (al > 0xff) al = 0xff;  // @599040_ad
        u32 color = (al << 24) | 0xffffff;
        ext_5a57a0(*(u8 **)(self + 0x1d0f), (u32)(sp - 4), id, 0x3f800000, color);  // @599040_ae
        sys = (u8 *)G(u32, 0x70039c);
        float tt = *(float *)(sp - 8) - G(float, (u32)sys + 0x48);
        i++;
        *(float *)(sp - 8) = tt;
        sp += 0x18;
      } while (i < *(u32 *)(self + 0x22c2));
      u32 cnt2 = *(u32 *)(self + 0x22c2);
      if (cnt2 != 0) {
        u8 *cp = self + 0x1fc2;
        u32 j = 0;
        do {
          if (0.0f > *(float *)(cp + 4)) {  // @599040_af
            u32 k3 = cnt2 * 3;
            __builtin_memmove(cp, self + k3 * 8 + 0x1faa, 16);
            __builtin_memmove(cp + 0x10, self + k3 * 8 + 0x1fba, 8);
            *(u32 *)(self + 0x22c2) = *(u32 *)(self + 0x22c2) - 1;
          }
          cnt2 = *(u32 *)(self + 0x22c2);
          j++; cp += 0x18;
        } while (j < cnt2);
      }
    }
  }
  U = *(u8 **)(self + 0x1d0f);
  if (U) {
    ext_5aaaf0(U);
    if (*(u8 *)(self + 0x22ce) != 0) ext_5aab10(*(u8 **)(self + 0x1d0f), *(u32 *)(self + 0x22cf));  // @599040_ag
  }
  sys = (u8 *)G(u32, 0x70039c);
  log599040(sys, 0x260, 0x17c);
  ext_633654(0);
}
PCREG(599040, fn599040);
