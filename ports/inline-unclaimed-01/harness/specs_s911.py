"""specs_s911.py - unclaimed-01 claim 10 (docs/20-unclaimed-01.md): CMsgForward::Load (0x49ef80). The load object is a
logging fake vtable whose slots +0x40 and +0x44 each write a per-case dword through the pointer argument (the way a real
ZLoadGame fills a field). The call sequence and arguments are compared as well as the object's fields."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    o = _rnd(c, 0x100)
    load = _rnd(c, 0x40)
    v1 = c.rng.getrandbits(32)
    v2 = c.rng.getrandbits(32)

    def w1(e, args, v=v1):
        e.w32(args[0], v)
        return (0, None)

    def w2(e, args, v=v2):
        e.w32(args[0], v)
        return (0, None)

    vt = c.emu.logging_vtable('ZLoadGame', 0x48, impl={0x40: w1, 0x44: w2}, argwords={0x40: 1, 0x44: 1})
    c.emu.w32(load, vt)
    return [o, load]


S(0x49ef80, 'CMsgForward::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-01 claim 10; slots +0x40 (pointer +0x48) and +0x44 (pointer +0x4c); returns true')
