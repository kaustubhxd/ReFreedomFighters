"""specs_s31086.py - Sonnet h1 batch 31086."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False, pop=None, side2=None):
    j = r32(c)

    def side(emu, k):
        if side2:
            side2(emu, k)
        if clob:
            emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side if (clob or side2) else None)


def hk(c, addr, n, pop=0, ret=None, clob=True, side2=None):
    j = r32(c)

    def side(emu, k):
        if side2:
            side2(emu, k)
        if clob:
            emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, addr, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side if (clob or side2) else None)


def g54c480(c):
    clear_hooks(c)
    r = c.rng
    scratch = c.emu.alloc(4, 4)
    hk(c, 0x54f2b0, 0, clob=False, side2=lambda emu, k: emu.w32(scratch, emu.reg('edx')))
    inner = obj(c, 0x40, {0x4c: st(c, 5, ret=r.choice([0, r32(c), 0x1234]))})
    me = rnd(c, 0x6400)
    c.emu.w32(me + 0x63ec, inner)
    return [me] + [r32(c) for _ in range(4)]


def g55b300(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x10)
    hk(c, 0x5003d0, 1, pop=4, ret=blk)
    hk(c, 0x5002f0, 1, pop=4, clob=False)
    inner = obj(c, 0x730, {0x720: st(c, 0, ret=r.choice([-3 & 0xffffffff, 0, 1, 2, 5, 0x80000000, 0x7fffffff]))})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, inner)
    arg = rnd(c, 0x20)
    c.emu.w32(arg + 8, rnd(c, 0x10))
    return [me, arg]


def g59d370(c):
    clear_hooks(c)
    r = c.rng
    O = obj(c, 0x440, {0x1e0: st(c, 1, ret=r.choice([0, 1, 0x100, 0x101, r32(c)])), 0x438: st(c, 0)})
    me = rnd(c, 0x20)
    c.emu.w32(me, O)
    return [me]


def g5e7150(c):
    clear_hooks(c)
    hk(c, 0x489d00, 1, pop=4)
    a = obj(c, 0x80, {0x64: st(c, 1)})
    return [rnd(c, 0x560), a]


def g658140(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x64f820, 0)
    so = sysobj(c)
    c.emu.w32(so + 0x8f, r.choice([0, 1, r32(c)]))
    sub = obj(c, 0x20, {0x64: st(c, 0)})
    c.emu.wbytes(sub + 4, bytes([r.choice([0, 1, 7])]))
    me = obj(c, 0x100, {0xd4: st(c, 0)})
    c.emu.w32(me + 0xbd, sub)
    return [me]


def g470c50(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0xd0, {0x35c: st(c, 0, ret=r.choice([0, 1, r32(c)]))})
    return [me, r.choice([0, 1, 0x100, 0x1ff])]


def g490fa0(c):
    clear_hooks(c)
    val = r32(c)

    def put(emu, k):
        emu.w32(emu.arg32(1), val)
    o2 = obj(c, 0x100, {0x88: pystub(c, 2, ret=r32(c), this=True, side=put)})
    sysobj(c, table_slots={0x134: st(c, 0, ret=o2)})
    return []


def g4f0bd0(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x4dc630, 2, pop=8)
    hk(c, 0x4dae40, 0, clob=False)
    sysobj(c, table_slots={0x2c: st(c, 0, ret=r.choice([0, 1, 0x100, 0x101, r32(c)]))})
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, rnd(c, 0x20))
    return [me]


def g564e40(c):
    clear_hooks(c)
    hk(c, 0x5626c0, 0)
    hk(c, 0x564e80, 0)
    o2 = obj(c, 0x80, {0x5c: st(c, 3)})
    sysobj(c, table_slots={0x134: st(c, 0, ret=o2)})
    return [rnd(c, 0x1a0)]


def g538300(c):
    clear_hooks(c)
    o2 = obj(c, 0x40, {0x2c: st(c, 4, pop=0)})
    lg = obj(c, 0x40, {0x20: st(c, 2, ret=o2)})
    c.emu.w32(0x700390, lg)
    a = rnd(c, 0x10)
    return [a]


S(0x54c480, 'GUESS call slot 0x4c of member with args, 54f2b0 on result', 'thiscall', None, ret='eax', gen=g54c480, note='batch31086')
S(0x55b300, 'GUESS slot 0x720 > 1 flag into 5003d0/5002f0', 'thiscall', None, ret='eax', gen=g55b300, note='batch31086')
S(0x59d370, 'GUESS slot 0x1e0 gate then tail slot 0x438', 'thiscall', None, ret='al', gen=g59d370, note='batch31086')
S(0x5e7150, 'GUESS 489d00 then arg slot 0x64, true', 'thiscall', None, ret='al', gen=g5e7150, note='batch31086')
S(0x658140, 'GUESS 64f820, conditional slots 0x64 and 0xd4, true', 'thiscall', None, ret='al', gen=g658140, note='batch31086')
S(0x470c50, 'GUESS flag byte from slot 0x35c and arg', 'thiscall', None, ret='eax', gen=g470c50, note='batch31086')
S(0x490fa0, 'GUESS table slot 0x134 lookup into local, return it', 'cdecl', None, ret='eax', gen=g490fa0, note='batch31086')
S(0x4f0bd0, 'GUESS table slot 0x2c gate, 4dc630, tail 4dae40', 'thiscall', None, ret='eax', gen=g4f0bd0, note='batch31086')
S(0x564e40, 'GUESS 5626c0, 564e80, flag, table slot 0x134 then 0x5c', 'thiscall', None, ret='eax', gen=g564e40, note='batch31086')
S(0x538300, 'GUESS log object slot 0x20 then 0x2c with fields of arg', 'stdcall', None, ret='al', gen=g538300, note='batch31086')
