#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_4db500(void *obj, float *vec);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline s32 cvtt(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

typedef u32(THISCALL *V3)(void *, u32, u32, u32);

// 0x572be0: thiscall() with no defined return value, /GS protected: pushes the state of this (a UI element, this+0x44 its widget) into the engine table object T = [[0x70039c]+0x9b]:
// reports the widget's text (T slot 0x4c(this[0x44], 0x10) and the named string of this, found like 0x41e680 does, through slot 0x60 of T's slot 0x138 object: called with 2 and with 3 arguments, so the two calls
// reach different callees (the epilogue pops registers before restoring esp: every call is callee-cleaned)), reads the widget size with 0x4db500 into a vector, scales its x by [0x67a6ac] when the flag at this+0x87e is set and (the object [G+0x190f] has +0x81 set
// or the T slot 0x134 object's slot 0x90(0x67d9dc, &flag) sets the flag), stores x as int at this+0x868, moves y to ([G+0x73] - [G+0x73] / [0x6a688c] * y) rounded to int, positions the widget
// (slot 0x70), shows it (slot 0xbc(1)), resets this+0x50 / +0x86c, looks up the sibling T slot 0x58([this+0x87a]) into this+0x876 and positions it (y and x + [0x680a60]) and shows it, +0x872 = 0.
extern "C" void THISCALL fn_572be0(u8 *self) {
  float vec[3];
  u8 flag;
  void *S1 = (void *)(*(V0 *)(vt(*(void **)(G(u8 *, 0x70039c) + 0x9b)) + 0x138))(*(void **)(G(u8 *, 0x70039c) + 0x9b));
  u32 f60 = *(u32 *)(vt(S1) + 0x60);
  {
    void *T = *(void **)(G(u8 *, 0x70039c) + 0x9b);
    u32 n = (*(V2 *)(vt(T) + 0x4c))(T, rd32u(self + 0x44), 0x10);
    (*(V2 *)&f60)(S1, 0x6a8a74, n);
  }
  void *T2 = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  void *S2 = (void *)(*(V0 *)(vt(T2) + 0x138))(T2);
  u8 *E = G(u8 *, 0x70038c);
  u32 name;
  if ((*(V1 *)(vt(E) + 0x20))(E, (u32)self)) {
    name = 0;
  } else {
    E = G(u8 *, 0x70038c);
    u32 cb = rd32u(E + 8);
    if (cb && rd32u(E + 0xc) <= (u32)self && (u32)self < rd32u(E + 0x10)) {
      name = (*(V0 *)&cb)(self);
    } else {
      if (rd32u(self - 4) == 0) (*(V1 *)(vt(E) + 0xac))(E, (u32)self);
      name = rd32u(self - 4);
    }
  }
  (*(V3 *)(vt(S2) + 0x60))(S2, 0x6a8a80, name, 4);
  ext_4db500((void *)rd32u((u8 *)rd32u(self + 0x44) + 8), vec);
  float x = vec[0];
  bool scale = false;
  if (self[0x87e]) {
    u8 *G2 = G(u8 *, 0x70039c);
    u8 *px = (u8 *)rd32u(G2 + 0x190f);
    if (px && px[0x81]) {
      scale = true;
    } else {
      void *Tt = *(void **)(G2 + 0x9b);
      void *X = (void *)(*(V0 *)(vt(Tt) + 0x134))(Tt);
      flag = 0;
      (*(V2 *)(vt(X) + 0x90))(X, 0x67d9dc, (u32)&flag);
      if (flag) scale = true;
    }
  }
  if (scale) {
    x = x * G(float, 0x67a6ac);
    vec[0] = x;
  }
  wr32u(self + 0x868, (u32)cvtt(x));
  void *w = (void *)rd32u(self + 0x44);
  float cur = (float)(s32)rd32u(G(u8 *, 0x70039c) + 0x73);
  vec[2] = 0.0f;
  float t = cur / G(float, 0x6a688c);
  t = t * vec[1];
  cur = cur - t;
  vec[1] = (float)cvtt(cur);
  (*(V1 *)(vt(w) + 0x70))(w, (u32)vec);
  w = (void *)rd32u(self + 0x44);
  (*(V1 *)(vt(w) + 0xbc))(w, 1);
  wr32u(self + 0x50, 0);
  self[0x86c] = 0;
  self[0x86d] = 0;
  {
    void *Tn = *(void **)(G(u8 *, 0x70039c) + 0x9b);
    void *Y = (void *)(*(V1 *)(vt(Tn) + 0x58))(Tn, rd32u(self + 0x87a));
    wr32u(self + 0x876, (u32)Y);
    if (Y) {
      vec[1] = vec[1] + G(float, 0x680a60);
      vec[0] = vec[0] + G(float, 0x680a60);
      (*(V1 *)(vt(Y) + 0x70))(Y, (u32)vec);
      Y = (void *)rd32u(self + 0x876);
      (*(V1 *)(vt(Y) + 0xbc))(Y, 1);
    }
  }
  wr32u(self + 0x872, 0);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(572be0, fn_572be0);
