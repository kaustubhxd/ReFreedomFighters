"""specs_s938.py - unclaimed-09 batch 30 (docs/20-unclaimed-09.md, claim 32): ZOnScreenDisplay::ClassInit().

The view object is 0x400 random bytes; the mode at +0x360 is 0..6, so all four constants run. GUESS recording stubs:
- M (the global's +0x9b object): vt+0x138 returns r; vt+0x4c logs its two arguments (the view object is a heap value) and
  returns a random dword.
- r: vt+0x60 logs its two arguments (K and the dword from M's vt+0x4c)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    v = rng.getrandbits(32)

    def h4c(e2, r):
        e2.calllog.append(('M4c', e2.arg32(0), e2.arg32(1)))
        e2.ret(eax=v, argbytes=8)

    def h138(e2, r):
        e2.calllog.append(('M138',))
        e2.ret(eax=robj, argbytes=0)

    def h60(e2, r):
        e2.calllog.append(('R60', e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    robj = e.fake_object('onscreen_r', 0x40, slots={0x60: h60})
    m = e.fake_object('onscreen_m', 0x40, slots={0x138: h138, 0x4c: h4c})
    g = _rnd(c, 0x2000)
    e.w32(g + 0x9b, m)
    e.w32(0x70039c, g)
    this = _rnd(c, 0x400)
    e.w32(this + 0x360, rng.randint(0, 6))
    return [this]


S(0x5a64c0, 'ZOnScreenDisplay::ClassInit (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b30; GUESS recording stubs for M (0x138, 0x4c) and r (0x60)')
