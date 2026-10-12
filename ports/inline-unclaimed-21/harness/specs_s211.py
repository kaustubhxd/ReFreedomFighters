"""specs_s211.py - unclaimed area 21 (docs/20-unclaimed-21.md): 0x514500, 0x440d40, 0x487600 (batch211).

Vtable slots are raw stubs (see specs_s210.py for why logging_vtable is not used). Each stub that receives an argument
stores it in a heap cell so the compare sees it.
"""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _buf(c, n=0x40):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a + 0x10


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _stub_store_arg(c, cell):
    """thiscall slot with one stack word (ret 4): stores the word in cell."""
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cell) + b'\xc2\x04\x00')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _release_obj(c):
    cell = _cell(c)
    obj = ss.mkobj(c, {0x2ec: _stub_store_arg(c, cell)}, size=0x200)
    v = 0 if c.rng.random() < 0.3 else _buf(c)
    c.emu.w32(obj + 0x1d1, v)
    _flush(c)
    return [obj]


def _chain(c):
    """A list of 0 to 3 nodes; each node's vtable slot 0x20 returns the next node (0 at the end)."""
    n = c.rng.choice([0, 1, 2, 3])
    nxt = 0
    for _ in range(n):
        stub = ss.code(c, b'\xb8' + struct.pack('<I', nxt) + b'\xc3')
        nxt = ss.mkobj(c, {0x20: stub}, size=0x40)
    _flush(c)
    return [nxt]


def _ctor_args(c):
    obj = _rnd(c, 0x40)
    _flush(c)
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x514500, 'slot2ecRelease (GUESS)', 'thiscall', None, ret=None, gen=_release_obj,
  note='batch211; vtable 0x2ec with the field value, then the field is cleared')
S(0x440d40, 'flagWalk (GUESS)', 'thiscall', None, ret=None, gen=_chain,
  note='batch211; walks the list through vtable 0x20, ORs 0x8000 into each node')
S(0x487600, 'ctorFields (GUESS)', 'thiscall', None, ret='eax', gen=_ctor_args,
  note='batch211; two stack args; writes the fields and vtable 0x68d0e8')
