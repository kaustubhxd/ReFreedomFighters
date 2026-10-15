from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    helper_status = r.choice([0, 1, 2, 0xffffffff])
    hook_rec(c, 0x4614d0, 3, this=True, pop=12,
             side=lambda emu, k: emu.calllog.append(('helper', emu.reg('ecx'), *(emu.arg32(i) for i in range(3)))))
    def edx_stub(emu, res):
        emu.calllog.append(('edx', emu.reg('ecx'), emu.reg('edx')))
        emu.ret(eax=helper_status)
    nv = e.alloc(0x2ec, 4)
    e.w32(nv + 0x2e8, e.stub_fn('edx callback', edx_stub))
    next_obj = rnd(c, 0x20)
    e.w32(next_obj, nv)
    first = obj(c, 0x20, {0x10: pystub(c, 0, this=True, ret=next_obj)})
    fallback = r.getrandbits(32)
    action_result = rnd(c, 0x20)
    action = obj(c, 0x240, {0x230: pystub(c, 2, this=True, pop=8, ret=action_result,
                           side=lambda emu, k: emu.calllog.append(('action', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))}, nslots=0x231 // 4)
    self = obj(c, 0x30, {0x0c: pystub(c, 0, this=True, ret=fallback)}, nslots=0x10 // 4)
    e.w32(self + 0x0c, first)
    e.w32(self + 0x08, action)
    value = r.choice([0, r.getrandbits(32)])
    e.w32(self + 0x10, value)
    return [self]


S(0x5e03c0, 'GUESS resolve conditional engine resource action', 'thiscall', None,
  ret='al', gen=gen, note='batch62065')
