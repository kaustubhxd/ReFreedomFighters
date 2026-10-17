"""specs_s240014h.py - Sonnet-w4a: hand specs for the lifted tier-5 ports of batch 240014."""
import struct
import pe_emu
import recruits_util
from pilot import S, F
from recruits_util import sysobj, rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain, STACK_LO, STACK_HI


def _w(c):
    return c.rng.getrandbits(32)


def g570310h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x300)
    e.wbytes(this + 0x1a3, bytes([r.choice([0, 0, 1, 0x80])]))
    n = r.choice([0, 1, 2, 3, 4, 6])
    e.w32(this + 0x22c, n)
    e.w32(this + 0x230, _w(c))
    e.w32(this + 0x234, _w(c))
    for i in range(8):
        a = obj(c, 0x20, {0x284: pystub(c, 1, this=True, ret=lambda em, k: _w(c)),
                          0xbc: pystub(c, 1, this=True, ret=lambda em, k: _w(c))})
        e.w32(this + 0x1cc + 4 * i, a)
    for i in range(2):
        a = obj(c, 0x20, {0x70: pystub(c, 1, this=True, deref={0: 3}, ret=lambda em, k: _w(c))})
        e.w32(this + 0x1c0 + 4 * i, a)
    return [this]


def g5ae710h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(0x400)))
    hook_rec(c, 0x5ae5a0, 2, this=True, pop=8, stackmark=(0,), side=fill, ret=lambda em, k: _w(c))
    st14 = pystub(c, 4, this=True, deref={2: -0x400}, ret=lambda em, k: _w(c))
    st68 = pystub(c, 3, this=True, ret=lambda em, k: _w(c))
    st5c = pystub(c, 3, this=True, ret=lambda em, k: _w(c))
    console = obj(c, 0x80, {0x14: st14, 0x68: st68, 0x5c: st5c})
    sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=console)})
    this = rnd(c, 0x600)
    return [this, r.choice([0, 1, 0x100, 0xff])]


S(0x570310, "GUESS lifted 0x570310", "thiscall", None, ret=None, gen=g570310h, note='batch240014')
S(0x5ae710, 'GUESS lifted 0x5ae710', 'thiscall', None, ret='eax', gen=g5ae710h, note='batch240014')

def g5ae020h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def get_flag(em, k):
        if r.random() < 0.7:     # sometimes the lookup leaves the caller's default flag untouched
            em.w8(em.arg32(1), r.choice([0, 1]))
    st90 = pystub(c, 2, this=True, stackmark=(1,), side=get_flag, ret=lambda em, k: _w(c))
    console = obj(c, 0x100, {0x90: st90})
    sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=console)})

    def fill(em, k):
        em.wbytes(em.reg('ecx'), bytes(r.getrandbits(8) for _ in range(0x14)))
    hook_rec(c, 0x5b07d0, 2, this=True, pop=8, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5b07f0, 2, this=True, pop=8, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5aedb0, 0, this='mark', pop=0, side=fill, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5af2a0, 2, this='mark', pop=8, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5b04e0, 5, this=True, pop=20, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5b0560, 1, this=True, pop=4, ret=lambda em, k: _w(c))
    this = rnd(c, 0xe40)
    e.wbytes(this + 3, bytes([r.choice([0x52, 0x52, 0x41, 0])]))
    return [this]


S(0x5ae020, 'GUESS lifted 0x5ae020', 'thiscall', None, ret=None, gen=g5ae020h, note='batch240014')


def g5ef3a0h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    def sr(em, k):     # log the head record the callee sees into the call log (a shared seh_record block keeps only the last state)
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))
    sysobj(c)
    child = obj(c, 0x40, {0x14: pystub(c, 5, this=True, side=sr, pop=20, ret=lambda em, k: _w(c)),
                          0x8: pystub(c, 0, this=True, side=sr, ret=lambda em, k: _w(c))})
    hook_rec(c, 0x41e290, 1, pop=0, side=sr, ret=lambda em, k: rnd(c, 0x100))
    hook_rec(c, 0x5aba60, 4, this=True, pop=16, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5ac5d0, 1, this=True, pop=4, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5ac940, 1, this=True, pop=4, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5acac0, 1, this=True, pop=4, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5ed460, 0, this=True, pop=0, side=sr, ret=lambda em, k: child)
    hook_rec(c, 0x5edc60, 1, this=True, pop=4, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5edb00, 1, this=True, pop=4, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5ef880, 4, this=True, pop=16, side=sr, ret=lambda em, k: _w(c))
    seh_chain(c, r.choice([0, 1, 2]))
    this = rnd(c, 0x100)
    for off in (0xa9, 0xa1, 0xa5):
        e.w32(this + off, rnd(c, 0x20))
    e.w32(this + 0x8c, r.choice([0, 1, 5, 8, _w(c)]))
    e.wbytes(this + 0xb7, struct.pack('<hh', r.choice([0, 1, -1, 0x7fff, -0x8000, r.randrange(-300, 300)]), r.choice([0, 1, -1, 0x7fff, -0x8000, r.randrange(-300, 300)])))
    a4 = r.choice([0, 0, _w(c) | 1])
    return [this, _w(c), _w(c), _w(c), _w(c), a4]


S(0x5ef3a0, 'GUESS lifted 0x5ef3a0', 'thiscall', None, ret=None, gen=g5ef3a0h, note='batch240014')


_FMT_NARGS = {0x6a1f68: 2, 0x6a1f70: 3, 0x6a1f7c: 4, 0x6a1f94: 7, 0x6a1fb0: 3}


def g536370h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def logf(em, res):       # cdecl logger slot 0x2c(obj, fmt, ...): the number of arguments follows the format string
        n = _FMT_NARGS[em.arg32(1)]
        vals = tuple(0x57ac0000 if STACK_LO <= em.arg32(i) < STACK_HI else em.arg32(i) for i in range(n))
        em.calllog.append(('log',) + vals)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=sink)})
    e.w32(0x700390, logger)
    e.w32(0x7003b0, pystub(c, 0, pop=0, ret=lambda em, k: _w(c)))
    e.w32(0x677b5c, _w(c))
    e.wbytes(0x677b60, bytes([r.getrandbits(8)]))
    base = rnd(c, 0x400)
    edi = obj(c, 0x5400, {0x1ec: pystub(c, 1, this=True, ret=lambda em, k: _w(c)),
                          0x1e8: pystub(c, 1, this=True, ret=lambda em, k: _w(c))})
    e.w32(edi + 0x5302, base)
    rec = rnd(c, 0x40)
    typ = r.choice([1, 2, 3, 3, 4, 5, 5, 16, 6, 7, 15, 17, 0, 0xffffffff])
    e.w32(rec, typ)
    e.w32(rec + 4, r.randrange(0, 0x100))
    e.wbytes(rec + 8, struct.pack('<H', r.choice([0, 1, 2, 3, 5, 8])))
    e.w32(rec + 0xc, r.choice([0, 0, r.randrange(1, 0x100)]))
    tab = r.randrange(0, 0x100)
    e.w32(rec + 0x10, r.choice([tab, 0, r.randrange(0, 0x100)]))
    for i in range(10):
        e.w32(base + 4 * i + 0, r.choice([0, 0, r.randrange(0, 0x200)]))
    for off in range(0, 0x400, 4):
        if r.random() < 0.3:
            e.w32(base + off, r.choice([0, r.randrange(0, 0x100)]))
    return [edi, rec]


S(0x536370, 'GUESS lifted 0x536370', 'thiscall', None, ret=None, gen=g536370h, note='batch240014')


def g5ae940h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def reg(em, res):      # 0x5c2b00 thiscall(5 args): every call is logged in full (hook_rec keeps only 8 rows)
        em.calllog.append(('reg', em.reg('ecx')) + tuple(em.arg32(i) for i in range(5)))
        em.ret(eax=_w(c), argbytes=20)
    c.emu.hook(0x5c2b00, reg)
    recruits_util._HOOKED.add(0x5c2b00)
    this = rnd(c, 0x200)
    a = rnd(c, 8)
    e.wbytes(a + 2, bytes([r.choice([0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x31, 0x39, 0, 0xff, 0x80])]))
    return [this, a]


S(0x5ae940, 'GUESS lifted 0x5ae940', 'thiscall', None, ret=None, gen=g5ae940h, note='batch240014')


