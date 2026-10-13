// fb0707.cpp - fresh slice 17, batch 7.
#include "ff.h"

extern "C" u32 THISCALL ext_49c420(u8 *self, u32 off, const u32 *base);
extern "C" u32 THISCALL ext_5167d0(void *self);
extern "C" u32 THISCALL ext_59a9b0(void *vec, u32 n);
extern "C" u32 THISCALL ext_4ff9d0(void *vec);
extern "C" u32 *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" u32 THISCALL ext_4e5ef0(void *rd);       // DBREAD::operator bool() (AL)
extern "C" char *THISCALL ext_4e5ea0(void *rd);     // DBREAD::operator char*()
extern "C" void *ext_41e290(u32 size);               // __builtin_new
extern "C" u32 THISCALL ext_4dbbe0(void *e, void *rd);

typedef u32 (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

// 0x49c4d0 CListUser::ConvertOffsetsToRefs(const unsigned*): the list at this+0x1d (word count this+0x19) holds, after a
// 0x10-byte header, records of one header word (0x49c420(header, base)) followed by tagged words; bit 0 marks the last
// word of a record, bits 0-2 are kept, and a non-zero offset (word & ~7) becomes db->slot +0x54((offset + 0x60) | 0x40000000).
static void THISCALL convertOffsetsToRefs49c4d0(u8 *self, const u32 *base) {
  u32 *p = (u32 *)(*(u8 **)(self + 0x1d) + 0x10);
  while (p < (u32 *)(*(u8 **)(self + 0x1d) + *(u32 *)(self + 0x19) * 4)) {
    ext_49c420(self, *p, base);
    p++;
    u8 last;
    do {
      u32 w = *p;
      last = w & 1;
      u32 off = w & ~7u;
      if (off) {
        void *db = *(void **)(G(u8 *, 0x70039c) + 0x9b);
        *p = vcall<u32>(db, 0x54, (off + 0x60) | 0x40000000u) | (w & 7);
      }
      p++;
    } while (!last);
  }
}
PCREG(49c4d0, convertOffsetsToRefs49c4d0);

// 0x5298d0 (GUESS constructor): vtable 0x6a0bd8, members at +0x3d and +0xb6 built by 0x5167d0, +0x10 = 0, floats
// +0x29 = 200, +0x2d = -400, +0x31 = -4, +0x35 = -500, +0x39 = 500. SEH frame not reproduced. Returns this.
static u8 *THISCALL ctor5298d0(u8 *self) {
  *(u32 *)self = 0x6a0bd8;
  ext_5167d0(self + 0x3d);
  ext_5167d0(self + 0xb6);
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x35) = 0xc3fa0000u;
  *(u32 *)(self + 0x39) = 0x43fa0000u;
  *(u32 *)(self + 0x29) = 0x43480000u;
  *(u32 *)(self + 0x2d) = 0xc3c80000u;
  *(u32 *)(self + 0x31) = 0xc0800000u;
  return self;
}
PCREG(5298d0, ctor5298d0);

// 0x5577d0 and 0x603850 (OpaqueUserType_t::buildCMM()): once (while the global is 0) a local 16-byte vector object
// {0, 0, 0, owns = 1} reserves 50 entries (0x59a9b0), is filled by this->slot +0x1c(&vec) and destroyed (0x4ff9d0).
// SEH frame not reproduced. (The global is set elsewhere, presumably by the slot +0x1c call chain.)
struct LocalVec {
  u32 a, b, c;
  u8 owns;
};
static void THISCALL build5577d0(u8 *self) {
  if (G(u32, 0x713e2c) == 0) {
    LocalVec v;
    v.a = v.b = v.c = 0;
    v.owns = 1;
    ext_59a9b0(&v, 0x32);
    vcall<u32>(self, 0x1c, (void *)&v);
    ext_4ff9d0(&v);
  }
}
PCREG(5577d0, build5577d0);
static void THISCALL buildCMM603850(u8 *self) {
  if (G(u32, 0x724698) == 0) {
    LocalVec v;
    v.a = v.b = v.c = 0;
    v.owns = 1;
    ext_59a9b0(&v, 0x32);
    vcall<u32>(self, 0x1c, (void *)&v);
    ext_4ff9d0(&v);
  }
}
PCREG(603850, buildCMM603850);

