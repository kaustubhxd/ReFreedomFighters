from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    key = r.getrandbits(32)
    def resource_call(emu, k):
        emu.calllog.append(('resource', emu.reg('ecx'), emu.arg32(0), emu.r32(emu.arg32(1))))
        emu.w32(emu.arg32(1), key)
    resource = obj(c, 0x90, {0x88: pystub(c, 2, this=True, pop=8, deref={1: 1}, side=resource_call)})
    lookup_value = r.getrandbits(32)
    list_obj = obj(c, 0x150, {
        0x138: pystub(c, 0, ret=resource, side=lambda emu, k: emu.calllog.append(('get-resource', emu.reg('ecx')))),
        0x58: pystub(c, 1, this=True, pop=4, ret=lookup_value,
            side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0))))})
    engine = rnd(c, 0xb0)
    e.w32(engine + 0x9b, list_obj)
    e.w32(0x70039c, engine)
    out = r.getrandbits(32)
    def target_call(emu, k):
        emu.calllog.append(('target', emu.reg('ecx'), emu.arg32(0)))
        emu.w32(emu.arg32(0), out)
    target = obj(c, 0x80, {0x68: pystub(c, 1, this=True, pop=4, side=target_call)})
    self = rnd(c, 0x70)
    e.w32(self + 4, r.getrandbits(32))
    e.w32(self + 0x52, r.getrandbits(32))
    return [self, target]


S(0x4c5690, 'GUESS resolve resource key and initialize target', 'thiscall', None,
  ret='al', gen=gen, note='batch62084')
