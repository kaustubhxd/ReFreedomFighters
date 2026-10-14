"""specs_s34118.py - 0x4e9200: every callee is a recorder (stack-local pointers are recorded as one marker); the register arguments (edx) are logged; 0x4e9280 records its three local pointers through stackmark; the /GS check is a zero-argument recorder."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _tag(name, st):
    def side(em, k):
        em.calllog.append(('edx', em.reg('edx')))
        st[em.reg('ecx')] = name
    return side


def _g4e9200(c):
    clear_hooks(c)
    r = c.rng
    st = {}
    hook_rec(c, 0x4de4b0, 1, this='mark', pop=4, ret=r.getrandbits(32), side=_tag('4de4b0', st))
    hook_rec(c, 0x43e920, 1, this='mark', pop=4, ret=r.getrandbits(32), side=_tag('43e920', st))
    hook_rec(c, 0x441a60, 0, this='mark', pop=0, ret=r.getrandbits(32), side=_tag('441a60', st))
    hook_rec(c, 0x459fc0, 1, this='mark', pop=4, ret=r.getrandbits(32), side=_tag('459fc0', st))
    hook_rec(c, 0x4e9280, 3, this=True, ret=r.getrandbits(32), stackmark=(0, 1, 2),
             side=lambda em, k: em.calllog.append(('which', tuple(st.get(em.arg32(i), '?') for i in range(3)))))
    hook_rec(c, 0x633654, 0, pop=0)
    return [rnd(c, 0x60), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4e9200, 'GUESS build three locals and hand them over', 'thiscall', None, ret=None, gen=_g4e9200, note='batch34118')
