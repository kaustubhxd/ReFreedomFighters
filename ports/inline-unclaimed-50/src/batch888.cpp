// batch888.cpp - area 50 (residue-09 candidate table row): 0x558b50 [54 instr, thiscall (ECX unused), one stack arg (a record),
// ret 4, void; GUESS "Query558b50": read three floats from the record's object (accessor 0x5003d0 with index 2, 1, 0), build a
// vector V = (x, y, z) from them, run the helper 0x4de7a0 on a local object L (ECX only; stood in), then call the manager's
// vt+0x238 with (L, V, W = (10, 10, 10), 0x7f7f8f, 0). The exe's stack cookie check is not reproduced.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_5003d0(void *obj, u32 idx);            // accessor (stood in by the harness)
extern "C" void THISCALL ext_4de7a0(void *local);                  // helper on the local object (stood in)

// 0x558b50 (name GUESS).
static void THISCALL Query558b50(void *unused, u8 *rec) {
  (void)unused;
  u8 *pa = ext_5003d0(FP(rec, 4), 2);
  u8 *pb = ext_5003d0(FP(rec, 4), 1);
  u8 *pc = ext_5003d0(FP(rec, 4), 0);
  float V[3];
  V[0] = F32(pc, 0);
  V[1] = F32(pb, 0);
  V[2] = F32(pa, 0);
  u8 L[0x40];
  ext_4de7a0(L);
  float W[3] = {10.0f, 10.0f, 10.0f};
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u8 *M = (u8 *)FP(mgr, 0xadc);
  vcall<void>(M, 0x238, (void *)L, (void *)V, (void *)W, 0x7f7f8fu, 0u);
}
PCREG(558b50, Query558b50);
