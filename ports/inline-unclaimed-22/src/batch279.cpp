// batch279.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch279"): ZMovementGuide::
// GetActiveAnim (the guided walk's blend phase from the height difference to the guide point, with foot-switch calls)
// and ZMovementStand::GetAnims (the stand movement's animation lookup and blend setup). Names from the GameCube name map;
// behaviour from the PC bytes.
#include "ff.h"

extern "C" float THISCALL ext_4884b0(u8 *self, u32 *out, const float *a, const float *b, const float *c,
                                     const float *d);                               // ZMovementBaseMove::GetActiveAnim (unclaimed-65; hooked)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract (inline-batch45)

#define C(a) (*(float *)(a##u))
#define D(a) (*(double *)(a##u))
#define F(o) (*(float *)(self + (o)))

// fmod(d, 1.0) through the exe's _CIfmod thunk 0x634dc4 (st1 = d, st0 = 1.0), kept as a double.
static double fmodOneD(double d) {
  double out;
  asm volatile("fldl %[d]\n\t"
               "fld1\n\t"
               "call *%[t]\n\t"
               "fstpl %[o]\n\t"
               : [o] "=m"(out)
               : [d] "m"(d), [t] "r"(0x634dc4)
               : "eax", "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)", "cc");
  return out;
}

// 0x488650 ZMovementGuide::GetActiveAnim(AnimHeader **out, a, b, c, pos) (thiscall, ret 0x14, st0). Without the guide
// byte +0x3ad it is ZMovementBaseMove::GetActiveAnim 0x4884b0. Else phase +0xc = 1, *out = anim +0x391; the vertical
// distance y from pos (lowered by the actor's +0x43d) to the guide point +0x379 sets the blend +0x3a9: below 169 it is
// 1 - max(0, y) / 169 clamped to [0, 1] and the result is blend * 0.48 + 0.52 (feet 0.1/0.45/0.65 up, 0.35/0.05 down);
// from 169 it is 1 - fmod((y - 169) / 100, 1) and the result blend * 0.21 + 0.31 (0.25/0.75). When the old blend is not
// negative and within 0.5 of the new one, crossing one of those marks calls actor vt 0x3f8(1 or 0). The actor's +0x14b
// (or +0x147 when 0) is written back to +0x14b.
float THISCALL guideGetActiveAnim_488650(u8 *self, u32 *out, const float *a, const float *b, const float *c,
                                         const float *pos) {
  if (!self[0x3ad]) return ext_4884b0(self, out, a, b, c, pos);
  *(u32 *)(self + 0xc) = 0x3f800000u;
  *out = *(u32 *)(self + 0x391);
  float old = F(0x3a9);
  float L[3] = {pos[0], pos[1], pos[2]};
  L[1] = L[1] - *(float *)(*(u8 **)(self + 4) + 0x43d);
  float d[3];
  ext_43e920(d, (const float *)(self + 0x379), L);
  u8 *act = *(u8 **)(self + 4);
  u32 saved = *(u32 *)(act + 0x14b);
  if (!saved) saved = *(u32 *)(act + 0x147);
  float y = d[1];
  float res, x3;
  int sel = -1;
  if (C(0x68d460) > y) {
    float r = 0.0f > y ? 0.0f : y;
    r = r / C(0x68d460);
    float p = C(0x678858) - r;
    F(0x3a9) = p;
    if (0.0f > p) *(u32 *)(self + 0x3a9) = 0;
    if (F(0x3a9) > C(0x678858)) *(u32 *)(self + 0x3a9) = 0x3f800000u;
    x3 = F(0x3a9);
    res = x3 * C(0x68d440) + C(0x68d444);
    if (old >= 0.0f && D(0x68c740) > __builtin_fabs((double)(old - x3))) {
      float A = C(0x67a284), B = C(0x68d43c), Cc = C(0x68d448), E = C(0x68d438), G = C(0x681dc4);
      if (A >= old && x3 > A) sel = 1;
      else if (old > B && B > x3) sel = 1;
      else if (Cc >= old && x3 > Cc) sel = 1;
      else if (E >= old && x3 > E) sel = 0;
      else if (old > G && G >= x3) sel = 0;
      else if (old > Cc && Cc >= x3) sel = 0;
    }
  } else {
    float q = (y - C(0x68d460)) / C(0x67cd40);
    double fm = fmodOneD((double)q);
    x3 = (float)(D(0x678610) - fm);
    F(0x3a9) = x3;
    res = x3 * C(0x68d430) + C(0x68d434);
    if (old >= C(0x6785d0) && D(0x68c740) > __builtin_fabs((double)(old - x3))) {
      float A = C(0x67a288), H = C(0x684ce4);
      if (A >= old && x3 > A) sel = 1;
      else if (old > H && H >= x3) sel = 1;
      else if (H >= old && x3 > H) sel = 0;
      else if (old > A && A >= x3) sel = 0;
    }
  }
  if (sel >= 0) vcall<void>(act, 0x3f8, (u32)sel);
  *(u32 *)(*(u8 **)(self + 4) + 0x14b) = saved;
  return res;
}
PCREG(488650, guideGetActiveAnim_488650);

