// batch38006.cpp - cascade s8 batch 38006: 0x59ae60 (property getter dispatch by interned name id).
#include "ff.h"

extern "C" u32 THISCALL ext_5adeb0(u8 *self, u32 a);          // ret 4
extern "C" u32 THISCALL ext_5ae930(u8 *self, u32 *out, u32 f);   // ret 8
extern "C" u32 THISCALL ext_59b350(u8 *self, u32 a);          // ret 4
extern "C" u32 THISCALL ext_48aad0(void *p);
extern "C" u32 THISCALL ext_4db2c0(void *self, void *a, void *b);   // ret 8
extern "C" u32 THISCALL ext_5b1760(u8 *self, u32 a, u32 b, void *c, void *d);   // ret 0x10
typedef u32(THISCALL *q4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define ENG G(u8 *, 0x70039c)
#define OBJ9B (*(u8 **)(ENG + 0x9b))
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

static inline u16 name_id(u32 str, u32 line) { return (u16)SLOT(OBJ9B, 0x114, q4_t)(OBJ9B, str, 0, 0x6adc28, line); }

// 0x59ae60, thiscall(id, out) ret 8, returns 0: compares the u16 `id` with the ids the name table (engine +0x9b, slot 0x114) gives for six names and
// stores / forwards a different piece of this for the matching one. (The second case dereferences `out` even when null, like the original.)
static u32 THISCALL fn59ae60(u8 *self, u32 idarg, u32 *out) {
  u16 id = (u16)idarg;
  if (id == name_id(0x6ad354, 0x26a)) {
    *out = (u32)(self + 0x57);
  } else if (id == name_id(0x6a5c68, 0x26f)) {
    if (out == 0) {
      *(volatile u32 *)out = 0;
    } else if (out[1] != 0) {
      *out = ext_5adeb0(self + 0x57, out[1]);
    }
  } else if (id == name_id(0x6a5c58, 0x280)) {
    if (out) ext_5ae930(self + 0x57, out, 1);
  } else if (id == name_id(0x6a5c78, 0x289)) {
    *out = *(u32 *)(self + 0x411);
  } else if (id == name_id(0x6add1c, 0x290)) {
    *out = (u32)(self + 0x13298);
  } else if (id == name_id(0x6add3c, 0x295)) {
    u32 loc10;
    u8 loc34[0x24];
    u32 loc[2];
    u32 r = SLOT(OBJ9B, 0x58, v1_t)(OBJ9B, (u32)out);
    u32 ebx = ext_59b350(self, r);
    loc[0] = SLOT(OBJ9B, 0x138, v0_t)(OBJ9B);
    loc[1] = 0x681320;
    u8 *o = OBJ9B;
    u8 **esi = *(u8 ***)o;
    u32 k = ext_48aad0(loc);
    u8 *res = (u8 *)((v1_t)esi[0x58 / 4])(OBJ9B, k);
    if (res) {
      u32 w = SLOT(res, 0x20, v0_t)(res);
      ext_4db2c0(*(void **)((u8 *)w + 8), loc34, &loc10);
      ext_5b1760(self + 0xedb, (u32)(self + 0x48), ebx, &loc10, loc34);
    }
  }
  return 0;
}
PCREG(59ae60, fn59ae60);
