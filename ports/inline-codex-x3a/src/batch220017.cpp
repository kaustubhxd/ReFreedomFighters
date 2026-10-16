// batch220017.cpp - Codex-x3a manual port of ZGeomBuffer::AllocResourceGeom.
#include "ff.h"

typedef void (*log4_495fd0)(void *, u32, u32, u32);

// 0x495fd0 ZGeomBuffer::AllocResourceGeom(this, name, resource, variant),
// thiscall ret 12.  The outer table has 12-byte records {resource, first,
// count}; the inner table has 8-byte {variant, free_count} records.
extern "C" u8 *THISCALL lifted_495fd0(u8 *self, u32 name, u32 resource, u32 variant) {
  u32 count = *(u32 *)(self + 0x48);
  if (!count) return 0;  // @empty_495fd0
  u32 *table = *(u32 **)(self + 0x40);
  u8 i = 0;
  while (table[(u32)i * 3] != resource) {  // @find_outer_495fd0
    ++i;
    if ((u32)i == count) return 0;  // @outer_end_495fd0
  }

  u32 *entry = table + (u32)i * 3;
  u32 *sub = (u32 *)(*(u32 *)(self + 0x44) + entry[1] * 8);  // @sub_base_495fd0
  u32 sub_count = entry[2];
  u32 j = 0;
  while (j != sub_count && sub[0] != variant) {
    ++j;
    sub += 2;
  }
  if (j == sub_count) {  // @sub_miss_495fd0
    u8 *log = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x68e36cu, 0xb18u);
    (*(log4_495fd0 *)(*(u8 **)log + 0x2c))(log, 0x68e530u, variant, resource);
    return 0;
  }
  if (sub[1] == 0) {  // @free_empty_495fd0
    u8 *log = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x68e36cu, 0xb1eu);
    (*(log4_495fd0 *)(*(u8 **)log + 0x2c))(log, 0x68e568u, resource, name);
    return 0;
  }

  sub[1]--;  // @take_free_495fd0
  u8 *geom = vcall<u8 *>(self, 0x0c);
  vcall<void>(self, 0, name, variant, geom);  // @init_geom_495fd0
  geom[0x59] = i + 1;  // @outer_index_495fd0
  return geom;
}
PCREG(495fd0, lifted_495fd0);
