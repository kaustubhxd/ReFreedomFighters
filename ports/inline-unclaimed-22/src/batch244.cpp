// batch244.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch244"). Names from the GameCube
// name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 index);   // original, script argument getter (ret 4)
extern "C" u8 *ext_41e290(u32 size);                       // original operator new (cdecl)
extern "C" u8 *THISCALL ext_49f670(u8 *self);              // original CActionEvaluator ctor (ret), returns this

typedef void(__attribute__((cdecl)) * logf1_t)(void *, const char *, u32);

// The _CIfmod thunk 0x634dc4: st1 = d, st0 = 1.0; leaves fmod(d, 1.0) in st0 (one pop). Stored as a float.
// Same helper as inline-unclaimed-65 batch6518.
static float fmodOne(double d) {
  float out;
  asm volatile("fldl %[d]\n\t"
               "fld1\n\t"
               "call *%[t]\n\t"
               "fstps %[o]\n\t"
               : [o] "=m"(out)
               : [d] "m"(d), [t] "r"(0x634dc4)
               : "eax", "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)", "cc");
  return out;
}

// 0x477740 ZActor::ActivateBaseMove(unsigned int id, bool force) ret 8, returns al.
// Same id and not force: true, nothing changes. Otherwise +0x654 = old id, +0x650 = id, r = vt[0x5a8](id) ({offset, flags});
// none: +0x658 = id, false. The anim header is engine db->[+0x44] + offset (offset 0: address 0). Then
// +0x759 = ((float)h[+0x64] + 1.0f - (float)h[+0x60]) / (float)h[+0x6c], +0x769 = (float)h[+0x5c] / (float)h[+0x6c]
// (ints, signed); flags bit 3: +0x755 = fmod(+0x755, 1.0) through the _CIfmod thunk, else 0; vt[0x268](h, h[+0x7c]); true.
static bool THISCALL activateBaseMove_477740(u8 *self, u32 id, bool force) {
  u32 cur = *(u32 *)(self + 0x650);
  if (cur == id && !force) return true;
  *(u32 *)(self + 0x654) = cur;
  *(u32 *)(self + 0x650) = id;
  u32 *r = (u32 *)vcall<u32>(self, 0x5a8, id);
  if (!r) {
    *(u32 *)(self + 0x658) = id;
    return false;
  }
  u32 off = r[0];
  u32 flags = r[1];
  u8 *h = 0;
  if (off) {
    u8 *rm = *(u8 **)0x70039cu;
    h = *(u8 **)(*(u8 **)(rm + 0x9b) + 0x44) + off;
  }
  float a = (float)*(s32 *)(h + 0x64) + 1.0f;   // 1.0f read from 0x678858
  a = a - (float)*(s32 *)(h + 0x60);
  *(float *)(self + 0x759) = a / (float)*(s32 *)(h + 0x6c);
  *(float *)(self + 0x769) = (float)*(s32 *)(h + 0x5c) / (float)*(s32 *)(h + 0x6c);
  if (flags & 8)
    *(float *)(self + 0x755) = fmodOne((double)*(float *)(self + 0x755));
  else
    *(u32 *)(self + 0x755) = 0;
  vcall<void>(self, 0x268, (u32)h, *(u32 *)(h + 0x7c));
  return true;
}
PCREG(477740, activateBaseMove_477740);

// 0x5063d0 ZActorIf::BeamActorToRef(OpaqueCallParameters_t&) ret 4 (this unused). actor = engine db->vt[0x58](*arg0),
// target = engine db->vt[0x58](*arg1) (args from 0x5003d0 on params->[+4]). With a target: target->vt[0x80](&m, &pos)
// fills a 0x24-byte block and a 12-byte position on the stack; actor->vt[0x370](&m, &pos). Without: logs "WARNING: Error in
// BeamActorToRef() for %s: Target geom is NULL" (actor_if.cpp line 0x21f) with actor->vt[0x20]()->[+4], through slot 0x30
// of the log object. Stack cookie (0x6f5630 / 0x633654) not reproduced.
static void THISCALL beamActorToRef_5063d0(u8 *self, u8 *params) {
  (void)self;
  u8 *a0 = ext_5003d0(*(u8 **)(params + 4), 0);
  u8 *rm = *(u8 **)0x70039cu;
  u8 *actor = (u8 *)vcall<u32>(*(u8 **)(rm + 0x9b), 0x58, *(u32 *)a0);
  u8 *a1 = ext_5003d0(*(u8 **)(params + 4), 1);
  rm = *(u8 **)0x70039cu;
  u8 *target = (u8 *)vcall<u32>(*(u8 **)(rm + 0x9b), 0x58, *(u32 *)a1);
  if (target) {
    u8 m[0x24];
    u8 pos[0xc];
    vcall<void>(target, 0x80, (u32)m, (u32)pos);
    vcall<void>(actor, 0x370, (u32)m, (u32)pos);
    return;
  }
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x69cff0u, 0x21fu);
  u8 *nm = (u8 *)vcall<u32>(actor, 0x20);
  (*(logf1_t *)(*(u8 **)log + 0x30))(log, (const char *)0x69d148u, *(u32 *)(nm + 4));
}
PCREG(5063d0, beamActorToRef_5063d0);

// 0x49fa80 CActionController::AddEvaluator(unsigned int id) ret 4. Count +0x48 (signed) at 4 or more: logs "Warning: Trying
// to add more than %d action evaluators" (action.cpp line 0x2e7) with 4. Else e = new 0x844 bytes (0x41e290), constructed
// by 0x49f670 when not null; slot +0x5c[count] = e; e+4 gets the 0x800 bytes at +0x70; e+0x804 the 0x40 bytes at +0x870;
// e[0] = id; count + 1. SEH frame (fs:[0], for the new/ctor unwind) and cookie not reproduced.
static void THISCALL addEvaluator_49fa80(u8 *self, u32 id) {
  s32 *count = (s32 *)(self + 0x48);
  if (*count >= 4) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x68f6b4u, 0x2e7u);
    (*(logf1_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x68f7b0u, 4u);
    return;
  }
  u8 *mem = ext_41e290(0x844);
  u8 *e = mem ? ext_49f670(mem) : 0;
  u8 **slots = (u8 **)(self + 0x5c);
  slots[*count] = e;
  u8 *dst = slots[*count];
  u32 *d = (u32 *)(dst + 4);
  const u32 *s = (const u32 *)(self + 0x70);
  for (u32 i = 0; i < 0x200; i++) d[i] = s[i];
  u32 *d2 = (u32 *)(dst + 0x804);
  const u32 *s2 = (const u32 *)(self + 0x870);
  for (u32 i = 0; i < 0x10; i++) d2[i] = s2[i];
  *(u32 *)slots[*count] = id;
  *count = *count + 1;
}
PCREG(49fa80, addEvaluator_49fa80);
