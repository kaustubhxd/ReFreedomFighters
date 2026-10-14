"""specs_s880.py - area 50, batch 880: 0x4d9350 (GUESS name), thiscall, two stack args (ret 8), no result. The helper calls are stood in
and logged (their local-object pointer is not logged: it differs between the runs). 0x4cc1d0 answers a generation-time value that
0x4d92e0 receives (logged). SEH frame not reproduced."""
from pilot import S
from anim_common import only_hooks, rnd

def _gen(c):
    e, r = c.emu, c.rng
    v = r.getrandbits(32)

    def h_ctor(e, rr):
        e.calllog.append(('ctor.4cbe80', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h_step(e, rr):
        e.calllog.append(('step.4cc690',))
        e.ret(eax=0, argbytes=0)

    def h_query(e, rr):
        e.calllog.append(('query.4cc1d0', e.arg32(0)))
        e.ret(eax=v, argbytes=4)

    def h_meth(e, rr):
        e.calllog.append(('meth.4d92e0', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h_dtor(e, rr):
        e.calllog.append(('dtor.4cbec0',))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x4cbe80: h_ctor, 0x4cc690: h_step, 0x4cc1d0: h_query, 0x4d92e0: h_meth, 0x4cbec0: h_dtor})
    self = rnd(c, 0x100)
    return [self, r.getrandbits(32), r.getrandbits(32)]


S(0x4d9350, 'Build4d9350 (GUESS name; SEH frame not reproduced)', 'thiscall', None, gen=_gen, note='area50 batch880')
