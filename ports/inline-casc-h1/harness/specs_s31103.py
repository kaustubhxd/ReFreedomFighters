"""specs_s31103.py - Sonnet h1 batch 31103."""
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


def g5eaf80(c):
    clear_hooks(c)
    p = obj(c, 0x800, {0x704: pystub(c, 1, ret=r32(c), this=True, side=clob(c)),
                       0x128: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x200)
    sysobj(c, table_slots={0x114: pystub(c, 6, ret=r32(c), this=True)})
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, p)
    return [me]


def g5f3320(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    buf = rnd(c, 0x40)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, buf)
    c.emu.w32(me + 0xc, buf + 4 + r.choice([0, 0, 1, 4, 0x20, -1, -4]) & 0xffffffff)
    return [me, r32(c)]


def g63f090(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    hook_rec(c, 0x4ce7b0, 0, ret=lambda e, k: r.choice([0xfff, 0x1fff, 0xffffffff, 0, 5, r.getrandbits(32), 0xffe]),
             pop=0, this=True)
    me = rnd(c, 0xb9a0)
    c.emu.w32(me + 0x68, rnd(c, 0x4000))
    return [me, r32(c)]


S(0x5eaf80, 'GUESS slot 0x704(0) then sys slot 0x114 result passed to slot 0x128', 'thiscall', None, ret='al', gen=g5eaf80, note='batch31103')
S(0x5f3320, 'GUESS bounds-asserted push dword', 'thiscall', None, ret=None, gen=g5f3320, note='batch31103')
S(0x63f090, 'GUESS ring table store at (4ce7b0+1)&0xfff', 'thiscall', None, ret='eax', gen=g63f090, note='batch31103')
