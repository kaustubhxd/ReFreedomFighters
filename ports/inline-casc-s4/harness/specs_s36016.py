"""specs_s36016.py - cascade s4 batch 36016: 0x50f060 (bind record to engine object), 0x535ac0 (release matching entries), 0x564a40 (broadcast a visibility flag), 0x579bd0 (format and dispatch), 0x57aaf0 (build a suffix string)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _cstr(em, p, limit=0x200):
    s = b''
    while len(s) < limit:
        ch = em.rbytes(p, 1)
        if ch == b'\0':
            break
        s += ch
        p += 1
    return s


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g50f060(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert(c)
    logger(c, 3)
    rec1 = rnd(c, 0x10)
    rec2 = rnd(c, 0x10)
    e.wbytes(rec2 + 4, bytes([r.choice([0, 1, 2, 5, 0xff])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec1, rec2)[min(k, 1)])
    hook_rec(c, 0x5002f0, 1, this=True)
    hook_rec(c, 0x4db2f0, 1, this=True, ret=r.getrandbits(32))
    o = 0 if r.random() < 0.25 else rnd(c, 0x20)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o), 0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    a = rnd(c, 0x20)
    return [a]


def _g535ac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    n = r.choice([0, 1, 2, 3])
    locs = [1] * n + [0]
    rets = [r.getrandbits(32) for _ in range(5)]
    a = r.choice([0xffffffff, 7, r.getrandbits(32)])
    ss = []
    for i in range(n):
        s = 0 if r.random() < 0.2 else rnd(c, 0x40)
        if s:
            e.w32(s + 0x2c, a if r.random() < 0.5 else r.getrandbits(32))
        ss.append(s)

    def side(em, k):
        em.w32(em.arg32(0), locs[min(k, len(locs) - 1)])
    sub_vt = e.r32(obj(c, 0x10, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                                 0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: rets[min(k, 4)], side=side)}))
    E = e.alloc(0x5400, 4)
    _w32(c, E + 0x53b2, sub_vt)
    sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=lambda em, k: ss[min(k, len(ss) - 1)] if ss else 0)})
    hook_rec(c, 0x44b610, 0, this=True)
    hook_rec(c, 0x44b740, 1, pop=0)
    return [E, a]


def _g564a40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def boolstub(tag):
        # the bool argument is pushed as a whole register in the exe (upper bytes are junk); only the low byte is compared
        def h(em, rr):
            em.calllog.append((tag, em.reg('ecx'), em.arg32(0) & 0xff))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn(tag, h)

    def h610(em, rr):
        em.calllog.append(('610100', em.reg('ecx'), em.arg32(0) & 0xff))
        em.ret(eax=0, argbytes=4)
    e.hook(0x610100, h610)
    st = pystub(c, 1, this=True)
    E = e.alloc(0xc90, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x20)))
    for off in (0xc62, 0xc6a, 0xc6e, 0xc72, 0xc76, 0xc7a):
        _w32(c, E + off, obj(c, 0x10, {0xbc: boolstub('bool%x' % off)}))
    _w32(c, E + 0xc66, obj(c, 0x10, {0xbc: st}))
    e.w32(E + 0x5c, 0 if r.random() < 0.3 else obj(c, 0x10, {0xbc: st}))
    q = 0 if r.random() < 0.3 else obj(c, 0x10, {0xbc: st})
    p = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=q)})
    _w32(c, E + 0xc7e, 0 if r.random() < 0.2 else p)
    return [E, r.choice([0, 1, 0x100, 0x101, 0xff, r.getrandbits(32)])]


def _g579bd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def sprintf(em, res):
        a = [em.arg32(i) for i in range(4)]
        s = bytes(r.randint(1, 255) for _ in range(r.choice([0, 3, 20, 0x3e]))) + b'\0'
        em.wbytes(a[1], s)
        em.calllog.append(('fmt', a[0], a[2], a[3]))
        em.ret(eax=len(s) - 1, argbytes=0)

    def z68(em, res):
        em.calllog.append(('z68', _cstr(em, em.arg32(0)), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    y = obj(c, 0x20, {0x198: e.stub_fn('sprintf', sprintf)})
    z = obj(c, 0x20, {0x68: e.stub_fn('z68', z68)})
    w = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)})
    sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=y), 0xbc: pystub(c, 0, this=True, ret=w)},
           table_slots={0x134: pystub(c, 0, this=True, ret=z)})
    i = r.randint(0, 3)
    tbl = e.alloc(0x2c90, 4)
    _w32(c, tbl + i * 4 + 0x2c3d, 0 if r.random() < 0.3 else r.getrandbits(32) | 1)
    e.w32(0x7003b8, tbl)
    cc = obj(c, 0x20, {0x130: pystub(c, 3, this=True, deref={2: 1})})
    E = e.alloc(0x200, 4)
    e.wbytes(E + 0x194, i.to_bytes(4, 'little'))
    e.wbytes(E + 0x198, r.getrandbits(16).to_bytes(2, 'little'))
    e.w32(E + 0x44, cc)
    return [E, r.getrandbits(32)]


def _g57aaf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def s284(em, res):
        em.calllog.append(('s284', _cstr(em, em.arg32(0))))
        em.ret(eax=0, argbytes=4)
    cc = obj(c, 0x20, {0x284: e.stub_fn('s284', s284)})
    E = e.alloc(0x200, 4)
    e.wbytes(E + 0x194, bytes(r.choice([0, 0, 1, 0xff]) for _ in range(4)) + bytes([r.getrandbits(8)]))
    e.w32(E + 0x180, cc)
    return [E]


S(0x50f060, 'GUESS bind record to engine object', 'stdcall', None, ret=None, gen=_g50f060, note='batch36016')
S(0x535ac0, 'GUESS release matching entries', 'thiscall', None, ret=None, gen=_g535ac0, note='batch36016')
S(0x564a40, 'GUESS broadcast a visibility flag', 'thiscall', None, ret=None, gen=_g564a40, note='batch36016')
S(0x579bd0, 'GUESS format and dispatch a message', 'thiscall', None, ret=None, gen=_g579bd0, note='batch36016')
S(0x57aaf0, 'GUESS build suffix string and send', 'thiscall', None, ret=None, gen=_g57aaf0, note='batch36016')
