#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u32 ftobits(u32 v) {
  float f = (float)(double)v;
  u32 b;
  __builtin_memcpy(&b, &f, 4);
  return b;
}

// 0x570040: thiscall(a, b, c) ret 0xc, no result, /GS protected: places up to three text entries (a, b, c; zero ones are skipped) in a column. Nothing happens when this[0x1a3] is set.
// Each entry takes the next widget of the pool this+0x1cc (index this[0x230] below the limit this[0x22c], the index is advanced even when the pool slot is empty) and, for a widget,
// lays it out at (x, float(unsigned(this[0x234] * 20 + 0x1c)), 0) with x = 0 / 300.0f / 520.0f for a / b / c: slot 0x260(1 for a, 2 otherwise), slot 0x70(&pos), slot 0xbc(0) and
// slot 0x284(entry value). Finally this[0x234]++ and the cursor object this[0x1c4] (when it exists) gets slot 0x70(&(0, float(unsigned(this[0x234] * 20 + 20)), 0)).
static inline void place(u8 *self, u32 value, u32 x, u32 arg260) {
  u32 idx = rd32u(self + 0x230);
  if (idx >= rd32u(self + 0x22c)) return;
  u8 *w = (u8 *)rd32u(self + 0x1cc + idx * 4);
  wr32u(self + 0x230, idx + 1);
  if (!w) return;
  u32 pos[3];
  pos[2] = 0;
  pos[0] = x;
  pos[1] = ftobits(rd32u(self + 0x234) * 20 + 0x1c);
  (*(V1 *)(vt(w) + 0x260))(w, arg260);
  (*(V1 *)(vt(w) + 0x70))(w, (u32)pos);
  (*(V1 *)(vt(w) + 0xbc))(w, 0);
  (*(V1 *)(vt(w) + 0x284))(w, value);
}

extern "C" void THISCALL fn_570040(u8 *self, u32 a, u32 b, u32 c) {
  if (self[0x1a3]) {
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  if (a) place(self, a, 0, 1);
  if (b) place(self, b, 0x43960000, 2);
  if (c) place(self, c, 0x44020000, 2);
  wr32u(self + 0x234, rd32u(self + 0x234) + 1);
  u8 *P = (u8 *)rd32u(self + 0x1c4);
  u32 pos2[3];
  pos2[0] = 0;
  pos2[2] = 0;
  pos2[1] = ftobits((rd32u(self + 0x234) * 5 + 5) << 2);
  if (P) (*(V1 *)(vt(P) + 0x70))(P, (u32)pos2);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(570040, fn_570040);
