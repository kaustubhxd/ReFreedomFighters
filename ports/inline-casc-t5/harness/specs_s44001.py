"""specs_s44001.py - t5 (Sonnet) batch 44001: 0x43d020, 0x64f9f0."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def g43d020(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x30, r.choice([0, 1, -1 & 0xffffffff, r.getrandbits(32), r.randrange(0, 5000), r.randrange(0, 200)]))
    me = rnd(c, 0x90)
    n = r.choice([0, 1, 2, 3, 4, 5, 6])
    e.w32(me + 0x80, n)
    for i in range(n):
        base = me + 8 + i * 0x18
        e.w32(base + 4, r.choice([r.randrange(0, 100000), r.randrange(0, 3000), r.getrandbits(32), 0]))
        e.w32(base + 8, r.choice([_bits(r.uniform(0, 3000)), _bits(r.uniform(-100, 100)), 0, NAN, _bits(r.uniform(0, 1e5)), _bits(1e30)]))
    return [me]


def g64f9f0(c):
    clear_hooks(c)
    e = c.emu
    rng = c.rng
    vals = [rng.choice([0.0, 0.0, -0.0, 1.5, 12.0, rng.uniform(-50, 50), float('nan')]) for _ in range(2)]
    ret = rng.choice([0, 1, 2, -1])

    def scan(em, r):
        em.calllog.append(('sscanf', 0x42ab0d, None, (em.arg32(0), em.arg32(1))))
        if ret >= 1:
            em.wf32(em.arg32(2), vals[0])
        if ret >= 2:
            em.wf32(em.arg32(3), vals[1])
        em.ret(eax=ret, argbytes=0)
    e.hook(0x42ab0d, scan)
    pre = bytes(rng.getrandbits(8) for _ in range(8))
    if rng.random() < 0.5:
        pre = struct.pack('<ff', vals[0], rng.choice([0.0, vals[1]]))

    def get(em, r):
        em.calllog.append(('fnt.100', 0, em.reg('ecx'), ()))
        em.wbytes(em.arg32(0), pre)
        em.ret(eax=0, argbytes=4)

    def put(em, r):
        em.calllog.append(('fnt.fc', 0, em.reg('ecx'), (em.rbytes(em.arg32(0), 8),)))
        em.ret(eax=0, argbytes=4)
    fnt = rnd(c, 0x10)
    e.w32(fnt, e.fake_vtable('fnt', 0x110, {0xfc: put, 0x100: get}))
    s = rnd(c, 0x110)
    e.w32(s + 0x104, fnt)
    logobj = rnd(c, 16)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(6))))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    return [s, rng.choice([0, 0, rnd(c, 16)])]


S(0x43d020, 'GUESS drop expired entries', 'thiscall', None, ret=None, gen=g43d020, nan_heap=True, note='batch44001')
S(0x64f9f0, 'GUESS parse two floats and set font size', 'thiscall', None, ret=None, gen=g64f9f0, nan_heap=True, note='batch44001')
