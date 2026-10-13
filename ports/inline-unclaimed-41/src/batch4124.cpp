// batch4124.cpp - unclaimed-41 batch 24 (slice 13): 0x645490 ZBoneModifyBase::AttachBaseGeomToBone(const ZBaseGeom*, unsigned int,
// const float*, const float*). Thiscall, four stack arguments (g, bone, a3, a4), ret 0x10, returns al.
// SEH frame not reproduced (the fs:[0] push and pop around the body are not modelled, so fs:[0] writes are not compared).
#include "ff.h"

extern "C" u32 THISCALL ext_4da2f0(u8 *self, u8 *a1, u32 a2);     // ecx = g; two stack arguments, callee pops (checksum stub, GUESS)
extern "C" u32 THISCALL ext_4cc1d0(u8 *self);                      // ecx = R3, no arguments (stub, GUESS)
extern "C" void THISCALL ext_4cbec0(u8 *self);                     // ecx = &Lc8, no arguments (stub, GUESS)
extern "C" void FASTCALL ext_4de420(u32 *c, u32 d);                // ecx = &buf[2], edx = a3 (writer stub, GUESS)
extern "C" void THISCALL ext_4de7a0(u32 *c);                       // ecx = &buf[2], no arguments (writer stub, GUESS)
extern "C" void THISCALL ext_63d7d0(u8 *self);                     // ecx = result of p.vt[0x20], no arguments (stub, GUESS)

typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

// 0x645490: self = ecx (the bone table at +0x69 (count) and +0x6d (56-byte entries)).
static u8 THISCALL fn645490(u8 *self, u8 *g, u32 bone, u8 *a3, float *a4) {
  if (*(u32 *)(self + 0x69) >= 8)
    return 0;

  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u32 E = ((f1_t)vslot(o, 0x50))(o, (u32)g);

  u32 cnt = *(u32 *)(self + 0x69);
  for (u32 i = 0; i < cnt; i++) {
    u8 *ent = self + 0x6d + 0x38 * i;
    if (*(u32 *)(ent + 4) == bone && *(u32 *)ent == E) {
      // duplicate: error path, returns true
      u8 *L = G(u8 *, 0x700390);
      u8 *o2 = (u8 *)((f2_t)vslot(L, 0x20))(L, 0x6c2904u, 0x2e1u);
      u32 Lc8[16];
      u32 R3 = ext_4da2f0(g, (u8 *)Lc8, 1u);
      u32 R4 = ext_4cc1d0((u8 *)R3);
      u32 fn2c = *(u32 *)(*(u8 **)o2 + 0x2c);
      u8 *tmp = (u8 *)R3;
      // ecx = R3, then o2, 0x6c29d0, R4 pushed; the caller pops 12 (cdecl-style call through the vtable slot)
      asm volatile("pushl %[r4]\n\tpushl $0x6c29d0\n\tpushl %[o2]\n\tcall *%[fn]\n\taddl $12, %%esp"
                   : "+c"(tmp)
                   : [r4] "r"(R4), [o2] "r"(o2), [fn] "r"(fn2c)
                   : "eax", "edx", "memory", "cc");
      ext_4cbec0((u8 *)Lc8);
      return 1;
    }
  }

  // new entry: buf[0] = E, buf[1] = bone, buf[2..10] written by the call below (L40), buf[11..13] = a4 (or zeros)
  u32 buf[14];
  buf[0] = E;
  buf[1] = bone;
  if (a3 != 0)
    ext_4de420(&buf[2], (u32)a3);
  else
    ext_4de7a0(&buf[2]);
  if (a4 != 0) {
    *(float *)&buf[11] = a4[0];
    *(float *)&buf[12] = a4[1];
    *(float *)&buf[13] = a4[2];
  } else {
    buf[11] = 0;
    buf[12] = 0;
    buf[13] = 0;
  }

  if (*(u32 *)(self + 0x69) + 1 > 8) {
    void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
    if (hook != 0)
      hook();
  }

  u32 idx = *(u32 *)(self + 0x69);
  u8 *ent = self + 0x6d + 0x38 * idx;
  for (u32 k = 0; k < 14; k++)
    *(u32 *)(ent + 4 * k) = buf[k];
  *(u32 *)(self + 0x69) = idx + 1;

  u8 *rm2 = G(u8 *, 0x70039c);
  u8 *p = *(u8 **)(rm2 + 0x190f);
  u32 R5 = ((f1_t)vslot(p, 0x20))(p, (u32)g);   // one stack argument (g), callee pops
  ext_63d7d0((u8 *)R5);
  return 1;
}
PCREG(645490, fn645490);
