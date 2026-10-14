"""specs_s953.py - area 50 batch 953 (residue-16 slice, coordinator split): 0x54a0c0 (thiscall, no args, eax from the tail target 0x54d910, stood in;
the object's slot +0x18 logs), 0x5f9700 (thiscall, one arg, ret 8, returns this; the arg's slot +0x5c logs), 0x656f40 and 0x656900 (thiscall chains through
slot +0xc of this: the first call returns an object; the second call (0x656f40) or slot +0x144 (0x656900) logs), 0x657940 (thiscall, one arg, returns al:
slot +0xc returns an object whose word at +2 and dword at +0x50 are drawn)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen_54a(c):
    e, r = c.emu, c.rng
    rv = r.getrandbits(32)

    def h54d(e, rr):
        e.calllog.append(('54d910', e.reg('ecx') != 0))
        e.ret(eax=rv, argbytes=0)

    only_hooks(c, {0x54d910: h54d})

    def h18(e, rr):
        e.calllog.append(('c.18', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    self = rnd(c, 0x8100)
    if r.random() < 0.7:
        cobj = vt_object(c, 0x40, {0x18: h18}, nslots=0x100, name='c')
        e.w32(self + 0x8061, cobj)
    else:
        e.w32(self + 0x8061, 0)
    return [self]


def _gen_5f9(c):
    e, r = c.emu, c.rng

    def h5c(e, rr):
        e.calllog.append(('a.5c', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    a = vt_object(c, 0x40, {0x5c: h5c}, nslots=0x100, name='a')
    self = rnd(c, 0x40)
    return [self, a, r.getrandbits(32)]


def _gen_chain(c, second_slot_144=False):
    e, r = c.emu, c.rng
    obj = rnd(c, 0x100)
    e.w32(obj + 0x94, r.getrandbits(32))
    state = {'n': 0}

    def h0c(e, rr):
        state['n'] += 1
        e.calllog.append(('self.c', state['n'], e.arg32(0)))
        e.ret(eax=obj if state['n'] == 1 else 0, argbytes=4)

    def h144(e, rr):
        e.calllog.append(('self.144', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    slots = {0xc: h0c}
    if second_slot_144:
        slots[0x144] = h144
    self = vt_object(c, 0x200, slots, nslots=0x200, name='self')
    return self, obj


def _gen_656f40(c):
    self, obj = _gen_chain(c)
    return [self, r_arg(c)]


def _gen_656900(c):
    self, obj = _gen_chain(c, second_slot_144=True)
    return [self, r_arg(c), c.rng.getrandbits(32)]


def _gen_657(c):
    e, r = c.emu, c.rng
    obj = rnd(c, 0x80)
    e.w16(obj + 2, r.choice([0, 0, 1, 0x100])) if hasattr(e, 'w16') else e.wbytes(obj + 2, bytes([r.choice([0, 1]), 0]))
    e.w32(obj + 0x50, r.choice([0, 1, 2, r.getrandbits(32)]))

    def h0c(e, rr):
        e.calllog.append(('self.c', e.arg32(0)))
        e.ret(eax=obj, argbytes=4)

    self = vt_object(c, 0x100, {0xc: h0c}, nslots=0x100, name='self')
    return [self, r.getrandbits(32)]


def r_arg(c):
    return c.rng.getrandbits(32)


S(0x54a0c0, 'tail to 54d910 after a slot call (no name in map)', 'thiscall', None, ret='eax', gen=_gen_54a, note='area50 batch953 (residue 16)')
S(0x5f9700, 'init and call slot 0x5c of arg (no name in map)', 'thiscall', None, ret='eax', gen=_gen_5f9, note='area50 batch953 (residue 16)')
S(0x656f40, 'chain through slot 0xc (no name in map)', 'thiscall', None, gen=_gen_656f40, note='area50 batch953 (residue 16)')
S(0x656900, 'chain through slot 0xc and 0x144 (no name in map)', 'thiscall', None, gen=_gen_656900, note='area50 batch953 (residue 16)')
S(0x657940, 'flag from slot 0xc object (no name in map)', 'thiscall', None, ret='al', gen=_gen_657, note='area50 batch953 (residue 16)')
