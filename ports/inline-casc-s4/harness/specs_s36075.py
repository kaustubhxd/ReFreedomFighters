"""specs_s36075.py - cascade s4 batch 36075: 0x551d70 (query an object and pass the result back), 0x555a40 (compare two lookups and report), 0x56c950 (append two texts to a string)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g551d70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    recs = [rnd(c, 0x10) for _ in range(4)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 3)])
    hook_rec(c, 0x5002f0, 1, this=True)
    s = rnd(c, 0x20)
    mode = r.choice(['have', 'have', 'made', 'none'])
    x = obj(c, 0x20, {0x84: pystub(c, 1, this=True, deref={0: 6}, side=lambda em, k: em.w32(em.arg32(0), 0xabc000 + k))})
    if mode == 'have':
        e.w32(s + 0xc, x)
    else:
        e.w32(s + 0xc, 0)

        def side(em, k):
            if mode == 'made':
                em.w32(em.reg('ecx') + 0xc, x)
        hook_rec(c, 0x553d00, 0, this=True, side=side)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [s, p]


def _g555a40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5002f0, 1, this=True)
    v = r.choice([0, 5, 7])
    lvals = [r.choice([0, 5, 7, 9]), r.choice([0, 5, 7, 9])]
    cnt = [0]

    def s128(em, rr):
        k = cnt[0]
        cnt[0] += 1
        em.calllog.append(('s128', em.reg('ecx'), em.arg32(0), em.arg32(2)))
        em.w32(em.arg32(1), lvals[min(k, 1)])
        em.ret(0, 12)
    o = obj(c, 0x140, {0x128: e.stub_fn('s128', s128)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o),
                           0x114: pystub(c, 4, this=True, ret=lambda em, k: 0x12345678 * (k + 3) & 0xffffffff)})
    rec0 = rnd(c, 0x10)
    rec1 = rnd(c, 0x10)
    e.w32(rec1, v)
    recs = [rec0, rec1, rnd(c, 0x10)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 2)])
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [p]


def _g56c950(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    srcs = []
    for _ in range(2):
        t = bytes(r.randint(0x41, 0x5a) for _ in range(r.choice([0, 1, 3, 4, 5, 9]))) + b'\0'
        a = e.alloc(len(t) + 1, 4)
        e.wbytes(a, t)
        srcs.append(a)
    o = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=lambda em, k, _s=srcs: _s[min(k, 1)])})
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xae4, o)
    dest = e.alloc(0x100, 4)
    e.wbytes(dest, bytes([0x55]) * 0x100)
    ln = r.choice([0, 1, 2, 7, 30])
    e.wbytes(dest, bytes(r.randint(0x41, 0x5a) for _ in range(ln)) + b'\0')
    return [dest]


S(0x551d70, 'GUESS query an object and pass the result back', 'thiscall', None, ret=None, gen=_g551d70, note='batch36075')
S(0x555a40, 'GUESS compare two lookups and report', 'stdcall', None, ret=None, gen=_g555a40, note='batch36075')
S(0x56c950, 'GUESS append two texts to a string', 'stdcall', None, ret=None, gen=_g56c950, note='batch36075')
