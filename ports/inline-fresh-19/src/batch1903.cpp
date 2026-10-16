// batch1903.cpp - fresh slice 19, batch 1903 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

typedef void (*logf2_t)(void *, u32, u32);
extern "C" void THISCALL ext_612030(u8 *self, u32 x, u32 c);              // (no GC name; hooked, ret 8)
extern "C" void THISCALL ext_563a50(u8 *self);                            // CBaseWindow::SetupScanLinesAndHelp (hooked)
extern "C" void THISCALL ext_5f2d60(u8 *str, u32 b, u32 e);               // string assign(begin, end) (hooked, ret 8)
extern "C" void THISCALL ext_65f0f0(u8 *self);                            // ZGeometryDecal::End (hooked)
extern "C" void STDCALL ext_63418c(void *a, u32 sz, u32 n, void *dtor);   // eh vector destructor iterator (hooked)
extern "C" u8 *THISCALL ext_49e140(u8 *self, u32 name, u32 t);            // ResourceCollection::Lookup (hooked)

static inline void assert_hook() {
  void (*hook)() = *(void (**)())0x7003b0u;
  if (hook) hook();
  else __builtin_debugtrap();
}

// 0x6120f0 (no GC name) (id, b, c) ret 0xc: id other than 0 and 0x800 maps through the object at +0x13e7 (vt[4](id, b));
// otherwise the default 0x724ae8; then 0x612030(this; that, c).
static void THISCALL fn_6120f0(u8 *self, u32 id, u32 b, u32 c) {
  u8 *o = *(u8 **)(self + 0x13e7);
  if (id != 0 && id != 0x800) ext_612030(self, vcall<u32>(o, 4, id, b), c);
  else ext_612030(self, 0x724ae8u, c);
}
PCREG(6120f0, fn_6120f0);

// 0x5f3bf0 (no GC name) operator= of a {ptr, type byte} handle ret 4: unless self-assign, a type-4 old value is released
// (ptr->vt[0x28]()), a type-4 new value is copied through vt[0x24](), else the pointer is copied; then the type.
static u8 *THISCALL assign_5f3bf0(u8 *self, u8 *o) {
  if (o == self) return self;
  if (self[4] == 4) vcall<void>(*(u8 **)self, 0x28);
  if (o[4] == 4) *(u32 *)self = vcall<u32>(*(u8 **)o, 0x24);
  else *(u32 *)self = *(u32 *)o;
  self[4] = o[4];
  return self;
}
PCREG(5f3bf0, assign_5f3bf0);

// 0x56a030 CLinkMenu::Init2(): mode +0x1c5 == 2 with a link at +0x94: link->+0x1329f = db vt[0x4c](+0x44); mode 5:
// vt[0x64](0x10) and SetupScanLinesAndHelp (tail call).
static void THISCALL init2_56a030(u8 *self) {
  if (*(u32 *)(self + 0x1c5) == 2) {
    u8 *l = *(u8 **)(self + 0x94);
    if (l) *(u32 *)(l + 0x1329f) = vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x4c, *(u32 *)(self + 0x44));
  }
  if (*(u32 *)(self + 0x1c5) == 5) {
    vcall<void>(self, 0x64, 0x10u);
    ext_563a50(self);
  }
}
PCREG(56a030, init2_56a030);

// 0x5f2f70 SerialInfo_t::loadstring(string &s) ret 4: s.assign(cur, cur + strlen(cur)) with cur = +8; then
// cur += s.end - s.begin + 1; past the end +0xc calls the assert hook.
static void THISCALL loadstring_5f2f70(u8 *self, u8 *s) {
  const char *p = *(const char **)(self + 8);
  u32 n = 0;
  while (p[n]) n++;
  ext_5f2d60(s, (u32)p, (u32)p + n);
  *(u32 *)(self + 8) += *(u32 *)(s + 4) - *(u32 *)s + 1;
  if (*(u32 *)(self + 8) > *(u32 *)(self + 0xc)) assert_hook();
}
PCREG(5f2f70, loadstring_5f2f70);

// 0x65e130 (no GC name) destructor of a decal owner: vptr 0x6c48f4, ZGeometryDecal::End, then the eh vector destructor
// iterator over 0x10 entries of 0xc bytes at +4 with the empty destructor 0x4690b0. (The exe's SEH frame is not ported.)
static void THISCALL dtor_65e130(u8 *self) {
  *(u32 *)self = 0x6c48f4;
  ext_65f0f0(self);
  ext_63418c(self + 4, 0xc, 0x10, (void *)0x4690b0);
}
PCREG(65e130, dtor_65e130);

// 0x4e83f0 ZBinTree::Next(SBinTreeNode *n) ret 4 (nil node = +8): first child +4, else +8; else up the parent chain
// (+0) to the first ancestor whose +8 child is neither nil nor the node we came from, and returns that child; 0 at the root.
static u8 *THISCALL next_4e83f0(u8 *self, u8 *n) {
  u8 *nil = *(u8 **)(self + 8);
  u8 *c = *(u8 **)(n + 4);
  if (c != nil) return c;
  c = *(u8 **)(n + 8);
  if (c != nil) return c;
  for (u8 *p = *(u8 **)n; p != nil; p = *(u8 **)n) {
    u8 *r = *(u8 **)(p + 8);
    if (r != nil && r != n) return r;
    n = p;
  }
  return 0;
}
PCREG(4e83f0, next_4e83f0);

// 0x49e070 ResourceCollection::GetResourceText(const char *name) ret 4: no table (+4) returns 0; Lookup fails: logs
// (file 0x68f018, line 0xdd, fmt 0x68f040, name; printf slot 0x30) and returns 0; a found entry with bit 0 set returns
// entry + 1, otherwise the empty string 0x677b5a.
static u32 THISCALL getResourceText_49e070(u8 *self, u32 name) {
  u32 t = *(u32 *)(self + 4);
  if (!t) return 0;
  u8 *r = ext_49e140(self, name, t);
  if (!r) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x68f018u, 0xddu);
    (*(logf2_t *)(*(u8 **)log + 0x30))(log, 0x68f040u, name);
    return 0;
  }
  if (*r & 1) return (u32)r + 1;
  return 0x677b5a;
}
PCREG(49e070, getResourceText_49e070);

// 0x4a90b0 ZSIGTE::InitPointer(ZGEOM *g) ret 4: when g->vt[0x1e0](0x200011), g->vt[0x21c](&v) with v = {0.015f x3}
// (0x3c75c28f). The exe's stack cookie check is not ported.
static void THISCALL initPointer_4a90b0(u8 *self, u8 *g) {
  u32 v[3] = {0x3c75c28f, 0x3c75c28f, 0x3c75c28f};
  if (vcall<bool>(g, 0x1e0, 0x200011u)) vcall<void>(g, 0x21c, (u32)v);
}
PCREG(4a90b0, initPointer_4a90b0);
