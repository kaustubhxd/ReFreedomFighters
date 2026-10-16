"""specs_s210074.py - Sonnet-w3a: 0x5d7e00. Manager sub-object at mgr+0x1c (slots 0x54 / 0x74: 0x74 yields a result sequence), element container this[0x14e] (packed; slot 0x4c clears the stack iterator flag, slot 0x5c yields elements and sets the flag while more remain), lookup slot 0x58 on the manager, slot 0x100 on the looked up objects, 0x5d7bc0 hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g5d7e00(c):
    clear_hooks(c)
    e = c.emu
    seq74 = [c.rng.choice([0, 1, 1]) for _ in range(5)]
    k = c.rng.choice([0, 1, 2, 3, 4])
    seq74 = [1] * k + [0]
    n = c.rng.choice([0, 1, 2, 3])
    elems = [_r(c) for _ in range(n)]
    objs = [obj(c, 0x20, {0x100: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x50) for _ in range(max(n, 1) + 1)]

    def s4c(emu, kk):
        emu.w32(emu.arg32(0), 1 if n else 0)

    def s5c(emu, kk):
        emu.w32(emu.arg32(0), 1 if kk < n else 0)
        emu.calllog.append(('s5c', kk))
    cont = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=s4c),
                         0x5c: pystub(c, 1, ret=lambda emu, kk: elems[kk] if kk < n else 0, this=True, stackmark=(0,), side=s5c)}, nslots=0x30)
    # careful: with n elements the first 0x5c call (kk = 0) must leave the flag set only if n > 0
    vt = c.emu.alloc(0x100, 4)
    e.w32(vt + 0x54, pystub(c, 1, ret=_r(c), this=True, stackmark=(0,)))
    e.w32(vt + 0x74, pystub(c, 1, ret=lambda emu, kk: seq74[min(kk, len(seq74) - 1)], this=True, stackmark=(0,)))
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda emu, kk: objs[min(kk, len(objs) - 1)], this=True)}, nslots=0x30)
    e.w32(mg + 0x1c, vt)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    hook_rec(c, 0x5d7bc0, 0, ret=_r(c), this=True)
    s = rnd(c, 0x1e0)
    _ub(c, s + 0x14e, 0 if c.rng.random() < 0.2 else cont)
    e.wbytes(s + 0x1cc, bytes([c.rng.choice([0, 0, 2])]))
    return [s]


S(0x5d7e00, 'drain_and_notify', 'thiscall', None, ret=None, gen=g5d7e00, note='batch210074')
