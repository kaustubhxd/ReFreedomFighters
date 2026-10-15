// batch1080.cpp - ZCameraOverlay::ClassInit (0x457c30, high confidence in the class map). Camera/view thread, 2026-10-12.
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" CDECL void *ext_41e290(u32 size);   // operator new

// 0x457c30 ZCameraOverlay::ClassInit(void) (thiscall): two floats (+0x78, +0x7c) come from a record of the global manager
// (sys +0x1aa3, its +0x18 object, slot 0xf8 of the owner's +6c id); then a header of 8 bytes (+0x84: word count, word +4 the
// array) and an array of count * 0x44 bytes, each record set to zeros, 1.0 and 5.0 at fixed offsets and four 0xffffffff
// words at the end. count = +0x8c * +0x88 (32-bit); the array size saturates to 0xffffffff on overflow.
static THISCALL void ZCameraOverlay_ClassInit(u8 *self) {
  u8 *obj = at<u8 *>(self, 8);
  u32 id = at<u32>(obj, 0x6c);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *m = at<u8 *>(sys, 0x1aa3);
  u8 *sub = at<u8 *>(m, 0x18);
  u8 *rec = (u8 *)(unsigned long)vcall<u32>(sub, 0xf8, id);
  if (rec) {
    at<float>(self, 0x78) = (float)(u32)at<u16>(rec, 0x0c);
    at<float>(self, 0x7c) = (float)(u32)at<u16>(rec, 0x0e);
  }
  u32 count = at<u32>(self, 0x8c) * at<u32>(self, 0x88);
  u8 *hdr = (u8 *)ext_41e290(8);
  at<u32>(self, 0x84) = (u32)(unsigned long)hdr;
  at<u32>(hdr, 0) = count;
  at<u32>(hdr, 4) = 0;
  unsigned long long p = (unsigned long long)count * 0x44u;
  u32 size = (p >> 32) ? 0xffffffffu : (u32)p;
  u8 *arr = (u8 *)ext_41e290(size);
  at<u32>(hdr, 4) = (u32)(unsigned long)arr;
  for (u32 i = 0; i < count; i++) {
    u8 *r = arr + 0x44u * i;
    at<u32>(r, 0x00) = 0;
    at<u32>(r, 0x04) = 0;
    at<u32>(r, 0x08) = 0;
    at<u32>(r, 0x0c) = 0;
    at<u32>(r, 0x10) = 0;
    at<u32>(r, 0x14) = 0x3f800000u;   // 1.0
    at<u32>(r, 0x18) = 0;
    at<u32>(r, 0x1c) = 0x3f800000u;
    at<u32>(r, 0x20) = 0x3f800000u;
    at<u32>(r, 0x24) = 0;
    at<u32>(r, 0x28) = 0x3f800000u;
    at<u32>(r, 0x2c) = 0x40a00000u;   // 5.0
    at<u32>(r, 0x30) = 0x40a00000u;
    at<u32>(r, 0x34) = 0xffffffffu;
    at<u32>(r, 0x38) = 0xffffffffu;
    at<u32>(r, 0x3c) = 0xffffffffu;
    at<u32>(r, 0x40) = 0xffffffffu;
  }
}
PCREG(457c30, ZCameraOverlay_ClassInit);
