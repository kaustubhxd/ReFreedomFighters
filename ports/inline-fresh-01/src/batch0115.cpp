// batch0115.cpp - fresh-01 batch 15 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void FASTCALL ext_6383a0(u32 flag, s32 *out, s32 *a, s32 *b);  // fills a 4x4 int table (ret 8)
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie
extern "C" void THISCALL ext_63da80(u32 draw, u8 *entry);            // ZDrawBase::PrimInstanceEnter
extern "C" u32 THISCALL ext_658f50(u8 *prim);                        // ZPrimDrawEntry::GetTextureNrFrames
extern "C" u32 THISCALL ext_4e5e60(u32 *db);                         // DBREAD::operator unsigned int
extern "C" float THISCALL ext_4e5e80(u32 *db);                       // DBREAD::operator float (st0)
extern "C" u16 THISCALL ext_4e5e40(u32 *db);                         // DBREAD::operator unsigned short

typedef void (*handlerFn)();

// 0x603110, RunTimeTypeLibrary_t::serialSize(): 8 plus, for each entry of the map at +1 (packed tree: node +1 parent,
// +5 left, +9 right, null leaves, value +0x19), 0x15 + (end - begin) (+8, +4) + 4, or + slot 8(begin)+4 of the +0x1c
// object when set, + (c+0x10 + c+0x28 + c+0x1c + c+4 - c+0xc - c - c+0x24 - c+0x18 + 4) of the +0x24 block when set.
static u32 THISCALL rttlSerialSize(u8 *self) {
  u32 total = 8;
  u8 *head = *(u8 **)(self + 1);
  u8 *n = *(u8 **)(head + 5);
  while (n != *(u8 **)(self + 1)) {
    u8 *v = *(u8 **)(n + 0x19);
    u32 len = *(u32 *)(v + 8) - *(u32 *)(v + 4);
    u32 a = 4;
    u8 *o = *(u8 **)(v + 0x1c);
    if (o) a = vcall<u32>(o, 8, *(u32 *)(v + 4)) + 4;
    u32 d = a + 0x15 + len;
    u32 *c = *(u32 **)(v + 0x24);
    if (c) d += c[4] + c[10] + c[7] + c[1] - c[3] - c[0] - c[9] - c[6] + 4;
    total += d;
    u8 *r = *(u8 **)(n + 9);
    if (r) {
      n = r;
      while (*(u8 **)(n + 5)) n = *(u8 **)(n + 5);
    } else {
      u8 *p = *(u8 **)(n + 1);
      while (n == *(u8 **)(p + 9)) {
        n = p;
        p = *(u8 **)(p + 1);
      }
      if (*(u8 **)(n + 9) != p) n = p;
    }
  }
  return total;
}
PCREG(603110, rttlSerialSize);

// 0x63a390 (unnamed, fastcall + 5 stack words): smears the bits of two int triples (x | x >> 5, the second word of
// the first triple >> 6 when flag is 0, the second triple's second word always >> 6), builds a 4x4 table with
// 0x6383a0(flag, table, &a, &b), then sums the squared differences base[col + 4i] - table[col + 4 idx[i]] for
// i = 0..15, stopping once the sum is above the limit (signed). Returns the sum. /GS cookie.
static u32 FASTCALL blockError63a390(u32 flag, u32 col, s32 *p, s32 *q, s32 *base, u32 *idx, s32 limit) {
  s32 tab[16];
  s32 b[3], a[3];
  a[0] = (p[0] >> 5) | p[0];
  b[0] = (q[0] >> 5) | q[0];
  a[1] = (flag ? (p[1] >> 5) : (p[1] >> 6)) | p[1];
  b[1] = (q[1] >> 6) | q[1];
  a[2] = (p[2] >> 5) | p[2];
  b[2] = (q[2] >> 5) | q[2];
  ext_6383a0(flag, tab, a, b);
  u32 sum = 0;
  for (u32 i = 0; i < 16; i++) {
    u32 d = (u32)base[col + 4 * i] - (u32)tab[col + idx[i] * 4];
    sum += d * d;
    if ((s32)sum > limit) break;
  }
  ext_633654(G(u32, 0x6f5630));
  return sum;
}
PCREG(63a390, blockError63a390);

