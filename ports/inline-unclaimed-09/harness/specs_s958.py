"""specs_s958.py - area 56 band, claim A20 (PARTIAL): 0x536260 with the tail target 0x53b100 as a GUESS recording stub.

The object is 0x5400 random bytes (the field is at +0x52fa). The field is null in about one case in four. The target's stub
logs its object and returns with a plain ret (no argument pop): the ret-4 path of the real target needs an argument the caller
does not pass in this harness, so only this path is exercised."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng

    def h(e2, r):
        e2.calllog.append(('T53b100', e2.reg('ecx')))
        e2.ret(argbytes=0)

    e.hook(0x53b100, h)
    this = _rnd(c, 0x5400)
    if rng.random() < 0.25:
        e.w32(this + 0x52fa, 0)
    else:
        e.w32(this + 0x52fa, _rnd(c, 0x40))
    return [this]


S(0x536260, 'unnamed 0x536260 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A20 PARTIAL; tail target 0x53b100 stubbed (plain-return path only)')
