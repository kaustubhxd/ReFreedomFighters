"""specs_s31105.py - batch 31105."""
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


def g539730(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x53b2a0, 1, ret=r32(c), pop=4, this=True)
    hook_rec(c, 0x534570, 1, ret=r32(c), pop=4, this=True)
    st = obj(c, 0x100, {0x8: pystub(c, 1, ret=r32(c), this=True, side=clob(c)),
                        0x6c: pystub(c, 1, ret=r32(c), this=True, side=clob(c))})
    me = rnd(c, 0x5400)
    c.emu.w32(me + 0x52fa, r.choice([0, 0, r32(c) | 1]))
    return [me, st]


def g5578d0(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    n = r.choice([0, 1, 2, 3, 5, 6])
    c.emu.w32(0x713e2c, n)
    for i in range(6):
        c.emu.w32(0x713e30 + 4 * i, pystub(c, 1, ret=r32(c)))
    o2 = obj(c, 0x40, {0x2c: pystub(c, 3, ret=r32(c), this=True, pop=0)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}))
    a = rnd(c, 0x40)
    c.emu.w32(a + 0x10, r.randrange(0, 9) | (r.getrandbits(16) << 16))
    return [a]


def g5f5050(c):
    clear_hooks(c)
    r = c.rng
    cnt = r.choice([0, 1, 2, 3, 5, 6])
    arr = rnd(c, 8 * 8 + 8)
    for i in range(cnt):
        o = obj(c, 0x40, {0x28: pystub(c, 0, ret=r32(c), this=True)})
        c.emu.w32(arr + 8 * i, o)
        c.emu.w32(arr + 8 * i + 4, r.choice([4, 4, 0, 1, 3, 5, r.getrandbits(8)]) | (r.getrandbits(24) << 8))
    me = rnd(c, 0x20)
    c.emu.w32(me, arr)
    c.emu.w32(me + 8, cnt)
    lim = rnd(c, 0x10)
    c.emu.w32(lim, r.choice([0, cnt, r.randrange(0, cnt + 2)]))
    return [me, lim]


S(0x539730, 'GUESS stream vcalls slot 8/0x6c then 53b2a0 and 534570', 'thiscall', None, ret='al', gen=g539730, note='batch31105')
S(0x5578d0, 'GUESS jump table dispatch by word +0x10 else log+assert', 'stdcall', None, ret='eax', gen=g5578d0, note='batch31105')
S(0x5f5050, 'GUESS unwind stack down to limit, slot 0x28 on kind 4', 'thiscall', None, ret=None, gen=g5f5050, note='batch31105')
