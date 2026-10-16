"""specs_s210028.py - Sonnet-w3a: typed lookup offset, tag check with report, slot chain, serializers; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g5a4610(c):
    clear_hooks(c)
    meta = rnd(c, 0x10); c.emu.w32(meta + 4, c.rng.choice([2, 3, 4, 5, 8, 9, 10, 0, 0xfffffffe, 0x80000000]))
    o = 0 if c.rng.random() < 0.2 else obj(c, 0x70, {0x1e0: pystub(c, 1, ret=lambda e, k: c.rng.choice([0, 1, 0x100, 5]), this=True)}, nslots=0x90)
    if o: c.emu.w32(o + 0x54, meta)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x20))
    return [rnd(c, 0x20), _r(c)]


def g512940(c):
    clear_hooks(c)
    x = obj(c, 0x40, {0x2c: pystub(c, 0, ret=_r(c), this=True), 0x2f0: pystub(c, 1, ret=_r(c), this=True), 0xbc: pystub(c, 1, ret=_r(c), this=True)}, nslots=0xc0)
    o = obj(c, 0x40, {0x2c4: pystub(c, 2, ret=x, this=True)}, nslots=0xb2)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=o, this=True), 0x4c: pystub(c, 3, ret=_r(c), this=True)}, nslots=0x60))
    return [rnd(c, 0x20), _r(c), c.rng.choice([0, 0, _r(c)]), _r(c)]


def g5b7c00(c):
    clear_hooks(c)

    def side(emu, k):
        emu.w32(emu.arg32(0), c.rng.getrandbits(32))
    r = obj(c, 0x40, {0x6c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    a = obj(c, 0x40, {0x50: pystub(c, 1, ret=_r(c), this=True), 0x6c: pystub(c, 1, ret=r, this=True),
                      0x68: pystub(c, 1, ret=_r(c), this=True), 0x40: pystub(c, 1, ret=_r(c), this=True, deref={0: 1}, side=side)}, nslots=0x20)
    return [rnd(c, 0x40), a]


def g5d4020(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x44: pystub(c, 1, ret=_r(c), this=True), 0x3c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    return [rnd(c, 0x90), a]


def g4e0f60(c):
    clear_hooks(c)
    _assert_hook(c)
    buf = rnd(c, 0x20)
    c.emu.wbytes(buf, bytes([c.rng.choice([7, 9, 0xc, 0x47, 0x49, 0x4c, 0xff, 0x01, 0x3f, 0x87])]))
    t = rnd(c, 0x20); c.emu.w32(t + 8, buf)
    hook_rec(c, 0x4e1590, 0, ret=c.rng.randrange(0, 20), this=True)
    g = obj(c, 0x40, {0x24: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    return [t, rnd(c, 8)]


S(0x5a4610, 'typed_lookup_offset', 'thiscall', None, ret='eax', gen=g5a4610, note='batch210028')
S(0x512940, 'create_object_chain', 'thiscall', None, ret='eax', gen=g512940, note='batch210028')
S(0x5b7c00, 'serialize_with_outparam', 'thiscall', None, ret='eax', gen=g5b7c00, note='batch210028')
S(0x5d4020, 'serialize_nine_fields', 'thiscall', None, ret='eax', gen=g5d4020, note='batch210028')
S(0x4e0f60, 'tag_check_or_report', 'thiscall', None, ret='eax', gen=g4e0f60, note='batch210028')
