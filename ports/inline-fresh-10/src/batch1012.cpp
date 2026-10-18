// batch1012.cpp - fresh-10 batch 12: pull-to-value, save refs, serial lists, xor swap, menu ctor/open, mouse,
// spot cone, zlib heap, disk text (slice 10).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FL(p, o) (*(float *)((u8 *)(p) + (o)))
#define SCENE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
extern "C" void THISCALL ext_4cbec0(void *);        // MYSTR::~MYSTR
extern "C" void THISCALL ext_4cbee0(void *, void *); // MYSTR::operator=
typedef void (*log2c_t)(void *, u32);

// 0x526f20 CPullToValueAccel::CalcDistance(float, float) (high; the stack words are not read): unless done (+0x19):
// d = slot2c() (ST0, stored as float); a = +0x25; x = |a| < [0x685278] (double 1/8192) ? log (0x6a0a20 line 0xcc,
// 0x6a0aa0), [0x67cd44] : (0 - +0x10)^2 / a * [0x67a6ac]; x += [0x679540]; x > d: +0xc = -a, done = 1.
static void THISCALL PullCalcDistance(u8 *self) {
  if (F32(self, 0x19)) return;
  float d = vcall<float>(self, 0x2c);
  float a = FL(self, 0x25);
  float x;
  if (G(double, 0x685278) > __builtin_fabs((double)a)) {
    void *pr = vcall<void *>(G(void *, 0x700390), 0x20, 0x6a0a20u, 0xccu);
    (*(log2c_t *)(*(u8 **)pr + 0x2c))(pr, 0x6a0aa0);
    x = G(float, 0x67cd44);
  } else {
    float t = 0.0f - FL(self, 0x10);
    x = t * t / a * G(float, 0x67a6ac);
  }
  x = x + G(float, 0x679540);
  if (x > d) {
    F32(self, 0xc) = F32(self, 0x25) ^ 0x80000000u;
    F32(self, 0x19) = 1;
  }
}
PCREG(526f20, PullCalcDistance);

// 0x49a160 ZSaveGame::AddRefTabRaw(REFTAB*) (medium): writes (kind, value) with slotc: 1 for null; 2 and the offset
// from scene.slot17c() when p is inside the block [scene+0x1c5d] (size at -8, low 29 bits); 3 and the offset from
// slot180() for the block [scene+0x44]; 4 and t.slot10(p) when the table ([rm+0x1aa3]+0x18).slot14(p) knows it; else 0, 0.
static void THISCALL AddRefTabRaw(void *self, u8 *p) {
  u32 kind = 0, val = 0;
  if (!p) {
    kind = 1;
  } else {
    u8 *s = SCENE;
    u8 *d = *(u8 **)(s + 0x1c5d);
    u8 *d2;
    if (p >= d && d && p < d + (*(u32 *)(d - 8) & 0x1fffffff)) {
      kind = 2;
      val = p - vcall<u8 *>(s, 0x17c);
    } else if (d2 = *(u8 **)(s + 0x44), p >= d2 && d2 && p < d2 + (*(u32 *)(d2 - 8) & 0x1fffffff)) {
      kind = 3;
      val = p - vcall<u8 *>(s, 0x180);
    } else {
      void *t = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x18);
      if (vcall<u8>(t, 0x14, p)) {
        kind = 4;
        t = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x18);
        val = vcall<u32>(t, 0x10, p);
      }
    }
  }
  vcall<void>(self, 0xc, kind);
  vcall<void>(self, 0xc, val);
}
PCREG(49a160, AddRefTabRaw);

