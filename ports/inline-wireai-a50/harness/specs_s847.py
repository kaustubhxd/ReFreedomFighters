"""specs_s847.py - area 50, batch 847: ZFFHERO::CreateMovements. The player's base, the allocator and the nine movement
constructors are hooked: each allocates a fresh object (logged); the hero's vt +0x624 is logged with the object's address
(same allocation order in both runs, so addresses match)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, vslot


def _ctor(name):
    def h(e, res):
        p, this, arg = e.reg('ecx'), e.arg32(0), e.arg32(1)
        e.calllog.append((name, this, arg))
        e.ret(eax=p, argbytes=8)
    return h


def _gen(c):
    e, r = c.emu, c.rng
    def alloc(e, res):
        sz = e.arg32(0)
        e.calllog.append(('new', sz))
        e.ret(eax=e.alloc(sz, 8), argbytes=0)
    hooks = {0x482ac0: vslot('ZPlayer::CreateMovements', 0), 0x41e290: alloc}
    only_hooks(c, {0x482ac0: vslot('ZPlayer::CreateMovements', 0), 0x41e290: alloc,
                   0x5e1110: _ctor('m5e1110'), 0x5e1200: _ctor('m5e1200'), 0x5e1160: _ctor('m5e1160'),
                   0x5e1190: _ctor('m5e1190'), 0x5e11c0: _ctor('m5e11c0'), 0x5e10a0: _ctor('m5e10a0'),
                   0x5e0ee0: _ctor('m5e0ee0'), 0x5e0f80: _ctor('m5e0f80'), 0x5e0ff0: _ctor('m5e0ff0')})
    self = vt_object(c, 0x2000, {0x624: vslot('hero.Register', 1)}, nslots=0x300, name='hero')
    return [self]


S(0x590e20, 'ZFFHERO::CreateMovements', 'thiscall', None, gen=_gen, note='area50 batch847')
