"""specs_s2418.py - decomp area 24, batch 2418: two tail-jump forwarders that take their argument from the caller.
0x41fa30 ZSysMemGC::GetReadOutBlock() const: ecx = dword at +0x31, then jmp to 0x4d0ee0 (exe; reads and clears the
byte at +0x821b of that object, returns 0 or -1 by the stack argument). The stack argument is the caller's.
0x48ffb0 (GUESS owner): ecx = dword at +8, then jmp to ZGeomBuffer::GeomRefToPtr (0x497450, recorded here).
Both are thiscall with one stack argument, kept by the jump."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _sysmem(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    inner = rnd(c, 0x8400)
    e.w32(o + 0x31, inner)
    e.w8(inner + 0x821b, r.getrandbits(8))
    return [o, r.getrandbits(32)]


def _geom(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    tgt = rnd(c, 0x40)
    e.w32(o + 8, tgt)
    hook_rec(c, 0x497450, 1, this=True, ret=0x5000)
    return [o, r.getrandbits(32)]


S(0x41fa30, 'ZSysMemGC::GetReadOutBlock', 'thiscall', None, ret='eax', gen=_sysmem, note='batch2418')
S(0x48ffb0, 'GUESS: forwarder to GeomRefToPtr (0x48ffb0)', 'thiscall', None, ret='eax', gen=_geom, note='batch2418')
