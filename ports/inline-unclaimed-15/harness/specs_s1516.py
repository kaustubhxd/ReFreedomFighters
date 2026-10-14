"""specs_s1516.py - unclaimed-15 claim 16 (docs/20-unclaimed-15.md): ZActor::Load2 (0x4790e0).

Stubbed (unverified, not lifted):
- 0x474710 (thiscall, no args): serial_stubs.rec with 0 arguments (counts calls).
- The render manager (global 0x70039c, +0x9b) is an object whose slot +0x134 returns X and slot +0x138 returns Y. Both
  are code stubs (mov eax, imm; ret).
- X's slot +0x90 is a BYTE writer: it stores the next byte of a per-case table through its second stack argument (the
  address of the local flag). Y's slot +0x88 is a DWORD writer: it stores the next dword through its second argument.
  Each consumes its own counter, and each has ret 8. Writers are unlogged because the pointer is a stack address.
- The actor object (self, 0x800 random bytes) has a logged vtable: its slots +0x654 and +0x580 take one argument. The byte
  at +0x5d2 is 0 or 1 per case, so both the +0x654 call and its skip run.
The byte writer writes ONE byte, so it cannot clobber neighbouring stack slots; the dword writer writes a dword into the
local v, which is exactly the local's size."""
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


def _ret_const(c, value):
    return ss.code(c, b'\xb8' + ss.P(value) + b'\xc3')


def _writer2(c, table, width):
    """thiscall writer with two arguments (ecx, then the second stack argument is the pointer): stores the next table
    value through the pointer, width 1 (byte) or 4 (dword), then counter += 1; ret 8."""
    tab = c.emu.alloc(4 * len(table), 4)
    c.emu.wbytes(tab, b''.join(ss.P(v) for v in table))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    arg0 = c.emu.alloc(4, 4)                                     # the first argument is kept in a heap cell too
    c.emu.w32(arg0, 0)
    store = b'\x88\x0a' if width == 1 else b'\x89\x0a'          # mov [edx], cl   /   mov [edx], ecx
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(arg0)            # mov eax, [esp + 4] ; mov [arg0], eax
            + b'\x8b\x54\x24\x08'                                  # mov edx, [esp + 8]   (pointer argument)
            + b'\xa1' + ss.P(cnt)                                # mov eax, [cnt]
            + b'\x8b\x0c\x85' + ss.P(tab)                        # mov ecx, [tab + eax*4]
            + store
            + b'\xff\x05' + ss.P(cnt)                            # inc dword [cnt]
            + b'\xc2\x08\x00')                                   # ret 8
    return ss.code(c, code)


def _load2(c):
    self_obj = _rnd(c, 0x800)        # the flag at +0x5d2 must lie inside the object
    c.emu.wbytes(self_obj + 0x5d2, bytes([c.rng.choice([0, 1])]))
    used = {0x654: 1, 0x580: 1}
    avt = c.emu.logging_vtable('ZActorLoad', 0x1a0, impl={}, argwords=used)
    c.emu.w32(self_obj, avt)
    ss.patch(c, 0x474710, ss.rec(c, 0, ret=0))
    x = _rnd(c, 0x200)
    y = _rnd(c, 0x200)
    xvt = c.emu.fake_vtable('ZLoadX', 0x80, {0x90: _writer2(c, [c.rng.getrandbits(32) for _ in range(8)], 1)})
    yvt = c.emu.fake_vtable('ZLoadY', 0x80, {0x88: _writer2(c, [c.rng.getrandbits(32) for _ in range(8)], 4)})
    c.emu.w32(x, xvt)
    c.emu.w32(y, yvt)
    rvt = c.emu.fake_vtable('ZRenderSub2', 0x80, {0x134: _ret_const(c, x), 0x138: _ret_const(c, y)})
    robj = _rnd(c, 0x200)
    c.emu.w32(robj, rvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, robj)
    c.emu.w32(0x70039c, rm)
    return [self_obj]


S(0x4790e0, 'ZActor::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_load2,
  note='unclaimed-15 claim 16; 0x474710 stubbed; render 0x134/0x138 code stubs; X byte writer, Y dword writer')
