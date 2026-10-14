"""specs_s950.py - area 50 batch 950: 0x562140 (stdcall, two words, ret 8, void; ECX unused). Stand-ins (logged): 0x4db9a0 (thiscall, one flag word; returns
a drawn bool), the node objects' slot +0x250 (thiscall, one word), and the list object's slot +0x50 (thiscall, one pointer; the handler moves the node
variable to the node's +0x60 link). The list is drawn with 0 to 3 nodes, and the first node drawn null sometimes."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    rv = r.random() < 0.6

    def h4db(e, rr):
        e.calllog.append(('4db9a0', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=1 if rv else 0, argbytes=4)

    only_hooks(c, {0x4db9a0: h4db})

    def h250(e, rr):
        e.calllog.append(('item.250', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h50(e, rr):
        p = e.arg32(0)
        cur = e.r32(p)
        e.calllog.append(('list.50', e.arg32(0) != 0, cur != 0))
        e.w32(p, e.r32(cur + 0x60) if cur else 0)
        e.ret(eax=0, argbytes=4)

    L = vt_object(c, 0x40, {0x50: h50}, nslots=0x100, name='list')
    cnt = r.randint(0, 3)
    nodes = [rnd(c, 0x80) for _ in range(cnt)]
    for i, nd in enumerate(nodes):
        item = vt_object(c, 0x40, {0x250: h250}, nslots=0x200, name='item%d' % i)
        e.w32(nd + 0x54, item)
        e.w32(nd + 0x60, nodes[i + 1] if i + 1 < cnt else 0)
    e.w32(L + 8, nodes[0] if cnt else 0)
    a = rnd(c, 0x40)
    if r.random() < 0.1:
        L = 0            # a null list: the port returns at once
    return [a, L]


S(0x562140, 'walk nodes with flag and item call (no name in map; 4db9a0 stood in)', 'stdcall', None, gen=_gen, note='area50 batch950 (label D)')
