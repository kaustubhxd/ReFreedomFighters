import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec
from pe_emu import STACK_TOP


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    # A caller frame matching the unusual register/stack ABI at 0x4de6a3:
    # saved EDI/ESI/EBX sit below EBP; return address and two arguments above.
    frame = STACK_TOP - 0x1800
    e.w32(frame, STACK_TOP - 0x80)
    e.w32(frame + 4, e.RET_ADDR)
    dest = rnd(c, 0x40)
    src = rnd(c, 0x40)
    argptr = rnd(c, 0x40)
    vec = rnd(c, 0x30)
    for base in (src, argptr, vec):
        for off in (0, 4, 8, 12, 16, 20, 24, 28):
            e.wf32(base + off, c.fv(-8, 8, edge=0.01))
    weight = c.fv(-1, 1, edge=0.01)
    e.w32(frame + 8, argptr)
    e.wf32(frame + 12, weight)
    e.w32(frame - 4, 0x0b0b0b0b)  # saved EBX
    e.w32(frame - 8, 0x05151515)  # saved ESI
    e.w32(frame - 12, 0x0d0d0d0d) # saved EDI
    # Intercept the large helper chain at its direct entry points so its
    # complicated internal object preconditions do not dominate this wrapper.
    hook_rec(c, 0x4e0390, 1, pop=4, this=True, st0=0.0,
             side=lambda em, k: em.calllog.append(('edx', em.reg('edx'))))
    hook_rec(c, 0x44c840, 0, pop=0, this=True, st0=0.75)
    hook_rec(c, 0x446ee0, 1, pop=4, this=True, stackmark={0},
             side=lambda em, k: em.calllog.append(('edx', em.reg('edx'))))
    e.wf32(0x679540, 0.5)
    # The engine assert gate must always be a valid hook.
    def ah(em, retaddr):
        em.ret(eax=r.getrandbits(32), argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    return [dest, src, vec, vec, rnd(c, 0x80), struct.unpack('<I', struct.pack('<f', weight))[0], frame, frame - 12]


S(0x4de6a3, 'GUESS_interpolate_transform_state', ('regs', ['ebx','esi','eax','edx','ecx','xmm2','ebp','esp']),
  None, ret=None, gen=gen, note='batch102001')
