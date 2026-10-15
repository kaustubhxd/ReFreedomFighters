"""specs_s31113.py - Sonnet h1 batch 31113."""
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


def g4f7a20(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4ccfe0, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x43ea20, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x45c510, 1, ret=r32(c), pop=0)
    hook_rec(c, 0x4690b0, 2, ret=r32(c), pop=0)
    return [rnd(c, 0xd0), r.choice([0, 1, 2, 3, 4, 5, 7, r32(c)])]


def g5603e0(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x20)
    hook_rec(c, 0x41e290, 1, ret=r.choice([blk, blk, 0]), pop=0)
    hook_rec(c, 0x560280, 0, ret=r32(c), pop=0, this=True)
    if r.random() < 0.4:
        c.emu.w32(0x71419c, obj(c, 0x40, {0x24: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x40))
    else:
        c.emu.w32(0x71419c, 0)
    return []


def g57aa80(c):
    clear_hooks(c)
    hook_rec(c, 0x563110, 2, ret=r32(c), pop=8, this=True, side=clob(c))
    hook_rec(c, 0x610100, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    me = obj(c, 0x100, {0xd4: pystub(c, 1, ret=r32(c), this=True, side=clob(c))}, nslots=0x80)
    o = obj(c, 0x40, {0x138: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x80)
    sysobj(c, table_slots={0xb4: pystub(c, 1, ret=r32(c), this=True)})
    so = c.emu.r32(0x70039c)
    c.emu.w32(so + 0x1a9f, o)
    return [me, r32(c), r32(c)]


def g5f2ea0(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    buf = rnd(c, 0x40)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, buf)
    c.emu.w32(me + 0xc, (buf + 4 + r.choice([0, 0, 1, 4, 0x20, -1, -4])) & 0xffffffff)
    return [me, rnd(c, 0x20)]


S(0x4f7a20, 'GUESS dtor vtable 69ae94: 4ccfe0, 43ea20, flags -> 45c510 or 4690b0', 'thiscall', None, ret='eax', gen=g4f7a20, note='batch31113')
S(0x5603e0, 'GUESS singleton getter at 0x71419c: create via 41e290/560280 or slot 0x24', 'cdecl', None, ret='eax', gen=g5603e0, note='batch31113')
S(0x57aa80, 'GUESS init: 563110, 610100(0), slots 0xd4(0xfe), 0xb4(1), 0x138(1), true', 'thiscall', None, ret='al', gen=g57aa80, note='batch31113')
S(0x5f2ea0, 'GUESS bounds-asserted read dword from cursor to out', 'thiscall', None, ret=None, gen=g5f2ea0, note='batch31113')
