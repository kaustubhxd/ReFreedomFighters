"""specs_s844.py - area 50, batch 844: ZItemTemplateWeapon::Load. ZGROUP::Load is hooked; the stream's virtuals fill
values and the global manager resolves words (logged). Values are stored into the object and compared as bytes."""
import struct
from pilot import S
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x440e10: logged_fn('ZGROUP::Load', 1)})
    stream_vals = [r.getrandbits(32) for _ in range(4)]
    res = {'i': 0}

    def s40(e, rr):
        p = e.arg32(0)
        v = stream_vals[res['i'] % 4]
        res['i'] += 1
        e.w32(p, v)
        e.calllog.append(('s.read', v))
        e.ret(eax=0, argbytes=4)

    def mgr58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=(k * 3 + 1) & 0xffffffff, argbytes=4)

    def fl(name):
        def h(e, rr):
            p = e.arg32(0)
            e.wf32(p, c.fv(-100, 100))
            e.calllog.append((name, round(e.rf32(p), 6) if e.rf32(p) == e.rf32(p) else 'nan'))
            e.ret(eax=0, argbytes=4)
        return h

    def logv(name):
        def h(e, rr):
            e.calllog.append((name, e.arg32(0)))
            e.ret(eax=0, argbytes=4)
        return h

    stream = vt_object(c, 0x40, {0x70: logv('s.int70'), 0x74: logv('s.ptr74'), 0x6c: logv('s.ptr6c'),
                                 0x50: fl('s.float50'), 0x40: s40}, nslots=0x80, name='stream')
    mgr = vt_object(c, 0x40, {0x58: mgr58}, nslots=0x80, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = rnd(c, 0x140)
    e.w32(self + 0x70, r.getrandbits(32))
    return [self, stream]


S(0x46f6e0, 'ZItemTemplateWeapon::Load', 'thiscall', None, ret='al', gen=_gen, note='area50 batch844')
