"""specs_s261.py - unclaimed area 26 (docs/20-unclaimed-26.md): 0x4fd5d0, thirteen word queries on the engine object."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    e = c.emu
    vals = [c.rng.getrandbits(32) for _ in range(13)]   # eax per query, low word is stored
    k = [0]

    def nxt(em, a):
        v = vals[k[0] % 13]
        k[0] += 1
        return (v, None)

    vt = e.logging_vtable('eng4fd', 0x46, impl={0x114: nxt}, argwords={0x114: 4})
    o = _rnd(c, 0x40)
    e.w32(o, vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    return [_rnd(c, 0x200)]


S(0x4fd5d0, 'loadQueries (GUESS)', 'thiscall', None, ret=None, gen=_load,
  note='batch261; 13 word queries through engine+0x9b vtbl[0x114]')
