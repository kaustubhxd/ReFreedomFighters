"""specs_s210023.py - Sonnet-w3a: chain with out-params, flag set + slots, stream record fetch; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g5c2d90(c):
    clear_hooks(c)
    t = rnd(c, 0x80)
    b = rnd(c, 0x10); cc = rnd(c, 0x10)
    hook_rec(c, 0x5c2ec0, 0, ret=_r(c), this=True)
    hook_rec(c, 0x5c2f90, 0, ret=_r(c), this=True)
    hook_rec(c, 0x5c2e10, 1, ret=0 if c.rng.random() < 0.3 else rnd(c, 0x10), this=True)
    hook_rec(c, 0x5c2cb0, 0, ret=c.rng.choice([0xffffffff, 0, 1, 2, 3]), this=True)
    hook_rec(c, 0x5c2f30, 0, ret=(_r(c) | 0xff) if c.rng.random() < 0.4 else _r(c), this=True)
    return [t, 0 if c.rng.random() < 0.2 else _r(c) | 1, b, cc]


def g5d92e0(c):
    clear_hooks(c)
    r = 0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x258: pystub(c, 2, ret=_r(c), this=True, deref={0: 2})}, nslots=0x90)
    e = obj(c, 0x80, {0x25c: pystub(c, 2, ret=r, this=True)}, nslots=0xa0)
    a = obj(c, 0x80, {0x20: pystub(c, 0, ret=e, this=True), 0x27c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0xa0)
    mgr = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr)
    c.emu.w32(0x70039c, eng)
    return [a]


def g603e40(c):
    clear_hooks(c)
    _assert_hook(c)
    hook_rec(c, 0x42ab62, 1, ret=_r(c), pop=0)
    arr = rnd(c, 0x100)
    cap = c.rng.choice([2, 4, 5, 6])
    cnt = c.rng.choice([0, 1, 2, 3, 6])
    st = rnd(c, 0x20); c.emu.w32(st, arr); c.emu.w32(st + 4, cap); c.emu.w32(st + 8, cnt)
    rec = arr + cnt * 8
    c.emu.wbytes(rec + 4, bytes([c.rng.choice([0, 4, 4, 1, 2])]))
    c.emu.w32(rec, obj(c, 0x40, {0x28: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20))
    this = rnd(c, 0x20); c.emu.w32(this, st)
    a = obj(c, 0x40, {0x24: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20)
    return [this, a]


S(0x5c2d90, 'lookup_index_fill_outparams', 'thiscall', None, ret='eax', gen=g5c2d90, note='batch210023')
S(0x5d92e0, 'set_flag_slots_engine', 'stdcall', None, ret='eax', gen=g5d92e0, note='batch210023')
S(0x603e40, 'stream_record_fetch', 'thiscall', None, ret='eax', gen=g603e40, note='batch210023')
