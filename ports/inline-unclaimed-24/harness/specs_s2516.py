"""specs_s2516.py - decomp area 24, batch 2516.
0x536c70 (GUESS entity list update): thiscall(A, B), ret 8, no SEH. this+0x5306: embedded reftab (slots 0x4c, 0x5c, 0x44) whose vtable
pointer is stored at that address; A: reftab. B: object with slot 4 (1 arg recorder). System table (system+0x9b) slots 0x60 (id -> entity or 0)
and 0x58 (id -> placement holder or 0) are deterministic functions of the id. Entities are random heap objects with controlled kind (+8),
state (+4), flags (+0x40), slot index (+0x2c) and timing fields. this slots 0x40, 0x1dc, 0x78 (1 arg), 0x1e0 / 0x1e4 (1 arg, float on ST0).
0x44b610 / 0x44b740 (cdecl) / 0x44bc00 hooked. Logger at 0x700390 (slot 0x30, 3 args)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab_vt, logger


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, nargs=3, slot=0x30)

    def rl(n, f):
        v = [f() for _ in range(n)]
        return lambda em, k: v[k % n]

    ents = []
    for _ in range(4):
        en = rnd(c, 0x100)
        e.w32(en + 4, r.choice([0, 3, 7, 0xa, 0xb, 0xc, 0xc]))
        e.w32(en + 8, r.choice([4, 5, 8, 1, 2, 3]))
        e.w32(en + 0x0, r.choice([0, 0, r.getrandbits(32) | 1]))
        e.w32(en + 0x2c, r.randint(0, 3))
        e.w32(en + 0x3c, r.choice([0, 0, r.getrandbits(32) | 1, r.getrandbits(32) & ~3 | 4, r.getrandbits(32) | 1]))
        fl = r.choice([0, 0x80, 0x80, 0x40, 0x8, 0x2, 0x82, 0xc0, 0x88])
        e.w32(en + 0x40, fl | (r.getrandbits(8) << 8 if r.random() < 0.3 else 0))
        e.w32(en + 0x60, r.getrandbits(32))
        e.w32(en + 0x6c, r.randint(-50, 5000) & 0xffffffff)
        e.w32(en + 0x70, _fb(r.uniform(-5, 20)))
        e.w32(en + 0x78, _fb(r.choice([0.0, 1.0, 5.0, r.uniform(-3, 30)])))
        e.w32(en + 0x7c, r.getrandbits(32))
        e.wbytes(en + 0xec, bytes([r.choice([0, 1])]))
        ents.append(en)
    holders = []
    for _ in range(3):
        h = obj(c, 0x40, {0x84: pystub(c, 1, this=True, deref={0: 3}), 0x88: pystub(c, 1, this=True, deref={0: 3})})
        hold = rnd(c, 0x40)
        for i in range(12):
            e.w32(hold + 4 * i, _fb(r.uniform(-10, 10)))
        e.w32(h + 8, hold)
        holders.append(h)
    tgt = obj(c, 0x20, {0x84: pystub(c, 1, this=True, deref={0: 3}), 0x88: pystub(c, 1, this=True, deref={0: 3})})

    e.w32(tgt + 8, e.r32(holders[0] + 8))

    def ent_of(em, k):
        a = em.arg32(0)
        return ents[a % 4] if (a & 7) else 0

    def hold_of(em, k):
        a = em.arg32(0)
        if a & 3 == 0:
            return 0
        if a & 3 == 1:
            return tgt
        return holders[a % 3]
    sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=ent_of), 0x58: pystub(c, 1, this=True, ret=hold_of)})
    e.w32(0x70039c + 0, e.r32(0x70039c))
    so = e.r32(0x70039c)
    e.w32(so + 0x1c, r.choice([r.randint(0, 6000), r.getrandbits(32)]))
    e.w32(so + 0x20, _fb(r.uniform(-5, 20)))
    if r.random() < 0.5:
        # shared timing so the expiry comparisons hit their boundaries
        f78 = r.choice([1.0, 2.0, 5.0, 2.5])
        c6c = r.choice([r.randint(0, 3000), 3000000])
        d = r.choice([0.0, 0.0, 1e-4, 1e-5, 0.5])
        delta = r.choice([-1, 0, 0, 1, 5000000])
        e.w32(so + 0x20, _fb(10.0))
        e.w32(so + 0x1c, (c6c + int(1024 * f78) + delta) & 0xffffffff)
        for en in ents:
            e.w32(en + 0x78, _fb(f78))
            e.w32(en + 0x6c, c6c)
            e.w32(en + 0x70, _fb(10.0 + d))
            e.w32(en + 0x40, r.choice([0, 0, 0x2, 0x80, 0x82]))
            e.w32(en + 0x8, 1)
            e.w32(en + 0x3c, 0)
            e.w32(en + 0x0, 0)
            e.w32(en + 0x4, r.choice([3, 0xb, 0xa]))

    hook_rec(c, 0x44b610, 0, this=True)
    hook_rec(c, 0x44b740, 1, pop=0)
    hook_rec(c, 0x44bc00, 0, this=True, ret=rl(8, lambda: r.choice([0, 1, 1, 1])))

    fl_ = [_fb(r.choice([0.5, 1.0, 2.0, r.uniform(0.01, 5.0)])) for _ in range(6)]
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0x40, pystub(c, 1, this=True, ret=rl(8, lambda: r.getrandbits(32))))
    e.w32(vt + 0x78, pystub(c, 1, this=True, ret=rl(8, lambda: r.getrandbits(32))))
    e.w32(vt + 0x1dc, pystub(c, 1, this=True, ret=rl(8, lambda: r.getrandbits(32))))
    e.w32(vt + 0x1e0, pystub(c, 1, this=True, st0=1.0))
    e.w32(vt + 0x1e4, pystub(c, 1, this=True, st0=lambda em, k: struct.unpack('<f', struct.pack('<I', fl_[k % 6]))[0]))
    me = rnd(c, 0x5400)
    e.w32(me, vt)
    for i in range(4):
        e.wbytes(me + 0x515d + 9 * i, bytes([r.choice([0, 1])]))
    # embedded list
    ids1 = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 3]))]
    e.w32(me + 0x5306, reftab_vt(c, ids1))
    ids2 = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 4, 6]))]
    from recruits_util import reftab
    A = reftab(c, ids2) if r.random() < 0.95 else 0
    B = obj(c, 0x20, {4: pystub(c, 1, this=True)})
    return [me, A, B]


S(0x536c70, 'GUESS entity list update', 'thiscall', None, ret=None, gen=_gen, note='batch2516')
