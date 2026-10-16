// batch0613.cpp - fresh-06 batch 13 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*hfn)();
static inline void handlerCall() {
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}
static inline void *logAt(u32 file, u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, file, line); }
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" void THISCALL ext_5002f0(void *v, u32 x);

// 0x4f20a0, ZWINDOWS::CopyDataBlock(DBLK*): ZWINGROUP::CopyDataBlock; then from the block: a geom id (render manager
// slot 0x58 -> +0x6f, passed to own slot 0x32c), the uint +0x73, a second geom id (-> +0x1db), an int whose != 0 goes to
// byte +0x5fb (+0x5fc cleared first); with a type-3 entry next, another int (!= 0 -> +0x5fc); with a type-3 entry next,
// a bool into +0x5fd. Then NextBlock.
extern "C" void THISCALL ext_44edd0(void *self, void *blk);
extern "C" void THISCALL ext_4e12e0(void *blk, u32 *v, s32 n);
extern "C" void THISCALL ext_4e11e0(void *blk, s32 *v, s32 n);
extern "C" void THISCALL ext_4e14a0(void *blk, u8 *v, s32 n);
extern "C" u32 THISCALL ext_4e1600(void *blk);
extern "C" void THISCALL ext_4e1b30(void *blk);
static void THISCALL winCopyDataBlock(u8 *self, void *blk) {
  u32 fr[4];
  ext_44edd0(self, blk);
  ext_4e12e0(blk, &fr[0], 1);
  u32 g = vcall<u32>(rmgr(), 0x58, fr[0]);
  *(u32 *)(self + 0x6f) = g;
  vcall<void>(self, 0x32c, g);
  ext_4e12e0(blk, (u32 *)(self + 0x73), 1);
  ext_4e12e0(blk, &fr[1], 1);
  *(u32 *)(self + 0x1db) = vcall<u32>(rmgr(), 0x58, fr[1]);
  ext_4e11e0(blk, (s32 *)&fr[2], 1);
  self[0x5fc] = 0;
  self[0x5fb] = fr[2] != 0;
  if ((u8)ext_4e1600(blk) == 3) {
    ext_4e11e0(blk, (s32 *)&fr[3], 1);
    self[0x5fc] = fr[3] != 0;
  }
  if ((u8)ext_4e1600(blk) == 3) ext_4e14a0(blk, self + 0x5fd, 1);
  ext_4e1b30(blk);
}
PCREG(4f20a0, winCopyDataBlock);

// 0x50d9e0 (no map name; GUESS: script native, stdcall (OpaqueCallParameters_t&)): argument 0 (array +4) is a value
// of type 3 (taken as is) or 4 (an object: its slot 0x34); any other type logs an error (0x69c8e0 line 0x111; sink
// with 0x69c6b0, 0x69c9b0), calls the handler (int3 when none; not exercised) and uses 0. The render manager's object
// (slot 0x138) gives n (slot 0x88(v, &n), n starts at 0); its slot 0x5c(v, argument 1's value + n, 2) runs and the
// result (array +8) element 0 gets n.
static void STDCALL scriptNative50d9e0(u8 *p) {
  u32 *a = (u32 *)ext_5003d0(*(void **)(p + 4), 0);
  u32 v;
  u8 t = ((u8 *)a)[4];
  if (t == 3) {
    v = a[0];
  } else if (t == 4) {
    v = vcall<u32>((void *)a[0], 0x34);
  } else {
    void *sink = logAt(0x69c8e0, 0x111);
    typedef void (*sinkFn)(void *, u32, u32);
    (*(sinkFn *)(*(u8 **)sink + 0x2c))(sink, 0x69c6b0, 0x69c9b0);
    handlerCall();
    v = 0;
  }
  u32 n = 0;
  vcall<void>(vcall<void *>(rmgr(), 0x138), 0x88, v, &n);
  void *o = vcall<void *>(rmgr(), 0x138);
  u32 *b = (u32 *)ext_5003d0(*(void **)(p + 4), 1);
  u32 nn = n;
  vcall<void>(o, 0x5c, v, b[0] + nn, 2u);
  ext_5002f0(ext_5003d0(*(void **)(p + 8), 0), nn);
}
PCREG(50d9e0, scriptNative50d9e0);

// 0x50dc60, ZScriptSceneInterface_t::CopyObjectPosDir(OpaqueCallParameters_t&) (stdcall): geoms for arguments 0 (dst)
// and 1 (src) (render manager slot 0x58); with both, the source's matrix and position (slot 0x80) go to the
// destination (slot 0x7c). A missing one logs an error (0x69db34 line 0x197 with 0x69dbbc for dst, line 0x198 with
// 0x69dbe0 for src).
static void STDCALL scriptCopyObjectPosDir(u8 *p) {
  float f[12];
  void *d = vcall<void *>(rmgr(), 0x58, *(u32 *)ext_5003d0(*(void **)(p + 4), 0));
  void *s = vcall<void *>(rmgr(), 0x58, *(u32 *)ext_5003d0(*(void **)(p + 4), 1));
  typedef void (*sinkFn)(void *, u32);
  if (d) {
    if (s) {
      vcall<void>(s, 0x80, f, f + 9);
      vcall<void>(d, 0x7c, f, f + 9);
      return;
    }
  } else {
    void *sink = logAt(0x69db34, 0x197);
    (*(sinkFn *)(*(u8 **)sink + 0x2c))(sink, 0x69dbbc);
    if (s) return;
  }
  void *sink = logAt(0x69db34, 0x198);
  (*(sinkFn *)(*(u8 **)sink + 0x2c))(sink, 0x69dbe0);
}
PCREG(50dc60, scriptCopyObjectPosDir);

// 0x48f5e0 (no map name; GUESS: find a free numbered file name, stdcall (n)): for i = 1..3 the name is formatted
// (sprintf 0x42ac56 into a 0x400-byte buffer with format 0x68d7d8, the engine's path string (slot 0x140 into a local
// MYSTR, c_str), n, i); the file system (0x700394) gets slot 0x5c(name), and when its slot 0x34(name, 0) is true the
// result is false. True when none of the three exists.
extern "C" const char *THISCALL ext_4cc1d0(void *str);
extern "C" void THISCALL ext_4cbec0(void *str);
extern "C" void ext_42ac56(char *buf, u32 fmt, const char *s, u32 n, u32 i);
static u8 STDCALL freeNumberedName(u32 n) {
  u8 fr[0x480];
  char *buf = (char *)fr;
  u8 *str = fr + 0x400;
  for (u32 i = 1; i <= 3; ++i) {
    void *s = vcall<void *>(G(void *, 0x70039c), 0x140, str);
    ext_42ac56(buf, 0x68d7d8, ext_4cc1d0(s), n, i);
    ext_4cbec0(str);
    vcall<void>(G(void *, 0x700394), 0x5c, buf);
    if (vcall<u8>(G(void *, 0x700394), 0x34, buf, 0u)) return 0;
  }
  return 1;
}
PCREG(48f5e0, freeNumberedName);
