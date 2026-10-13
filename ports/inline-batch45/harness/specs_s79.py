"""specs_s79.py - inline session batch 79: CTelePortList::FrameUpdate (0x4b8360), ZKillBox::Init (0x5b1cb0) and
ZRelayMessageList::RelayMessage (0x4b8ab0). TelePort(int) (0x4b84b0) is patched per run with a recorder (ecx and the
argument). The render manager (global 0x70039c) is a stub object whose slots 0xe8 and 0xe4 return sequences, and whose
+0x9b object holds the +0xadc object with slot 0x25c. A relay list's start takes two stack arguments (ret 8)."""
import struct
from pilot import S
import specs_s53 as k53
import specs_s60 as k60
import specs_s73 as k73

_rnd, _obj = k53._rnd, k53._obj
_seq, _ecx, _patch = k60._seq, k73._ecx, k73._patch
P = lambda v: struct.pack('<I', v & 0xffffffff)


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _relay_list(c, handles):
    """Handle list whose start takes (valid, ebx) (ret 8); next takes (valid) (ret 4)."""
    k = len(handles)
    tab = c.emu.alloc(4 * (k + 2), 4)
    c.emu.w32(tab, 0)
    for i, h in enumerate(handles):
        c.emu.w32(tab + 4 * (i + 1), h)
    start = _code(c, b'\x8b\x4c\x24\x04\xc7\x01' + P(k + 1) + b'\xc2\x08\x00')
    nxt = _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x85\xc0\x74\x03\x48\x89\x01\x8b\x04\x85' + P(tab) + b'\xc2\x04\x00')
    return _obj(c, 0x20, {0x4c: start, 0x5c: nxt})


def _tele(c):
    r = c.rng
    s = _rnd(c, 0x60)
    c.emu.w32(s + 0x4c, r.getrandbits(32))
    rets8 = [r.choice((0, 1, 0x100, 0xff, 0x101, 2)) for _ in range(8)]
    rm = _obj(c, 0x200, {0xe8: _seq(c, 1, rets8), 0xe4: _seq(c, 1, [r.choice((0, 1, 0x100)) for _ in range(8)])})
    c.emu.w32(0x70039c, rm)
    _patch(c, 0x4b84b0, _ecx(c, 1))
    c.emu.mu.ctl_flush_tb()
    return [s]


def _kill(c):
    r = c.rng
    s = _rnd(c, 0x60)
    obj = _obj(c, 0x40, {0x25c: _seq(c, 2, [r.getrandbits(32) for _ in range(8)])})
    o = _rnd(c, 0xc00)
    c.emu.w32(o + 0xadc, obj)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    c.emu.mu.ctl_flush_tb()
    return [s]


S(0x4b8360, 'CTelePortList::FrameUpdate', 'thiscall', None, ret=None, gen=_tele, note='batch79; TelePort patched')
S(0x5b1cb0, 'ZKillBox::Init', 'thiscall', None, ret=None, gen=_kill, note='batch79')
