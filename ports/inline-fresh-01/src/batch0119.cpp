// batch0119.cpp - fresh-01 batch 19 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void *ext_634d22(void *d, const void *s, u32 n);          // memcpy thunk
extern "C" void *ext_634d10(void *d, s32 v, u32 n);                  // memset thunk
extern "C" void *ext_41e290(u32 size);                               // operator new
extern "C" u8 *THISCALL ext_4ccdd0(void *p, u32 a, u32 size, u32 n); // ZOffsetAlloc::ZOffsetAlloc
extern "C" s32 THISCALL ext_4cd9b0(void *a, u32 size, u32 flag);     // ZOffsetAlloc::Alloc(unsigned, bool)

typedef void (*handlerFn)();
typedef u32 (STDCALL *checkFn)(u32, const u8 *, u32);
typedef void (*log2Fn)(void *, u32);
typedef void (*log4Fn)(void *, u32, u32, u32);

// 0x6331d0, inflate_flush (zlib 1.1 infutil.c, cdecl): copies as much as possible from the sliding window (s: window
// +0x28, end +0x2c, read +0x30, write +0x34, checkfn +0x38, check +0x3c) to the output (z: next_out +0xc, avail_out
// +0x10, total_out +0x14, adler +0x30), wrapping once at the window end; Z_BUF_ERROR becomes Z_OK when anything was
// copied. checkfn is stdcall: the exe does not clean up after it and pops ebx/esi/edi before restoring esp.
static s32 inflateFlush(u8 *s, u8 *z, s32 r) {
  u8 *p = *(u8 **)(z + 0xc);
  u8 *q = *(u8 **)(s + 0x30);
  u32 n = (u32)((q <= *(u8 **)(s + 0x34) ? *(u8 **)(s + 0x34) : *(u8 **)(s + 0x2c)) - q);
  if (n > *(u32 *)(z + 0x10)) n = *(u32 *)(z + 0x10);
  if (n && r == -5) r = 0;
  *(u32 *)(z + 0x10) -= n;
  *(u32 *)(z + 0x14) += n;
  if (*(checkFn *)(s + 0x38)) {
    u32 c = (*(checkFn *)(s + 0x38))(*(u32 *)(s + 0x3c), q, n);
    *(u32 *)(s + 0x3c) = c;
    *(u32 *)(z + 0x30) = c;
  }
  ext_634d22(p, q, n);
  p += n;
  q += n;
  if (q == *(u8 **)(s + 0x2c)) {
    q = *(u8 **)(s + 0x28);
    if (*(u8 **)(s + 0x34) == *(u8 **)(s + 0x2c)) *(u8 **)(s + 0x34) = q;
    n = (u32)(*(u8 **)(s + 0x34) - q);
    if (n > *(u32 *)(z + 0x10)) n = *(u32 *)(z + 0x10);
    if (n && r == -5) r = 0;
    *(u32 *)(z + 0x14) += n;
    *(u32 *)(z + 0x10) -= n;
    if (*(checkFn *)(s + 0x38)) {
      u32 c = (*(checkFn *)(s + 0x38))(*(u32 *)(s + 0x3c), q, n);
      *(u32 *)(s + 0x3c) = c;
      *(u32 *)(z + 0x30) = c;
    }
    ext_634d22(p, q, n);
    p += n;
    q += n;
  }
  *(u8 **)(z + 0xc) = p;
  *(u8 **)(s + 0x30) = q;
  return r;
}
PCREG(6331d0, inflateFlush);

// 0x495fd0, ZGeomBuffer::AllocResourceGeom(const char*, unsigned int, unsigned int): finds resource `a` in the
// +0x48 entries at +0x40 (12 bytes: key, first, count; u8 index), then sub-entry `b` among its count 8-byte entries
// {key, free} at +0x44 + 8 * first (not found: log 0x68e36c:0xb18, 0); a sub-entry with no free slot logs
// 0x68e36c:0xb1e. Else takes one slot, g = slot 0xc(), slot 0(name, b, g), g+0x59 = index + 1; returns g.
static u8 *THISCALL geomBufferAllocResource(u8 *self, u32 name, u32 a, u32 b) {
  u32 cnt = *(u32 *)(self + 0x48);
  if (!cnt) return 0;
  u32 *tbl = *(u32 **)(self + 0x40);
  u8 i = 0;
  while (tbl[(u32)i * 3] != a) {
    i++;
    if ((u32)i == cnt) return 0;
  }
  u32 *ent = &tbl[(u32)i * 3];
  u32 *sub = (u32 *)(*(u32 *)(self + 0x44) + ent[1] * 8);
  u32 k = ent[2];
  u32 j = 0;
  if (k) {
    for (; j != k; j++, sub += 2) {
      if (sub[0] == b) break;
    }
  }
  if (j == k) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x68e36cu, 0xb18u);
    (*(log4Fn *)(*(u8 **)lg + 0x2c))(lg, 0x68e530, b, a);
    return 0;
  }
  if (sub[1] == 0) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x68e36cu, 0xb1eu);
    (*(log4Fn *)(*(u8 **)lg + 0x2c))(lg, 0x68e568, a, name);
    return 0;
  }
  sub[1]--;
  u8 *g = vcall<u8 *>(self, 0xc);
  vcall<void>(self, 0, name, b, g);
  g[0x59] = i + 1;
  return g;
}
PCREG(495fd0, geomBufferAllocResource);

// 0x42bf90, ZSysInterface::AllocString(unsigned short): on first use makes the 0xa000-byte string pool (+0x1b55,
// cleared) and its ZOffsetAlloc(0, 0xa000, 0x800) (+0x1b51; 0 when new fails); allocates (len + 4) & 0xfffe bytes
// (failure: log 0x6799ac:0x120 and the handler / int3), writes the size word in front and a 0x5a guard byte at the
// end; returns the text pointer (block + 2).
static u8 *THISCALL sysAllocString(u8 *self, u32 len) {
  if (*(u32 *)(self + 0x1b55) == 0) {
    void *buf = ext_41e290(0xa000);
    *(void **)(self + 0x1b55) = buf;
    ext_634d10(buf, 0, 0xa000);
    void *p = ext_41e290(0x10);
    *(u8 **)(self + 0x1b51) = p ? ext_4ccdd0(p, 0, 0xa000, 0x800) : 0;
  }
  u32 size = (len + 4) & 0xfffe;
  s32 off = ext_4cd9b0(*(void **)(self + 0x1b51), size, 1);
  if (off < 0) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6799acu, 0x120u);
    (*(log2Fn *)(*(u8 **)lg + 0x2c))(lg, 0x6799d8);
    handlerFn h = G(handlerFn, 0x7003b0);
    if (!h) __builtin_debugtrap();
    else h();
  }
  u8 *blk = *(u8 **)(self + 0x1b55) + off;
  blk[size - 1] = 0x5a;
  *(u16 *)blk = (u16)size;
  return blk + 2;
}
PCREG(42bf90, sysAllocString);
