"""specs_s302.py - unclaimed-43 batch 302: ZBoneModifyBase::CalcCenSize(const ZBone *a, const SBoneDefinition *b) (0x645660),
thiscall with two stack arguments, ret 8. Object: count dword at +0x11, output vectors at +0x275 and +0x281.
a: 0x30-stride bone records (matrix at +0..0x20, translation at +0x24). b: 0x30-stride definitions (vector at +0x0,
the offset at +0x10). Counts are 1 and up: count 0 reads uninitialised frame slots in the original (quirk, see batch302.cpp),
so it is not part of this claim."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E

COUNTS = [1, 1, 2, 2, 3, 4, 6]


def _gen(c):
    count = c.rng.choice(COUNTS)
    o = E.zero_obj(c, 0x400)
    c.emu.wbytes(o + 0x11, struct.pack('<I', count))
    a = c.fbuf(12 * count + 12)
    b = c.fbuf(12 * count + 12)
    c.emu.mu.ctl_flush_tb()
    return [o, a, b]


S(0x645660, 'ZBoneModifyBase::CalcCenSize(const ZBone*, const SBoneDefinition*)', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 302 (count >= 1); count 0 reads uninitialised frame slots in the original')
