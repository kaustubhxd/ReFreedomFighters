"""specs_s816.py - unclaimed-08 batch 816 (residue 7): ZBoneModifyBase::UnfixParticle(int), thiscall, one stack argument, ret 4.

The bone-modify object is 0x400 random bytes. Its pointer at +0x291 is null (30%) or a 0x400 random object (the particle).
The index is 0..0x7f, so the zeroed dword stays inside the particle. The tail jump 0x645100 runs the original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _unfix(c):
    obj = _rnd(c, 0x400)
    if c.rng.random() < 0.3:
        c.emu.w32(obj + 0x291, 0)
    else:
        c.emu.w32(obj + 0x291, _rnd(c, 0x400))
    return [obj, c.rng.randint(0, 0x7f)]


S(0x6475f0, 'ZBoneModifyBase::UnfixParticle (unknown)', 'thiscall', None, ret=None, gen=_unfix,
  note='unclaimed-08 batch 16 (residue 7); zero dword at particle+4*i+0x3f when +0x291 is set; tail-jumps to 0x645100 (original)')
