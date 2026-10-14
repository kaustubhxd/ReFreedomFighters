"""specs_s36012.py - cascade s4 batch 36012: 0x4db860 (toggle flag state with helper calls), 0x4f4160 (load tables from a resource block), 0x5601c0 (nine slot calls guarded by a byte), 0x56f0c0 (dispatch on engine id)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4db860(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    flag = r.choice([0, 1, 0x100, 0x101, 0xff, r.getrandbits(32)])
    q = 0 if r.random() < 0.35 else obj(c, 0x20, {0x320: pystub(c, 1, this=True)})
    for a, n in ((0x4da770, 1), (0x4dae60, 0), (0x4d9bf0, 0), (0x4d9ce0, 0), (0x4d9d20, 1)):
        hook_rec(c, a, n, this=True)
    hook_rec(c, 0x4daff0, 0, this=True, ret=q)
    me = rnd(c, 0x80)
    bits = (0x800 if r.random() < 0.5 else 0) | (0x40000 if r.random() < 0.6 else 0) | (r.choice([0, 0x400, 0x200000, 0x1]) if r.random() < 0.4 else 0)
    f = (r.getrandbits(32) & ~(0x800 | 0x40000 | 0x200c00 | 0xff)) | bits | (r.choice([0, 0, 1, 0x80]) if r.random() < 0.6 else 0)
    e.w32(me + 0x3c, f)
    nf = [(r.getrandbits(32) & ~(0x800 | 0x40000 | 0x200c00)) | (0x800 if r.random() < 0.5 else 0) | (0x40000 if r.random() < 0.6 else 0)
          | (r.choice([0, 0x400, 0x200000]) if r.random() < 0.4 else 0) for _ in range(2)]

    def side(em, k):
        em.w32(em.reg('ecx') + 0x3c, nf[min(k, 1)])
    hook_rec(c, 0x4dc630, 2, this=True, side=side)
    e.w32(me + 0x64, 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    ctx = rnd(c, 0x20)
    p = rnd(c, 0x70)
    e.w32(p + 0x54, ctx)
    e.w32(me + 0x50, p)
    return [me, flag]


def _g4f4160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = r.choice([0, 1, 2])
    q = r.choice([0, 1, 2, 3])
    P = e.alloc(0x300, 4)
    e.wbytes(P, bytes(r.getrandbits(8) for _ in range(0x300)))
    e.w32(P, cnt)
    Q = P + 4 + cnt * 40
    e.w32(Q, q)
    for i in range(q):
        e.w32(Q + 4 + 4 * q + 8 * i + 4, r.choice([0, 1, 2, 3, r.randint(0, 5)]))
    holder = obj(c, 0x20, {0xc: pystub(c, 1, this=True, ret=P)})
    o = rnd(c, 0x30)
    e.w32(o + 0x18, holder)
    so = sysobj(c)
    e.wbytes(so + 0x1aa3, o.to_bytes(4, 'little'))
    hook_rec(c, 0x4ef660, 1, this=True)

    def side(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x4e12e0, 2, this=True, side=side, stackmark=(0,))
    hook_rec(c, 0x4e1b30, 0, this=True)
    me = obj(c, 0x100, {0x228: pystub(c, 0, this=True), 0x244: pystub(c, 0, this=True)})
    return [me, rnd(c, 0x20)]


def _g5601c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = rnd(c, 0x20)
    stop = r.choice([-1, 0, 1, 3, 7, 8])
    e.wbytes(a + 0xc, bytes([r.choice([1, 1, 2, 0xff]) if r.random() > 0.15 else 0]))

    def side(em, k):
        if k == stop:
            em.wbytes(a + 0xc, bytes([0]))
    me = obj(c, 0x20, {0x48: pystub(c, 1, this=True, side=side)})
    return [me, a]


def _g56f0c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    r1, r2 = r.getrandbits(32), r.getrandbits(32)
    hook_rec(c, 0x561cb0, 2, this=True, ret=r.getrandbits(32))
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: (r1, r2)[min(k, 1)])})
    m = r.random()
    hi = r.getrandbits(16) << 16
    code = hi | (r1 & 0xffff) if m < 0.35 else (hi | (r2 & 0xffff) if m < 0.7 else r.getrandbits(32))
    if m >= 0.35 and m < 0.5 and (r1 & 0xffff) == (r2 & 0xffff):
        code ^= 1
    p = rnd(c, 0x10)
    e.w32(p, r.choice([6, 6, 0, 5, 9, 0xff, r.getrandbits(32)]))
    me = e.alloc(0x500, 4)
    e.wbytes(me + 0x1e0, bytes(r.getrandbits(8) for _ in range(0x20)))
    e.wbytes(me + 0x4b0, bytes(r.getrandbits(8) for _ in range(0x10)))
    return [me, code, p]


S(0x4db860, 'GUESS toggle flag state via helpers', 'thiscall', None, ret=None, gen=_g4db860, note='batch36012')
S(0x4f4160, 'GUESS load tables from resource block', 'thiscall', None, ret=None, gen=_g4f4160, note='batch36012')
S(0x5601c0, 'GUESS nine slot calls while flag set', 'thiscall', None, ret=None, gen=_g5601c0, note='batch36012')
S(0x56f0c0, 'GUESS dispatch on engine id', 'thiscall', None, ret='eax', gen=_g56f0c0, note='batch36012')
