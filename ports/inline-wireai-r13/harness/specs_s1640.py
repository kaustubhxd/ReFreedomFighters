"""specs_s1640.py - residue 13 batch 1640: ZActor::UpdateBlockers (whole function, multi-batch job).
The actor is a 0x800-byte record with the vtable slots the function calls (recorders). The move object (+0x6c6), its
inner object (+4), the list object (+0x695, table at +0xc with 3-word entries) and the database/root objects are stubs.
Exe callees 0x487440, 0x47ad60, 0x47aad0, 0x477740, 0x487550, 0x41e680 and the global-object calls are hooked; the
vector subtract 0x43e920 and vnorm 0x44c840 run as exe code (vnorm's st0 result is the float the stub returns)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook, HOOKED


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _setf(c, s, off, v):
    c.emu.w32(s + off, _f(v))


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    for a in (0x487440, 0x47ad60, 0x47aad0, 0x477740, 0x487550, 0x41e680):
        pass
    hook(c, seq, 0x487440, 1, this=False, pop=True)   # ECX is a stack buffer: not recorded
    hook(c, seq, 0x47ad60, 2, ret=r.choice([0, 1]), this=True, pop=True)
    hook(c, seq, 0x47aad0, 2, this=True, pop=True)
    hook(c, seq, 0x477740, 2, ret=r.choice([0, 1]), this=True, pop=True)
    hook(c, seq, 0x487550, 1, ret=r.choice([0, 1]), this=False, pop=True)   # ECX is a stack buffer
    hook(c, seq, 0x41e680, 0, ret=rnd(c, 8), this=True, pop=True)
    # the float global and the words the function reads
    c.emu.wf32(0x6ffa48, r.choice([0.0, 1.0, -1.0, r.uniform(-2, 2)]))
    c.emu.w16(0x6ffa38, r.choice([0, 1, 2, 3]))
    c.emu.w16(0x6ffa3c, r.choice([0, 1, 2, 3]))
    # the database with its object at +0xadc and the load slot
    db = obj(c, 0x1000, {0x4c: stub(c, seq, 2, ret=r.getrandbits(32))})   # +0xadc lies beyond 0x80
    adc = obj(c, 0x80, {0x218: stub(c, seq, 3, ret=r.getrandbits(32))})
    c.emu.w32(db + 0xadc, adc)
    sysobj(c, db=db)
    # the move object and its inner object
    inner = obj(c, 0x80, {0x128: stub(c, seq, 3, skip=(1,))})   # &loc4 is a stack address
    move = obj(c, 0x200, {0xc: stub(c, seq, 0, ret=r.choice([0, 1, 1, 2])), 4: stub(c, seq, 1, skip=(0,))})   # the out buffer is a stack address
    c.emu.w32(move + 4, inner)
    # the list object at +0x695 with its table pointer at +0xc
    tbl = rnd(c, 0x400)
    lst = obj(c, 0x80, {})
    c.emu.w32(lst + 0xc, tbl)
    for i in range(0, 64):
        _setf(c, tbl, 0x14 + i * 8, r.uniform(-300, 300))
        _setf(c, tbl, 0x18 + i * 8, r.uniform(-300, 300))
        _setf(c, tbl, 0x1c + i * 8, r.uniform(-300, 300))
    vnorm_stub = None
    # the actor
    a = rnd(c, 0x1000)
    vt = obj(c, 0x800, {0x128: stub(c, seq, 2), 0x5f4: stub(c, seq, 0), 0x84: stub(c, seq, 1, skip=(0,)),
                        0x620: stub(c, seq, 3), 0x628: stub(c, seq, 3)})
    c.emu.w32(a, c.emu.r32(vt))
    c.emu.w32(a + 0x6c6, move if r.random() < 0.7 else 0)
    _setf(c, a, 0x6ca, r.uniform(-100, 300))
    _setf(c, a, 0x722, r.uniform(-100, 300))
    c.emu.w8(a + 0x730, r.choice([0, 0, 1]))
    c.emu.w8(a + 0x731, r.choice([0, 0, 1]))
    c.emu.w16(a + 0x6d2, r.choice([0, 1, 2, 3, 5]))
    c.emu.w32(a + 0x64c, r.choice([0, 1, 0xa, 0xb, 3]))
    _setf(c, a, 0x6d6, r.uniform(-100, 300))
    c.emu.w32(a + 0x695, lst if r.random() < 0.9 else 0)
    c.emu.w32(a + 0x6ce, r.getrandbits(32))
    c.emu.w32(a + 0x73e, obj(c, 0x40, {0x20: stub(c, seq, 1), 4: stub(c, seq, 1)}))
    c.emu.w16(a + 0x6d4, r.choice([0, 1, 2, 3, 4, 5]))
    _setf(c, a, 0x6ea, r.uniform(-300, 300))
    _setf(c, a, 0x6de, r.uniform(-300, 300))
    dt = _f(r.uniform(0, 0.1))
    return [a, dt]


S(0x47c690, 'ZActor::UpdateBlockers', 'thiscall', None, ret=None, gen=_gen, note='batch1640')
