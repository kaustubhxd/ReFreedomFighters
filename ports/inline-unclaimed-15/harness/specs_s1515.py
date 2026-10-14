"""specs_s1515.py - unclaimed-15 claim 15 (docs/20-unclaimed-15.md): ZActionControlMap::Load (0x5b3e60).

Stubbed (unverified, not lifted): the load object's slots +0x40 and +0x50 are a WRITER code stub: it stores the next value
of a per-case table (16 random dwords, consumed in order through a counter cell) through its pointer argument, and returns
with ret 4. The render manager's slot +0x58 is a logged thiscall stub (records ecx and its argument, returns a random eax).
The self object is 0x400 random bytes; the argument is a load object whose vtable is the writer's slot table. The table
order matters: the stored values land in different fields, so a wrong call order or a wrong slot shows in the heap."""
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
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _writer(c, table):
    """thiscall writer stub with one argument (a pointer): stores table[counter] through it, then counter += 1."""
    tab = c.emu.alloc(4 * len(table), 4)
    c.emu.wbytes(tab, b''.join(ss.P(v) for v in table))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = (b'\x8b\x54\x24\x04'                       # mov edx, [esp + 4]   (pointer argument)
            + b'\xa1' + ss.P(cnt)                       # mov eax, [cnt]
            + b'\x8b\x0c\x85' + ss.P(tab)               # mov ecx, [tab + eax*4]
            + b'\x89\x0a'                               # mov [edx], ecx
            + b'\xff\x05' + ss.P(cnt)                   # inc dword [cnt]
            + b'\xc2\x04\x00')                          # ret 4
    return ss.code(c, code)


def _load(c):
    self_obj = _rnd(c, 0x400)
    # Separate writers for slots +0x40 and +0x50 (each with its own table), so a call on the wrong slot shows.
    writer40 = _writer(c, [c.rng.getrandbits(32) for _ in range(16)])
    writer50 = _writer(c, [c.rng.getrandbits(32) for _ in range(16)])
    zload = _rnd(c, 0x200)
    zvt = c.emu.fake_vtable('ZLoadGame', 0x60, {0x40: writer40, 0x50: writer50})
    c.emu.w32(zload, zvt)
    robj = _rnd(c, 0x200)
    rstub = _thiscall_log(c, 1, c.rng.getrandbits(32))
    rvt = c.emu.fake_vtable('ZRenderLoad', 0x80, {0x58: rstub})
    c.emu.w32(robj, rvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, robj)
    c.emu.w32(0x70039c, rm)
    return [self_obj, zload]


S(0x5b3e60, 'ZActionControlMap::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-15 claim 15; load slots +0x40 and +0x50 are writer stubs; render slot +0x58 logged')
