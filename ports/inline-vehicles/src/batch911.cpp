// batch911.cpp - vehicles thread, batch 911: ZHeli::UpdatePos, the helicopter flight model.
#include "ff.h"

extern "C" void FASTCALL ext_451890(float *v, const float *a, float k);         // vaddscalar: v += a * k (x87)
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);  // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b
extern "C" void THISCALL ext_4e0d00(float *v, float k);                         // vscalar: v *= k
extern "C" float FASTCALL ext_44e630(float *out, const float *v);               // vnorm(out, v) -> length
extern "C" float THISCALL ext_44c840(float *v);                                 // vnorm in place -> length
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);  // vcross
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);           // vangle
extern "C" void FASTCALL ext_4ddcb0(float *m, const float *axis, float a);      // LoadRotationAxisAngle (batch 904)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                  // vmmul: v = v * m
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                  // mcpy 3x3
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);           // distance

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
static inline double fabs64(double d) {
  return _mm_cvtsd_f64(_mm_and_pd(_mm_set_sd(d), _mm_load_pd((const double *)ABS64)));
}

// 0x51ddc0 ZHeli::UpdatePos(). Skipped when the frame time (engine +0x48) is under 2^-13. A spring toward the
// spline point: lift A = (0, 50000, 0) + 0.01 * (spline pos +0x24a - (pos +0x60 + vel +0x23e * dt)) * 5000 / dt^2.
// The body's up vector follows the lift direction N: while firing (+0x469) N is turned about up x dir by
// atan(height / 3500) - angle(up +0x262, world up) (nose down to aim); N.y is clamped to [0.7, 1] and N
// normalised; the smoothed up +0x3f1 eases to N at 2.5 * dt; the body up +0x262 eases (in heli space, x twice as
// fast when the new x is larger) at 0.5 * dt, back to world, normalised; the matrix +0x6c = rows
// ((side x up), up, side) with side = norm(up x dir +0x216). Position += (A - (0, 50000, 0)) * 0.02 * dt^2 +
// vel * dt; more than 1 unit off the spline draws a red debug line (world +0xadc slot 0x218 first time, its
// handle kept at 0x7018d0, then slot 0x21c). Velocity = (pos - old pos +0x90) / dt; old pos = pos.
static void THISCALL heliUpdatePos(u8 *s) {
  u8 *sy = *(u8 **)0x70039c;
  if (0.0001220703125f > *(float *)(sy + 0x48))
    return;
  float *pos = (float *)(s + 0x60), *vel = (float *)(s + 0x23e), *spl = (float *)(s + 0x24a);
  float *up = (float *)(s + 0x262), *dir = (float *)(s + 0x216);
  float P[3], D[3], A[3], N[3];
  P[0] = pos[0];
  P[1] = pos[1];
  P[2] = pos[2];
  ext_451890(P, vel, *(float *)(sy + 0x48));
  ext_43e920(D, spl, P);
  ext_4e0d00(D, 0.01f);
  A[0] = 0;
  A[1] = 50000.0f;
  A[2] = 0;
  float dt = *(float *)(*(u8 **)0x70039c + 0x48);
  ext_451890(A, D, 5000.0f / (dt * dt));
  ext_44e630(N, A);
  if (*(u32 *)(s + 0x469)) {
    float ax[3], wup[3], R[9];
    ext_446ee0(ax, up, dir);
    double tgt = crt::atan((double)(*(float *)(s + 0x597) / 3500.0f));
    wup[0] = 0;
    wup[1] = 1.0f;
    wup[2] = 0;
    volatile double tv = tgt;
    float r = (float)((long double)tv - (long double)ext_4e0030(up, wup));
    ext_4ddcb0(R, ax, r);
    ext_4419f0(N, R);
  }
  float y = N[1];
  N[1] = 0.7f > y ? 0.7f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(y)));
  if (!(N[0] == 0.0f && N[1] == 0.0f && N[2] == 0.0f)) {
    long double x = N[0], yy = N[1], z = N[2];
    long double inv = 1.0L / fsqrt_x87((x * x + yy * yy) + z * z);
    N[0] = (float)(N[0] * inv);
    N[1] = (float)(N[1] * inv);
    N[2] = (float)(N[2] * inv);
  }
  float h = *(float *)(*(u8 **)0x70039c + 0x48) * 0.5f;
  float k = h * 5.0f;
  float *U = (float *)(s + 0x3f1);
  float T[3];
  for (int i = 0; i < 3; i++) {
    U[i] = (N[i] - U[i]) * k + U[i];
    T[i] = U[i];
  }
  vcall<void>(s, 0x90, up);
  vcall<void>(s, 0x90, T);
  float x4 = up[0], t0 = T[0];
  float f = fabs64((double)t0) > fabs64((double)x4) ? 2.0f : 1.0f;
  up[0] = (t0 - x4) * f * h + x4;
  up[1] = (T[1] - up[1]) * h + up[1];
  up[2] = (T[2] - up[2]) * h + up[2];
  vcall<void>(s, 0x88, up);
  ext_44c840(up);
  float M[9];  // rows: E, Q (= up), C (= side)
  M[3] = up[0];
  M[4] = up[1];
  M[5] = up[2];
  ext_446ee0(M + 6, up, dir);
  ext_44c840(M + 6);
  ext_446ee0(M, M + 6, M + 3);
  ext_4de420((float *)(s + 0x6c), M);
  float gdn[3], G[3];
  gdn[0] = 0;
  gdn[1] = -50000.0f;
  gdn[2] = 0;
  ext_43e8e0(G, A, gdn);
  dt = *(float *)(*(u8 **)0x70039c + 0x48);
  ext_451890(pos, G, dt * dt * 0.019999999552965164f);
  ext_451890(pos, vel, *(float *)(*(u8 **)0x70039c + 0x48));
  volatile float d = ext_4e0870(pos, spl);
  if (d > 1.0f) {
    u8 *dbg = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc);
    u32 hd = *(u32 *)0x7018d0;
    if (!hd)
      *(u32 *)0x7018d0 = vcall<u32>(dbg, 0x218, pos, spl, 0xff0000);
    else
      vcall<void>(dbg, 0x21c, hd, pos, spl, 0xff0000);
  }
  float *old = (float *)(s + 0x90);
  ext_43e920(vel, pos, old);
  ext_4e0d00(vel, 1.0f / *(float *)(*(u8 **)0x70039c + 0x48));
  ((u32 *)old)[0] = ((u32 *)pos)[0];
  ((u32 *)old)[1] = ((u32 *)pos)[1];
  ((u32 *)old)[2] = ((u32 *)pos)[2];
}
PCREG(51ddc0, heliUpdatePos);
