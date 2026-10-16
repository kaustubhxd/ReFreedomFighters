#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);
typedef u32(THISCALL *V4)(void *, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_589b50(void *self, void *out);
extern "C" u32 THISCALL ext_59d370(void *entry);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *kdraw() { return (u8 *)rd32u((u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b) + 0xadc); }

// draws (dt > 0) / updates / frees (dt <= 0) the debug line with handle h from prev to cur through the draw object K = [[0x70039c]+0x9b]->[0xadc]:
// no handle: h = K.slot 0x218(prev, cur, color) is stored in *hp; handle: K.slot 0x21c(h, prev, cur, color); dt <= 0 with a handle: K.slot 0x220(h), *hp = 0.
static inline void line_update(float dt, u8 *hp, float *prev, float *cur, u32 color) {
  u32 h = rd32u(hp);
  u8 *K = kdraw();
  if (dt > 0.0f) {
    if (h == 0) {
      u32 nh = (*(V3 *)(vt(K) + 0x218))(K, (u32)prev, (u32)cur, color);
      wr32u(hp, nh);
    } else {
      (*(V4 *)(vt(K) + 0x21c))(K, h, (u32)prev, (u32)cur, color);
    }
  } else if (h != 0) {
    (*(V1 *)(vt(K) + 0x220))(K, h);
    wr32u(hp, 0);
  }
}

// 0x58a680: thiscall(float dt) ret 4, /GS protected, void. this[0] = n1 and this+4 holds n1 object pointers; this+0x80 + 4*i are the line handles of the first array; this[0x38] = n2
// and this+0x3c holds n2 entries (pointers to {object, ...}); this+0xb4 + 4*j are the handles of the second array. First array: each object's slot 0x84(&V) with V = (0, 0, 0) gives a point,
// V.y += [0x67cd40]; for i > 0 a line prev -> V (colour 0xffff00) is drawn/updated/freed by line_update; prev = V. Then entries for which 0x59d370(entry) is nonzero are removed
// (the last entry replaces them and n2 shrinks), 0x589b50(this, &W) gives a base point and every remaining entry's object slot 0x80(&Q, &V) yields V, line_update draws W -> V (colour 0xff0000).
extern "C" void THISCALL fn_58a680(u8 *self, float dt) {
  float V[3], Pv[3], W[3], Q[9];
  u8 *ebx = self + 4;
  if (ebx != self + (rd32u(self) + 1) * 4) {
    do {
      u8 *obj = (u8 *)rd32u(ebx);
      V[0] = V[1] = V[2] = 0.0f;
      (*(V1 *)(vt(obj) + 0x84))(obj, (u32)V);
      V[1] = V[1] + G(float, 0x67cd40);
      if (ebx != self + 4) {
        u32 i = (u32)(ebx - self - 4) >> 2;
        line_update(dt, self + 0x80 + i * 4, Pv, V, 0xffff00);
      }
      __builtin_memcpy(Pv, V, 12);
      ebx += 4;
    } while (ebx != self + (rd32u(self) + 1) * 4);
  }
  u8 *edi = self + 0x3c;
  if (edi != self + (rd32u(self + 0x38) + 0xf) * 4) {
    do {
      if ((u8)ext_59d370((void *)rd32u(edi)) != 0) {
        u32 last = rd32u(self + rd32u(self + 0x38) * 4 + 0x38);
        wr32u(edi, last);
        wr32u(self + 0x38, rd32u(self + 0x38) - 1);
      } else {
        edi += 4;
      }
    } while (edi != self + (rd32u(self + 0x38) + 0xf) * 4);
  }
  ext_589b50(self, W);
  ebx = self + 0x3c;
  if (ebx != self + (rd32u(self + 0x38) + 0xf) * 4) {
    u32 off = (u32)(ebx - self - 0x3c);
    do {
      u8 *entry = (u8 *)rd32u(ebx);
      u8 *O = (u8 *)rd32u(entry);
      (*(V2 *)(vt(O) + 0x80))(O, (u32)Q, (u32)V);
      u32 j = off >> 2;
      line_update(dt, self + 0xb4 + j * 4, W, V, 0xff0000);
      ebx += 4;
      off += 4;
    } while (ebx != self + (rd32u(self + 0x38) + 0xf) * 4);
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(58a680, fn_58a680);
