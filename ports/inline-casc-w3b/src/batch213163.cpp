#include "ff.h"

extern "C" void FASTCALL ext_43e920(void *out, void *a, void *b);
extern "C" void FASTCALL ext_441a60(void *vec, void *mat);
extern "C" u32 THISCALL ext_45d380(void *self, u32 a, u32 b);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u16 R16(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
#define MSG(a) G(u16, a)

// 0x472ae0: thiscall(msg, data) ret 8, /GS, returns 0. Dispatches a ZLNKWHANDS style command on the message id (words at 0x6ff99c..0x6ff9bc).
static void body_472ae0(u8 *edi, u32 arg1, u8 *arg2) {
  u8 fr[0x90];
  __builtin_memset(fr, 0xcc, sizeof fr);
#define EBP (fr + 0x88)
#define P(off) (EBP - (off))
  u16 bx = (u16)arg1;
  u8 *esi = arg2;
  W32(P(0x7c), 0);
  W32(P(0x78), 0);
  W32(P(0x80), 0);
  const u16 mA = MSG(0x6ff99c), mB = MSG(0x6ff9a4), mC = MSG(0x6ff9a8), mD = MSG(0x6ff9b0), mE = MSG(0x6ff9ac),
            mF = MSG(0x6ff9bc), mG = MSG(0x6ff9a0), mH = MSG(0x6ff9b4), mI = MSG(0x6ff9b8);
  if (bx != mA && (bx == mB || bx == mC || bx == mD || bx == mE || bx == mF || bx == mG)) {
    W32(P(0x78), 0);
    vcall<u32>(esi, 0x88, 0x688a30u, P(0x78));
    u32 id = R32(P(0x78));
    W32(P(0x7c), id);
    u8 *T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
    u8 *obj = (u8 *)vcall<u32>(T, 0x58, id);
    W32(P(0x78), (u32)obj);
    if (obj) W32(P(0x80), vcall<u32>(obj, 0x2e8));
    if (bx == mD) vcall<u32>(esi, 0x4c, 0x689834u, 1u);
  }
  if (bx == mB) {
    vcall<u32>(edi, 0x488, R32(P(0x78)));
    goto done;
  }
  if (bx == mG) {
    vcall<u32>(edi, 0x48c, R32(P(0x78)));
    goto done;
  }
  if (bx == mC) {
    W32(P(0x80), 0);
    vcall<u32>(esi, 0x88, 0x68983cu, P(0x80));
    u8 *o = (u8 *)R32(P(0x80));
    W32(P(0x7c), 0);
    vcall<u32>(esi, 0x88, 0x689844u, P(0x7c));
    if (!o) goto done;
    if (vcall<u32>(o, 0x14) == 0) goto done;
    W32(P(0x78), vcall<u32>(o, 0x30, 0u));
    u32 s2 = 0;
    if (vcall<u32>(o, 0x14) == 2) s2 = vcall<u32>(o, 0x30, 1u);
    if (R32(P(0x7c)) == 2) {
      if (s2) vcall<u32>(edi, 0x484, R32(P(0x78)), s2);
      else vcall<u32>(edi, 0x47c, R32(P(0x78)));
    } else {
      vcall<u32>(edi, 0x480, R32(P(0x78)));
    }
    goto done;
  }
  if (bx == mH) vcall<u32>(edi, 0x448, (u32)esi);
  else if (bx == mI) vcall<u32>(edi, 0x44c, (u32)esi);
  if (bx == mE || bx == mD) {
    u8 *o80 = (u8 *)R32(P(0x80));
    if (vcall<u32>(o80, 0x300) != 0) {
      u8 *e = (u8 *)R32(P(0x78));
      vcall<u32>(e, 0x2e0, P(0x70), P(0x28));
      vcall<u32>(e, 0x98, P(0x70), P(0x28));
      u32 r = vcall<u32>(edi, 0x3a8, P(0x4c), P(0x1c));
      vcall<u32>(edi, 0x390, r);
      vcall<u32>(edi, 0x98, P(0x4c), P(0x1c));
      vcall<u32>(edi, 0x80, P(0x4c), P(0x10));
      ext_43e920(P(0x10), P(0x28), P(0x1c));
      ext_441a60(P(0x10), P(0x4c));
      float y = RF(P(0xc));
      if (y > G(float, 0x689d24) && G(float, 0x67da2c) > y) {
        WF(P(0xc), 0.0f);
        bool skip = false;
        if (bx == mD) {
          float x = RF(P(0x10)), z = RF(P(8));
          float sum = x * x + 0.0f;
          sum = sum + z * z;
          if (G(float, 0x689d20) > sum) {
            vcall<u32>(arg2, 0x4c, 0x689834u, 0u);
            skip = true;
          }
        }
        if (!skip) {
          u32 k = vcall<u32>(edi, 0x478, R32(P(0x78)));
          u32 v7c = R32(P(0x7c));
          if (k == 6) {
            vcall<u32>(edi, 0x45c, 4u, v7c);
            vcall<u32>(edi, 0x45c, 0xbu, 0u);
          } else if (k == 1) {
            vcall<u32>(edi, 0x45c, 3u, v7c);
          } else if (k == 2) {
            vcall<u32>(edi, 0x45c, 4u, v7c);
          } else if (k == 3) {
            if (RF(P(0x10)) > 0.0f) vcall<u32>(edi, 0x45c, 3u, v7c);
            else vcall<u32>(edi, 0x45c, 4u, v7c);
          } else if (k == 4) {
            u32 s = vcall<u32>(edi, 0x500);
            if (s) vcall<u32>(edi, 0x45c, 5u, 0u);
            vcall<u32>(edi, 0x45c, 3u, v7c);
            vcall<u32>(edi, 0x45c, 5u, 0u);
            if (s) {
              u8 *T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
              u32 t = vcall<u32>(T, 0x4c, s);
              vcall<u32>(edi, 0x45c, 7u, t);
            }
          } else if (k == 5) {
            u32 s = vcall<u32>(edi, 0x504);
            if (s) vcall<u32>(edi, 0x45c, 6u, 0u);
            vcall<u32>(edi, 0x45c, 4u, v7c);
            vcall<u32>(edi, 0x45c, 6u, 0u);
            if (s) {
              u8 *T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
              u32 t = vcall<u32>(T, 0x4c, s);
              vcall<u32>(edi, 0x45c, 8u, t);
            }
          }
        }
      }
    }
  }
  if (bx == R16(edi + 0x167) && R32(edi + 0x169) == (u32)arg2) {
    if (vcall<u32>(edi, 0x500) != 0) {
      u8 *o = (u8 *)vcall<u32>(edi, 0x500);
      vcall<u32>(o, 0xbc, 0u);
    }
  }
  if (bx == mF) vcall<u32>(edi, 0x4ec, R32(P(0x78)));
  if (R32(P(0x80)) == 0) ext_45d380(edi, arg1, (u32)arg2);
done:;
}
extern "C" u32 THISCALL fn_472ae0(u8 *self, u32 arg1, u8 *arg2);
extern "C" u32 THISCALL fn_472ae0(u8 *self, u32 arg1, u8 *arg2) {
  body_472ae0(self, arg1, arg2);
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(472ae0, fn_472ae0);
