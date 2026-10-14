"""specs_s923.py - residue-9 slice, batch 923: 0x45a190 (thiscall, one flag arg, ret 4, returns this). Stand-ins (logged): 0x45a0e0 (thiscall,
no args; SEH-framed in the exe, the frame is not reproduced here), 0x4690b0 (cdecl, two words), 0x45c510 (cdecl, one word; SEH-framed,
not reproduced). The flag's bits 0 and 2 are drawn in all four combinations."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng

    def h0e0(e, rr):
        e.calllog.append(('45a0e0', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    def h4690(e, rr):
        e.calllog.append(('4690b0', e.arg32(0) != 0, e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    def h510(e, rr):
        e.calllog.append(('45c510', e.arg32(0) != 0))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x45a0e0: h0e0, 0x4690b0: h4690, 0x45c510: h510})
    self = rnd(c, 0x80)
    return [self, r.choice([0, 1, 2, 3, 4, 5, 6, 7, r.getrandbits(32)])]


S(0x45a190, 'init with flag (no name in map; SEH callees stood in)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch923 (residue-9 slice)')
