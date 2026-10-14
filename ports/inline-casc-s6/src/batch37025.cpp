// batch37025.cpp - cascade s6 batch 37025: 0x410560.
#include "ff.h"

extern "C" void ext_410340(u32 *p);                   // cdecl, 1 arg: checksum over the page, stores it at +0x16
extern "C" u8 *ext_634d3a(u8 *p, u32 c, u32 n);       // memchr-style import thunk, cdecl

// 0x410560, cdecl(ctx, out), returns the bytes consumed (hdr+payload), 0 when the data is incomplete, or minus the bytes skipped when resynchronising: Ogg-style page
// reader. ctx: +0 buffer, +8 size, +0xc position, +0x10, +0x14 header length (0 = not parsed yet), +0x18 payload length. A page starts with the 4-byte signature at
// [0x6f282c]; its byte +0x1a counts the segment bytes that follow the 0x1b-byte header (their sum is the payload). When the whole page is present its checksum
// (0x410340 fills +0x16, which must come out equal to the stored value) is verified; on success out (when not null) gets {page, hdr, page+hdr, payload} and the position
// advances; otherwise the position moves to the next 'O' (0x4f) after the current byte.
static s32 fn410560(u8 *ctx, u32 *out) {
  u32 pos = *(u32 *)(ctx + 0xc);
  u8 *page = (u8 *)(*(u32 *)ctx + pos);
  s32 avail = (s32)(*(u32 *)(ctx + 8) - pos);
  if (*(u32 *)(ctx + 0x14) == 0) {
    if (avail < 0x1b) return 0;
    if (*(u32 *)page == *(u32 *)0x6f282c) {
      u32 nseg = page[0x1a];
      u32 hdr = nseg + 0x1b;
      if (avail < (s32)hdr) return 0;
      for (u32 i = 0; (s32)nseg > 0 && i < (u32)page[0x1a];) {
        *(u32 *)(ctx + 0x18) += page[0x1b + i];
        i++;
        nseg = page[0x1a];
      }
      *(u32 *)(ctx + 0x14) = hdr;
      goto parsed;
    }
    goto resync;
  }
parsed:
  if ((s32)(*(u32 *)(ctx + 0x14) + *(u32 *)(ctx + 0x18)) > avail) return 0;
  {
    u32 old = *(u32 *)(page + 0x16);
    *(u32 *)(page + 0x16) = 0;
    u32 st[4];
    st[0] = (u32)page;
    st[1] = *(u32 *)(ctx + 0x14);
    st[2] = *(u32 *)(ctx + 0x14) + (u32)page;
    st[3] = *(u32 *)(ctx + 0x18);
    ext_410340(st);
    if (old == *(u32 *)(page + 0x16)) {
      u32 base = *(u32 *)ctx + *(u32 *)(ctx + 0xc);
      if (out) {
        out[0] = base;
        out[1] = *(u32 *)(ctx + 0x14);
        out[2] = *(u32 *)(ctx + 0x14) + base;
        out[3] = *(u32 *)(ctx + 0x18);
      }
      u32 tot = *(u32 *)(ctx + 0x14) + *(u32 *)(ctx + 0x18);
      *(u32 *)(ctx + 0x10) = 0;
      *(u32 *)(ctx + 0xc) += tot;
      *(u32 *)(ctx + 0x14) = 0;
      *(u32 *)(ctx + 0x18) = 0;
      return (s32)tot;
    }
    *(u32 *)(page + 0x16) = old;
  }
resync:
  avail--;
  *(u32 *)(ctx + 0x14) = 0;
  *(u32 *)(ctx + 0x18) = 0;
  u8 *f = ext_634d3a(page + 1, 0x4f, (u32)avail);
  if (!f) f = (u8 *)(*(u32 *)(ctx + 8) + *(u32 *)ctx);
  *(u32 *)(ctx + 0xc) = (u32)f - *(u32 *)ctx;
  return (s32)((u32)page - (u32)f);
}
PCREG(410560, fn410560);
