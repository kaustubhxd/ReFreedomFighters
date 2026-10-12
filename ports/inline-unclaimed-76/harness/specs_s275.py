"""specs_s275.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 list: 0x46c170, fills an array of handles
through this's slot 0x334 (child), the child's slot 0x1bc (seven args) and the engine object's slot 0x4c."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fill(c):
    e = c.emu
    n = c.rng.randrange(0, 4)
    rs = [c.rng.getrandbits(32) for _ in range(4)]
    vs = [c.rng.getrandbits(32) for _ in range(4)]
    kr = [0]
    kv = [0]

    def ret_r(em, a):
        v = rs[kr[0] % 4]
        kr[0] += 1
        return (v, None)

    def ret_v(em, a):
        v = vs[kv[0] % 4]
        kv[0] += 1
        return (v, None)

    c_vt = e.logging_vtable('child46c', 0x70, impl={0x1bc: ret_r}, argwords={0x1bc: 7})
    child = _rnd(c, 0x40)
    e.w32(child, c_vt)
    o_vt = e.logging_vtable('eng46c', 0x5a, impl={0x4c: ret_v}, argwords={0x4c: 1})
    o = _rnd(c, 0x2000)
    e.w32(o, o_vt)
    e.w32(o + 0xadc, c.rng.getrandbits(32))
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    self_vt = e.logging_vtable('self46c', 0xce, impl={0x334: lambda em, a: (child, None)}, argwords={0x334: 0})
    self_ = _rnd(c, 0x100)
    e.w32(self_, self_vt)
    e.w32(self_ + 0x9c, n)
    arr = _rnd(c, 0x20)
    e.w32(self_ + 0x98, arr)
    return [self_]


S(0x46c170, 'fillHandles (GUESS)', 'thiscall', None, ret=None, gen=_fill, note='batch275; residue-15 list; plain ret')
