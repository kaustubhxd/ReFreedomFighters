"""specs_s1506.py - unclaimed-15 claim 6 (docs/20-unclaimed-15.md): ZOctreeCompiled::~ZOctreeCompiled (0x441d20) and the
scalar deleting destructor at 0x487960 (GUESS: a movement class).

Both are STUBBED at their callees: the CRT delete 0x634273 (cdecl) and the embedded sub-destructor 0x480fd0 (thiscall, no
args) are patched to counting no-op stubs (serial_stubs.rec with 0 arguments; for the cdecl delete the stub returns with
ret 0 and the caller's add esp cleans up). The objects are 0x200 random bytes. The flags argument is drawn from
{0, 1, 2, 3, random}, so the delete branch runs for odd values only. Return value (this) is compared."""
import os
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


def _delete_stub(c):
    """cdecl delete (this, size): stores both arguments in two heap dwords, returns with ret 0 (the caller cleans up).
    rec() would log only the first argument, so a wrong size would go unnoticed; this stub logs both."""
    cell = c.emu.alloc(8, 4)
    c.emu.w32(cell, 0)
    c.emu.w32(cell + 4, 0)
    code = (b'\x8b\x44\x24\x04'                 # mov eax, [esp+4]   (this)
            + b'\xa3' + ss.P(cell)               # mov [cell], eax
            + b'\x8b\x54\x24\x08'                # mov edx, [esp+8]   (size)
            + b'\x89\x15' + ss.P(cell + 4)       # mov [cell+4], edx
            + b'\xc3')                           # ret
    return ss.code(c, code)


def _dtor(c):
    o = _rnd(c, 0x200)
    ss.patch(c, 0x634273, _delete_stub(c))
    ss.patch(c, 0x480fd0, ss.rec(c, 0, ret=0))
    return [o, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x441d20, 'ZOctreeCompiled::~ZOctreeCompiled (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-15 claim 6; delete 0x634273 stubbed; vtable 0x67d108')
S(0x487960, 'movement scalar deleting dtor (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-15 claim 6; sub-dtor 0x480fd0 and delete 0x634273 stubbed; vtables 0x68d018 then 0x68cf50')
