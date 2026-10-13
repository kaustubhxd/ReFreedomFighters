"""specs_m1403.py - batch 1403: CBuffer helpers, CPlayerStats Put/Take, CPlayerProfile save image."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, logger  # noqa: E402
from specs_m1401 import buf, stats, mgr_sys  # noqa: E402


def g_ctor(c):
    return [rnd(c, 16)]


def g_set(c):
    return [rnd(c, 16), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def g_addf(c):
    return [buf(c), c.rng.getrandbits(32)]


def st_obj(c):
    st = rnd(c, 0x160)
    stats(c, st)
    n = c.rng.choice([0, 1, 5, 63, 64, 70])
    c.emu.wbytes(st + 8, bytes(c.rng.randrange(1, 256) for _ in range(min(n, 0x40))))
    if n < 0x40:
        c.emu.w8(st + 8 + n, 0)
    elif n == 0x40:
        c.emu.w8(st + 0x48, 0)
    return st


def g_put(c):
    return [st_obj(c), buf(c, cap=c.rng.choice([0, 10, 100, 150, 151, 152, 300, 312, 313, 400]))]


def g_take(c):
    st = st_obj(c)
    logger(c, nargs=2)
    ver = c.rng.choice([1, 1, 2, 2, 2, 0, 3, c.rng.getrandbits(32)])
    # version 2 reads its +0x60 dword into an uninitialised local: keep that read inside the buffer
    cap = c.rng.choice([0, 3, 50, 100, 151, 152, 300, 400]) if ver != 2 else c.rng.choice([0x4c, 100, 151, 152, 312, 400])
    b = buf(c, cap=cap)
    c.emu.w32(b + 4, 0)
    if cap >= 4:
        c.emu.w32(c.emu.r32(b + 8), ver)
    return [st, b]


def part_obj(c, size):
    o = rnd(c, size)
    vt = c.emu.alloc(8, 4)
    for slot in (0, 4):
        c.emu.w32(vt + slot, stub(c, 1, this=True, skip=(0,), derefs=[(0, 0), (0, 8), (0, 4)], rets=[c.rng.getrandbits(32)]))
    c.emu.w32(o, vt)
    return o


def prof(c):
    pr = rnd(c, 0xf00)
    for off, size in ((0x35a, 0x160), (0x4b8, 0x960), (0xe18, 0x6c), (0xe84, 0x40)):
        po = part_obj(c, size)
        c.emu.wbytes(pr + off, c.emu.rbytes(po, size))
    return pr


def g_psave(c):
    pr = prof(c)
    gv = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 7)]),
                       0x90: stub(c, 2, this=True, skip=(1,), outs=[(1, 1, 1)])})
    disp = obj(c, 0x10, {0xdc: stub(c, 0, this=True, ret=c.rng.getrandbits(32))})
    mgr_sys(c, {0x134: stub(c, 0, this=True, ret=gv)}, {0xbc: stub(c, 0, this=True, ret=disp)})
    return [pr, rnd(c, 0x400), c.rng.choice([0, 1, 0x100])]


def g_pload(c):
    pr = prof(c)
    logger(c, nargs=2)
    gv = obj(c, 0x10, {0x68: stub(c, 3, this=True)})
    mgr_sys(c, {0x134: stub(c, 0, this=True, ret=gv)})
    b = rnd(c, 0x400)
    c.emu.w32(b + 0x3f8, c.rng.choice([0, 1, 2, 2, 3, c.rng.getrandbits(32)]))
    return [pr, b]


S(0x65e090, 'CBuffer::CBuffer (map: ZFFInventoryBridge ctor)', 'thiscall', ret='eax', gen=g_ctor)
S(0x5f0320, 'CBuffer::Set', 'thiscall', ret=None, gen=g_set)
S(0x5f0220, 'CBuffer::Add(float)', 'thiscall', ret='al', gen=g_addf)
S(0x5ad020, 'CPlayerStats::PutDataIntoBuffer', 'thiscall', ret='al', gen=g_put)
S(0x5ad320, 'CPlayerStats::TakeDataOutOfBuffer', 'thiscall', ret='al', gen=g_take)
S(0x5ae5a0, 'CPlayerProfile::SaveProfileToBuffer', 'thiscall', ret=None, gen=g_psave)
S(0x5ae450, 'CPlayerProfile::LoadProfileFromBuffer', 'thiscall', ret='al', gen=g_pload)
