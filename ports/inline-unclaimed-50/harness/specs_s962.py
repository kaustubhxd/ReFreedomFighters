"""specs_s962.py - area 50 batch 962: 0x512940 (thiscall, 3 stack args, ret 12, returns pointer).
Stand-ins (logged): global object at 0x70039c with virtual methods [+0x9b] (method [+0x58] and [+0x4c]),
result objects with methods [+0x2c4], [+0x2c], [+0x2f0], [+0xbc]."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    # Create return object (ebx)
    ret_obj = rnd(c, 0x100)

    # Create result1 (return value from global.58)
    result1 = rnd(c, 0x100)

    def h_global_9b_58(e, rr):
        e.calllog.append(('global.9b.58', e.arg32(0)))
        e.ret(eax=result1, argbytes=4)

    def h_result1_2c4(e, rr):
        e.calllog.append(('result1.2c4', e.arg32(0)))
        e.ret(eax=ret_obj, argbytes=4)

    def h_ebx_2c(e, rr):
        e.calllog.append(('ebx.2c',))
        e.ret(eax=0, argbytes=0)

    def h_global_9b_4c(e, rr):
        e.calllog.append(('global.9b.4c', e.arg32(0), e.arg32(1)))
        e.ret(eax=ret_obj, argbytes=8)

    def h_ebx_2f0(e, rr):
        e.calllog.append(('ebx.2f0', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h_ebx_bc(e, rr):
        e.calllog.append(('ebx.bc', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    # Set up global object at 0x70039c
    global_obj = vt_object(c, 0x100, {0x58: h_global_9b_58, 0x4c: h_global_9b_4c}, nslots=0x200, name='global_9b')
    e.w32(0x70039c, global_obj)

    # Set up result1 vt
    result1_obj = vt_object(c, 0x100, {0x2c4: h_result1_2c4}, nslots=0x200, name='result1')

    # Set up ebx vt
    ebx_vt = vt_object(c, 0x100, {0x2c: h_ebx_2c, 0x2f0: h_ebx_2f0, 0xbc: h_ebx_bc}, nslots=0x200, name='ebx_vt')

    self = rnd(c, 0x40)

    # Make result1 point to its vt
    e.w32(result1, result1_obj)

    # Make ret_obj point to its vt
    e.w32(ret_obj, ebx_vt)

    return [self, c.rng.randint(0, 100), c.rng.randint(0, 1), c.rng.randint(0, 100)]


S(0x512940, 'multi-virtual-call function with global and conditional (no name in map)', 'thiscall', None, gen=_gen, note='area50 batch962 (claimed)')
