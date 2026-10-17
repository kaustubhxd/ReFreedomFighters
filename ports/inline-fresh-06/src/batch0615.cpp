// batch0615.cpp - fresh-06 batch 15 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

typedef void (*hfn)();
static inline void handlerCall() {
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}
typedef s32 (*stricmpFn)(const char *, const char *);
static inline s32 iatStricmp(const char *a, const char *b) { return G(stricmpFn, 0x676414)(a, b); }   // _stricmp import
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);

// 0x5600a0, CFFMPGameControl_if::SetTimer(OpaqueCallParameters_t&) (stdcall): with the game controller at
// [0x7003b8]+0x2c21: argument 0 as a float >= 0 (NaN fails) sets +0x4c and copies it into +0xe of the stats of teams
// 3-6 (GetStatFromTeam); argument 1 >= 0 sets +0x50; arguments 2 and 3 (nonzero) set bytes +0x58 and +0x59.
extern "C" u8 *THISCALL ext_5a46f0(void *gc, s32 team);
static inline u8 *mpgc() { return *(u8 **)(G(u8 *, 0x7003b8) + 0x2c21); }
static void STDCALL mpSetTimer(u8 *p) {
  if (*(float *)ext_5003d0(*(void **)(p + 4), 0) >= 0.0f) {
    u32 v = *(u32 *)ext_5003d0(*(void **)(p + 4), 0);
    *(u32 *)(mpgc() + 0x4c) = v;
    for (s32 t = 3; t <= 6; ++t) {
      u8 *s = ext_5a46f0(mpgc(), t);
      *(u32 *)(s + 0xe) = *(u32 *)(mpgc() + 0x4c);
    }
  }
  if (*(float *)ext_5003d0(*(void **)(p + 4), 1) >= 0.0f) *(u32 *)(mpgc() + 0x50) = *(u32 *)ext_5003d0(*(void **)(p + 4), 1);
  u32 a2 = *(u32 *)ext_5003d0(*(void **)(p + 4), 2);
  mpgc()[0x58] = a2 != 0;
  u32 a3 = *(u32 *)ext_5003d0(*(void **)(p + 4), 3);
  mpgc()[0x59] = a3 != 0;
}
PCREG(5600a0, mpSetTimer);

// 0x4346e0, ZSysFile::BigLoaded(const char*): the name goes into a local MYSTR with every '\' turned into '/'; true
// when an entry of the list at +4 (slot 0x4c begin, slot 0x64 next; entry -> object, name at +0xd) matches it with
// _stricmp.
extern "C" void THISCALL ext_4cbe80(void *s, const char *p);
extern "C" u32 THISCALL ext_4cc5f0(void *s);
extern "C" char *THISCALL ext_4cc1d0(void *s);
extern "C" void THISCALL ext_4cbec0(void *s);
static u8 THISCALL sysFileBigLoaded(u8 *self, const char *name) {
  u32 fr[0x23];
  u32 *it = fr, *str = fr + 3;
  ext_4cbe80(str, name);
  if (ext_4cc5f0(str)) {
    u32 i = 0;
    do {
      if (ext_4cc1d0(str)[i] == '\\') ext_4cc1d0(str)[i] = '/';
      ++i;
    } while (i != ext_4cc5f0(str));
  }
  u8 r = 0;
  if (*(void **)(self + 4)) {
    vcall<void>(*(void **)(self + 4), 0x4c, it);
    for (u8 **e = vcall<u8 **>(*(void **)(self + 4), 0x64, it); e; e = vcall<u8 **>(*(void **)(self + 4), 0x64, it)) {
      const char *en = *(const char **)(*e + 0xd);
      if (!iatStricmp(ext_4cc1d0(str), en)) {
        r = 1;
        break;
      }
    }
  }
  ext_4cbec0(str);
  return r;
}
PCREG(4346e0, sysFileBigLoaded);

// 0x601720, CSdlDataExchange::getExportSymbolInt(const char*): the first symbol (array +4 of pointers to records,
// count +0xc) whose record has a zero first dword and whose name (+0xc) matches (_stricmp) gives its int (+4); 0 when
// none. (The index checks against the count call the handler; never true inside the loop.)
static u32 THISCALL sdlGetExportSymbolInt(u8 *self, const char *name) {
  for (u32 i = 0; i < *(u32 *)(self + 0xc); ++i) {
    if (!(i < *(u32 *)(self + 0xc))) handlerCall();
    u32 *rec = **(u32 ***)(*(u8 **)(self + 4) + i * 4);
    if (rec[0]) continue;
    if (!(i < *(u32 *)(self + 0xc))) handlerCall();
    rec = **(u32 ***)(*(u8 **)(self + 4) + i * 4);
    if (!iatStricmp((const char *)rec[3], name)) {
      if (!(i < *(u32 *)(self + 0xc))) handlerCall();
      return (**(u32 ***)(*(u8 **)(self + 4) + i * 4))[1];
    }
  }
  return 0;
}
PCREG(601720, sdlGetExportSymbolInt);

// 0x607260, hashtable<pair<const char*, u16>, ..., eqstr>::find_or_insert(const pair&): resize for count (+0xf) + 1,
// bucket = 0x606ea0(pair, bucket count) over the bucket array (+3..+7); a node (next, key, value) with a matching key
// (_stricmp) gives &node->key; else a 10-byte node from CHostInterface::alloc gets the pair, goes in front of the
// bucket's chain and the count grows. Returns &node->key.
extern "C" void THISCALL ext_6073b0(void *h, u32 n);
extern "C" u32 THISCALL ext_606ea0(void *h, const void *pair, u32 nb);
extern "C" u8 *THISCALL ext_6014a0(void *h, u32 size);
static u8 *THISCALL strHashFindOrInsert(u8 *self, const u32 *pair) {
  ext_6073b0(self, *(u32 *)(self + 0xf) + 1);
  u32 nb = (u32)((s32)(*(u32 *)(self + 7) - *(u32 *)(self + 3)) >> 2);
  u32 idx = ext_606ea0(self, pair, nb);
  u32 off = idx * 4;
  u8 *first = *(u8 **)(*(u8 **)(self + 3) + off);
  for (u8 *n = first; n; n = *(u8 **)n)
    if (!iatStricmp(*(const char **)(n + 4), (const char *)pair[0])) return n + 4;
  u8 *node = ext_6014a0(self, 0xa);
  u8 *kv = node + 4;
  *(u32 *)node = 0;
  if (kv) {
    *(u32 *)kv = pair[0];
    *(u16 *)(kv + 4) = *(const u16 *)(pair + 1);
  }
  *(u8 **)node = first;
  *(u8 **)(*(u8 **)(self + 3) + off) = node;
  ++*(u32 *)(self + 0xf);
  return kv;
}
PCREG(607260, strHashFindOrInsert);
