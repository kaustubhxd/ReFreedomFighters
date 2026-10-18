// batch1102.cpp - fresh-11 batch 2: slice-11 functions of 53 to 90 bytes. Names from the GC name map; GUESS otherwise.
#include "ff.h"

static inline u8 *Eng9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x4b5970 CCutSequenceSoundStartStop::Init() [high]: GetInput(&local=0), slot +0x98(&local), slot +0x68(0x10, 0).
extern "C" u32 THISCALL ext_6352f0(void *self, void *db);
static u32 THISCALL CutSoundStartStop_Init(u8 *self) {
  u32 local = 0;
  ext_6352f0(self, &local);
  vcall<void>(self, 0x98, &local);
  return vcall<u32>(self, 0x68, 0x10u, 0u);
}
PCREG(4b5970, CutSoundStartStop_Init);

// 0x60fd70 GUESS set two device states (fastcall a, b): device [0x724a00] slot +0xc8 (COM stdcall):
// state 0x19 = a only when a differs from the cache at 0x72496c, then state 0x18 = b.
typedef u32(STDCALL *setstate_t)(void *, u32, u32);
static u32 FASTCALL SetStates60fd70(u32 a, u32 b) {
  if (G(u32, 0x72496c) != a) {
    G(u32, 0x72496c) = a;
    void *d = G(void *, 0x724a00);
    (*(setstate_t *)(*(u8 **)d + 0xc8))(d, 0x19, a);
  }
  void *d = G(void *, 0x724a00);
  return (*(setstate_t *)(*(u8 **)d + 0xc8))(d, 0x18, b);
}
PCREG(60fd70, SetStates60fd70);

// 0x54e3f0 ZSoundStreamer::Initialize() [medium]: per entry i (stride 0x6b, count at +0x1c5 re-read each pass):
// +0x1c = i, +0x68 = 0 (byte), +0x5b = this, +0x42 = 0 (byte); then +0x1c9 = 0.
static void THISCALL SoundStreamer_Initialize(u8 *self) {
  for (s32 i = 0; i < *(s32 *)(self + 0x1c5); i++) {
    u8 *e = self + 0x6b * i;
    *(s32 *)(e + 0x1c) = i;
    e[0x68] = 0;
    *(u8 **)(e + 0x5b) = self;
    e[0x42] = 0;
  }
  self[0x1c9] = 0;
}
PCREG(54e3f0, SoundStreamer_Initialize);

// 0x4d1cb0 GUESS lookup: r = 0x4d1cf0(key); r ? r->+0xc : log (file 0x695fec line 0x222, msg 0x6960e8) and 0.
extern "C" u8 *THISCALL ext_4d1cf0(void *self, u32 key);
typedef void *(THISCALL *logopen_t)(void *, u32, u32);
typedef void (*logmsg_t)(void *, u32);
static u32 THISCALL Lookup4d1cb0(u8 *self, u32 key) {
  u8 *r = ext_4d1cf0(self, key);
  if (r) return *(u32 *)(r + 0xc);
  void *lg = G(void *, 0x700390);
  void *l2 = (*(logopen_t *)(*(u8 **)lg + 0x20))(lg, 0x695fec, 0x222);
  (*(logmsg_t *)(*(u8 **)l2 + 0x2c))(l2, 0x6960e8);
  return 0;
}
PCREG(4d1cb0, Lookup4d1cb0);

// 0x4a2ff0 ZPlaySound::CopyEventDataBlock(DBREAD&) [medium]: +0x48 = uint, +0x4c = uint != 0, +0x4d = ushort,
// +0x4f = uint != 0 (EAX keeps the last call's upper bytes).
extern "C" u32 THISCALL ext_4e5e60(void *db);
extern "C" u32 THISCALL ext_4e5e40(void *db);
static u32 THISCALL PlaySound_CopyEventDataBlock(u8 *self, void *db) {
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  self[0x4c] = ext_4e5e60(db) != 0;
  *(u16 *)(self + 0x4d) = (u16)ext_4e5e40(db);
  u32 r = ext_4e5e60(db);
  self[0x4f] = r != 0;
  return (r & 0xffffff00) | (r != 0);
}
PCREG(4a2ff0, PlaySound_CopyEventDataBlock);

