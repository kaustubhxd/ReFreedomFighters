"""specs_s36052.py - cascade s4 batch 36052: 0x606dc0 (get or add an id in a string table), 0x49c980 (expand packed ranges), 0x4ace80 (create and register an object)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g606dc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    node = rnd(c, 0x20) if r.random() < 0.5 else 0

    def f607200(em, rr):
        key_ptr, out = em.arg32(1), em.arg32(0)
        em.calllog.append(('607200', em.reg('ecx'), em.r32(key_ptr)))
        em.w32(out, node)
        em.w32(out + 4, em.reg('ecx'))
        em.ret(0, 8)
    e.hook(0x607200, f607200)
    newrec = rnd(c, 0x10)

    def f607260(em, rr):
        p = em.arg32(0)
        em.calllog.append(('607260', em.reg('ecx'), em.r32(p), int.from_bytes(em.rbytes(p + 4, 2), 'little')))
        em.ret(newrec, 4)
    e.hook(0x607260, f607260)
    hook_rec(c, 0x4301c0, 2, this=True, deref={1: 1})
    hook_rec(c, 0x6070b0, 2, this=True, deref={1: 1})
    s = rnd(c, 0x60)
    buf = e.alloc(0x40, 4)
    e.wbytes(buf, bytes([0x55]) * 0x40)
    for v, off in ((0x17, 4), (0x23, 2)):
        cur = buf + (0 if v == 0x17 else 0x20) + 8
        e.w32(s + v + 4, cur)
        e.w32(s + v + 8, cur if r.random() < 0.4 else cur + 0x10)
    e.w32(s + 0x2f, r.choice([0, 1, 0xfffe, 0xffff, r.getrandbits(32)]))
    return [s, r.getrandbits(32)]


def _g49c980(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = e.alloc(0x40, 4)
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3])):
        n = rnd(c, 0x10)
        nodes.append(n)
    for i, n in enumerate(nodes):
        e.w32(n + 0xc, nodes[i + 1] if i + 1 < len(nodes) else 0)
        if r.random() < 0.3:
            e.w32(n + 8, 0)
            if r.random() < 0.5:
                e.w32(n + 4, 0)
    idx = r.randint(0, 2)
    e.w32(A + 4 * idx, nodes[0] if nodes else 0)
    words = []
    for k in range(r.choice([1, 2, 3, 4])):
        base = 0x70 * r.randint(0, 6) + 8 * r.randint(0, 3)
        flags = r.choice([0, 2, 2, 4, 6, 3, 0x7])
        words.append((base | (flags & 6)) & ~1)
    words[-1] |= 1
    for k, w in enumerate(words):
        e.w32(A + 4 * (idx + 1 + k), w)
    t = rnd(c, 0x40)
    e.w32(t + 0x1d, A)
    out = e.alloc(0x100, 4)
    e.wbytes(out, bytes([0x55]) * 0x100)
    return [t, out, idx]


def _g4ace80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = e.alloc(0x80, 16)
    e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x80)))
    o = blk + 8
    ovt = e.alloc(0xc0, 4)
    e.w32(ovt + 0x5c, pystub(c, 3, this=True))
    e.w32(ovt + 0xb0, pystub(c, 8, this=True))
    e.w32(o, ovt)
    e.w32(o - 4, r.choice([0, 0, 5, 0xffffffff]))
    hcode = pystub(c, 0, this=True, ret=r.getrandbits(32))
    mode = r.choice(['in', 'below', 'above', 'noh'])
    g = obj(c, 0x20, {0x20: pystub(c, 1, this=True, ret=r.choice([0, 0, 0, 1, 0x100])), 0xac: pystub(c, 1, this=True)})
    e.w32(g + 8, 0 if mode == 'noh' else hcode)
    if mode == 'below':
        e.w32(g + 0xc, o + 1)
        e.w32(g + 0x10, o + 0x100)
    elif mode == 'above':
        e.w32(g + 0xc, o - 0x100)
        e.w32(g + 0x10, o)
    else:
        e.w32(g + 0xc, o)
        e.w32(g + 0x10, o + 1)
    e.w32(0x70038c, g)
    e._image_dirty = True
    t = obj(c, 0x20, {0x10c: pystub(c, 2, this=True, ret=o if r.random() < 0.88 else 0)})
    return [t, r.getrandbits(32)] + [r.getrandbits(32) for _ in range(6)]


S(0x606dc0, 'GUESS get or add an id in a string table', 'thiscall', None, ret='ax', gen=_g606dc0, note='batch36052')
S(0x49c980, 'GUESS expand packed ranges', 'thiscall', None, ret='eax', gen=_g49c980, note='batch36052')
S(0x4ace80, 'GUESS create and register an object', 'fastcall', None, ret='eax', gen=_g4ace80, note='batch36052')
