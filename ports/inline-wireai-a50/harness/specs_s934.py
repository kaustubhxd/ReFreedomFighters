"""specs_s934.py - batch 934: 0x483f20 (ZPlayer::Load, thiscall, one stream arg, ret 4, returns al). Gate 0x474770 stood in (thiscall, drawn bool).
The stream's slots +0x40, +0x48, +0x50, +0x68, +0x6c, +0x74 each write a drawn word to the pointer (callee pops 4); this's slot +0x628 (no args);
the entries at this+0x461 (count at +0x459, 0..3 entries, one may be null) take slot +0x38 (one arg). Heap writes compared."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.8

    def h474(e, rr):
        e.calllog.append(('474770', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=1 if ok else 0, argbytes=4)

    only_hooks(c, {0x474770: h474})

    def sw(name):
        def h(e, rr):
            e.w32(e.arg32(0), r.getrandbits(32))
            e.calllog.append(('s.' + name, e.arg32(0) != 0))
            e.ret(eax=0, argbytes=4)
        return h

    stream = vt_object(c, 0x40, {0x40: sw('40'), 0x48: sw('48'), 0x50: sw('50'), 0x68: sw('68'), 0x6c: sw('6c'), 0x74: sw('74')},
                       nslots=0x100, name='stream')

    def h38(e, rr):
        e.calllog.append(('entry.38', e.arg32(0) != 0))
        e.ret(eax=0, argbytes=4)

    def h628(e, rr):
        e.calllog.append(('self.628',))
        e.ret(eax=0, argbytes=0)

    self = vt_object(c, 0x1000, {0x628: h628}, nslots=0x200, name='self')
    count = r.randint(0, 3)
    e.w32(self + 0x459, count)
    for i in range(count):
        if i == 1 and r.random() < 0.5:
            e.w32(self + 0x461 + 4 * i, 0)
        else:
            ent = vt_object(c, 0x40, {0x38: h38}, nslots=0x40, name='entry%d' % i)
            e.w32(self + 0x461 + 4 * i, ent)
    return [self, stream]


S(0x483f20, 'ZPlayer::Load (named; gate 474770 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch934 (core slice)')
