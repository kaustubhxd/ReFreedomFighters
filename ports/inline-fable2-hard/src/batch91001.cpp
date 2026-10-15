// batch91001.cpp - hard-function trial (fable 2), batch 91001: 0x552b50 script binding (446 insns, 74 calls), stdcall(ctx) ret 4.
// ctx[4] = input argument list, ctx[8] = output argument list; a variant is {u32 value; u8 type} (8 bytes): type 0 = unset, 1 = int, 2 = float.
// Reads three ints, resets 12 outputs, then if the data table [0x7003b8]->0x2c1d exists and 0x5873a0(a0, a1, a2) finds an entry (>= 0),
// fills the outputs from that 72-byte entry.
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void (*cdecl3_t)(void *, u32, u32);
typedef u32 (*hook_t)(void);

extern "C" u8 *THISCALL ext_5003d0(void *list, u32 idx);        // ret 4 (verified unclaimed-64): &variant idx (real code runs)
extern "C" u8 *THISCALL ext_5002f0(void *var, u32 v);           // ret 4 (verified unclaimed-64): set int (real code runs)
extern "C" void THISCALL ext_602cd0(void *var, u32 *p);         // ret 4 (verified casc-h3): set float from *p (real code runs)
extern "C" s32 STDCALL ext_5873a0(u32 a0, u32 a1, u32 a2);      // ret 0xc (verified inline-ai, hooked): entry index or < 0

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// logger [0x700390]->slot 0x20(file, line) -> log object; log->slot 0x2c is cdecl (log, "RAISE_EXCEPTION %s", "NO! WRONG TYPE"), caller pops 12.
static inline void raise_wrong_type(u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)lg)[0x20 / 4](lg, 0x69c8e0u, line);
  cdecl3_t fn = *(cdecl3_t *)(*(u8 **)lo + 0x2c);
  fn(lo, 0x69c6b0u, 0x69c938u);
  hook_t h = G(hook_t, 0x7003b0);
  if (h) h(); else asm volatile("int3");
}
static inline void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (h) h(); else asm volatile("int3");
}
static inline u32 getint(u8 *in, u32 idx) {   // variant must be unset or int
  u8 *v = ext_5003d0(in, idx);
  u8 t = v[4];
  if (t != 0 && t != 1) raise_wrong_type(0x104);
  return rd(v);
}
static inline void setf(u8 *out, u32 idx, u32 bits) {   // inline float store: variant must be unset or float
  u8 *v = ext_5003d0(out, idx);
  u8 t = v[4];
  if (t != 0 && t != 2) raise_wrong_type(0x104);
  v[4] = 2;
  wr(v, bits);
}
static inline void seti(u8 *out, u32 idx, u32 val) { ext_5002f0(ext_5003d0(out, idx), val); }
static inline void setv(u8 *out, u32 idx, u8 *p) { ext_602cd0(ext_5003d0(out, idx), (u32 *)p); }

static void STDCALL fn552b50(u8 *ctx) {
  u8 *in = *(u8 **)(ctx + 4);
  u8 *out = *(u8 **)(ctx + 8);
  u32 a0 = getint(in, 0);
  u32 a1 = getint(in, 1);
  u32 a2 = getint(in, 2);
  setf(out, 0, 0);
  setf(out, 1, 0);
  setf(out, 2, 0);
  seti(out, 3, 0xffffffffu);
  seti(out, 4, 0);
  seti(out, 5, 0);
  seti(out, 6, 0);
  setf(out, 7, 0);
  setf(out, 8, 0);
  setf(out, 9, 0);
  seti(out, 10, 0);
  setf(out, 11, 0x3f800000u);   // 1.0f
  u8 *g = G(u8 *, 0x7003b8);
  u8 *tab = *(u8 **)(g + 0x2c1d);
  if (!tab) return;
  s32 idx = ext_5873a0(a0, a1, a2);
  if (idx < 0) return;
  g = G(u8 *, 0x7003b8);
  tab = *(u8 **)(g + 0x2c1d);
  u8 *base = *(u8 **)(tab + 0x5f);
  u8 *ent = base + (u32)idx * 72;
  setv(out, 0, ent + 0x10);
  setv(out, 1, ent + 0x14);
  setv(out, 2, ent + 0x18);
  seti(out, 3, (u32)idx);
  u32 flags = rd(ent + 0x34);
  u32 kind;
  if (flags & 1) kind = 0;
  else if (flags & 2) kind = 1;
  else if (flags & 4) kind = 2;
  else { assert_hook(); kind = 0; }
  seti(out, 4, kind);
  seti(out, 5, (flags >> 3) & 1);
  seti(out, 6, (flags >> 4) & 1);
  setv(out, 7, ent + 0x28);
  setv(out, 8, ent + 0x2c);
  setv(out, 9, ent + 0x30);
  g = G(u8 *, 0x7003b8);
  seti(out, 10, rd(g + 0x2c25));
}
PCREG(552b50, fn552b50);
