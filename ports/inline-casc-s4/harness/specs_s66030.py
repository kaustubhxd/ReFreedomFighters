"""specs_s66030.py - cascade s4 batch 66030: 0x572240 (/GS-protected: describe a channel in a stack buffer and forward the request)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g572240(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))

    def fmt(em, rr):                      # L->slot 0x198 (L, buf, fmt, b) cdecl
        em.calllog.append(('fmt', em.arg32(2), em.arg32(3)))
        em.wbytes(em.arg32(1), b'chan%08x\0' % em.arg32(3))
        em.ret(eax=0, argbytes=0)
    L = obj(c, 0x40, {0x198: e.stub_fn('fmt', fmt)})

    def describe(em, rr):                 # chan->slot 0x378 (buf)
        em.calllog.append(('describe', em.reg('ecx'), bytes(em.rbytes(em.arg32(0), 12))))
        em.ret(eax=0, argbytes=4)
    chans = [obj(c, 0x30, {0x378: e.stub_fn('describe', describe)}) for _ in range(6)]
    tsvc = obj(c, 0x30, {0x80: pystub(c, 1, this=True), 0x88: pystub(c, 1, this=True), 0x90: pystub(c, 1, this=True)})
    xo = obj(c, 0x30, {0x60: pystub(c, 3, this=True)})
    sysobj(c, slots={0xbc: pystub(c, 0, this=True, ret=tsvc), 0x190: pystub(c, 0, this=True, ret=L)},
           table_slots={0x134: pystub(c, 0, this=True, ret=xo)})
    t = e.alloc(0x1a8, 8)
    for i in range(6):
        e.w32(t + 0x180 + 4 * i, chans[i])
    return [t, r.choice([0, 1, 2, 3, 4, 5]), r.getrandbits(32)]


S(0x572240, 'GUESS /GS describe a channel and forward a request', 'thiscall', None, ret='eax', gen=_g572240, note='batch66030')
