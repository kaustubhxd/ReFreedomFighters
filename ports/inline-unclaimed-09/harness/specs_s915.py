"""specs_s915.py - unclaimed-09 batch 7 (docs/20-unclaimed-09.md, claim 7): ZActionControlMap::End().

Stubs (unverified callees, logged in the call log; arguments that are stack pointers are not logged):
- global+0x9b object: vt+0x134 returns the object r (heap, fixed for the case).
- r: vt+0x90 writes the flag byte (0 or 1, random per case) through its pointer argument; logs its constant.
- the object at global+0x1907 (may be null, one case in eight): vt+0x14 logs its constant argument. In about one case
  in four the first call clears global+0x1907, so the exe's reload of that field is exercised.
The global object is 0x2000 random bytes; the spec writes the fields it needs."""
from pilot import S
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    flag = rng.getrandbits(1)
    clear_after_first = rng.random() < 0.25

    def get134(e2, r):
        e2.calllog.append(('Get134',))
        e2.ret(eax=robj, argbytes=0)

    def set90(e2, r):
        e2.calllog.append(('Set90', e2.arg32(0)))
        e2.w8(e2.arg32(1), flag)
        e2.ret(eax=0, argbytes=8)

    def call14(e2, r):
        arg = e2.arg32(0)
        e2.calllog.append(('Call14', arg))
        if clear_after_first and arg == 0x6b2028:
            e2.w32(g + 0x1907, 0)
        e2.ret(eax=0, argbytes=4)

    g = _rnd(c, 0x2000)
    o = e.fake_object('actmap_global_obj', 0x40, slots={0x134: get134})
    robj = e.fake_object('actmap_r', 0x40, slots={0x90: set90})
    e.w32(g + 0x9b, o)
    e.w32(0x70039c, g)
    if rng.random() < 0.125:
        e.w32(g + 0x1907, 0)
    else:
        a = e.fake_object('actmap_a', 0x40, slots={0x14: call14})
        e.w32(g + 0x1907, a)
    return [_rnd(c, 0x40)]


S(0x5b2c80, 'ZActionControlMap::End (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b7; vtable calls stubbed (unverified callees)')
