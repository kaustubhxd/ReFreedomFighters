"""specs_s31080.py - Sonnet h1 batch 31080."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def _stub(c, n=0, ret=None, pop=None):
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True)


def g630070(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x630910, 4, ret=r32(c), pop=0)
    s = rnd(c, 0x16c0)
    c.emu.w32(s + 8, rnd(c, 0x60))
    c.emu.w32(s + 0x14, r.randrange(0, 0x20))
    c.emu.w32(s + 0x16b4, r.choice([-1, 0, 5, 0xc, 0xd, 0xe, 15, 20, 31]) & 0xffffffff)
    return [s, r32(c), r32(c), r32(c)]


def g431270(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x54f870, 2, ret=r32(c), pop=8, this=True)
    blk = rnd(c, 0x140)
    hook_rec(c, 0x6014a0, 1, ret=blk, pop=4)
    me = rnd(c, 0x10)
    n = r.choice([0, 1, 5, 20])
    src = rnd(c, 0x40)
    srcend = src + n if r.random() < 0.9 else src + n
    c.emu.w32(me, src if r.random() < 0.8 else 0)
    c.emu.w32(me + 4, srcend)
    c.emu.w32(me + 8, src + r.choice([0, 0x20, 0x40]))
    if c.emu.r32(me) == 0:
        c.emu.w32(me + 4, 0)
    return [me, r.choice([0, 3, 10, 30, 0x80])]


def _slot_this(slot, nstack):
    def g(c):
        clear_hooks(c)
        me = obj(c, 0x40, {slot: _stub(c, nstack)})
        return [me] + [r32(c) for _ in range(2)]
    return g


def g4afec0(c):
    clear_hooks(c)
    me = obj(c, 0x40, {0x84: _stub(c, 0, pop=0)})
    return [me, r32(c), r32(c)]


def g4c8340(c):
    clear_hooks(c)
    me = obj(c, 0x40, {8: _stub(c, 0, pop=0)})
    return [me, r32(c)]


def _sys_slot(slot, off=None, field_off=0x94):
    def g(c):
        clear_hooks(c)
        sysobj(c, table_slots={slot: _stub(c, 1)})
        me = rnd(c, 0x900)
        return [me, r32(c)]
    return g


def g533b80(c):
    clear_hooks(c)
    so = sysobj(c)
    c.emu.w32(so + 0x1a9f, obj(c, 0x40, {0x160: _stub(c, 1)}))
    return [rnd(c, 0x20)]


def g654a20(c):
    clear_hooks(c)
    me = obj(c, 0x40, {0x268: _stub(c, 0, pop=0)})
    sysobj(c, slots={0x16c: _stub(c, 0, pop=0)})
    return [me, r32(c)]


def g561c40(c):
    clear_hooks(c)
    o2 = obj(c, 0x40, {0xe0: _stub(c, 2)})
    sysobj(c, slots={0xbc: pystub(c, 0, ret=o2, pop=0, this=True)})
    return [rnd(c, 0x20), r32(c), r32(c)]


def g63cc40(c):
    clear_hooks(c)
    me = obj(c, 0x40, {0x50: _stub(c, 1)})
    return [me, r32(c), r32(c)]


S(0x630070, 'GUESS bit writer: flush 16 bits when the accumulator overflows', 'cdecl', None, ret='eax', gen=g630070, note='batch31080')
S(0x431270, 'GUESS string buffer reserve and copy', 'thiscall', None, ret=None, gen=g431270, note='batch31080')
S(0x4afec0, 'GUESS vtable call slot 0x84', 'thiscall', None, ret='eax', gen=g4afec0, note='batch31080')
S(0x466d80, 'GUESS vtable call slot 0x2b4 with 6', 'thiscall', None, ret='eax', gen=_slot_this(0x2b4, 1), note='batch31080')
S(0x4673f0, 'GUESS vtable call slot 0x2b4 with 0x15', 'thiscall', None, ret='eax', gen=_slot_this(0x2b4, 1), note='batch31080')
S(0x4cb110, 'GUESS vtable call slot 0x64 with 0x10', 'thiscall', None, ret='eax', gen=_slot_this(0x64, 1), note='batch31080')
S(0x54e080, 'GUESS vtable call slot 0x2c with 0', 'thiscall', None, ret='eax', gen=_slot_this(0x2c, 1), note='batch31080')
S(0x4c8340, 'GUESS clear flag 0x40, vtable call slot 8, true', 'thiscall', None, ret='al', gen=g4c8340, note='batch31080')
S(0x46e590, 'GUESS sysobj table slot 0x58 with this+0x94', 'thiscall', None, ret='eax', gen=_sys_slot(0x58), note='batch31080')
S(0x533b80, 'GUESS sysobj member slot 0x160 with 0x1200', 'thiscall', None, ret='eax', gen=g533b80, note='batch31080')
S(0x591f00, 'GUESS sysobj table slot 0x58 with this+0x842', 'thiscall', None, ret='eax', gen=_sys_slot(0x58), note='batch31080')
S(0x654a20, 'GUESS vtable call 0x268 then sysobj slot 0x16c', 'thiscall', None, ret='eax', gen=g654a20, note='batch31080')
S(0x561c40, 'GUESS sysobj slot 0xbc result, tail slot 0xe0', 'thiscall', None, ret='eax', gen=g561c40, note='batch31080')
S(0x63cc40, 'GUESS forward arg to vtable slot 0x50', 'thiscall', None, ret='eax', gen=g63cc40, note='batch31080')
