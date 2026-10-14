"""specs_s945.py - area 50 batch 945: 0x573860 (thiscall, two words, ret 8). Stand-ins (logged): the manager's slot +0x114 (thiscall, four words, returns a
drawn dword; the caller compares its low word), 0x561c60 (thiscall, no args) and 0x561cb0 (thiscall: this, two words, returns a drawn dword). The first word
is drawn with its low word equal to the result's low word about half the time, so both branches run; the byte at this+0x88 is drawn 0, 1 or 2."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    rv = r.getrandbits(32)

    def h114(e, rr):
        e.calllog.append(('mgr.114', e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=rv, argbytes=16)

    def h561c60(e, rr):
        e.calllog.append(('561c60', e.reg('ecx')))
        e.ret(eax=0, argbytes=0)

    def h561cb0(e, rr):
        e.calllog.append(('561cb0', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=rv ^ 0x5a5a5a5a, argbytes=8)

    only_hooks(c, {0x561c60: h561c60, 0x561cb0: h561cb0})
    mgr = vt_object(c, 0x40, {0x114: h114}, nslots=0x100, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = rnd(c, 0x100)
    e.wbytes(self + 0x88, bytes([r.choice([0, 1, 2])]))
    if r.random() < 0.5:
        a = (rv & 0xffff) | (r.getrandbits(16) << 16)
    else:
        a = r.getrandbits(32)
    b = r.getrandbits(32)
    return [self, a, b]


S(0x573860, 'dispatch on low word (no name in map; 561c60, 561cb0 and 0x114 stood in)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch945 (label D)')
