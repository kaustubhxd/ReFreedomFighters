"""specs_s32133.py - h2 () batch 32133: 0x470720, 0x4f8510, 0x52ab00. Callees/slots are recorders; 0x4db500 runs as exe code."""
import struct
from pilot import S, F
from unicorn.x86_const import UC_X86_REG_EDX
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def g470720(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x441790, 1, this=True, pop=4)
    slots = {off: pystub(c, 1, this=True) for off in (0x6c, 0x70, 0x68, 0x4c, 0x64)}
    o = obj(c, 0x20, slots, nslots=0x70 // 4 + 1)
    me = rnd(c, 0x140)
    for off in (0x10b, 0x10f):
        e.wbytes(me + off, struct.pack('<I', r.choice([NAN, _bits(r.uniform(-9, 9)), 0, 0x7f800000, r.getrandbits(32)])))
    return [me, o]


def g4f8510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0)
    me = obj(c, 0x200, {0x358: pystub(c, 0, this=True)}, nslots=0x35c // 4)
    ent = obj(c, 0x40, {0x70: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x74 // 4)
    inner = rnd(c, 0x40)
    e.w32(ent + 8, inner)
    ptrs = r.random() < 0.9
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ent if ptrs else 0)})
    a = r.choice([r.randrange(-50, 50), r.randrange(-1000, 1000), 0, r.getrandbits(31), -r.getrandbits(31)]) & 0xffffffff
    fa = r.choice([0.0, 1.0, r.uniform(-30, 30), r.uniform(-1000, 1000), -2.0, 1e30])
    fb = r.choice([0.0, 1.0, r.uniform(-30, 30), r.uniform(-100, 100), 3.0, 1e30])
    e.wbytes(me + 0xa3, struct.pack('<I', _bits(fa)))
    e.wbytes(me + 0x9f, struct.pack('<I', _bits(fb)))
    e.wbytes(me + 0xa7, struct.pack('<I', a))
    e.wbytes(me + 0xab, struct.pack('<I', r.getrandbits(32)))
    # tmp[0] (the [inner+0x24] float) equal to the computed value in a share of the cases
    sa = struct.unpack('<i', struct.pack('<I', a))[0]
    try:
        t = struct.unpack('<f', struct.pack('<f', struct.unpack('<f', struct.pack('<f', fa))[0] * struct.unpack('<f', struct.pack('<f', fb))[0]))[0] - float(sa)
        t = struct.unpack('<f', struct.pack('<f', t))[0]
        ti = int(t) if abs(t) < 2 ** 31 else None
    except (OverflowError, ValueError):
        ti = None
    if ti is not None and r.random() < 0.4:
        v = _bits(float(ti))
    else:
        v = r.choice([r.getrandbits(32), NAN, _bits(r.uniform(-30, 30))])
    e.wbytes(inner + 0x24, struct.pack('<I', v))
    return [me, r.choice([0, 1, 2, 0x100, 0xff, r.getrandbits(32)])]


def g52ab00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def edx_set(emu, k):
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
        emu.calllog.append(('p1c8', emu.arg32(0), emu.arg32(1)))
    hook_rec(c, 0x52c000, 1, this=True, pop=4)
    fl = lambda: r.choice([0, 0x80000000, NAN, _bits(1.0), _bits(r.uniform(-5, 5)), r.getrandbits(32)])
    so = sysobj(c, slots={0x1c8: pystub(c, 2, this=True, ret=lambda emu, k: 0x100 + k, side=edx_set),
                          0x178: pystub(c, 3, this=True), 0x17c: pystub(c, 3, this=True)}, table_slots={})
    f1, f2 = fl(), fl()
    e.wbytes(so + 0x9c7, struct.pack('<I', f1))
    e.wbytes(so + 0x9c3, struct.pack('<I', f2))
    if r.random() < 0.4:   # the second pair of checks sees other values
        def flip(emu, k):
            emu.wbytes(so + 0x9c7, struct.pack('<I', fl()))
            emu.wbytes(so + 0x9c3, struct.pack('<I', fl()))
        hook_rec(c, 0x52c000, 1, this=True, pop=4, side=flip)
    return [rnd(c, 0x40)]


S(0x470720, 'GUESS apply settings to renderer object', 'thiscall', None, ret='al', gen=g470720, nan_heap=True, note='batch32133')
S(0x4f8510, 'GUESS sync entry value', 'thiscall', None, ret=None, gen=g4f8510, nan_heap=True, note='batch32133')
S(0x52ab00, 'GUESS profiled call wrapper', 'thiscall', None, ret=None, gen=g52ab00, nan_heap=True, note='batch32133')
