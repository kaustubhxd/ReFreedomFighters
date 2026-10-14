"""specs_s1519.py - unclaimed-15 claim 19 (docs/20-unclaimed-15.md): ZActor::Die (0x478320, GUESS name).

Stubbed (unverified, not lifted): 0x466ce0 (thiscall, no args) and 0x47aad0 (thiscall, two args), both logged thiscall stubs
(serial_stubs-style code that records ecx and their arguments and returns a per-case eax). The actor (self) is 0x1000 random
bytes with a logged vtable: slot +0x588 returns a per-case bool, slots +0x654, +0x584, +0x62c take one argument, +0x628 takes
three, +0x3dc none and +0x130 three. The render manager's sub-object has a logged slot +0x114 (five arguments, returns a per-case
eax). The fields +0x6ce and +0x64c are drawn so the 0x47aad0 branch runs in some cases and not in others.
The exe's push of esi before the +0x628 call is a save (popped at the end), not an argument."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _thiscall_log(c, nargs, ret):
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _die(c):
    self_obj = _rnd(c, 0x1000)
    ok = c.rng.choice([0, 1])
    v = c.rng.choice([0, 5, 0x1234])
    c.emu.w32(self_obj + 0x6ce, v)
    c.emu.w32(self_obj + 0x64c, c.rng.choice([0xa, 0, 3]))
    impl = {0x588: lambda e, a, ok=ok: (ok, None)}
    vt = c.emu.logging_vtable('ZActorDie', 0x400,
                              impl=impl,
                              argwords={0x654: 1, 0x584: 1, 0x62c: 1, 0x628: 3, 0x130: 3})
    c.emu.w32(self_obj, vt)
    ss.patch(c, 0x466ce0, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x47aad0, _thiscall_log(c, 2, 0))
    sub = _rnd(c, 0x200)
    subvt = c.emu.fake_vtable('ZActorRenderSub', 0x140, {0x114: _thiscall_log(c, 4, c.rng.getrandbits(32))})
    c.emu.w32(sub, subvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, sub)
    c.emu.w32(0x70039c, rm)
    return [self_obj]


S(0x478320, 'ZActor::Die (GUESS) thiscall', 'thiscall', None, ret=None, gen=_die,
  note='unclaimed-15 claim 19; 0x466ce0 and 0x47aad0 stubbed (logged); render slot +0x114 logged; esi passed via asm')
