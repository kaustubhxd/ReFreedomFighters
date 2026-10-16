"""specs_s210061.py - Sonnet-w3a: 0x5bedd0. Stream slot 0x48 writes tags by call index (first two are the signed counts), slot 0x40 an id, slot 0x18 is a recorder; the entry loader 0x5beeb0 is hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g5bedd0(c):
    clear_hooks(c)
    e = c.emu
    A = c.rng.choice([0, 1, 2, 3, 0xffffffff, 0x80000000, 0xfffffffe])
    B = c.rng.choice([0, 1, 7, _r(c), 0x80000000])
    tags = [A, B] + [_r(c) for _ in range(4)]

    def s48(emu, k):
        v = tags[min(k, 5)]
        emu.wbytes(emu.arg32(0), v.to_bytes(4, 'little'))
        emu.calllog.append(('s48', k, v))

    def s40(emu, k):
        v = _r(c) if False else tags[5]
        emu.w32(emu.arg32(0), v)
        emu.calllog.append(('s40', v))
    st = obj(c, 0x40, {0x48: pystub(c, 1, ret=_r(c), this=True, side=s48), 0x40: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=s40),
                       0x18: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x20)
    hook_rec(c, 0x5beeb0, 1, ret=_r(c), this=True)
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    return [rnd(c, 0x940), st]


S(0x5bedd0, 'load_entry_table', 'thiscall', None, ret='al', gen=g5bedd0, note='batch210061')
