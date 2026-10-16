// batch961.cpp - residue-04 (core todo), batch 961: ZOctreeCompiled::RemapObjects(unsigned int (*)(unsigned int)), 0x4e3e40,
// thiscall with one stack argument (ret 4). Builds the walk record {node = [this+0x14] + 0x14, end = [node-0x14] + node,
// fn} and calls the recursive remap 0x4e3dc0 (ECX = node, one argument = record). The recursion is stood in by the checker.
#include "ff.h"

extern "C" void THISCALL ext_4e3dc0(void *node, void *rec);   // recursive remap (exe, stood in by the checker)

// 0x4e3e40 ZOctreeCompiled::RemapObjects(fn).
static void THISCALL octRemapObjects(u8 *t, u32 fn) {
  u8 *edx = *(u8 **)(t + 0x14);
  u32 rec[3];
  rec[0] = (u32)(edx + 0x14);
  rec[1] = *(u32 *)edx + (u32)edx;
  rec[2] = fn;
  ext_4e3dc0((void *)rec[0], rec);
}
PCREG(4e3e40, octRemapObjects);
