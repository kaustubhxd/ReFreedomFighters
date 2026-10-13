"""specs_s2716.py - unclaimed-27 batch 16: ZMoveOnSpline::GetExitRef (0x513040, thiscall, returns eax). Stubs, NOT verified:
the object at this+0x127 (Q) has slot +0x14 (no args) returning a count n (about a quarter of the time n <= 0), and slot +0x30
(one argument, ret 4) recording its argument and returning a random eax. The global at 0x70039c (G) has slot +0x1bc (two
arguments, ret 8) returning a random r."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _gx(c):
    rec = c.emu.alloc(0x10, 4)
    n = c.rng.randint(-2, 9) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    if c.rng.random() < 0.25:
        n = c.rng.randint(-3, 0)
    rr = c.rng.getrandbits(32)
    ret30 = c.rng.getrandbits(32)
    qvt = c.emu.alloc(0x200, 4)
    c.emu.w32(qvt + 0x14, _stub(c, b'\xb8' + (n & 0xffffffff).to_bytes(4, 'little') + b'\xc3'))
    c.emu.w32(qvt + 0x30, _stub(c, b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little')
                                + b'\xb8' + ret30.to_bytes(4, 'little') + b'\xc2\x04\x00'))
    q = _rnd(c, 0x100)
    c.emu.w32(q, qvt)
    gvt = c.emu.alloc(0x400, 4)
    c.emu.w32(gvt + 0x1bc, _stub(c, b'\xb8' + rr.to_bytes(4, 'little') + b'\xc2\x08\x00'))
    g = _rnd(c, 0x800)
    c.emu.w32(g, gvt)
    c.emu.w32(0x70039c, g)
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x127, q)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x513040, 'ZMoveOnSpline::GetExitRef (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gx,
  note='batch 16; Q slots +0x14 and +0x30 and the global slot +0x1bc are stubs')
