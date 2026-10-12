// batch721.cpp - soldier AI, batch 721 (2026-10-11): CFFCoverList spot-vector insert and reserve.
// The vector is {begin, end, cap} of 0x48-byte CCoverSpot records (CFFCoverList list pointer at self+0x6b, see Init).
// Copy routines 0x5853a0 (forward, returns the end of its destination) and 0x5852f0 (backward) are the exe's; allocation
// 0x6014a0 and release 0x54f870 are exe code too (hooked by the spec). The insert returns the element's new address.
#include "ff.h"

struct CSpotVec { u8 *begin; u8 *end; u8 *cap; };

extern "C" u8 *FASTCALL ext_5853a0(u8 *first, u8 *last, u8 *dest, u32 unused);       // copy forward
extern "C" void FASTCALL ext_5852f0(u8 *first, u8 *last, u8 *dest, u32 u1, u32 u2);  // copy backward
extern "C" u8 *THISCALL ext_6014a0(void *self, u32 bytes);                            // CHostInterface::alloc
extern "C" void THISCALL ext_54f870(void *self, u8 *block, u32 bytes);               // release

static inline void copy48(u8 *dst, const u8 *src) {
  for (int k = 0; k < 0x48; k++)
    dst[k] = src[k];
}

// 0x5885c0 (ret 8): insert src at pos, in the middle of the vector (or after a realloc). The shift uses 0x5852f0.
static void THISCALL cover_InsertMiddle(CSpotVec *v, u8 *pos, const u8 *src) {
  if (v->end != v->cap) {
    if (v->end)
      copy48(v->end, v->end - 0x48);                  // the last record moves up into the new slot
    u8 *oldEnd = v->end;
    v->end = oldEnd + 0x48;
    u8 tmp[0x48];
    copy48(tmp, src);                                  // read src before the shift (it may alias the range)
    ext_5852f0(pos, oldEnd - 0x48, oldEnd, 0, 0);     // move [pos, last) up by one record
    copy48(pos, tmp);
    return;
  }
  // full: new buffer of twice the count (one record when empty)
  s32 count = (s32)(v->end - v->begin) / 0x48;
  s32 newCount = count == 0 ? 1 : count * 2;
  u8 *nb = ext_6014a0(v, newCount * 0x48);
  u8 *p = ext_5853a0(v->begin, pos, nb, 0);            // [begin, pos) to the new buffer
  if (p)
    copy48(p, src);
  p += 0x48;
  u8 *e2 = ext_5853a0(pos, v->end, p, 0);              // [pos, end) after the new record
  u32 oldBytes = (u32)(v->cap - v->begin);
  if (oldBytes != 0)
    ext_54f870(v, v->begin, oldBytes);
  v->begin = nb;
  v->end = e2;
  v->cap = nb + newCount * 0x48;
}

PCREG(5885c0, cover_InsertMiddle);

// 0x588750 (ret 8): insert src at pos. Appends in place when pos is the end and there is room; otherwise 0x5885c0.
// Returns the address the element ends up at.
static u8 *THISCALL cover_Insert(CSpotVec *v, u8 *pos, const u8 *src) {
  s32 idx = (s32)(pos - v->begin) / 0x48;
  if (v->end != v->cap && pos == v->end) {
    if (v->end)
      copy48(v->end, src);
    v->end += 0x48;
  } else {
    cover_InsertMiddle(v, pos, src);
  }
  return v->begin + idx * 0x48;
}
PCREG(588750, cover_Insert);

// 0x5887e0 (ret 4): reserve room for n records. Copies the live records to a new buffer (0x5853a0), releases the old one,
// and sets cap = begin + n. Does nothing when the capacity is already n or more.
static void THISCALL cover_Reserve(CSpotVec *v, u32 n) {
  if ((s32)(v->cap - v->begin) / 0x48 >= (s32)n)
    return;
  u8 *oldBegin = v->begin;
  u8 *oldEnd = v->end;
  s32 count = (s32)(oldEnd - oldBegin) / 0x48;
  u8 *nb = n ? ext_6014a0(v, n * 0x48) : 0;
  ext_5853a0(oldBegin, oldEnd, nb, 0);
  u32 oldBytes = (u32)(v->cap - v->begin);
  if (oldBytes != 0)
    ext_54f870(v, oldBegin, oldBytes);
  v->begin = nb;
  v->end = nb + count * 0x48;
  v->cap = nb + n * 0x48;
}
PCREG(5887e0, cover_Reserve);
