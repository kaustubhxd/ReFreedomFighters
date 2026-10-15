"""specs_s67549.py - cascade s6 batch 67549 (0x48dcb0, thiscall() plain ret, return value unused). this[0xaec] points at a block whose dword at +0 (0 / 1) and +0x10 (a cursor dword) are read; the
device at 0x70038c has slot 0x48 (colour); the table object (sys[0x9b][0xadc]) has slots 0x300 (1 arg) and 0x50 (iterator update through a stack-marked pointer from a short child list), child objects with
sub-records (+0x54, type block at +0xc, slots 0x308 bool / 0x32c returning a cursor block); 0x4db9a0 is a hook; sys[0x1aa3][0x1c] has slots 0x50 (cursor blocks ending in one whose dword is -1) and 0x40."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g48dcb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def blk(first):
        b = rnd(c, 0x40)
        _w(c, b, first)
        return b
    negs = [blk(r.choice([1, 2, 0xffffffff])) for _ in range(2)] + [blk(0xffffffff)]
    dev = obj(c, 0x20, {0x48: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    e.w32(0x70038c, dev)
    lobj = obj(c, 0x20, {0x50: pystub(c, 1, this=True, ret=lambda em, k: negs[min(k, 2)]),
                         0x40: pystub(c, 2, this=True)})
    pl = rnd(c, 0x40)
    _w(c, pl + 0x1c, lobj)
    kids = []
    for _ in range(3):
        k = rnd(c, 0x70)
        if r.random() < 0.15:
            _w(c, k + 0x54, 0)
        else:
            tb = rnd(c, 0x40)
            _w(c, tb + 0x23, (r.getrandbits(32) | 0x100000) if r.random() < 0.7 else (r.getrandbits(32) & ~0x100000))
            sub = obj(c, 0x20, {0x308: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100])),
                                0x32c: pystub(c, 1, this=True, ret=lambda em, k: negs[k % 3])})
            _w(c, sub + 0xc, tb)
            _w(c, k + 0x54, sub)
        kids.append(k)
    its = [r.choice(kids) for _ in range(r.choice([0, 1, 2, 3]))] + [0]

    def s50(em, k):
        em.wbytes(em.arg32(0), (its[k + 1] if k + 1 < len(its) else 0).to_bytes(4, 'little'))
    first = its[0] if r.random() < 0.9 else 0
    tobj = obj(c, 0x20, {0x300: pystub(c, 1, this=True),
                         0x50: pystub(c, 1, this=True, stackmark=(0,), side=s50)})
    _w(c, tobj + 8, first)
    its[0:0] = []
    so = sysobj(c, table_slots={}, table_size=0xb00)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    _w(c, tab + 0xadc, tobj)
    _w(c, so + 0x1aa3, pl)
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 1]))
    lst = rnd(c, 0x40)
    _w(c, lst, r.choice([0, 1, 5]))
    _w(c, lst + 0x10, r.choice([0, 1, 0xffffffff, 3]))
    t = rnd(c, 0xb00)
    _w(c, t + 0xaec, lst if r.random() < 0.9 else 0)
    _w(c, t + 0xae8, r.getrandbits(32))
    return [t]


S(0x48dcb0, 'GUESS flush_pending_list', 'thiscall', None, ret=None, gen=_g48dcb0, note='batch67549')
