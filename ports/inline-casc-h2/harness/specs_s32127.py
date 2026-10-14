"""specs_s32127.py - h2 () batch 32127: four tier H functions. Callees/slots are recorders; the vector subtract and the CRT sqrt run as exe code; order pinned with calllog."""
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


def g5c8750(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda emu, k: emu.reg('eax'), side=_log('gs'))

    def fill(emu, k):
        base = emu.arg32(0)
        for i in range(3):
            emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        emu.calllog.append(('w',))

    def fillv(emu, k):
        base = emu.arg32(0)
        for i in range(3):
            if r.random() < 0.6:
                emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        emu.calllog.append(('v',))
    hook_rec(c, 0x4db500, 1, this=True, pop=4, nullflag=(0,), side=fill)
    hook_rec(c, 0x5c88c0, 2, this=True, pop=8, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), deref={0: 3}, side=_log('t'))
    sub = obj(c, 0x20, {0x8c: pystub(c, 1, this=True, nullflag=(0,), side=fillv)}, nslots=0x8c // 4 + 1)
    inner = rnd(c, 0x20)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=inner, this=True, side=_log('lk'))})
    e.w32(inner + 8, rnd(c, 0x20))
    me = rnd(c, 0x80)
    e.w32(me + 0x44, sub)
    e.w32(me + 0x74, r.getrandbits(32))
    p = rnd(c, 0x10)
    for i in range(3):
        e.wbytes(p + 4 * i, struct.pack('<f', r.uniform(-9, 9)))
    return [me, p]


def g65c690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x65c530, 1, this=True, pop=4, side=_log('p'))
    o = obj(c, 0x20, {0x1d8: pystub(c, 1, this=True, side=_log('a')), 0x154: pystub(c, 3, this=True, side=_log('b'))}, nslots=0x1d8 // 4 + 1)
    m = rnd(c, 0x80)
    e.w32(m + 0x6c, r.choice([0, 1, 1, 2, r.getrandbits(32)]))
    e.w32(m + 0x48, r.choice([0, 0x80000, 0x7ffff, r.getrandbits(32)]))
    for off in (0x68, 0x70, 0x74):
        e.wbytes(m + off, struct.pack('<f', r.choice([r.uniform(-5, 5), 0.0, -0.0, _f(NAN)])))
    e.wbytes(0x6f6318, struct.pack('<f', r.choice([0.0, 0.0, 1.0, _f(NAN)])))
    mid = rnd(c, 0x20)
    e.w32(mid + 0xc, m)
    pp = rnd(c, 0x20)
    e.w32(pp + 0xc, mid)
    me = rnd(c, 0x10080)
    e.wbytes(me + 0x10051, o.to_bytes(4, 'little'))
    return [me, pp]


def g4dff10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x10)
    x = r.choice([0.0, -0.0, r.uniform(-9, 9), 3.0, 1e-30, 1e30, _f(NAN)])
    y = r.choice([0.0, -0.0, r.uniform(-9, 9), 4.0, 1e-30, 1e30])
    e.wbytes(me, struct.pack('<ff', x, y))
    return [me]


def g50ac10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    fv = struct.unpack('<f', struct.pack('<f', r.uniform(-100, 100)))[0]
    so = sysobj(c, slots={0x1c4: pystub(c, 2, this=True, st0=fv, side=_log('rnd'))})
    q = rnd(c, 0x20)
    e.wbytes(q + 4, bytes([r.choice([0, 2, 1, 3, 0xff])]))
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=q, side=_log('lk'))
    inner = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, side=_log('log2'))})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    p = rnd(c, 0x20)
    e.w32(p + 8, rnd(c, 0x20))
    return [p]


S(0x5c8750, 'GUESS test shifted point through 5c88c0 (GS frame)', 'thiscall', None, ret='al', gen=g5c8750, nan_heap=True, note='batch32127')
S(0x65c690, 'GUESS apply scaled motion parameters through slots', 'thiscall', None, ret=None, gen=g65c690, nan_heap=True, note='batch32127')
S(0x4dff10, 'GUESS normalise 2D vector and return its length', 'thiscall', None, ret='st0', gen=g4dff10, nan_heap=True, note='batch32127')
S(0x50ac10, 'GUESS stamp random value into slot or log error', 'stdcall', None, ret=None, gen=g50ac10, nan_heap=True, note='batch32127')
