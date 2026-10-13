#include "ff.h"
// batch1388.cpp - unclaimed-13 claim 7 (docs/20-unclaimed-13.md). Name from the GC name map (high).
// The helpers are original code, bound by build.sh as ext_<addr>. Calling conventions as the original uses them.

extern "C" void FASTCALL ext_4dfd10(float *dst, const float *src);              // tmat(dst, src)
extern "C" void FASTCALL ext_4de480(float *a, const float *b);                  // GUESS: vmmul pair helper
extern "C" void FASTCALL ext_441970(float *out, const float *a, const float *b); // vmmul(out, a, b), 3rd arg on stack
extern "C" void FASTCALL ext_43e960(float *a, const float *b);                  // GUESS: vector subtract
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);           // vdist2(a, b), float in st0
extern "C" void THISCALL ext_4e0d80(float *v, float len);                       // vsetlen(v, len)
extern "C" void FASTCALL ext_441940(float *a, const float *b);                  // PSVECAdd(a, b)

// 0x46d400, ZItem::CorrectOwnerDrawMatrix(float*, float*, unsigned int) (high). Thiscall, ret 0xc.
// m = first argument (the matrix written at the end), v = second (a point), mode = third.
// The vtable slot +0x2dc (no arguments) gives an object o; the source is o (or this, if o is null).
static void THISCALL zItemCorrectOwnerDrawMatrix(u8 *self, float *m, float *v, u32 mode) {
  typedef u8 *(THISCALL * slot2dc_fn)(u8 *);
  u8 *o = ((slot2dc_fn)(*(u32 *)(*(u32 *)self + 0x2dc)))(self);
  u8 *src = o ? o : self;

  float local28[9];
  float local38[3];

  ext_4dfd10(local28, *(float **)(src + 8));
  ext_4de480(local28, m);
  ext_441970(local38, *(float **)(src + 8) + 9, local28);
  ext_43e960(v, local38);

  // tmat copy: 36 bytes from local28 to m (the 0x4de420 copy, inlined)
  for (int i = 0; i < 9; i++) ((u32 *)m)[i] = ((u32 *)local28)[i];

  if (mode != 0xbu) return;

  typedef void(THISCALL * slot8c_fn)(u8 *, float *);
  typedef void(THISCALL * slot84_fn)(u8 *, float *);
  ((slot8c_fn)(*(u32 *)(*(u32 *)self + 0x8c)))(self, v);

  u8 *a = self + 0x82;
  float dist = ext_4e0830((const float *)a, v);
  if (dist > 100.0f) {
    ext_43e960((float *)a, v);
    ext_4e0d80((float *)a, 10.0f);
    ext_441940((float *)a, v);
  }

  // common tail (the 0x84 call takes v as its one stack argument: `push ebx` before it): v[0] and v[1] are pulled toward a with factor 0.5 (x and y); v[2] is kept; then a takes v.
  float vx = v[0];
  float vz = v[2];
  float x = (vx - ((float *)a)[0]) * 0.5f + ((float *)a)[0];
  float yv = v[1];
  float y = (yv - ((float *)a)[1]) * 0.5f + ((float *)a)[1];
  v[0] = x;
  v[2] = vz;
  v[1] = y;
  ((float *)a)[0] = v[0];
  ((float *)a)[1] = v[1];
  ((float *)a)[2] = v[2];

  ((slot84_fn)(*(u32 *)(*(u32 *)self + 0x84)))(self, v);
}
PCREG(46d400, zItemCorrectOwnerDrawMatrix);
