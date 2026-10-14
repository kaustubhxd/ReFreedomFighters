"""specs_s31120.py - batch 31120."""
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


def g4f8f80(c):
    clear_hooks(c)
    hook_rec(c, 0x4fa330, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    y = obj(c, 0x40, {0x324: pystub(c, 0, ret=r32(c), this=True),
                      0x350: pystub(c, 3, ret=r32(c), this=True)}, nslots=0x100)
    b = obj(c, 0x40, {0xbc: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x40)
    me = obj(c, 0x200, {0x114: pystub(c, 1, ret=r32(c), this=True, side=clob(c)),
                        0x2c4: pystub(c, 0, ret=y, this=True, side=clob(c))}, nslots=0x100)
    c.emu.w32(me + 0x1bf, b)
    return [me, r32(c)]


def g50b7f0(c):
    clear_hooks(c)
    blk = rnd(c, 0x20)
    hook_rec(c, 0x5003d0, 1, ret=blk, pop=4, this=True)
    e = obj(c, 0x40, {0x130: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x80)
    g = obj(c, 0x40, {0x25c: pystub(c, 2, ret=e, this=True)}, nslots=0x100)
    so = sysobj(c, table_slots={0x114: pystub(c, 5, ret=r32(c), this=True)}, table_size=0xb00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.w32(tbl + 0xadc, g)
    return [rnd(c, 0x20)]


def g56fc20(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x56fb10, 0, ret=r32(c), pop=0, this=True)
    me = rnd(c, 0x600)
    L = r.choice([0, 0, 1, 2, 3, 5])
    b = [r.randrange(1, 256) for _ in range(L)] + [0] + [r.getrandbits(8) for _ in range(7)]
    for i in range(0, 8, 4):
        c.emu.w32(me + 0x1c9 + i, b[i] | b[i + 1] << 8 | b[i + 2] << 16 | b[i + 3] << 24)
    cnt = r.choice([0, 1, 2, 3, 4])
    c.emu.w32(me + 0x4b2, cnt)
    for i in range(5):
        c.emu.w32(me + 0x3b2 + 4 * i, r.choice([0, 1, L, L, max(L - 1, 0), L + 1]))
    c.emu.w32(me + 0x5ca, obj(c, 0x40, {0x248: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x100))
    c.emu.w32(me + 0x5ce, obj(c, 0x40, {0x284: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x100))
    return [me]


def g5f3240(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    L = r.choice([0, 1, 2, 5, 9])
    s = rnd(c, 0x20)
    bs = [r.randrange(1, 256) for _ in range(L)] + [0]
    for i, v in enumerate(bs):
        c.emu.w32(s + i, v | (c.emu.r32(s + i) & ~0xff))
    # byte stores through w32 overlap neighbours; rewrite ascending so the string stays intact
    for i, v in enumerate(bs):
        c.emu.w32(s + i, v | (c.emu.r32(s + i) & ~0xff))
    end = s + L + r.choice([0, 0, 0, 1, 2])
    a = rnd(c, 0x10)
    c.emu.w32(a, s)
    c.emu.w32(a + 4, end)
    D = rnd(c, 0x40)
    edi = end - s + 1
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, D)
    c.emu.w32(me + 0xc, (D + edi + r.choice([0, 0, 1, -1, 4, 0x20])) & 0xffffffff)
    return [me, a]


S(0x4f8f80, 'GUESS 4fa330(arg), slots 0x114(0x10), 0xbc(1), 0x2c4 chain 0x324 and 0x350(0x1c,0,this)', 'thiscall', None, ret='al', gen=g4f8f80, note='batch31120')
S(0x50b7f0, 'GUESS global+0xadc slot 0x25c, 5003d0, sys slot 0x114 word to slot 0x130', 'stdcall', None, ret='eax', gen=g50b7f0, note='batch31120')
S(0x56fc20, 'GUESS pop one level of string buffer, notify slot 0x284 and tail 56fb10', 'thiscall', None, ret='eax', gen=g56fc20, note='batch31120')
S(0x5f3240, 'GUESS bounds-asserted string append (end-start+1 bytes advance)', 'thiscall', None, ret=None, gen=g5f3240, note='batch31120')