def g5b4b40h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fl = lambda: struct.pack('<f', r.choice([0.0, 1.0, 2.0, 0.2, 0.5, 3.0, r.uniform(0, 4)]))

    def log_hook(addr, nargs, pop):
        def h(em, res):
            em.calllog.append(('h%x' % addr, em.reg('ecx')) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=_w(c), argbytes=pop)
        c.emu.hook(addr, h)
        recruits_util._HOOKED.add(addr)
    log_hook(0x59a580, 3, 12)
    log_hook(0x596d30, 1, 4)
    log_hook(0x5c4290, 0, 0)
    strobj = obj(c, 0x20, {0x0: pystub(c, 2, this=True, ret=lambda em, k: _w(c))})
    keyobj = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100, 0x101]) if r.random() < 0.5 else 0)})
    inobj = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, ret=lambda em, k: r.choice([0, 1]))})
    pstruct = rnd(c, 0x20)
    e.wbytes(pstruct + 4, fl())
    e.wbytes(pstruct + 0xc, fl())
    ptrobj = obj(c, 0x20, {0x94: pystub(c, 0, this=True, ret=pstruct)})

    def wr_local(em, k):
        em.w32(em.arg32(1), _w(c))
    console = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=wr_local, ret=lambda em, k: _w(c))})
    found = rnd(c, 0x40)
    obj38c = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, found, found]))})
    e.w32(0x70038c, obj38c)
    so = sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=console)}, table_size=0xc00)
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0xae4, strobj)
    e.wbytes(tbl + 0xbac, bytes([r.getrandbits(8)]))
    e.w32(so + 0x1907, inobj)
    e.w32(so + 0x1aa3, ptrobj)
    e.wbytes(so + 0x1b40, fl())
    blk = rnd(c, 0x500)
    e.w32(blk + 0x4ac, r.choice([0, 1, 5]))
    e.w32(0x7003b8, blk)
    e.wbytes(0x700324, fl())
    e.wbytes(0x6ffa60, fl())
    child = rnd(c, 0x2400)
    mid = rnd(c, 0x900)
    e.w32(mid + 0x852, child)
    this = rnd(c, 0x200)
    e.w32(this + 0x5f, mid)
    for off in range(0x12f, 0x15f + 1, 4):
        e.w32(this + off, _w(c))
    return [this]


S(0x5b4b40, 'GUESS lifted 0x5b4b40', 'thiscall', None, ret=None, gen=g5b4b40h, note='batch240014')


class _Lst:
    """a game list container as the exe iterates it: slot 0x4c(&it) rewinds, slot 0x5c(&it) returns the next element and sets
    it[0] = 1 (valid) or 0, slot 0x64 returns the next element or 0, slot 0x44(&it) erases the last returned element"""

    def __init__(self, c, elems, slots=(0x4c, 0x5c, 0x44, 0x64)):
        self.c, self.el, self.idx = c, list(elems), 0
        d = {0x4c: pystub(c, 1, this=True, stackmark=(0,), side=self.rewind, ret=lambda em, k: 0),
             0x5c: pystub(c, 1, this=True, stackmark=(0,), side=None, ret=self.nxt_flag),
             0x44: pystub(c, 1, this=True, stackmark=(0,), side=self.erase, ret=lambda em, k: 0),
             0x64: pystub(c, 1, this=True, stackmark=(0,), ret=self.nxt_ptr)}
        self.o = obj(c, 0x40, d)

    def rewind(self, em, k):
        self.idx = 0

    def nxt_flag(self, em, k):
        if self.idx < len(self.el):
            e = self.el[self.idx]
            self.idx += 1
            em.w32(em.arg32(0), 1)
            return e
        em.w32(em.arg32(0), 0)
        return 0

    def nxt_ptr(self, em, k):
        if self.idx < len(self.el):
            self.idx += 1
            return self.el[self.idx - 1]
        return 0

    def erase(self, em, k):
        if self.idx > 0:
            self.el.pop(self.idx - 1)
            self.idx -= 1


def g53b380h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fl = lambda: struct.pack('<f', r.choice([0.0, 1.0, 2.0, -1.5, 5.0, r.uniform(-10, 10)]))
    ids = {}

    def lookup(em, k):
        i = em.arg32(0)
        if i not in ids:
            if r.random() < 0.2 and i < 10:      # list-N ids (>= 10) are dereferenced right away: always known
                ids[i] = 0
            else:
                o = obj(c, 0x20, {0x8c: pystub(c, 1, this=True, deref={0: 3}, ret=lambda em, k: _w(c)),
                                  0x180: pystub(c, 2, this=True, deref={0: 3}, ret=lambda em, k: r.choice([0, 1, 1]))})
                e.w32(o + 8, rnd(c, 0x10))
                ids[i] = o
        return ids[i]
    ev = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=lookup)})
    v2 = obj(c, 0x40, {0x8c: pystub(c, 1, this=True, deref={0: 3}, ret=lambda em, k: _w(c)),
                       0x180: pystub(c, 2, this=True, deref={0: 3}, ret=lambda em, k: r.choice([0, 1, 1]))})
    B = obj(c, 0x40, {0x10: pystub(c, 6, this=True, ret=lambda em, k: r.choice([0, 1, 1]))})
    A = rnd(c, 0x5400)
    e.w32(A + 0x52fe, B)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lookup)}, table_size=0x40)
    e.w32(so + 0x1a9f, A)

    def h4db3b0(em, res):
        em.calllog.append(('h4db3b0', em.reg('ecx')))
        em.ret(eax=obj3, argbytes=0)
    obj3 = rnd(c, 0x100)
    c.emu.hook(0x4db3b0, h4db3b0)
    recruits_util._HOOKED.add(0x4db3b0)

    def elem(idr=(0, 6)):
        o = rnd(c, 0x40)
        e.w32(o, r.choice([1, 1, 2, 3]))
        e.wbytes(o + 4, fl())
        e.wbytes(o + 0xc, fl() + fl() + fl())
        e.w32(o + 0x18, r.randrange(*idr))
        e.wbytes(o + 0x1c, fl())
        return o
    Lel = [elem() for _ in range(r.choice([0, 1, 2, 3, 4]))]
    L = _Lst(c, Lel)
    # list N (optional): its slot 0x14 says whether it is usable, elements are ids of the same kind
    N = None
    if r.random() < 0.5:
        N = _Lst(c, [elem((10, 16)) for _ in range(r.choice([0, 1, 2, 3]))])
        e.w32(N.o + 0x0, e.r32(N.o))
        vt = e.r32(N.o)
        e.w32(vt + 0x14, pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 1])))
    # list M (optional): nodes with kind at +0xc and key at +0x14 that may match the element, float at +0x10
    M = None
    if True:     # an accepted element is merged into M, and a NULL M is dereferenced right away: M is always present
        mel = []
        for _ in range(r.choice([0, 1, 2, 3])):
            n = rnd(c, 0x40)
            src = r.choice(Lel) if Lel and r.random() < 0.6 else None
            e.w32(n + 0xc, e.r32(src) if src else r.choice([1, 2]))
            e.wbytes(n + 0x14, e.rbytes(src + 4, 4) if src else fl())
            e.wbytes(n + 0x10, fl())
            mel.append(n)
        M = _Lst(c, mel)
        vt = e.r32(M.o)
        e.w32(vt + 4, pystub(c, 1, this=True, ret=lambda em, k: rnd(c, 0x40) + 8))
    owner = rnd(c, 0x100)
    a3 = rnd(c, 0x20)
    return [owner, L.o, M.o if M else 0, a3, N.o if N else 0]


S(0x53b380, 'GUESS lifted 0x53b380', 'stdcall', None, ret=None, gen=g53b380h, note='batch240014')


_FMT660 = {0x6c4990: 2, 0x6c49d4: 3}


def g660cf0h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fl0 = lambda: struct.pack('<f', r.choice([0.0, 0.0, 1.0, -2.0, 3.5])) if r.random() < 0.7 else struct.pack('<I', r.choice([1, 0x80000001, 0x7fc00000, _w(c) | 1]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))
    seh_chain(c, r.choice([0, 1, 2]))

    def logf(em, res):
        n = _FMT660[em.arg32(1)]
        em.calllog.append(('log',) + tuple(em.arg32(i) for i in range(n)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, side=sr, ret=sink)})
    e.w32(0x700390, logger)
    so = sysobj(c)
    e.wbytes(so + 0x9c7, fl0() if r.random() < 0.4 else struct.pack('<f', 1.0))
    e.wbytes(so + 0x9c3, fl0() if r.random() < 0.4 else struct.pack('<f', 1.0))
    S_ = rnd(c, 0x200)
    newobj = obj(c, 0x20, {0x4: pystub(c, 1, this=True, side=sr, ret=S_)})

    def node():
        n = rnd(c, 0x200)
        e.w32(n + 0x1dd, r.choice([0, 0, 1, _w(c)]))
        e.w32(n + 0x1e5, r.choice([0, 1, 2, 7]))
        e.w32(n + 0x1e1, r.choice([0, 0, 5]))
        return n
    nodes = [node() for _ in range(r.choice([0, 1, 2, 3]))]
    ch = _Lst(c, nodes)
    vt = e.r32(ch.o)
    e.w32(vt + 0x0, pystub(c, 1, this=True, side=sr, ret=lambda em, k: _w(c)))
    e.w32(vt + 0x14, pystub(c, 0, this=True, side=sr, ret=lambda em, k: _w(c)))
    this = rnd(c, 0x100)
    f1c = r.choice([0, 0, 1, 5])
    e.w32(this + 0x1c, f1c)
    e.w32(this + 0x18, ch.o if (f1c == 0 or r.random() < 0.8) else 0)   # path B (1c == 0) calls through [this+0x18]: never NULL there
    e.wbytes(this + 0x20, bytes([r.choice([0, 0, 0, 1])]))
    e.w32(this + 0xc, r.choice([0, 1, 5, 0x30, 0x31, 0x32]))
    e.w32(this + 0x10, _w(c))

    def h41e290(em, res):
        em.calllog.append(('new', em.arg32(0)))
        sr(em, 0)
        em.ret(eax=rnd(c, 0x40), argbytes=0)
    c.emu.hook(0x41e290, h41e290)
    recruits_util._HOOKED.add(0x41e290)
    hook_rec(c, 0x4cca60, 2, this=True, pop=8, side=sr, ret=lambda em, k: newobj)
    return [this]


