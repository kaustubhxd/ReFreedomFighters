"""specs_s905.py - gap-band slice, batch 905: two SEH-framed rows (fs:[0] frame not reproduced; not compared).
0x41e1f0 (thiscall, no args, void): vtable store 0x67716c, then 0x41e590 on this. 0x41e230 (thiscall, one flag arg, ret 4, returns this):
the same, then 0x634273 (cdecl: this, 0x4f) if bit 0 of the flag is set. Stand-ins: 0x41e590 (logs ECX identity), 0x634273 (cdecl, logs).
The SEH frame is not reproduced (noted in the doc); heap writes and calls are compared."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen_ctor(c):
    e, r = c.emu, c.rng
    def h_base(e, rr):
        e.calllog.append(('base.41e590', e.reg('ecx') != 0, e.r32(e.reg('ecx'))))
        e.ret(eax=0, argbytes=0)
    only_hooks(c, {0x41e590: h_base})
    self = rnd(c, 0x100)
    return [self]


def _gen_dtor(c):
    e, r = c.emu, c.rng

    def h_base(e, rr):
        e.calllog.append(('base.41e590', e.reg('ecx') != 0, e.r32(e.reg('ecx'))))
        e.ret(eax=0, argbytes=0)

    def h_273(e, rr):
        e.calllog.append(('634273', e.arg32(0) != 0, e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x41e590: h_base, 0x634273: h_273})
    self = rnd(c, 0x100)
    return [self, r.choice([0, 1, 2, 0x100, 0xff, r.getrandbits(32)])]


S(0x41e1f0, 'Ctor41e1f0 (GUESS name; SEH frame not reproduced)', 'thiscall', None, gen=_gen_ctor, note='area50 batch905 (SEH row)')
S(0x41e230, 'ZSysMem::~ZSysMem() (SEH frame not reproduced)', 'thiscall', None, ret='eax', gen=_gen_dtor, note='area50 batch905 (SEH row)')
