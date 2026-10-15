"""specs_s42009.py - Sonnet t3 batch 42009. 0x4e13c0: hooked 0x4e1590 (this, returns a small size), assert hook 0x7003b0 (always set). Cursor [this+8] walks a random byte buffer whose
tag bytes are mostly 1/2/3 (also 0x41, 0xff, others -> assert path); count 1..4."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g4e13c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e1590, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 1, 4, 8, 9, 12]))

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    buf = rnd(c, 0x100)
    for i in range(0, 0x80, 13):
        e.wbytes(buf + i, bytes([r.choice([1, 2, 3, 1, 2, 3, 0x41, 0x42, 0xff, 0, 4, r.getrandbits(8)])]))
    me = rnd(c, 0x20)
    e.w32(me + 8, buf + r.choice([0, 0, 1, 5]))
    out = rnd(c, 0x40)
    return [me, out, r.choice([1, 1, 2, 3, 4])]


S(0x4e13c0, 'GUESS read tagged numbers as doubles', 'thiscall', None, ret=None, gen=g4e13c0, note='batch42009')
