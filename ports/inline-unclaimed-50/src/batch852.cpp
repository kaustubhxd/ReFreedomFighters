// batch852.cpp - area 50 (residue-9 candidate): 0x4aea10 [359 instr, thiscall, no args; no name in the map (GUESS: a pass
// over the table at [0x7003b8] that picks and pairs fire-like entries)]. Three phases, as the asm has them:
//  1. For each table entry (count at +4, pointers from +8): skipped unless the entry's sub-object has flag 0x1000 at +0x3c,
//     vt +0x438 and vt +0x2fc both answer false, and byte +0x776 is set. Then vt +0x57c gives two vectors; the timer +0x624
//     is raised by 25*dt while it is below 30; a 0x35-byte record is added: the two vectors (0x0c each), 0x18 more bytes
//     (not written by the callee; the exe copies stack junk there, the port copies zeros), the object at +0x30 and a flag
//     byte at +0x34. At 60 records the exe logs an overflow and stops (the harness keeps its table at 50 entries).
//  2. The records are sorted (exe code, 0x4ae3e0). Pairs (i, j): j not flagged, key(j) <= key(i) + 60, and the pair test
//     0x4ae5a0 (stood in by the harness, logged) answers true: i and j are appended to the list at the stack.
//  3. Up to nine list entries are popped; each swaps its record along the keys, with the pair test applied in both
//     directions (a true answer appends the pair). The only outputs are the timers, the calls and the record swaps.
// The exe keeps these values in registers and stack slots; the port keeps the same slots (V_* names) and the same
// register values between the phases, so the flow matches the asm line by line.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" void FASTCALL ext_4ae3e0(void *begin, void *end);             // sort of 0x35-byte records (exe code)
extern "C" u8 THISCALL ext_4ae5a0(void *self, void *recA, void *recB);    // pair test (stood in by the harness)

static void SwapRec(u8 *a, u8 *b) {
  for (u32 k = 0; k < 0x35; k++) {
    u8 t = a[k];
    a[k] = b[k];
    b[k] = t;
  }
}