// 0x64d490, ZViewBase::PrimInstanceEnter(ZPrimInstViewEntry*): ZDrawBase::PrimInstanceEnter(+0x1005d, entry); the
// instance (entry+8) use count (+9, u8) goes up and its first use calls draw slot 0xa0(inst); its prim (+0x10): use
// count (+0xc, u16) up, first use -> ZDrawBase::PrimInstanceEnter(prim); the prim's texture record (table +0x10071,
// index u16 [[prim+8]+6] & 0xfff) count (+0xc) up, first use -> own slot 0x48(record); the list at +0x181c5 (count
// word, up to 0x2000, else handler / int3) gets the entry; entry+5 |= 8 when the prim has more than one frame.
static void THISCALL viewPrimInstanceEnter(u8 *self, u8 *entry) {
  ext_63da80(*(u32 *)(self + 0x1005d), entry);
  u8 *inst = *(u8 **)(entry + 8);
  u8 c = inst[9];
  inst[9] = c + 1;
  if (c == 0) vcall<void>(*(u8 **)(self + 0x1005d), 0xa0, inst);
  u8 *prim = *(u8 **)(inst + 0x10);
  if (!prim) return;
  u16 pc = *(u16 *)(prim + 0xc);
  *(u16 *)(prim + 0xc) = pc + 1;
  if (pc == 0) ext_63da80(*(u32 *)(self + 0x1005d), prim);
  u32 ti = *(u16 *)(*(u8 **)(prim + 8) + 6) & 0xfff;
  u8 *rec = (*(u8 ***)(self + 0x10071))[ti];
  u32 rc = *(u32 *)(rec + 0xc);
  *(u32 *)(rec + 0xc) = rc + 1;
  if (rc == 0) vcall<void>(self, 0x48, rec);
  u32 *list = *(u32 **)(self + 0x181c5);
  if (list) {
    if (list[0] + 1 > 0x2000) {
      handlerFn h = G(handlerFn, 0x7003b0);
      if (!h) __builtin_debugtrap();
      else h();
    }
    list[list[0] + 1] = (u32)entry;
    list[0]++;
  }
  if (ext_658f50(prim) > 1) entry[5] |= 8;
}
PCREG(64d490, viewPrimInstanceEnter);

// 0x4a4ad0, ZVertAnim::CopyEventDataBlock(DBREAD&): nothing when the reader is empty; +0x63 = uint != 0; when the next
// type byte (low 6 bits, 0xff = none) is 2: +0x5e = 0, else +0x5e = that flag and +0x63 = uint != 0; float +0x5a;
// +0x60, +0x61 = uint != 0; u16 +0x48; +0x5f = uint != 0; when the next type is 3: +0x62, +0x64 = uint != 0, uint
// +0x4e, uint +0x52 (unaligned fields).
static u8 nextType(u32 *db) { return *(u8 *)*db; }
static void THISCALL vertAnimCopyEventDataBlock(u8 *self, u32 *db) {
  if (*db == 0) return;
  u8 f = ext_4e5e60(db) != 0;
  self[0x63] = f;
  u8 t = nextType(db);
  if (t != 0xff && (t & 0x3f) == 2) {
    self[0x5e] = 0;
  } else {
    self[0x5e] = f;
    self[0x63] = ext_4e5e60(db) != 0;
  }
  float x = ext_4e5e80(db);
  __builtin_memcpy(self + 0x5a, &x, 4);
  self[0x60] = ext_4e5e60(db) != 0;
  self[0x61] = ext_4e5e60(db) != 0;
  *(u16 *)(self + 0x48) = ext_4e5e40(db);
  self[0x5f] = ext_4e5e60(db) != 0;
  t = nextType(db);
  if (t != 0xff && (t & 0x3f) == 3) {
    self[0x62] = ext_4e5e60(db) != 0;
    self[0x64] = ext_4e5e60(db) != 0;
    *(u32 *)(self + 0x4e) = ext_4e5e60(db);
    *(u32 *)(self + 0x52) = ext_4e5e60(db);
  }
}
PCREG(4a4ad0, vertAnimCopyEventDataBlock);
