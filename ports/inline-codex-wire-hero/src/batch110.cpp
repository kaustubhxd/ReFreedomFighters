// batch110.cpp - going down into a sewer: when the hero may open a lid (climb thread, batch 110).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);  // PSVECSubtract, original
extern "C" void THISCALL ext_4e0d00(float *v, float s);                           // in-place vscalar, original
extern "C" void THISCALL ext_5950c0(void *hero, u32 action, float dist, const char *text);  // ZFFHERO::SetUseAction
extern "C" void THISCALL ext_5c3860(void *openSewer, u32 ref);                    // COpenSewer::ActivateMenu

static inline u8 *engineDb() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x5e88e0, ZFFHeroMovementOpenSewer::WantControl(a, pos, c) (GC map high). thiscall, ret 0xc, AL. From the exe:
//  - Already opening (+0x54c): yes. Hero (+0x36d) byte +0x9f5 clear (guess: may use things): no.
//  - Walks the game data's SSewer list (count +0xc69, 9-byte records at +0xc6d): each lid geom's position (slot 0x80)
//    raised by 60, minus pos; when the squared distance is not above 40000 (200 units) that sewer goes to +0x557 (so the
//    last one in range wins) and the offset is normalised in place (result unused). The squared distance kept for later
//    is the LAST entry's, in range or not (exe behaviour, kept).
//  - No sewer in range: no. Otherwise SetUseAction(0xa if the lid's open byte (+8) is clear else 0xc, sqrt of that
//    squared distance, null): the use prompt (ZFFHERO::DisplayUseAction shows the action names).
//  - If the hero's current use action (+0x9d3) is 0xc and the use key (+0x66c) is down: COpenSewer::ActivateMenu on the
//    sewer's event object (record +0) with its geom ref (record +4), answer no (the sewer menu opens). If it is 0xa and
//    the key is down: yes (the opening animation starts). Otherwise no.
static bool THISCALL openSewerWantControl(u8 *self, const float *a, const float *pos, const float *c) {
  (void)a;
  (void)c;
  if (self[0x54c])
    return true;
  if (!(*(u8 **)(self + 0x36d))[0x9f5])
    return false;
  *(u32 *)(self + 0x557) = 0;
  u8 *gd = G(u8 *, 0x7003b8);
  float d2 = 0.0f;   // only read when a sewer was found, which means the loop ran
  for (u8 *s = gd + 0xc6d; s != gd + 0xc6d + 9 * *(s32 *)(gd + 0xc69); s += 9) {
    void *g = vcall<void *>(engineDb(), 0x58, *(u32 *)(s + 4));
    float mat[9], p[3], d[3];
    vcall<void>(g, 0x80, mat, p);
    p[1] = p[1] + 60.0f;
    ext_43e920(d, p, pos);
    d2 = d[0] * d[0] + d[1] * d[1];
    d2 = d2 + d[2] * d[2];
    if (d2 > 40000.0f)
      continue;
    ext_4e0d00(d, (float)(1.0 / crt::sqrt((double)d2)));
    *(u8 **)(self + 0x557) = s;
  }
  u8 *s = *(u8 **)(self + 0x557);
  if (!s)
    return false;
  float dist = (float)crt::sqrt((double)d2);
  ext_5950c0(*(void **)(self + 0x36d), s[8] ? 0xcu : 0xau, dist, 0);
  u8 *hero = *(u8 **)(self + 0x36d);
  if (*(s32 *)(hero + 0x9d3) == 0xc && hero[0x66c]) {
    u8 *rec = *(u8 **)(self + 0x557);
    ext_5c3860(*(void **)rec, *(u32 *)(rec + 4));
    return false;
  }
  if (*(s32 *)(hero + 0x9d3) == 0xa && hero[0x66c])
    return true;
  return false;
}
PCREG(5e88e0, openSewerWantControl);
