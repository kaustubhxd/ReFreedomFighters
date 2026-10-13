"""specs_f16b026.py - fresh slice 16 batch 26 (see src/f16b026.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, fval
import struct


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _4bd(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x469870, 0, this=True)
    db = obj(c, 0x200, {0x114: stub(c, seq, 4, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    return [rnd(c, 0x90)]


def _4e2(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    log = c.emu.alloc(4 * 16 * 8, 4)
    k = [0]

    def clip(e, a):
        # record the plane (stack) and src/dst offsets; return a count that sometimes reaches 0
        base = log + 32 * (k[0] % 16)
        e.wbytes(base, bytes(e.rbytes(a[0], 12)))
        e.w32(base + 12, e.reg('ecx'))
        e.w32(base + 16, e.reg('edx'))
        e.w32(base + 20, a[1])
        e.w32(base + 24, a[2])
        k[0] += 1
        return r.choice([0, 1, 3, 4, 5, a[2]]) if r.random() < 0.9 else 0
    phook(c, seq, 0x4e1c90, 3, pop=True, act=clip)
    n = r.choice([0, 1, 2, 3, 4, 5])
    ring = c.emu.alloc(12 * max(n, 1) + 12, 4)
    for i in range(3 * max(n, 1) + 3):
        c.emu.w32(ring + 4 * i, fval(c) if r.random() < 0.05 else _f(r.uniform(-50, 50)))
    nrm = c.emu.alloc(12, 4)
    for i in range(3):
        c.emu.w32(nrm + 4 * i, _f(r.uniform(-1, 1)))
    poly = rnd(c, 12 * max(n, 1) + 12)
    return [poly, ring, n, rnd(c, 0x40), r.choice([0, 1, 3, 6]), nrm]


def _551(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    rec = c.emu.alloc(4 * 16, 4)

    def get(e, a):
        return e.reg('ecx') + 0x100 * a[0]
    phook(c, seq, 0x5003d0, 1, this=True, pop=True, act=get)

    def setter(tag):
        def h(e, a):
            ec = e.reg('ecx')
            i = ((ec - arr) // 0x100) & 0xf
            e.w32(rec + 4 * i, a[0] ^ tag)
            e.w32(rec + 0x20 + 4 * i, e.r32(rec + 0x20 + 4 * i) + 1)
        return h
    phook(c, seq, 0x500360, 1, this=True, pop=True, act=setter(0x11111111))
    phook(c, seq, 0x5002f0, 1, this=True, pop=True, act=setter(0x22222222))
    arr = rnd(c, 0x10)
    t = obj(c, 0x80, {0x4c: stub(c, seq, 0, ret=arr)}) if r.random() < 0.85 else 0
    fac = obj(c, 0x40, {0x18: stub(c, seq, 1, ret=t)})
    data = c.emu.alloc(32, 4)
    for i in range(8):
        c.emu.w32(data + 4 * i, fval(c))
    return [rnd(c, 8), fac, r.getrandbits(32), data]


S(0x4bde40, 'FUN_4bde40 (ctor vtable 0x6937c4)', 'thiscall', None, ret='eax', gen=_4bd, note='f16b026; SEH not reproduced')
S(0x4e29c0, 'MakeInclusivePolygon', 'fastcall', None, ret='eax', gen=_4e2, note='f16b026; PSVECSubtract/vcross run as exe code')
S(0x551500, 'Signature_fffiiiif_EventTranslator_t::handleEventTranslation', 'thiscall', None, ret='eax', gen=_551, note='f16b026')
