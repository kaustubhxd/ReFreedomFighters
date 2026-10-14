"""specs_s36024.py - cascade s4 batch 36024: 0x63f220 (get or allocate a node by handle), 0x64f760 (refresh visible entries), 0x41f7f0 (allocate a tracked block), 0x46b760 (find entry by key and name), 0x44cd90 (link four entries)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memset


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g63f220(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    hook_rec(c, 0x63ef90, 1, this=True)
    hook_rec(c, 0x4db6c0, 2, this=True)
    cnt = r.choice([0xfff, 0xffe, 0, 5, 0x7ff])
    hook_rec(c, 0x4ce7b0, 0, this=True, ret=cnt)
    arr = e.alloc(0x4010, 4)
    a = rnd(c, 0x80)
    idx = r.choice([0, 0, 1, 0x1005, 0x7ff, 0xfff, r.randint(1, 0xffff)])
    e.wbytes(a + 0x5a, idx.to_bytes(2, 'little'))
    if idx & 0xffff:
        nd = rnd(c, 0x60)
        e.wbytes(nd + 5, bytes([r.choice([0, 1, 2, 3])]))
        e.w32(arr + 4 * (idx & 0xfff), nd)
    pnode = 0 if r.random() < 0.2 else rnd(c, 0x80)
    pool = obj(c, 0x20, {8: pystub(c, 0, this=True, ret=pnode)})
    E = e.alloc(0xba00, 4)
    e.w32(E + 0x68, arr)
    e.w32(E + 0x230, pool)
    return [E, a]


def _g64f760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x64f6a0, 1, this=True)
    xs = [r.getrandbits(32), r.getrandbits(32)]
    e.w32(0x70038c, obj(c, 0x20, {0x48: pystub(c, 1, ret=lambda em, k: xs[min(k, 1)], this=True)}))
    n = r.choice([0, 1, 2, 3])
    locs = [1] * n + [0]
    rets = [r.getrandbits(32) for _ in range(5)]

    def side(em, k):
        em.w32(em.arg32(0), locs[min(k, len(locs) - 1)])
    lst = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                        0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: rets[min(k, 4)], side=side)})
    ts = [0 if r.random() < 0.3 else rnd(c, 0x10) for _ in range(5)]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: ts[min(k, 4)])})
    cobj = obj(c, 0x20, {8: pystub(c, 0, this=True)})
    e.wbytes(cobj + 5, bytes([r.choice([0, 0, 1])]))
    E = obj(c, 0x100, {0x3c: pystub(c, 0, this=True), 0xa4: pystub(c, 1, this=True, ret=r.choice([0, 0, 1, 0x100]))})
    e.wbytes(E + 0xbd, cobj.to_bytes(4, 'little'))
    e.w32(E + 0x8c, 0 if r.random() < 0.2 else lst)
    return [E]


def _g41f7f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    sz = r.choice([0, 1, 4, 0x10, r.randint(0, 0x40)])
    ba = e.alloc(sz + 0x40, 4)
    e.wbytes(ba, bytes(r.getrandbits(8) for _ in range(sz + 0x40)))
    bb = e.alloc(sz + 0x40, 4)
    e.wbytes(bb, bytes(r.getrandbits(8) for _ in range(sz + 0x40)))

    def ml(em, rr):
        em.calllog.append(('malloc', em.arg32(0)))
        em.ret(eax=ba, argbytes=0)
    e.stub_import('malloc', ml)
    hook_rec(c, 0x4d0700, 1, this=True, ret=bb)
    hook_rec(c, 0x41f190, 1, this=True)
    E = obj(c, 0x80, {0xec: pystub(c, 0, this=True), 0xe8: pystub(c, 0, this=True)})
    e.wbytes(E + 0x30, bytes([r.choice([0, 1, 0xff])]))
    e.wbytes(E + 0x31, rnd(c, 0x10).to_bytes(4, 'little'))
    tail = 0 if r.random() < 0.4 else rnd(c, 0x40)
    e.w32(E + 0x1c, tail)
    e.w32(E + 0x18, rnd(c, 0x10) if tail == 0 and r.random() < 0.5 else 0)
    return [E, sz]


def _g46b760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def sic(em, rr):
        a, b = em.arg32(0), em.arg32(1)
        sa = bytearray()
        p = a
        while True:
            ch = em.rbytes(p, 1)
            if ch == b'\0':
                break
            sa += ch
            p += 1
        sb = bytearray()
        p = b
        while True:
            ch = em.rbytes(p, 1)
            if ch == b'\0':
                break
            sb += ch
            p += 1
        x, y = bytes(sa).lower(), bytes(sb).lower()
        res = (x > y) - (x < y)
        em.calllog.append(('stricmp', bytes(sa), bytes(sb)))
        em.ret(eax=res & 0xffffffff, argbytes=0)
    e.stub_import('_stricmp', sic)
    names = [b'abc\0', b'ABC\0', b'xyz\0']
    key = r.randint(1, 3)
    n = r.choice([0, 1, 2, 3])
    elems = []
    for i in range(n):
        el = rnd(c, 0x10)
        _w32(c, el, key if r.random() < 0.6 else r.randint(1, 3))
        _w32(c, el + 4, r.getrandbits(32) | 1)
        elems.append(el)
    objs = []
    for i in range(n):
        if r.random() < 0.2:
            objs.append(0)
        else:
            o = rnd(c, 0x20)
            nm = 0
            if r.random() < 0.8:
                nm = e.alloc(0x10, 4)
                e.wbytes(nm, r.choice(names))
            _w32(c, o + 4, nm)
            objs.append(o)
    seq = elems + [0]
    cobj = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                         0x64: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[min(k, len(seq) - 1)])})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, len(objs) - 1)] if objs else 0)})
    E = rnd(c, 0x80)
    e.w32(E + 0x70, 0 if r.random() < 0.1 else cobj)
    nmp = 0
    if r.random() > 0.3:
        nmp = e.alloc(0x10, 4)
        e.wbytes(nmp, r.choice(names + [b'\0']))
    return [E, key, nmp]


def _g44cd90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    x = obj(c, 0x20, {0x60: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=x), 0x50: pystub(c, 2, this=True, ret=r.getrandbits(32))})
    E = e.alloc(0xd00, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0xd00)))
    return [E]


S(0x63f220, 'GUESS get or allocate node by handle', 'thiscall', None, ret='eax', gen=_g63f220, note='batch36024')
S(0x64f760, 'GUESS refresh visible entries', 'thiscall', None, ret=None, gen=_g64f760, note='batch36024')
S(0x41f7f0, 'GUESS allocate a tracked block', 'thiscall', None, ret='eax', gen=_g41f7f0, note='batch36024')
S(0x46b760, 'GUESS find entry by key and name', 'thiscall', None, ret='al', gen=_g46b760, note='batch36024')
S(0x44cd90, 'GUESS link four entries', 'thiscall', None, ret=None, gen=_g44cd90, note='batch36024')