// 0x4aea10 (name GUESS).
static void THISCALL Pass4aea10(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *table = G(u8 *, 0x7003b8);
  u8 R[0x35 * 64];                                  // records at R + i*0x35 (the exe's ebp-0xd64 base)
  for (u32 i = 0; i < sizeof R; i++) R[i] = 0;
  u32 S[160];                                       // list: S[0] is the count word ([ebp-0xf8]); S[k] = [ebp-0xf8+4k]
  for (u32 i = 0; i < 160; i++) S[i] = 0;

  float V_db4f = F32(eng, 0x48) * 25.0f;            // [ebp-0xdb4]: dt*25 (phase 1), then the pair threshold
  s32 V_db4i = 0;                                   // [ebp-0xdb4] read as an offset (phase 3)
  float V_db8 = 0.0f;                               // [ebp-0xdb8]: key of the popped record
  float V_dc0 = 0.0f;                               // [ebp-0xdc0]
  s32 V_dac = 0;                                    // record count
  s32 V_da8 = 0;                                    // list length
  s32 V_da4 = 0;                                    // record index in use
  s32 V_db0 = 0;                                    // record offset in use
  s32 V_dc4 = 0;                                    // pop counter

  // ---------------------------------------------------------------- phase 1: gather the records
  {
    u32 *slot = (u32 *)(table + 8);
    u32 *tend = (u32 *)(table + 4 * (U32(table, 4) + 2));
    if (slot != tend) {
      for (;;) {
        u8 *obj = (u8 *)*slot;
        u8 *sub = (u8 *)U32(obj, 8);
        bool skip = !(U32(sub, 0x3c) & 0x1000);
        if (!skip) skip = vcall<u8>(obj, 0x438) != 0;
        if (!skip) skip = vcall<u8>(obj, 0x2fc) != 0;
        if (!skip) skip = U8(obj, 0x776) == 0;
        if (!skip) {
          s32 n = V_dac;
          if (n >= 0x3c) {
            // overflow: logged, then the gather stops (the harness never reaches this)
            u8 *lg = G(u8 *, 0x700390);
            u8 *sink = vcall<u8 *>(lg, 0x20, (u32)0x690d54, 0x88u);
            typedef void (*printf_t)(void *, const char *);   // cdecl (default on i686)
            (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x690d88);
            break;
          }
          u8 frame[0x30];
          for (u32 i = 0; i < sizeof frame; i++) frame[i] = 0;
          vcall<void>(obj, 0x57c, frame + 0x0c, frame);     // B at frame+0x0c, A at frame+0 (exe: -0xd94 and -0xda0)
          float t = F32(obj, 0x624);
          if (30.0f > t) F32(obj, 0x624) = t + V_db4f;
          s32 off = n * 0x35;
          for (u32 i = 0; i < 0x30; i++) R[off + i] = frame[i];
          U32(R + off, 0x30) = (u32)obj;
          R[off + 0x34] = 0;
          V_dac = n + 1;
        }
        table = G(u8 *, 0x7003b8);
        slot += 1;
        tend = (u32 *)(table + 4 * (U32(table, 4) + 2));
        if (slot == tend) break;
      }
    }
  }

  // ---------------------------------------------------------------- phase 2: sort, then pair up
  ext_4ae3e0(R, R + V_dac * 0x35);
  float xmm4 = 60.0f;
  s32 edi = 0;
  s32 edx = 0;
  V_da8 = edi;
  V_da4 = edx;
  s32 esi = V_dac;
  s32 ebx = 0;
  if (esi > 0) {
    s32 ecx = 0;
    V_db0 = ecx;
    for (;;) {
      if (R[ecx + 0x34] == 0) {                     // 4aec14: record i (at ecx) not flagged
        float a = F32(R, ecx);
        edi = edx + 1;
        s32 eax = V_dac;
        float xmm1 = a + xmm4;
        V_db4f = xmm1;
        bool pairA = false;
        bool brk = false;
        esi = ecx + 0x35;
        if (edi < eax) {
          for (;;) {
            if (R[esi + 0x34] == 0) {
              float xmm0 = F32(R, esi);
              if (xmm0 > V_db4f) { brk = true; break; }
              u8 r = ext_4ae5a0(self, R + ecx, R + esi);
              ecx = V_db0;
              if (r) { pairA = true; break; }
              xmm1 = V_db4f;
              eax = V_dac;
            }
            edi++;
            esi += 0x35;
            if (!(edi < eax)) break;
          }
        }
        if (pairA) {
          // 4af008: append i and j
          edx = V_da4;
          xmm4 = 60.0f;
          S[ebx + 1] = (u32)edx;
          S[0] = S[0] + 1;
          S[S[0] + 1] = (u32)edi;
          ebx = (s32)S[0];
          edi = V_da8;
          ebx++;
          edi += 2;
          S[0] = (u32)ebx;
          V_da8 = edi;
        } else {
          if (brk) {
            edx = V_da4;                            // 4aec80
            xmm4 = 60.0f;
          }
          edi = V_da8;                              // 4aec8e
        }
      }
      // 4aec94: next record
      esi = V_dac;
      edx++;
      ecx += 0x35;
      V_da4 = edx;
      V_db0 = ecx;
      if (!(edx < esi)) break;
    }
    V_db0 = ebx;
  }

  // ---------------------------------------------------------------- phase 3: pop the list and swap along the keys
  if (edi != 0) {
    s32 ecx = 0;
    for (;;) {
      s32 eax = ecx;
      ecx++;
      V_dc4 = ecx;
      if (eax > 8) break;
      ecx = (s32)S[edi];
      edi--;
      V_da8 = edi;
      V_da4 = ecx;
      if (ebx != 0) {
        ebx--;
        V_db0 = ebx;
        S[0] = (u32)ebx;
      }
      eax = ecx * 0x35;
      edi = ecx + 1;
      V_db4i = eax;
      float xmm1 = F32(R, eax);
      V_db8 = xmm1;
      if (edi < esi) {
        eax = V_dac;
        ebx = V_db4i;
        esi = edi * 0x35;
        for (;;) {
          if (R[esi + 0x34] == 0) {
            float xmm0 = F32(R, esi);
            if (xmm0 >= xmm1) break;                // jae 4aee06
            SwapRec(R + ebx, R + esi);
            eax = V_dac;
            xmm1 = V_db8;
            ecx = edi;
            ebx = esi;
          }
          edi++;
          esi += 0x35;
          if (!(edi < eax)) break;
        }
        ebx = V_db0;                                // 4aee06
        V_da4 = ecx;
      }
      // 4aee12: left scan from the pivot (ecx)
      edi = ecx - 1;
      if (edi >= 0) {
        ebx = ecx * 0x35;
        esi = edi * 0x35;
        for (;;) {
          if (R[esi + 0x34] == 0) {
            if (xmm1 >= F32(R, esi)) break;         // jae 4aeefc
            SwapRec(R + ebx, R + esi);
            ecx = edi;
            ebx = esi;
          }
          xmm1 = V_db8;                             // 4aeee8
          esi -= 0x35;
          edi--;
          if (!(edi >= 0)) break;
        }
        ebx = V_db0;                                // 4aeefc
        V_da4 = ecx;
      }
      // 4aef08: the pivot is ecx; its flag is cleared; a right scan and a left scan follow
      edx = ecx * 0x35;
      edi = ecx + 1;
      float xmm2 = xmm1 + xmm4;
      V_db4i = edx;
      V_dc0 = xmm2;
      R[edx + 0x34] = 0;
      bool pairB = false;
      if (edi < V_dac) {
        esi = edi * 0x35;
        eax = V_dac;
        for (;;) {
          if (R[esi + 0x34] == 0) {
            float xmm0 = F32(R, esi);
            if (xmm0 >= xmm2) break;                // jae 4aef8c
            u8 r = ext_4ae5a0(self, R + edx, R + esi);
            if (r) { pairB = true; break; }
            xmm2 = V_dc0;
            eax = V_dac;
            edx = V_db4i;
          }
          edi++;
          esi += 0x35;
          if (!(edi < eax)) break;
        }
      }
      if (!pairB) {
        // 4aef8c / 4aefa2
        ecx = V_da4;
        xmm4 = 60.0f;
        xmm1 = V_db8;
        xmm1 = xmm1 - xmm4;
        edi = ecx - 1;
        V_db8 = xmm1;
        if (edi >= 0) {
          esi = edi * 0x35;
          for (;;) {
            if (R[esi + 0x34] == 0) {
              if (xmm1 >= F32(R, esi)) break;       // jae 4af099
              u8 r = ext_4ae5a0(self, R + edx, R + esi);
              if (r) { pairB = true; break; }
              xmm1 = V_db8;
            }
            esi -= 0x35;
            edi--;
            if (edi < 0) break;
            edx = V_db4i;
          }
        }
      }
      if (pairB) {
        // 4af052: append i (pivot index, V_da4) and j
        eax = V_da4;
        xmm4 = 60.0f;
        S[ebx + 1] = (u32)eax;
        S[0] = S[0] + 1;
        S[S[0] + 1] = (u32)edi;
        ebx = (s32)S[0];
        edi = V_da8;
        ebx++;
        V_db0 = ebx;
        edi += 2;
        S[0] = (u32)ebx;
      } else {
        edi = V_da8;                                // 4af0a1
      }
      // 4af0a7
      esi = V_dac;
      ecx = V_dc4;
      if (edi == 0) break;
    }
  }
}
PCREG(4aea10, Pass4aea10);
