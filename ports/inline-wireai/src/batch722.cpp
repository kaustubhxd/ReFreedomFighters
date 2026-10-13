// batch722.cpp - soldier AI, batch 722 (2026-10-11): CFFCoverList::Init, the cover-spot build from the scene.
// Steps (all from 0x587a30): (1) the engine's global record gets this list (+0x2c1d) and the reference of the owner geom
// (+0x2c25, from db slot 0x4c on this+0x44); (2) the scene chain (db+0xadc, head at +8, next via slot 0x50) is scanned for
// objects whose info name (object+0x54 -> +4) contains "coverbox", "coverarrow" or "coverspline" (striwcmp wildcards);
// (3) a spot vector {begin,end,cap} is made at this+0x6b with capacity 0x800 records; (4) each kept object is dispatched
// by its exact sub-name: coverboxl/m/h -> CreateSpotsAroundBox (type 0/1/2, flag 1), coverarrowl -> the arrow spot built
// inline (GetRootTM, vneg, CreateSpot with type 0, flag 1), coverarrowm/h -> CreateSpotForArrow (type 1/2, flag 1),
// coverspline -> CreateSpotsAlongSpline (type 2, flag 1), anything else warns "Invalid covername: '%s'";
// (5) the spot vector is copied into the inline list this+0x5f (reserve + append or insert), its buffer and 12-byte
// record are released, and the totals are logged.
#include "ff.h"

struct CSpotVec { u8 *begin; u8 *end; u8 *cap; };
struct MYSTR_buf { u8 b[0x80]; };

extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);                       // operator new
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);               // operator delete (sized)
extern "C" u8 *THISCALL ext_6014a0(void *self, u32 bytes);                          // CHostInterface::alloc
extern "C" void THISCALL ext_54f870(void *self, u8 *block, u32 bytes);             // release
extern "C" s32 FASTCALL ext_4cc850(const char *name, const char *pattern);          // striwcmp
extern "C" void THISCALL ext_5887e0(void *vec, u32 n);                             // reserve (inline list)
extern "C" void THISCALL ext_5885c0(void *vec, u8 *pos, const u8 *src);            // insert middle
extern "C" void THISCALL ext_5868e0(void *self, void *g, u32 type, u32 flag);      // CreateSpotsAroundBox
extern "C" void THISCALL ext_585ed0(void *self, void *g, u32 type, u32 flag);      // CreateSpotForArrow
extern "C" void THISCALL ext_586760(void *self, void *shape, u32 type, u32 flag);  // CreateSpotsAlongSpline
extern "C" void THISCALL ext_585a40(void *self, float *a, float *b, float *c, float *d, u32 check, u32 type, u32 flags);
extern "C" void THISCALL ext_4de7a0(float *m);                                      // mreset
extern "C" void THISCALL ext_4e09b0(float *v);                                      // vneg

static inline void *engine() { return *(void **)0x70039c; }
static inline u8 *db() { return *(u8 **)((u8 *)engine() + 0x9b); }
static inline void *logger() { return *(void **)0x700390; }

static const char *cover_name(u8 *info) {
  const char *n = info ? *(const char **)(info + 4) : 0;
  return n ? n : (const char *)0x67c8e8;   // "<NONAME>"
}

static void copy48(u8 *dst, const u8 *src) {
  for (int k = 0; k < 0x48; k++)
    dst[k] = src[k];
}