S(0x660cf0, 'GUESS lifted 0x660cf0', 'thiscall', None, ret=None, gen=g660cf0h, note='batch240014')


def g4d8450h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))

    def logf(em, res):
        em.calllog.append(('log', em.arg32(0), em.arg32(1), em.arg32(2)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, side=sr, ret=sink)})
    e.w32(0x700390, logger)

    def owned():
        return obj(c, 0x20, {0x0: pystub(c, 1, this=True, side=sr, ret=lambda em, k: _w(c))})
    els = []
    for _ in range(r.choice([0, 1, 2, 3])):
        n = rnd(c, 0x10)
        e.w32(n + 4, r.choice([0, owned(), owned()]))
        els.append(n)
    L = _Lst(c, els)
    vt = e.r32(L.o)
    e.w32(vt + 0x0, pystub(c, 1, this=True, side=sr, ret=lambda em, k: _w(c)))
    e.w32(vt + 0x14, pystub(c, 0, this=True, side=sr, ret=lambda em, k: r.choice([0, 1, 7])))
    this = rnd(c, 0x20)
    e.w32(this + 4, L.o)
    e.w32(this + 8, r.choice([0, owned(), owned()]))
    e.w32(this + 0xc, r.choice([0, owned(), owned()]))
    hook_rec(c, 0x4d8c30, 1, this=True, pop=4, side=sr, ret=lambda em, k: _w(c))
    return [this]


S(0x4d8450, 'GUESS lifted 0x4d8450', 'thiscall', None, ret=None, gen=g4d8450h, note='batch240020')


def g4d8af0h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))

    def logf(em, res):
        em.calllog.append(('log', em.arg32(0), em.arg32(1), em.arg32(2)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, side=sr, ret=sink)})
    e.w32(0x700390, logger)
    srcel = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 3, 4]))]
    SRC = _Lst(c, srcel)
    holder = obj(c, 0x20, {0x10: pystub(c, 0, this=True, side=sr, ret=lambda em, k: SRC.o if r.random() < 0.9 else 0)})
    loc = []
    pos = [0]
    lvt = e.alloc(0x100, 4)

    def l_rewind(em, k):
        pos[0] = 0

    def l_next(em, k):
        if pos[0] < len(loc):
            pos[0] += 1
            em.w32(em.arg32(0), 1)
            return loc[pos[0] - 1]
        em.w32(em.arg32(0), 0)
        return 0
    e.w32(lvt + 0x4c, pystub(c, 1, this='mark', stackmark=(0,), side=l_rewind, ret=lambda em, k: 0))
    e.w32(lvt + 0x5c, pystub(c, 1, this='mark', stackmark=(0,), ret=l_next))

    def h_ctor(em, res):         # 0x4ccd10(this = stack container, 0x20, 0): installs the vtable
        em.calllog.append(('ctor', 0x57ac0000 if STACK_LO <= em.reg('ecx') < STACK_HI else em.reg('ecx'), em.arg32(0), em.arg32(1)))
        sr(em, 0)
        em.w32(em.reg('ecx'), lvt)
        loc.clear()
        em.ret(eax=_w(c), argbytes=8)

    def h_ins(em, res):
        em.calllog.append(('ins', 0x57ac0000 if STACK_LO <= em.reg('ecx') < STACK_HI else em.reg('ecx'), em.arg32(0)))
        sr(em, 0)
        loc.append(em.arg32(0))
        em.ret(eax=_w(c), argbytes=4)

    def h_sort(em, res):
        em.calllog.append(('sort', 0x57ac0000 if STACK_LO <= em.reg('ecx') < STACK_HI else em.reg('ecx')))
        sr(em, 0)
        loc.reverse()
        em.ret(eax=_w(c), argbytes=0)

    def h_dtor(em, res):
        em.calllog.append(('dtor', 0x57ac0000 if STACK_LO <= em.reg('ecx') < STACK_HI else em.reg('ecx')))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    for a, h in ((0x4ccd10, h_ctor), (0x4cd950, h_ins), (0x4cf850, h_sort), (0x4cd0e0, h_dtor)):
        c.emu.hook(a, h)
        recruits_util._HOOKED.add(a)
    this = rnd(c, 0x120)
    e.w32(this + 0x104, holder)
    return [this, _w(c)]


S(0x4d8af0, 'GUESS lifted 0x4d8af0', 'thiscall', None, ret=None, gen=g4d8af0h, note='batch240020')


_FMT49D = {0x68eee0: 2, 0x68ef38: 2, 0x68ef4c: 4, 0x68ef68: 2, 0x68ef7c: 6, 0x68ef24: 2, 0x68efb8: 2}


def g49d480h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))

    def logf(em, res):
        n = _FMT49D[em.arg32(1)]
        em.calllog.append(('log',) + tuple(0x57ac0000 if STACK_LO <= em.arg32(i) < STACK_HI else em.arg32(i) for i in range(n)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, side=sr, ret=sink)})
    e.w32(0x700390, logger)
    strobj = rnd(c, 0x20)
    ids = {}

    def tool(i):
        if i not in ids:
            k = r.random()
            if k < 0.15:
                ids[i] = 0
            else:
                o = rnd(c, 0x60)
                e.w32(o + 0x18, r.choice([0x10, 0x10, 0x30, 0, 0x1f]))
                e.w32(o + 0x1c, r.choice([0, 0, r.randrange(1, 5)]))
                if r.random() < 0.8:
                    d = obj(c, 0x40, {0x1d8: pystub(c, 2, this=True, stackmark=(0,), side=sr, ret=strobj)})
                    e.w32(o + 0x30, d)
                else:
                    e.w32(o + 0x30, 0)
                st = rnd(c, 0x30)
                e.w32(o + 0x40, st)
                ids[i] = o
        return ids[i]
    t38c = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, side=sr, ret=lambda em, k: tool(em.arg32(0)))})
    e.w32(0x70038c, t38c)
    look = {}

    def lookup(em, k):
        i = em.arg32(0)
        if i not in look:
            if r.random() < 0.25:
                look[i] = 0
            else:
                o = rnd(c, 0x20)
                e.w32(o + 0xc, rnd(c, 8))
                look[i] = o
        return look[i]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lookup)})
    n = r.choice([0, 1, 2, 3, 4])
    arr = rnd(c, 4 * max(n, 1))
    for i in range(n):
        e.w32(arr + 4 * i, r.randrange(1, 4))
    this = rnd(c, 0x20)
    e.w32(this + 4, arr)
    e.w32(this + 0x10, n)

    def h4cc1d0(em, res):
        em.calllog.append(('cstr', 0x57ac0000 if STACK_LO <= em.reg('ecx') < STACK_HI else em.reg('ecx')))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)

    def h4cbec0(em, res):
        em.calllog.append(('strdtor', 0x57ac0000 if STACK_LO <= em.reg('ecx') < STACK_HI else em.reg('ecx')))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    for a, h in ((0x4cc1d0, h4cc1d0), (0x4cbec0, h4cbec0)):
        c.emu.hook(a, h)
        recruits_util._HOOKED.add(a)
    return [this]


S(0x49d480, 'GUESS lifted 0x49d480', 'thiscall', None, ret=None, gen=g49d480h, note='batch240020')


