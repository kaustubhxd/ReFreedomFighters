// batch52002.cpp - cascade tier H, batch 52002: 0x480120 (draw/emit six scaled entries through vtable slots).
#include "ff.h"

extern "C" u32 THISCALL ext_47ff20(void *self, void *b, void *d);                       // ret 8
extern "C" u32 THISCALL ext_480640(void *self, void *b, void *d, u32 r, void *v);       // ret 0x10
extern "C" void THISCALL ext_4de7a0(void *m);                                           // fills a 3x3 identity
extern "C" void THISCALL ext_4dffb0(void *v, float f);                                  // ret 4: scales two floats
extern "C" void FASTCALL ext_633654(u32 cookie);                                        // /GS check

// 0x480120, thiscall(A, B, c, d) ret 0x10, /GS. A, B are objects with vtables, d points to a struct with a float at +8.
// If B[0x48] & 0x10000: A.slot0x88(c, d, this[8] + 0x40), then if this[0x14] & 8: A.slot0xdc(c, d, this[8] + 0x40).
// Exit when 5.0 (0x679544) > d[8] or ext_47ff20(this, B, d) is 0. Else r = ext_480640(this, B, d, r1, &v60) after B.slot0x270(&v60, d) (a 2-float vector);
// then for six entries (floats at this+0x34+12k, words at this+0x30+12k, objects at this+0x74+4k) with the float x != 0:
// v54 = (x, -x); B.slot0x274(&v10, &v54); (*[this+0x74+4k])[4] gets [+0x14] = r and [+0xc] = v10[0]; v54 = v60 scaled by (1.0 - float at this+0x30+12k) through ext_4dffb0;
// B.slot0x274(&v10, &v54); A.slot0x24(word at this+0x2c+12k, &m40, &v10, &v1c, 0x7e967699, [this+0x74+4k]).
static void THISCALL fn480120(u8 *self, u8 *A, u8 *B, u32 c, u8 *d) {
  u8 m40[0x30];
  float v10[3], v1c[3];
  u32 v60[2], v54[2];
  if (*(u32 *)(B + 0x48) & 0x10000) {
    u32 t = *(u32 *)(self + 8) + 0x40;
    vcall<void>(A, 0x88, c, (u32)d, t);
    if (self[0x14] & 8) vcall<void>(A, 0xdc, c, (u32)d, *(u32 *)(self + 8) + 0x40);
  }
  if (G(float, 0x679544) > *(float *)(d + 8)) goto done;
  {
    u32 r1 = ext_47ff20(self, B, d);
    if (!r1) goto done;
    ext_4de7a0(m40);
    vcall<void>(B, 0x270, (u32)v60, (u32)d);
    v10[0] = 0; v10[1] = 0; v10[2] = 5.0f;
    v1c[0] = 0; v1c[1] = 0; v1c[2] = 0;
    u32 r = ext_480640(self, B, d, r1, v60);
    for (int k = 0; k < 6; k++) {
      float x = *(float *)(self + 0x34 + 12 * k);
      if (x != 0.0f) {
        v54[0] = fbits(x);
        v54[1] = fbits(x) ^ G(u32, 0x67af40);
        vcall<void>(B, 0x274, (u32)v10, (u32)v54);
        u8 *o = *(u8 **)(self + 0x74 + 4 * k);
        *(u32 *)(*(u8 **)(o + 4) + 0x14) = r;
        *(float *)(*(u8 **)(*(u8 **)(self + 0x74 + 4 * k) + 4) + 0xc) = v10[0];
        float s = G(float, 0x678858) - *(float *)(self + 0x30 + 12 * k);
        v54[0] = v60[0];
        v54[1] = v60[1];
        ext_4dffb0(v54, s);
        vcall<void>(B, 0x274, (u32)v10, (u32)v54);
        vcall<void>(A, 0x24, *(u32 *)(self + 0x2c + 12 * k), (u32)m40, (u32)v10, (u32)v1c, 0x7e967699u, *(u32 *)(self + 0x74 + 4 * k));
      }
    }
  }
done:
  ext_633654(0);
}
PCREG(480120, fn480120);
