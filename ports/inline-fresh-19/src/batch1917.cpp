// batch1917.cpp - fresh slice 19, batch 1917 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 i);                       // parameter array element (hooked)
extern "C" u8 *THISCALL ext_4daff0(u8 *g);                                // ZBaseGeom::GetDynamicTreeGroup (hooked)
extern "C" u8 *THISCALL ext_4db7e0(u8 *g);                                // ZBaseGeom::GetTreeGroup (hooked)
extern "C" void THISCALL ext_443c80(u8 *tg, u32 c);                       // ZTreeGroup::RemoveStaticChildTreeGroup (hooked)
extern "C" void THISCALL ext_442050(u8 *tg, u32 c);                       // ZTreeGroup::AddStaticChildTreeGroup (hooked)
extern "C" void THISCALL ext_4cbeb0(u8 *s);                               // MYSTR::MYSTR() (hooked)
extern "C" u32 THISCALL ext_4cc5f0(u8 *s);                                // MYSTR::Length (hooked)
extern "C" void THISCALL ext_4cc2c0(u8 *s, u8 *o);                        // MYSTR::operator+= (hooked)
extern "C" void THISCALL ext_4cbe80(u8 *s, const char *t);                // MYSTR::MYSTR(const char *) (hooked)
extern "C" void THISCALL ext_4cbec0(u8 *s);                               // MYSTR::~MYSTR (hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))
typedef void (*logf_t)(void *, ...);

static inline void assert_hook() {
  void (*hook)() = *(void (**)())0x7003b0u;
  if (hook) hook();
  else __builtin_debugtrap();   // the exe falls into an int3 when no hook is set
}

static inline void raise(u32 line, u32 what) {
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x69c8e0u, line);
  (*(logf_t *)(*(u8 **)log + 0x2c))(log, 0x69c6b0u, what);   // "RAISE_EXCEPTION %s"
  assert_hook();
}

// 0x50a770 (no GC name; script native, string value) (params) ret 4: in param 0 of type 3 is used as is, type 4 through
// its object's vt[0x34](), anything else raises "No CStr Rep" (SDL line 0x111) and uses 0; db vt[0x134]()->vt[0x88](v,
// &out) gives out (0 first); out param 0 (array +8) of type 0 or 1 takes out with type 1, else raises "NO! WRONG TYPE"
// (line 0xc4).
static void THISCALL str_50a770(u8 *, u8 *pr) {
  u8 *a = ext_5003d0(*(u8 **)(pr + 4), 0);
  u32 v;
  if (a[4] == 3) v = *(u32 *)a;
  else if (a[4] == 4) v = vcall<u32>(*(u8 **)a, 0x34);
  else {
    raise(0x111, 0x69c9b0u);
    v = 0;
  }
  u32 out = 0;
  vcall<void>(vcall<u8 *>(DB, 0x134), 0x88, v, &out);
  u8 *r = ext_5003d0(*(u8 **)(pr + 8), 0);
  if (r[4] > 1) {
    raise(0xc4, 0x69c938u);
    return;
  }
  *(u32 *)r = out;
  r[4] = 1;
}
PCREG(50a770, str_50a770);

// 0x4437b0 ZTreeGroup::MakePrivate(bool b) ret 4: nothing when +0x5c == b. With a geom (vt[0x20]()), its dynamic tree group
// gets vt[0x2f4](+8) (b) or vt[0x2f0](+8); its tree group gets vt[0x2cc](this) and each static child of the list +0x7b
// (u16 count, words from +4) removed (b), or vt[0x2c8](this) and each child added. +0x5c = b.
static void THISCALL makePrivate_4437b0(u8 *self, u32 arg) {
  u8 b = (u8)arg;
  if (self[0x5c] == b) return;
  if (vcall<u8 *>(self, 0x20)) {
    if (u8 *dyn = ext_4daff0(*(u8 **)(vcall<u8 *>(self, 0x20) + 8))) vcall<void>(dyn, b ? 0x2f4 : 0x2f0, *(u32 *)(self + 8));
    if (u8 *tg = ext_4db7e0(*(u8 **)(vcall<u8 *>(self, 0x20) + 8))) {
      vcall<void>(tg, b ? 0x2cc : 0x2c8, self);
      u8 *l = *(u8 **)(self + 0x7b);
      if (l && *(u16 *)l) {
        u32 i = 0;
        do {
          u32 ch = *(u32 *)(*(u8 **)(self + 0x7b) + 4 + 4 * i);
          if (b) ext_443c80(tg, ch);
          else ext_442050(tg, ch);
          i++;
        } while (i != *(u16 *)*(u8 **)(self + 0x7b));
      }
    }
  }
  self[0x5c] = b;
}
PCREG(4437b0, makePrivate_4437b0);

// 0x4208f0 ZSysInterfaceGC::ConvertFileName(const char *name) ret 8 (returns MYSTR in the hidden first argument): an
// empty MYSTR; names longer than one character with no drive (':' second) and no "\\\\" start get the base path +0x123
// first (when its Length() is not 0); then the name through a temporary MYSTR. Returns the result pointer. (SEH, cookie
// not ported.)
static u8 *THISCALL convert_4208f0(u8 *self, u8 *out, const char *name) {
  ext_4cbeb0(out);
  u32 n = 0;
  while (name[n]) n++;
  if (n > 1 && name[1] != ':' && *(const u16 *)name != 0x5c5c) {
    if (ext_4cc5f0(self + 0x123)) ext_4cc2c0(out, self + 0x123);
  }
  u8 tmp[0x80];
  ext_4cbe80(tmp, name);
  ext_4cc2c0(out, tmp);
  ext_4cbec0(tmp);
  return out;
}
PCREG(4208f0, convert_4208f0);
