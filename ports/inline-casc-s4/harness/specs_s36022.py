"""specs_s36022.py - cascade s4 batch 36022: 0x5331f0 (dump entries to the log), 0x536650 (resolve a record and dispatch), 0x537ed0 (write state and mark entries), 0x57a5c0 (key handler), 0x554bf0 (bind a record to an engine id)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g5331f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def pf(em, rr):
        a = [em.arg32(i) for i in range(5)]
        if a[1] == 0x6a18dc:
            em.calllog.append(('log', a[0], a[1], a[2], a[3], a[4]))
        else:
            em.calllog.append(('log', a[0], a[1]))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('printf', pf)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)}))
    n = r.choice([0, 1, 2, 3, 0xffffffff])
    recs = []
    for i in range(3):
        rc = rnd(c, 0x100)
        recs.append(rc)
    E = obj(c, 0x5500, {0x248: pystub(c, 1, this=True, ret=lambda em, k: recs[min(k, 2)])}) if False else None
    vt = e.r32(obj(c, 0x10, {0x248: pystub(c, 1, this=True, ret=lambda em, k: recs[min(k, 2)])}))
    E = e.alloc(0x5500, 4)
    e.w32(E, vt)
    e.w32(E + 0x546e, n)
    return [E]


def _g536650(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def l30(em, rr):
        em.calllog.append(('l30', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x40, {0x30: e.stub_fn('l30', l30)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)}))
    base = e.alloc(0x100, 4)
    off = r.choice([0, 0x10, 0x20, 0x30])
    e.w32(base + off, r.choice([3, 3, 3, 2, 0]))
    me = obj(c, 0x5400, {0x1c0: pystub(c, 1, this=True, ret=r.getrandbits(32)), 0x1c4: pystub(c, 3, this=True, ret=r.getrandbits(32))})
    e.wbytes(me + 0x5302, (0 if r.random() < 0.15 else base).to_bytes(4, 'little'))
    bs = rnd(c, 0x10)
    e.wbytes(bs, bytes([r.choice([0, 0, 0x41, 0x61])]))
    b = 0 if r.random() < 0.1 else bs
    return [me, 0 if r.random() < 0.1 else off, b]


def _g537ed0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x53aae0, 1, this=True)
    hook_rec(c, 0x534150, 0, this=True)
    hook_rec(c, 0x534220, 1, this=True)
    s = obj(c, 0x20, {0xc: pystub(c, 1, this=True), 0x70: pystub(c, 1, this=True)})
    n = r.choice([0, 1, 2, 3])
    locs = [1] * n + [0]
    rets = [r.getrandbits(32) for _ in range(5)]
    ents = []
    for i in range(n):
        en = 0 if r.random() < 0.2 else rnd(c, 0x20)
        if en:
            e.w32(en + 4, r.choice([1, 1, 5, 2, 0]))
        ents.append(en)

    def side(em, k):
        em.w32(em.arg32(0), locs[min(k, len(locs) - 1)])
    sub_vt = e.r32(obj(c, 0x10, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                                 0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: rets[min(k, 4)], side=side)}))
    sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=lambda em, k: ents[min(k, len(ents) - 1)] if ents else 0)})
    E = e.alloc(0x5500, 4)
    _w32(c, E + 0x53b2, sub_vt)
    e.wbytes(E + 0x52fa, (0 if r.random() < 0.3 else rnd(c, 0x10)).to_bytes(4, 'little'))
    return [E, s]


def _g57a5c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ax = r.getrandbits(32)
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=ax)})
    hook_rec(c, 0x561cb0, 2, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x563500, 0, this=True)
    hook_rec(c, 0x57aaf0, 0, this=True)
    g = rnd(c, 0x80)
    e.w32(0x7003a0, g)
    x = obj(c, 0x20, {0x300: pystub(c, 0, this=True)})
    me = obj(c, 0x300, {0x84: pystub(c, 0, this=True, ret=x)})
    a = e.alloc(0x1060, 4)
    e.wbytes(a + 0x103f, bytes([r.choice([0, 1, 0xff])]))
    e.w32(me + 0x94, 0 if r.random() < 0.2 else a)
    i = r.randint(0, 5)
    e.wbytes(me + 0x194, bytes(r.choice([0, 0, 1]) for _ in range(4)))
    e.wbytes(me + 0x193 + i, bytes([r.choice([0, 1, 1])]))
    p = e.alloc(0x10, 4)
    e.w32(p, i)
    m = r.random()
    code = (r.getrandbits(16) << 16 | (ax & 0xffff)) if m < 0.75 else r.getrandbits(32)
    return [me, code, p]


def _g554bf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec0, rec1, rec2 = rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (rec0, rec1, rec2)[min(k, 2)])
    hook_rec(c, 0x5002f0, 1, this=True)
    hook_rec(c, 0x506040, 0, this=True)

    def s88(em, rr):
        em.w32(em.arg32(1), r.getrandbits(32))
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=0, argbytes=8)

    def s114(em, rr):
        em.w32(em.arg32(4), r.getrandbits(32))
        em.calllog.append(('s114', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(5)))
        em.ret(eax=r.getrandbits(32), argbytes=24)
    x = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    ob = 0 if r.random() < 0.2 else obj(c, 0x20, {0x128: pystub(c, 1, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=x), 0x58: pystub(c, 1, this=True, ret=ob), 0x114: e.stub_fn('s114', s114)})
    a = rnd(c, 0x20)
    return [a]


S(0x5331f0, 'GUESS dump entries to the log', 'thiscall', None, ret=None, gen=_g5331f0, note='batch36022')
S(0x536650, 'GUESS resolve record and dispatch by text', 'thiscall', None, ret='eax', gen=_g536650, note='batch36022')
S(0x537ed0, 'GUESS write state and mark entries', 'thiscall', None, ret='al', gen=_g537ed0, note='batch36022')
S(0x57a5c0, 'GUESS key handler with state clear', 'thiscall', None, ret='eax', gen=_g57a5c0, note='batch36022')
S(0x554bf0, 'GUESS bind record to engine id (B)', 'stdcall', None, ret=None, gen=_g554bf0, note='batch36022')
