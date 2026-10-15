"""specs_s412.py - batch 412: 0x4e9280 (list box test) and 0x4e9200 (its probe wrapper)."""
import math
from pilot import S, F
import fu_kit as K


def _list(c):
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
    lst = _list(c)
    # reuse this list's groups: the probe object is itself the list (+8, +0xc) as in the exe
    c.emu.w32(obj + 8, c.emu.r32(lst + 8))
    c.emu.w32(obj + 0xc, c.emu.r32(lst + 0xc))
    return [obj, K.vec(c, 9, -2, 2, pad=0), _vec(c, -50, 50), _vec(c, -50, 50)]


S(0x4e9280, 'list box test (no name)', 'thiscall', None, ret='al', gen=_box_args,
  note='batch412; box test 0x4dddf0 as exe code')
S(0x4e9200, 'probe wrapper (no name)', 'thiscall', None, ret='al', gen=_probe_args,
  note='batch412; mmtmul, vmtmul, PSVECSubtract as exe code')
