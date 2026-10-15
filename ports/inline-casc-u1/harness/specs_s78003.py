"""Spec for batch 78003: 0x5d28c0 vector update."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub

def _f32(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]

def _g5d28c0(c):
    clear_hooks(c)
    em, r = c.emu, c.rng
    hook_rec(c, 0x7003b0, 0, pop=0, ret=lambda e, k: e.reg('eax'))
    hook_rec(c, 0x5d1ea0, 0, this=True)

    def fill_output(emu, k):
        p = emu.arg32(0)
        emu.w32(p, _f32(0.125))
        emu.w32(p+4, _f32(-0.25))
        emu.w32(p+8, _f32(0.375))
    def fill_pair(emu, k):
        p = emu.arg32(0)
        emu.w32(p, _f32(0.2))
        emu.w32(p+4, _f32(0.3))
    hook_rec(c, 0x5cf300, 2, this=True, side=fill_pair, stackmark=(0,1))

    selfp = rnd(c, 0xe40)
    for off in (0xa54, 0xa5c, 0xdfd):
        em.w32(selfp+off, _f32(r.uniform(-2.5, 2.5)))
    for off in (0xd15, 0xd19, 0xd1d, 0xa7e, 0xa82, 0xa86):
        em.w32(selfp+off, _f32(r.uniform(-1, 1)))
    em.w8(selfp+0xd33, 0)
    em.w32(selfp+0xe18, 0)
    vt = em.alloc(0x90, 4)
    em.w32(selfp, vt)
    em.w32(vt+0x88, pystub(c, 1, this=True, side=fill_output, stackmark=(0,)))
    return [selfp]

S(0x5d28c0, 'GUESS update heading vectors', 'thiscall', None, ret=None, gen=_g5d28c0)
