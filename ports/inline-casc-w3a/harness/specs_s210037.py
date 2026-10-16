"""specs_s210037.py - Sonnet-w3a: selector with callbacks, forwarder with branches, message router; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g62ce70(c):
    clear_hooks(c)
    A = rnd(c, 0x20); c.emu.w32(A + 0xc, c.rng.choice([0, 0, 1]))
    ob = rnd(c, 0x40)
    cnt = [0]
    c.emu.w32(ob + 0x1c, pystub(c, 4, ret=lambda e, k: c.rng.choice([0, 0, 1, 7]), pop=0))
    return [A, c.rng.choice([0xf, 0x12, 0x12, 0x12, 0x1c, 0, 5]), _r(c), _r(c), ob]


def g45df10(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x298: pystub(c, 5, ret=c.rng.choice([0, 0, _r(c)]), this=True)}, nslots=0xa8)
    m = rnd(c, 0x40)
    t = obj(c, 0x40, {0x1b8: pystub(c, 5, ret=_r(c), this=True), 0x20: pystub(c, 0, ret=c.rng.choice([0, 1, _r(c)]), this=True),
                      0x1b4: pystub(c, 2, ret=c.rng.choice([0, 1, 0x100]), this=True)}, nslots=0x70)
    c.emu.w32(t + 4, _r(c)); c.emu.w32(t + 0xc, m)
    mg = obj(c, 0x40, {0x10: pystub(c, 0, ret=c.rng.choice([0, 1, 0x100]), this=True)}, nslots=0x20)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    return [t, a, _r(c), _r(c), c.rng.choice([0, _r(c)]), _r(c)]


def g57c2b0(c):
    clear_hooks(c)
    hook_rec(c, 0x562d90, 1, ret=_r(c), this=True)
    hook_rec(c, 0x561c40, 0, ret=c.rng.choice([0, 1, 0x100, 0x80, 0xff]))
    hook_rec(c, 0x561f50, 1, ret=_r(c))
    real = c.emu.rbytes(0x6aa64c, 32).split(b'\x00')[0] + b'\x00'
    s = rnd(c, 0x40)
    r = c.rng.random()
    if r < 0.5: c.emu.wbytes(s, real)
    elif r < 0.8:
        b = bytearray(real)
        if len(b) > 1: b[c.rng.randrange(0, len(b) - 1)] ^= 0x20
        c.emu.wbytes(s, bytes(b))
    else: c.emu.wbytes(s, bytes([0x41, 0]))
    holder = rnd(c, 0x10)
    c.emu.w32(holder + 4, 0 if c.rng.random() < 0.15 else s)
    t = obj(c, 0x100, {0xd8: pystub(c, 0, ret=c.rng.choice([0, 0, 0, 1, 0x100]), this=True), 0xf8: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x40)
    c.emu.w32(t + 0xf4, holder)
    return [t, c.rng.choice([0x102, 0x103, 0x104, 0, _r(c)])]


S(0x62ce70, 'selector_with_callbacks', 'cdecl', None, ret='eax', gen=g62ce70, note='batch210037')
S(0x45df10, 'forwarder_with_branches', 'thiscall', None, ret='eax', gen=g45df10, note='batch210037')
S(0x57c2b0, 'message_router_102_103', 'thiscall', None, ret='eax', gen=g57c2b0, note='batch210037')
