#include "ff.h"

typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void *ext_41e290(u32 size);  // cdecl allocator

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// cdecl log call M.vtable[0x2c](M, 0x6b620c, count) with ecx = the header pointer (this[0x24]), caller cleans 12 bytes
static inline void logcall(u8 *M, u8 *hdr, u32 count) {
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = (u32)hdr;
  asm volatile(
      "pushl %[n]\n\t"
      "pushl %[f]\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $12, %%esp"
      : "+a"(ra), "+c"(rc)
      : [n] "r"(count), [f] "r"(0x6b620c), [m] "r"(M)
      : "edx", "memory", "cc");
}

// 0x5d8a50: thiscall(), void, /GS protected. Tile grid builder: tile = this[0x2c] / this[0x30]; cols this[0x18] = ceil(W / tile) with W = [eng+0x6f]; rows this[0x1c] =
// (H + this[0x3c]) / tile, +1 when H % tile != 0 (H = [eng+0x73], the remainder test ignores this[0x3c]). Allocates cells = 0x41e290(saturating cols * rows * 0x28) in this[0x20]
// and a header {count, cells} (0x41e290(8)) in this[0x24]; a count above 0x40 is logged (log manager slot 0x20(0x6b61dc, 0x62), cdecl line 0x6b620c with ecx = header). Then every cell
// (index j * cols + i, 0x28 bytes) gets pos = (i * tile - W / 2, j * tile - H / 2), 0, 0, 1.0f, 0, 1.0f, tile, tile and the object [[eng+0x1aa3]+0x18] slot 0x130(cell + 0x24, &(1, 1, 1, this_f[0x38])).
extern "C" void THISCALL fn_5d8a50(u8 *self) {
  s32 tile = (s32)rd32u(self + 0x2c) / (s32)rd32u(self + 0x30);
  u8 *eng = G(u8 *, 0x70039c);
  s32 W = (s32)rd32u(eng + 0x6f);
  s32 cols = W / tile;
  wr32u(self + 0x18, (u32)cols);
  eng = G(u8 *, 0x70039c);
  s32 W2 = (s32)rd32u(eng + 0x6f);
  if (W2 % tile != 0) {
    wr32u(self + 0x18, (u32)(W2 / tile + 1));
    eng = G(u8 *, 0x70039c);
  }
  s32 rows = (s32)(rd32u(eng + 0x73) + rd32u(self + 0x3c)) / tile;
  wr32u(self + 0x1c, (u32)rows);
  eng = G(u8 *, 0x70039c);
  s32 H2 = (s32)rd32u(eng + 0x73);
  if (H2 % tile != 0) wr32u(self + 0x1c, (u32)(rows + 1));
  u32 total = rd32u(self + 0x18) * rd32u(self + 0x1c);
  u64 size64 = (u64)total * 0x28;
  u32 size = (size64 >> 32) ? 0xffffffffu : (u32)size64;
  wr32u(self + 0x20, (u32)ext_41e290(size));
  u8 *hdr = (u8 *)ext_41e290(8);
  wr32u(self + 0x24, (u32)hdr);
  wr32u(hdr, rd32u(self + 0x18) * rd32u(self + 0x1c));
  wr32u((u8 *)rd32u(self + 0x24) + 4, rd32u(self + 0x20));
  if (rd32u((u8 *)rd32u(self + 0x24)) > 0x40) {
    void *Lg = G(void *, 0x700390);
    u8 *M = (u8 *)(*(V2 *)(vt(Lg) + 0x20))(Lg, 0x6b61dc, 0x62);
    u8 *h2 = (u8 *)rd32u(self + 0x24);
    logcall(M, h2, rd32u(h2));
  }
  eng = G(u8 *, 0x70039c);
  float w4[4];
  w4[0] = 1.0f;
  w4[1] = 1.0f;
  w4[2] = 1.0f;
  w4[3] = rdf(self + 0x38);
  s32 We = (s32)rd32u(eng + 0x6f);
  float hw = (float)(We / 2);
  s32 He = (s32)rd32u(eng + 0x73);
  float hh = (float)(He / 2);
  if ((s32)rd32u(self + 0x18) <= 0) goto done;
  {
    u32 xi = 0;
    for (s32 i = 0; i < (s32)rd32u(self + 0x18); i++) {
      if ((s32)rd32u(self + 0x1c) > 0) {
        u32 yj = 0;
        for (s32 j = 0; j < (s32)rd32u(self + 0x1c); j++) {
          float px = (float)(s32)xi - hw;
          u8 *cells = (u8 *)rd32u(self + 0x20);
          u32 k = (rd32u(self + 0x18) * (u32)j + (u32)i);
          u8 *cell = cells + (u64)(u32)(k * 5) * 8;
          wrf(cell, px);
          wr32u(cell + 8, 0);
          wr32u(cell + 0xc, 0);
          wr32u(cell + 0x14, 0);
          wr32u(cell + 0x10, 0x3f800000);
          wr32u(cell + 0x18, 0x3f800000);
          float py = (float)(s32)yj - hh;
          wrf(cell + 0x1c, (float)tile);
          wrf(cell + 0x20, (float)tile);
          wrf(cell + 4, py);
          u8 *G1 = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3);
          u8 *Co = (u8 *)rd32u(G1 + 0x18);
          (*(V2 *)(vt(Co) + 0x130))(Co, (u32)(cell + 0x24), (u32)w4);
          yj += (u32)tile;
        }
      }
      xi += (u32)tile;
    }
  }
done:
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5d8a50, fn_5d8a50);
