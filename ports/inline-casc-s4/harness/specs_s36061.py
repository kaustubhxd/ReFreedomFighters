"""specs_s36061.py - cascade s4 batch 36061: 0x4298b0 (set input flag bits from a profile), 0x493f20 (release an object with flag-selected notifications), 0x49ccc0 (look a key up in a packed range table)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4298b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.wbytes(so + 0x6d, bytes([r.choice([0, 1, 1, 1, 0x80])]))
    prof = rnd(c, 0x20)
    for off in (0xc, 0xd, 0xe):
        e.wbytes(prof + off, bytes([r.choice([0, 1, 1, 0x80])]))

    def h(em, rr):
        em.calllog.append(('435eb0', em.arg32(0)))
        em.ret(eax=prof if flag else 0, argbytes=4)
    flag = r.random() < 0.9
    e.hook(0x435eb0, h)
    return []


def _g493f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hcode = pystub(c, 0, this=True, ret=r.getrandbits(32))
    g = obj(c, 0x20, {0x20: pystub(c, 1, this=True, ret=r.choice([0, 0, 0, 1, 0x100])), 0xac: pystub(c, 1, this=True)})
    mode = r.choice(['in', 'below', 'above', 'noh'])
    blk = e.alloc(0x80, 16)
    e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x80)))
    a = blk + 8
    e.w32(a - 4, r.choice([0, 0, 7, 0xffffffff]))
    e.w32(g + 8, 0 if mode == 'noh' else hcode)
    if mode == 'below':
        e.w32(g + 0xc, a + 1)
        e.w32(g + 0x10, a + 0x100)
    elif mode == 'above':
        e.w32(g + 0xc, a - 0x100)
        e.w32(g + 0x10, a)
    else:
        e.w32(g + 0xc, a)
        e.w32(g + 0x10, a + 1)
    e.w32(0x70038c, g)
    e._image_dirty = True
    cell = rnd(c, 8)
    vt = e.alloc(0x10, 4)
    e.w32(vt + 4, pystub(c, 1, this=True, ret=cell if r.random() < 0.6 else 0))
    s = rnd(c, 0x110)
    e.w32(s + 0xcc, vt)
    e.w32(s + 0xc8, obj(c, 0x20, {4: pystub(c, 1, this=True)}))
    e.w32(s + 0x60, obj(c, 0x20, {0x3c: pystub(c, 1, this=True)}))
    flags = r.choice([0, 0x10, 8, 0x40, 0x58, 0x48, 0x50, 0x7, 0x1f, 0x18, r.getrandbits(8)])
    return [s, 0 if r.random() < 0.15 else a, flags]


def _g49ccc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x49ca30, 4, this=True, ret=lambda em, k: 0x4400 + k)
    nw = 14
    A = e.alloc(4 * (nw + 8), 4)
    e.wbytes(A, bytes([0x55]) * (4 * (nw + 8)))
    for k in range(nw + 8):
        if k < nw - 1:
            v = 8 * r.randint(0, 5)
            w = v | (r.choice([0, 0, 2, 2, 4, 1]) if True else 0)
        else:
            w = 1
        e.w32(A + 4 * k, w)
    e.w32(A + 4 * (nw - 1), 1)
    t = rnd(c, 0x40)
    e.w32(t + 0x1d - 0x1d + 0x1d, A - 0)
    i = r.randint(0, 3)
    e.w32(t + 0x1d, A)
    key = 8 * r.randint(0, 6) + r.choice([0, 0, 1, 3])
    return [t, i, key, r.choice([0, 1, 0x100, 0x2, r.getrandbits(32)])]


S(0x4298b0, 'GUESS set input flag bits from a profile', 'cdecl', None, ret=None, gen=_g4298b0, note='batch36061')
S(0x493f20, 'GUESS release an object with flag-selected notifications', 'thiscall', None, ret=None, gen=_g493f20, note='batch36061')
S(0x49ccc0, 'GUESS look a key up in a packed range table', 'thiscall', None, ret='eax', gen=_g49ccc0, note='batch36061')
