"""specs_s91002.py - hard trial (fable 2) batch 91002: 0x46c1e0 item Init (zitem.cpp).
this = B (vtable slots 0x1d8 string temp ctor [writes an inline string into the caller's stack local, returns it], 0x210, 0x2fc, 0x350 -> w,
0x324, 0x394 (4 args -> object or 0 per call), 0x2d8, 0x364 -> int per call, 0, 0x2f0); B[8] -> object with flags at +0x3c (bit 10 = log);
B[0xd9] -> object whose slot 4 takes the handle; w slots 0x340 -> x (slot 0x338 -> e), 0x358, 0x364 -> element iterator (reftab 0x4c/0x5c)
or 0, 0x25c(name, 0) -> per-name object or 0, 0x328/0x324 bools, 0x368/0x36c -> e or 0, 0x370 -> li or 0; e slot 0x1e0 bool.
Table [eng+0x9b]: slots 0x58 (element -> template or 0), 0x4c (handle), 0x6c, 0x68; field +0xadc. Logger [0x700390]: slot 0x20 -> log
object whose cdecl slots 0x2c/0x30 log the format and the TEXT of the %s argument (a stack pointer) plus the extra ints.
Hooked: 0x456b70, 0x4dbe30, 0x4dc440, 0x4dc630, 0x46f240 (recorders), 0x633654 (cookie check)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab, _HOOKED


def _cstr(em, p, limit=0x100):
    s = b''
    while len(s) < limit:
        ch = em.rbytes(p, 1)
        if ch == b'\0':
            break
        s += ch
        p += 1
    return s


def _g46c1e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rets = [r.getrandbits(32) for _ in range(64)]
    cnt = [0]

    def nxt(em=None, k=None):
        v = rets[cnt[0] % len(rets)]
        cnt[0] += 1
        return v

    def boolret(em, k):
        return (nxt() & ~0xff) | r.choice([0, 1, 1, 0xff])
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'))
    texts = [bytes(r.randint(1, 255) for _ in range(r.choice([0, 1, 5, 30]))) for _ in range(3)]
    scnt = [0]

    def strctor(em, res):   # B->slot 0x1d8(&s, 1): inline string {data ptr -> s+4, text}
        s = em.arg32(0)
        k = scnt[0]
        scnt[0] += 1
        em.calllog.append(('strctor', em.reg('ecx'), 1 if s else 0, em.arg32(1)))
        em.w32(s, s + 4)
        em.wbytes(s + 4, texts[k % 3] + b'\0')
        em.ret(eax=s, argbytes=8)

    def logfn(em, res):   # cdecl (log, fmt, text, ...): the NOTIFY format 0x688ca4 carries two more ints
        a = [em.arg32(i) for i in range(5 if em.arg32(1) == 0x688ca4 else 3)]
        em.calllog.append(('log', 1 if a[0] else 0, a[1], _cstr(em, a[2])) + tuple(a[3:]))
        em.ret(eax=nxt(), argbytes=0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('log2c', logfn), 0x30: e.stub_fn('log30', logfn)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=lo)})
    e.w32(0x700390, lg)
    # objects hanging off the weapon data
    def eobj():
        return obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=boolret)})
    x = obj(c, 0x40, {0x338: pystub(c, 0, this=True, ret=r.choice([0, eobj(), eobj()]))})
    elems = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 3, 5]))]
    tmpls = {el: r.choice([0, rnd(c, 0x20), rnd(c, 0x20)]) for el in elems}
    it = r.choice([0, reftab(c, list(elems)), reftab(c, list(elems))])
    d = rnd(c, 0x40)
    pl = rnd(c, 0x20)
    e.w32(pl + 8, d)
    names = {0x688860: r.choice([0, rnd(c, 0x20), rnd(c, 0x20)]), 0x688cdc: r.choice([0, pl, pl]),
             0x688cec: r.choice([0, rnd(c, 0x20)]), 0x688cf4: r.choice([0, rnd(c, 0x20)])}
    w = obj(c, 0x40, {0x340: pystub(c, 1, this=True, ret=x), 0x358: pystub(c, 1, this=True, ret=nxt),
                      0x364: pystub(c, 0, this=True, ret=it),
                      0x25c: pystub(c, 2, this=True, ret=lambda em, k: names.get(em.arg32(0), 0)),
                      0x328: pystub(c, 0, this=True, ret=boolret), 0x324: pystub(c, 0, this=True, ret=boolret),
                      0x368: pystub(c, 0, this=True, ret=r.choice([0, eobj(), eobj()])),
                      0x36c: pystub(c, 0, this=True, ret=r.choice([0, eobj(), eobj()])),
                      0x370: pystub(c, 0, this=True, ret=r.choice([0, rnd(c, 0x20), rnd(c, 0x20)]))})
    # objects returned by B->slot 0x394 (spawned sub-items): {vtable slot 0x224, +8 -> q {+0x54 -> a or 0 {+0xc -> b {+0x23 flags}}}}
    def o394():
        if r.random() < 0.25:
            return 0
        b = rnd(c, 0x40)
        e.w32(b + 0x23, r.choice([0, 0x100000, 0x200002, r.getrandbits(32)]))
        a = rnd(c, 0x20)
        e.w32(a + 0xc, b)
        q = rnd(c, 0x80)
        e.w32(q + 0x54, r.choice([0, a, a]))
        o = obj(c, 0x20, {0x224: pystub(c, 1, this=True, ret=nxt)})
        e.w32(o + 8, q)
        return o
    objs = [o394() for _ in range(12)]
    nvals = [r.choice([0xffffffff, 0, 1, 5, 30, r.getrandbits(32)]) for _ in range(4)]
    pd = obj(c, 0x20, {4: pystub(c, 1, this=True, ret=nxt)})
    B = obj(c, 0x140, {0x1d8: e.stub_fn('strctor', strctor), 0x210: pystub(c, 1, this=True, ret=nxt),
                       0x2fc: pystub(c, 0, this=True, ret=nxt), 0x350: pystub(c, 0, this=True, ret=w),
                       0x324: pystub(c, 1, this=True, ret=nxt),
                       0x394: pystub(c, 4, this=True, ret=lambda em, k: objs[k % 12]),
                       0x2d8: pystub(c, 1, this=True, ret=nxt), 0x364: pystub(c, 0, this=True, ret=lambda em, k: nvals[k % 4]),
                       0: pystub(c, 0, this=True, ret=nxt), 0x2f0: pystub(c, 3, this=True, ret=nxt)})
    e.w32(B + 0x60, r.choice([0, 1, 1, 1, r.getrandbits(32)]))
    e.w32(B + 0xba, r.choice([0xffffffff, 0xffffffff, 0, 3, 10, r.getrandbits(32)]))
    e.w32(B + 0xd9, pd)
    q8 = rnd(c, 0x40)
    e.w32(q8 + 0x3c, r.choice([0, 0x400, 0xffffffff, r.getrandbits(32)]))
    e.w32(B + 8, q8)
    sysobj(c, slots={}, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: tmpls.get(em.arg32(0), 0)),
                                     0x4c: pystub(c, 1, this=True, ret=nxt), 0x6c: pystub(c, 0, this=True, ret=nxt),
                                     0x68: pystub(c, 0, this=True, ret=nxt)}, table_size=0xb00)
    hook_rec(c, 0x456b70, 2, this=True, ret=nxt)
    hook_rec(c, 0x4dbe30, 1, this=True, ret=nxt)
    hook_rec(c, 0x4dc440, 1, this=True, ret=nxt)
    hook_rec(c, 0x4dc630, 2, this=True, ret=nxt)
    hook_rec(c, 0x46f240, 0, this=True, ret=nxt)
    return [B]


S(0x46c1e0, 'GUESS ZItem::Init', 'thiscall', None, ret=None, gen=_g46c1e0, note='batch91002')