// 0x4f11f0 GUESS: slot +0x70(&{x, y, z}) with three float arguments copied to a local vector.
static u32 THISCALL Vec3Fwd4f11f0(u8 *self, u32 x, u32 y, u32 z) {
  u32 v[3] = {x, y, z};
  return vcall<u32>(self, 0x70, v);
}
PCREG(4f11f0, Vec3Fwd4f11f0);

// 0x57bcb0 ZFFLoadError::Init2() [medium]: background 0x6aa484; o = eng9b->slot +0x138(); local = 0;
// o->slot +0x88(0x6a6c28, &local); this+0xcae = local.
extern "C" u32 THISCALL ext_563510(void *self, u32 pic);
static u32 THISCALL FFLoadError_Init2(u8 *self) {
  ext_563510(self, 0x6aa484);
  void *o = vcall<void *>(Eng9b(), 0x138);
  u32 local = 0;
  vcall<void>(o, 0x88, 0x6a6c28u, &local);
  *(u32 *)(self + 0xcae) = local;
  return local;
}
PCREG(57bcb0, FFLoadError_Init2);

// 0x548ef0 CShatter::CopyEventDataBlock(DBREAD&) [high]: +0x4c, +0x50, +0x54 = uint; +0x58 = 0, or one more uint
// when the next type byte (not 0xff) has low six bits 0xb. EAX is the type pointer with AL patched on the skip paths.
static u32 THISCALL Shatter_CopyEventDataBlock(u8 *self, u8 **db) {
  *(u32 *)(self + 0x4c) = ext_4e5e60(db);
  *(u32 *)(self + 0x50) = ext_4e5e60(db);
  *(u32 *)(self + 0x54) = ext_4e5e60(db);
  *(u32 *)(self + 0x58) = 0;
  u32 p = (u32)*db;
  u8 b = *(u8 *)p;
  if (b == 0xff) return (p & 0xffffff00) | b;
  b &= 0x3f;
  if (b != 0xb) return (p & 0xffffff00) | b;
  u32 r = ext_4e5e60(db);
  *(u32 *)(self + 0x58) = r;
  return r;
}
PCREG(548ef0, Shatter_CopyEventDataBlock);

// 0x63ae30 ZDrawArray<ZLightDrawEntry,...>::Add() [medium]: from block +8, walk blocks (next at +8, stop at the first
// again or 0) for one whose word +2 is not 0xffff; else 0x63b340() must add one (else 0). count +0xc++, tail
// 0x63b0c0(block).
extern "C" bool THISCALL ext_63b340(void *self);
extern "C" u32 THISCALL ext_63b0c0(void *blk);
static u32 THISCALL LightDrawArray_Add(u8 *self) {
  u8 *first = *(u8 **)(self + 8);
  if (first) {
    for (;;) {
      u8 *b = *(u8 **)(self + 8);
      if (*(u16 *)(b + 2) != 0xffff) {
        *(u32 *)(self + 0xc) += 1;
        return ext_63b0c0(b);
      }
      u8 *n = *(u8 **)(b + 8);
      *(u8 **)(self + 8) = n;
      if (first == n || !n) break;
    }
  }
  if (!ext_63b340(self)) return 0;
  *(u32 *)(self + 0xc) += 1;
  return ext_63b0c0(*(u8 **)(self + 8));
}
PCREG(63ae30, LightDrawArray_Add);

// 0x6401f0 ZDrawBase::SetMemorySize(unsigned int) [high]: printf(0x6c25f0, (double)((float)n * [0x6c2800])); +0x10 = n.
extern "C" u32 ext_42ab62(u32 fmt, ...);
static u32 THISCALL DrawBase_SetMemorySize(u8 *self, u32 n) {
  float f = (float)(double)n;
  f = f * G(float, 0x6c2800);
  u32 r = ext_42ab62(0x6c25f0, (double)f);
  *(u32 *)(self + 0x10) = n;
  return r;
}
PCREG(6401f0, DrawBase_SetMemorySize);

