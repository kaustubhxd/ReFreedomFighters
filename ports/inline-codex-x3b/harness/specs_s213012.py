"""specs_s213012.py - batch 213012: selector dispatchers with hooked helpers, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g663300(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sel = r.randint(0, 10) if r.random() < 0.92 else r.getrandbits(32)
    o = rnd(c, 0x12110 if sel == 3 else 0x40)
    x = r.getrandbits(32)
    for a, n in ((0x663a40, 1), (0x663520, 1), (0x6639a0, 1), (0x663250, 1)):
        hook_rec(c, a, n, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5adea0, 0, ret=r.getrandbits(32), this=True)
    tab = obj(c, 0x40, {0x20: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x10)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, tab)
    m = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    return [o, sel, x]


def g5afe20(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x40)

    def outw(emu, k):
        if r.random() < 0.5:
            emu.w32(emu.arg32(0), r.choice([0, 1, r.getrandbits(32)]))
    hook_rec(c, 0x5af5b0, 3, ret=r.getrandbits(32), this=True, deref={0: 1}, nullflag=(1,), side=outw)
    sel = r.randint(0, 0x12) if r.random() < 0.92 else r.getrandbits(32)
    for k in (0, 4, 8, 0xc, 0x10):
        if r.random() < 0.3:
            c.emu.w32(o + k, r.getrandbits(8))
    off = {12: 0xc, 13: 8, 14: 0, 16: 4}
    if sel in off:
        v = c.emu.r32(o + off[sel])
    elif sel == 15:
        v = 1 if c.emu.r32(o + 0x10) else 0
    else:
        v = 0
    bret = r.choice([r.getrandbits(8), r.getrandbits(32), 0, v, v, v + 1, v - 1]) & 0xffffffff
    hook_rec(c, 0x5af350, 1, ret=bret, this=True)
    return [o, sel]


def g56a140(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x200)
    if r.random() < 0.5:
        e.wbytes(o + 0x87, b'\0')
    p = obj(c, 0x20, {0x28: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x14)
    if r.random() < 0.8:
        e.w32(o + 0x5c, p)
    else:
        e.w32(o + 0x5c, 0)
    e.w32(o + 0x1b8, r.randint(0, 7) if r.random() < 0.9 else r.getrandbits(32))
    if r.random() < 0.3:
        e.wbytes(o + 0x1c1, struct.pack('<I', 0))
    obj60 = obj(c, 0x20, {0x60: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x20)
    tab = obj(c, 0x40, {0x138: pystub(c, 0, ret=obj60, this=True),
                        0x4c: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x50)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, tab)
    hook_rec(c, 0x563610, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x563750, 2, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x563510, 1, ret=r.getrandbits(32), this=True)
    return [o]


S(0x663300, 'dispatch_sel9', 'thiscall', None, ret='eax', gen=g663300)
S(0x5afe20, 'sel_query_map', 'thiscall', None, ret='eax', gen=g5afe20)
S(0x56a140, 'reset_ui_state', 'thiscall', None, ret=None, gen=g56a140)
