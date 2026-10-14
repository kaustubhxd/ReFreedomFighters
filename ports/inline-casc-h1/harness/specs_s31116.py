"""specs_s31116.py - batch 31116."""
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


def logobj(c, slot, nargs):
    o2 = obj(c, 0x40, {slot: pystub(c, nargs, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))


def g46a940(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43ea20, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x45c510, 1, ret=r32(c), pop=0)
    hook_rec(c, 0x4690b0, 2, ret=r32(c), pop=0)
    me = rnd(c, 0x90)
    sub = r.choice([0, obj(c, 0x40, {0: pystub(c, 1, ret=r32(c), this=True, side=clob(c))}, nslots=0x10)])
    c.emu.w32(me + 0x70, sub)
    return [me, r.choice([0, 1, 2, 3, 4, 5, 7, r32(c)])]


def g4c21e0(c):
    clear_hooks(c)
    _assert_hook(c)
    hook_rec(c, 0x4c0d70, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    cc = obj(c, 0x40, {0x48: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x40)
    b = obj(c, 0x40, {0x48: pystub(c, 1, ret=cc, this=True)}, nslots=0x40)
    a = obj(c, 0x40, {0x40: pystub(c, 1, ret=b, this=True)}, nslots=0x40)
    return [rnd(c, 0x1e0), a]


def g4f1070(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 4])
    blks = [rnd(c, 0x40) for _ in range(4)]
    calls = [0]

    def nxt(e, k):
        calls[0] += 1
        return blks[(calls[0] - 1) % 4]
    h = obj(c, 0x40, {0xc: pystub(c, 1, ret=lambda e, k: blks[k % 4], this=True)}, nslots=0x10)
    g = rnd(c, 0x40)
    c.emu.w32(g + 0x18, h)
    so = sysobj(c)
    c.emu.w32(so + 0x1aa3, g)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x32, n)
    c.emu.w32(me + 0x36, rnd(c, 0x20))
    c.emu.w32(me + 0x3a, r.choice([0, 1, r32(c) | 1]))
    return [me, r.choice([0xffffffff, 0, 5, r32(c)]) if False else r32(c) & ~1, r.choice([0xffffffff, 0, 1, r32(c)])]


def g54f1a0(c):
    clear_hooks(c)
    r = c.rng
    logobj(c, 0x2c, 2)
    ob = r.choice([0, obj(c, 0x40, {0x10: pystub(c, 7, ret=r.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, r32(c)]), this=True, deref={5: 1})}, nslots=0x20)])
    me = rnd(c, 0x20)
    c.emu.w32(me + 4, ob)
    return [me, r32(c)]


S(0x46a940, 'GUESS dtor vtable 6868e8: delete this[0x70], 43ea20, flags -> 45c510 or 4690b0', 'thiscall', None, ret='eax', gen=g46a940, note='batch31116')
S(0x4c21e0, 'GUESS clear flag, assert hook, 4c0d70(0), slot chain 0x40/0x48/0x48', 'thiscall', None, ret='al', gen=g4c21e0, note='batch31116')
S(0x4f1070, 'GUESS set flags and propagate to list objects via slot 0xc', 'thiscall', None, ret='eax', gen=g4f1070, note='batch31116')
S(0x54f1a0, 'GUESS call slot 0x10 with 7 args, log on failure', 'thiscall', None, ret='eax', gen=g54f1a0, note='batch31116')
