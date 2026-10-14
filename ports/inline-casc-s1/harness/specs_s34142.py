"""specs_s34142.py - both: vector {data, cap, size} with size around cap, the data area prefilled with slots whose kind byte is 0, 1, 4 (kind 4 -> an object with slots 0x24 / 0x28) or other; error print 0x42ab62 (cdecl) hooked, assert hook word at 0x7003b0 a recorder.
0x5f5490 (src, count 0..3): src a record of kind 4 or other, sometimes equal to the destination slot. 0x5f9010: embedded object at this+0xaca (vtable pointer there, slot 0 returns s with slots 0x30, 0x24, 0x28), word at +0x1a."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _common(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x42ab62, 1, pop=0)


def _recobj(c):
    r = c.rng
    return obj(c, 0x20, {0x24: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)), 0x28: pystub(c, 0, this=True)}, nslots=0x2c // 4)


def _vec(c, data_slots=12):
    r = c.rng
    e = c.emu
    data = rnd(c, 8 * data_slots + 8)
    for i in range(data_slots):
        kind = r.choice([0, 1, 4, 4, 7])
        e.w32(data + 8 * i, _recobj(c) if kind == 4 else r.getrandbits(32))
        e.wbytes(data + 8 * i + 4, bytes([kind]))
    cap = r.choice([1, 2, 3, 4, 6])
    size = r.choice([0, 1, 2, cap - 1, cap, cap + 1])
    return data, cap, max(size, 0)


def _g5f5490(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _common(c)
    data, cap, size = _vec(c)
    me = rnd(c, 0x10)
    e.w32(me, data)
    e.w32(me + 4, cap)
    e.w32(me + 8, size)
    count = r.choice([0, 1, 2, 3])
    if r.random() < 0.15 and size < 8:
        src = data + 8 * size
    else:
        src = rnd(c, 0x10)
        kind = r.choice([0, 1, 4, 4, 9])
        e.w32(src, _recobj(c) if kind == 4 else r.getrandbits(32))
        e.wbytes(src + 4, bytes([kind]))
    return [me, src, count]


def _g5f9010(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _common(c)
    s = obj(c, 0x20, {0x30: pystub(c, 1, this=True), 0x24: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)),
                      0x28: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))}, nslots=0x34 // 4)
    vt = c.emu.alloc(0x20, 4)
    e.w32(vt, pystub(c, 2, this=True, ret=s))
    data, cap, size = _vec(c)
    me = rnd(c, 0xad0)
    e.w32(me + 0x34, data)
    e.w32(me + 0x38, cap)
    e.w32(me + 0x3c, size)
    e.wbytes(me + 0xaca, vt.to_bytes(4, 'little'))
    e.wbytes(me + 0x1a, r.getrandbits(32).to_bytes(4, 'little'))
    return [me]


S(0x5f5490, 'GUESS copy records into a vector', 'thiscall', None, ret=None, gen=_g5f5490, note='batch34142')
S(0x5f9010, 'GUESS push a ref-counted record', 'thiscall', None, ret='eax', gen=_g5f9010, note='batch34142')
