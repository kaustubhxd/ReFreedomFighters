// batch1233.cpp - pathfinding tree: ZActor::FindPath(from, to) [map 0x478780; thiscall, ret 8].
// Not active (+0x690 == 0): builds a CChkPntLst of two points (the straight segment from..to, with its length at +4
// and +0x10), then a 0x20-byte request record that refers to it, sets +0x691 = 1 and hands the record to the actor's
// slot 0x5e4. Active (+0x690 != 0): with no pathfinder (+0x5b2 == 0) the debug reporter is called and the function
// returns; otherwise the request goes to the message table (engine +0x9b, slot 0x4c) and the result is handed to the
// pathfinder's slot 0x214, and its return is kept at +0x691. The +0x74e flag is cleared on both paths.
// The exe's SEH frame (fs:[0]) is not reproduced; nothing in the body can throw in this harness.
#include "pf.h"

extern "C" void *THISCALL ext_476dc0(void *lst, int n);   // CChkPntLst::CChkPntLst(int); returns this
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract: dst = a - b

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL actorFindPath(u8 *self, const float *from, const float *to) {
  self[0x74e] = 0;
  if (self[0x690] == 0) {
    u8 *lst = (u8 *)ext_41e290(0x18);
    if (lst) lst = (u8 *)ext_476dc0(lst, 2);
    float d[3];
    ext_43e920(d, to, from);                               // d = to - from
    float sq = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
    float len = (float)crt::sqrt((double)sq);
    *(float *)(lst + 4) = len;
    u8 *pts = *(u8 **)(lst + 0xc);
    *(u32 *)pts = 0;
    *(float *)(pts + 0x10) = len;
    for (int k = 0; k < 3; k++) {
      *(u32 *)(pts + 4 + 4 * k) = ((const u32 *)from)[k];
      *(u32 *)(pts + 0x14 + 4 * k) = ((const u32 *)to)[k];
    }
    u8 *rec = (u8 *)ext_41e290(0x20);
    *(u8 **)(rec + 0x1c) = lst;
    *(u32 *)(rec + 0x18) = 1;
    wr32u(self + 0x691, 1);
    vcall<void>(self, 0x5e4, rec);
    return;
  }
  u8 *path = (u8 *)rd32u(self + 0x5b2);
  if (!path) {
    pfReport((const char *)0x68a7c4, 0x4fb, (const char *)0x68aad4);
    return;
  }
  wr32u(self + 0x691, 0x12345678);
  u32 flag = (self[0x6c4] != 0 && self[0x6c3] == 0) ? 1 : 0;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *msg = *(u8 **)(eng + 0x9b);
  u32 r = vcall<u32>(msg, 0x4c, self, from, to, (u32)0, (u32)0, (u32)0, flag);
  u32 res = vcall<u32>(path, 0x214, r);
  wr32u(self + 0x691, res);
}
PCREG(478780, actorFindPath);
