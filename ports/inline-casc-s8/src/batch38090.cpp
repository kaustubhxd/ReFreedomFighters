// batch38090.cpp - cascade s8 batch 38090: 0x405ca0 (Vorbis codebook header parser).
#include "ff.h"

extern "C" int ext_410de0(u8 *bs, int nbits);       // read nbits bits (cdecl)
extern "C" int ext_405090(int v);                    // ilog
extern "C" u8 *ext_634d58(u32 size);                 // malloc
extern "C" int ext_4053f0(u8 *book);                 // quantvals (maptype 1)
extern "C" void ext_4055a0(u8 *book);                // clear / free book
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))

static int fail(u8 *book) {
  ext_4055a0(book);
  return -1;
}

// 0x405ca0, cdecl(bitstream, book) -> 0 ok / -1 error. book: +0 dim, +4 entries, +8 lengths, +0xc maptype, +0x10 / +0x14 min / delta, +0x18 value bits, +0x1c sequence flag, +0x20 quantised values, +0x30 = 1.
static int fn405ca0(u8 *bs, u8 *book) {
  for (int i = 0; i < 13; i++) W(book, 4 * i) = 0;
  W(book, 0x30) = 1;
  if (ext_410de0(bs, 0x18) != 0x564342) return fail(book);
  W(book, 0) = ext_410de0(bs, 0x10);
  int entries = ext_410de0(bs, 0x18);
  W(book, 4) = entries;
  if (entries == -1) return fail(book);
  int ordered = ext_410de0(bs, 1);
  if (ordered == 1) {
    int len = ext_410de0(bs, 5);
    int ebp = len + 1;
    u32 *lengths = (u32 *)ext_634d58(W(book, 4) << 2);
    W(book, 8) = (u32)lengths;
    int edi = 0;
    if ((int)W(book, 4) > 0) {
      do {
        int n = ext_410de0(bs, ext_405090((int)W(book, 4) - edi));
        if (n == -1) return fail(book);
        int ecx = 0;
        if (n > 0 && edi < (int)W(book, 4)) {
          do {
            ecx++;
            lengths[edi] = ebp;
            edi++;
          } while (ecx < n && edi < (int)W(book, 4));
        }
        ebp++;
      } while (edi < (int)W(book, 4));
    }
  } else if (ordered == 0) {
    u32 *lengths = (u32 *)ext_634d58(W(book, 4) << 2);
    W(book, 8) = (u32)lengths;
    int sparse = ext_410de0(bs, 1);
    if (sparse) {
      if ((int)W(book, 4) > 0) {
        int edi = 0;
        do {
          if (ext_410de0(bs, 1)) {
            int v = ext_410de0(bs, 5);
            if (v == -1) return fail(book);
            ((u32 *)W(book, 8))[edi] = v + 1;
          } else {
            ((u32 *)W(book, 8))[edi] = 0;
          }
          edi++;
        } while (edi < (int)W(book, 4));
      }
    } else if ((int)W(book, 4) > 0) {
      int edi = 0;
      do {
        int v = ext_410de0(bs, 5);
        if (v == -1) return fail(book);
        ((u32 *)W(book, 8))[edi] = v + 1;
        edi++;
      } while (edi < (int)W(book, 4));
    }
  } else {
    return -1;
  }
  int mt = ext_410de0(bs, 4);
  W(book, 0xc) = mt;
  if (mt == 0) return 0;
  if (mt <= 0) return fail(book);
  if (mt > 2) return fail(book);
  W(book, 0x10) = ext_410de0(bs, 0x20);
  W(book, 0x14) = ext_410de0(bs, 0x20);
  W(book, 0x18) = ext_410de0(bs, 4) + 1;
  W(book, 0x1c) = ext_410de0(bs, 1);
  int edi = 0;
  if (mt == 1) edi = ext_4053f0(book);
  else if (mt == 2) edi = (int)W(book, 0) * (int)W(book, 4);
  u32 size = (u32)edi * 4;
  u32 *vals = (u32 *)ext_634d58(size);
  W(book, 0x20) = (u32)vals;
  int ebp = 0;
  if (edi > 0) {
    do {
      vals[ebp] = ext_410de0(bs, (int)W(book, 0x18));
      ebp++;
    } while (ebp < edi);
  }
  if (edi == 0) return 0;
  if (*(int *)((u8 *)W(book, 0x20) + size - 4) == -1) return fail(book);
  return 0;
}
PCREG(405ca0, fn405ca0);
