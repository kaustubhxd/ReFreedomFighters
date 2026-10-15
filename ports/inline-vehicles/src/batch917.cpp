// batch917.cpp - vehicles thread, batch 917: ZTank::CheckPlayerCollision and ZTank::OnCameraEnter.
#include "ff.h"

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);           // distance
extern "C" void FASTCALL ext_4e2c60(const float *m, float *p);                  // TransformBox / point by TM
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void THISCALL ext_528100(void *uc, const float *p, const float *d);  // CUnderCarriageTank::InitPosDir
extern "C" void THISCALL ext_525380(void *uc, float *m, float *p);             // CUnderCarriageTank::GetMatPos

// The command block the tank sends when the player is close (packed, 0x79 bytes).
struct __attribute__((packed)) TankHit {
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

// 0x520450 ZTank::CheckPlayerCollision(const float* oldMat, const float* oldPos, float* newMat, float* newPos),
// pops 16. The player (+0x2707) origin in tank space is checked against the tank's bounding sphere (group +8:
// centre +0x30, radius +0x4c, plus 200). When inside, the body geom (+0x123) gives its centre (group +0x40, by the
// body's matrix in tank space: GetRootTM, GetLocalMatPos, TransformBox), and the tank sends itself the command word
// +0x2ce from the player with a TankHit block: old/new headings (flattened rows 0 of the matrices) and positions.
static void THISCALL tankCheckPlayerCollision(u8 *s, const float *m0, const float *p0, const float *m1, const float *p1) {
  float pp[3];
  pp[0] = 0;
  pp[1] = 0;
  pp[2] = 0;
  vcall<void>(*(void **)(s + 0x2707), 0x84, pp);
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
  TankHit h;
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
  vcall<void>(s, 0x130, *(void **)(s + 0x2707), (u32) * (u16 *)(s + 0x2ce), &h);
}
PCREG(520450, tankCheckPlayerCollision);

// 0x5212f0 ZTank::OnCameraEnter(): a stationary tank only pushes its timer +0x382 to now + 1 s (0x400 ticks) once
// it has passed; a moving one is re-seated at its path point (lifted 100) with its hull direction (undercarriage
// InitPosDir + GetMatPos) and its old position reset.
static void THISCALL tankOnCameraEnter(u8 *s) {
  if (s[0x133]) {
    s32 now = *(s32 *)(*(u8 **)0x70039c + 0x40);
    if (*(s32 *)(s + 0x382) < now)
      *(s32 *)(s + 0x382) = now + 0x400;
    return;
  }
  u8 *p = *(u8 **)(s + 0x5c);
  float S[3];
  S[0] = *(float *)(p + 8);
  S[1] = *(float *)(p + 0xc) + 100.0f;
  S[2] = *(float *)(p + 0x10);
  ext_528100(s + 0x2fd, S, (float *)(s + 0x2d8));
  ext_525380(s + 0x2fd, (float *)(s + 0x6c), (float *)(s + 0x60));
  *(u32 *)(s + 0x90) = *(u32 *)(s + 0x60);
  *(u32 *)(s + 0x94) = *(u32 *)(s + 0x64);
  *(u32 *)(s + 0x98) = *(u32 *)(s + 0x68);
}
PCREG(5212f0, tankOnCameraEnter);
