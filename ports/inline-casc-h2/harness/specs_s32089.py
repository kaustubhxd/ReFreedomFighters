"""specs_s32089.py - h2 (Sonnet) batch 32089: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs; call order pinned with calllog side effects."""
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


def g476bd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, side=_log('tbl'))})
    me = obj(c, 0x90, {0x28: pystub(c, 0, ret=r.getrandbits(32), this=True, side=_log('tail'))})
    if r.random() < 0.5:
        e.wbytes(me + 0x72, bytes(1))
    return [me]


def g52a2c0(c):
    clear_hooks(c)
    hook_rec(c, 0x52a370, 3, this='mark', pop=0xc, side=_log('init'))
    hook_rec(c, 0x52a600, 0, this='mark', pop=0, side=_log('fini'))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    return []


def g54a680(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x100)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    c.emu.w32(0x700394, obj(c, 0x20, {0x60: pystub(c, 5, ret=r.getrandbits(32), this=True)}, nslots=0x60 // 4 + 1))
    return [rnd(c, 0xa280), r.choice([0, 1, r.randrange(0, 0x100)]), r.getrandbits(32)]


def g563400(c):
    clear_hooks(c)
    r = c.rng

    def side(emu, k):
        if r.random() < 0.6:
            emu.w32(emu.arg32(1), r.choice([0, 1, r.getrandbits(32)]))
    o = obj(c, 0x20, {0x88: pystub(c, 2, this=True, nullflag=(1,), side=side)}, nslots=0x88 // 4 + 1)
    sysobj(c, table_slots={0x134: pystub(c, 0, ret=o, this=True)})
    return []


def g5d5940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5f09b0, 0, this=True, pop=0, side=_log('a'))
    me = obj(c, 0x60, {0x114: pystub(c, 1, this=True, side=_log('b'))}, nslots=0x114 // 4 + 1)
    e.wbytes(me + 0x19, rnd(c, 0x10).to_bytes(4, 'little'))
    e.wbytes(me + 0x31, bytes([r.choice([0, 1, 5])]))
    e.wbytes(me + 0x2d, r.choice([0, 1, 2, 3, 0xffffffff, r.getrandbits(32)]).to_bytes(4, 'little'))
    return [me]


def g656420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = obj(c, 0x20, {0x18: pystub(c, 2, this=True)})
    o = obj(c, 0x20, {0x20: pystub(c, 0, ret=t, this=True)})
    so = sysobj(c)
    e.wbytes(so + 0x190f, o.to_bytes(4, 'little'))
    return [r.getrandbits(32), r.choice([0, 1, 5, 0x20000000, r.getrandbits(32), r.randrange(0, 100)])]


def g4639f0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x90, {0x2f8: pystub(c, 1, this=True, side=_log('a')), 0x330: pystub(c, 0, this=True, side=_log('b'))}, nslots=0x330 // 4 + 1)
    return [me]


def g474690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rr = obj(c, 0x20, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True)}, nslots=0x1e0 // 4 + 1)
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0x10, pystub(c, 0, ret=(rr if r.random() < 0.75 else 0), this=True))
    me = rnd(c, 0x360)
    e.wbytes(me + 0x34f, vt.to_bytes(4, 'little'))
    return [me]


S(0x476bd0, 'GUESS assert unless flag, table slot 0x4c, tail slot 0x28', 'thiscall', None, ret='eax', gen=g476bd0, note='batch32089')
S(0x52a2c0, 'GUESS /GS frame init + fini of local', 'cdecl', None, ret=None, gen=g52a2c0, note='batch32089')
S(0x54a680, 'GUESS alloc buffer, store, slot 0x60', 'thiscall', None, ret='eax', gen=g54a680, note='batch32089')
S(0x563400, 'GUESS query out-param nonzero', 'cdecl', None, ret='al', gen=g563400, note='batch32089')
S(0x5d5940, 'GUESS tick counter, notify at 2', 'thiscall', None, ret=None, gen=g5d5940, note='batch32089')
S(0x656420, 'GUESS engine object slot 0x18(a, n*8)', 'stdcall', None, ret=None, gen=g656420, note='batch32089')
S(0x4639f0, 'GUESS two slots then shift saved fields', 'thiscall', None, ret=None, gen=g4639f0, note='batch32089')
S(0x474690, 'GUESS embedded object lookup filtered by slot 0x1e0', 'thiscall', None, ret='eax', gen=g474690, note='batch32089')
