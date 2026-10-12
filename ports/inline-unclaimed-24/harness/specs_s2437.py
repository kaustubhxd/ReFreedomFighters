"""specs_s2437.py - decomp area 24, batch 2437 (slice 11 leaves).
0x41f0b0 ZSysMemGC::GetNrAllocs(node*), thiscall, ret 4: node+4 = the dword at this+0x2c, this+0x2c = node.
0x4d5130 IOFSMemoryAccess_t::nativeFdValid(ImpNativeFd_t*), thiscall, ret 4, eax: 1 when the argument equals this+4.
0x5f33f0 ZScriptDll::setOpaqueCallPrice(int), thiscall, ret 4: the object at ([this+0xc])+4 gets +0x34 = argument.
0x425af0 ZSysComGC::SetFileAndLine(char*, int), thiscall, ret 8, eax = this: +0x18 = first, +0x1c = second argument.
0x4930f0 (GUESS owner), thiscall, plain ret: when the byte at +0xbc2 is set it is cleared, and the object at +8 (if any) gets
+0x24 = 0 (the jump target 0x4986f0 is three instructions, exe code).
0x410470 (GUESS, unnamed), cdecl, eax = 0: when the pointer argument is non-null, seven dwords at it are zeroed."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _node(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x40)
    return [o, rnd(c, 0x10)]


def _fd(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    arg = o + 4 if r.random() < 0.5 else r.getrandbits(32)
    return [o, arg]


def _price(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x20)
    o2 = rnd(c, 0x20)
    o3 = rnd(c, 0x80)
    e.w32(o + 0xc, o2)
    e.w32(o2 + 4, o3)
    return [o, r.getrandbits(32)]


def _file(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x40)
    return [o, rnd(c, 0x20), r.getrandbits(32)]


def _flag(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0xc00)
    e.w8(o + 0xbc2, r.choice([0, 1]))
    if r.random() < 0.7:
        inner = rnd(c, 0x40)
        e.w32(inner + 0x24, r.getrandbits(32))
        e.w32(o + 8, inner)
    else:
        e.w32(o + 8, 0)
    return [o]


def _zero(c):
    clear_hooks(c)
    r = c.rng
    p = rnd(c, 0x20) if r.random() < 0.7 else 0
    return [p]


S(0x41f0b0, 'ZSysMemGC::GetNrAllocs', 'thiscall', None, ret=None, gen=_node, note='batch2437')
S(0x4d5130, 'IOFSMemoryAccess_t::nativeFdValid', 'thiscall', None, ret='eax', gen=_fd, note='batch2437')
S(0x5f33f0, 'ZScriptDll::setOpaqueCallPrice', 'thiscall', None, ret=None, gen=_price, note='batch2437')
S(0x425af0, 'ZSysComGC::SetFileAndLine', 'thiscall', None, ret='eax', gen=_file, note='batch2437')
S(0x4930f0, 'GUESS: flag clear and +0x24 reset (0x4930f0)', 'thiscall', None, ret=None, gen=_flag, note='batch2437')
S(0x410470, 'GUESS: cdecl zeroing of seven dwords (0x410470)', 'cdecl', None, ret='eax', gen=_zero, note='batch2437')
