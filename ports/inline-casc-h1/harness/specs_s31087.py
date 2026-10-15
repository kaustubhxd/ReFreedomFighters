"""specs_s31087.py - Sonnet h1 batch 31087."""
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


def hk(c, addr, n, pop=0, ret=None, clob=True):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, addr, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def g6392b0(c):
    clear_hooks(c)
    me = obj(c, 0x80, {0x58: st(c, 6)})
    return [me, r32(c), c.rng.choice([0, 1, 7, 0x1000, r32(c)]), r32(c), r32(c)]


def g42c0a0(c):
    clear_hooks(c)
    r = c.rng
    O2 = obj(c, 0x40, {0x20: st(c, 1)})
    me = obj(c, 0x200, {0x1b0: st(c, 0, ret=r.choice([0, O2, O2]), clob=True)})
    return [me, r32(c)]


def _two_call(first, second, pop1, pop2, off):
    def g(c):
        clear_hooks(c)
        hk(c, first, 1, pop=pop1)
        hk(c, second, 2, pop=pop2)
        hk(c, 0x4e1b30, 0, clob=False)
        return [rnd(c, 0x200), rnd(c, 0x40)]
    return g


def g561e80(c):
    clear_hooks(c)
    hk(c, 0x561180, 1, pop=4)
    hk(c, 0x561330, 1, pop=4, clob=False)
    me = obj(c, 0x100, {0xc8: st(c, 1, clob=True)})
    return [me, r32(c)]


def g54a640(c):
    clear_hooks(c)
    blk = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, ret=blk, pop=0)
    c.emu.w32(0x700394, obj(c, 0x80, {0x60: st(c, 5)}))
    return [rnd(c, 0x8040), r32(c), r32(c)]


def g5c65e0(c):
    clear_hooks(c)
    v = [r32(c), r32(c)]
    w = r32(c)
    hook_rec(c, 0x4e5e60, 0, ret=lambda emu, k: v[min(k, 1)], pop=0, this=True)
    hook_rec(c, 0x4e5ea0, 0, ret=w, pop=0, this=True)
    return [rnd(c, 0x60), rnd(c, 0x20)]


def g656320(c):
    clear_hooks(c)
    r = c.rng
    O2 = obj(c, 0x40, {0x18: st(c, 2)})
    so = sysobj(c)
    c.emu.w32(so + 0x190f, obj(c, 0x40, {0x20: st(c, 0, ret=O2)}))
    return [r32(c), r.choice([0, 1, 5, 0x40000000, 0x10, 0x40000001])]


S(0x6392b0, 'GUESS slot 0x58 with 6 args incl. product', 'thiscall', None, ret='eax', gen=g6392b0, note='batch31087')
S(0x42c0a0, 'GUESS slot 0x1b0 chain then tail slot 0x20', 'thiscall', None, ret='eax', gen=g42c0a0, note='batch31087')
S(0x46cdc0, 'GUESS 43f900, 4e12e0(this+0x60, 1), 4e1b30', 'thiscall', None, ret='eax', gen=_two_call(0x43f900, 0x4e12e0, 4, 8, 0x60), note='batch31087')
S(0x4f4550, 'GUESS 4ef3f0, 4e11e0(this+0xb0, 1), 4e1b30', 'thiscall', None, ret='eax', gen=_two_call(0x4ef3f0, 0x4e11e0, 4, 8, 0xb0), note='batch31087')
S(0x54a640, 'GUESS alloc, global 0x700394 slot 0x60', 'thiscall', None, ret='eax', gen=g54a640, note='batch31087')
S(0x561e80, 'GUESS slot 0xc8, 561180, 561330 with arg', 'thiscall', None, ret='eax', gen=g561e80, note='batch31087')
S(0x5c65e0, 'GUESS three getters stored in members', 'thiscall', None, ret='eax', gen=g5c65e0, note='batch31087')
S(0x656320, 'GUESS global member slot 0x20 then 0x18 with size', 'stdcall', None, ret='eax', gen=g656320, note='batch31087')
