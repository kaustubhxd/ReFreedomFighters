// batch36064.cpp - cascade s4 batch 36064: 0x62fb30, 0x6015c0, 0x442c30 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32 (*cmp_t)(u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

// 0x62fb30, stdcall(crc, buf, len) ret 0xc: buf == 0 -> 0. c = ~crc; for each byte: c = table[(c ^ byte) & 0xff] ^ (c >> 8) (table of 256 dwords at 0x6c0338); return ~c.
static u32 STDCALL fn62fb30(u32 crc, const u8 *buf, u32 len) {
  if (!buf) return 0;
  const u32 *tab = (const u32 *)0x6c0338;
  u32 c = ~crc;
  while (len) {
    c = tab[(u8)(c ^ *buf)] ^ (c >> 8);
    buf++;
    len--;
  }
  return ~c;
}
PCREG(62fb30, fn62fb30);

// 0x6015c0, thiscall(name) ret 4 returns eax (this = d): for i < d[0xc]: rec = **(d[4] + i * 4); rec[0] == 2 and _stricmp(rec[0xc], name) == 0 -> return *(u32 *)rec[4]. Otherwise 0.
static u32 THISCALL fn6015c0(u8 *d, u32 name) {
  if (rd(d + 0xc) == 0) return 0;
  u32 i = 0;
  do {
    u8 *rec = **(u8 ***)(*(u8 **)(d + 4) + i * 4);
    if (rd(rec) == 2) {
      if (G(cmp_t, 0x676414)(rd(rec + 0xc), name) == 0) return rd(*(u8 **)(rec + 4));
    }
    i++;
  } while (i < rd(d + 0xc));
  return 0;
}
PCREG(6015c0, fn6015c0);

extern "C" void THISCALL ext_43f900(void *self, void *a);          // ret 4
extern "C" u32 THISCALL ext_4e1600(void *a);                       // plain ret, low byte = kind
extern "C" void THISCALL ext_4e11e0(void *a, u32 *p, u32 f);       // ret 8
extern "C" void THISCALL ext_4e1b30(void *a);                      // plain ret

// 0x442c30, thiscall(a) ret 4 (this = d): 0x43f900(d, a); kind(a) == 3: l4 = v = l8 = 0; 0x4e11e0(a, &l4, 1); kind == 3 -> 0x4e11e0(a, &v, 1); kind == 3 -> 0x4e11e0(a, &l8, 1);
// w = (u8)d->slot 0x1e0(0x100021) ? 1 : v; d->slot 0x304(l4 != 0); d->slot 0x300(w != 0); d->slot 0x2c4(l8 != 0). Finally 0x4e1b30(a).
static void THISCALL fn442c30(u8 *d, u8 *a) {
  ext_43f900(d, a);
  if ((u8)ext_4e1600(a) == 3) {
    u32 l4 = 0, v = 0, l8 = 0;
    ext_4e11e0(a, &l4, 1);
    if ((u8)ext_4e1600(a) == 3) ext_4e11e0(a, &v, 1);
    if ((u8)ext_4e1600(a) == 3) ext_4e11e0(a, &l8, 1);
    u32 w = v;
    if ((u8)(*(v1r_t **)d)[0x1e0 / 4](d, 0x100021u)) w = 1;
    (*(v1_t **)d)[0x304 / 4](d, l4 != 0);
    (*(v1_t **)d)[0x300 / 4](d, w != 0);
    (*(v1_t **)d)[0x2c4 / 4](d, l8 != 0);
  }
  ext_4e1b30(a);
}
PCREG(442c30, fn442c30);
