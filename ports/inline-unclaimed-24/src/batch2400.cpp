// batch2400.cpp - decomp area 24, batch 2400: zstd::vector<CSprite2D::tagSPRITE2DINFO*>::_M_insert_aux(pos, value&)
// (0x5fe3b0), thiscall, ret 8. The vector is {begin +0, finish +4, end_of_storage +8}; elements are 4-byte pointers.
// Two paths, as in the original: room left (shift the tail right by one and store the value at pos), or no room
// (new storage of 2*len elements, or 1 when empty; copy [begin, pos), the value, then [pos, finish); free the old).
// The allocator is CHostInterface::alloc (0x6014a0, stdcall ret 4) and the free is 0x54f870 (ret 8). Both are called
// through the exe (ext_), so the harness stubs them with recorders.
#include "ff.h"

extern "C" u32 STDCALL ext_6014a0(u32 bytes);                    // CHostInterface::alloc (stdcall, ret 4)
extern "C" void THISCALL ext_54f870(u8 *alloc, u32 ptr, u32 bytes);  // free (ret 8; this = allocator)

static void THISCALL vecInsertAux(u32 *self, u32 pos, u32 *value) {
  if (self[1] != self[2]) {
    if (self[1] != 0)
      *(u32 *)self[1] = *(u32 *)(self[1] - 4);   // construct the new last element from the old last one
    self[1] += 4;
    u32 oldF = self[1] - 4;
    u32 val = *value;
    s32 count = (s32)(self[1] - 8 - pos) >> 2;   // (edx - pos) >> 2, arithmetic
    u32 src = self[1] - 8;                       // edx: last old element
    u32 dst = oldF;                              // esi
    while (count > 0) {
      *(u32 *)(dst - 4) = *(u32 *)(src - 4);
      src -= 4;
      dst -= 4;
      --count;
    }
    *(u32 *)pos = val;
    return;
  }
  // no room: reallocate
  u32 len = (u32)((s32)(self[1] - self[0]) >> 2);
  u32 newlen = (len == 0) ? 1u : len * 2u;
  u32 storage = ext_6014a0(newlen * 4u);
  u32 esi = storage;
  u32 ecx = self[0];
  u32 cnt = (pos - ecx + 3u) >> 2;
  if (ecx > pos)
    cnt = 0;
  for (u32 k = 0; k != cnt; ++k) {
    if (esi != 0)
      *(u32 *)esi = *(u32 *)ecx;
    esi += 4;
    ecx += 4;
  }
  if (esi != 0)
    *(u32 *)esi = *value;
  esi += 4;
  u32 finish = self[1];
  u32 cnt2 = (finish - pos + 3u) >> 2;
  if (pos > finish)
    cnt2 = 0;
  u32 ebx = pos - esi;   // (wrapping; the original reads [ebx + esi] while esi advances)
  for (u32 k = 0; k != cnt2; ++k) {
    if (esi != 0)
      *(u32 *)esi = *(u32 *)(ebx + esi);
    esi += 4;
  }
  u32 oldBegin = self[0];
  s32 nOld = (s32)(self[2] - oldBegin) >> 2;
  if (nOld != 0)
    ext_54f870((u8 *)self, oldBegin, (u32)nOld * 4u);
  self[1] = esi;
  self[0] = storage;
  self[2] = storage + newlen * 4u;
}
PCREG(5fe3b0, vecInsertAux);
