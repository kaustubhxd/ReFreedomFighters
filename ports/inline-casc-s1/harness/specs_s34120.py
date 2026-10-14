"""specs_s34120.py - 0x56c4c0: this with slots 0xd8 (low byte zero in 3/4), 0x84 (returns an object with slot 0x2f0 that returns the value stored at the unaligned +0xcae in a half); msg in {0x102, 0x103, 0x100, random}; the four helpers are recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g56c4c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x563d20, 3, this=True, ret=r.getrandbits(32), stackmark=(1,))
    hook_rec(c, 0x563d40, 3, this=True, ret=r.getrandbits(32), stackmark=(1,))
    hook_rec(c, 0x56b460, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x562d90, 1, this=True, ret=r.getrandbits(32))
    val = r.getrandbits(32)
    inner = obj(c, 0x20, {0x2f0: pystub(c, 0, ret=val if r.random() < 0.5 else val ^ 1, this=True)}, nslots=0x2f4 // 4)
    me = obj(c, 0xcf0, {0xd8: pystub(c, 0, ret=lambda em, k: r.choice([0, 0, 0, 1, 0x100]), this=True),
                        0x84: pystub(c, 0, ret=inner, this=True)}, nslots=0xdc // 4)
    c.emu.wbytes(me + 0xcae, val.to_bytes(4, 'little'))
    return [me, r.choice([0x102, 0x103, 0x102, 0x103, 0x100, 0x101, r.getrandbits(32)])]


S(0x56c4c0, 'GUESS window message filter', 'thiscall', None, ret='eax', gen=_g56c4c0, note='batch34120')
