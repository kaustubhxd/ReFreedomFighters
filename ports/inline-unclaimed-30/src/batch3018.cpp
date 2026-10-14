// batch3018.cpp - unclaimed-30: batch 18 (docs/20-unclaimed-30.md, claim 1). Unnamed in the name map: 0x58a8d0 [fastcall (this in ecx,
// out in edx), no stack arguments, returns this]. The object's slot 0x48 gives a count n; for each entry: slot 0x40 gives a handle h,
// the message table's slot 0x58 turns h into an object m, slot 0x6c gives a vector v0, slot 0x50 a float, slot 0x50 a float, slot 0x48 a
// float, slot 0x50 a float, slot 0x6c a vector v1, slot 0x48 a float. The out array gets a 48-byte record at 4 + 48 * count: m, v0,
// the four floats, v1 and the last float; the count goes up by one. (Local layout, per the exe's stack, is kept by the copies.)
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }


static u8 *FASTCALL unnamed58a8d0(u8 *self, u8 *out) {
  u32 n = 0;
  vcall<void>(self, 0x48, &n);
  for (u32 i = 0; (int)i < (int)n; i++) {
    u32 h = 0;
    vcall<void>(self, 0x40, &h);
    u8 *eng = G(u8 *, 0x70039c);
    u8 *msg = *(u8 **)(eng + 0x9b);
    u32 m = vcall<u32>(msg, 0x58, h);
    float v0[3];
    vcall<void>(self, 0x6c, v0);
    float f24 = 0, f20 = 0, f1c = 0, f18 = 0;
    vcall<void>(self, 0x50, &f24);
    vcall<void>(self, 0x50, &f20);
    vcall<void>(self, 0x48, &f1c);
    vcall<void>(self, 0x50, &f18);
    float v1[3];
    vcall<void>(self, 0x6c, v1);
    float f8 = 0;
    vcall<void>(self, 0x48, &f8);
    u32 cnt = rd32u(out);
    u8 *rec = out + 48 * cnt;     // the exe stores at rec + 4 (the count is the first dword of out)
    wr32u(rec + 4, m);
    *(float *)(rec + 8) = v0[0];
    *(float *)(rec + 0xc) = v0[1];
    *(float *)(rec + 0x10) = v0[2];
    *(float *)(rec + 0x14) = f24;
    *(float *)(rec + 0x18) = f20;
    *(float *)(rec + 0x1c) = f1c;
    *(float *)(rec + 0x20) = f18;
    *(float *)(rec + 0x24) = v1[0];
    *(float *)(rec + 0x28) = v1[1];
    *(float *)(rec + 0x2c) = v1[2];
    *(float *)(rec + 0x30) = f8;
    wr32u(out, cnt + 1);
  }
  return self;
}
PCREG(58a8d0, unnamed58a8d0);
