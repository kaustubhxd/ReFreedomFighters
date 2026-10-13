// batch101.cpp - climbing out of a sewer: the sewer-lid table lookup and its rotation helper (climb thread, batch 101).
#include "ff.h"

extern "C" void FASTCALL ext_4ddcb0(float *mat, const float *axis, float angle);  // LoadRotationAxisAngle, original

// 0x4ddcb0, fastcall (mat in ECX, axis in EDX, angle on the stack), ret 4. LoadRotationAxisAngle (GC map high).
// Fills nine floats from an axis (x, y, z) and an angle, SSE float maths; cos and sin go through the CRT (IAT slots
// 0x676320 and 0x676338, via the thunks 0x634d70 and 0x634d76) as doubles, rounded to float. The layout is the exe's:
// the diagonal terms land at indices 6, 4 and 2 (for x, y and z), so the matrix is stored with its rows reversed
// relative to the textbook form (observed, not interpreted further). t = 1 - c, with 1.0 read from 0x678858.
static void FASTCALL loadRotationAxisAngle(float *m, const float *a, float angle) {
  float c = (float)crt::cos((double)angle);
  float s = (float)crt::sin((double)angle);
  float x = a[0], y = a[1], z = a[2];
  float yy = y * y, xx = x * x, zz = z * z;
  float ys = y * s, xs = x * s, zs = z * s;
  float t = 1.0f - c;
  float xyt = (y * x) * t;
  float zxt = (z * x) * t;
  float zyt = (z * y) * t;
  m[6] = (1.0f - xx) * c + xx;
  m[7] = xyt + zs;
  m[3] = xyt - zs;
  m[8] = zxt - ys;
  m[0] = zxt + ys;
  m[4] = (1.0f - yy) * c + yy;
  m[2] = (1.0f - zz) * c + zz;
  m[5] = zyt + xs;
  m[1] = zyt - xs;
}
PCREG(4ddcb0, loadRotationAxisAngle);

// 0x5b15d0, thiscall (name, int& lid, float pos[3]&, float mat[9]&), ret 0x10. ZSewerControl::GetSewerInfo (GC map high).
// The control holds 19 packed 18-byte records from this+8: +0 name (char*), +4 lid id (signed byte), +5 position (three
// floats, unaligned), +0x11 heading byte. The first record whose name equals `name` (exact, case-sensitive strcmp, inlined)
// gives lid = id, pos = the three floats, and mat = LoadRotationAxisAngle(axis (0, -1, 0), angle) with
// angle = (float)(2 * heading) * pi / 255 (pi and 255 read as floats from 0x67da18 and 0x68af18). No match: lid = -2 and
// pos and mat are left alone. (Used by ZFFLevelController::GetStartingSewerLid when the hero climbs out of a sewer, and by
// the sub-zone map and objectives screens.)
static int strEq(const char *a, const char *b) {
  for (;;) {
    char c = *a;
    if (c != *b)
      return 0;
    if (!c)
      return 1;
    ++a;
    ++b;
  }
}

static void THISCALL getSewerInfo(u8 *self, const char *name, s32 *lid, float *pos, float *mat) {
  for (int i = 0; i < 0x13; ++i) {
    u8 *rec = self + 8 + 0x12 * i;
    if (strEq(name, *(const char **)rec)) {
      *lid = (s8)rec[4];
      *(u32 *)pos = *(u32 *)(rec + 5);
      *(u32 *)(pos + 1) = *(u32 *)(rec + 9);
      *(u32 *)(pos + 2) = *(u32 *)(rec + 0xd);
      float axis[3] = {0.0f, -1.0f, 0.0f};
      float ang = (float)(s32)(rec[0x11] * 2);
      ang = ang * 3.14159274101257324f;   // 0x67da18
      ang = ang / 255.0f;                 // 0x68af18
      ext_4ddcb0(mat, axis, ang);
      return;
    }
  }
  *lid = -2;
}
PCREG(5b15d0, getSewerInfo);
