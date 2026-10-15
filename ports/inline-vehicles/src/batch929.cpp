// batch929.cpp - vehicles thread, batch 929: ZCar::CheckPlayerCollision, ZCar::InitCarPosDir, ZCar::OnCameraEnter.
#include "ff.h"

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);           // distance
extern "C" void FASTCALL ext_4e2c60(const float *m, float *p);                  // TransformBox
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" float THISCALL ext_44c840(float *v);                                 // vnorm in place
extern "C" void THISCALL ext_523330(void *path, float *d);                      // CMoveAlongPath::GetDir
extern "C" void THISCALL ext_4e09b0(float *v);                                  // vneg
extern "C" void FASTCALL ext_443ef0(float *o, const float *a, const float *b, float k);  // o = a + b * k
extern "C" void THISCALL ext_525640(void *uc, const float *p, const float *d);  // CUnderCarriageCar::InitPosDir
extern "C" void THISCALL ext_525380(void *uc, float *m, float *p);             // GetMatPos
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// The command block the tank sends when the player is close (packed, 0x79 bytes).
struct __attribute__((packed)) CarHit {
  u8 flag;          // +0x00 = 0
  u32 body;         // +0x01 body geom
  float k;          // +0x05 = 100
  float at[3];      // +0x09 body centre, y + 50
  float oldMat[9];  // +0x15 createmat of the old heading
  float oldPos[3];  // +0x39
  float newMat[9];  // +0x45 createmat of the new heading
  float newPos[3];  // +0x69
  float one;        // +0x75 = 1.0
};

// 0x5172e0 ZCar::CheckPlayerCollision (the tank's body with the player at +0x164a and an early exit without one)
// Tank text:(const float* oldMat, const float* oldPos, float* newMat, float* newPos),
// pops 16. The player (+0x2707) origin in tank space is checked against the tank's bounding sphere (group +8:
// centre +0x30, radius +0x4c, plus 200). When inside, the body geom (+0x123) gives its centre (group +0x40, by the
// body's matrix in tank space: GetRootTM, GetLocalMatPos, TransformBox), and the tank sends itself the command word
// +0x2ce from the player with a CarHit block: old/new headings (flattened rows 0 of the matrices) and positions.
static void THISCALL carCheckPlayerCollision(u8 *s, const float *m0, const float *p0, const float *m1, const float *p1) {
  float pp[3];
  pp[0] = 0;
  pp[1] = 0;
  pp[2] = 0;
  if (!*(void **)(s + 0x164a))
    return;
  vcall<void>(*(void **)(s + 0x164a), 0x84, pp);
  vcall<void>(s, 0x8c, pp);
  u8 *grp = *(u8 **)(s + 8);
  float r = *(float *)(grp + 0x4c);
  volatile float d = ext_4e0870(pp, (float *)(grp + 0x30));
  if (!(r + 200.0f > d))
    return;
  u8 *body = vcall<u8 *>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, *(u32 *)(s + 0x123));
  float M[9], P[3], C[3];
  vcall<void>(body, 0x80, M, P);
  vcall<void>(s, 0x94, M, P);
  u8 *bg = *(u8 **)(body + 8);
  C[0] = *(float *)(bg + 0x40);
  C[1] = *(float *)(bg + 0x44);
  C[2] = *(float *)(bg + 0x48);
  ext_4e2c60(M, C);
  CarHit h;
  h.at[0] = C[0];
  h.at[2] = C[2];
  h.flag = 0;
  h.one = 1.0f;
  h.body = (u32)body;
  h.at[1] = C[1] + 50.0f;
  float t[3];
  t[0] = m0[0];
  h.k = 100.0f;
  t[1] = 0;
  t[2] = m0[2];
  ext_4de040(h.oldMat, t, 0);
  t[0] = m1[0];
  t[1] = 0;
  t[2] = m1[2];
  ext_4de040(h.newMat, t, 0);
  h.flag = 0;
  h.oldPos[0] = p0[0];
  h.oldPos[1] = p0[1];
  h.oldPos[2] = p0[2];
  h.newPos[0] = p1[0];
  h.newPos[1] = p1[1];
  h.newPos[2] = p1[2];
  vcall<void>(s, 0x130, *(void **)(s + 0x164a), (u32) * (u16 *)(s + 0x2ce), &h);
}
PCREG(5172e0, carCheckPlayerCollision);

// 0x517d50 ZCar::InitCarPosDir(bool forward): a stationary car takes its geom TM and faces its flattened matrix row
// 0; a car with undercarriage physics (+0x1614) starts at the path point lifted 100, facing the flat path
// direction: forward -> body at point - dir * rear offset (+0x378), state 0; backward -> facing the reversed
// direction with the body at point + dir * front offset (+0x37c), state 1; direction and target stored
// (+0x15df, +0x15d3). The undercarriage is placed (InitPosDir) and read back (GetMatPos). Other cars do nothing.
static void THISCALL carInitCarPosDir(u8 *s, u32 fwd) {
  if (s[0x133]) {
    vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
    u32 *d = (u32 *)(s + 0x15df);
    d[0] = *(u32 *)(s + 0x6c);
    d[1] = *(u32 *)(s + 0x70);
    d[2] = *(u32 *)(s + 0x74);
    *(u32 *)(s + 0x15e3) = 0;
    ext_44c840((float *)d);
    ext_525640(s + 0x2d8, (float *)(s + 0x60), (float *)d);
    ext_525380(s + 0x2d8, (float *)(s + 0x6c), (float *)(s + 0x60));
    return;
  }
  if (!s[0x1614])
    return;
  u8 *p = *(u8 **)(s + 0x5c);
  float S[3], D[3], P[3];
  S[0] = F(p, 8);
  S[1] = F(p, 0xc);
  S[1] = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss(S[1]), _mm_set_ss(100.0f)));
  S[2] = F(p, 0x10);
  ext_523330(p, D);
  D[1] = 0;
  ext_44c840(D);
  if ((u8)fwd) {
    ext_443ef0(P, S, D, bitsf(fbits(F(s, 0x378)) ^ 0x80000000));
    *(u32 *)(s + 0x1650) = 0;
  } else {
    ext_4e09b0(D);
    ext_443ef0(P, S, D, F(s, 0x37c));
    *(u32 *)(s + 0x1650) = 1;
  }
  ext_525640(s + 0x2d8, P, D);
  F(s, 0x15df) = D[0];
  F(s, 0x15e3) = D[1];
  F(s, 0x15e7) = D[2];
  F(s, 0x15d3) = S[0];
  F(s, 0x15d7) = S[1];
  F(s, 0x15db) = S[2];
  ext_525380(s + 0x2d8, (float *)(s + 0x6c), (float *)(s + 0x60));
}
PCREG(517d50, carInitCarPosDir);

// 0x518110 ZCar::OnCameraEnter(): a stationary car pushes its timer +0x35c to now + 1 s once passed; a moving one
// re-runs InitCarPosDir (slot 0x36c, forward unless reversing) between two GetRootTM reads.
static void THISCALL carOnCameraEnter(u8 *s) {
  if (s[0x133]) {
    s32 now = *(s32 *)(*(u8 **)0x70039c + 0x40);
    if (*(s32 *)(s + 0x35c) < now)
      *(s32 *)(s + 0x35c) = now + 0x400;
    return;
  }
  u32 fwd = *(u32 *)(s + 0x1650) != 1;
  vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
  vcall<void>(s, 0x36c, fwd);
  vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
}
PCREG(518110, carOnCameraEnter);
