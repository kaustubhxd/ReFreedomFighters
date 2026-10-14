"""specs_s32090.py - h2 () batch 32090: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs; call order pinned with calllog side effects."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _g_tail(slot, nargs, thunk, thunk_args, thunk_pop):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, thunk, thunk_args, this=True, pop=thunk_pop, side=_log('thunk'))
        o = obj(c, 0x20, {slot: pystub(c, nargs, ret=r.getrandbits(32), this=True, side=_log('tail'))}, nslots=slot // 4 + 1)
        sysobj(c, table_slots={0x58: pystub(c, 1, ret=(o if r.random() < 0.75 else 0), this=True, side=_log('tbl'))})
        me = rnd(c, 0x40)
        return [me] + [r.getrandbits(32) for _ in range(nargs)]
    return g


def g4abc00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4ad3a0, 1, this=True, pop=4, side=_log('a'))
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0x14, pystub(c, 0, ret=r.choice([0, 1, r.getrandbits(32)]), this=True))
    e.w32(vt + 0xc, pystub(c, 0, ret=r.getrandbits(32), this=True, side=_log('tail')))
    me = rnd(c, 0x90)
    e.wbytes(me + 0x6e, vt.to_bytes(4, 'little'))
    return [me]


def g4b16e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e6330, 1, this=True, pop=4, side=_log('a'))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('b'))
    hook_rec(c, 0x4e5e40, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('c'))
    return [rnd(c, 0x100), rnd(c, 0x20)]


def g4f70a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    r2 = obj(c, 0x20, {0x330: pystub(c, 1, this=True, side=_log('c'))}, nslots=0x330 // 4 + 1)
    o = obj(c, 0x20, {0xb8: pystub(c, 1, this=True, side=_log('a'))}, nslots=0xb8 // 4 + 1)
    so = sysobj(c)
    e.wbytes(so + 0x190f, o.to_bytes(4, 'little'))
    me = obj(c, 0xb0, {0x2c4: pystub(c, 0, ret=r2, this=True, side=_log('b'))}, nslots=0x2c4 // 4 + 1)
    e.wbytes(me + 0x93, r.choice([0, 0, r.getrandbits(32), 1]).to_bytes(4, 'little'))
    return [me]


def g567050(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562440, 0, this=True, pop=0, side=_log('a'))
    hook_rec(c, 0x563510, 1, this=True, pop=4, ret=r.getrandbits(32), side=_log('b'))
    hook_rec(c, 0x563610, 1, this=True, pop=4, side=_log('c'))
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('d'))})
    return [rnd(c, 0x1a0)]


def g5ceb70(c):
    clear_hooks(c)
    r = c.rng
    for i, a in enumerate((0x5d0f10, 0x5d2eb0, 0x5d2ab0, 0x5d1530, 0x5d2080, 0x5d2280, 0x5cd890)):
        hook_rec(c, a, 0, this=True, pop=0, side=_log(str(i)))
    hook_rec(c, 0x5ce0b0, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('tail'))
    return [rnd(c, 0xb60)]


def g608d60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x658140, 0, this=True, pop=0)
    e.wbytes(0x724b34, bytes([r.choice([0, 0, 0, 1])]))
    e.w32(0x724a00, r.getrandbits(32))
    me = rnd(c, 0x1400)
    alt = rnd(c, 0x20)

    def side(emu, k):
        if r.random() < 0.6:
            emu.wbytes(me + 0x1377, alt.to_bytes(4, 'little'))
    o = obj(c, 0x20, {0x88: pystub(c, 1, ret=r.choice([0, 1, 0x80000000, 0xffffffff, r.getrandbits(32)]), side=side)}, nslots=0x88 // 4 + 1)
    e.wbytes(me + 0x1377, o.to_bytes(4, 'little'))
    return [me]


S(0x47fad0, 'GUESS thunk then table lookup tail slot 0x70', 'thiscall', None, ret='eax', gen=_g_tail(0x70, 1, 0x45fd20, 1, 4), note='batch32090')
S(0x47fa90, 'GUESS thunk then table lookup tail slot 0x74', 'thiscall', None, ret='eax', gen=_g_tail(0x74, 2, 0x45fc80, 2, 8), note='batch32090')
S(0x4abc00, 'GUESS embedded object check then notify, tail slot 0xc', 'thiscall', None, ret='eax', gen=g4abc00, note='batch32090')
S(0x4b16e0, 'GUESS copy fields from 4e6330/4e5e60/4e5e40', 'thiscall', None, ret=None, gen=g4b16e0, note='batch32090')
S(0x4f70a0, 'GUESS release pending id through engine object', 'thiscall', None, ret=None, gen=g4f70a0, note='batch32090')
S(0x567050, 'GUESS init sequence with table slot 0x58', 'thiscall', None, ret='eax', gen=g567050, note='batch32090')
S(0x5ceb70, 'GUESS init sequence of seven, tail 5ce0b0', 'thiscall', None, ret='eax', gen=g5ceb70, note='batch32090')
S(0x608d60, 'GUESS try acquire via slot 0x88, bool', 'thiscall', None, ret='al', gen=g608d60, note='batch32090')
