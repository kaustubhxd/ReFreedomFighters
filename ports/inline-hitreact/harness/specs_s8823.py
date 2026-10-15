"""specs_s8823.py - inline-frameupdate specs_s412.py (0x4e9280 list box test, 0x4e9200 probe wrapper) ported to this harness: fu_kit's rnd /
vec inlined, the probe list built in Python instead of read back from the emulator. Box test 0x4dddf0 and the vector helpers run as exe code."""
import math
from pilot import S


class K:
    @staticmethod
    def rnd(c, n, align=4):
        a = c.emu.alloc(n, align)
        c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
        return a

    @staticmethod
    def vec(c, n, lo=-100.0, hi=100.0, pad=4):
        a = c.emu.alloc(4 * (n + pad), 4)
        for i in range(n + pad):
            c.emu.wf32(a + 4 * i, c.rng.uniform(lo, hi))
        return a


def _list(c, info=None):
    """A list object (this) with groups: list+8 count, list+0xc head; groups laid out as the exe walks them."""
    r = c.rng
    e = c.emu
    obj = K.rnd(c, 0x60)
    groups = r.choice([0, 1, 2, 3])
    buf = K.rnd(c, 0x800)
    cur = buf
    head = cur
    for g in range(groups):
        n = r.choice([2, 2, 3, 4, 6])
        e.w32(cur, n)
        for k in range(n - 2):
            ent = cur + 0x18 + 0xc * k
            for i in range(3):
                e.wf32(ent + 4 * i, r.uniform(-50, 50))
        nxt = cur + 0x18 + 0xc * (n - 2) + 0x18
        cur = nxt
    e.w32(obj + 8, groups)
    e.w32(obj + 0xc, head if groups else 0)
    if info is not None:
        info.extend([groups, head if groups else 0])
    return obj


def _vec(c, lo, hi):
    return K.vec(c, 3, lo, hi, pad=0)


def _box_args(c):
    r = c.rng
    e = c.emu
    obj = _list(c)
    A = K.vec(c, 9, -2, 2, pad=0)
    B = _vec(c, -50, 50)
    Sv = _vec(c, 0.5, 40)
    if r.random() < 0.1:
        e.wf32(Sv + 4, 0.0)
    return [obj, A, B, Sv]


def _probe_args(c):
    r = c.rng
    obj = K.rnd(c, 0x60)
    for k in range(9):
        c.emu.wf32(obj + 0x18 + 4 * k, r.uniform(-2, 2))
    for k in range(3):
        c.emu.wf32(obj + 0x3c + 4 * k, r.uniform(-50, 50))
    info = []
    _list(c, info)
    # reuse this list's groups: the probe object is itself the list (+8, +0xc) as in the exe
    c.emu.w32(obj + 8, info[0])
    c.emu.w32(obj + 0xc, info[1])
    return [obj, K.vec(c, 9, -2, 2, pad=0), _vec(c, -50, 50), _vec(c, -50, 50)]


S(0x4e9280, 'list box test (no name)', 'thiscall', None, ret='al', gen=_box_args,
  note='batch412; box test 0x4dddf0 as exe code')
S(0x4e9200, 'probe wrapper (no name)', 'thiscall', None, ret='al', gen=_probe_args,
  note='batch412; mmtmul, vmtmul, PSVECSubtract as exe code')
