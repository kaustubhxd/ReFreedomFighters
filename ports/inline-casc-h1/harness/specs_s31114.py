"""specs_s31114.py - Sonnet h1 batch 31114."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def g5f9b80(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    hook_rec(c, 0x5f9940, 3, ret=r32(c), pop=12, this=True)
    c.emu.w32(0x7241a0, r.choice([0, 1, 7, 0x30, 0x31, 0x32, 0x33, 0x1000]))
    a = rnd(c, 0x20)
    c.emu.w32(a + 0xc, r.choice([0, 1, 0x100, r32(c) | 1]))
    return [a]


def g48f580(c):
    clear_hooks(c)
    r = c.rng
    prev = r.choice([0, rnd(c, 0x40)])
    nxt = r.choice([0, rnd(c, 0x40)])
    node = rnd(c, 0x40)
    c.emu.w32(node + 0x24, prev)
    c.emu.w32(node + 0x28, nxt)
    c.emu.w32(node + 4, r.choice([0, 0x10, r32(c)]))
    o = r.choice([0, obj(c, 0x40, {4: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x10)])
    me = rnd(c, 0x5d40)
    c.emu.w32(me + 0xc, o)
    return [me, node]


def g4b0c80(c):
    clear_hooks(c)
    _assert_hook(c)
    me = obj(c, 0x100, {0x98: pystub(c, 1, ret=r32(c), this=True, side=clob(c))}, nslots=0x40)
    a = obj(c, 0x40, {0x48: pystub(c, 1, ret=r32(c), this=True), 0x58: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x40)
    return [me, a]


def g4f2610(c):
    clear_hooks(c)
    hook_rec(c, 0x634d10, 3, ret=r32(c), pop=0)
    hook_rec(c, 0x4f2f60, 1, ret=r32(c), pop=4, this=True)
    me = obj(c, 0x640, {0x334: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x200)
    return [me]


S(0x5f9b80, 'GUESS register 5f9940 and push handler 5f992f to table (cap 0x32)', 'stdcall', None, ret='eax', gen=g5f9b80, note='batch31114')
S(0x48f580, 'GUESS unlink node from list, release via owner slot 4', 'thiscall', None, ret='eax', gen=g48f580, note='batch31114')
S(0x4b0c80, 'GUESS clear flag 0x40, assert hook, slot 0x98(0), slots 0x48/0x58 of arg', 'thiscall', None, ret='al', gen=g4b0c80, note='batch31114')
S(0x4f2610, 'GUESS reset state: slot 0x334, flags, memset 0x418, zero fields, 4f2f60', 'thiscall', None, ret='eax', gen=g4f2610, note='batch31114')
