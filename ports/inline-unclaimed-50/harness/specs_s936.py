"""specs_s936.py - batch 936: 0x47ade0 (ZActor::Save, thiscall, one stream arg, ret 4, returns al = 1). The stream and every object the calls return share
one stand-in vtable with slots 0x3c, 0x4c, 0x60, 0x68, 0x10, 0x24, 0x44. Each slot logs its object label (stream or chain) and its argument (floats and
dwords as values), and returns the chain object (so the exe's EAX chain is exercised). The gate 0x4753c0 is stood in (thiscall; logs). The manager
(g+0x9b) slot +0x4c returns a drawn dword. The block at this+0x695 is drawn present or null (its count and pointers are read as values only)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    box = {}

    def mk(slot_name):
        def h(e, rr):
            ecx = e.reg('ecx')
            who = 'st' if ecx == box['st'] else 'chain'
            if slot_name in ('4c',):
                raw = e.arg32(0)
                e.calllog.append((who, slot_name, repr(e.rf32(e.r32(e.reg('esp')) and e.reg('esp')) if False else raw)))
            else:
                e.calllog.append((who, slot_name, e.arg32(0) if slot_name != '10' else (e.arg32(0), e.arg32(1))))
            e.ret(eax=box['chain'], argbytes=(8 if slot_name == '10' else 4))
        return h

    slots = {0x3c: mk('3c'), 0x4c: mk('4c'), 0x60: mk('60'), 0x68: mk('68'), 0x10: mk('10'), 0x24: mk('24'), 0x44: mk('44')}
    chain = vt_object(c, 0x40, slots, nslots=0x200, name='chain')
    box['chain'] = chain
    st = vt_object(c, 0x40, slots, nslots=0x200, name='st')
    box['st'] = st

    def g4753(e, rr):
        e.calllog.append(('4753c0', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=0, argbytes=4)

    rv = r.getrandbits(32)

    def mgr4c(e, rr):
        e.calllog.append(('mgr.4c', e.arg32(0)))
        e.ret(eax=rv, argbytes=4)

    only_hooks(c, {0x4753c0: g4753})
    mgr = vt_object(c, 0x40, {0x4c: mgr4c}, nslots=0x100, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = rnd(c, 0x800)
    if r.random() < 0.6:
        blk = rnd(c, 0x40)
        e.w32(self + 0x695, blk)
    else:
        e.w32(self + 0x695, 0)
    return [self, st]


S(0x47ade0, 'ZActor::Save (named; gate 4753c0 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch936 (core slice)')
