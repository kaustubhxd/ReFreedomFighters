// batch726.cpp - soldier AI, batch 726 (2026-10-12): ZFFActorIf::CheckPosDir (0x558390), the walk-to-position-and-direction
// check. Argument pr: the in-accessor holds the target position (items 0..2, with y replaced by the actor's own y from the
// slot 0x57c query) and the direction (items 3..5, negated). The actor's root vector F = (0,0,1) is taken through slot 0x88.
// Pass: distance |pos - P| <= 1 and |angle(D, F)| <= 0.1 (both compared, NaN passes); logs "Distanct to pos" and
// "Angle to dst_dir" (lines 0x44e/0x44f). Fail: logs the actor name (slot 0x20 object, slot 0x1d8 name), the failure
// line and both measures (0x438..0x43b), then two scene rays (P to P + 200 D, and v28 to v28 + 200 F, each with y += 1
// before and after the second) through the cached handles 0x7140bc/0x7140c0. Both paths end with the db update (slot
// 0xb4, 1) and a ray from the actor root point to root + (0,300,0) through the handle at 0x7140c4. The SEH frame and the
// stack cookie belong to the exe prologue and are not ported.
#include "ff.h"

struct Item { u32 v; u8 t; u8 pad[3]; };   // accessor item: value at +0, type byte at +4
struct MYSTR_buf { u8 b[0x80]; };

extern "C" Item *THISCALL ext_5003d0(void *acc, u32 idx);                          // accessor (ecx = object, idx on stack)
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);             // distance |a - b| (st0)
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);             // angle(a, b) (st0)
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);         // vscalar: out = a * s
extern "C" void FASTCALL ext_441940(float *v, const float *b);                    // PSVECAdd: v += b
extern "C" void THISCALL ext_4e09b0(float *v);                                    // vneg
extern "C" const char *THISCALL ext_4cc1d0(void *mystr);                          // MYSTR::c_str
extern "C" void THISCALL ext_4cbec0(void *mystr);                                 // MYSTR::~MYSTR

static inline void *engine() { return *(void **)0x70039c; }
static inline void *db() { return *(void **)((u8 *)engine() + 0x9b); }
static inline void *scene() { return *(void **)((u8 *)db() + 0xadc); }

static void *log_of(u32 line) { return vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6a5eb0, line); }

static void printf_d(void *log, const char *fmt, double v) {
  typedef void(__attribute__((cdecl)) * pf_t)(void *, const char *, double);
  (*(pf_t *)(*(u8 **)log + 0x2c))(log, fmt, v);
}

static void printf_s(void *log, const char *fmt, const char *s) {
  typedef void(__attribute__((cdecl)) * pf_t)(void *, const char *, const char *);
  (*(pf_t *)(*(u8 **)log + 0x2c))(log, fmt, s);
}

static void printf_0(void *log, const char *fmt) {
  typedef void(__attribute__((cdecl)) * pf_t)(void *, const char *);
  (*(pf_t *)(*(u8 **)log + 0x2c))(log, fmt);
}

// a scene ray: the first call stores the handle in the global cache, later calls update it.
static void ray(u32 *cache, float *a, float *b, u32 flags) {
  if (!*cache)
    *cache = vcall<u32>(scene(), 0x218, a, b, flags);
  else
    vcall<void>(scene(), 0x21c, *cache, a, b, flags);
}

// 0x558390 ZFFActorIf::CheckPosDir(OpaqueCallParameters_t&) [high].
static void THISCALL actorif_CheckPosDir(u8 *self, u8 *pr) {
  void *inAcc = *(void **)(pr + 4);
  Item *i2 = ext_5003d0(inAcc, 2);
  Item *i1 = ext_5003d0(inAcc, 1);
  Item *i0 = ext_5003d0(inAcc, 0);
  Item *i5 = ext_5003d0(inAcc, 5);
  Item *i4 = ext_5003d0(inAcc, 4);
  Item *i3 = ext_5003d0(inAcc, 3);
  float P[3] = {bitsf(i0->v), bitsf(i1->v), bitsf(i2->v)};
  float D[3] = {bitsf(i3->v), bitsf(i4->v), bitsf(i5->v)};
  ext_4e09b0(D);

  u8 *actor = *(u8 **)(self + 0x1c);
  float v28[3];
  u8 b88[0x30];
  vcall<void>(actor, 0x57c, b88, v28);     // actor position into v28
  P[1] = v28[1];                           // the target keeps the actor's height

  float F[3] = {0.0f, 0.0f, 1.0f};
  vcall<void>(actor, 0x88, F);             // F = root vector of (0, 0, 1)

  float d = ext_4e0870(v28, P);
  bool ok = true;
  if (d > bitsf(0x3f800000u))              // 1.0
    ok = false;
  if (ok) {
    double ang = ext_4e0030(D, F);
    if (__builtin_fabs(ang) > 0.10000000149011612)   // 0.1 (as the float constant widened)
      ok = false;
  }

  if (ok) {
    void *log = log_of(0x44e);
    printf_d(log, (const char *)0x6a5f88, (double)ext_4e0870(v28, P));   // "Distanct to pos : %f"
    log = log_of(0x44f);
    printf_d(log, (const char *)0x6a5fa0, (double)ext_4e0030(D, F));    // "Angle to dst_dir: %f"
  } else {
    void *obj = vcall<void *>(actor, 0x20);
    void *log = log_of(0x438);
    MYSTR_buf nm;
    void *ms = vcall<void *>(obj, 0x1d8, &nm, 1);
    printf_s(log, (const char *)0x6a5f60, ext_4cc1d0(ms));          // "Actor %s"
    ext_4cbec0(&nm);
    log = log_of(0x439);
    printf_0(log, (const char *)0x6a5f6c);                           // "Walk/RunToPosDir failed..."
    log = log_of(0x43a);
    printf_d(log, (const char *)0x6a5f88, (double)ext_4e0870(v28, P));
    log = log_of(0x43b);
    printf_d(log, (const char *)0x6a5fa0, (double)ext_4e0030(D, F));

    float X[3];
    ext_4e0d40(X, D, bitsf(0x43480000u));  // 200
    ext_441940(X, P);
    ray((u32 *)0x7140bc, P, X, 0xff00u);

    v28[1] = v28[1] + bitsf(0x3f800000u);  // y += 1 (0x678858)
    ext_4e0d40(X, F, bitsf(0x43480000u));
    ext_441940(X, v28);
    ray((u32 *)0x7140c0, v28, X, 0xff0000u);
    v28[1] = v28[1] + bitsf(0x3f800000u);
  }

  vcall<void>(db(), 0xb4, 1u);

  float root[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(actor, 0x84, root);
  float V1[3] = {root[0], root[1] + bitsf(0x43960000u), root[2]};   // + 300
  ray((u32 *)0x7140c4, root, V1, 0xffffffu);
}
PCREG(558390, actorif_CheckPosDir);
