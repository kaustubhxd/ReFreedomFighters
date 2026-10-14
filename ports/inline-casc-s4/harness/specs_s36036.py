"""specs_s36036.py - cascade s4 batch 36036: 0x63f9f0 / 0x64d9e0 (pool slot release, record 0x18 / 0x14), 0x65c730 (per-frame counters), 0x40b6f0 (table resample), 0x470920 (send a text when allowed)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


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


def _g65c730(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = e.alloc(0x10300, 4)
    e.wbytes(s, bytes(r.getrandbits(8) for _ in range(0x100)))
    X = rnd(c, 0x60)
    e.w32(s + 0x10051, X)
    n = r.choice([0, 1, 2, 3, 5, 8])
    e.w32(s + 0x20, n)
    for off, tag in ((0x10171, 1), (0x10199, 2)):
        vt = e.alloc(8, 4)
        e.w32(vt + 4, pystub(c, 0, this=True, ret=r.getrandbits(32)))
        e.w32(s + off, vt)
    flags_pool = [0x78000000, 0x78000010, 0x7ff0, 0x7fe0, 0x7fe1, 0x7ff1, 0x6, 0x16, 0x26, 0x10, 0x20, 0xffffffff, 0, 0x3, 0x7fff0006, 0x1, 0x70000010]
    for i in range(0, 16):
        f = r.choice(flags_pool) if r.random() < 0.85 else r.getrandbits(32)
        e.w32(s + 0x28 + 8 * i, f)
        q = rnd(c, 0x10) if r.random() < 0.85 else rnd(c, 0x10)
        e.w32(q + 8, 0 if r.random() < 0.25 else rnd(c, 0x10))
        e.w32(s + 0x28 + 8 * i + 4, q)
    rec = rnd(c, 0x20)
    rec2 = rnd(c, 0x20)
    e.w32(rec + 0xc, rec2)
    hook_rec(c, 0x659000, 0, this=True, ret=lambda em, k: rec if (k % 3) != 1 else 0)
    return [s]


def _g40b6f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a0 = r.randint(0, 8)
    D = r.choice([1, 2, 3, 5, 9, 12, -1, -4])
    a1 = a0 + D
    a2 = r.randint(50, 150)
    a3 = a2 + r.randint(-40, 40)
    dst = rnd(c, 0x80)
    e.wbytes(dst, bytes([0x5a]) * 0x80)
    return [a0, a1 & 0xffffffff, a2, a3 & 0xffffffff, dst]


def _g470920(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ident = r.getrandbits(32)

    def side88(em, k):
        em.w32(em.arg32(1), ident)
    o = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=side88)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o),
                           0x114: pystub(c, 5, this=True, deref={4: -1}, ret=lambda em, k: 0x12345678 * (k + 1) & 0xffffffff)})
    w = obj(c, 0x20, {0x32c: pystub(c, 0, this=True, ret=r.choice([0, 1, 1, 1, 0x100]))})
    y = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100])),
                      0x420: pystub(c, 0, this=True, ret=r.choice([0, 1, 1, 2]))})
    s = obj(c, 0x20, {0x350: pystub(c, 0, this=True, ret=w),
                      0x2f4: pystub(c, 0, this=True, ret=y if r.random() < 0.85 else 0),
                      0x12c: pystub(c, 2, this=True)})
    return [s]


S(0x63f9f0, 'GUESS release a pool slot (record 0x18)', 'thiscall', None, ret=None, gen=_pool, note='batch36036')
S(0x64d9e0, 'GUESS release a pool slot (record 0x14)', 'thiscall', None, ret=None, gen=_pool, note='batch36036')
S(0x65c730, 'GUESS accumulate per-frame counters', 'thiscall', None, ret=None, gen=_g65c730, note='batch36036')
S(0x40b6f0, 'GUESS resample a table run', 'cdecl', None, ret=None, gen=_g40b6f0, note='batch36036')
S(0x470920, 'GUESS send a text when allowed', 'thiscall', None, ret=None, gen=_g470920, note='batch36036')
