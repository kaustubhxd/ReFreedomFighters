"""specs_s2429.py - decomp area 24, batch 2429.
0x63e5f0 ZDrawBase::Free(void*, int), thiscall, ret 8: tail jump to ZOffsetAllocPointerSort::Free (0x63e310) on the
object at +0x60 with (pointer - the dword at +0x64) and the size rounded up to 16. 0x63e310 is a recorder (2 args).
0x45ed70 ZGEOM::GetChunkData(int) const, thiscall, ret 4: when the dword at +0x10 and then its +0xc are set, tail jump
to 0x45e420 with that second object (ecx) and the argument; else 0. 0x45e420 is a recorder (1 arg, returns random).
0x499bf0 (GUESS owner), thiscall, ret 4: slot 0x10 of this with (argument, 0x24), returns this. Slot 0x10 is a recorder."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _free(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x80)
    alloc = obj(c, 0x40, {})
    e.w32(self_ + 0x60, alloc)
    e.w32(self_ + 0x64, r.randint(0, 1 << 16))
    hook_rec(c, 0x63e310, 2, this=True, ret=0)
    return [self_, r.getrandbits(32), r.randint(0, 300)]


def _chunk(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x40)
    if r.random() < 0.8:
        p = rnd(c, 0x40)
        e.w32(self_ + 0x10, p)
        if r.random() < 0.8:
            q = rnd(c, 0x40)
            e.w32(p + 0xc, q)
        else:
            e.w32(p + 0xc, 0)
    else:
        e.w32(self_ + 0x10, 0)
    hook_rec(c, 0x45e420, 1, this=True, ret=lambda emu, k: r.getrandbits(32))
    return [self_, r.getrandbits(32)]


def _self10(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x40, {0x10: pystub(c, 2)})
    return [o, r.getrandbits(32)]


S(0x63e5f0, 'ZDrawBase::Free', 'thiscall', None, ret=None, gen=_free, note='batch2429')
S(0x45ed70, 'ZGEOM::GetChunkData', 'thiscall', None, ret='eax', gen=_chunk, note='batch2429')
S(0x499bf0, 'GUESS: slot 0x10 caller returning this (0x499bf0)', 'thiscall', None, ret='eax', gen=_self10, note='batch2429')
