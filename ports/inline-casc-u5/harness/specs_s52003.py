"""specs_s52003.py - tier H. 0x52b170: this[0x24] / this[0x31] / [0x701b4d] / S[0x48] / S[0x99] flags each set about half the time, logger object at 0x700390, assert hook, 0x52b080 a recorder, 0x52e830 a custom recorder (ECX, both vectors by content, float, the byte args masked to 8 bits)."""
import struct
from pilot import S, EDGE_F, F
import recruits_util
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-100, 100)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _fv(r):
    return struct.unpack('<f', struct.pack('<I', _fbits(r)))[0]


def _g52b170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    e.wbytes(0x701b4d, bytes([1 if r.random() < 0.3 else 0]))
    hook_rec(c, 0x52b080, 0, this=True)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    ret = r.getrandbits(32)

    def h(em, rr):
        v = [em.reg('ecx')]
        for i in (0, 1):
            p = em.arg32(i)
            v += [em.r32(p + 4 * j) for j in range(3)]
        v += [em.arg32(2), em.arg32(3) & 0xff, em.arg32(4) & 0xff, em.arg32(5), em.arg32(6)]
        em.calllog.append(('52e830',) + tuple(v))
        em.ret(eax=ret, argbytes=0x1c)
    e.hook(0x52e830, h)
    recruits_util._HOOKED.add(0x52e830)
    me = rnd(c, 0x100)
    e.wbytes(me + 0x24, bytes([1 if r.random() < 0.2 else 0]))
    e.wbytes(me + 0x31, bytes([0 if r.random() < 0.2 else r.getrandbits(8) | 1]))
    e.w32(me + 0x20, _fbits(r))
    P = rnd(c, 12)
    Q = rnd(c, 12)
    for i in range(3):
        e.w32(P + 4 * i, _fbits(r))
        e.w32(Q + 4 * i, _fbits(r))
    s = rnd(c, 0xb0)
    e.wbytes(s + 0x48, bytes([r.choice([0, 0, 1, r.getrandbits(8)])]))
    e.wbytes(s + 0x99, bytes([r.choice([0, 1, r.getrandbits(8)])]))
    T = rnd(c, 0x20)
    return [me, P, Q, F(_fv(r)), r.getrandbits(8), r.getrandbits(8), s, T]


S(0x52b170, 'GUESS segment test lifted', 'thiscall', None, ret='eax', gen=_g52b170, note='batch52003')
