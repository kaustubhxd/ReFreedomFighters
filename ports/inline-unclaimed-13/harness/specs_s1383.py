"""specs_s1383.py - unclaimed-13 claim 2 (docs/20-unclaimed-13.md): three virtual forwarders at 0x437080 (slot +0x18),
0x438340 (+0x1c) and 0x43ac10 (+0x2c). Each object is 0x800 random bytes whose vtable has a stub at +0x60 (mov eax, p;
ret 4) returning either 0 or a second object P. P has its own vtable with stubs at +0x18, +0x1c and +0x2c (mov eax, imm;
ret) returning random values, so both the exe and the port get the same answers. The result is eax.

Slot +0x60 returns its argument, so the argument is the candidate p (0 or a fresh object), which also checks that the
argument is forwarded."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, imm, ret_bytes=b'\xc3'):
    code = b'\xb8' + (imm & 0xffffffff).to_bytes(4, 'little') + ret_bytes
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _fwd(c):
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x80, 4)
    # The argument is the candidate p: slot +0x60 is a stub that returns its own argument (mov eax, [esp+4]; ret 4),
    # so a port that passes the wrong value to slot +0x60 is caught.
    if c.rng.random() < 0.2:
        p = 0
    else:
        p = _rnd(c, 0x40)
        pvt = c.emu.alloc(0x40, 4)
        c.emu.w32(pvt + 0x18, _stub(c, c.rng.getrandbits(32)))
        c.emu.w32(pvt + 0x1c, _stub(c, c.rng.getrandbits(32)))
        c.emu.w32(pvt + 0x2c, _stub(c, c.rng.getrandbits(32)))
        c.emu.w32(p, pvt)
    code = b'\x8b\x44\x24\x04\xc2\x04\x00'   # mov eax, [esp+4]; ret 4
    stub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(stub, code)
    c.emu.w32(vt + 0x60, stub)
    c.emu.w32(o, vt)
    return [o, p]


S(0x437080, 'forwardSlot18 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_fwd,
  note='unclaimed-13 claim 2; p = vt[+0x60](arg); p ? p->vt[+0x18]() : 0')
S(0x438340, 'forwardSlot1c (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_fwd,
  note='unclaimed-13 claim 2; p = vt[+0x60](arg); p ? p->vt[+0x1c]() : 0')
S(0x43ac10, 'forwardSlot2c (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_fwd,
  note='unclaimed-13 claim 2; p = vt[+0x60](arg); p ? p->vt[+0x2c]() : 0')
