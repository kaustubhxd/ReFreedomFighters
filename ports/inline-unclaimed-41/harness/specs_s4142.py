"""specs_s4142.py - unclaimed-41 batch 42 (core-todo residue-19): 0x46a4f0 ZItem::~ZItem() (thiscall, no arguments, plain ret). SEH frame
not reproduced (fs:[0] writes not compared).

self: 0x100 random bytes. L = this+0x6c (an object, or zero one time in five): its vtable slot 0x4c is a checksum stub; slot 0x64 is a
sequence stub that returns X1, X2, ... and then zero (so the loop runs 0 to 2 times). Each X (0x40 bytes) has a random first dword. The
render manager (0x70039c, rm+0x9b = o): o's slot 0x58 is a checksum stub returning Y (an object, or zero one time in three); Y's slot 0x210
is a checksum stub. The release objects at this+0x70, +0x78, +0x74 (and this+0x6c, after the loop) are objects with vt[0] a checksum
stub; each is null one time in four. 0x43ea20 is a checksum stub (ecx = this). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, slots):
    vt = c.emu.alloc(0x400, 4)
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _obj(c, slots):
    o = _rnd(c, 0x40)
    c.emu.w32(o, _vt(c, slots))
    return o


def _layout(c):
    s_vt0, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)

    # the list: 0x64 returns X1, X2, ... then zero
    n = c.rng.randint(0, 2)
    Xs = [_rnd(c, 0x40) for _ in range(n)]
    for X in Xs:
        c.emu.w32(X, c.rng.getrandbits(32))
    rets64 = Xs + [0]
    s64 = ss.seqr(c, 1, rets64)
    s4c, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[], cleanup=True, ret=0)
    s_vt0L, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)   # the release of +0x6c calls vt[0]
    L = _obj(c, {0: s_vt0L, 0x4c: s4c, 0x64: s64}) if c.rng.random() < 0.8 else 0

    # o (rm+0x9b): 0x58 returns Y or zero; Y's 0x210 is a checksum stub
    s210, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    Y = _obj(c, {0x210: s210})
    s58, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=Y if c.rng.random() < 2 / 3 else 0)
    o = _obj(c, {0x58: s58})
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)

    # the release objects
    rel = []
    for _ in range(4):
        rel.append(_obj(c, {0: s_vt0}) if c.rng.random() < 0.75 else 0)

    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x6c, L)
    c.emu.w32(self_ + 0x70, rel[0])
    c.emu.w32(self_ + 0x74, rel[1])
    c.emu.w32(self_ + 0x78, rel[2])
    # the release list order in the exe: 0x70, 0x6c (after the loop), 0x78, 0x74; 0x6c is the list object
    s43, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x43ea20, s43)
    return [self_]


S(0x46a4f0, 'ZItem::~ZItem()', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 42; SEH frame not reproduced (fs:[0] writes not compared); the member teardown 0x43ea20 and the vtable slots are stubs (GUESS)')
