"""specs_s933.py - unclaimed-80 claim 13 (docs/20-unclaimed-80.md): ZFFActorIf::MakeInactiveOnMap (0x55b3f0). The exe helpers are
hooked by address with logging thiscall stubs (every argument is recorded in a heap ring, the call count too, and the stub returns
its per-case value): 0x5003d0 (returns a pointer to a record), 0x59d150 (returns al), 0x59d250, 0x589c20 (returns an object), 0x596940
and 0x59d090 (returns al). The object at this+0x1c has a type record whose +8 is 2, 3 or another value. Its virtual slots (+0x3a0 two
args, +0x390 one, +0x20 none) are logging fakes; the object X from +0x20 has slot +0x84 (one argument, returns al)."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _thl(c, n, ret, skip=(), deref=()):
    """thiscall stub: logs its n arguments in a heap ring (except the indices in skip, which are stack addresses and differ
    between the two runs), counts calls, returns ret, cleans 4*n bytes."""
    P = lambda v: struct.pack('<I', v & 0xffffffff)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(4 * max(n, 1), 4)
    c.emu.wbytes(ring, bytes(4 * max(n, 1)))
    b = b''
    for k in range(n):
        if k in skip:
            continue
        b += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x15' + P(ring + 4 * k)
    # deref: (k, off) logs the dword at *(arg k + off) (the value a stack pointer argument points at)
    dring = c.emu.alloc(4 * max(len(deref), 1), 4)
    c.emu.wbytes(dring, bytes(4 * max(len(deref), 1)))
    for j, (k, off) in enumerate(deref):
        b += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x8b\x52' + bytes([off]) + b'\x89\x15' + P(dring + 4 * j)
    b += b'\xff\x05' + P(cnt) + b'\xb8' + P(ret) + b'\xc2' + struct.pack('<H', 4 * n)
    return ss.code(c, b)


def _fake(c, name, nslots, handlers):
    slots = {}
    for off, (n, fn) in handlers.items():
        def h(e, r, off=off, n=n, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
            eax, st0 = fn(e, args)
            e.ret(eax=eax, argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _make(c):
    R = _rnd(c, 0x40)
    c.emu.w32(R, c.rng.getrandbits(32))
    Y = _rnd(c, 0x40)
    bool_a = c.rng.choice([0, 1, c.rng.getrandbits(8)])
    bool_b = c.rng.choice([0, 1, c.rng.getrandbits(8)])
    r3a0 = c.rng.getrandbits(32)
    X = _rnd(c, 0x40)
    c.emu.w32(X, _fake(c, 'ZInactX', 0x90, {0x84: (1, lambda e, a, v=bool_a: (v, None))}))
    obj = _rnd(c, 0x80)
    c.emu.w32(obj, _fake(c, 'ZInactObj', 0x3b0, {
        0x3a0: (2, lambda e, a, v=r3a0: (v, None)),
        0x390: (1, lambda e, a: (0, None)),
        0x20: (0, lambda e, a, x=X: (x, None)),
    }))
    mid = _rnd(c, 0x20)
    t = c.rng.choice([2, 3, 3, 5, c.rng.getrandbits(32)])
    c.emu.w32(mid + 8, t)
    c.emu.w32(obj + 0x54, mid)
    self_o = _rnd(c, 0x40)
    c.emu.w32(self_o + 0x1c, obj)
    param = _rnd(c, 0x40)
    P = _rnd(c, 0x40)
    c.emu.w32(param + 4, P)
    A = _rnd(c, 0x40)
    G = _rnd(c, 0x2c20)
    c.emu.w32(G + 0x2c15, A)
    c.emu.w32(0x7003b8, G)
    ss.patch(c, 0x5003d0, _thl(c, 1, R))
    ss.patch(c, 0x59d150, _thl(c, 2, bool_a))
    ss.patch(c, 0x59d250, _thl(c, 3, 0))
    ss.patch(c, 0x589c20, _thl(c, 1, Y))
    ss.patch(c, 0x596940, _thl(c, 4, 0, skip=(1,), deref=((1, 4),)))   # arg 2 is &L (a stack address); its L[1] is logged
    ss.patch(c, 0x59d090, _thl(c, 1, bool_b))
    return [self_o, param]


S(0x55b3f0, 'ZFFActorIf::MakeInactiveOnMap (unknown) thiscall', 'thiscall', None, ret=None, gen=_make,
  note='unclaimed-80 claim 13; six exe helpers hooked by address (logging thiscall stubs); cookie check omitted')
