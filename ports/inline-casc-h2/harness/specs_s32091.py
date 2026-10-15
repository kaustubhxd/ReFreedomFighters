"""specs_s32091.py - h2 (Sonnet) batch 32091: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs; order pinned with calllog side effects."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g49ef50(c):
    clear_hooks(c)
    o = obj(c, 0x20, {0x3c: pystub(c, 1, this=True, side=_log('a')), 0x40: pystub(c, 1, this=True, side=_log('b'))})
    return [rnd(c, 0x60), o]


def g4c2780(c):
    clear_hooks(c)
    r = c.rng
    r2 = obj(c, 0x20, {0x44: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('c'))})
    r1 = obj(c, 0x20, {0x44: pystub(c, 1, ret=r2, this=True, side=_log('b'))})
    o = obj(c, 0x20, {0x3c: pystub(c, 1, ret=r1, this=True, side=_log('a'))})
    return [rnd(c, 0x1e0), o]


def g4cdc20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    nodes = [rnd(c, 0x10) for _ in range(n)]
    for a, b in zip(nodes, nodes[1:]):
        e.w32(a + 4, b)
    if nodes:
        e.w32(nodes[-1] + 4, 0)
    me = obj(c, 0x40, {0x10: pystub(c, 0, this=True, side=lambda emu, k: emu.calllog.append(('x', emu.r32(emu.reg('ecx') + 0xc)))), 0x7c: pystub(c, 1, this=True, side=_log('n'))}, nslots=0x7c // 4 + 1)
    e.w32(me + 4, nodes[0] if nodes else 0)
    return [me]


def _g_518(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    if r.random() < 0.8:
        o = obj(c, 0x20, {0x60: pystub(c, 2, ret=r.getrandbits(32), this=True)})
        e.wbytes(so + 0x1a9f, o.to_bytes(4, 'little'))
    else:
        e.wbytes(so + 0x1a9f, bytes(4))
    me = obj(c, 0x140, {0x2e8: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x2e8 // 4 + 1)
    e.wbytes(me + 0x12f, r.getrandbits(32).to_bytes(4, 'little'))
    return [me]


def g537340(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x1d8: pystub(c, 2, ret=r.choice([0, r.getrandbits(32)]), this=True, side=_log('a')),
                       0x54: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('b'))}, nslots=0x1d8 // 4 + 1)
    return [me, r.getrandbits(32), r.getrandbits(32)]


def g566ea0(c):
    clear_hooks(c)
    r = c.rng
    seq = [r.getrandbits(32) for _ in range(3)]
    hook_rec(c, 0x610100, 1, this=True, pop=4, side=_log('first'))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: seq[min(k, 2)], side=_log('v'))
    return [rnd(c, 0x1a0), rnd(c, 0x20)]


def g5cf3e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45bfd0, 1, this=True, pop=4, side=_log('a'))
    o = obj(c, 0x20, {0x88: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('c'))}, nslots=0x88 // 4 + 1)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=(o if r.random() < 0.75 else 0), this=True, side=_log('b'))})
    me = rnd(c, 0xba8)
    return [me, r.getrandbits(32)]


S(0x49ef50, 'GUESS clear bit 6, slot 0x3c, slot 0x40 (word), true', 'thiscall', None, ret='al', gen=g49ef50, note='batch32091')
S(0x4c2780, 'GUESS clear bit 6, chained slot calls, true', 'thiscall', None, ret='al', gen=g4c2780, note='batch32091')
S(0x4cdc20, 'GUESS release all list nodes', 'thiscall', None, ret=None, gen=g4cdc20, note='batch32091')
S(0x518750, 'GUESS engine object slot 0x60 then own slot 0x2e8 (A)', 'thiscall', None, ret='eax', gen=_g_518, note='batch32091')
S(0x518810, 'GUESS engine object slot 0x60 then own slot 0x2e8 (B)', 'thiscall', None, ret='eax', gen=_g_518, note='batch32091')
S(0x537340, 'GUESS slot 0x1d8 then slot 0x54', 'thiscall', None, ret='eax', gen=g537340, note='batch32091')
S(0x566ea0, 'GUESS copy three values from 4e5e60', 'thiscall', None, ret=None, gen=g566ea0, note='batch32091')
S(0x5cf3e0, 'GUESS member init then table lookup tail slot 0x88', 'thiscall', None, ret='eax', gen=g5cf3e0, note='batch32091')
