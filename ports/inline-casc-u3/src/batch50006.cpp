// batch50006.cpp - cascade u3, tier H, batch 50006: 0x65be00 (rebuild the per-bone transform arrays of every entry in the list at this+0x1c8).
#include "ff.h"

extern "C" void THISCALL ext_659c40(u8 *self);
extern "C" u8 *THISCALL ext_658d30(u8 *e);
extern "C" u8 *THISCALL ext_658d80(u8 *e);
extern "C" void FASTCALL ext_4dfd10(u8 *dst, u8 *src);               // dst (9 floats) = transpose of src
extern "C" void FASTCALL ext_4de480(u8 *dst, u8 *other);             // dst *= other (3x3)
extern "C" void FASTCALL ext_459fc0(u8 *out, u8 *v, u8 *m);          // ret 4: out = v * m (vec3)
extern "C" void FASTCALL ext_633654(u32 cookie);                     // /GS check

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x65be00, thiscall() void, /GS: ext_659c40(this); L = [[sys+0x1aa3]+0x20] (unaligned pointer chain); walks the container at this+0x1c8 (slot 0xc(&buf) returns {cur, idx, node}; block walk:
// idx+1 == node[0] -> node = node[8], cur = node+0x10 (idx 0) or 0; else cur += 4). For each entry E: K = [[E+0x38]+0x6c]; A = [[sys+0x1aa3]+0x18] slot 0xbc(K); B = ext_658d30(E); C = ext_658d80(E);
// count N = dword [L + K + 0x7c] (re-read every pass); for i < N (0x30-byte records): m = transpose(B_i) (4dfd10), m *= A_i (4de480), v = A_i[0x24..] * m (459fc0); C_i[0..8] = m[6..8],
// C_i[0x10..0x18] = m[3..5], C_i[0x20..0x28] = m[0..2], C_i[0xc] = B_i[0x24] - v.x, C_i[0x1c] = B_i[0x28] - v.y, C_i[0x2c] = B_i[0x2c] - v.z.
static void THISCALL fn65be00(u8 *self) {
  ext_659c40(self);
  u8 *sys = G(u8 *, 0x70039c);
  u32 L = rd32((u8 *)rd32(sys + 0x1aa3) + 0x20);
  u32 buf[3];
  u32 *it = vcall<u32 *>(self + 0x1c8, 0xc, (u32)buf);
  u32 cur = it[0], idx = it[1], node = it[2];
  if (cur) {
    do {
      u8 *E = *(u8 **)cur;
      u32 K = *(u32 *)(*(u8 **)(E + 0x38) + 0x6c);
      sys = G(u8 *, 0x70039c);
      u8 *A = vcall<u8 *>((void *)rd32((u8 *)rd32(sys + 0x1aa3) + 0x18), 0xbc, K);
      u8 *B = ext_658d30(E);
      u8 *C = ext_658d80(E);
      if (*(u32 *)(K + L + 0x7c) != 0) {
        u32 i = 0;
        do {
          u32 m[9];
          float v[3];
          ext_4dfd10((u8 *)m, B + 0x30 * i);
          ext_4de480((u8 *)m, A + 0x30 * i);
          ext_459fc0((u8 *)v, A + 0x30 * i + 0x24, (u8 *)m);
          u32 *c = (u32 *)(C + 0x30 * i);
          c[0] = m[6]; c[1] = m[7]; c[2] = m[8];
          c[4] = m[3]; c[5] = m[4]; c[6] = m[5];
          c[8] = m[0]; c[9] = m[1]; c[10] = m[2];
          float *b = (float *)(B + 0x30 * i);
          *(float *)&c[3] = b[9] - v[0];
          *(float *)&c[7] = b[10] - v[1];
          *(float *)&c[11] = b[11] - v[2];
          i++;
        } while (i < *(u32 *)(K + L + 0x7c));
      }
      idx++;
      if (idx == *(u32 *)node) {
        node = *(u32 *)(node + 8);
        if (node) {
          idx = 0;
          cur = node + 0x10;
        } else {
          cur = 0;
        }
      } else {
        cur += 4;
      }
    } while (cur);
  }
  ext_633654(0);
}
PCREG(65be00, fn65be00);