// 0x489190 ZMovementStand::GetAnims() (thiscall). Looks up its animations by name (this->vt 0x58): Std_Pose +0x1d,
// Stand_Do_Nothing +0x35 and +0x95, Stand_Do_Nothing_L* +0x4d, Stand_Do_Nothing_R* +0x65, Stand_Rel* +0x7d,
// Drag_Ambient +0xad, Sneak_Ambient +0xc5. The random blend at +0xdd gets entries (vt 8(entry, 0, weight)) for +0x35 (1.0),
// +0x4d and +0x65 (0.1), +0x7d and +0x95 (0.2); the blends at +0xf5 and +0x10d get +0xad and +0xc5 (1.0). Then
// this->vt 0x54 on +0x35, +0x4d, +0x65, +0x7d, +0x95 and +0x1d.
void THISCALL standGetAnims_489190(u8 *self) {
  *(u32 *)(self + 0x1d) = vcall<u32>(self, 0x58, 0x68d1acu);
  *(u32 *)(self + 0x35) = vcall<u32>(self, 0x58, 0x68d1b8u);
  *(u32 *)(self + 0x4d) = vcall<u32>(self, 0x58, 0x68d1ccu);
  *(u32 *)(self + 0x65) = vcall<u32>(self, 0x58, 0x68d1e0u);
  *(u32 *)(self + 0x7d) = vcall<u32>(self, 0x58, 0x68d1f4u);
  *(u32 *)(self + 0x95) = vcall<u32>(self, 0x58, 0x68d1b8u);
  *(u32 *)(self + 0xad) = vcall<u32>(self, 0x58, 0x68d200u);
  *(u32 *)(self + 0xc5) = vcall<u32>(self, 0x58, 0x68d210u);
  u8 *bl = self + 0xdd;
  vcall<void>(bl, 8, (u32)(self + 0x35), 0u, 1.0f);
  vcall<void>(bl, 8, (u32)(self + 0x4d), 0u, 0.1f);
  vcall<void>(bl, 8, (u32)(self + 0x65), 0u, 0.1f);
  vcall<void>(bl, 8, (u32)(self + 0x7d), 0u, 0.2f);
  vcall<void>(bl, 8, (u32)(self + 0x95), 0u, 0.2f);
  vcall<void>(self + 0xf5, 8, (u32)(self + 0xad), 0u, 1.0f);
  vcall<void>(self + 0x10d, 8, (u32)(self + 0xc5), 0u, 1.0f);
  vcall<void>(self, 0x54, (u32)(self + 0x35));
  vcall<void>(self, 0x54, (u32)(self + 0x4d));
  vcall<void>(self, 0x54, (u32)(self + 0x65));
  vcall<void>(self, 0x54, (u32)(self + 0x7d));
  vcall<void>(self, 0x54, (u32)(self + 0x95));
  vcall<void>(self, 0x54, (u32)(self + 0x1d));
}
PCREG(489190, standGetAnims_489190);
#undef F
#undef D
#undef C
