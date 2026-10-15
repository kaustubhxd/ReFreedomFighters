"""specs_s36089.py - cascade s4 batch 36089: 0x562280 (/GS-protected: format a name through the log object, look it up and report)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g562280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    cnt = [0]

    def fmt(em, rr):                      # L->slot 0x198 (L, buf, fmt, args...) cdecl
        k = cnt[0]
        cnt[0] += 1
        buf = em.arg32(1)
        em.calllog.append(('fmt', k, em.arg32(0), em.arg32(2), em.arg32(3), em.arg32(4) if k == 0 else 0))
        em.wbytes(buf, bytes([(k * 31 + i * 7 + em.arg32(3)) & 0xff for i in range(8)]))
        em.ret(eax=0, argbytes=0)
    L = obj(c, 0x40, {0x198: e.stub_fn('fmt', fmt)})
    found = 0 if r.random() < 0.2 else rnd(c, 0x110)

    def lookup(em, rr):                   # 0x49df60: ecx = table[0xae4], (buf, buf2) ret 8
        em.calllog.append(('lookup', em.reg('ecx'), bytes(em.rbytes(em.arg32(0), 8))))
        em.ret(eax=found, argbytes=8)
    e.hook(0x49df60, lookup)
    out = obj(c, 0x20, {0x6c: pystub(c, 1, this=True, deref={0: 2}, ret=r.getrandbits(32))})
    so = sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=L)})
    e.w32(so + 0x1a9f, 0 if r.random() < 0.25 else out)
    tab = int.from_bytes(bytes(e.rbytes(so + 0x9b, 4)), 'little')
    e.w32(tab + 0xae4, rnd(c, 8))
    return [r.getrandbits(32), r.getrandbits(32)]


S(0x562280, 'GUESS /GS log a lookup request and report the result', 'stdcall', None, ret=None, gen=_g562280, note='batch36089')