// 0x600860 GUESS serialise opaque refs (thiscall w, x, buf): parent (+0x9c) first (recursive); then the two lists
// (+0x84 and +0x80, each offset by +0x98; count dword, 6-byte entries whose dword at +4 points at a record): for each,
// w.slot2c(buf.getOpaqueObjectIndex(record[x+0x9e])).
extern "C" u32 THISCALL ext_5fa220(void *, u32);
static void THISCALL SerialRefs600860(u8 *self, void *w, u8 *x, void *buf) {
  if (*(void **)(self + 0x9c)) SerialRefs600860(*(u8 **)(self + 0x9c), w, x, buf);
  u8 *l = *(u8 **)(self + 0x84) + F32(self, 0x98);
  for (u32 n = *(u32 *)l, i = 0; n; n--, i += 6) {
    u8 *rec = *(u8 **)(l + i + 4);
    vcall<void>(w, 0x2c, ext_5fa220(buf, *(u32 *)(rec + F32(x, 0x9e))));
  }
  l = *(u8 **)(self + 0x80) + F32(self, 0x98);
  for (u32 n = *(u32 *)l, i = 0; n; n--, i += 6) {
    u8 *rec = *(u8 **)(l + i + 4);
    vcall<void>(w, 0x2c, ext_5fa220(buf, *(u32 *)(rec + F32(x, 0x9e))));
  }
}
PCREG(600860, SerialRefs600860);

// 0x4f9520 GUESS xor-swap n bytes (fastcall a, b; stack n): n/4 dwords (32 bytes at a time with SSE when the ranges'
// last dwords do not cross, which the exe checks the same way), then the n%4 bytes. Each step is a ^= b, b ^= a,
// a ^= b, so overlapping ranges give the exe's exact result.
static void FASTCALL XorSwap(u8 *a, u8 *b, u32 n) {
  u32 q = n >> 2, i = 0;
  if (q) {
    if (q >= 8 && ((u32)a > (u32)b - 4 + q * 4 || (u32)a - 4 + q * 4 < (u32)b)) {
      u32 lim = q & ~7u;
      do {
        for (int h = 0; h < 0x20; h += 0x10) {
          __m128i x0 = _mm_loadu_si128((__m128i *)(a + h));
          __m128i x2 = _mm_xor_si128(_mm_loadu_si128((__m128i *)(b + h)), x0);
          _mm_storeu_si128((__m128i *)(a + h), x2);
          __m128i x1 = _mm_xor_si128(_mm_loadu_si128((__m128i *)(b + h)), x2);
          _mm_storeu_si128((__m128i *)(b + h), x1);
          x0 = _mm_xor_si128(_mm_loadu_si128((__m128i *)(a + h)), x1);
          _mm_storeu_si128((__m128i *)(a + h), x0);
        }
        a += 0x20;
        b += 0x20;
        i += 8;
      } while (i < lim);
    }
    for (; i < q; i++) {
      volatile u32 *pa = (u32 *)a, *pb = (u32 *)b;
      *pa ^= *pb;
      *pb ^= *pa;
      *pa ^= *pb;
      a += 4;
      b += 4;
    }
  }
  for (u32 k = n & 3; k; k--) {
    volatile u8 *pa = a, *pb = b;
    *pa ^= *pb;
    *pb ^= *pa;
    *pa ^= *pb;
    a++;
    b++;
  }
}
PCREG(4f9520, XorSwap);

// 0x56fea0 CSewerMenu::CSewerMenu() (high; SEH frame): CBaseWindow(); vtable 0x6a858c; +0x1a0 = 0x10101; message ids
// +0x1a4/+0x1a6 = scene.RegisterZMsg(0x6a86b0 / 0x6a86c8, 0, 0x6a8684, 0x17 / 0x18); +0x22c..+0x234, +0x1c0, +0x1c4 = 0.
extern "C" void THISCALL ext_561020(void *);
static u8 *THISCALL SewerMenuCtor(u8 *self) {
  ext_561020(self);
  F32(self, 0) = 0x6a858c;
  F32(self, 0x1a0) = 0x10101;
  *(u16 *)(self + 0x1a4) = (u16)vcall<u32>(SCENE, 0x114, 0x6a86b0u, 0u, 0x6a8684u, 0x17u);
  *(u16 *)(self + 0x1a6) = (u16)vcall<u32>(SCENE, 0x114, 0x6a86c8u, 0u, 0x6a8684u, 0x18u);
  F32(self, 0x22c) = 0;
  F32(self, 0x230) = 0;
  F32(self, 0x234) = 0;
  F32(self, 0x1c0) = 0;
  F32(self, 0x1c4) = 0;
  return self;
}
PCREG(56fea0, SewerMenuCtor);

