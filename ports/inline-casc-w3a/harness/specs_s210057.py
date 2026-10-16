"""specs_s210057.py - Sonnet-w3a: 0x5dd1b0. Manager slot 0x114 (4 args) returns code1 then code2; the key slots at this+0x49..0x59 (unaligned) come from a small pool that includes b; slot 0x58 / 0xbc are recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g5dd1b0(c):
    clear_hooks(c)
    e = c.emu
    a = _r(c)
    low = a & 0xffff
    pick = lambda: c.rng.choice([low, low, (low + 1) & 0xffff, _r(c) & 0xffff])
    codes = [(_r(c) & 0xffff0000) | pick(), (_r(c) & 0xffff0000) | pick()]
    tgt = obj(c, 0x40, {0xbc: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x40)
    mg = obj(c, 0x40, {0x114: pystub(c, 4, ret=lambda emu, k: codes[min(k, 1)], this=True),
                       0x58: pystub(c, 1, ret=tgt, this=True)}, nslots=0x50)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    b = c.rng.choice([0, 1, 7, _r(c)])
    s = rnd(c, 0x90)
    for off in (0x49, 0x4d, 0x51, 0x55, 0x59):
        _ub(c, s + off, c.rng.choice([b, b, 0, 1, 7, _r(c)]))
    _ub(c, s + 0x5d, _r(c))
    for off in range(0x75, 0x7a):
        e.wbytes(s + off, bytes([c.rng.choice([0, 1, 2, 0xff])]))
    return [s, a, b]


S(0x5dd1b0, 'key_state_update', 'thiscall', None, ret='eax', gen=g5dd1b0, note='batch210057')
