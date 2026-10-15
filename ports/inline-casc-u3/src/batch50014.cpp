// batch50014.cpp - cascade u3, tier H, batch 50014: 0x467d00 (pick a direction-name string from a facing vector and apply it, logging when unavailable).
#include "ff.h"

extern "C" float THISCALL ext_44c840(float *v);            // normalises v, returns the length in st0 (here discarded)
extern "C" void FASTCALL ext_633654(u32 cookie);           // /GS check
typedef int (*CDECL_LOG)(void *self, u32 fmt, u32 a, u32 b) __attribute__((cdecl));

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x467d00, thiscall() void, /GS (unaligned dwords [+0x136], [+0x1a6]): needs [+0x136] & 0x200000 and an id [+0x1a6]; w = table slot 0x58(id) (table = [[0x70039c]+0x9b]), none -> end;
// this slot 0x324(0) true and this slot 0x320(0) & 0x200 clear -> end. v = (0,0,0): w slot 0x84(&v), this slot 0x8c(&v), v.y = 0, ext_44c840(&v). With z' = -v.z: z' < -0.5 (0x67a6b0): str = 0x685f74 / 0x685f88,
// else 0.5 (0x67a6ac) > z': 0x685fa0 / 0x685fb4, else end; the second string of the pair is chosen when !(0 > -v.x). r = this slot 0x21c(str): non-zero -> this slot 0x230(r, 1); else a log message through
// [0x700390] slot 0x20(0x685ee0, 0x2d4) -> L: L slot 0x30 (cdecl)(L, 0x685fc8, name = [this slot 0x20()+4] or 0x67c8e8, str).
static void THISCALL fn467d00(u8 *self) {
  if (!(rd32(self + 0x136) & 0x200000)) { ext_633654(0); return; }
  u32 id = rd32(self + 0x1a6);
  if (!id) { ext_633654(0); return; }
  u8 *tab = (u8 *)rd32(G(u8 *, 0x70039c) + 0x9b);
  u8 *w = vcall<u8 *>(tab, 0x58, id);
  if (!w) { ext_633654(0); return; }
  if (vcall<u8>(self, 0x324, 0)) {
    if (!(vcall<u32>(self, 0x320, 0) & 0x200)) { ext_633654(0); return; }
  }
  float v[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(w, 0x84, (u32)v);
  vcall<void>(self, 0x8c, (u32)v);
  v[1] = 0.0f;
  ext_44c840(v);
  float z = bitsf(fbits(v[2]) ^ G(u32, 0x67af40));
  u32 a, b;
  if (G(float, 0x67a6b0) > z) {
    a = 0x685f74;
    b = 0x685f88;
  } else if (G(float, 0x67a6ac) > z) {
    a = 0x685fa0;
    b = 0x685fb4;
  } else {
    ext_633654(0);
    return;
  }
  float x = bitsf(fbits(v[0]) ^ G(u32, 0x67af40));
  u32 str = (0.0f > x) ? a : b;
  u32 r = vcall<u32>(self, 0x21c, str);
  if (r) {
    vcall<void>(self, 0x230, r, 1);
  } else {
    u8 *L = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x685ee0, 0x2d4);
    u8 *q = vcall<u8 *>(self, 0x20);
    u32 name = rd32(q + 4);
    if (!name) name = 0x67c8e8;
    (*(CDECL_LOG *)(*(u8 **)L + 0x30))(L, 0x685fc8, name, str);
  }
  ext_633654(0);
}
PCREG(467d00, fn467d00);
