"""specs_s49.py - inline session batch 49: ZFFHERO::StashItem, GetInventoryInfo, GetItem and the FirstAid_Large lookup.
Vtable callees are heap stubs. The inventory walk uses small stateful stubs: the list's slot 0x48 sets the iterator to
N, slot 0x58 decrements it and returns the new value as a handle, render-manager slot 0x58 maps a handle to an item
from a per-input table, and each item's slot 0x2e8 returns the dword at item+8."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _stub(c, nargs, ret=0):
    rec = c.emu.alloc(4 * nargs + 4, 4)
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return _code(c, code)


def _obj(c, size, slots):
    o = _rnd(c, size)
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def _stash(c):
    r = c.rng
    rm = _obj(c, 0x10, {0x4c: _stub(c, 1, ret=r.getrandbits(32))})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    held = r.getrandbits(32) if r.random() < 0.7 else 0
    self = _obj(c, 0x840, {0x504: _stub(c, 0, ret=held), 0x3dc: _stub(c, 0), 0x480: _stub(c, 1)})
    reasons = (1, 2, 0x80, 0x100)
    cur = 0
    for b in reasons:
        if r.random() < 0.3:
            cur |= b
    c.emu.w32(self + 0x836, cur)
    c.emu.w32(self + 0x832, 0 if r.random() < 0.5 else r.getrandbits(32))
    stash = r.getrandbits(32) if r.random() < 0.5 else (r.getrandbits(24) << 8)
    c.emu.mu.ctl_flush_tb()
    return [self, stash, r.choice(reasons) if r.random() < 0.9 else r.getrandbits(32)]


def _infolist(c, n, types):
    lst = c.emu.alloc(4 + 4 * max(n, 1) + 0x10, 4)
    c.emu.w32(lst, n)
    ents = []
    for i in range(n):
        e = _rnd(c, 0x20)
        c.emu.w32(e + 0x10, types[i])
        c.emu.w32(lst + 4 + 4 * i, e)
        ents.append(e)
    return lst, ents


def _gii(c):
    r = c.rng
    n = r.randint(0, 6)
    types = [r.randint(0, 8) for _ in range(n)]
    lst, _ = _infolist(c, n, types)
    return [lst, r.randint(0, 9)]


def _walk(c, item_val):
    """Inventory with N-1 items reachable; returns (self-with-slot-0x464 builder args)."""
    r = c.rng
    n = r.randint(1, 6)
    table = c.emu.alloc(4 * n + 4, 4)
    for h in range(n):
        it = _obj(c, 0x20, {0x2e8: _code(c, b'\x8b\x41\x08\xc3')})   # mov eax, [ecx+8]; ret
        c.emu.w32(it + 8, item_val(h))
        c.emu.w32(table + 4 * h, it)
    rm = _obj(c, 0x10, {0x58: _code(c, b'\x8b\x44\x24\x04\x8b\x04\x85' + struct.pack('<I', table) + b'\xc2\x04\x00')})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    lst = _obj(c, 0x10, {0x48: _code(c, b'\x8b\x44\x24\x04\xc7\x00' + struct.pack('<I', n) + b'\xc2\x04\x00'),
                         0x58: _code(c, b'\x8b\x4c\x24\x04\x8b\x01\x48\x89\x01\xc2\x04\x00')})
    inv = _obj(c, 0x10, {0xa0: _stub(c, 0, ret=lst if r.random() < 0.85 else 0)})
    return inv


def _getitem(c):
    r = c.rng
    ntype = r.randint(0, 4)
    types = [r.randint(0, 8) for _ in range(ntype)]
    lst, ents = _infolist(c, ntype, types)
    for e in ents:
        c.emu.w32(e, r.choice((0, 0x1000, 0x2000, 0x3000)))
    inv = _walk(c, lambda h: r.choice((0x1000, 0x2000, 0x3000, 0x4000)))
    self = _obj(c, 0x970, {0x464: _stub(c, 0, ret=inv)})
    # GetInventoryInfo reads the list embedded at self+0x95b: copy count and entries there
    c.emu.w32(self + 0x95b, ntype)
    for i, e in enumerate(ents):
        c.emu.w32(self + 0x95f + 4 * i, e)
    c.emu.mu.ctl_flush_tb()
    return [self, r.randint(0, 9)]


def _str(c, s):
    a = c.emu.alloc(len(s) + 8, 4)
    c.emu.wbytes(a, s + b'\0')
    return a


def _firstaid(c):
    r = c.rng
    names = [b'FirstAid_Large', b'FirstAid_Small', b'FirstAid_Larg', b'FirstAid_Large2', b'', b'X']

    def ti(h):
        t = _rnd(c, 0x10)
        x = r.random()
        c.emu.w32(t + 4, 0 if x < 0.15 else _str(c, r.choice(names)))
        return t
    inv = _walk(c, ti)
    self = _obj(c, 0x470, {0x464: _stub(c, 0, ret=inv)})
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x595440, 'ZFFHERO::StashItem', 'thiscall', None, ret=None, gen=_stash, note='batch49')
S(0x5af130, 'ZFFInventoryInfoList::GetInventoryInfo', 'thiscall', None, ret='eax', gen=_gii, note='batch49')
S(0x591e50, 'ZFFHERO::GetItem', 'thiscall', None, ret='eax', gen=_getitem, note='batch49; GetInventoryInfo as exe code')
S(0x591d80, 'ZFFHERO find FirstAid_Large', 'thiscall', None, ret='eax', gen=_firstaid, note='batch49')