// 0x4b41b0 CCutSequenceCharacterSound::FrameUpdate() [high]: when +0x181 is set: needs +0x64 and +0x6c; s =
// eng9b->slot +0x60(+0x6c); stop slot +0xa0 unless s exists with 0 < s+0x70 (or NaN). Then slot +0x68(0x10, 0).
static void THISCALL CutCharSound_FrameUpdate(u8 *self) {
  if (self[0x181]) {
    if (!*(u32 *)(self + 0x64)) return;
    u32 h = *(u32 *)(self + 0x6c);
    if (!h) return;
    u8 *s = vcall<u8 *>(Eng9b(), 0x60, h);
    if (s && !(*(float *)(s + 0x70) <= 0.0f)) return;
    vcall<void>(self, 0xa0);
  }
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(4b41b0, CutCharSound_FrameUpdate);

// 0x57d830 GUESS id remap (fastcall id): ids with high bits pass through; else find range i in the table at
// [0x70039c]+0x190b (16-byte entries: base, ?, ?, len) with base <= id < base+len (signed) -> (i<<16) + id - base.
static u32 FASTCALL Remap57d830(s32 id) {
  if ((u32)id & 0xffff0000) return id;
  s32 *e = *(s32 **)(G(u8 *, 0x70039c) + 0x190b);
  if (!e) return 0xffffffff;
  for (u32 i = 0;; i++, e += 4) {
    s32 base = e[0];
    if (base <= id && base + e[3] > id) return (i << 16) - base + id;
    if (!(e + 4)) return 0xffffffff;
  }
}
PCREG(57d830, Remap57d830);

// 0x4e80f0 ZBinTree::Depth(SBinTreeNode*) [high]: node 0 = root (+4); nil = +8; 1 + max(depth(left +4),
// depth(right +8)) through slot +0x1c, each side 1 when nil.
static s32 THISCALL BinTree_Depth(u8 *self, u8 *node) {
  if (!node) node = *(u8 **)(self + 4);
  s32 d1 = 1, d2 = 1;
  u32 l = *(u32 *)(node + 4);
  if (l != *(u32 *)(self + 8)) d1 = vcall<s32>(self, 0x1c, l) + 1;
  u32 r = *(u32 *)(node + 8);
  if (r != *(u32 *)(self + 8)) d2 = vcall<s32>(self, 0x1c, r) + 1;
  return d1 < d2 ? d2 : d1;
}
PCREG(4e80f0, BinTree_Depth);

// 0x659330 GUESS init (size a, ZOffsetAlloc* b): +8 = b, +0 = a, +4 = (b+4)->Alloc(a, true); on -1 log
// (file 0x6c44fc line 0x7d, slot +0x30 msg 0x6c4560) and +4 = 0.
extern "C" u32 THISCALL ext_4cd9b0(void *alloc, u32 size, u32 flag);
static u32 THISCALL Init659330(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 8) = b;
  *(u32 *)self = a;
  u32 r = ext_4cd9b0((void *)(b + 4), a, 1);
  *(u32 *)(self + 4) = r;
  if (r != 0xffffffff) return r;
  void *lg = G(void *, 0x700390);
  void *l2 = (*(logopen_t *)(*(u8 **)lg + 0x20))(lg, 0x6c44fc, 0x7d);
  typedef u32 (*logmsg30_t)(void *, u32);
  r = (*(logmsg30_t *)(*(u8 **)l2 + 0x30))(l2, 0x6c4560);
  *(u32 *)(self + 4) = 0;
  return r;
}
PCREG(659330, Init659330);

// 0x57a9f0 ZFFMissingControllerDialog::Load2() [medium]: base Load2; ([this+0x94])+0x132ab = eng9b->slot +0x4c(+0x44);
// +0x184 = [[0x7003a0]+0x6c]; +0x180 = (+0x54)->slot +0x25c(0x6a69e0, 0).
extern "C" void THISCALL ext_5626c0(void *self);
static u32 THISCALL MissingCtlDialog_Load2(u8 *self) {
  ext_5626c0(self);
  u32 arg = *(u32 *)(self + 0x44);
  u8 *o = *(u8 **)(self + 0x94);
  *(u32 *)(o + 0x132ab) = vcall<u32>(Eng9b(), 0x4c, arg);
  *(u32 *)(self + 0x184) = *(u32 *)(G(u8 *, 0x7003a0) + 0x6c);
  u32 r = vcall<u32>(*(void **)(self + 0x54), 0x25c, 0x6a69e0u, 0u);
  *(u32 *)(self + 0x180) = r;
  return r;
}
PCREG(57a9f0, MissingCtlDialog_Load2);

