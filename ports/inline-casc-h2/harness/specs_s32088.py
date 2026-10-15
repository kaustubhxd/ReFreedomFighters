"""specs_s32088.py - h2 (Sonnet) batch 32088: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs. Call order is pinned with calllog side effects."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g486d90(c):
    clear_hooks(c)
    r = c.rng

    def side(emu, k):
        if r.random() < 0.7:
            emu.w32(emu.arg32(0), r.getrandbits(32))
    o = obj(c, 0x20, {0x40: pystub(c, 1, this=True, nullflag=(0,), side=side)})
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x20), o]


def g49eed0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('a'))
    hook_rec(c, 0x4e5e40, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('c'))
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('b'))})
    return [rnd(c, 0x60), rnd(c, 0x20)]


def g533b50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x537ed0, 1, this=True, pop=4, side=_log('b'))
    p = obj(c, 0x20, {0xc: pystub(c, 1, this=True, side=_log('a'))})
    return [rnd(c, 0x20), p]


def g54dca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0x90, {0x5c: pystub(c, 0, this=True), 0x58: pystub(c, 0, this=True)})
    e.wbytes(me + 0x79, bytes([r.choice([0, 1, 2, 0x80])]))
    return [me, r.choice([0, 1, r.getrandbits(32)])]


def g5c94f0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x2f4: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x2f4 // 4 + 1)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True), 0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x90)]


def g603eb0(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    inner = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0)})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True)})
    c.emu.w32(0x700390, g)
    return []


def g65c500(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    d = obj(c, 0x20, {4: pystub(c, 2, this=True)})
    cc = rnd(c, 0x40)
    e.w32(cc + 0x18, d if r.random() < 0.7 else 0)
    a = rnd(c, 0x20)
    e.w32(a + 8, cc if r.random() < 0.8 else 0)
    me = rnd(c, 0x10070)
    return [me, a, r.getrandbits(32)]


def g462f50(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x2cc: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x2cc // 4 + 1)
    return [me, r.choice([0, 1, 5, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32), r.randrange(0, 1000)])]


S(0x486d90, 'GUESS out-param slot 0x40 then table slot 0x58', 'thiscall', None, ret=None, gen=g486d90, note='batch32088')
S(0x49eed0, 'GUESS store 4e5e60 result and 4e5e40 word', 'thiscall', None, ret=None, gen=g49eed0, note='batch32088')
S(0x533b50, 'GUESS slot 0xc(0x14) then 537ed0, true', 'thiscall', None, ret='al', gen=g533b50, note='batch32088')
S(0x54dca0, 'GUESS toggle flag with slots 0x5c / 0x58', 'thiscall', None, ret=None, gen=g54dca0, note='batch32088')
S(0x5c94f0, 'GUESS table slot 0x58, 0x2f4, table slot 0x4c', 'thiscall', None, ret='eax', gen=g5c94f0, note='batch32088')
S(0x603eb0, 'GUESS log call then assert hook, return 0', 'cdecl', None, ret='eax', gen=g603eb0, note='batch32088')
S(0x65c500, 'GUESS slot 4 of nested member', 'thiscall', None, ret=None, gen=g65c500, note='batch32088')
S(0x462f50, 'GUESS slot 0x2cc + i*0x30 + 0x1c', 'thiscall', None, ret='eax', gen=g462f50, note='batch32088')
