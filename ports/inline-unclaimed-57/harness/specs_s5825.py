"""specs_s5825.py - unclaimed-57, batch 125: 0x5c3140, thiscall, no args, plain ret (GUESS name). Its callees 0x4de000 (stdcall, two floats, returns a float
in st0) and 0x5c3560 (thiscall, two stack args, ret 8) are hooked with logging stubs in each case: 0x4de000 returns a per-case float (equal to the value the code
just stored in about one case in three), and 0x5c3560 writes nothing. The engine (global 0x70039c) has the limit at +0x40 and a float at +0x48. The object's
float fields and flag bytes are random, and the limit is set to the first cut value in about one case in four (the strict and non-strict tests are checked).
The float constants are the exe's data (0x678620, 0x6785e4, 0x67862c)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _bits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _d5140(c):
    e = c.emu
    rnd = c.rng
    k = struct.unpack('<f', e.mu.mem_read(0x678620, 4))[0]
    c67 = struct.unpack('<f', e.mu.mem_read(0x67862c, 4))[0]
    inv = struct.unpack('<f', e.mu.mem_read(0x6785e4, 4))[0]

    def fl():
        return _f32(rnd.uniform(-0.6, 0.6))

    self_obj = _rnd(c, 0x200)
    f = {off: fl() for off in (0xfa, 0x102, 0x106, 0xfe, 0x115, 0x119, 0x11d, 0x121)}
    for off, v in f.items():
        e.w32(self_obj + off, _bits(v))
    e.wbytes(self_obj + 0x114, bytes([rnd.choice([0, 1])]))
    e.wbytes(self_obj + 0x125, bytes([rnd.choice([0, 1])]))
    eng48 = fl()
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x48, _bits(eng48))
    t1 = int(_f32(_f32(f[0x115] + f[0xfa]) * k))
    t2 = int(_f32(f[0x11d] * k))
    t3 = int(_f32(f[0x119] * k))
    if rnd.random() < 0.4:
        lim = rnd.choice([t1, t2, t3])  # the strict and non-strict tests at their edges
    else:
        lim = rnd.randrange(-700, 700)
    e.w32(eng + 0x40, lim & 0xffffffff)
    e.w32(0x70039c, eng)
    v_in = _f32(eng48 + f[0x121])
    r = v_in if rnd.random() < 0.3 else fl()
    ret4de = [r]
    log = []

    def h4de(em, rr):
        log.append(('4de', em.arg32(0), em.arg32(1)))
        em.calllog.append(('4de', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(st0=ret4de[0], argbytes=8)

    def h5c3560(em, rr):
        em.calllog.append(('c3560', 0, None, (em.arg32(0) & 0xff, em.arg32(1) & 0xff)))
        em.ret(eax=0, argbytes=8)

    e.hook(0x4de000, h4de)
    e.hook(0x5c3560, h5c3560)
    return [self_obj]


S(0x5c3140, 'unnamed5c3140 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5140,
  note='unclaimed-57 batch 125; 0x4de000 and 0x5c3560 hooked (logging; 0x4de000 returns st0); engine +0x40 limit, +0x48 float; object floats and flags random')
