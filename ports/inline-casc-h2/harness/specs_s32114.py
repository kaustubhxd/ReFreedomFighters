"""specs_s32114.py - h2 (Sonnet) batch 32114: tier H functions. Callees/slots are recorders; the assert hook 0x7003b0 is always set; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g50aa30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    so = sysobj(c)
    e.w32(so + 0x40, r.randrange(0, 100000))
    rec = rnd(c, 0x20)
    e.wbytes(rec + 4, bytes([r.choice([0, 2, 1, 3, 0xff])]))
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=rec, side=_log('lk'))
    inner = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, side=_log('log2'))})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    p = rnd(c, 0x20)
    e.w32(p + 8, rnd(c, 0x20))
    return [p]


def g527b30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x516070, 1, this=True, pop=4, side=_log('r'))
    me = rnd(c, 0x2400)
    n1 = r.choice([0, 1, 2, 3, 0xffffffff, 0x80000000])
    n2 = r.choice([0, 1, 2, 3, 0xffffffff])
    e.w32(me + 0x8d, n1)
    e.w32(me + 0x91, n2)
    e.wbytes(me + 0x21b5, struct.pack('<f', r.choice([r.uniform(-5, 5), 0.0, _f(NAN)])))
    for i in range(3):
        e.wbytes(me + 0xa5 + 0xde * i, bytes([r.choice([0, 0, 1])]))
        e.wbytes(me + 0x795 + 0xde * i, bytes([r.choice([0, 0, 1])]))
    e.w32(me + 0x22cc, r.getrandbits(32))
    return [me]


def g610070(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0xc8: pystub(c, 3, this=True, side=_log('s'))}, nslots=0xc8 // 4 + 1)
    me = rnd(c, 0x1400 + 0x400)
    e.wbytes(me + 0x1377, o.to_bytes(4, 'little'))
    a = r.choice([0.0, 1.0, 0.99, r.uniform(0, 1), r.uniform(-5, 5), 0.5, 1.5, -0.0, 0.9899999, 0.9900001, r.uniform(0.9, 1.0), r.uniform(0.9975, 0.9999), r.uniform(0.9975, 0.9999), r.uniform(0.9975, 0.9999)])
    return [me, F(a)]


def g529760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x1000)
    e.w32(me + 0x8d, r.choice([0, 1, 2, 3, 0xffffffff]))
    e.w32(me + 0x91, r.choice([0, 1, 2, 3, 0x80000000]))
    for i in range(4):
        for base in (0x95, 0x785):
            e.wbytes(me + base + 0xde * i + 0x55, struct.pack('<f', r.choice([r.uniform(-9, 9), r.uniform(-1e6, 1e6), 0.0, _f(NAN)])))
    return [me]


def g551670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    q = rnd(c, 0x20)
    r0, r1, r2 = rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)
    seq = [r0, r1, r2]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 2)], side=_log('lk'))
    hook_rec(c, 0x500360, 1, this=True, pop=4, side=_log('f'))
    hook_rec(c, 0x5002f0, 1, this=True, pop=4, side=_log('i'))
    b = obj(c, 0x20, {0x4c: pystub(c, 0, ret=q, this=True, side=_log('q'))}, nslots=0x4c // 4 + 1)
    p = obj(c, 0x20, {0x18: pystub(c, 1, ret=(b if r.random() < 0.8 else 0), this=True, side=_log('b'))}, nslots=0x18 // 4 + 1)
    v = rnd(c, 0x10)
    return [p, r.getrandbits(32), v]


S(0x50aa30, 'GUESS stamp time into slot or log error', 'stdcall', None, ret='eax', gen=g50aa30, nan_heap=True, note='batch32114')
S(0x527b30, 'GUESS update all records and set active flag', 'thiscall', None, ret=None, gen=g527b30, nan_heap=True, note='batch32114')
S(0x610070, 'GUESS fade level selector', 'thiscall', None, ret=None, gen=g610070, note='batch32114')
S(0x529760, 'GUESS average of record values', 'thiscall', None, ret=None, gen=g529760, nan_heap=True, note='batch32114')
S(0x551670, 'GUESS look up object and set three vector components', 'stdcall', None, ret='eax', gen=g551670, note='batch32114')