def g5ef560h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))

    def rd(slot, size):
        def h(em, res):          # reader slot: writes `size` random bytes through its pointer argument, argument count 1 (slot 0x18: 2)
            p = em.arg32(0)
            nb = min(em.arg32(1), 0x100) if slot == 0x18 else size
            data = bytes(r.getrandbits(8) for _ in range(nb))
            if slot == 0x68 and r.random() < 0.5:
                data = bytes([r.choice([0, 1])])
            em.wbytes(p, data)
            em.calllog.append(('rd', slot, 0x57ac0000 if STACK_LO <= p < STACK_HI else p, data.hex(), em.arg32(1) if slot == 0x18 else 0))
            sr(em, 0)
            nargs = 2 if slot == 0x18 else 1
            em.ret(eax=_w(c), argbytes=4 * nargs)
        return c.emu.stub_fn('rd%x' % slot, h)
    slots = {0xc: pystub(c, 1, this=True, side=sr, ret=lambda em, k: _w(c)), 0x18: rd(0x18, 0x80), 0x40: rd(0x40, 4),
             0x48: rd(0x48, 4), 0x50: rd(0x50, 4), 0x68: rd(0x68, 1), 0x4c: rd(0x4c, 2)}
    reader = obj(c, 0x100, slots)

    def child():
        return obj(c, 0x20, {0xc: pystub(c, 1, this=True, side=sr, ret=lambda em, k: _w(c))})
    this = rnd(c, 0x100)
    for off in (0xa9, 0xa1, 0xa5):
        e.w32(this + off, child())
    objB = obj(c, 0x20, {0x14: pystub(c, 5, this=True, side=sr, pop=20, ret=lambda em, k: _w(c)),
                         0xc: pystub(c, 1, this=True, side=sr, ret=lambda em, k: _w(c))})

    def h41e290(em, res):
        em.calllog.append(('new', em.arg32(0)))
        sr(em, 0)
        em.ret(eax=rnd(c, 0x100), argbytes=0)
    c.emu.hook(0x41e290, h41e290)
    recruits_util._HOOKED.add(0x41e290)
    hook_rec(c, 0x5ed460, 0, this=True, pop=0, side=sr, ret=lambda em, k: objB)
    return [this, reader]


S(0x5ef560, 'GUESS lifted 0x5ef560', 'thiscall', None, ret=None, gen=g5ef560h, note='batch240020')


class _Map:
    """the exe's stack-allocated tool-count map (ctor 0x4ccbe0, find 0x4ce0c0, insert 0x4cd540, erase 0x4cecd0, size field at +0x14,
    iteration slots 0x4c rewind / 0x64 next-node): node = {key, count}; find returns the node, insert returns &node.count"""

    def __init__(self, c, e, sr):
        self.c, self.e, self.sr = c, e, sr
        self.nodes = []
        self.pos = 0
        self.vt = e.alloc(0x100, 4)
        e.w32(self.vt + 0x4c, pystub(c, 1, this='mark', stackmark=(0,), side=self.rewind, ret=lambda em, k: 0))
        e.w32(self.vt + 0x64, pystub(c, 1, this='mark', stackmark=(0,), ret=self.nxt))
        self.ctr = None

    def sync(self, em):
        if self.ctr is not None:
            em.w32(self.ctr + 0x14, len(self.nodes))

    def rewind(self, em, k):
        self.pos = 0

    def nxt(self, em, k):
        if self.pos < len(self.nodes):
            self.pos += 1
            return self.nodes[self.pos - 1]
        return 0

    def mark(self, em):
        v = em.reg('ecx')
        return 0x57ac0000 if STACK_LO <= v < STACK_HI else v

    def ctor(self, em, res):
        em.calllog.append(('mctor', self.mark(em), em.arg32(0), em.arg32(1)))
        self.sr(em, 0)
        self.ctr = em.reg('ecx')
        self.nodes = []
        em.w32(self.ctr, self.vt)
        em.w32(self.ctr + 0x14, 0)
        em.ret(eax=_w(self.c), argbytes=8)

    def find(self, em, res):
        key = em.arg32(0)
        em.calllog.append(('mfind', self.mark(em), key))
        self.sr(em, 0)
        r = 0
        for n in self.nodes:
            if em.r32(n) == key:
                r = n
        em.ret(eax=r, argbytes=4)

    def insert(self, em, res):
        key = em.arg32(0)
        em.calllog.append(('minsert', self.mark(em), key))
        self.sr(em, 0)
        n = self.c.emu.alloc(8, 4)
        em.w32(n, key)
        em.w32(n + 4, 0)
        self.nodes.append(n)
        self.sync(em)
        em.ret(eax=n + 4, argbytes=4)

    def erase(self, em, res):
        key = em.arg32(0)
        em.calllog.append(('merase', self.mark(em), key))
        self.sr(em, 0)
        for n in list(self.nodes):
            if em.r32(n) == key:
                self.nodes.remove(n)
        self.sync(em)
        em.ret(eax=_w(self.c), argbytes=4)

    def dtor(self, em, res):
        em.calllog.append(('mdtor', self.mark(em)))
        self.sr(em, 0)
        em.ret(eax=_w(self.c), argbytes=0)


_FMT496 = {0x68e744: 2, 0x68e77c: 6, 0x68e794: 2}


def g496760h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))

    def logf(em, res):
        n = _FMT496[em.arg32(1)]
        em.calllog.append(('log',) + tuple(em.arg32(i) for i in range(n)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, side=sr, ret=sink)})
    e.w32(0x700390, logger)
    # keys (shared pool) and tools
    keys = [rnd(c, 0x30) for _ in range(3)]
    tools = {}

    def tool(i):
        if i not in tools:
            o = rnd(c, 0x60)
            e.w32(o + 0x1c, r.choice([0, 0, 0, 5]))
            e.w32(o + 0x40, r.choice([0, keys[0], keys[1], keys[2]]))
            tools[i] = o
        return tools[i]
    e.w32(0x70038c, obj(c, 0x20, {0xcc: pystub(c, 1, this=True, side=sr, ret=lambda em, k: tool(em.arg32(0)))}))
    # entries: g groups of 8 entries of 0x70 bytes
    cnt = r.choice([0, 1, 7, 8, 9, 0x70 * 1, 0x70 * 8, 0x70 * 9, 0x70 * 17, r.randrange(0, 0x70 * 20)])
    ngroups = (((cnt * 0x24924925 >> 32) + ((cnt - (cnt * 0x24924925 >> 32)) >> 1)) >> 6)
    ngroups = (ngroups + 7) >> 3
    base = rnd(c, 0x54 + 0x380 * max(ngroups, 1) + 0x80)
    X = rnd(c, 0x20)
    e.w32(X + 0xc, cnt)
    e.w32(X + 4, base)
    this = rnd(c, 0x20)
    e.w32(this + 0x14, X)
    # iterable lists behind each entry
    def mk_iter():
        ids = [r.randrange(1, 4) for _ in range(r.choice([0, 1, 2, 3]))]
        st = {'i': 0}

        def rew(em, k):
            st['i'] = 0

        def nx(em, k):
            if st['i'] < len(ids):
                st['i'] += 1
                em.w32(em.arg32(0), 1)
                return ids[st['i'] - 1]
            em.w32(em.arg32(0), 0)
            return 0
        return obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,), side=rew, ret=lambda em, k: 0),
                             0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=nx)})
    for off in range(0x54 - 0x18, 0x54 + 0x380 * max(ngroups, 1), 0x70):
        pass
    for g in range(max(ngroups, 1)):
        for k in range(8):
            ent = base + 0x54 + g * 0x380 + k * 0x70
            e.w32(ent - 0x18, r.choice([0, 0, 0x4000000, 0x1]))
            if r.random() < 0.8:
                o1 = rnd(c, 0x20)
                o2 = rnd(c, 0x20)
                e.w32(o2 + 8, r.choice([0, mk_iter(), mk_iter()]))
                e.w32(o1 + 0x10, r.choice([0, o2, o2]))
                e.w32(ent, o1)
            else:
                e.w32(ent, 0)
    for kk in keys:
        e.w32(kk, _w(c))
        e.w32(kk + 0x18, r.randrange(0, 0x100))
    M = _Map(c, e, sr)

    def h41e290(em, res):
        em.calllog.append(('new', em.arg32(0)))
        sr(em, 0)
        em.ret(eax=rnd(c, em.arg32(0) + 8), argbytes=0)

    def hmemset(em, res):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(p, bytes([v & 0xff]) * n)
        em.calllog.append(('memset', v, n))
        sr(em, 0)
        em.ret(eax=p, argbytes=0)

    def h496380(em, res):       # clears some flag bits (a pure function of the array in the exe; random mask here)
        arr = em.arg32(0)
        em.calllog.append(('flags', em.reg('ecx')))
        n = em.r32(em.r32(em.reg('ecx') + 0x14) + 0xc)
        m = (((n * 0x24924925) >> 32) + ((n - ((n * 0x24924925) >> 32)) >> 1)) >> 6
        sz = (m + 7) >> 3
        for i in range(sz):
            em.w8(arr + i, em.r8(arr + i) & r.choice([0xff, 0xff, 0xaa, 0x0f, 0]))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=4)
    for a, h in ((0x41e290, h41e290), (0x634d10, hmemset), (0x496380, h496380), (0x4ccbe0, M.ctor), (0x4ce0c0, M.find),
                 (0x4cd540, M.insert), (0x4cecd0, M.erase), (0x4ccfe0, M.dtor), (0x634273, None)):
        if h is None:
            hook_rec(c, 0x634273, 2, pop=0, side=sr, ret=lambda em, k: 0)
        else:
            c.emu.hook(a, h)
            recruits_util._HOOKED.add(a)
    return [this]


S(0x496760, 'GUESS lifted 0x496760', 'thiscall', None, ret=None, gen=g496760h, note='batch240020')


_FMT496A = {0x68e694: 2, 0x68e6cc: 7, 0x68e704: 2}


