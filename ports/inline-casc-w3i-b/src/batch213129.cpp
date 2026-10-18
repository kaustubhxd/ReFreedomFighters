#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V6)(void *, u32, u32, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_431410(void *c, u32 s, u32 v);
extern "C" void THISCALL ext_4314c0(void *c, u32 s, u32 fbits);
extern "C" void THISCALL ext_431580(void *c, u32 s, u32 v);
extern "C" u32 THISCALL ext_48aad0(void *pair);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *eng() { return G(u8 *, 0x70039c); }
static inline u8 *tab() { return (u8 *)rd32u(eng() + 0x9b); }
static inline u32 tbl(u32 base, u32 b) { return *(u32 *)(base + b * 4); }
static inline u32 bits(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

static inline u32 fmt_d(u32 fn, u32 ecx_, u32 P, u32 buf, u32 fmt, double d) {
  u32 r;
  __asm__ volatile("subl $8,%%esp; movsd %[d],(%%esp); pushl %[fmt]; pushl %[buf]; pushl %[P]; call *%%eax; addl $20,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [d] "x"(d), [fmt] "r"(fmt), [buf] "r"(buf), [P] "r"(P) : "edx", "memory", "cc");
  return r;
}
static inline u32 fmt_i(u32 fn, u32 ecx_, u32 P, u32 buf, u32 fmt, u32 v) {
  u32 r;
  __asm__ volatile("pushl %[v]; pushl %[fmt]; pushl %[buf]; pushl %[P]; call *%%eax; addl $16,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [v] "r"(v), [fmt] "r"(fmt), [buf] "r"(buf), [P] "r"(P) : "edx", "memory", "cc");
  return r;
}

// 0x57b0d0: stdcall(id, value) ret 8 option/setting change handler, always returns al = 0. R = object-table entry for id (slot 0x58); its kind (R slot 0x310, 1..12) selects one of
// twelve handlers (jump table 0x57b5d8): each updates a console variable (0x431410 / 0x4314c0 / 0x431580 or console slots 0x64 / 0x68 / 0x6c), an engine field, the UI object
// [eng+0x190f] (slots 0x1d0 / 0x1cc) and the entry's label text (R slot 0x378) from image string tables indexed by the value.
extern "C" u32 STDCALL fn_57b0d0(u32 id, u32 b) {
  u8 buf[0x20];
  u8 *T = tab();
  u8 *R = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, id);
  u8 *E = eng();
  u8 *U = (u8 *)rd32u(E + 0x190f);
  u8 *C = (u8 *)(*(V0 *)(vt(E) + 0xbc))(E);
  u32 kind = (*(V0 *)(vt(R) + 0x310))(R);
  if (rd32u(R + 0x70) == 0x20) goto done;
  kind -= 1;
  if (kind > 0xb) goto done;
  if (kind == 0) {
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6ecc74, b));
    u32 v = 3 - b;
    ext_431410(C, 0x678398, v);
    wr32u(eng() + 0x93, v);
  } else if (kind == 1) {
    u32 val;
    if (b >= 1) {
      (*(V1 *)(vt(C) + 0x6c))(C, 0x6aa2d8);
      val = 1;
    } else {
      (*(V2 *)(vt(C) + 0x64))(C, 0x6aa2d8, 1);
      val = 0;
    }
    (*(V2 *)(vt(U) + 0x1d0))(U, 8, val);
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6eccc4, b));
  } else if (kind == 2) {
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6eccd0, b));
    float f = *(float *)(0x6aa1cc + b * 4);
    ext_4314c0(C, 0x6922d4, bits(f));
    u32 pair[2];
    pair[0] = (*(V0 *)(vt(tab()) + 0x138))(tab());
    pair[1] = 0x685a0c;
    u32 nid = ext_48aad0(pair);
    T = tab();
    u8 *Q = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, nid);
    if (Q == 0) goto done;
    u8 *qv = vt(Q);
    u8 *K = tab();
    u32 h = (*(V6 *)(vt(K) + 0x114))(K, 0x69c594, 0, 0x6aa2f4, 0x12d, 0, 0);
    (*(V1 *)(qv + 0x128))(Q, (u16)h);
  } else if (kind == 3) {
    wr32u(eng() + 0x97, b);
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6ecc78, b));
    ext_431410(C, 0x678240, b);
  } else if (kind == 4) {
    wr32u(eng() + 0x8f, b);
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6ecc78, b));
    ext_431410(C, 0x678358, b);
  } else if (kind == 5) {
    float f = (float)(double)(u32)b;
    f = f / G(float, 0x67cd40);
    u8 *P = (u8 *)(*(V0 *)(vt(eng()) + 0x190))(eng());
    fmt_d(rd32u(vt(P) + 0x198), rd32u(P), (u32)P, (u32)buf, 0x6aa320, (double)f);
    (*(V1 *)(vt(R) + 0x378))(R, (u32)buf);
    ext_4314c0(C, 0x683724, bits(f));
  } else if (kind == 6) {
    if (b == 0) {
      (*(V1 *)(vt(R) + 0x378))(R, G(u32, 0x6eccbc));
      (*(V2 *)(vt(U) + 0x1d0))(U, 2, 0);
      ext_431410(C, 0x6aa32c, 0);
    } else {
      u32 st[2];
      (*(V1 *)(vt(U) + 0x1cc))(U, (u32)st);
      u32 mask = st[1];
      u32 n = 1;
      u32 edx = 2;
      for (;;) {
        if (b == 0) break;
        u32 nb = b - 1;
        n++;
        if ((mask & edx) == 0) nb = b;
        b = nb;
        edx += edx;
        if (edx == 0) break;
      }
      u8 *P = (u8 *)(*(V0 *)(vt(eng()) + 0x190))(eng());
      fmt_i(rd32u(vt(P) + 0x198), rd32u(P), (u32)P, (u32)buf, 0x6aa328, n);
      (*(V1 *)(vt(R) + 0x378))(R, (u32)buf);
      (*(V2 *)(vt(U) + 0x1d0))(U, 2, n);
      ext_431410(C, 0x6aa32c, n);
    }
  } else if (kind == 7) {
    u32 val;
    if (b != 0) {
      (*(V2 *)(vt(C) + 0x68))(C, 0x6aa338, 0x679e54);
      val = 1;
    } else {
      (*(V1 *)(vt(C) + 0x6c))(C, 0x6aa338);
      val = 0;
    }
    (*(V2 *)(vt(U) + 0x1d0))(U, 3, val);
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6eccbc, b));
  } else if (kind == 8) {
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6eccbc, b));
    ext_431410(C, 0x6aa1dc, b);
  } else if (kind == 9) {
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6eccbc, b));
    if (b != 0) {
      (*(V1 *)(vt(C) + 0x6c))(C, 0x679c7c);
      eng()[0x68] = 1;
    } else {
      ext_431410(C, 0x679c7c, 1);
      eng()[0x68] = 0;
    }
  } else if (kind == 10) {
    (*(V1 *)(vt(R) + 0x378))(R, tbl(0x6eccbc, b));
    if (b != 0) {
      ext_431580(C, 0x6aa344, 0);
      (*(V2 *)(vt(U) + 0x1d0))(U, 7, b);
    } else {
      (*(V1 *)(vt(C) + 0x6c))(C, 0x6aa344);
      (*(V2 *)(vt(U) + 0x1d0))(U, 7, b);
    }
  } else {
    float f1 = (float)(double)(u32)b;
    float m = f1 * G(float, 0x67da00);
    float v = m;
    if (G(float, 0x67a284) > m) v = 0.1f;
    else if (m > G(float, 0x680a70)) v = 10.0f;
    u8 *P = (u8 *)(*(V0 *)(vt(eng()) + 0x190))(eng());
    fmt_d(rd32u(vt(P) + 0x198), rd32u(P), (u32)P, (u32)buf, 0x6aa320, (double)v);
    (*(V1 *)(vt(R) + 0x378))(R, (u32)buf);
    float inv = G(float, 0x678858) / v;
    (*(V2 *)(vt(U) + 0x1d0))(U, 6, (u32)&inv);
    ext_4314c0(C, 0x6aa1e8, bits(inv));
  }
done:
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(57b0d0, fn_57b0d0);
