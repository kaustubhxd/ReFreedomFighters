"""specs_s36035.py - cascade s4 batch 36035: 0x606120 (MD5 finalize), 0x616000 / 0x63f8a0 (pool slot release with record 0x30 / 0x4c), 0x638d60 (indexed rows to dwords), 0x639df0 (pack channels)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g606120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x606940, 2, this=True, deref={0: -8})
    ctx = rnd(c, 0x60)
    n = r.choice([0, 1, 0x30, 0x37, 0x38, 0x39, 0x3f, r.randint(0, 0x3f)])
    low = r.getrandbits(3)
    hi = r.getrandbits(23) << 9
    e.w32(ctx + 0x10, hi | (n << 3) | low)
    out = rnd(c, 0x20)
    return [ctx, out]


def _pool(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blocks = [rnd(c, 0x20) for _ in range(3)]
    p = rnd(c, 0x20)
    rnd(c, r.randint(0, 0x300))
    b = rnd(c, 0x20)
    if r.random() < 0.5:
        p, b = b, p
    e.wbytes(b, bytes([r.choice([1, 1, 2, 3, 0])]))
    other = blocks[0]
    a = b if r.random() < 0.2 else blocks[1]
    d = b if r.random() < 0.2 else blocks[2]
    e.w32(b + 8, a)
    e.w32(b + 0xc, d)
    head = b if r.random() < 0.3 else other
    e.w32(other + 0xc, blocks[1] if r.random() < 0.5 else blocks[2])
    E = obj(c, 0x20, {0x2c: pystub(c, 1, this=True, ret=b), 0x34: pystub(c, 1, this=True)})
    e.w32(E + 8, head)
    e.w32(E + 0xc, r.getrandbits(32))
    return [E, p]


def _g638d60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    D = r.choice([-1, 0, 1, 2, 3, 5, 6])
    E = r.choice([-1, 0, 1, 2, 3, 4])
    rec = rnd(c, 0x20)
    buf = rnd(c, 0x200)
    e.w32(rec + 4, D & 0xffffffff if r.random() < 0.8 and D > 0 else r.randint(1, 6))
    e.w32(rec + 8, E & 0xffffffff if r.random() < 0.8 else r.randint(1, 4))
    e.w32(rec + 0x10, buf)
    tab = rnd(c, 0x400)
    t = obj(c, 0x40, {0x38: pystub(c, 1, this=True, ret=rec)})
    e.w32(t + 0x2d, tab)
    dst = rnd(c, 0x200)
    d0 = D & 0xffffffff
    return [t, dst, r.randint(0, 8), r.randint(0, 3), d0, E & 0xffffffff, r.choice([4 * max(D, 0), 4 * max(D, 0), 4, 8, 0x10]), r.getrandbits(32)]


def _g639df0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x70)
    for off in range(0x10, 0x60, 4):
        e.w32(s + off, r.choice([0, 1, 3, 8, 16, 24, 31, 32, 33, r.randint(0, 40)]))
    for off in (0, 4, 8, 0xc):
        e.w32(s + off, r.choice([0xff, 0xff00, 0xff0000, 0xff000000, 0xf800, 0x7e0, 0x1f, r.getrandbits(32)]))
    return [s, r.getrandbits(32), r.choice([0, 1, 0x100, 0x200, 0xff, r.getrandbits(32)])]


S(0x606120, 'GUESS MD5 finalize', 'thiscall', None, ret=None, gen=_g606120, note='batch36035')
S(0x616000, 'GUESS release a pool slot (B, record 0x30, clear bit 1)', 'thiscall', None, ret=None, gen=_pool, note='batch36035')
S(0x638d60, 'GUESS indexed rows to dwords', 'thiscall', None, ret=None, gen=_g638d60, note='batch36035')
S(0x639df0, 'GUESS pack colour channels', 'thiscall', None, ret='eax', gen=_g639df0, note='batch36035')
S(0x63f8a0, 'GUESS release a pool slot (B, record 0x4c, clear bit 1)', 'thiscall', None, ret=None, gen=_pool, note='batch36035')
