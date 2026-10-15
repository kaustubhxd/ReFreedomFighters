"""specs_s44010.py - t5 (Sonnet) batch 44010: 0x554e50."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g554e50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    fv = struct.unpack('<f', struct.pack('<f', r.uniform(-100, 100)))[0]
    e.w32(0x6762d4, pystub(c, 1, pop=0, st0=fv, side=lambda emu, k: emu.calllog.append(('imp', emu.arg32(0)))))
    A = rnd(c, 0x10)
    B = rnd(c, 0x10)
    rec = rnd(c, 0x10)
    O = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32), side=_log('s34'))}, nslots=0x38 // 4)
    e.w32(rec, r.choice([O, r.getrandbits(32)]))
    st = r.choice([3, 4, 3, 4, 0, 1, 2, 5, 0xff])
    if st == 4:
        e.w32(rec, O)
    e.wbytes(rec + 4, bytes([st]))
    flt = rnd(c, 0x10)
    tgt = rnd(c, 0x10)

    def lk(emu, k):
        ec = emu.reg('ecx')
        if ec == A:
            return rec if emu.arg32(0) == 0 else flt
        return tgt
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lk)
    hook_rec(c, 0x500360, 1, this=True, pop=4)
    ok = r.choice([0, 1, 1])

    def put(emu, k):
        emu.calllog.append(('s5c', emu.arg32(0)))
        emu.w32(emu.arg32(1), r.choice([0x3f800000, r.getrandbits(32), 0x7fc00000, 0]))
    so = sysobj(c, slots={0x5c: pystub(c, 2, this=True, ret=ok, side=put)})
    inner = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, side=_log('log2'))}, nslots=0x30 // 4)
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    me = rnd(c, 0x10)
    e.w32(me + 4, A)
    e.w32(me + 8, B)
    return [me]


S(0x554e50, 'GUESS lookup state and set float', 'stdcall', None, ret=None, gen=g554e50, nan_heap=True, note='batch44010')
