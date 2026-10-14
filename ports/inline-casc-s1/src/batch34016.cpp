// batch34016.cpp - cascade tier E, batch 34016: 0x499de0 (lazy chunk allocation + append), 0x4f5860 (validate and read through a stream object),
// 0x4eb080 (copy three floats and run three fastcall vector helpers).
#include "ff.h"

extern "C" u32 THISCALL ext_4cd9b0(void *pool, u32 size, u32 flag);           // thiscall ret 8
extern "C" u32 ext_41e290(u32 size);                                           // cdecl alloc
extern "C" void THISCALL ext_499e60(void *chunk, u32 pos, u32 a, u32 b);       // thiscall ret 0xc
extern "C" bool THISCALL ext_4f05d0(void *self, void *stream);                 // thiscall ret 4, bool in al
extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *arg);          // fastcall, 1 stack arg
extern "C" void FASTCALL ext_441a60(void *ecx, void *edx);                     // fastcall, no stack args
extern "C" void FASTCALL ext_459fc0(void *ecx, void *edx, void *arg);          // fastcall, 1 stack arg

// 0x499de0, thiscall(a, n) ret 8: when [this] (current chunk) is null, allocate one (0x1394 bytes through the pool at [[this+0xc]+4] with its size
// word, else 0x1390 through 0x41e290), link it ([0] = 0, [4] = [this+0xc]); then 0x499e60(chunk, [this+8], a, n); [this+8] += n; [this+4] = max([this+4], [this+8]).
static u32 THISCALL fn499de0(u8 *self, u32 a, u32 n) {
  if (*(u32 *)self == 0) {
    u8 *p = *(u8 **)(self + 0xc);
    void *pool = *(void **)(p + 4);
    u32 *blk;
    if (pool) {
      blk = (u32 *)ext_4cd9b0(pool, 0x1394, 1);
      *blk = 0x1394;
      blk += 1;
    } else {
      blk = (u32 *)ext_41e290(0x1390);
    }
    void *owner = *(void **)(self + 0xc);
    *(u32 **)self = blk;
    if (blk) {
      blk[0] = 0;
      blk[1] = (u32)owner;
    }
  }
  ext_499e60(*(void **)self, *(u32 *)(self + 8), a, n);
  *(u32 *)(self + 8) += n;
  u32 pos = *(u32 *)(self + 8);
  if (*(u32 *)(self + 4) < pos) *(u32 *)(self + 4) = pos;
  return pos;
}
PCREG(499de0, fn499de0);

// 0x4f5860, thiscall(stream) ret 4: when 0x4f05d0(this, stream) is true, read two dwords into +0xbb / +0xbf (stream slot 0x48), 0x24 bytes into +0x93
// (slot 0x18), then this slots 0x244 and 0x27c; returns true, else false.
static bool THISCALL fn4f5860(u8 *self, u8 *stream) {
  if (!ext_4f05d0(self, stream)) return false;
  vcall<void>(stream, 0x48, (u32)(self + 0xbb));
  vcall<void>(stream, 0x48, (u32)(self + 0xbf));
  vcall<void>(stream, 0x18, (u32)(self + 0x93), 0x24u);
  vcall<void>(self, 0x244);
  vcall<void>(self, 0x27c);
  return true;
}
PCREG(4f5860, fn4f5860);

// 0x4eb080, thiscall(a, b, c) ret 0xc: flag byte +0xa4 = 1, copy three dwords of *c into +0x98..+0xa0, then three fastcall helpers.
static void THISCALL fn4eb080(u8 *self, u8 *a, u32 b, u32 *c) {
  self[0xa4] = 1;
  *(u32 *)(self + 0x98) = c[0];
  *(u32 *)(self + 0x9c) = c[1];
  *(u32 *)(self + 0xa0) = c[2];
  ext_43e920(self + 0x8c, (void *)b, self + 0x3c);
  u8 *edi = self + 0x18;
  ext_441a60(self + 0x8c, edi);
  ext_459fc0(self + 0x80, a + 0x18, edi);
  ext_459fc0(self + 0x74, a + 0xc, edi);
  ext_459fc0(self + 0x68, a, edi);
}
PCREG(4eb080, fn4eb080);
