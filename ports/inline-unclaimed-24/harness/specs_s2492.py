"""specs_s2492.py - decomp area 24, batch 2492 (residue 3, smallest first).
0x654df0 (GUESS): thiscall, ret 0xc. Slot 0x230 of this with the three arguments (recorder, pops 12); then byte flags of the system
object as in the source. 0x4cb970 (GUESS): thiscall, void. Table +0x9b, object at table+0xadc, slot 0x25c with (0x685f44, 0) (recorder,
returns a fixed dword); when nonzero, slot 0x4c of the table with it (recorder, returns a fixed dword), then 0x4cb7f0 (recorder,
thiscall, one argument, pops 4) on this with that result."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks, hook_rec


def _flags(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    for off in (0xa1f, 0xad8, 0x1406, 0x13f7):
        e.wbytes(so + off, bytes([r.getrandbits(8)]))
    self_ = obj(c, 0x40, {0x230: pystub(c, 3)})
    return [self_, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _lookup(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4cb7f0, 1, this=True)
    o25c = obj(c, 0x40, {0x25c: pystub(c, 2, ret=r.choice([0, r.getrandbits(16)]))})
    so = sysobj(c, table_slots={0x4c: pystub(c, 1, ret=r.getrandbits(32))}, table_size=0xb00)
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0xadc, o25c)
    self_ = rnd(c, 0x40)
    return [self_]


S(0x654df0, 'GUESS flags after call', 'thiscall', None, ret=None, gen=_flags, note='batch2492')
S(0x4cb970, 'GUESS table lookup then helper', 'thiscall', None, ret=None, gen=_lookup, note='batch2492')
