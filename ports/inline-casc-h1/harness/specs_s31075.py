"""specs_s31075.py - batch 31075."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g45c3a0(c):
    clear_hooks(c)
    hook_rec(c, 0x45fc90, 1, ret=r32(c), pop=4, this=True, side=_clob(c))
    return [rnd(c, 0x40), r32(c), r32(c), rnd(c, 0x80)]


def g4c2480(c):
    clear_hooks(c)
    val = r32(c)

    j = r32(c)

    def put(emu, k):
        emu.w32(emu.arg32(0), val)         # the callee fills the caller's local
        emu.mu.reg_write(REGS['ecx'], j)   # and clobbers ECX
    hook_rec(c, 0x6352f0, 1, ret=r32(c), pop=4, deref={0: 1}, side=put)
    hook_rec(c, 0x4c18b0, 1, ret=r32(c), pop=4, this=True, deref={0: 1})
    return [rnd(c, 0x40), r32(c)]


def g5dd020(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, ret=r32(c), pop=0, this=True, side=_clob(c))
    return [rnd(c, 0x90)]


def g476500(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=_clob(c))
    hook_rec(c, 0x43ea20, 0, ret=r32(c), pop=0, this=True)
    me = rnd(c, 0x80)
    for off in (0x64, 0x68):
        c.emu.w32(me + off, rnd(c, 0x10) if r.random() < 0.6 else 0)
    return [me]


def g54e0a0(c):
    clear_hooks(c)
    hook_rec(c, 0x41e290, 1, ret=r32(c), pop=0)
    return [rnd(c, 0x80)]


def g5e1040(c):
    clear_hooks(c)
    hook_rec(c, 0x5e0e10, 2, ret=r32(c), pop=8, this=True, side=_clob(c))
    return [rnd(c, 0x600), r32(c), r32(c)]


def g48f500(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0)
    me = rnd(c, 0x1c70)
    blk = rnd(c, 0x100) + 8
    size = r.choice([0x10, 0x20, 0x40, 0xf0])
    c.emu.w32(blk - 8, size | r.choice([0, 0xe0000000, 0x10000000, 0x10000000]))
    c.emu.w32(me + 0x1c5d, blk if r.random() < 0.85 else 0)
    base = c.emu.r32(me + 0x1c5d)
    a = r.choice([0, base, base + size - 1, base + size, base + size + 4, base + size + 0x100, base + 0x100, base - 4 if base else 5, base + 3, r32(c)])
    return [me, a & 0xffffffff]


def g606d60(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x20)
    val = c.rng.choice([0, blk])

    def put(emu, k):
        emu.w32(emu.arg32(0), val)
    hook_rec(c, 0x607200, 2, ret=r32(c), pop=8, this=True, deref={1: 1}, side=put)
    return [rnd(c, 0x40), r32(c)]


S(0x45c3a0, 'GUESS ctor linking this and owner c', 'thiscall', None, ret='eax', gen=g45c3a0, note='batch31075')
S(0x4c2480, 'GUESS clear flag 0x40, fill local via 6352f0, pass to 4c18b0', 'thiscall', None, ret='al', gen=g4c2480, note='batch31075')
S(0x5dd020, 'GUESS ctor base 469870, vtable 6b6cec', 'thiscall', None, ret='eax', gen=g5dd020, note='batch31075')
S(0x476500, 'GUESS dtor body: free two buffers, tail 43ea20', 'thiscall', None, ret='eax', gen=g476500, note='batch31075')
S(0x54e0a0, 'GUESS ctor allocating 0x40000 buffer', 'thiscall', None, ret='eax', gen=g54e0a0, note='batch31075')
S(0x5e1040, 'GUESS ctor base 5e0e10, vtable 6b79d0', 'thiscall', None, ret='eax', gen=g5e1040, note='batch31075')
S(0x48f500, 'GUESS free pointer if outside owned block', 'thiscall', None, ret='eax', gen=g48f500, note='batch31075')
S(0x606d60, 'GUESS word at +8 of 607200 lookup', 'thiscall', None, ret='eax', gen=g606d60, note='batch31075')
