"""specs_s1514.py - unclaimed-15 claim 14 (docs/20-unclaimed-15.md): CRigidBody::Save(ZSaveGame*) (0x5406e0).

Stubbed (unverified, not lifted): 0x547670 (thiscall, one argument), a code stub that logs ecx and its argument in heap
cells and returns ret 4. The save object is a 0x200-byte object whose slots (+0x3c, +0x44, +0x4c, +0x54, +0x60, +0x68,
+0x70) are logged, one argument each, and return a random eax. The body is 0x200 random bytes, so every field read is
random and compared through the logged arguments. The +4 flag bit clear is compared in the heap."""
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
    """thiscall stub: stores ecx and its nargs stack arguments in heap cells, returns ret in eax, ret 4*nargs."""
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)                              # mov [cells], ecx
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])              # mov eax, [esp + 4 + 4i]
        code += b'\xa3' + ss.P(cells + 4 + 4 * i)                 # mov [cells + 4 + 4i], eax
    code += b'\xb8' + ss.P(ret)                                   # mov eax, ret
    code += b'\xc2' + struct.pack('<H', 4 * nargs)                # ret 4n
    return ss.code(c, code)


def _save(c):
    self_obj = _rnd(c, 0x200)
    save = _rnd(c, 0x200)
    used = {0x3c: 1, 0x44: 1, 0x4c: 1, 0x54: 1, 0x60: 1, 0x68: 1, 0x70: 1}
    svt = c.emu.logging_vtable('ZSave', 0x80,
                               impl={off: (lambda e, a, v=c.rng.getrandbits(32): (v, None)) for off in used},
                               argwords=used)
    c.emu.w32(save, svt)
    ss.patch(c, 0x547670, _thiscall_log(c, 1, 0))
    return [self_obj, save]


S(0x5406e0, 'CRigidBody::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-15 claim 14; 0x547670 stubbed (logs ecx and its argument); save slots logged')
