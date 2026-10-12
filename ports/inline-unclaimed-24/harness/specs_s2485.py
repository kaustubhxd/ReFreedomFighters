"""specs_s2485.py - decomp area 24, batch 2485.
0x5c06c0 CEntityTracker::Load(ZLoadGame*), thiscall, ret 4, AL = 1 (parked item 744). The load object's slot 0x40 writes a
value into its pointer argument: the count (self+0x54, from a generation-time choice of 0..3) and fixed values elsewhere. The
system table's slot 0x58 returns a fixed value. Stack pointers are recorded as markers (they differ between builds)."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks, hook_rec


def _load(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = r.choice([0, 1, 2, 3])
    vals = [r.getrandbits(32) for _ in range(16)]
    self_ = rnd(c, 0x80)
    # operator new (cdecl): fresh emulator heap block of the requested size (as in batch 2421)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda emu, k: e.alloc(max(emu.arg32(0), 4), 4))

    def side40(emu, k):
        p = emu.arg32(0)
        if p == self_ + 0x54:
            emu.w32(p, cnt)
        else:
            emu.w32(p, vals[k % len(vals)])

    s68 = pystub(c, 1)
    s40 = pystub(c, 1, stackmark=(0,), side=side40)
    s50 = pystub(c, 1)
    s6c = pystub(c, 1)
    s44 = pystub(c, 1)
    ld = obj(c, 0x80, {0x68: s68, 0x40: s40, 0x50: s50, 0x6c: s6c, 0x44: s44})
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=0x1234)})
    return [self_, ld]


S(0x5c06c0, 'CEntityTracker::Load', 'thiscall', None, ret='al', gen=_load, note='batch2485')
