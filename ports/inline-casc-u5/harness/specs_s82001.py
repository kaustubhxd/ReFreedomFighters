"""0x501290: distance from a looked-up record's transformed position."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj

def _array(c, word, flag=None):
    e = c.emu
    data = rnd(c, 8)
    e.w32(data, word)
    if flag is not None:
        e.wbytes(data + 4, bytes([flag]))
    inner = rnd(c, 12)
    e.w32(inner, data)
    e.w32(inner + 8, 1)
    outer = rnd(c, 12)
    e.w32(outer, inner)
    e.w32(outer + 4, 0)
    e.w32(outer + 8, 1)
    return outer

def _g501290(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'))
    ah = e.stub_fn('assert hook', lambda em, rr: em.ret(eax=0))
    e.w32(0x7003b0, ah)

    arr_a = _array(c, 0xdeadbeef, r.choice([0, 2]))
    arr_b = _array(c, r.choice([1, 2, 7, 0x1234]))
    arg = rnd(c, 12)
    e.w32(arg + 4, arr_b)
    e.w32(arg + 8, arr_a)

    record = rnd(c, 0x60)
    tab = sysobj(c, table_slots={0x54: pystub(c, 1, this=True, ret=record)})
    me = rnd(c, 0x20)
    target = obj(c, 0x100, {0x8c: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x90 // 4)
    e.w32(me + 0xc, target)

    xyz = [3.25, -4.5, 7.125]
    def fill(em, k):
        em.wbytes(em.arg32(0), struct.pack('<fff', *xyz))
    hook_rec(c, 0x4db670, 1, pop=4, this=True, deref={0: 3}, side=fill)
    return [me, arg]

S(0x501290, 'GUESS vector magnitude after lookup', 'thiscall', None, ret='xmm0', gen=_g501290, note='batch82001')
