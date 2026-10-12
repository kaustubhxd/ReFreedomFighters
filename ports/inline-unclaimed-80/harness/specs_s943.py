"""specs_s943.py - unclaimed-80 (docs/20-unclaimed-80.md): GUESS FUN_45bab0 (0x45bab0). The index is 0..3 and the table entry at
this+0x8d8+4*index is nonzero 70% of the time (a logging-fake object). 0x45bb10 is hooked by address with a recording thiscall stub of
five stack arguments (ret 20): it logs the ecx, the first argument and the next three words; the local's address is not logged (it is a
stack address and differs between the runs)."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _thl(c, n, skip=()):
    P = lambda v: struct.pack('<I', v & 0xffffffff)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(4 * (n + 1), 4)
    c.emu.wbytes(ring, bytes(4 * (n + 1)))
    b = b'\x89\x0d' + P(ring)                                    # mov [ring], ecx
    for k in range(n):
        if k in skip:
            continue
        b += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x15' + P(ring + 4 * (k + 1))
    b += b'\xff\x05' + P(cnt) + b'\xc2' + struct.pack('<H', 4 * n)   # inc [cnt]; ret 4n (thiscall)
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


def _wrap(c):
    ss.patch(c, 0x45bb10, _thl(c, 5, skip=(4,)))
    o = _rnd(c, 0x1000)
    for k in range(4):
        if c.rng.random() < 0.7:
            x = _rnd(c, 0x40)
            c.emu.w32(x, _fake(c, 'ZWrapX', 0x20, {}))
            c.emu.w32(o + 0x8d8 + 4 * k, x)
        else:
            c.emu.w32(o + 0x8d8 + 4 * k, 0)
    return [o, c.rng.getrandbits(32), c.rng.randint(0, 3), c.rng.getrandbits(32)]


S(0x45bab0, 'GUESS FUN_45bab0 (wrapper) (unknown) thiscall', 'thiscall', None, ret=None, gen=_wrap,
  note='unclaimed-80 GUESS wrapper; 0x45bb10 hooked by address (recording thiscall stub, five arguments)')
