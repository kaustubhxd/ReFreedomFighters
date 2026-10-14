// batch38075.cpp - cascade s8 batch 38075: 0x4d7740 (zip writer: emit the central directory, two tables of 0x2a-byte entries).
#include "ff.h"

typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword
#define W16(p, off) (*(u16 *)((u8 *)(p) + (off)))

static u32 tell(u8 *self) {
  u8 *f = (u8 *)UN32(self, 0x15);
  return SLOT(f, 0xc, v1_t)(f, UN32(self, 0x11));
}

// one table: for every 0x2a-byte entry write the signature and the entry, then copy the name (length word at entry+0x18, data at the offset entry[0x26]+0x1e) after it
static void emit_table(u8 *self, u8 *name, u32 *sig, u32 base_off, u32 count_off, u32 counter_off) {
  for (u32 i = 0, off = 0; i < UN32(self, count_off); ) {
    u8 *f = (u8 *)UN32(self, 0x15);
    u32 rec = UN32(self, base_off) + off;
    if (SLOT(f, 0x18, v3_t)(f, (u32)sig, 4, UN32(self, 0x11)) != 4) self[0x6e] = 1;
    f = (u8 *)UN32(self, 0x15);
    if (SLOT(f, 0x18, v3_t)(f, rec, 0x2a, UN32(self, 0x11)) != 0x2a) self[0x6e] = 1;
    u32 pos = tell(self);
    f = (u8 *)UN32(self, 0x15);
    SLOT(f, 0x10, v3_t)(f, UN32(self, 0x11), UN32((u8 *)rec, 0x26) + 0x1e, 0);
    f = (u8 *)UN32(self, 0x15);
    SLOT(f, 0x14, v3_t)(f, (u32)name, W16((u8 *)rec, 0x18), UN32(self, 0x11));
    f = (u8 *)UN32(self, 0x15);
    SLOT(f, 0x10, v3_t)(f, UN32(self, 0x11), pos, 0);
    f = (u8 *)UN32(self, 0x15);
    if (SLOT(f, 0x18, v3_t)(f, (u32)name, W16((u8 *)rec, 0x18), UN32(self, 0x11)) != W16((u8 *)rec, 0x18)) self[0x6e] = 1;
    i++;
    W16(self, counter_off)++;
    off += 0x2a;
  }
}

// 0x4d7740, thiscall(this) void. this+0x11 handle, +0x15 file object (slots 0xc tell, 0x10 seek, 0x14 read, 0x18 write), tables: (+0x5a base, +0x56 count, word counter +0x38) and (+0x4e, +0x4a, +0x26);
// records the start (+0x40), size (+0x3c) and counts of the first table and the same for the second (+0x2e, +0x2a, +0x28).
static void THISCALL fn4d7740(u8 *self) {
  char name[0x10000];
  u32 sig = 0x2014b50;
  UN32(self, 0x40) = tell(self);
  emit_table(self, (u8 *)name, &sig, 0x5a, 0x56, 0x38);
  W16(self, 0x3a) = W16(self, 0x38);
  UN32(self, 0x3c) = tell(self) - UN32(self, 0x40);
  UN32(self, 0x2e) = tell(self);
  emit_table(self, (u8 *)name, &sig, 0x4e, 0x4a, 0x26);
  W16(self, 0x28) = W16(self, 0x26);
  UN32(self, 0x2a) = tell(self) - UN32(self, 0x2e);
}
PCREG(4d7740, fn4d7740);
