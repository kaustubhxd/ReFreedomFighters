"""specs_s272.py - unclaimed area 67, gap band: four small thiscall functions (constant return, two vtable-word stores, one field read)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5f2110, 'FUN_5f2110 (constPtr6b8498)', 'thiscall', None, ret='eax', gen=_obj, note='batch272; returns 0x6b8498')
S(0x5f0370, 'FUN_5f0370 (setVtable6b823c)', 'thiscall', None, ret=None, gen=_obj, note='batch272; [this] = 0x6b823c')
S(0x5f1420, 'FUN_5f1420 (setVtable6b84a8)', 'thiscall', None, ret=None, gen=_obj, note='batch272; [this] = 0x6b84a8')
S(0x5f49d0, 'FUN_5f49d0 (readAt82)', 'thiscall', None, ret='eax', gen=_obj, note='batch272; dword at [this+0x82]')
