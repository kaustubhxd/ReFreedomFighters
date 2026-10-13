// batch712.cpp - soldier AI, batch 712 (2026-10-11): the two FindCover front ends that build the search frame from a
// threat direction.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);     // out = a - b
extern "C" float FASTCALL ext_44c840(float *v);                                      // vnorm in place, returns length
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up);    // createmat (frame from dir)
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *v, float s);   // out = a + v * s
extern "C" double VECTORCALL ext_634d7c(double);                                     // CRT sqrt
extern "C" s32 THISCALL ext_586bc0(void *, u32, u32, float *, float *, float, float, float, float, float *, u32);

static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

static void cover_error(u32 line, u32 fmt) {
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ab8a0, line);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)fmt);
}

// Flat-ish direction: y clamped to +-0.15 of the 3D length, then normalised (length stored at +0x5b) and turned into
// a frame.
static float clamp_dir(u8 *self, float *dir, float *mat) {
  float r2 = dir[0] * dir[0] + dir[1] * dir[1];
  r2 = r2 + dir[2] * dir[2];
  float len = (float)ext_634d7c((double)r2);
  return len;
}

// 0x587640 CFFCoverList::FindCoverThreat(unsigned int actor, unsigned int threat, float zMin, float zMax, float xHalf,
// float ahead, bool flag) [high]: frame from the actor towards the threat (y clamped to +-0.15 of the distance), goal
// point = actor + direction * ahead, then FindCover around the actor. Missing actor or threat: logs
// "ERROR: (Tell PA) FindCoverThreat was called with no rThreat or no rRequester." and returns -1.
static s32 THISCALL cover_FindCoverThreat(u8 *self, u32 actor, u32 threat, float zMin, float zMax, float xHalf,
                                          float ahead, u32 flag) {
  void *ag = vcall<void *>(db(), 0x58, actor);
  void *tg = vcall<void *>(db(), 0x58, threat);
  if (!tg || !ag) {
    cover_error(0x361, 0x6abb18);
    return -1;
  }
  float apos[3] = {0, 0, 0}, tpos[3] = {0, 0, 0}, dir[3], mat[9], goal[3];
  vcall<void>(ag, 0x84, apos);
  vcall<void>(tg, 0x84, tpos);
  ext_43e920(dir, tpos, apos);
  float len = clamp_dir(self, dir, mat);
  float k = len * 0.15f;                 // 0x67af1c
  float y = dir[1];
  dir[1] = (-k > y) ? -k : ((k < y) ? k : y);
  *(float *)(self + 0x5b) = ext_44c840(dir);
  ext_4de040(mat, dir, 0);
  ext_443ef0(goal, apos, dir, ahead);
  return ext_586bc0(self, actor, threat, mat, apos, zMin, zMax, xHalf, k, goal, flag);
}
PCREG(587640, cover_FindCoverThreat);

// 0x5873a0 CFFCoverList::FindCoverNearLeader(unsigned int actor, unsigned int threat, unsigned int leader) [high]:
// frame from the leader towards the threat; box z from -500 to (distance > 2100 ? 2000 : distance - 100), x half-width
// 1000 when the threat is closer than 1000, else 1500; nearest to the leader wins; reserved with the flag set. Missing
// threat or leader: logs "ERROR: (Tell PA) FindCoverNearLeader called with null Threat or Leader", -1.
static s32 THISCALL cover_FindCoverNearLeader(u8 *self, u32 actor, u32 threat, u32 leader) {
  void *lg = vcall<void *>(db(), 0x58, leader);
  void *tg = vcall<void *>(db(), 0x58, threat);
  if (!lg || !tg) {
    cover_error(0x336, 0x6abad0);
    return -1;
  }
  float lpos[3] = {0, 0, 0}, tpos[3] = {0, 0, 0}, dir[3], mat[9];
  vcall<void>(lg, 0x84, lpos);
  vcall<void>(tg, 0x84, tpos);
  ext_43e920(dir, tpos, lpos);
  float len = clamp_dir(self, dir, mat);
  float zMax = (len > 2100.0f) ? 2000.0f : len - 100.0f;   // 0x6abba8, 0x686098, 0x67cd40
  float xHalf = (1000.0f > len) ? 1000.0f : 1500.0f;         // 0x67d164, 0x68af28
  float k = len * 0.15f;
  float y = dir[1];
  dir[1] = (-k > y) ? -k : ((k < y) ? k : y);
  *(float *)(self + 0x5b) = ext_44c840(dir);
  ext_4de040(mat, dir, 0);
  return ext_586bc0(self, actor, threat, mat, lpos, -500.0f, zMax, xHalf, k, lpos, 1);
}
PCREG(5873a0, cover_FindCoverNearLeader);
