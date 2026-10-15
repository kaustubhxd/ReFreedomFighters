"""specs_s31097.py - Sonnet h1 batch 31097. /GS check 0x633654 is a zero-argument recorder that records ECX (= the global cookie when the port is right)."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False, pop=None):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def g4d5c20(c):
    clear_hooks(c)
    val = r32(c)

    def put(emu, k):
        for i in range(8):               # the callee initialises the caller's 0x20-byte local with distinct dwords
            emu.w32(emu.arg32(1) + 4 * i, (val + i * 0x01010101) & 0xffffffff)
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    hook_rec(c, 0x4d6520, 3, ret=r32(c), pop=0xc, deref={1: 8}, side=put)
    return [r32(c)]


def g6352a0(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x150: st(c, 2)})
    me = rnd(c, 0x40)
    mask = r.choice([0x158, 0x100, 0x40, 0x18, 0, 0xffffffff])
    c.emu.w32(me + 0x18, r32(c) & 0xffffffff if r.random() < 0.5 else mask)
    return [me, r.choice([0x158, 0x100, 0x8, 0x40, 0x1, 0xffffffff, r32(c)]), r.choice([0, 1, 0x100, 0x101])]


def g5bfa80(c):
    clear_hooks(c)
    a = obj(c, 0x80, {0x44: st(c, 1, clob=True), 0x60: st(c, 1)})
    return [rnd(c, 0x90), a]


S(0x4d5c20, 'GUESS 4d6520(arg, &local, 0) with /GS check', 'stdcall', None, ret='eax', gen=g4d5c20, note='batch31097')
S(0x6352a0, 'GUESS clear masked flag bits, notify table slot 0x150', 'thiscall', None, ret='eax', gen=g6352a0, note='batch31097')
S(0x5bfa80, 'GUESS clear flag, two slot 0x44 calls and slot 0x60, true', 'thiscall', None, ret='al', gen=g5bfa80, note='batch31097')