def g496a40h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))

    def logf(em, res):
        n = _FMT496A[em.arg32(1)]
        em.calllog.append(('log',) + tuple(em.arg32(i) for i in range(n)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, side=sr, ret=sink)})
    e.w32(0x700390, logger)
    keys = [rnd(c, 0x30) for _ in range(3)]
    for kk in keys:
        e.w32(kk, _w(c))
        e.w32(kk + 0x18, r.randrange(0, 0x100))
    cnt = r.choice([0, 1, 7, 8, 9, 0x70, 0x70 * 8, 0x70 * 9, 0x70 * 17, r.randrange(0, 0x70 * 20)])
    ngroups = (((cnt * 0x24924925 >> 32) + ((cnt - (cnt * 0x24924925 >> 32)) >> 1)) >> 6)
    ngroups = (ngroups + 7) >> 3
    base = rnd(c, 0x380 * max(ngroups, 1) + 0x100)
    X = rnd(c, 0x20)
    e.w32(X + 0xc, cnt)
    e.w32(X + 4, base)
    this = rnd(c, 0x20)
    e.w32(this + 0x14, X)
    for g in range(max(ngroups, 1)):
        for k in range(8):
            ent = base + g * 0x380 + k * 0x70
            e.w32(ent + 0x3c, r.choice([0, 0, 0x4000000, 0x8000000, 0x1]))
            if r.random() < 0.85:
                A = obj(c, 0x240, {0x20c: pystub(c, 2, this=True, side=sr, ret=lambda em, k_: _w(c))})
                e.w32(A + 0xc, r.choice([0, 0, keys[0], keys[1], keys[2]]) if r.random() < 0.9 else 0)
                e.w32(ent + 0x54, A)
            else:
                e.w32(ent + 0x54, 0)
    M = _Map(c, e, sr)

    def h41e290(em, res):
        em.calllog.append(('new', em.arg32(0)))
        sr(em, 0)
        em.ret(eax=rnd(c, em.arg32(0) + 8), argbytes=0)

    def hmemset(em, res):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(p, bytes([v & 0xff]) * n)
        em.calllog.append(('memset', v, n))
        sr(em, 0)
        em.ret(eax=p, argbytes=0)

    def h496380(em, res):
        arr = em.arg32(0)
        em.calllog.append(('flags', em.reg('ecx')))
        n = em.r32(em.r32(em.reg('ecx') + 0x14) + 0xc)
        m = (((n * 0x24924925) >> 32) + ((n - ((n * 0x24924925) >> 32)) >> 1)) >> 6
        sz = (m + 7) >> 3
        for i in range(sz):
            em.w8(arr + i, em.r8(arr + i) & r.choice([0xff, 0xff, 0xaa, 0x0f, 0]))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=4)

    def h4db9a0(em, res):
        em.calllog.append(('isX', em.reg('ecx'), em.arg32(0)))
        sr(em, 0)
        em.ret(eax=r.choice([0, 1, 0x101]), argbytes=4)

    def h45f430(em, res):
        em.calllog.append(('do45f430', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=8)
    for a, h in ((0x41e290, h41e290), (0x634d10, hmemset), (0x496380, h496380), (0x4ccbe0, M.ctor), (0x4ce0c0, M.find),
                 (0x4cd540, M.insert), (0x4cecd0, M.erase), (0x4ccfe0, M.dtor), (0x4db9a0, h4db9a0), (0x45f430, h45f430)):
        c.emu.hook(a, h)
        recruits_util._HOOKED.add(a)
    hook_rec(c, 0x634273, 2, pop=0, side=sr, ret=lambda em, k: 0)
    return [this]


S(0x496a40, 'GUESS lifted 0x496a40', 'thiscall', None, ret=None, gen=g496a40h, note='batch240020')


_FMT4D88 = {0x696cd0: 2, 0x696d20: 4, 0x696d2c: 3, 0x677368: 3, 0x696d48: 2, 0x696d5c: 3, 0x696d88: 2}


def g4d8840h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8)))

    def logf(em, res):
        n = _FMT4D88[em.arg32(1)]
        em.calllog.append(('log',) + tuple(0x57ac0000 if STACK_LO <= em.arg32(i) < STACK_HI else em.arg32(i) for i in range(n)))
        sr(em, 0)
        em.ret(eax=_w(c), argbytes=0)
    sink = obj(c, 0x20, {0x2c: c.emu.stub_fn('logf', logf)})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, side=sr, ret=sink)})
    e.w32(0x700390, logger)
    recs = {}

    def lookup(em, k):
        i = em.arg32(0)
        if i not in recs:
            if r.random() < 0.25:
                recs[i] = 0
            else:
                srcobj = obj(c, 0x20, {0x8: pystub(c, 0, this=True, side=sr, ret=lambda em2, k2: rnd(c, 8))})
                mid = obj(c, 0x20, {0x30: pystub(c, 1, this=True, side=sr, ret=srcobj)})
                rec = rnd(c, 0x10)
                e.w32(rec + 4, mid)
                recs[i] = rec
        return recs[i]
    ids = [r.randrange(1, 6) for _ in range(r.choice([0, 1, 2, 3]))]
    L = _Lst(c, ids)
    vt = e.r32(L.o)
    e.w32(vt + 0x84, pystub(c, 1, this=True, side=sr, ret=lookup))
    H = obj(c, 0x20, {0x10: pystub(c, 0, this=True, side=sr, ret=L.o)})
    this = rnd(c, 0x120)
    e.w32(this + 0x104, H)
    st = rnd(c, 0x10)

    def mk(addr, nargs, pop, name, retf):
        def h(em, res):
            mark = 0x57ac0000 if STACK_LO <= em.reg('ecx') < STACK_HI else em.reg('ecx')
            em.calllog.append((name, mark) + tuple(em.arg32(i) for i in range(nargs)))
            sr(em, 0)
            em.ret(eax=retf(), argbytes=pop)
        c.emu.hook(addr, h)
        recruits_util._HOOKED.add(addr)
    mk(0x4ccd10, 2, 8, 'cctor', lambda: _w(c))
    mk(0x4cd0e0, 0, 0, 'cdtor', lambda: _w(c))
    mk(0x4cbe50, 1, 4, 'sctor', lambda: _w(c))
    mk(0x4cc5f0, 0, 0, 'sempty', lambda: r.choice([0, 1, 1, 0x101]))
    mk(0x4cc1d0, 0, 0, 'cstr', lambda: _w(c))
    mk(0x4cbec0, 0, 0, 'sdtor', lambda: _w(c))
    arg = r.choice([0, 0, 1, 2, 3, 4, 5])
    return [this, arg]


S(0x4d8840, 'GUESS lifted 0x4d8840', 'thiscall', None, ret=None, gen=g4d8840h, note='batch240020')


def g5ef950h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    # tokenizer 0x4cc500 (thiscall on a stack state struct): returns the next token id (non-zero) or 0; the spec logs the state
    toks = [r.randrange(1, 0x200) for _ in range(r.choice([0, 1, 2, 3, 5, 8, 12]))]
    pos = [0]

    def h4cc500(em, res):
        ctx = em.reg('ecx')
        words = []
        for i in range(7):
            w = em.r32(ctx + 4 * i)
            words.append(0x57ac0000 if STACK_LO <= w < STACK_HI else w)
        em.calllog.append(('tok', 0x57ac0000 if STACK_LO <= ctx < STACK_HI else ctx) + tuple(words))
        v = toks[pos[0]] if pos[0] < len(toks) else 0
        pos[0] += 1
        em.ret(eax=v, argbytes=0)
    c.emu.hook(0x4cc500, h4cc500)
    recruits_util._HOOKED.add(0x4cc500)

    def mk(addr, nargs, name):
        def h(em, res):
            em.calllog.append((name, em.reg('ecx')) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=_w(c), argbytes=4 * nargs)
        c.emu.hook(addr, h)
        recruits_util._HOOKED.add(addr)
    mk(0x5ac940, 1, 'a5ac940')
    mk(0x5acac0, 1, 'a5acac0')
    mk(0x5ef240, 0, 'a5ef240')
    widths = {}

    def w280(em, k):
        return rnd(c, 0x20)

    def w28c(em, k):
        key = (em.arg32(0), em.arg32(1))
        if key not in widths:
            widths[key] = r.choice([0, 1, 3, 8, 20, 100])
        return widths[key]
    glyph = obj(c, 0x300, {0x280: pystub(c, 1, this=True, ret=lambda em, k: gl()), 0x28c: pystub(c, 2, this=True, ret=w28c)})

    def gl():
        o = rnd(c, 0x20)
        e.wbytes(o + 0x10, bytes([r.choice([1, 5, 0x7f, 0x80, 0xff, 12])]))
        return o

    def h5ab950(em, res):
        em.calllog.append(('a5ab950', em.reg('ecx')))
        em.ret(eax=glyph, argbytes=0)
    c.emu.hook(0x5ab950, h5ab950)
    recruits_util._HOOKED.add(0x5ab950)
    sysobj(c)
    fl = lambda: struct.pack('<f', r.choice([0.0, 1.0, 10.0, 100.0, 640.0, r.uniform(1, 800)]))
    e.wbytes(0x70039c + 0, struct.pack('<I', e.r32(0x70039c)))
    so = e.r32(0x70039c)
    e.w32(so + 0x6f, r.choice([0, 50, 300, 640, 1000]))
    e.w32(so + 0x40, r.choice([0, 100, 1000, 0x7fffffff]))
    this = rnd(c, 0x120)
    for off in (0xa9, 0xa1, 0xa5):
        e.w32(this + off, rnd(c, 0x20))
    e.w32(this + 0xb1, r.choice([0, rnd(c, 0x60), rnd(c, 0x60)]))
    e.w32(this + 0x8c, r.choice([0, 1, 2, 10]))
    text = rnd(c, 0x40)
    e.wbytes(text, bytes(r.choice(b'ab c d  ef g') for _ in range(r.choice([0, 1, 5, 12, 30]))) + b'\0')
    e.w32(this + 4, text)
    return [this, r.choice([0, 1, 5, _w(c), 0x01000000, 0x7f000000, 0xff000001]), text, F(struct.unpack('<f', fl())[0])]


