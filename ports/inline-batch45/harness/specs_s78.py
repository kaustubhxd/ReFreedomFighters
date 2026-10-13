"""specs_s78.py - inline session batch 78: the searchlight group's handle lists. ZFFSearchLightGroup::IsInList
(0x5c7160, stdcall), GetRefTabToEngageGuards (0x5c6bf0) and GetRefTabToOperators (0x5c6c50), thiscall. Each walks a
handle list through its vtable (slot 0x4c starts, slot 0x5c returns the next handle and writes the valid flag). The
lists are small stateful stubs; the records behind the handles carry a key in their first dword and two values."""
import struct
from pilot import S
import specs_s53 as k53

_rnd, _obj = k53._rnd, k53._obj
P = lambda v: struct.pack('<I', v & 0xffffffff)


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _iter(c, handles):
    """A handle list object: start writes the valid flag (count + 1 as the state), next returns the handles from the
    last to the first and clears the flag at the end (the table's slot 0 is 0)."""
    k = len(handles)
    tab = c.emu.alloc(4 * (k + 2), 4)
    c.emu.w32(tab, 0)
    for i, h in enumerate(handles):
        c.emu.w32(tab + 4 * (i + 1), h)
    start = _code(c, b'\x8b\x4c\x24\x04\xc7\x01' + P(k + 1) + b'\xc2\x04\x00')
    nxt = _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x85\xc0\x74\x03\x48\x89\x01\x8b\x04\x85' + P(tab) + b'\xc2\x04\x00')
    return _obj(c, 0x20, {0x4c: start, 0x5c: nxt})


KEYS = (1, 2, 3, 0x1234, 0xabcdef01)


def _ids(c):
    """Handles that are plain ids (IsInList compares the handle itself)."""
    r = c.rng
    return [r.choice((0, 1, 2, 3, 7, r.getrandbits(32))) for _ in range(r.randint(0, 6))]


def _records(c):
    """Records with a key at +0, values at +8 and +0xc. Some keys repeat, so the first match matters."""
    r = c.rng
    recs = []
    for _ in range(r.randint(0, 6)):
        rec = _rnd(c, 0x10)
        c.emu.w32(rec, r.choice(KEYS) if r.random() < 0.9 else r.getrandbits(32))
        c.emu.w32(rec + 8, r.getrandbits(32))
        c.emu.w32(rec + 0xc, r.getrandbits(32))
        recs.append(rec)
    return recs


def _isin(c):
    r = c.rng
    s = _rnd(c, 0x40)
    if r.random() < 0.9:
        c.emu.w32(s + 4, _iter(c, _ids(c)))
    else:
        c.emu.w32(s + 4, 0)
    c.emu.mu.ctl_flush_tb()
    return [r.choice((0, 1, 2, 3, 7, 9, r.getrandbits(32))), s]


def _ref(c, slot_off):
    r = c.rng
    s = _rnd(c, 0x80)
    if r.random() < 0.9:
        c.emu.w32(s + 0x60, _iter(c, _records(c)))
    else:
        c.emu.w32(s + 0x60, 0)
    c.emu.mu.ctl_flush_tb()
    key = r.choice(KEYS) if r.random() < 0.9 else r.getrandbits(32)
    return [s, key]


def _engage(c):
    return _ref(c, 0xc)


def _ops(c):
    return _ref(c, 0x8)


S(0x5c7160, 'ZFFSearchLightGroup::IsInList', 'stdcall', None, ret='al', gen=_isin, note='batch78')
S(0x5c6bf0, 'ZFFSearchLightGroup::GetRefTabToEngageGuards', 'thiscall', None, ret='eax', gen=_engage, note='batch78')
S(0x5c6c50, 'ZFFSearchLightGroup::GetRefTabToOperators', 'thiscall', None, ret='eax', gen=_ops, note='batch78')
