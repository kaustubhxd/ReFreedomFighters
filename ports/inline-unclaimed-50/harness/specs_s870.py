"""specs_s870.py - area 50, batch 870: CMAINCAMERACONTROL::Save (0x4fd890), thiscall, one stack arg (the stream), ret 4, bool.
The stream's slots log their argument values (dwords 0x3c and 0x44, words 0x40, the float 0x4c, bytes 0x60, the vector 0x6c and
the 16-byte block 0x10 by pointer). The object is random; the flag word at +4 is random (bit 6 is cleared by the function)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})

    def logv(name, nargs):
        def h(e, rr):
            e.calllog.append((name,) + tuple(e.arg32(k) for k in range(nargs)))
            e.ret(eax=0, argbytes=4 * nargs)
        return h

    def log4c(e, rr):
        e.calllog.append(('s.4c', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def log10(e, rr):
        p, n = e.arg32(0), e.arg32(1)
        e.calllog.append(('s.10', p, n))
        e.ret(eax=0, argbytes=8)

    s = vt_object(c, 0x40, {0x3c: logv('s.3c', 1), 0x44: logv('s.44', 1), 0x40: logv('s.40', 1),
                            0x4c: log4c, 0x60: logv('s.60', 1), 0x6c: logv('s.6c', 1), 0x10: log10},
                  nslots=0x100, name='stream')
    self = rnd(c, 0x200)
    return [self, s]


S(0x4fd890, 'CMAINCAMERACONTROL::Save', 'thiscall', None, gen=_gen, note='area50 batch870')
