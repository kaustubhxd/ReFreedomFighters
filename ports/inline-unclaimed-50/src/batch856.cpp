// batch856.cpp - area 50 (residue-9 candidate): 0x558150 [114 instr, thiscall, one stack arg (a record pointer), ret 4; no
// name in the map (GUESS "resolve a random table entry of the record and call its pair of methods")].
// The record's sub-object (+4) gives a key through the accessor 0x5003d0 (stood in); the key is looked up in the engine's
// manager (vt +0x58) to an object B whose +0x18 object gives a count N (vt +0x14). A random index in [0, N) (rand, through
// the import slot at 0x67644c) selects an entry through the object's vt +0x30; the manager resolves that to an object Q,
// which fills two local arrays (vt +0x80) and is tested with vt +0x1e0 (flag 0x2000e1); 0x55eae0 (stood in) is then run,
// and this+0x1c's vt +0x370 gets both arrays. If the manager finds nothing, the exe logs (line 0x361) and prints the entry
// of this+0x1c. The exe's cookie check and the stack frame are not reproduced.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_5003d0(void *obj, u32 idx);                   // accessor (stood in by the harness)
extern "C" void THISCALL ext_55eae0(void *self, void *q, void *a, void *b); // pair call (stood in by the harness)

// 0x558150 (name GUESS).
static void THISCALL Fn558150(u8 *self, u8 *a) {
  if (*(u32 *)ext_5003d0(FP(a, 4), 0) == 0) return;
  u32 key = *(u32 *)ext_5003d0(FP(a, 4), 0);
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u8 *b = vcall<u8 *>(mgr, 0x58, key);
  if (!b) return;
  if (!vcall<u32>(FP(b, 0x18), 0x14)) return;
  u32 n = vcall<u32>(FP(b, 0x18), 0x14);
  s32 r = ((s32(*)(void))G(u32, 0x67644c))();            // rand (import slot)
  s32 rem = r % (s32)n;
  u32 k = vcall<u32>(FP(b, 0x18), 0x30, (u32)rem);
  u8 *q = vcall<u8 *>(mgr, 0x58, k);
  if (q) {
    float v34[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    float v10[3] = {0, 0, 0};
    vcall<void>(q, 0x80, v34, v10);
    if (vcall<u8>(q, 0x1e0, 0x2000e1u)) ext_55eae0(self, q, v34, v10);
    vcall<void>(FP(self, 0x1c), 0x370, v34, v10);
    return;
  }
  // not found: report through the engine logger (file 0x6a5eb0, line 0x361), then the entry of this+0x1c
  u8 *logger = G(u8 *, 0x700390);
  u8 *sink = vcall<u8 *>(logger, 0x20, (u32)0x6a5eb0, 0x361u);
  u8 *ent = vcall<u8 *>(FP(self, 0x1c), 0x20);
  typedef void (*printf_t)(void *, const char *, u32);
  (*(printf_t *)(*(u8 **)sink + 0x30))(sink, (const char *)0x69d10c, U32(ent, 4));
}
PCREG(558150, Fn558150);
