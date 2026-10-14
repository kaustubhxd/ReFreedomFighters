"""specs_s36033.py - cascade s4 batch 36033: 0x55fbd0 (accumulate four values into two records), 0x575160 (name compare then log call), 0x561200 (append a mode text to a string)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g55fbd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2, slot=0x30)
    cells = []
    for i in range(4):
        cell = e.alloc(8, 4)
        e.w32(cell, 0 if (i == 0 and r.random() < 0.15) else r.getrandbits(32))
        cells.append(cell)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, n, _c=cells: _c[min(n, 3)])
    q = rnd(c, 0x20) if r.random() < 0.7 else 0
    rr = rnd(c, 0x20) if r.random() < 0.7 else 0
    hook_rec(c, 0x5a45c0, 1, this=True, ret=q)
    hook_rec(c, 0x5a4610, 1, this=True, ret=rr)
    g = rnd(c, 0x2c30)
    e.w32(0x7003b8, g)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    e._image_dirty = True
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [p]


def _g575160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562440, 0, this=True)
    s1 = bytes(e.rbytes(0x6a6e5c, 40)).split(b'\0')[0]
    s2 = bytes(e.rbytes(0x6a8558, 40)).split(b'\0')[0]
    pick = r.choice([s1, s1, s2, s2, s1[:-1] + b'Z', s2 + b'x', b'', bytes(r.randint(0x41, 0x5a) for _ in range(5))])
    blk = rnd(c, 0x1050)
    e.wbytes(blk + 0x48, pick + b'\0' + bytes(0x30))
    e.wbytes(blk + 0x1040, bytes([r.choice([0, 0, 1, 0x80])]))
    o = obj(c, 0x20, {0x60: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x4c: pystub(c, 2, this=True, ret=r.getrandbits(32))})
    b = rnd(c, 0xa0)
    e.w32(b + 0x94, blk)
    return [b]


def _g561200(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    src = bytes(r.randint(0x41, 0x5a) for _ in range(r.choice([0, 1, 3, 4, 5, 9, 20]))) + b'\0'
    sa = e.alloc(len(src) + 1, 4)
    e.wbytes(sa, src)
    o = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=sa)})
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xae4, o)
    w = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100, 0x1ff])),
                      0x354: pystub(c, 0, this=True, ret=r.choice([0, 1, 2, 3, 3, 4, 0xffffffff]))})
    s = rnd(c, 0x110)
    e.w32(s + 0xf4, w if r.random() < 0.85 else 0)
    dest = e.alloc(0x100, 4)
    e.wbytes(dest, bytes([0x55]) * 0x100)
    ln = r.choice([0, 1, 2, 7, 30, 60])
    e.wbytes(dest, bytes(r.randint(0x41, 0x5a) for _ in range(ln)) + b'\0')
    return [s, dest]


S(0x55fbd0, 'GUESS accumulate four values into two records', 'stdcall', None, ret=None, gen=_g55fbd0, note='batch36033')
S(0x575160, 'GUESS name compare then log call', 'thiscall', None, ret=None, gen=_g575160, note='batch36033')
S(0x561200, 'GUESS append a mode text to a string', 'thiscall', None, ret=None, gen=_g561200, note='batch36033')
