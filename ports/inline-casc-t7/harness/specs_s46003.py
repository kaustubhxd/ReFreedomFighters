"""specs_s46003.py - cascade t7 batch 46003: 0x53b8d0 slot-record list builder. Real exe code runs for 0x53b860, 0x53b7f0 and 0x53c1f0; hooked: 0x53bfd0, 0x53c5b0 (writes
a record from one of two patterns), 0x4db3b0. Iterator object (slots 0x4c, 0x5c, 0x44) walks a short item list; table object (+0x9b) slots 0x60 (key -> s object) and 0x58."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g53b8d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    N = 12

    def lst(f, n=N):
        return [f() for _ in range(n)]
    nitems = r.choice([0, 1, 2, 3, 3, 4, 6])
    pat = []
    for _ in range(2):
        cntp = r.choice([0, 1, 2, 3, 3, 5, 7])
        data = bytes(r.getrandbits(8) for _ in range(0x89))
        pat.append((cntp, data))
    pick = lst(lambda: r.choice([0, 0, 1]))
    ok53c5 = lst(lambda: r.choice([1, 1, 1, 0, 0x100, 3]))
    fail_budget = [0]

    # ---- items, objects
    a1 = obj(c, 0x200, {0x350: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 0x55, r.getrandbits(32)]))})
    e.w32(a1 + 0x94, r.getrandbits(32))
    o2 = obj(c, 0x200, {0x350: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0x66, r.getrandbits(32)]))})
    e.w32(o2 + 0x94, r.getrandbits(32))
    keys = [r.choice([1, 2, 3, 0x10, 0x20, 0x30]) for _ in range(nitems)]
    sobjs = {}
    for k in set(keys):
        if r.random() < 0.12:
            sobjs[k] = 0
            continue
        s = rnd(c, 0x200)
        e.w32(s + 0x3c, r.choice([0, 7, 7, 7, 9]))
        e.w32(s + 0x40, r.choice([0, 1, 4, 5, 0x20, 0x21, 0x25, r.getrandbits(32) & 0x25]))
        e.w32(s + 0x30, r.choice([0, 0x80000000, 1, 2, 3]))
        sobjs[k] = s
    pobj = [rnd(c, 0x20) for _ in range(3)]
    p0 = [a1, a1, o2, pobj[0], pobj[1], 0]
    ret58 = lst(lambda: r.choice(p0 + [a1]))
    ret4db = lst(lambda: r.choice([a1, o2, o2, o2]))

    state = {'pos': 0}

    def s4c(em, k):
        state['pos'] = 0
        em.w32(em.arg32(0), 1 if nitems > 0 else 0)

    def s5c(em, k):
        em.w32(em.arg32(0), 1 if state['pos'] < nitems else 0)

    def r5c(em, k):
        return keys[min(state['pos'], nitems - 1)] if nitems else 0

    def s44(em, k):
        state['pos'] += 1
    it = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, stackmark=(0,), side=s4c),
                       0x5c: pystub(c, 1, this=True, stackmark=(0,), side=s5c, ret=r5c),
                       0x44: pystub(c, 1, this=True, stackmark=(0,), side=s44)}) if r.random() < 0.93 else 0
    sink = obj(c, 0x20, {0x4: pystub(c, 1, this=True)})

    # ---- engine
    o_l = obj(c, 0x20, {0x84: pystub(c, 1, this=True, stackmark=(0,))})
    lq = obj(c, 0x1200, {0xc0: pystub(c, 0, this=True, ret=o_l)})
    e.wbytes(lq + 0x86, bytes([r.choice([0, 1])]))
    for j in range(1, 8):
        e.w32(lq + 0x109f + 8 * j, r.choice([0, 0x10, 0x20, 0x30, r.getrandbits(32)]))
        e.w32(lq + 0x109f + 8 * j + 4, r.choice([0, 0x80000000, j, j]) if j < 7 else 0)
    cnt58 = [0]

    def t60(em, k):
        return sobjs.get(em.arg32(0), 0)
    sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=t60),
                           0x58: pystub(c, 1, this=True, ret=lambda em, k: ret58[min(k, N - 1)])}, table_size=0xb00)
    so = e.r32(0x70039c)
    e.w32(so + 0x1a9f, lq)
    tb = e.r32(so + 0x9b)
    e.w32(tb + 0xadc, a1 if r.random() < 0.4 else r.getrandbits(32))

    # ---- hooks
    hook_rec(c, 0x4db3b0, 0, this=True, ret=lambda em, k: ret4db[min(k, N - 1)])

    def s53bf(em, k):
        em.calllog.append(('l10', em.r32(em.arg32(1)), em.r32(em.arg32(1) + 4), em.r32(em.arg32(1) + 8)))
        em.w32(em.arg32(2), r.getrandbits(32))
        em.w32(em.arg32(3), r.getrandbits(32))
    wr = [(r.getrandbits(32), r.getrandbits(32)) for _ in range(N)]

    def s53bf2(em, k):
        em.calllog.append(('l10', em.r32(em.arg32(1)), em.r32(em.arg32(1) + 4), em.r32(em.arg32(1) + 8)))
        em.w32(em.arg32(2), wr[min(k, N - 1)][0])
        em.w32(em.arg32(3), wr[min(k, N - 1)][1])
    ret53bf = lst(lambda: r.choice([0, 1, 1, 0x100, 0x55]))
    hook_rec(c, 0x53bfd0, 4, this=True, stackmark=(1,), ret=lambda em, k: ret53bf[min(k, N - 1)], side=s53bf2)

    def s53c5(em, k):
        cn, data = pat[pick[min(k, N - 1)]]
        em.w32(em.arg32(2), cn)
        em.wbytes(em.arg32(3), data)
        em.w32(em.arg32(4), 0)
    calls = [0]

    def r53c5(em, k):
        v = ok53c5[min(k, N - 1)]
        if k >= 2:
            return 1
        return v
    hook_rec(c, 0x53c5b0, 6, this=True, stackmark=(2, 3, 4, 5), ret=r53c5, side=s53c5)

    # ---- this
    sub = obj(c, 0x20, {0xc: pystub(c, 0, this=True), 0x4: pystub(c, 1, this=True)})
    me = rnd(c, 0x1300)
    e.w32(me + 0x19, e.r32(sub))
    n = r.choice([0, 1, 2, 3, 4])
    e.w32(me + 0xc5, n if r.random() > 0.05 else 0xffffffff)
    for i in range(n):
        base = me + 0xc9 + 0x89 * i
        if r.random() < 0.5:
            cn, data = pat[r.choice([0, 1])]
            e.wbytes(base, data)
            e.w32(base + 0x25, cn)
    e.w32(me + 0x11f5, r.choice([0, 1, 1, 1, 0x100]))
    e.wbytes(me + 0x1209, bytes([r.choice([0, 0, 0, 1])]))
    return [me, a1, it, sink]


S(0x53b8d0, 'GUESS slot-record list builder', 'thiscall', None, ret=None, gen=g53b8d0, note='batch46003')