// 0x587a30 CFFCoverList::Init() [high].
static void THISCALL cover_Init(u8 *self) {
  u8 *gl = *(u8 **)0x7003b8;
  *(u8 **)(gl + 0x2c1d) = self;
  *(u32 *)(gl + 0x2c25) = vcall<u32>(db(), 0x4c, *(void **)(self + 0x44));

  // (2) scan the scene
  static u8 *keep[0x800];
  s32 n = 0;
  u8 *cur = *(u8 **)(*(u8 **)(db() + 0xadc) + 8);
  while (cur) {
    u8 *info = *(u8 **)(cur + 0x54);
    const char *name = cover_name(info);
    bool k = ext_4cc850(name, (const char *)0x6ab944) == 0 ||   // "*coverbox*"
             ext_4cc850(name, (const char *)0x6ab950) == 0 ||   // "*coverarrow*"
             ext_4cc850(name, (const char *)0x6ab960) == 0;     // "*coverspline*"
    if (k) {
      if (n >= 0x800) {
        void *log = vcall<void *>(logger(), 0x20, (const char *)0x6ab8a0, 0x165);
        typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
        (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6ab970);
      } else {
        keep[n++] = info;
      }
    }
    vcall<void>(*(void **)(db() + 0xadc), 0x50, &cur);   // next object (in place)
  }

  // (3) spot vector at this+0x6b, capacity 0x800
  CSpotVec *vec = (CSpotVec *)ext_41e290(12);
  if (vec) {
    vec->begin = vec->end = vec->cap = 0;
  }
  *(CSpotVec **)(self + 0x6b) = vec;
  {
    u32 count = vec ? (u32)((u8 *)vec->end - (u8 *)vec->begin) / 0x48 : 0;
    u8 *nb = ext_6014a0(vec, 0x24000);
    u8 *oldBegin = vec ? vec->begin : 0;
    u8 *oldEnd = vec ? vec->end : 0;
    for (u8 *s = oldBegin, *d = nb; s != oldEnd; s += 0x48, d += 0x48)
      copy48(d, s);
    if (oldBegin != oldEnd)
      ext_54f870(vec, oldBegin, (u32)(oldEnd - oldBegin));
    vec->begin = nb;
    vec->end = nb + count * 0x48;
    vec->cap = nb + 0x24000;
  }

  // (4) dispatch
  for (s32 i = 0; i < n; i++) {
    u8 *info = keep[i];
    *(u8 *)(self + 0x56) = 0;
    const char *name = cover_name(info);
    if (ext_4cc850(name, (const char *)0x6ab9b4) == 0)        // *coverboxl*
      ext_5868e0(self, info, 0, 1);
    else if (ext_4cc850(name, (const char *)0x6ab9c0) == 0)   // *coverboxm*
      ext_5868e0(self, info, 1, 1);
    else if (ext_4cc850(name, (const char *)0x6ab9cc) == 0)   // *coverboxh*
      ext_5868e0(self, info, 2, 1);
    else if (ext_4cc850(name, (const char *)0x6ab9d8) == 0) { // *coverarrowl*: arrow built inline
      float M[12];
      float P[3];
      vcall<void>(info, 0x80, M, P);
      ext_4e09b0(M);
      float A[3] = {P[0], P[1], P[2]};
      float C[3] = {M[2], M[1], -M[0]};
      float D[3] = {M[0], M[1], M[2]};
      ext_585a40(self, A, P, C, D, 0, 0, 0);
      vcall<void>(info, 0x210, 1);
    }
    else if (ext_4cc850(name, (const char *)0x6ab9e8) == 0)   // *coverarrowm*
      ext_585ed0(self, info, 1, 1);
    else if (ext_4cc850(name, (const char *)0x6ab9f8) == 0)   // *coverarrowh*
      ext_585ed0(self, info, 2, 1);
    else if (ext_4cc850(name, (const char *)0x6ab960) == 0)   // *coverspline*
      ext_586760(self, info, 2, 1);
    else {
      void *log = vcall<void *>(logger(), 0x20, (const char *)0x6ab8a0, 0x18f);
      typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
      (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aba08, name);   // "Invalid covername: '%s'"
    }
  }

  // (5) into the inline list at this+0x5f
  CSpotVec *inl = (CSpotVec *)(self + 0x5f);
  u32 vcount = vec ? (u32)((u8 *)vec->end - (u8 *)vec->begin) / 0x48 : 0;
  ext_5887e0(inl, vcount);
  if (vec) {
    for (u8 *s = vec->begin; s != vec->end; s += 0x48) {
      if (inl->end != inl->cap) {
        if (inl->end)
          copy48(inl->end, s);
        inl->end += 0x48;
      } else {
        ext_5885c0(inl, inl->end, s);
      }
    }
    // release the temporary buffer and its record
    u32 capBytes = (u32)(vec->cap - vec->begin);
    if (capBytes)
      ext_54f870(vec, vec->begin, capBytes);
    ext_634273(vec, 0xc);
  }
  *(CSpotVec **)(self + 0x6b) = 0;

  // totals
  u32 cnt = (u32)(inl->end - inl->begin) / 0x48;
  u32 mem = cnt * 0x48;   // the original multiplies the inline count again
  void *log = vcall<void *>(logger(), 0x20, (const char *)0x6ab8a0, 0x1ab);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, u32, u32, u32);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aba20, cnt, mem, 0x48);
}
PCREG(587a30, cover_Init);