S(0x5ef950, 'GUESS lifted 0x5ef950', 'thiscall', None, ret=None, gen=g5ef950h, note='batch240014')


def g425d30h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    mk = lambda v: 0x57ac0000 if STACK_LO <= v < STACK_HI else v

    def txt(n):
        return bytes(r.choice(b'abcXYZ 012.:%') for _ in range(n))

    def s_prefix(em, res):      # obj slot 0: cdecl(obj, buf, fmt, v18, v1c): writes a prefix text into buf
        buf = em.arg32(1)
        t = txt(r.choice([0, 3, 12, 40])) + b'\0'
        em.wbytes(buf, t)
        em.calllog.append(('prefix', em.arg32(0), mk(buf), em.arg32(2), em.arg32(3), em.arg32(4)))
        em.ret(eax=_w(c), argbytes=0)

    def s_format(em, res):      # obj slot 0x4c: thiscall(dst, fmt, va): writes the formatted text
        dst = em.arg32(0)
        k = r.random()
        t = (b'(' if r.random() < 0.3 else b'') + txt(r.choice([0, 1, 7, 25])) + (b'\n' if r.random() < 0.4 else b'') + b'\0'
        em.wbytes(dst, t)
        em.calllog.append(('format', em.reg('ecx'), mk(dst), em.arg32(1), mk(em.arg32(2)), em.r32(em.arg32(2)), em.r32(em.arg32(2) + 4)))
        em.ret(eax=_w(c), argbytes=12)
    obj_ = obj(c, 0x60, {0x0: c.emu.stub_fn('prefix', s_prefix), 0x4c: c.emu.stub_fn('format', s_format)})
    e.wbytes(obj_ + 0x10, bytes([r.choice([0, 1, 1, 1])]))
    e.wbytes(obj_ + 0x12, bytes([0]))
    e.wbytes(obj_ + 0x13, bytes([r.choice([0, 1])]))
    e.w32(obj_ + 0x14, r.choice([0, 0, 1, 3]))
    e.w32(obj_ + 0x18, _w(c))
    e.w32(obj_ + 0x1c, _w(c))
    e.w32(obj_ + 0x24, r.choice([0, 0, rnd(c, 8)]))

    def s_sys5c(em, res):
        em.calllog.append(('sys5c', em.arg32(0), mk(em.arg32(1))))
        em.ret(eax=r.choice([0, 1, 0x100, 0x101]), argbytes=8)
    Q = obj(c, 0x20, {0x4: c.emu.stub_fn('qprint', lambda em, res: (em.calllog.append(('qprint', em.arg32(0), bytes(em.rbytes(em.arg32(1), 8)).hex())), em.ret(eax=_w(c), argbytes=0))[1])})
    qs = [0, Q, Q]
    qlast = [0]

    def qpick(k):         # the exe asks twice and dereferences the second answer: both answers are the same object
        if k % 2 == 0:
            qlast[0] = r.choice(qs)
        return qlast[0]
    so = sysobj(c, slots={0x5c: c.emu.stub_fn('s5c', s_sys5c), 0x1b0: pystub(c, 0, this=True, ret=lambda em, k: qpick(k))})
    t38 = rnd(c, 0x60)
    e.wbytes(t38 + 0x4d, bytes([r.choice([0, 1])]))
    e.w32(0x70038c, r.choice([0, t38, t38]))

    def h42ab62(em, res):       # prints the final line: log its text
        p = em.arg32(0)
        data = bytes(em.rbytes(p, 0x2100)).split(b'\0')[0]
        em.calllog.append(('print', data.hex()))
        em.ret(eax=_w(c), argbytes=0)
    c.emu.hook(0x42ab62, h42ab62)
    recruits_util._HOOKED.add(0x42ab62)
    for cell, nargs, pop, nm in ((0x6763c8, 1, 0, 'fh'), (0x6763c4, 1, 0, 'fh2'), (0x67621c, 4, 16, 'write'), (0x676098, 1, 4, 'dbg')):
        a = e.r32(cell)

        def h(em, res, nargs=nargs, pop=pop, nm=nm, cell=cell):
            vals = [em.arg32(i) for i in range(nargs)]
            if nm == 'write':
                st = vals[3]
                vals = vals[:3] + [mk(em.r32(st + 4)), em.r32(st + 4) and 0, em.r32(st + 8)] if False else vals[:3] + [em.r32(st), em.r32(st + 4), mk(em.r32(st + 8))]
                vals.append(bytes(em.rbytes(em.r32(st + 8), 0x40)).hex())
            else:
                vals = [mk(v) for v in vals]
            em.calllog.append((nm,) + tuple(vals))
            em.ret(eax=_w(c), argbytes=pop)
        e.stubs[a] = (e.stubs[a][0], h)
    fmtlen = r.choice([0, 3, 9, 30, 30, 0x1fe0, 0x2000, 0x2100 - 8])
    fmt = rnd(c, 0x2200)
    e.wbytes(fmt, txt(min(fmtlen, 0x2100)) + b'\0')
    return [obj_, fmt, _w(c), _w(c), _w(c), _w(c)]


S(0x425d30, 'GUESS lifted 0x425d30', 'cdecl', None, ret=None, gen=g425d30h, note='batch240021')


def g4f5e00h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fl = lambda: struct.pack('<f', r.choice([0.0, 1.0, 16.0, 33.5, -7.25, 100.0, 640.0, 1e9, -1e9, r.uniform(-300, 300)]))
    nz = lambda: r.choice([0, 1, 5, 480, 640, 1000, 0x7fffffff, 0xffffffff, r.randrange(0, 2000)])

    def stub(nargs, ret, deref=None):
        return pystub(c, nargs, this=True, deref=deref or {}, ret=ret)
    # sub-widgets
    def structT(off1, off2):
        o = rnd(c, 0x80)
        e.wbytes(o + off1, fl())
        e.wbytes(o + off2, fl())
        return o
    ebxw = obj(c, 0x20, {0x210: stub(1, lambda em, k: _w(c)), 0x70: stub(1, lambda em, k: _w(c), {0: 3})})
    e.w32(ebxw + 8, structT(0x40, 0x44))
    Aobj = obj(c, 0x20, {0x26c: stub(3, lambda em, k: _w(c)), 0x260: stub(1, lambda em, k: _w(c)), 0x70: stub(1, lambda em, k: _w(c), {0: 3})})
    e.w32(Aobj + 8, structT(0x40, 0x44))
    Bobj = obj(c, 0x20, {0x26c: stub(3, lambda em, k: _w(c)), 0x260: stub(1, lambda em, k: _w(c)), 0x70: stub(1, lambda em, k: _w(c), {0: 3})})
    e.w32(Bobj + 8, structT(0x40, 0x44))
    # the engine object P (ecx = a0): slot 0x294(0x69a680, 0x699c90, 0, 1) returns the widget or 0; P+8 points to a struct with floats +0x24/+0x28
    P = obj(c, 0x40, {0x294: stub(4, lambda em, k: r.choice([0, ebxw, ebxw, ebxw]))})
    e.w32(P + 8, structT(0x24, 0x28))
    W1 = obj(c, 0x20, {0x70: stub(1, lambda em, k: _w(c), {0: 3})})
    W2 = obj(c, 0x20, {0x70: stub(1, lambda em, k: _w(c), {0: 3})})
    w1z = [r.random() < 0.4]

    def w2e0(k):         # first call: widget or 0; second call: always a widget (a NULL one would be dereferenced next)
        return (0 if w1z[0] else W1) if k % 2 == 0 else W2
    this = obj(c, 0x140, {0x2dc: stub(3, lambda em, k: r.choice([0, Aobj, Aobj, Aobj])),
                          0x2e4: stub(4, lambda em, k: r.choice([0, Bobj, Bobj, Bobj])),
                          0x2e0: stub(4, lambda em, k: w2e0(k))})
    e.w32(this + 0x98, _w(c))
    so = sysobj(c)
    e.w32(so + 0x6f, nz())
    e.w32(so + 0x73, nz())
    return [this, P, _w(c), _w(c), _w(c), _w(c), _w(c)]


