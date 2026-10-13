"""specs_s2515.py - decomp area 24, batch 2515.
0x4b2470 (GUESS per-element property application): thiscall(arg), ret 4, SEH frame. arg+0x18: reftab (slots 0x4c, 0x5c) over random ids.
Lookup table at system+0x9b (slots 0x54, 0x58, 0x50; results are deterministic functions of the id). Hooked callees: 0x4dc110, 0x4b4990 (3
args), 0x4b48c0, 0x4b7f90, 0x4cc1d0, 0x4cbec0 (this = stack local, marker), 0x4db9a0, 0x4cc7f0 (fastcall: EDX logged), 0x4b7940.
Slot 0x130 of the object at this+0x44 fills the record pointer at loc+4. IAT 0x67625c (string compare) is a stub. Logger at 0x700390."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab, logger


def _fbits(r):
    k = r.random()
    if k < 0.1:
        return 0
    if k < 0.2:
        return 0x7f800000
    if k < 0.3:
        return struct.unpack('<I', struct.pack('<f', r.uniform(-1e10, 1e10)))[0]
    return struct.unpack('<I', struct.pack('<f', r.uniform(-100, 100)))[0]


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, nargs=4)

    def rl(n, f):
        v = [f() for _ in range(n)]
        return lambda em, k: v[k % n]

    strs = [rnd(c, 0x20) for _ in range(3)]
    strobj = rnd(c, 0x40)

    def cmp_stub(em, rr):
        em.calllog.append(('cmp', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0 if r.random() < 0.75 else 1, argbytes=0)
    e.w32(0x67625c, e.stub_fn('cmp', cmp_stub))

    # target objects (the sys-table lookup results)
    X = obj(c, 0x80, {0x128: pystub(c, 3, this=True)})
    kids = []
    prev = 0
    for _ in range(r.choice([0, 1, 2, 3])):
        ch = rnd(c, 0x80)
        e.w32(ch + 0x60, prev)
        prev = ch
        kids.append(ch)
    e.w32(X + 0x50, prev)
    targets = []
    for _ in range(3):
        t = rnd(c, 0x80)
        q = rnd(c, 0x80)
        e.w32(t + 0x50, q)
        e.w32(t + 0x54, X if r.random() < 0.8 else 0)
        targets.append(t)
    # kids' own objects are used only as `this` of hooks
    pool = [(r.getrandbits(32) | 1) for _ in range(6)]
    pool = [p if p & 7 else p | 1 for p in pool]
    o_str = obj(c, 0x40, {0x2c4: pystub(c, 2, this=True, ret=r.getrandbits(32))})

    def tgt(em, k):
        a = em.arg32(0)
        return targets[a % 3] if (a & 7) else 0

    def tgt_nz(em, k):
        return targets[em.arg32(0) % 3]

    st_slots = {0x54: pystub(c, 1, this=True, ret=tgt), 0x58: pystub(c, 1, this=True, ret=o_str),
                0x50: pystub(c, 1, this=True, ret=tgt_nz)}
    sysobj(c, table_slots=st_slots)

    hook_rec(c, 0x4dc110, 0, this=True, ret=rl(8, lambda: r.choice(strs)))
    hook_rec(c, 0x4b4990, 3, this=True, ret=rl(8, lambda: r.choice(pool) if r.random() < 0.9 else 0))
    esis = []
    for _ in range(2):
        esis.append(obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1])),
                                  0x54c: pystub(c, 2, this=True),
                                  0x1d8: pystub(c, 2, this=True, nullflag=(0,), ret=strobj),
                                  0x224: pystub(c, 4, this=True), 0x22c: pystub(c, 2, this=True),
                                  0x32c: pystub(c, 1, this=True)}))
    hook_rec(c, 0x4b48c0, 1, this=True, ret=rl(8, lambda: r.choice(esis) if r.random() < 0.85 else 0))
    hook_rec(c, 0x4b7f90, 2, this=True)
    hook_rec(c, 0x4cc1d0, 0, this=True, ret=rl(8, lambda: r.choice(strs)))
    hook_rec(c, 0x4cbec0, 0, this='mark')
    hook_rec(c, 0x4db9a0, 1, this=True, ret=rl(10, lambda: r.choice([0, 1, 0x100, 1])))

    def edx_log(em, k):
        em.calllog.append(('edx', 0, 0, (em.reg('edx'),)))
    hook_rec(c, 0x4cc7f0, 0, this=True, ret=rl(8, lambda: r.choice([0, 1, 1])), side=edx_log)
    hook_rec(c, 0x4b7940, 1, this=True)

    recs = []
    for _ in range(3):
        b = rnd(c, 0x40)
        e.wbytes(b + 4, bytes([r.choice([0, 1, 7])]))
        e.w32(b + 9, r.choice([0, 0, r.getrandbits(32)]))
        e.w32(b + 0x11, _fbits(r))
        e.w32(b + 0x15, _fbits(r))
        e.wbytes(b + 0x1a, bytes([r.choice([0, 1, 5])]))
        e.wbytes(b + 0x1d, bytes([r.choice([0, 1, 9])]))
        recs.append(b)

    def w130(em, k):
        loc = em.arg32(2)
        em.w32(loc + 4, r.choice(recs) if r.random() < 0.88 else 0)
    o44 = obj(c, 0x40, {0x130: pystub(c, 3, this=True, deref={2: 2}, side=w130),
                        0x1d8: pystub(c, 2, this=True, nullflag=(0,), ret=strobj)})
    me = rnd(c, 0x100)
    e.w32(me + 0x44, o44)
    arg = rnd(c, 0x40)
    ids = [(r.getrandbits(32)) for _ in range(r.choice([0, 1, 2, 4]))]
    tbl = reftab(c, ids)
    e.w32(arg + 0x18, tbl if r.random() < 0.95 else 0)
    return [me, arg]


S(0x4b2470, 'GUESS per-element property application (SEH frame)', 'thiscall', None, ret=None, gen=_gen, note='batch2515')
