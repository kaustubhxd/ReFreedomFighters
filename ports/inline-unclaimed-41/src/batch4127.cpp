// batch4127.cpp - unclaimed-41 batch 27 (slice 13): 0x5aa710 ZOnScreenDisplay::MapIconSetupIcons() (thiscall, no arguments, ret 0, void).
// One file. The loop runs over the count at this+0x69d. For element i: E0 = *(this+0x4cc+4i) (a pointer), idx = *(this+0x7c1+4i) (a
// 13-way switch), P = this+0x6a5+12i (a float triple), a byte at this+0x881+i selects the scaled path. The default case of the
// switch (idx > 12) calls the hook when it is set and leaves ebx unset in the exe; the port leaves it null and the spec keeps idx in 0..12.
// The /GS cookie check is not reproduced.
#include "ff.h"

extern "C" u8 *THISCALL ext_5a8360(u8 *self, u32 c);             // ecx = this, one stack argument; returns an object (GUESS)
extern "C" void THISCALL ext_446320(u8 *self, float *out, float *in);   // ecx = dv; two stack arguments; writes out[0..1] (GUESS)
extern "C" void THISCALL ext_5ec660(u8 *self, u32 a1);           // ecx = E0, one stack argument (stub, GUESS)
extern "C" void THISCALL ext_5ebd80(u8 *self, u32 a1);           // ecx = E0, one stack argument (stub, GUESS)
extern "C" void THISCALL ext_5ed1e0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);   // ecx = E0, five stack arguments (stub, GUESS)

typedef void(THISCALL * v1_t)(u8 *, u32);

static const u32 kCase[13] = {0x6b0114u, 0x6b006cu, 0x6b0124u, 0x6b0138u, 0x6b0144u, 0x6b0158u, 0x6b0168u,
                              0x6b0178u, 0x6b0188u, 0x6b0194u, 0x6b01a0u, 0x6b01acu, 0x6b01bcu};

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static void THISCALL fn5aa710(u8 *self) {
  if (*(u32 *)(self + 0x69d) != 0) {
    for (u32 i = 0; i < *(u32 *)(self + 0x69d); i++) {   // the count is re-read each iteration, as the exe does
      u8 *E0 = *(u8 **)(self + 0x4cc + 4 * i);
      u32 idx = *(u32 *)(self + 0x7c1 + 4 * i);
      u8 *P = self + 0x6a5 + 12 * i;

      // the switch: ebx = the result of the case call (idx > 12 is not generated; see the header)
      u8 *B = 0;
      if (idx <= 12) {
        B = ext_5a8360(self, kCase[idx]);
      } else {
        void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
        if (hook != 0)
          hook();
      }

      float x0;
      float x1;
      if (*(u8 *)(self + 0x881 + i) != 0) {
        u8 *dv = *(u8 **)(self + 0x89a);
        float out[2] = {0.0f, 0.0f};
        if (dv != 0) {
          float L1c[3] = {*(float *)(P - 4), *(float *)P, *(float *)(P + 4)};
          ((v1_t)vslot(dv, 0x8c))(dv, (u32)L1c);
          ext_446320(dv, out, L1c);
        }
        u8 *rmv = G(u8 *, 0x70039c);
        float s0 = (float)(s32)*(u32 *)(rmv + 0x6f) * (out[0] + 0.5f);
        float s1 = (float)(s32)*(u32 *)(rmv + 0x73) * (out[1] + 0.5f);
        x0 = s0;
        x1 = s1;
        u8 *ec = *(u8 **)(self + 0x821 + 4 * i);
        if (ec != 0) {
          float L10[3] = {x0, x1 + G(float, 0x67da20), 0.0f};
          ((v1_t)vslot(ec, 0x70))(ec, (u32)L10);
        }
      } else {
        x0 = *(float *)(P - 4);
        x1 = *(float *)P;
      }

      ext_5ec660(E0, 1u);
      ext_5ebd80(E0, B != 0 ? *(u32 *)B : 0u);
      float K2 = G(float, 0x67da20);
      *(u8 *)(E0 + 0x35) = 1;
      s32 a4 = (s32)(x1 - K2);
      s32 a3 = (s32)(x0 - K2);
      ext_5ed1e0(E0, 1u, 1u, (u32)a3, (u32)a4, (u32)-1);
    }
  }
  *(u8 *)(self + 0x899) = 0;
}
PCREG(5aa710, fn5aa710);