S(0x4f5e00, 'GUESS lifted 0x4f5e00', 'thiscall', None, ret='eax', gen=g4f5e00h, note='batch240022')


_DRAW650 = {0x6c3418: 0, 0x677368: 1, 0x6c3434: 0, 0x6c3460: 10, 0x6c3480: 4}


def g650430h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, 0)
    fl = lambda: struct.pack('<f', r.choice([0.0, 1.0, 2.5, -3.0, 100.0, r.uniform(-50, 50)]))

    def draw(em, res):          # text console slot 0x184: cdecl(console, x, y, fmt, ...extras by format)
        fmt = em.arg32(3)
        n = _DRAW650[fmt]
        vals = [em.arg32(i) for i in range(4, 4 + n)]
        if fmt == 0x677368:      # the single extra is a C string: log the text it points to
            p = vals[0]
            vals = [bytes(em.rbytes(p, 0x80)).split(b'\0')[0].hex()]
        em.calllog.append(('draw', em.arg32(0), em.arg32(1), em.arg32(2), fmt) + tuple(vals))
        em.ret(eax=_w(c), argbytes=0)
    E = obj(c, 0x40, {0x184: c.emu.stub_fn('draw', draw)})
    K = obj(c, 0x20, {0xec: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 8, 16, 33, 200])),
                      0xf0: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 8, 16, 33, 200]))})
    so = sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=E)})
    e.w32(so + 0x190f, K)
    eqv = e.rbytes(0x6785d0, 4)
    e.wbytes(so + 0x9c3, eqv if r.random() < 0.5 else fl())
    e.wbytes(so + 0x58, fl())
    e.wbytes(0x725819, bytes([r.choice([0, 1])]))
    # the string formatter (sprintf into a stack buffer)
    def sprintf(em, res):
        dst, fmt, arg = em.arg32(0), em.arg32(1), em.arg32(2)
        txt = bytes(em.rbytes(arg, 0x20)).split(b'\0')[0]
        em.wbytes(dst, txt + b'\0')
        em.calllog.append(('sprintf', fmt, txt.hex()))
        em.ret(eax=len(txt), argbytes=0)
    c.emu.hook(0x42ac56, sprintf)
    recruits_util._HOOKED.add(0x42ac56)
    pool = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        n = rnd(c, 0x200)
        e.wbytes(n + 0x1dc, bytes([r.choice([0, 0, 1])]))
        e.w32(n + 0x1d8, r.choice([0, 1, 5, 120]))
        e.wbytes(n + 0x1c0, bytes(r.choice(b'abc DEF') for _ in range(r.randrange(0, 12))) + b'\0')
        pool.append(n)
    for n in pool:
        e.w32(n + 0x1d4, r.choice([0] + pool))
        e.w32(n + 0x1cc, r.choice([0] + pool))
    L = _Lst(c, pool)
    vt = e.r32(L.o)
    e.w32(vt + 0x14, pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, len(pool), 5])))
    this = rnd(c, 0x200)
    vt94 = e.alloc(0x40, 4)
    e.w32(vt94 + 0x18, pystub(c, 0, this=True, ret=lambda em, k: L.o if r.random() < 0.95 else 0))
    e.w32(vt94 + 0x8, pystub(c, 0, this=True, ret=lambda em, k: _w(c)))
    e.w32(this + 0x94, vt94)
    e.w32(this + 0x9c, r.choice([0, 1, 2, 3, 6]))
    return [this, r.choice([0, 1, 2, 5, 17, r.randrange(0, 40)])]


S(0x650430, 'GUESS lifted 0x650430', 'thiscall', None, ret='eax', gen=g650430h, note='batch240026')


def g482b80h(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seh_chain(c, r.choice([0, 1, 2]))
    mk = lambda v: 0x57ac0000 if STACK_LO <= v < STACK_HI else v

    def sr(em):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', mk(nxt), em.r32(a + 4), em.r32(a + 8)))

    fl = lambda: struct.pack('<f', r.choice([0.0, 1.0, 2.5, -3.0, 100.0, 640.0, r.uniform(-50, 50)]))
    flb = lambda n: b''.join(fl() for _ in range(n))

    def rec(name, nargs, pop, ret=None, fill=None, deref=None, this=True):
        """thiscall-style recorder: logs ecx (stack -> marker), the arguments (stack pointers: the bytes they point to after the call's
        fill, sizes from deref {index: bytes}), writes `fill(index) -> bytes` through the pointer arguments, returns ret()"""
        deref = deref or {}
        fill = fill or {}

        def h(em, res):
            for i, fn in fill.items():
                em.wbytes(em.arg32(i), fn())
            vals = []
            for i in range(nargs):
                v = em.arg32(i)
                if i in deref:
                    vals.append(bytes(em.rbytes(v, deref[i])).hex())
                else:
                    vals.append(mk(v))
            em.calllog.append((name, mk(em.reg('ecx')) if this else 0) + tuple(vals))
            sr(em)
            em.ret(eax=(ret() if ret else _w(c)), argbytes=pop)
        return h

    def stubfn(name, nargs, **kw):
        return e.stub_fn(name, rec(name, nargs, 4 * nargs, **kw))

    def hook(addr, name, nargs, **kw):
        c.emu.hook(addr, rec(name, nargs, 4 * nargs, **kw))
        recruits_util._HOOKED.add(addr)

    b = lambda p: (lambda em, k=None: 1 if r.random() < p else 0)
    rb = lambda p: (lambda: 1 if r.random() < p else 0)

    # objects of the engine
    iobj = obj(c, 0x20, {0x38: stubfn('key', 2, ret=rb(0.6))})
    # variadic member slot 0xdc of J: cdecl with ecx = this, the caller cleans; format decides the number of extras
    def v220(em, res):
        fmt = em.arg32(0)
        extra = 1 if fmt == 6865064 else 0
        txt = bytes(em.rbytes(em.arg32(1), 0x40)).split(b'\0')[0].hex() if extra else ''
        em.calllog.append(('fmt220', mk(em.reg('ecx')), fmt, txt))
        sr(em)
        em.ret(eax=r.choice([0, 6, 30, 100, 1000]), argbytes=0)
    P = obj(c, 0x20, {0x84: stubfn('P84', 1, deref={0: 12}), 0x28c: stubfn('P28c', 4, deref={0: 12}, ret=rb(0.75), fill={0: lambda: flb(8)})})
    U = obj(c, 0x20, {0x128: stubfn('U128', 1)})
    S = obj(c, 0x20, {0x25c: stubfn('S25c', 2, ret=lambda: U if r.random() < 0.7 else 0), 0x23c: stubfn('S23c', 6, deref={1: 12, 2: 12, 3: 12}),
                      0x238: stubfn('S238', 5, deref={0: 12, 1: 12, 2: 12}), 0x240: stubfn('S240', 1)})
    Rq = obj(c, 0x20, {})
    Q = obj(c, 0x20, {0x48: stubfn('Q48', 2, ret=lambda: Rq), 0x4c: stubfn('Q4c', 1)})
    G = rnd(c, 0x40)
    e.w32(G + 0x1c, Q)
    J = obj(c, 0x40, {0xb4: stubfn('J_b4', 1, ret=lambda: _w(c)), 0xdc: e.stub_fn('v220', v220)})
    T = obj(c, 0xb00, {0x58: stubfn('T58', 1, ret=lambda: P if r.random() < 0.8 else 0),
                       0x114: stubfn('T114', 6, ret=lambda: _w(c) & 0xffff)})
    e.w32(T + 0xadc, S)
    # console draw: cdecl(console, x, y)
    def draw(em, res):
        em.calllog.append(('draw', mk(em.arg32(0)), em.arg32(1), em.arg32(2)))
        sr(em)
        em.ret(eax=_w(c), argbytes=0)
    E = obj(c, 0x40, {0x184: e.stub_fn('draw', draw)})
    so = sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=E)})
    e.w32(so + 0x9b, T)
    e.w32(so + 0x1907, iobj)
    e.w32(so + 0x190f, J)
    e.w32(so + 0x1aa3, G)
    # ---- the manager object `this`
    strings = [b'', b'a', b'dir/file', b'/x', b'abc/def/ghi', b'no slash', b'0123456789']
    def item():
        return obj(c, 0x20, {0x1d8: stubfn('item1d8', 2, deref={0: 0}, fill={0: lambda: b'\0' * 4})})
    cnt = r.choice([0, 1, 2, 4, 6, 7])
    X = rnd(c, 0x80)
    e.wbytes(X + 0x1c, bytes([cnt]))
    for i in range(min(cnt, 25)):
        e.w32(X + 4 * i, item())
    Wnode = obj(c, 0x20, {})
    e.w32(Wnode + 8, rnd(c, 0x20))
    Wn2 = obj(c, 0x20, {})
    e.w32(Wn2 + 8, rnd(c, 0x20))
    esiobj = obj(c, 0x20, {0x88: stubfn('o88', 1, deref={0: 12}), 0x80: stubfn('o80', 2, deref={0: 12, 1: 12}, fill={0: lambda: flb(3), 1: lambda: flb(3)})})
    e.w32(esiobj + 8, rnd(c, 0x20))
    tflags = [r.random() < 0.5, r.random() < 0.5]
    this = obj(c, 0x700, {0x3fc: stubfn('t3fc', 1, ret=rb(0.5)), 0x580: stubfn('t580', 1), 0x20: pystub(c, 0, this=True, side=None, ret=lambda em, k: Wnode if k == 0 or r.random() < 0.5 else Wn2),
                          0x370: stubfn('t370', 2, deref={0: 48, 1: 12})})
    e.wbytes(this + 0x64a, bytes([r.choice([0, 1, 1])]))
    e.w32(this + 0x642, r.choice([0, 0, _w(c)]))
    # ---- hooked functions (exe code replaced)
    hook(0x4e1b60, 'c4e1b60', 0)
    hook(0x4de7a0, 'c4de7a0', 0, fill={}, ret=lambda: _w(c))

    def fillC(em, res):
        pass
    hook(0x484b10, 'c484b10', 5, deref={2: 12, 3: 12})
    hook(0x4ea300, 'c4ea300', 1)
    hook(0x4e9200, 'c4e9200', 3, deref={0: 48, 1: 12}, ret=rb(0.35))
    hook(0x4db550, 'c4db550', 0, ret=lambda: X)
    hook(0x4db3b0, 'c4db3b0', 0, ret=lambda: esiobj)
    hook(0x4daf90, 'c4daf90', 1, fill={0: lambda: flb(3)}, deref={0: 12})
    hook(0x441940, 'c441940', 0)
    hook(0x4db7c0, 'c4db7c0', 1, fill={0: lambda: flb(3)}, deref={0: 12})
    hook(0x4cc1d0, 'cstr', 0, ret=lambda: sbuf)
    hook(0x4cbec0, 'sdtor', 0)
    sbuf = rnd(c, 0x40)
    e.wbytes(sbuf, r.choice(strings) + b'\0')
    a = e.r32(0x676258)

    def strchr_(em, res):
        p = em.arg32(0)
        txt = bytes(em.rbytes(p, 0x40)).split(b'\0')[0]
        i = txt.find(bytes([em.arg32(1) & 0xff]))
        em.calllog.append(('strchr', txt.hex(), i))
        em.ret(eax=(p + i) if i >= 0 else 0, argbytes=0)
    e.stubs[a] = (e.stubs[a][0], strchr_)
    return [this]


