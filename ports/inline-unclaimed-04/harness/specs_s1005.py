"""specs_s1005.py - unclaimed-04 batch 5 (docs/20-unclaimed-04.md): ZActor::RemovePath (0x47abb0, high name).
thiscall, three stack arguments (ret 0xc): a1 (unsigned int), reason (PATH_CANCEL_REASONS), flag (bool, low byte).
The object is 0x1000 random bytes with a fake vtable (logging_vtable): slot 0x588 returns a random eax, slots 0x620
and 0x62c log their arguments. The path object at +0x695 is null in 30% of cases, else an 0x20-byte record whose
fields at +0xc, +0x10 and +0x14 are null or small buffers.
Stubs (unverified callees, GUESS: release helpers): 0x41e2c0 (cdecl, one argument) and 0x634273 (cdecl, pointer and size).
Both are Python hooks that only log their arguments, so the exe and the port must make the same release calls."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _args(c):
    this = _rnd(c, 0x1000)
    path = 0
    if c.rng.random() < 0.7:
        path = _rnd(c, 0x20)
        for off in (0xc, 0x10, 0x14):
            c.emu.w32(path + off, _rnd(c, 0x10) if c.rng.random() < 0.6 else 0)
    c.emu.w32(this + 0x695, path)
    c.emu.wbytes(this + 0x726, bytes([c.rng.choice([0, 0, 1, 2])]))
    c.emu.w32(this + 0x64c, c.rng.choice([0xb, 0, 5, 0xb]))
    alive = c.rng.choice([0, 1, 2])
    vt = c.emu.logging_vtable('ZActor', 0x630 // 4 + 1,
                              impl={0x588: lambda em, a: (alive, None)},
                              argwords={0x588: 0, 0x620: 3, 0x62c: 1})
    c.emu.w32(this, vt)
    a1 = c.rng.getrandbits(32)
    reason = c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(8)])
    flag = c.rng.choice([0, 1, c.rng.getrandbits(8), c.rng.getrandbits(32) & 0xffffff00])
    return [this, a1, reason, flag]


def _setup(c):
    e = c.emu

    def release41(em, r):
        em.calllog.append(('41e2c0', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    def release34(em, r):
        em.calllog.append(('634273', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    e.hook(0x41e2c0, release41)
    e.hook(0x634273, release34)


S(0x47abb0, 'ZActor::RemovePath (high) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 5; release helpers 0x41e2c0 and 0x634273 are logging stubs (GUESS)')
