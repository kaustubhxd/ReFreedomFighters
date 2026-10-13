// batch286.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch286"): the civilian path
// builder in CivilianPathList.cpp (GameCube map name CCivilianPathList::Load2, low confidence): for each civilian route
// it asks the enemy pathfinder for a path between consecutive waypoints and joins the pieces into one path. Behaviour
// from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_52c000(u8 *pf, u32 one);          // ZPathfinder3::ProcessQueue (GUESS: hooked)
extern "C" void ext_634273(void *p, u32 size);                  // sized delete (GUESS: hooked)
extern "C" u8 *ext_41e290(u32 size);                            // allocator (unclaimed-64; hooked)
extern "C" void ext_41e2c0(void *p);                            // free (unclaimed-64; hooked)
extern "C" u8 *THISCALL ext_476dc0(u8 *p, u32 n);               // path constructor (unclaimed-81; hooked)

typedef void(__attribute__((cdecl)) * logf_t)(void *, const char *);

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x5bea10 (thiscall). For each route i < +0x90c (entries of 0x3a bytes from +0x4c): the pathfinder object is
// db vt 0x58 of the id the db's name table (db vt 0x138, then vt 0x88("rEnemyPathFinder3", &id)) gives; the waypoint
// list [entry]+0x18 (vt 0x14 count, vt 0x30(index)) gives positions (db vt 0x58, vt 0x84); a closed route (byte +0x39)
// visits the first point again at the end. From the second point on, each leg is queued (pathfinder vt 0x214 of the
// request db vt 0x4c([this+0x44], &from, &to, 0, 0, 1, 1)) and ProcessQueue(1) runs until a result appears in +0x48.
// A result with a path (+0x1c) adds it to the leg list; a result without one is dropped, the route's byte +7 cleared,
// "Warning: CivilianPath got a path error, ignoring the path." logged (line 0xe4) and the route skipped. Otherwise a
// new path (0x18 bytes, ctor 0x476dc0) of all legs' point counts (+8) is filled: each point's three words +4..+0xc are
// copied, its +8 lowered by 15, its +0 is the leg's value plus the length so far (+4), and each leg's length is added;
// legs are freed (points through 0x41e2c0, +0x10 and +0x14 (4 bytes) and the leg (0x18) through sized delete). The new
// path goes to the route's +0xd. SEH frame and stack cookie not reproduced (the hooked constructor does not throw).
void THISCALL civilianPathBuild_5bea10(u8 *self) {
  for (s32 ri = 0; ri < *(s32 *)(self + 0x90c); ri++) {
    u8 *e = self + 0x4c + ri * 0x3a;
    bool firstPt = true;
    u32 nseg = 0;
    u8 *segs[16];
    u8 *names = (u8 *)vcall<u32>(DB, 0x138);
    u32 id = 0;
    vcall<void>(names, 0x88, 0x68a9e0u, (u32)&id);
    u8 *pf = (u8 *)vcall<u32>(DB, 0x58, id);
    s32 npts = vcall<s32>(*(u8 **)(*(u8 **)e + 0x18), 0x14);
    if (e[0x39]) npts++;
    float prev[3], pos[3];
    bool failed = false;
    for (s32 j = 0; j < npts; j++) {
      s32 have = vcall<s32>(*(u8 **)(*(u8 **)e + 0x18), 0x14);
      u32 x = vcall<u32>(*(u8 **)(*(u8 **)e + 0x18), 0x30, (u32)(j < have ? j : 0));
      u8 *o = (u8 *)vcall<u32>(DB, 0x58, x);
      pos[0] = pos[1] = pos[2] = 0.0f;
      vcall<void>(o, 0x84, (u32)pos);
      if (!firstPt) {
        u32 q = vcall<u32>(DB, 0x4c, *(u32 *)(self + 0x44), (u32)prev, (u32)pos, 0u, 0u, 1u, 1u);
        vcall<void>(pf, 0x214, q);
        while (!*(u32 *)(self + 0x48)) ext_52c000(pf, 1);
        u8 *r = *(u8 **)(self + 0x48);
        u8 *seg = *(u8 **)(r + 0x1c);
        if (!seg) {
          ext_634273(r, 0x20);
          *(u32 *)(self + 0x48) = 0;
          e[7] = 0;
          void *lg = vcall<void *>(*(u8 **)0x700390u, 0x20, 0x6b35ecu, 0xe4u);
          (*(logf_t *)(*(u8 **)lg + 0x2c))(lg, (const char *)0x6b365cu);
          failed = true;
          break;
        }
        segs[nseg++] = seg;
        ext_634273(r, 0x20);
        *(u32 *)(self + 0x48) = 0;
      }
      prev[0] = pos[0];
      prev[1] = pos[1];
      prev[2] = pos[2];
      firstPt = false;
    }
    if (failed) continue;
    u32 total = 0;
    for (u32 k = 0; k < nseg; k++) total += *(u32 *)(segs[k] + 8);
    u8 *p = ext_41e290(0x18);
    p = p ? ext_476dc0(p, total) : 0;
    u32 w = 0;
    for (u32 k = 0; k < nseg; k++) {
      u8 *s = segs[k];
      for (s32 m = 0; m < *(s32 *)(s + 8); m++) {
        u8 *src = *(u8 **)(s + 0xc) + m * 16;
        u8 *dst = *(u8 **)(p + 0xc) + w * 16;
        w++;
        *(u32 *)(dst + 4) = *(u32 *)(src + 4);
        *(u32 *)(dst + 8) = *(u32 *)(src + 8);
        *(u32 *)(dst + 0xc) = *(u32 *)(src + 0xc);
        *(float *)(*(u8 **)(p + 0xc) + (w - 1) * 16 + 8) -= *(float *)0x680a80u;
        *(float *)(*(u8 **)(p + 0xc) + (w - 1) * 16) = *(float *)(*(u8 **)(s + 0xc) + m * 16) + *(float *)(p + 4);
      }
      *(float *)(p + 4) = *(float *)(p + 4) + *(float *)(s + 4);
      if (s) {
        if (*(void **)(s + 0xc)) ext_41e2c0(*(void **)(s + 0xc));
        if (*(void **)(s + 0x10)) ext_634273(*(void **)(s + 0x10), 4);
        if (*(void **)(s + 0x14)) ext_634273(*(void **)(s + 0x14), 4);
        ext_634273(s, 0x18);
      }
    }
    *(u8 **)(e + 0xd) = p;
  }
}
PCREG(5bea10, civilianPathBuild_5bea10);
#undef DB
