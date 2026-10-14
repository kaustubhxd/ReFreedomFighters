"""specs_s32087.py - h2 () batch 32087: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs; the assert hook 0x7003b0 is always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _g_536(a_off, b_off):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        me = obj(c, 0x5320, {0x1b0: pystub(c, 3, ret=r.getrandbits(32), this=True)}, nslots=0x1b0 // 4 + 1)
        if r.random() < 0.25:
            e.wbytes(me + 0x5302, bytes(4))
        else:
            P = rnd(c, 0x80)
            e.w32(P, r.randrange(0, 0x20) * 4)
            e.wbytes(me + 0x5302, P.to_bytes(4, 'little'))
        return [me, r.getrandbits(32)]
    return g


def _g_cdecl_log(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    inner = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0)})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True)})
    c.emu.w32(0x700390, g)
    return [r.getrandbits(32), r.getrandbits(32)]


def g564b10(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562440, 0, this=True, pop=0, side=lambda emu, k: emu.calllog.append(('first',)))
    hook_rec(c, 0x564e80, 0, this=True, pop=0, side=lambda emu, k: emu.calllog.append(('second',)))
    o = obj(c, 0x20, {0x5c: pystub(c, 3, ret=r.getrandbits(32), this=True)})
    sysobj(c, table_slots={0x134: pystub(c, 0, ret=o, this=True)})
    return [rnd(c, 0x20)]


def g5d83e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5d8470, 0, this=True, pop=0)
    so = sysobj(c)
    ev = r.choice([0, 5, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)])
    e.w32(so + 0x40, ev)
    me = obj(c, 0xd0, {0x114: pystub(c, 1, this=True)}, nslots=0x114 // 4 + 1)
    e.w32(me + 0x44, obj(c, 0x20, {0x114: pystub(c, 1, this=True)}, nslots=0x114 // 4 + 1))
    if r.random() < 0.7:
        e.wbytes(me + 0xbb, b'\0')
    e.wbytes(me + 0xb3, r.choice([0, 3, ev, (ev - 1) & 0xffffffff, (ev + 1) & 0xffffffff, r.getrandbits(32)]).to_bytes(4, 'little'))
    if r.random() < 0.6:
        e.wbytes(me + 0xbc, bytes(4))
    return [me]


def g5ee6f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randrange(0, 5)
    arr = rnd(c, 4 * n + 8)
    for i in range(n):
        o = obj(c, 0x20, {8: pystub(c, 0, this=True)})
        cell = rnd(c, 8)
        e.w32(cell, o)
        e.w32(arr + 4 * i, cell)
    me = rnd(c, 0x90)
    e.wbytes(me + 5, arr.to_bytes(4, 'little'))
    e.wbytes(me + 9, (arr + 4 * n).to_bytes(4, 'little'))
    return [me]


def g441630(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x610100, 1, this=True, pop=4)
    res = rnd(c, 0x20) if r.random() < 0.7 else 0
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=res, this=True)})
    return [r.getrandbits(32)]


S(0x536720, 'GUESS slot 0x1b0 with record fields (+0x24,+0xc)', 'thiscall', None, ret='eax', gen=_g_536(0x24, 0xc), note='batch32087')
S(0x536920, 'GUESS slot 0x1b0 with record fields (+0x20,+8)', 'thiscall', None, ret='eax', gen=_g_536(0x20, 8), note='batch32087')
S(0x551020, 'GUESS log call then assert hook (A)', 'stdcall', None, ret='eax', gen=_g_cdecl_log, note='batch32087')
S(0x605890, 'GUESS log call then assert hook (B)', 'stdcall', None, ret='eax', gen=_g_cdecl_log, note='batch32087')
S(0x564b10, 'GUESS init then table slot 0x134 object slot 0x5c', 'thiscall', None, ret='eax', gen=g564b10, note='batch32087')
S(0x5d83e0, 'GUESS conditional update and notify', 'thiscall', None, ret=None, gen=g5d83e0, note='batch32087')
S(0x5ee6f0, 'GUESS notify all entries', 'thiscall', None, ret=None, gen=g5ee6f0, note='batch32087')
S(0x441630, 'GUESS lookup then 610100, true', 'stdcall', None, ret='al', gen=g441630, note='batch32087')
