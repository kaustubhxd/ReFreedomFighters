"""specs_s752.py - area 72 skipped forwarders. 0x533ba0 runs 0x5390b0 (exe) on a fake object: slot 0xa8 (no args) and 0x1bc
(one argument) log and return. 0x4f3c30 forwards to 0x43ea20 (hooked, logged, 0 args; GUESS arity). The four virtual tail jumps
(slots 0x8, 0x3c, 0x158, 0x18c) are logging stubs with 0 arguments (GUESS arity)."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _obj(c, e, slots):
    o = _rnd(c, 0x400)
    e.w32(o, e.fake_vtable('obj', 0x200, slots))
    return o


def _log_slot(e, off, nargs):
    def f(em, r):
        e.calllog.append(('vobj', off, nostk(e.reg('ecx')), tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=0x1000 + off, argbytes=4 * nargs)
    return f


def _g_533ba0(c):
    e = c.emu
    o = _obj(c, e, {0xa8: _log_slot(e, 0xa8, 0), 0x1bc: _log_slot(e, 0x1bc, 1)})
    return [o]


def _g_4f3c30(c):
    e = c.emu
    def h(em, r):
        e.calllog.append(('tgt', 0x43ea20, nostk(e.reg('ecx')), ()))
        em.ret(eax=0, argbytes=0)
    e.hook(0x43ea20, h)
    return [_rnd(c, 0x400)]


def _g_virt(off):
    def g(c):
        e = c.emu
        return [_obj(c, e, {off: _log_slot(e, off, 0)})]
    return g


S(0x533ba0, 'fwd_5390b0', 'thiscall', None, ret='al', gen=_g_533ba0, note='b752 area 72 forwarder; 0x5390b0 exe, slots faked')
S(0x4f3c30, 'fwd_43ea20', 'thiscall', None, ret=None, gen=_g_4f3c30, note='b752 area 72 forwarder; GUESS arity 0')
S(0x4d1630, 'virt_8', 'thiscall', None, ret='eax', gen=_g_virt(0x8), note='b752 area 72 virtual tail jump; GUESS arity 0')
S(0x4d1e30, 'virt_3c', 'thiscall', None, ret='eax', gen=_g_virt(0x3c), note='b752 area 72 virtual tail jump; GUESS arity 0')
S(0x4f04d0, 'virt_158', 'thiscall', None, ret='eax', gen=_g_virt(0x158), note='b752 area 72 virtual tail jump; GUESS arity 0')
S(0x536640, 'virt_18c', 'thiscall', None, ret='eax', gen=_g_virt(0x18c), note='b752 area 72 virtual tail jump; GUESS arity 0')
