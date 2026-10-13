// batch124.cpp - a 16-byte element vector: push_back fast path (0x5acbf0) and insert-with-growth (0x5acad0). Both written
// literally from the exe: pointer arithmetic follows the assembly line by line (climb thread, batch 124).
// The vector is {begin (+0), end (+4), capacity (+8)}, elements 16 bytes. Names: GUESS (std::vector-shaped; no GC match).
#include "ff.h"

extern "C" u32 STDCALL ext_6014a0(u32 size);                       // CHostInterface::alloc (batch 123 port of it is equal)
extern "C" void STDCALL ext_54f870(u32 begin, u32 size);            // deallocator wrapper (batch 123)

static inline void copy16(u8 *dst, const u8 *src) {
  for (int q = 0; q < 16; ++q)
    dst[q] = src[q];
}

// 0x5acad0, THISCALL with two stack args (ret 8): insert the 16-byte value at pos, growing when full.
static void THISCALL vecInsertGrow(u8 *v, u8 *pos, const u8 *val) {
  u8 *end = *(u8 **)(v + 4);
  if (end != *(u8 **)(v + 8)) {
    if (end)
      copy16(end, end - 0x10);            // movups xmm0,[eax-0x10]; movups [eax],xmm0
    u8 *oldEnd = *(u8 **)(v + 4);
    u8 *ecx = oldEnd + 0x10;
    *(u8 **)(v + 4) = ecx;
    ecx = oldEnd - 0x10;                  // lea ecx,[edx+0x10]; add ecx,-0x20
    u8 xmm1[16];
    for (int q = 0; q < 16; ++q)
      xmm1[q] = val[q];                   // the value is read before the shift
    s32 n = (s32)(ecx - pos) >> 4;        // sar eax,4 of (ecx - pos)
    u8 *edx = oldEnd;
    while (n > 0) {
      copy16(edx - 0x10, ecx - 0x10);     // xmm0 = [ecx-0x10]; [edx-0x10] = xmm0
      ecx -= 0x10;
      n--;
      edx -= 0x10;
    }
    for (int q = 0; q < 16; ++q)
      pos[q] = xmm1[q];                   // movups [esi], xmm1 (esi = pos)
    return;
  }
  // grow (end == capacity)
  s32 count = (s32)(end - *(u8 **)v) >> 4;
  u32 ebx;
  u32 block = 0;
  if (count == 0) {
    ebx = 1;
  } else {
    ebx = (u32)count * 2;
    if (ebx != 0)
      block = ext_6014a0(ebx << 4);
  }
  if (count == 0)
    block = ext_6014a0(ebx << 4);         // (count == 0 path: ebx = 1)
  u8 *newBlock = (u8 *)block;
  u8 *ecx = newBlock;
  u8 *edx = *(u8 **)v;
  while (edx != pos) {                    // copy the elements before pos
    if (ecx)
      copy16(ecx, edx);
    edx += 0x10;
    ecx += 0x10;
  }
  if (ecx)
    copy16(ecx, val);                     // the new element
  u8 *esi = ecx + 0x10;
  u8 *oldEnd = *(u8 **)(v + 4);
  if (pos != oldEnd) {
    u8 *src = pos;
    while (src != oldEnd) {               // copy the elements from pos to the old end, after the new one
      if (esi)
        copy16(esi, src);
      src += 0x10;
      esi += 0x10;
    }
  }
  u32 oldBegin = *(u32 *)v;
  u32 oldCap = *(u32 *)(v + 8);
  s32 bytes = (s32)(oldCap - oldBegin) >> 4;
  if (bytes != 0)
    ext_54f870(oldBegin, (u32)bytes << 4);
  u32 newCap = (ebx << 4) + block;
  *(u8 **)(v + 4) = esi;
  *(u32 *)(v + 8) = newCap;
  *(u32 *)v = block;
}
PCREG(5acad0, vecInsertGrow);

// 0x5acbf0, THISCALL with one stack arg (ret 4): push_back of the 16-byte value at arg0.
static void THISCALL vecPushBack(u8 *v, const u8 *val) {
  u8 *end = *(u8 **)(v + 4);
  if (end == *(u8 **)(v + 8)) {
    vecInsertGrow(v, end, val);
    return;
  }
  copy16(end, val);                       // movups xmm0,[eax]; movups [edx],xmm0
  *(u8 **)(v + 4) = end + 0x10;
}
PCREG(5acbf0, vecPushBack);
