"""specs_s885.py - area 50, batch 885: 0x4395d0 (ZInputActions::HandleDebugOptions), no stack args, void.
ECX from previous call modelled as input: the vt+0xf0 stand-in sets ECX on return to a generation-time value (the spec input);
the vt+0x184 callee logs ECX (the explicit this that the port passes). Objects: the engine object g (0x70039c; vt +0x190 -> RES),
O at g+0x1907 (vt +0x38 -> a flag), O2 at g+0x190f (vt +0xf0 -> the result r and the ECX input), RES (vt +0x184, cdecl: logs
ECX and the four stack words). g+0x9c7 is a float compared with 1.0 (the boundary 1.0 is drawn); g+0x1b3e is a flag byte."""
from unicorn.x86_const import UC_X86_REG_ECX
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    g = vt_object(c, 0x1b00, {}, nslots=0x100, name='g')   # slots filled below (need RES)
    e.w32(0x70039c, g)

    gate = r.choice([1.0, 0.5, 2.0])
    e.wf32(g + 0x9c7, gate)
    e.w8(g + 0x1b3e, r.randint(0, 1))
    flag38 = r.random() < 0.6
    ecx_in = r.getrandbits(32)              # the ECX value the vt+0xf0 callee leaves behind (the spec input)
    rf0 = r.getrandbits(32)

    def h38(e, rr):
        e.calllog.append(('O.38', e.arg32(0), e.arg32(1)))
        e.ret(eax=1 if flag38 else 0, argbytes=8)

    def hf0(e, rr):
        e.calllog.append(('O2.f0',))
        e.mu.reg_write(UC_X86_REG_ECX, ecx_in)
        e.ret(eax=rf0, argbytes=0)

    def h184(e, rr):
        e.calllog.append(('res.184', e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=0, argbytes=0)                # cdecl: the caller pops the four words

    RES = vt_object(c, 0x40, {0x184: h184}, nslots=0x100, name='res')

    def h190(e, rr):
        e.calllog.append(('g.190',))
        e.ret(eax=RES, argbytes=0)

    gvt = e.fake_vtable('g', 0x100, {0x190: h190})
    e.w32(g, gvt)
    O = vt_object(c, 0x40, {0x38: h38}, nslots=0x20, name='O')
    e.w32(g + 0x1907, O)
    O2 = vt_object(c, 0x40, {0xf0: hf0}, nslots=0x100, name='O2')
    e.w32(g + 0x190f, O2)
    only_hooks(c, {})
    e.w32(0x70039c, g)
    return [g]


S(0x4395d0, 'HandleDebugOptions (ECX from previous call modelled as input)', 'thiscall', None, gen=_gen, note='area50 batch885')