// 0x4f3b20 ZWINDOWS::UpdateMouse() (high): delta (+0x87) = mouse (rm+0x9e7/+0x9eb) - last (+0x7f/+0x83); last = mouse;
// v2scalar(delta, +0x97); slot308(&t); v2add(t, delta); unchanged position (v2len(delta) == 0.0) and no pending flag
// (+0x63b): return +0x1d3; else clear the flag and return slot304(&t).
extern "C" void FASTCALL ext_4dffb0(float *, float);   // the float goes on the stack (fastcall passes only ints in registers)
extern "C" void FASTCALL ext_4dfd80(float *, const float *);
extern "C" float FASTCALL ext_4dfda0(const float *);
static u32 THISCALL UpdateMouse(u8 *self) {
  u8 *rm = *(u8 **)0x70039c;
  FL(self, 0x87) = FL(rm, 0x9e7) - FL(self, 0x7f);
  u8 *rm2 = *(u8 **)0x70039c;
  FL(self, 0x8b) = FL(rm2, 0x9eb) - FL(self, 0x83);
  F32(self, 0x7f) = F32(rm, 0x9e7);
  F32(self, 0x83) = F32(rm2, 0x9eb);
  ext_4dffb0((float *)(self + 0x87), bitsf(F32(self, 0x97)));
  float t[2];
  vcall<void>(self, 0x308, t);
  ext_4dfd80(t, (float *)(self + 0x87));
  float len = ext_4dfda0((float *)(self + 0x87));
  if (len == G(float, 0x6785d0) && !self[0x63b]) return F32(self, 0x1d3);
  self[0x63b] = 0;
  return vcall<u32>(self, 0x304, t);
}
PCREG(4f3b20, UpdateMouse);

// 0x656c60 GUESS spot light cone setup (stdcall out, in): copies +0x10/+0x14; inner = min(in+0x18, in+0x1c - 1)
// (+0x18); +0x1c; +0x20 = 1 / (+0x1c - inner); angles +0x28/+0x24 and their cosines (+0x30/+0x2c, CRT cos on the
// double); +0x34 = equal angles ? 1.0 : 1 / (cos28 - cos24); +0x38.
static void STDCALL SpotCone(u8 *out, u8 *in) {
  float one = G(float, 0x678858);
  F32(out, 0x10) = F32(in, 0x10);
  F32(out, 0x14) = F32(in, 0x14);
  float a = FL(in, 0x1c) - one;
  float b = FL(in, 0x18);
  FL(out, 0x18) = b > a ? a : b;
  float x = FL(in, 0x1c);
  FL(out, 0x1c) = x;
  FL(out, 0x20) = one / (x - FL(out, 0x18));
  F32(out, 0x28) = F32(in, 0x28);
  F32(out, 0x24) = F32(in, 0x24);
  FL(out, 0x30) = (float)crt::cos((double)FL(in, 0x28));
  float c24 = (float)crt::cos((double)FL(in, 0x24));
  FL(out, 0x2c) = c24;
  if (FL(in, 0x24) - FL(in, 0x28) == G(float, 0x6785d0)) {
    F32(out, 0x34) = 0x3f800000;
  } else {
    FL(out, 0x34) = G(float, 0x678858) / (FL(out, 0x30) - c24);
  }
  F32(out, 0x38) = F32(in, 0x38);
}
PCREG(656c60, SpotCone);

