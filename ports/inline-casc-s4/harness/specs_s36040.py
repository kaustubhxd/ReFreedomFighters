"""specs_s36040.py - cascade s4 batch 36040: 0x51f7c0 (read a record from a stream), 0x539780 (validate a pointer, log), 0x53b100 (rotate ids and prune a list), 0x5aa190 (read two object arrays), 0x5d79f0 (resolve ids and settings)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g51f7c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = {'k': 0}

    def mk(width, slot):
        def h(em, rr):
            ptr = em.arg32(0)
            cnt['k'] += 1
            em.calllog.append(('stream', slot, em.reg('ecx')))
            em.wbytes(ptr, bytes(((cnt['k'] * 37 + i * 11 + slot) & 0xff) for i in range(width)))
            em.ret(0, 4)
        return h
    s = obj(c, 0x40, {0x40: e.stub_fn('s40', mk(4, 0x40)), 0x6c: e.stub_fn('s6c', mk(12, 0x6c)), 0x48: e.stub_fn('s48', mk(4, 0x48))})
    ok = r.choice([0, 1, 1, 1, 0x100])
    hook_rec(c, 0x517f20, 1, this=True, ret=ok)
    hook_rec(c, 0x5274a0, 1, this=True)
    hook_rec(c, 0x513510, 1, this=True)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: 0xbb000000 + k * 16)})
    d = rnd(c, 0x1800)
    return [d, s]


def _g539780(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def pr(em, rr):
        fmt = em.arg32(1)
        args = [em.arg32(0), fmt]
        if fmt == 0x6a1ee0:
            args.append(em.arg32(2))
        em.calllog.append(('log.printf', tuple(args)))
        em.ret(0, 0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('print', pr)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)})
    e.w32(0x700390, lg)
    _assert_hook(c)
    P = rnd(c, 0x20)
    e.w32(P, 0x10000 if r.random() < 0.6 else r.getrandbits(32))
    s = obj(c, 0x5300, {0x1a0: pystub(c, 0, this=True)})
    e.wbytes(s + 0x50ba, bytes([r.choice([0, 1, 1, 1, 0x80])]))
    mode = r.choice(['small', 'edge', 'neg'])
    if mode == 'neg':
        x = 0x7ffffff0
        delta = 0x80000010
    else:
        x = r.randint(0, 0x100)
        delta = x + r.choice([-1, 0, 1, -5, 7, 0x100]) if mode == 'edge' else r.randint(0, x + 3)
    e.w32(s + 0xd, x & 0xffffffff)
    e.w32(s + 0x51a5, (P - delta) & 0xffffffff)
    e.w32(s + 0x51a9, 0 if r.random() < 0.12 else P)
    return [s]


def _g53b100(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    sysv = e.r32(so + 0x40)
    hook_rec(c, 0x53aa10, 2, this=True, ret=lambda em, k: 0x1000 + k * 0x11)
    hook_rec(c, 0x53ac90, 1, this=True)
    other = r.choice([0, 1, 5, 0xfffffffb, 0x7fffffff, 0x80000000, 3])
    val = sysv if r.random() < 0.25 else other
    hook_rec(c, 0x53aa80, 1, this=True, stackmark=(0,), side=lambda em, k: em.w32(em.arg32(0), val))
    elems = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        el = rnd(c, 0x30)
        e.w32(el + 0x20, r.choice([0, 1, 2, 4, 5, 0xfffffffe, 0xffffffff, 0x80000000, 0x7fffffff, r.getrandbits(32)]))
        elems.append(el)
    lst = reftab(c, elems)
    vt = e.r32(lst)
    e.w32(vt + 0xc, pystub(c, 0, this=True))
    d = rnd(c, 0x40)
    e.w32(d, 0 if (val != sysv and r.random() < 0.1) else lst)
    return [d]


def _g5aa190(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    k = {'i': 0}

    def s40(em, rr):
        ptr = em.arg32(0)
        em.calllog.append(('stream.40', k['i'], em.reg('ecx')))
        em.w32(ptr, n if k['i'] == 0 else (0x100 + k['i'] * 7) & 0xffffffff)
        k['i'] += 1
        em.ret(0, 4)
    s = obj(c, 0x20, {0x40: e.stub_fn('s40', s40)})

    def alloc(em, rr):
        sz = em.arg32(0)
        em.calllog.append(('malloc', sz))
        em.ret(eax=rnd(c, max(sz, 16)), argbytes=0)
    e.hook(0x41e290, alloc)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: 0xaa000000 + k * 16)})
    d = rnd(c, 0x20)
    return [d, s]


def _g5d79f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = [r.getrandbits(32) | 1 for _ in range(4)]
    objs = {}
    for i in ids:
        if r.random() < 0.7:
            objs[i] = rnd(c, 0x20)

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    q = obj(c, 0x20, {0x60: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x58: e.stub_fn('find', find), 0xb0: pystub(c, 0, this=True, ret=rnd(c, 0x10)),
                           0x138: pystub(c, 0, this=True, ret=q), 0x4c: pystub(c, 2, this=True, ret=r.getrandbits(32))})

    def m4cc(em, rr):
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=r.choice([0, 0, 1, 0x100]), argbytes=0)
    e.hook(0x4cc850, m4cc)
    e.w32(0x7003a0, rnd(c, 0x90))
    e._image_dirty = True
    d = rnd(c, 0x200)
    for off, v in ((0x1de, ids[0]), (0x1e2, ids[1]), (0x1d6, ids[2]), (0x1da, ids[3])):
        e.w32(d + off, v)
    return [d]


S(0x51f7c0, 'GUESS read a record from a stream', 'thiscall', None, ret='al', gen=_g51f7c0, note='batch36040')
S(0x539780, 'GUESS validate a pointer and log', 'thiscall', None, ret='al', gen=_g539780, note='batch36040')
S(0x53b100, 'GUESS rotate ids and prune a list', 'thiscall', None, ret=None, gen=_g53b100, note='batch36040')
S(0x5aa190, 'GUESS read two object arrays from a stream', 'thiscall', None, ret=None, gen=_g5aa190, note='batch36040')
S(0x5d79f0, 'GUESS resolve ids and settings', 'thiscall', None, ret=None, gen=_g5d79f0, note='batch36040')
