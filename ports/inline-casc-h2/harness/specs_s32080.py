"""specs_s32080.py - h2 (Sonnet) batch 32080: eight tier C thunks. Slots and imports are recorder stubs; the assert hook 0x7003b0 is always set (random EAX)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g46ed30(c):
    clear_hooks(c)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=c.rng.getrandbits(32), this=True)})
    return [rnd(c, 0xa0)]


def g54ab50(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x701b68, r.getrandbits(32))
    c.emu.w32(0x676144, pystub(c, 2, ret=r.choice([0, 1, r.getrandbits(32)])))
    return []


def g5da650(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x44, obj(c, 0x20, {0xbc: pystub(c, 1, ret=r.getrandbits(32), this=True)}))
    return [me]


def g465fb0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x461c40, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [obj(c, 0x40, {0x410: pystub(c, 0, ret=r.getrandbits(32), this=True)})]


def g4ced80(c):
    clear_hooks(c)
    _assert_hook(c)
    return [c.rng.getrandbits(32)]


def g6044c0(c):
    clear_hooks(c)
    _assert_hook(c)
    return []


def g426ad0(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676100, pystub(c, 1, ret=r.choice([0, 1, r.getrandbits(32)])))
    return [r.getrandbits(32)]


def g50d750(c):
    clear_hooks(c)
    r = c.rng
    if r.random() < 0.7:
        c.emu.w32(0x7012cc, obj(c, 0x20, {4: pystub(c, 1, this=True)}))
    else:
        c.emu.w32(0x7012cc, 0)
    return []


S(0x46ed30, 'GUESS engine table slot 0x58([this+0x90])', 'thiscall', None, ret='eax', gen=g46ed30, note='batch32080')
S(0x54ab50, 'GUESS import(0x701b68,0)==0', 'cdecl', None, ret='al', gen=g54ab50, note='batch32080')
S(0x5da650, 'GUESS clear +0x4c, slot 0xbc(1)', 'thiscall', None, ret='eax', gen=g5da650, note='batch32080')
S(0x465fb0, 'GUESS slot 0x410 then tail jump', 'thiscall', None, ret='eax', gen=g465fb0, note='batch32080')
S(0x4ced80, 'GUESS assert hook, AL=0', 'stdcall', None, ret='eax', gen=g4ced80, note='batch32080')
S(0x6044c0, 'GUESS assert hook, return 0', 'cdecl', None, ret='eax', gen=g6044c0, note='batch32080')
S(0x426ad0, 'GUESS import(a)!=0', 'stdcall', None, ret='al', gen=g426ad0, note='batch32080')
S(0x50d750, 'GUESS release global object', 'cdecl', None, ret=None, gen=g50d750, note='batch32080')