// 0x630ce0 zlib pqdownheap(deflate_state*, ct_data* tree, int k) (medium; cdecl): heap +0xb54, heap_len +0x1448,
// depth +0x1450; smaller(n, m) = freq[n] < freq[m] || (== && depth[n] <= depth[m]).
static inline bool Smaller(u8 *tree, u8 *s, u32 n, u32 m) {
  u16 fn = *(u16 *)(tree + n * 4), fm = *(u16 *)(tree + m * 4);
  return fn < fm || (fn == fm && s[0x1450 + n] <= s[0x1450 + m]);
}
static void PqDownHeap(u8 *s, u8 *tree, s32 k) {
  s32 *heap = (s32 *)(s + 0xb54);
  s32 v = heap[k];
  s32 j = k << 1;
  while (j <= *(s32 *)(s + 0x1448)) {
    if (j < *(s32 *)(s + 0x1448) && Smaller(tree, s, heap[j + 1], heap[j])) j++;
    if (Smaller(tree, s, v, heap[j])) break;
    heap[k] = heap[j];
    k = j;
    j <<= 1;
  }
  heap[k] = v;
}
PCREG(630ce0, PqDownHeap);

// 0x4269e0 ZSysFileGC::GetFreeDiskSpace(const char*) (low; three stack words; /GS, SEH frame): when the MYSTR +0xc is
// empty it becomes sys.slot140() (a temporary MYSTR); then sys.slot190().slot198 (cdecl) (o, arg0, 0x678d1c, +0xc text,
// +0x8c text, arg1, arg2).
extern "C" u32 THISCALL ext_4cc5f0(void *);
typedef void (*fmt7_t)(void *, u32, u32, u32, u32, u32, u32);
static void THISCALL GetFreeDiskSpace(u8 *self, u32 a0, u32 a1, u32 a2) {
  if (!ext_4cc5f0(self + 0xc)) {
    u8 t[0x80];
    void *r = vcall<void *>(G(void *, 0x70039c), 0x140, t);
    ext_4cbee0(self + 0xc, r);
    ext_4cbec0(t);
  }
  void *o = vcall<void *>(G(void *, 0x70039c), 0x190);
  (*(fmt7_t *)(*(u8 **)o + 0x198))(o, a0, 0x678d1c, F32(self, 0xc), F32(self, 0x8c), a1, a2);
}
PCREG(4269e0, GetFreeDiskSpace);

// 0x56df60 CMultiplayerStat::OnWindowOpen(unsigned, bool) (high): first open (bool): SetupScanLinesAndHelp();
// ZVideoSelector::OnWindowOpen; GetSystem() (slot84, no stack words: the pushed 5 is SetActionMap's, GUESS from the
// callees' ret sizes).SetActionMap(5); for players 0..3: entry [0x7003b8]+0x2c3d+4i: (+0x44).SendCommand(entry,
// RegisterZMsg(0x6a6610, 0, 0x6a82f4, 0x89), 0); GetGameOSD(i).slot88(0) when there is one. Then +0x94 flags
// (+0x13299 = 1, +0x1043 = 0); first open: UpdateCharObjs(). False (AL).
extern "C" void THISCALL ext_563a50(void *);
extern "C" void THISCALL ext_563110(void *, u32, u32);
extern "C" void THISCALL ext_4f2f60(void *, u32);
extern "C" void *THISCALL ext_589c20(void *, u32);
extern "C" void THISCALL ext_56e050(void *);
static u8 THISCALL MultiplayerStatOnWindowOpen(u8 *self, u32 a, u32 b) {
  if ((u8)b) ext_563a50(self);
  ext_563110(self, a, b);
  ext_4f2f60(vcall<void *>(self, 0x84), 5);
  for (u32 i = 0; i < 4; i++) {
    u32 ent = *(u32 *)(G(u8 *, 0x7003b8) + i * 4 + 0x2c3d);
    if (ent) {
      u32 id = vcall<u32>(SCENE, 0x114, 0x6a6610u, 0u, 0x6a82f4u, 0x89u);
      vcall<void>(*(void **)(self + 0x44), 0x130, ent, id & 0xffff, 0u);
    }
    void *osd = ext_589c20(G(void *, 0x7003b8), i);
    if (osd) vcall<void>(osd, 0x88, 0u);
  }
  if (*(u8 **)(self + 0x94)) {
    (*(u8 **)(self + 0x94))[0x13299] = 1;
    (*(u8 **)(self + 0x94))[0x1043] = 0;
  }
  if ((u8)b) ext_56e050(self);
  return 0;
}
PCREG(56df60, MultiplayerStatOnWindowOpen);
