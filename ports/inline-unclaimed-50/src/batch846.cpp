// batch846.cpp - area 50 (residue-10 list): ZDamageBox2::FrameUpdate() [medium, vt]. Per frame: for each entry of the owner's
// list (vt +0x4c starts, vt +0x5c(&valid) steps; the entry's object comes from the global manager's vt +0x58), the entry's
// centre goes to its vt +0x84, the object at this+0x44 gets it (vt +0x8c) and is asked (vt +0x180(-10, centre)).
// When that is true the timer at +0x8b advances by the frame time (engine +0x48) and past +0x50 the second timer (+0x9b)
// advances past 1/(+0x97) and then fires once: the global manager's render slot 0x114 is called with six words
// (name "DamageInfo", 0, file, line 0x83, &this+0x57, 0) and the entry's vt +0x128 gets the 16-bit id. When false, the
// timer at +0x8f advances and past +0x87 both timers reset.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4daf90(void *geom, float *centre);   // ZBaseGeom::GetCen (not ported here)

static void THISCALL DamageBox2_FrameUpdate(u8 *self) {
  if (!F8(self, 0x54)) return;
  void *owner = FP(self, 0x48);
  if (!owner) return;
  u32 valid = 0;
  vcall<void>(owner, 0x4c, &valid);
  void *cur = vcall<void *>(FP(self, 0x48), 0x5c, &valid);
  if (!valid) return;
  do {
    u8 *ent = (u8 *)vcall<void *>(FP(G(void *, 0x70039c), 0x9b), 0x58, cur);
    float v[3];
    ext_4daf90(FP(ent, 8), v);
    vcall<void>(ent, 0x84, v);
    void *A = FP(self, 0x44);
    vcall<void>(A, 0x8c, v);
    u8 al = vcall<u8>(A, 0x180, v, -10.0f);
    float dt = FF(G(u8 *, 0x70039c), 0x48);
    if (al) {
      float x = dt + FF(self, 0x8b);
      FF(self, 0x8b) = x;
      if (x > FF(self, 0x50)) {
        float inv = 1.0f / FF(self, 0x97);
        float y = dt + FF(self, 0x9b);
        FF(self, 0x9b) = y;
        if (y > inv) {
          F32(self, 0x7f) = F32(self, 0x93);
          u32 id = vcall<u32>(FP(G(void *, 0x70039c), 0x9b), 0x114, (const char *)0x69eaac, 0u,
                              (const char *)0x6b695c, 0x83u, (u32)(unsigned long)(self + 0x57), 0u);
          vcall<void>(ent, 0x128, (u32)(u16)id);
          F32(self, 0x9b) = 0;
          F32(self, 0x8f) = 0;
        }
      }
    } else {
      float z = dt + FF(self, 0x8f);
      FF(self, 0x8f) = z;
      if (z > FF(self, 0x87)) {
        F32(self, 0x8b) = 0;
        F32(self, 0x8f) = 0;
      }
    }
    cur = vcall<void *>(FP(self, 0x48), 0x5c, &valid);
  } while (valid);
}
PCREG(5dba60, DamageBox2_FrameUpdate);