// 0x4d0630 GUESS pool get: pop from the free stack (+0x1c4 count, entries +0x34); else take the next id
// (+0x11530[+0x12130++]) and object (+0xc628[+0xd628++]), object+0xc = id, (this+0x1ea)->slot 0(object); id.
static u32 THISCALL PoolGet4d0630(u8 *self) {
  u32 n = *(u32 *)(self + 0x1c4);
  if (n) {
    n--;
    *(u32 *)(self + 0x1c4) = n;
    return *(u32 *)(self + 0x34 + n * 4);
  }
  u32 a = *(u32 *)(self + 0x12130);
  u32 c = *(u32 *)(self + 0xd628);
  u32 id = *(u32 *)(self + 0x11530 + a * 4);
  *(u32 *)(self + 0x12130) = a + 1;
  u8 *o = *(u8 **)(self + 0xc628 + c * 4);
  *(u32 *)(self + 0xd628) = c + 1;
  *(u32 *)(o + 0xc) = id;
  vcall<void>(self + 0x1ea, 0, o);
  return id;
}
PCREG(4d0630, PoolGet4d0630);

// 0x430c70 GUESS find (vector* v, offset n) in [this+0, this+4): fails (-1) when n + v.size > buffer size;
// p = 0x42b1e0(fastcall: begin+n, end; v.begin, v.end, n); p == end ? -1 : p - begin.
typedef u32(FASTCALL *find_t)(u32, u32, u32, u32, u32);
extern "C" u32 FASTCALL ext_42b1e0(u32 from, u32 end, u32 s, u32 e, u32 n);
static u32 THISCALL Find430c70(u32 *self, u32 *v, u32 n) {
  u32 b = self[0], e = self[1];
  u32 s = v[0], len = v[1] - s;
  if (n + len > e - b) return 0xffffffff;
  u32 p = ext_42b1e0(b + n, e, s, len + s, n);
  return p != e ? p - b : 0xffffffff;
}
PCREG(430c70, Find430c70);

// 0x4c2170 ZSoundAnimation::Load(ZLoadGame*) [high]: clear flag 0x40; load +0x48 (slot +0x44), +0x4a, +0x52
// (slot +0x40), +0x56 (slot +0x50); call [0x7003b0] (int3 when null); GetValues(0); true.
extern "C" void THISCALL ext_4c0b00(void *self, u32 db);
static bool THISCALL SoundAnimation_Load(u8 *self, void *ld) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(ld, 0x44, self + 0x48);
  vcall<void>(ld, 0x40, self + 0x4a);
  vcall<void>(ld, 0x40, self + 0x52);
  vcall<void>(ld, 0x50, self + 0x56);
  typedef void (*cb_t)();
  cb_t f = G(cb_t, 0x7003b0);
  if (!f) __builtin_trap();
  f();
  ext_4c0b00(self, 0);
  return true;
}
PCREG(4c2170, SoundAnimation_Load);

// 0x622fb0 GUESS Latin-1 to UTF-8 (cdecl: ?, &src, src_end, &dst, dst_end): bytes >= 0x80 become two bytes;
// stops at src_end or when dst is full. Returns &dst (src_end when nothing to do).
static u32 Latin1ToUtf8(u32, u8 **src, u8 *send, u8 **dst, u8 *dend) {
  if (*src == send) return (u32)send;
  do {
    u8 c = **src;
    u8 *q;
    if (c & 0x80) {
      u8 *p = *dst;
      if ((s32)(dend - p) < 2) break;
      *p = (c >> 6) | 0xc0;
      (*dst)++;
      c = (c & 0x3f) | 0x80;
      q = *dst;
    } else {
      q = *dst;
      if (q == dend) break;
    }
    *q = c;
    (*dst)++;
    (*src)++;
  } while (*src != send);
  return (u32)dst;
}
PCREG(622fb0, Latin1ToUtf8);

// 0x57b670 GUESS window open: background 0x6a6f98; w = slot +0x84(); w->slot +0x34c(0x10000, 0, +0x44, 10.0f, 0);
// 0x57b6d0(); OnWindowOpen(a, b); returns false (AL cleared, upper EAX from OnWindowOpen).
extern "C" void THISCALL ext_57b6d0(void *self);
extern "C" u32 THISCALL ext_563110(void *self, u32 a, u32 b);
static u32 THISCALL WindowOpen57b670(u8 *self, u32 a, u32 b) {
  ext_563510(self, 0x6a6f98);
  void *w = vcall<void *>(self, 0x84);
  vcall<void>(w, 0x34c, 0x10000u, 0u, *(u32 *)(self + 0x44), 0x41200000u, 0u);
  ext_57b6d0(self);
  return ext_563110(self, a, b) & 0xffffff00;
}
PCREG(57b670, WindowOpen57b670);
