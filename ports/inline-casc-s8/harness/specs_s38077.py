"""specs_s38077.py - cascade s8 batch 38077. thiscall(a8, W, H, src) ret 0x10. W, H in 1..11 (so padding and edge clamping vary), src = W*H random dwords. 0x41e290 (new) returns a heap buffer, 0x6378c0 (stdcall 5 args)
is a custom hook that logs the 16 gathered dwords and writes four dwords derived from them (so the gather order is observable) into the out buffer; 0x634273 free logs; the owner's slot 0x58 logs its args and the content of the
result buffer."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g639510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def new(em, res_):
        sz = em.arg32(0)
        em.calllog.append(('new', sz))
        em.ret(eax=e.alloc(max(sz, 16), 4), argbytes=0)
    e.hook(0x41e290, new)

    def xf(em, res_):
        a0, a1, g, tmp, out = (em.arg32(i) for i in range(5))
        v = struct.unpack('<16I', em.rbytes(g, 64))
        em.calllog.append(('xform', a0, a1, v))
        em.wbytes(out, struct.pack('<4I', *[(sum(v[k::4]) * (k + 1) + sum(v)) & 0xffffffff for k in range(4)]))
        em.ret(eax=0, argbytes=20)
    e.hook(0x6378c0, xf)
    e.hook(0x634273, lambda em, res_: (em.calllog.append(('free', em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=0)))

    def s58(em, res_):
        B, nb = em.arg32(0), em.arg32(1)
        em.calllog.append(('s58', em.reg('ecx') != 0, B, nb, em.arg32(2), em.arg32(3), em.arg32(4), em.arg32(5), bytes(em.rbytes(B, nb))))
        em.ret(eax=0, argbytes=24)
    this = obj(c, 0x80, {0x58: e.stub_fn('s58', s58)})
    W = r.randrange(1, 12)
    H = r.randrange(1, 12)
    src = rnd(c, 4 * W * H + 4)
    return [this, r.getrandbits(32), W, H, src]


S(0x639510, 'GUESS blockwise image transform', 'thiscall', None, ret=None, gen=_g639510, note='batch38077')