// 0x560010 (GUESS, sets the active slot of the object at (*0x7003b8)+0x2c21): two ints from 0x5003d0(arg[1], 0 / 1);
// a non-negative first sets +0x54 = it with flags +0x5a = 1, +0x5b = 0; a non-negative second sets +0x54 = it with
// +0x5a = 0, +0x5b = 1 (so the second wins).
static void THISCALL setSlot560010(u8 *, u8 *arg) {
  s32 a = *(s32 *)ext_5003d0(*(void **)(arg + 4), 0);
  s32 b = *(s32 *)ext_5003d0(*(void **)(arg + 4), 1);
  if (a >= 0) {
    *(s32 *)(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c21) + 0x54) = a;
    *(u8 *)(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c21) + 0x5a) = 1;
    *(u8 *)(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c21) + 0x5b) = 0;
  }
  if (b >= 0) {
    *(s32 *)(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c21) + 0x54) = b;
    *(u8 *)(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c21) + 0x5a) = 0;
    *(u8 *)(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c21) + 0x5b) = 1;
  }
}
PCREG(560010, setSlot560010);

// 0x4ca790 ZSetZDefine::CopyEventDataBlock(DBREAD&): the next field's type byte (low 6 bits; 0xff = end) decides what is
// read: type 3 is a bool into +0x48 (else 0), then type 4 is a string copied to a new heap block at +0x49 (else 0).
static void THISCALL copyEventDataBlock4ca790(u8 *self, u8 **rd) {
  self[0x48] = 0;
  u8 t = **rd;
  if (t != 0xff && (t & 0x3f) == 3)
    self[0x48] = (u8)ext_4e5ef0(rd);
  t = **rd;
  char *s = 0;
  if (t != 0xff && (t & 0x3f) == 4)
    s = ext_4e5ea0(rd);
  *(u32 *)(self + 0x49) = 0;
  if (s) {
    u32 len = 0;
    while (s[len])
      len++;
    char *p = (char *)ext_41e290(len + 1);
    for (u32 i = 0;; i++) {
      p[i] = s[i];
      if (!s[i])
        break;
    }
    *(char **)(self + 0x49) = p;
  }
}
PCREG(4ca790, copyEventDataBlock4ca790);

// 0x498650 (GUESS load of 0x70-byte entries by index): stream slot +0xc(0xb), then indices (slot +0x18(&i, 4)) until -1;
// each entry (table this+0x14 -> +4, stride 0x70) gets slot +0xc(0xc), slot +0x34('GEOM' 0x47454f4d) and 0x4dbbe0(entry,
// stream); a false result asserts (hook at 0x7003b0, int3 when none).
static void THISCALL load498650(u8 *self, void *rd) {
  vcall<u32>(rd, 0x0c, 0xbu);
  u8 *base = *(u8 **)(*(u8 **)(self + 0x14) + 4);
  s32 i;
  vcall<u32>(rd, 0x18, (void *)&i, 4u);
  while (i != -1) {
    u8 *e = base + i * 0x70;
    vcall<u32>(rd, 0x0c, 0xcu);
    vcall<u32>(rd, 0x34, 0x47454f4du);
    if (!(u8)ext_4dbbe0(e, rd)) {
      if (!g_pAssertHook)
        __builtin_debugtrap();
      g_pAssertHook();
    }
    vcall<u32>(rd, 0x0c, 0xbu);
    vcall<u32>(rd, 0x18, (void *)&i, 4u);
  }
}
PCREG(498650, load498650);
