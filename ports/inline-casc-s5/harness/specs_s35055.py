"""specs_s35055.py - 0x4a22f0 (thiscall(s) ret 4). s null in 1/6, else a pointer into a heap block with the hash dword at s-4 (zero in 1/3); the object E at 0x70038c: slot 0x20 (1 arg, non-zero in 1/4),
slot 0xac (1 arg, writes a random hash to s-4 in half the calls), function pointer at +8 (null in 1/4, else a thiscall recorder returning a random hash) and range [E+0xc, E+0x10) placed around s in 2/3 of
the cases; this+0x48 = count 0..3 (negative in 1/10 to exercise the signed loop test), targets at +0x5c; 0x4a2380 hooked (thiscall, 1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4a22f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4a2380, 1, this=True)
    blk = rnd(c, 0x40)
    s = 0 if r.random() < 1 / 6 else blk + 8
    if s and r.random() < 1 / 3:
        e.w32(s - 4, 0)

    def w0ac(em, k):
        if s and r.random() < 0.5:
            em.w32(s - 4, r.getrandbits(32))
    E = obj(c, 0x20, {0x20: pystub(c, 1, this=True, ret=0 if r.random() < 0.75 else r.getrandbits(32) | 1),
                      0xac: pystub(c, 1, this=True, side=w0ac)}, nslots=0x2c)
    e.w32(E + 8, 0 if r.random() < 1 / 4 else e.stub_fn('fn8', lambda em, rr, v=r.getrandbits(32): (em.calllog.append(('f8', em.reg('ecx'))), em.ret(eax=v))))
    if s and r.random() < 2 / 3:
        e.w32(E + 0xc, s - r.choice([0, 1, 8]))
        e.w32(E + 0x10, s + r.choice([0, 1, 4, 100]))
    elif s:
        e.w32(E + 0xc, s + r.choice([1, 4]))
        e.w32(E + 0x10, s + r.choice([-1, 0, 8, 100]) & 0xffffffff)
    e.w32(0x70038c, E)
    me = rnd(c, 0x80)
    n = r.choice([0, 1, 2, 3, 3])
    if r.random() < 0.1:
        n = r.choice([0xffffffff, 0x80000000])
    e.w32(me + 0x48, n if n < 0x80000000 and n != 0xffffffff else n)
    for i in range(4):
        e.w32(me + 0x5c + 4 * i, rnd(c, 0x10))
    if n >= 0x80000000:
        pass
    return [me, s]


S(0x4a22f0, 'GUESS apply string hash to registered targets', 'thiscall', None, ret=None, gen=_g4a22f0, note='batch35055')
