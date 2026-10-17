"""specs_s814.py - animation layer thread, batch 814: ActivateAnim / ActivateAnimSegment by name."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot


def _cstr(e, p, n=64):
    return e.rbytes(p, n).split(b'\0')[0]


def _env(c):
    e, r = c.emu, c.rng

    def printf(e, res):
        e.calllog.append(('printf', e.arg32(0), e.arg32(1), _cstr(e, e.arg32(2)), _cstr(e, e.arg32(3))))
        e.ret(eax=0, argbytes=0)
    sink = e.fake_object('sink', 0x10, nslots=12, slots={0x2c: printf})

    def where(e, res):
        e.calllog.append(('log.where', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)
    e.w32(0x700390, e.fake_object('logger', 0x10, nslots=9, slots={0x20: where}))
    who = b'Hero_%d' % r.randint(0, 99)

    def getname(e, res):
        out, k = e.arg32(0), e.arg32(1)
        e.calllog.append(('GetName', k))
        e.w32(out, out + 4)
        e.wbytes(out + 4, who + b'\0')
        e.ret(eax=out, argbytes=8)
    hdr = r.choice([0, 0, r.getrandbits(32)])
    name = e.alloc(0x20, 4)
    e.wbytes(name, b'Walk_%d\0' % r.randint(0, 9))
    o = vt_object(c, 0x100, {0x21c: vslot('GetAnim', 1, ret=hdr), 0x1d8: getname,
                             0x230: vslot('ActivateAnim(hdr)', 2, ret=r.getrandbits(32)),
                             0x228: vslot('ActivateAnimSegment(hdr)', 5, ret=r.getrandbits(32))}, nslots=0xe0,
                  name='lnk')
    return o, name


def _act(c):
    only_hooks(c, {})
    o, name = _env(c)
    return [o, name, c.rng.getrandbits(32)]


def _seg(c):
    only_hooks(c, {})
    o, name = _env(c)
    return [o, name, c.rng.getrandbits(32), F(c.fv()), F(c.fv())]


S(0x461120, 'ZLNKOBJ::ActivateAnim(name)', 'thiscall', None, ret='eax', gen=_act, note='batch814')
S(0x4613a0, 'ZLNKOBJ::ActivateAnimSegment(name)', 'thiscall', None, ret='eax', gen=_seg, note='batch814')
