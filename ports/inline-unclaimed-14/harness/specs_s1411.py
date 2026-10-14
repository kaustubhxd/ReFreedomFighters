"""specs_s1411.py - unclaimed-14 batch 11 (slice 13, heavy): ZRequireMatPosSpeed::Command (0x4a60d0, thiscall, two stack
arguments, ret 8, returns 0). Six helpers are replaced by accumulating stubs (helper_stubs.py): 0x4db2c0 (2 stack args),
0x4e0a10, 0x4e0980, 0x4de7e0, 0x4419f0, 0x441940 (register arguments only). The helpers' output buffers are not written
(GUESS, see helper_stubs.py), so the check covers the calls and their registers, not the values the helpers compute.

Each case: a random 0x200-byte object whose +0x44 points to P, P+8 points to Q (random 0x40 bytes); a random 0x40-byte buf;
the command is 0x4004 in about 4 cases of 5, otherwise random. The object fields copied at +0x60..+0x80 are random."""
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cmd(c):
    # ecx/edx that hold the caller's stack locals (loc1c, loc10) are left out; thiscall helpers do not take edx.
    hs.install(c, {0x4db2c0: (2, False, False), 0x4e0a10: (0, False, False), 0x4e0980: (0, False, True),
                   0x4de7e0: (0, True, False), 0x4419f0: (0, False, True), 0x441940: (0, True, False)})
    o = _rnd(c, 0x200)
    p = _rnd(c, 0x20)
    q = _rnd(c, 0x40)
    c.emu.w32(p + 8, q)
    c.emu.w32(o + 0x44, p)
    buf = _rnd(c, 0x40)
    cmd = 0x4004 if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    return [o, cmd, buf]


S(0x4a60d0, 'ZRequireMatPosSpeed::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  note='unclaimed-14 batch 11; six helpers stubbed by helper_stubs.py; out-parameters not modelled')
