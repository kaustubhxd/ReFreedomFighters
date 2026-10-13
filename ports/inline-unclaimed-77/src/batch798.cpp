// batch798.cpp - unclaimed-77 batch 798, claims 39 to 43 (docs/20-unclaimed-77.md), residue 4 rows.
// 5 functions: 0x4b0a40, 0x48f700, 0x565080, 0x4cc600, 0x564680
#include "ff.h"

extern "C" u8 FASTCALL ext_4cc400(u32 a, u32 b);  // stubbed: register helper (ecx, edx) returning al

// 0x4b0a40, CCutSequenceSoundInRoot::Run(REFTAB*, REFTAB*): ret 8 (both arguments ignored, ecx unused).
// o = *(g_pSysInterface + 0x1a9f) (unaligned dword); if o: p = o->vtbl[0xc4](o) (thiscall); if p: p[0x1209] = 1.
static void THISCALL cutSeqSoundRun(u8 *self, void *a1, void *a2) {
  u8 *si = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(si + 0x1a9f);
  (void)self; (void)a1; (void)a2;
  if (o) {
    void **vt = *(void ***)o;
    u8 *p = ((u8 *(THISCALL *)(void *))(*(void **)((u8 *)vt + 0xc4)))(o);
    if (p) p[0x1209] = 1;
  }
}
PCREG(4b0a40, cutSeqSoundRun);

// 0x48f700, ZEngineDataBase::DumpUsedResources(): no arguments.
// db = [0x700390]; o = db->vtbl[0x20](db, 0x68d798, 0x1443) (thiscall, callee pops 8);
// then with ecx = o->vtbl (as the exe does, odd but real): o->vtbl[0x2c](o, 0x68e1b8), caller pops 8 (cdecl).
static void engineDBDumpUsedResources() {
  u8 *db = G(u8 *, 0x700390);
  void **vt = *(void ***)db;
  u8 *o = ((u8 *(THISCALL *)(void *, u32, u32))(*(void **)((u8 *)vt + 0x20)))(db, 0x68d798u, 0x1443u);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[s]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                   : "+c"(vt2)
                   : [s] "i"(0x68e1b8), [o] "r"(o), [f] "r"(fn)
                   : "eax", "edx", "memory", "cc");
}
PCREG(48f700, engineDBDumpUsedResources);

// 0x565080, CFileWindow::ResetMessageTime(): self+0xca6 = (float)(g_pSysInterface->dword[0x30] - (int)(self->float[0xcaa] * K1)) * K2,
// K1 = float at 0x67862c, K2 = float at 0x6785e4 (cvttss2si, cvtdq2ps).
static void THISCALL fileWindowResetMessageTime(u8 *self) {
  float f = *(float *)(self + 0xcaa) * G(float, 0x67862c);
  int t = __builtin_ia32_cvttss2si(__extension__(__attribute__((vector_size(16))) float){f, 0, 0, 0});
  int now = *(int *)(G(u8 *, 0x70039c) + 0x30);
  *(float *)(self + 0xca6) = (float)(now - t) * G(float, 0x6785e4);
}
PCREG(565080, fileWindowResetMessageTime);

// 0x4cc600, QSortAlphaCompare(const void*, const void*): cdecl, two pointers to elements (each element is a pointer).
// Calls the register helper 0x4cc400(ecx = *p1, edx = *p2) and returns 1 if its al is nonzero, else -1.
static int qsortAlphaCompare(const void *p1, const void *p2) {
  u32 a = *(const u32 *)p1;
  u32 b = *(const u32 *)p2;
  return ext_4cc400(a, b) ? 1 : -1;
}
PCREG(4cc600, qsortAlphaCompare);

extern "C" void THISCALL ext_561e80(void *self, char *prompt);  // stubbed (GUESS): thiscall, one stack arg

// 0x564680, CFileWindow::ConstructControlPrompt(char*): ret 4. If dword[self+0xc9a] == 10: tail-calls vtbl[0xc8](self, prompt)
// when byte[self+0x18a] is nonzero, else 0x561e80(self, prompt). Otherwise returns (eax untouched, treated as void).
static void THISCALL fileWindowConstructControlPrompt(u8 *self, char *prompt) {
  if (*(u32 *)(self + 0xc9a) == 10) {
    if (self[0x18a]) {
      void **vt = *(void ***)self;
      ((void (THISCALL *)(void *, char *))(*(void **)((u8 *)vt + 0xc8)))(self, prompt);
    } else {
      ext_561e80(self, prompt);
    }
  }
}
PCREG(564680, fileWindowConstructControlPrompt);