S(0x482b80, 'GUESS lifted 0x482b80', 'thiscall', None, ret=None, gen=g482b80h, note='batch240027')


# ---------------------------------------------------------------- 0x61dcd0 (batch 240028, asm copy): cdecl (obj, strm, a3..a7), 55-way state switch
PTRRET = {0x61fb10, 0x620840, 0x61fd60, 0x61f5a0}
ZEROISH = {0x620910, 0x6211c0, 0x620890}


def g61dcd0h(c):
    clear_hooks(c)
    c.emu.mu.mem_write(pe_emu.HEAP_BASE, b'\0' * 0x80000)   # stale heap bytes from the previous (original) run must not be readable by out-of-range indices
    r = c.rng
    e = c.emu
    nm = lambda: r.choice([0, 1, 2, 3, 5, 8, 16, 32])

    def logh(name, nargs, retf):
        def h(em, res):
            em.calllog.append((name,) + tuple(em.arg32(i) for i in range(nargs)))
            em.ret(eax=retf(), argbytes=0)
        return h

    def bufret(nonnull=False):
        if not nonnull and r.random() < 0.15:
            return 0
        pb = rnd(c, 0x1000)
        e.wbytes(pb, small(0x400))
        return pb

    def nodeb():
        pb = rnd(c, 0x200)
        e.wbytes(pb, small(0x80))
        if r.random() < 0.6:
            e.w32(pb, e.r32(c.emu.reg('esp') + 8))   # the key (2nd argument)
        return pb

    def cbret():
        return r.choice([0, 0, 1, 1, 2, 4, 0xffffffff, 7, 100, r.randrange(0, 12)])

    def ext(addr, nargs, retf=None):
        c.emu.hook(addr, logh('x%x' % addr, nargs, retf or cbret))
        recruits_util._HOOKED.add(addr)

    def cb(name, nargs=9, retf=None):
        return e.stub_fn(name, logh(name, nargs, retf or cbret))

    small = lambda n: b''.join(struct.pack('<I', r.choice([0, 0, 0, 0, 1, 2, 3, 4, 6, 8, 12, 16, 32, r.randrange(0, 40), 0x28, 0x4f4e, 0x4e, 0x29])) for _ in range(n))
    # direct callees (cdecl): arities from the callers' cleanup
    for a, n in [(0x620910, 4), (0x620840, 4), (0x6204a0, 1), (0x61fd60, 3), (0x620120, 1), (0x61fb10, 4), (0x61f5a0, 4), (0x620320, 2),
                 (0x620180, 4), (0x61cd60, 6), (0x6206e0, 1), (0x6211c0, 6), (0x6218c0, 4), (0x620cb0, 4), (0x61dba0, 5), (0x61ffb0, 1),
                 (0x620890, 2), (0x61cb70, 1), (0x620c00, 4), (0x620d50, 4), (0x61d090, 6)]:
        ext(a, n, (lambda: 0 if r.random() < 0.85 else r.choice([1, 2, 5])) if a in ZEROISH else (lambda a=a: nodeb() if a == 0x61fd60 else ((lambda pb: (e.wbytes(pb, small(0x80)), pb)[1])(rnd(c, 0x200)) if r.random() < 0.6 else 0)) if a in PTRRET else None)
    esi = rnd(c, 0x400)
    e.wbytes(esi, small(0x100))   # all 0x400 bytes
    e.wbytes(esi, small(0x100))
    def mkstrm():
        st = rnd(c, 0x100)
        e.wbytes(st, small(0x40))
        for off in (0x30, 0x38):
            e.w32(st + off, cb('s%x' % off))
        e.w32(st, cb('s0'))
        pb = rnd(c, 0x1000); e.wbytes(pb, small(0x400)); e.w32(st + 0x44, pb)
        return st
    strm = mkstrm()
    other = mkstrm()
    # state-machine callback chooses the switch index
    e.w32(esi + 0x100, cb('sw', 9, lambda: r.choice([0xffffffff] + list(range(0, 54)) + [54, 60])))
    for off in (0x54, 0x58, 0x5c, 0x60, 0x6c, 0x70, 0x7c, 0x80, 0x84, 0x10, 0xc):
        e.w32(esi + off, cb('f%x' % off, 9, (lambda: bufret(off != 0xc)) if off in (0xc, 0x10) else None) if (off not in (0x5c, 0x60, 0x6c, 0x70, 0x7c, 0x80, 0x84) or r.random() < 0.8) else 0)
    e.w32(esi + 0x8c, strm if r.random() < 0.5 else other)
    for off in (0x124, 0x130, 0x140, 0x14c, 0x150, 0x1e8, 0x1fc, 0x238, 0x23c, 0x25c):
        pb = rnd(c, 0x1000); e.wbytes(pb, small(0x400)); e.w32(esi + off, pb)
    for off in (0x140, 0x23c):
        e.w32(e.r32(esi + off), r.choice([0x28, 0x4f4e, 0x41, 0x4e, 0x28]))
    if r.random() < 0.4:
        e.w32(esi + 0x1c4, 0)
        e.w32(esi + 0x26c, 0)
    p238 = e.r32(esi + 0x238)
    e.w32(esi + 0x234, p238 + r.choice([0, 1, 2, 3, 0x800]))
    if r.random() < 0.7:
        for k, off in enumerate((0x1b4, 0x1b8, 0x1bc)):
            e.w32(esi + off, r.randrange(100 * (k + 1), 100 * (k + 1) + 90))
    for off in (0x140, 0x130):
        if r.random() < 0.25:
            e.w32(esi + off, 0)
    e.w32(esi + 0x1c, 0)
    ebx = strm if r.random() < 0.6 else other
    return [esi, ebx, r.choice([0, 1, 2, 5, 100]), r.choice([0, 3, 7]), r.choice([-5, -4, -3, -2, -1, 0, 1, 2, 3, 11, 11, 12, 12, 13, 13, 14, 20, 28, 30, 42]) & 0xffffffff, r.choice([0, 1, 2, 4, 9]), r.choice([0, 1, 5, 11, 12, 13, 20, 30, 40]) if False else (rnd(c, 0x40) if r.random() < 0.6 else 0)]


S(0x61dcd0, 'asm copy 0x61dcd0', 'cdecl', None, ret='eax', gen=g61dcd0h, note='batch240028')
