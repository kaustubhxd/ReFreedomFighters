"""specs_s34080.py - ten queue items. 0x5edc80 takes ecx = begin, edx = end plus one unused stack dword (regs ABI)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g65f170(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x100)
    n = r.choice([0, 1, 2, 5])
    c.emu.w32(me + 0xcc, n)
    for i in range(n):
        c.emu.w32(me + 0xd0 + 4 * i, rnd(c, 0x50))
    return [me]


def _g533ce0(c):
    clear_hooks(c)
    return [rnd(c, 0x4020)]


def _g63da80(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x300)
    so = rnd(c, 0x50)
    c.emu.w32(0x70039c, so)
    a = rnd(c, 0x10)
    c.emu.wbytes(a + 6, r.choice([0xffff, 0xffff, 0, 1, 7, 0x40, 0x7f]).to_bytes(2, 'little'))
    return [me, a]


def _g622aa0(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x150)
    tab = [9, 10, 0x15, 0x15, 3, 11, 0x20, 0, 8, 0x14, 0x16, 0xff]
    c.emu.wbytes(a + 0x4c, bytes(r.choice(tab) for _ in range(0x100)))
    b = rnd(c, 0x40)
    c.emu.wbytes(b, bytes(r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]) for _ in range(0x40)))
    return [a, b]


def _g63b160(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x200)
    c.emu.wbytes(me + 2, r.choice([0xffff, 0, 1, 3, 5]).to_bytes(2, 'little'))
    return [me]


def _g5aedf0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x100)
    n = r.choice([0, 1, 3, 0x13, 0x14, 0x15, 0xffffffff])
    c.emu.w32(me, n)
    a = r.getrandbits(32)
    if 0 < n <= 0x14 and r.random() < 0.5:
        c.emu.w32(me + 4 + 4 * r.randrange(n), a)
    return [me, a]


def _g4d12e0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x200)
    n = r.choice([0, 1, 2, 4, 6])
    c.emu.w32(me + 0x88, n)
    a = r.choice([0, 100, 0x7fffffff, 0xffffffff, r.getrandbits(32)])
    for i in range(n):
        lo = (a + r.choice([-3, -1, 0, 1, 5, r.getrandbits(32)])) & 0xffffffff
        hi = (lo + r.choice([0, 1, 2, 10, r.getrandbits(32)])) & 0xffffffff
        c.emu.w32(me + 0x10 + 12 * i, lo)
        c.emu.w32(me + 0x14 + 12 * i, hi)
    return [me, a]


def _g5edc80(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x60)
    n = r.choice([0, 1, 2, 3, 4, 7, 10])
    return [buf, buf + 4 * n, r.getrandbits(32)]


S(0x5df690, 'GUESS constructor with four fields (vtable 0x6b7400)', 'thiscall', None, ret='eax', gen=_ctor, note='batch34080')
S(0x5df620, 'GUESS constructor with four fields (vtable 0x6b7388)', 'thiscall', None, ret='eax', gen=_ctor, note='batch34080')
S(0x65f170, 'GUESS reset entries', 'thiscall', None, ret=None, gen=_g65f170, note='batch34080')
S(0x533ce0, 'GUESS init free-list table', 'thiscall', None, ret='eax', gen=_g533ce0, note='batch34080')
S(0x63da80, 'GUESS release handle slot', 'thiscall', None, ret='eax', gen=_g63da80, note='batch34080')
S(0x622aa0, 'GUESS skip class run', 'cdecl', None, ret='eax', gen=_g622aa0, note='batch34080')
S(0x63b160, 'GUESS pop entry from free list', 'thiscall', None, ret='eax', gen=_g63b160, note='batch34080')
S(0x5aedf0, 'GUESS set insert (20 entries)', 'thiscall', None, ret=None, gen=_g5aedf0, note='batch34080')
S(0x4d12e0, 'GUESS value in ranges', 'thiscall', None, ret='al', gen=_g4d12e0, note='batch34080')
S(0x5edc80, 'GUESS reverse dwords [begin, end)', ('regs', ['ecx', 'edx', 's']), None, ret=None, gen=_g5edc80, note='batch34080')
