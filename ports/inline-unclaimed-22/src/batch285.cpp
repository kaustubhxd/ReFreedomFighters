// batch285.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch285"): ZCollisionBase::
// ExpandThroughGates, the room set expansion used by collision and line-of-sight queries (a box that overlaps a gate
// pulls the rooms behind that gate into the set). Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                // mcpy (inline-batch45)
extern "C" void THISCALL ext_4daf90(u8 *geom, float *out);                        // ZBaseGeom::GetCen (inline-collision; hooked)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                    // vmmul (inline-batch45)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                    // PSVECAdd (inline-batch45)
extern "C" u8 FASTCALL ext_4df330(const float *m, const float *p, const float *ext, const float *gm,
                                  const float *gc, const float *gext);            // rectBoxColi (GUESS: hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x4ec750 ZCollisionBase::ExpandThroughGates(bool &changed, ZROOM **rooms, ZROOM **roomsEnd, unsigned cnt,
// ZBaseGeom **gates, ZBaseGeom **gatesEnd, unsigned *first, const float *mat, const float *pos, const float *ext) const
// (thiscall, this unused, ret 0x28, returns the new room count). Nothing unless 0 < cnt < capacity n = roomsEnd - rooms.
// The first cnt rooms get vt 0x378(1, 0). Then for each room i (the count can grow while it runs): first[i] = gates
// written so far; room vt 0x378(2, 0); with a non-empty gate list +0xa4 (vt 0x14) the query box (mat copied, pos) is
// moved into the room (vt 0x94(m, p)) and for every gate (list vt 0x4c / 0x5c, db vt 0x58) that is a portal (vt 0x234)
// with a non-empty room list (vt 0x230, vt 0x14), stopping when the set is full: the gate's centre (GetCen, vmmul by its
// matrix, plus +0x24) and box go to rectBoxColi; on a hit every room behind it (db vt 0x58, vt 0x20) that is not in the
// set (vt 0x37c bit 1 clear) is marked (vt 0x378(3, 0)) and inserted right after room i (count + 1, stop when full);
// one in the set but not yet visited (bit 2 clear) is moved to right after room i if found later in the list, and gets
// vt 0x378(2, 0) either way; the gate geometry is appended to gates (changed = true) while there is room. A 0 ends each
// room's gate run. Finally every room gets vt 0x378(0, 3), and a -1 ends the gate list when there is room. Stack
// cookie not reproduced.
u32 THISCALL expandThroughGates_4ec750(u8 *self, u8 *changed, u8 **rooms, u8 **roomsEnd, u32 cnt, u8 **gates,
                                       u8 **gatesEnd, u32 *first, const float *mat, const float *pos,
                                       const float *ext) {
  (void)self;
  u32 n = (u32)((s32)((u8 *)roomsEnd - (u8 *)rooms) >> 2);
  u8 **cur = gates;
  if (cnt != 0 && cnt < n) {
    for (u32 k = 0; k < cnt; k++) vcall<void>(rooms[k], 0x378, 1u, 0u);
    u32 i = 0;
    do {
      if (n <= cnt) break;
      u8 *r = rooms[i];
      first[i] = (u32)((s32)((u8 *)cur - (u8 *)gates) >> 2);
      vcall<void>(r, 0x378, 2u, 0u);
      u8 *list = *(u8 **)(r + 0xa4);
      if (list && vcall<u32>(list, 0x14)) {
        float M[12], P[3];
        ext_4de420(M, mat);
        P[0] = pos[0];
        P[1] = pos[1];
        P[2] = pos[2];
        vcall<void>(r, 0x94, (u32)M, (u32)P);
        u32 it[3];
        vcall<u32>(list, 0x4c, (u32)it);
        u32 g = vcall<u32>(list, 0x5c, (u32)it);
        while (it[0]) {
          u8 *obj = (u8 *)vcall<u32>(DB, 0x58, g);
          if ((u8)vcall<u32>(obj, 0x234)) {
            u8 *rl = (u8 *)vcall<u32>(obj, 0x230);
            if (rl && vcall<u32>(rl, 0x14)) {
              if (n <= cnt) break;
              u8 *geo = *(u8 **)(obj + 8);
              float v[3];
              ext_4daf90(geo, v);
              ext_4419f0(v, (const float *)geo);
              ext_441940(v, (const float *)(geo + 0x24));
              if (ext_4df330(M, P, ext, (const float *)geo, v, (const float *)(geo + 0x40))) {
                u32 it2[3];
                vcall<u32>(rl, 0x4c, (u32)it2);
                u32 x = vcall<u32>(rl, 0x5c, (u32)it2);
                while (it2[0]) {
                  u8 *o2 = (u8 *)vcall<u32>(DB, 0x58, x);
                  u8 *room = (u8 *)vcall<u32>(o2, 0x20);
                  if (vcall<u32>(room, 0x37c) & 1) {
                    if (!(vcall<u32>(room, 0x37c) & 2)) {
                      for (u32 c = i + 1; c < cnt; c++) {
                        if (rooms[c] == room) {
                          rooms[c] = rooms[i + 1];
                          rooms[i + 1] = room;
                          break;
                        }
                      }
                      vcall<void>(room, 0x378, 2u, 0u);
                    }
                  } else {
                    vcall<void>(room, 0x378, 3u, 0u);
                    for (u32 c = cnt; c > i + 1; c--) rooms[c] = rooms[c - 1];
                    cnt++;
                    rooms[i + 1] = room;
                    if (n <= cnt) break;
                  }
                  x = vcall<u32>(rl, 0x5c, (u32)it2);
                }
                if (cur < gatesEnd) {
                  *changed = 1;
                  *cur++ = geo;
                }
              }
            }
          }
          g = vcall<u32>(list, 0x5c, (u32)it);
        }
      }
      if (cur < gatesEnd) *cur++ = 0;
      i++;
    } while (i != cnt);
    for (u32 k = 0; k < cnt; k++) vcall<void>(rooms[k], 0x378, 0u, 3u);
  }
  if (cur < gatesEnd) *cur = (u8 *)0xffffffffu;
  return cnt;
}
PCREG(4ec750, expandThroughGates_4ec750);
#undef DB
