// batch114.cpp - ZMovementBase::CheckGroundContact (footsteps) and GetActiveAnimMovement, the last two shared slots of
// the climb-family vtables (climb thread, batch 114).
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                        // mcpy
extern "C" void THISCALL ext_4de7a0(float *m);                                            // mreset
extern "C" void FASTCALL ext_4de520(float *out, const float *a, const float *b, float t);  // mpul
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                            // vmmul
extern "C" void FASTCALL ext_4de440(float *out, const float *a, const float *b);          // mmmul
extern "C" void FASTCALL ext_441940(float *v, const float *a);                            // v += a (x87)

static inline u8 *sys() { return G(u8 *, 0x70039c); }
// comiss outcomes: "below" (CF) is true for less-than or unordered; "above" only for ordered greater-than.
static inline bool below(float x, float y) { return !(x >= y); }
static inline bool above(float x, float y) { return x > y; }

// 0x4882d0, ZMovementBase::CheckGroundContact(float prev, float cur) (GC map medium). thiscall, ret 8.
// prev and cur are animation phases. Nothing happens when the owner's (+4) flag word +0x417 has bit 27 (guess: in water).
// owner+0x145 = (flag word == 2). When |prev - cur| < 0.5 (as doubles; NaN fails), a foot touches down as the phase
// crosses a quarter: up through 0.25 or down through 0.75 gives foot 1, up through 0.75 or down through 0.25 gives foot
// 0 (comiss rules kept exactly). The foot's sound geom (owner slot 0x3f8(foot), then engine slot 0x60) gets a random
// offset: i = trunc((random(file zmovement.cpp, line 0x21c) - 0.5) * 50) on the x87 stack; g+0x60 = i - g+0x64,
// g+0x64 = i (guess: the footstep sound's pitch or start offset).
static void THISCALL checkGroundContact(u8 *self, float prev, float cur) {
  u8 *own = *(u8 **)(self + 4);
  u32 f = *(u32 *)(own + 0x417);
  if (f & 0x8000000u)
    return;
  float diff = prev - cur;
  own[0x145] = f == 2;
  if (!(0.5 > __builtin_fabs((double)diff)))   // andps sign clear, comisd; NaN never passes
    return;
  u32 foot;
  if (!below(0.25f, prev) && above(cur, 0.25f))
    foot = 1;
  else if (above(prev, 0.75f) && !below(0.75f, cur))
    foot = 1;
  else if (!below(0.75f, prev) && above(cur, 0.75f))
    foot = 0;
  else if (above(prev, 0.25f) && !below(0.25f, cur))
    foot = 0;
  else
    return;
  u32 x = vcall<u32>(*(void **)(self + 4), 0x3f8, foot);
  if (!x)
    return;
  u8 *g = vcall<u8 *>(*(void **)(sys() + 0x9b), 0x60, x);
  if (!g)
    return;
  typedef long double(THISCALL * randfn)(void *, const char *, u32);
  randfn rnd = *(randfn *)(*(u8 **)sys() + 0x1c0);
  float v = (float)((rnd(sys(), (const char *)0x68d220, 0x21c) - 0.5f) * 50.0f);
  s32 i = (s32)v;
  *(s32 *)(g + 0x60) = i - *(s32 *)(g + 0x64);
  *(s32 *)(g + 0x64) = i;
}
PCREG(4882d0, checkGroundContact);

// 0x488a00, ZMovementBase::GetActiveAnimMovement(mat, pos, outMat, outPos) const (GC map medium). thiscall, ret 0x10, AL.
// The owner's slot 0x5e0(m, v) gives the root motion of the active animation for this frame; none: outMat = mat,
// outPos = pos, returns 0. Otherwise s = (this+0x18 equal to 0 ? dt : this+0x18) / dt with dt = sys+0x48 (frame time;
// s stays 0 when dt is 0, NaN counts as not 0), outMat = mat * mpul(identity, m, s), outPos = pos + (v * s) * mat.
// Returns 1.
static bool THISCALL getActiveAnimMovement(u8 *self, const float *mat, const float *pos, float *outMat, float *outPos) {
  float m[9], v[3];
  if (!vcall<bool>(*(void **)(self + 4), 0x5e0, m, v)) {
    ext_4de420(outMat, mat);
    outPos[0] = pos[0];
    outPos[1] = pos[1];
    outPos[2] = pos[2];
    return false;
  }
  float s = 0.0f;
  float dt = *(float *)(sys() + 0x48);
  if (dt != 0.0f) {
    float x = *(float *)(self + 0x18);
    s = (x == 0.0f ? dt : x) / dt;
  }
  float id[9], blend[9];
  ext_4de7a0(id);
  ext_4de520(blend, id, m, s);
  outPos[0] = (v[0] - 0.0f) * s + 0.0f;
  outPos[1] = (v[1] - 0.0f) * s + 0.0f;
  outPos[2] = (v[2] - 0.0f) * s + 0.0f;
  ext_4419f0(outPos, mat);
  ext_4de440(outMat, mat, blend);
  ext_441940(outPos, pos);
  return true;
}
PCREG(488a00, getActiveAnimMovement);
