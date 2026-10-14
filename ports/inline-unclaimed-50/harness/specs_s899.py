"""specs_s899.py - gap-band slice, batch 899: three wrappers (thiscall, one stack arg, ret 4). The object's slots +0xec and +0xe8 log
(no args, return nothing). The helpers 0x41e8a0 (returns a byte), 0x41ee20 and 0x41eee0 (return dwords) are stood in and log their
argument. The argument is drawn small or random."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c, res=None):
    e, r = c.emu, c.rng
    n = r.choice([0, 1, 0x40, r.getrandbits(32)])
    rv = r.getrandbits(32)
    b = r.randint(0, 1)

    def h_ec(e, rr):
        e.calllog.append(('self.ec',))
        e.ret(eax=0, argbytes=0)

    def h_e8(e, rr):
        e.calllog.append(('self.e8',))
        e.ret(eax=0, argbytes=0)

    def h_8a0(e, rr):
        e.calllog.append(('h.41e8a0', e.arg32(0)))
        e.ret(eax=b, argbytes=4)

    def h_20(e, rr):
        e.calllog.append(('h.41ee20', e.arg32(0)))
        e.ret(eax=rv, argbytes=4)

    def h_e0(e, rr):
        e.calllog.append(('h.41eee0', e.arg32(0)))
        e.ret(eax=rv ^ 0x55, argbytes=4)

    only_hooks(c, {0x41e8a0: h_8a0, 0x41ee20: h_20, 0x41eee0: h_e0})
    from anim_common import vt_object
    self = vt_object(c, 0x80, {0xec: h_ec, 0xe8: h_e8}, nslots=0x80, name='self')
    return [self, n]


S(0x41f510, 'ZSysMemGC::NewWithRef (named)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch899 (band slice)')
S(0x41f7c0, 'ZSysMem::ExgRefs (named)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch899 (band slice)')
S(0x41f8c0, 'ZSysMemGC::New (named)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch899 (band slice)')
