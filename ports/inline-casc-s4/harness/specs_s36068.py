"""specs_s36068.py - cascade s4 batch 36068: 0x56df60 (reset a screen's handles), 0x521830 (per-frame update of a window)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g56df60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x563a50, 0, this=True)
    hook_rec(c, 0x563110, 2, this=True)
    hook_rec(c, 0x4f2f60, 1, this=True)
    hook_rec(c, 0x56e050, 0, this=True)
    oo = [obj(c, 0x20, {0x88: pystub(c, 1, this=True)}) for _ in range(4)]
    pick = [oo[i] if r.random() < 0.5 else 0 for i in range(4)]
    hook_rec(c, 0x589c20, 1, ret=lambda em, k, _p=pick: _p[min(k, 3)])
    M = e.alloc(0x2c60, 4)
    e.wbytes(M, bytes([0x66]) * 0x2c60)
    for i in range(4):
        e.w32(M + 0x2c3d + 4 * i, 0 if r.random() < 0.35 else r.getrandbits(32) | 1)
    e.w32(0x7003b8, M)
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, ret=lambda em, k: 0x12345678 * (k + 3) & 0xffffffff)})
    w = obj(c, 0x20, {0x130: pystub(c, 2, this=True)})
    X = e.alloc(0x13300, 16)
    e.wbytes(X + 0x1040, bytes([0x77]) * 8)
    e.wbytes(X + 0x13290, bytes([0x78]) * 16)
    d = obj(c, 0xa0, {0x84: pystub(c, 0, this=True, ret=rnd(c, 0x10))})
    e.w32(d + 0x44, w)
    e.w32(d + 0x94, 0 if r.random() < 0.3 else X)
    e._image_dirty = True
    return [d, r.getrandbits(32), r.choice([0, 1, 0x100, 0x2])]


def _g521830(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x515c70, 0x522520, 0x521db0, 0x521ab0, 0x522250):
        hook_rec(c, a, 0, this=True)
    hook_rec(c, 0x527d10, 7, this=True)
    hook_rec(c, 0x523330, 1, this=True, stackmark=(0,))
    d = obj(c, 0x2800, {0x80: pystub(c, 2, this=True), 0x36c: pystub(c, 0, this=True), 0x2ec: pystub(c, 1, this=True)})
    e.wbytes(d + 0x133, bytes([r.choice([0, 1, 1, 0x80])]))
    e.w32(d + 0x123, r.choice([0, 1, 5]))
    e.wbytes(d + 0x215, bytes([r.choice([0, 0, 1, 0x80])]))
    e.w32(d + 0x26fa, r.choice([0, 0, 0x1111, 0x2222]))
    e.w32(d + 0x26ea, r.choice([0, 0, 0x3333, 0x4444]))
    e.w32(d + 0x5c, rnd(c, 0x20))
    return [d]


S(0x56df60, "GUESS reset a screen's handles", 'thiscall', None, ret='al', gen=_g56df60, note='batch36068')
S(0x521830, 'GUESS per-frame update of a window', 'thiscall', None, ret=None, gen=_g521830, note='batch36068')
