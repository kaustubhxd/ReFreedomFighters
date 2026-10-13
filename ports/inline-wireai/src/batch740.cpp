// batch740.cpp - ZMatPosAnim::Init() (0x4a5930) [high], residue 11 slice (2026-10-12).
// Tag 0x4b455953 to the object at +0x44 (slot 0x4c) gives R. ZRunMatPosAnim::Create (+0x48) gets (R, frame, byte +0xc4,
// float +0xc7), frame = engine +0x40. mreset(+0x6b). If byte +0xc6: slot 0x80(+0x6b, +0x5f), then slot 0x20 object's slot 0x94
// (+0x6b, +0x5f), Run(frame, P, V, -1) with P = [ebp-0x34] (9 floats), V = [ebp-0x10] (3), vmmul(V, +0x93), 0x43e960(+0x5f, V),
// 0x4de4f0(+0x6b, P). Then SetFrameStart(+0xcc) if set, SetFrameEnd(+0xd0) if set. If byte +0xc5: Run again, V += +0x5f,
// slot 0x74(P, V). If byte +0xcb is clear: byte +0x92 = 1, slot 0x68(0x10, 0) on this, byte +0xbf = 0. Then obj44 slot 0x40,
// (+0x44)->+0x10 gets |= 2, RegisterMessages, and if byte +0x92 is clear: obj44 slot 0x3c(1) and slot 0x68(0x10, 0).
// The x87 result of Run is discarded (fstp st(0)). Create/Run/SetFrame*/RegisterMessages/0x43e960/0x4de4f0 are exe calls.
#include "ff.h"

struct Run;   // ZRunMatPosAnim (opaque; the object lives at this+0x48)

extern "C" void THISCALL ext_4e7880(void *run, void *R, u32 frame, u32 b, float f);   // ZRunMatPosAnim::Create
extern "C" float THISCALL ext_4e7930(void *run, u32 frame, float *P, float *V, float m1);   // ZRunMatPosAnim::Run (st0)
extern "C" void THISCALL ext_4e7ce0(void *run, u32 v);                                 // ZRunMatPosAnim::SetFrameStart
extern "C" void THISCALL ext_4e7c50(void *run, u32 v);                                 // ZRunMatPosAnim::SetFrameEnd
extern "C" void THISCALL ext_4de7a0(void *m);                                          // mreset
extern "C" void FASTCALL ext_4419f0(float *V, const float *a);                         // vmmul
extern "C" void FASTCALL ext_441940(float *v, const float *b);                         // PSVECAdd
extern "C" void FASTCALL ext_43e960(void *a, const float *b);                          // unknown helper
extern "C" void FASTCALL ext_4de4f0(void *a, const float *b);                          // unknown helper
extern "C" void THISCALL ext_4a5c20(void *self);                                       // ZMatPosAnim::RegisterMessages

// 0x4a5930 ZMatPosAnim::Init() [high].
static void THISCALL matpos_Init(u8 *self) {
  void *obj44 = *(void **)(self + 0x44);
  void *R = vcall<void *>(obj44, 0x4c, 0x4b455953u);
  float fl = *(float *)(self + 0xc7);
  u32 frame = *(u32 *)(*(u8 **)0x70039c + 0x40);
  u32 b = self[0xc4];
  ext_4e7880(self + 0x48, R, frame, b, fl);
  ext_4de7a0(self + 0x6b);

  float P[9];
  float V[3];
  if (self[0xc6]) {
    obj44 = *(void **)(self + 0x44);
    vcall<void>(obj44, 0x80, self + 0x6b, self + 0x5f);
    void *o = vcall<void *>(*(void **)(self + 0x44), 0x20);
    vcall<void>(o, 0x94, self + 0x6b, self + 0x5f);
    ext_4e7930(self + 0x48, *(u32 *)(*(u8 **)0x70039c + 0x40), P, V, bitsf(0xbf800000u));
    ext_4419f0(V, (float *)(self + 0x93));
    ext_43e960(self + 0x5f, V);
    ext_4de4f0(self + 0x6b, P);
  }
  u32 cc = *(u32 *)(self + 0xcc);
  if (cc)
    ext_4e7ce0(self + 0x48, cc);
  u32 d0 = *(u32 *)(self + 0xd0);
  if (d0)
    ext_4e7c50(self + 0x48, d0);
  if (self[0xc5]) {
    ext_4e7930(self + 0x48, *(u32 *)(*(u8 **)0x70039c + 0x40), P, V, bitsf(0xbf800000u));
    ext_441940(V, (float *)(self + 0x5f));
    vcall<void>(*(void **)(self + 0x44), 0x74, P, V);
  }
  if (!self[0xcb]) {
    self[0x92] = 1;
    vcall<void>(self, 0x68, 0x10u, 0u);
    self[0xbf] = 0;
  }
  vcall<void>(*(void **)(self + 0x44), 0x40);
  u8 *sub = *(u8 **)(*(u8 **)(self + 0x44) + 0x10);
  *(u32 *)(sub + 0x18) |= 2;
  ext_4a5c20(self);
  if (!self[0x92]) {
    vcall<void>(*(void **)(self + 0x44), 0x3c, 1u);
    vcall<void>(self, 0x68, 0x10u, 0u);
  }
}
PCREG(4a5930, matpos_Init);
