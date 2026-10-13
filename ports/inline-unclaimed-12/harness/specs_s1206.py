"""specs_s1206.py - unclaimed-12 batch 6 (docs/20-unclaimed-12.md, claim 6, in slice): CTelePortList::Load (three reads
through a load object's vtable slot +0x40) and CCHECKOBJINOBJ::CopyEventDataBlock (DBREAD operators through the shared
dbread_patch stubs). Thiscall; both take one stack argument."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load_vt(c):
    # vtable slot +0x40: writes the next per-case value through its pointer argument (stack arg 0)
    vals = [c.rng.getrandbits(32) for _ in range(3)]
    state = {'i': 0}

    def h(e, r):
        ptr = e.arg32(0)
        e.w32(ptr, vals[state['i'] % 3])
        state['i'] += 1
        e.ret(eax=0, argbytes=4)
    return c.emu.fake_vtable('zloadgame', 0x44, {0x40: h})


def _load_gen(c):
    obj = _rnd(c, 0x80)
    c.emu.w32(obj + 4, c.rng.getrandbits(32))
    load = _rnd(c, 0x40)
    c.emu.w32(load, _load_vt(c))
    return [obj, load]


def _setup_dbread(c):
    rets32 = [c.rng.getrandbits(32) for _ in range(8)]
    rets16 = [c.rng.getrandbits(16) for _ in range(8)]
    ss.dbread_patch(c, rets32, rets16, [0] * 8)


def _dbread_gen(c):
    return [_rnd(c, 0x100), _rnd(c, 0x40)]


S(0x4b83f0, 'CTelePortList::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load_gen,
  note='unclaimed-12 batch 6 (in slice); clears +4 bit 0x40; loads +0x4c, +0x50, +0x48 via vtable +0x40')
S(0x4fb830, 'CCHECKOBJINOBJ::CopyEventDataBlock (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_dbread_gen, setup=_setup_dbread,
  note='unclaimed-12 batch 6 (in slice); dwords +0x51/+0x59/+0x55 and words +0x4d/+0x4f from DBREAD')
