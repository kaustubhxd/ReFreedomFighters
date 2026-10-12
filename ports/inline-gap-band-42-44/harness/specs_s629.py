"""specs_s629.py - band 0x421000-0x441000, batch 629 (see src/batch629.cpp). Every callee is a recording slot of a fake object.
The list (0x423fb0, 0x424460) has 0..3 nodes; a node's slot 0x108 answers an object whose slot 0 or 4 is recorded.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

SYS_GLOBAL = 0x70039c


def _rec(name, off, nargs, ret):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _block(c, size):
    a = c.emu.alloc(size, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a


def _gen_sound(c):
    r = c.rng
    self_ = _block(c, 0x200)
    snd = c.emu.fake_object('snd', 0x40, nslots=0x110, slots={0x104: _rec('snd.104', 0x104, 3, 0)}) \
        if r.random() < 0.8 else 0
    sys_ = _block(c, 0x2000)
    c.emu.w32(sys_ + 0x1a9f, snd)
    c.emu.w32(SYS_GLOBAL, sys_)
    return [self_]


def _gen_three_self(c):
    r = c.rng
    e_val = (r.getrandbits(32) | 1) if r.random() < 0.85 else 0   # the lookup result: 0 with 15% chance (the null case)
    slots = {0xc: _rec('self.c', 0xc, 1, e_val if e_val else 0),
             0x38: _rec('self.38', 0x38, 3, 0),
             0x1c: _rec('self.1c', 0x1c, 1, r.getrandbits(32))}
    self_ = c.emu.fake_object('self3', 0x40, nslots=0x100, slots=slots)
    return [self_, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _gen_list(slot):
    def gen(c):
        r = c.rng
        self_ = _block(c, 0x2000)
        nodes = []
        for k in range(r.randint(0, 3)):
            obj = c.emu.fake_object('leaf%d' % k, 0x40, nslots=0x20,
                                    slots={0: _rec('leaf.0', 0, 3, 0), 4: _rec('leaf.4', 4, 3, 0)})

            def h108(e, rr, obj=obj):
                e.calllog.append(('node.108', 0x108, e.reg('ecx'), ()))
                e.ret(eax=obj, argbytes=0)
            node = c.emu.fake_object('node%d' % k, 0x40, nslots=0x110, slots={0x108: h108})
            nodes.append(node)
        for a, b in zip(nodes, nodes[1:]):
            c.emu.w32(a + 8, b)
        if nodes:
            c.emu.w32(nodes[-1] + 8, 0)
        c.emu.w32(self_ + 0x190f, nodes[0] if nodes else 0)
        return [self_, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]
    return gen


S(0x431fb0, 'CConfiguration::ApplySound: four slot 0x104 calls on the sound object', 'thiscall', None, ret=None, gen=_gen_sound)
S(0x4265e0, 'slot 0xc, then slot 0x38 and slot 0x1c', 'thiscall', None, ret='eax', gen=_gen_three_self)
S(0x423fb0, 'list walk: slot 0x108 node, slot 0 of its object', 'thiscall', None, ret=None, gen=_gen_list(0))
S(0x424460, 'list walk: slot 0x108 node, slot 4 of its object', 'thiscall', None, ret=None, gen=_gen_list(4))
