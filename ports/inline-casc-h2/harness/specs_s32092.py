"""specs_s32092.py - h2 () batch 32092: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs; order pinned with calllog side effects."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g5f4f70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    n = r.choice([0, 1, 2, 4])
    arr = rnd(c, 8 * 5 + 8)
    for i in range(5):
        kind = r.choice([0, 4, 4, 1])
        e.wbytes(arr + 8 * i + 4, bytes([kind]))
        o = obj(c, 0x20, {0x28: pystub(c, 0, this=True, side=_log('rel%d' % i))})
        e.w32(arr + 8 * i, o)
    me = rnd(c, 0x20)
    e.w32(me, arr)
    e.w32(me + 8, n)
    return [me]


def g63cde0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    nodes = [rnd(c, 0x20) for _ in range(n)]
    circular = r.random() < 0.5
    for i, a in enumerate(nodes):
        nxt = nodes[i + 1] if i + 1 < n else (nodes[0] if circular else 0)
        e.w32(a + 8, nxt)
    me = obj(c, 0x40, {0x34: pystub(c, 1, this=True, side=_log('n'))}, nslots=0x34 // 4 + 1)
    e.w32(me + 8, nodes[0] if nodes else 0)
    e.w32(me + 0xc, r.getrandbits(32))
    return [me]


def g45fa30(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x168: pystub(c, 2, this=True, side=_log('a')), 0x124: pystub(c, 4, ret=r.getrandbits(32), this=True, side=_log('b'))}, nslots=0x168 // 4 + 1)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g47fba0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {8: pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True)})
    me = obj(c, 0x40, {0x14: pystub(c, 0, this=True)})
    return [me, o]


def g4d1cb0(c):
    clear_hooks(c)
    r = c.rng
    rec = rnd(c, 0x20)
    hook_rec(c, 0x4d1cf0, 1, this=True, pop=4, ret=(rec if r.random() < 0.6 else 0))
    inner = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), pop=0)})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True)})
    c.emu.w32(0x700390, g)
    return [rnd(c, 0x20), r.getrandbits(32)]


def g51fa10(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x514480, 1, this=True, pop=4, ret=r.getrandbits(32))
    me = obj(c, 0x1700, {0x310: pystub(c, 1, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True)}, nslots=0x310 // 4 + 1)
    return [me, r.getrandbits(32)]


def g591080(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x20)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=s, this=True)})
    hook_rec(c, 0x4dcbb0, 1, this=True, pop=4, side=_log('a'))
    me = obj(c, 0x860, {0x294: pystub(c, 2, this=True, side=_log('b'))}, nslots=0x294 // 4 + 1)
    return [me]


def g5c5cc0(c):
    clear_hooks(c)
    o = obj(c, 0x20, {0x40: pystub(c, 1, this=True, side=_log('a')), 0x48: pystub(c, 1, this=True, side=_log('b'))})
    return [rnd(c, 0x60), o]


S(0x5f4f70, 'GUESS pop stack entry and release it', 'thiscall', None, ret=None, gen=g5f4f70, note='batch32092')
S(0x63cde0, 'GUESS release all list nodes (circular-safe)', 'thiscall', None, ret=None, gen=g63cde0, note='batch32092')
S(0x45fa30, 'GUESS slot 0x168 then slot 0x124', 'thiscall', None, ret='eax', gen=g45fa30, note='batch32092')
S(0x47fba0, 'GUESS set owner, check slot 8, else slot 0x14', 'thiscall', None, ret='al', gen=g47fba0, note='batch32092')
S(0x4d1cb0, 'GUESS lookup field or log and return 0', 'thiscall', None, ret='eax', gen=g4d1cb0, note='batch32092')
S(0x51fa10, 'GUESS accept via slot 0x310, forward', 'thiscall', None, ret='eax', gen=g51fa10, note='batch32092')
S(0x591080, 'GUESS detach looked-up object', 'thiscall', None, ret='eax', gen=g591080, note='batch32092')
S(0x5c5cc0, 'GUESS clear bit 6, slot 0x40/0x48 with field addresses, true', 'thiscall', None, ret='al', gen=g5c5cc0, note='batch32092')
