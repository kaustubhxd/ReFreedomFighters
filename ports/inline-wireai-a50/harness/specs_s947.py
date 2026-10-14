"""specs_s947.py - area 50 batch 947: 0x513860 (thiscall, no args, plain ret). Stand-ins (logged): 0x45f410 (thiscall, no args; the tail target), the list
objects' slot +0x28 (no args), the manager's slot +0x58 (one word; returns the object), and the object's slots +0x2c (no args) and +0xbc (one word).
The flag at +0x138 is drawn zero or not, and the list holds 0 to 3 nodes."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    def h45f(e, rr):
        e.calllog.append(('45f410', e.reg('ecx')))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x45f410: h45f})

    def h28(e, rr):
        e.calllog.append(('item.28', e.reg('ecx')))
        e.ret(eax=0, argbytes=0)

    def h2c(e, rr):
        e.calllog.append(('obj.2c', e.reg('ecx')))
        e.ret(eax=0, argbytes=0)

    def hbc(e, rr):
        e.calllog.append(('obj.bc', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h58(e, rr):
        e.calllog.append(('mgr.58', e.arg32(0)))
        e.ret(eax=obj, argbytes=4)

    obj = vt_object(c, 0x40, {0x2c: h2c, 0xbc: hbc}, nslots=0x200, name='obj')
    mgr = vt_object(c, 0x40, {0x58: h58}, nslots=0x100, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = rnd(c, 0x200)
    e.w32(self + 0x123, r.getrandbits(32))
    e.w32(self + 0x138, r.choice([0, 1, r.getrandbits(32)]))
    cnt = r.randint(0, 3)
    nodes = [rnd(c, 0x80) for _ in range(cnt)]
    for i, nd in enumerate(nodes):
        it = vt_object(c, 0x40, {0x28: h28}, nslots=0x100, name='item%d' % i)
        e.w32(nd + 0x54, it)
        e.w32(nd + 0x60, nodes[i + 1] if i + 1 < cnt else 0)
    e.w32(self + 0x50, nodes[0] if cnt else 0)
    return [self]


S(0x513860, 'walk list then notify (no name in map; 45f410 stood in)', 'thiscall', None, gen=_gen, note='area50 batch947 (label A+D)')
