"""specs_s38046.py - cascade s8 batch 38046. The id argument is one of the four ids at this+0x80 / 0x86 / 0x82 / 0x84 (90%) or unrelated; v in 0..9, 99, 100, -1 and small values; the table object
(engine +0x9b) slot 0x58 maps ids to objects (or 0) and logs every call; the objects' slot 0x288 is a custom stub that logs the C string it is given (stack buffers differ in address), slot 0xbc is
recorded; 0x42ac56 (sprintf) is a Python hook that formats the values with %x so the text is observable. The table 0x6ef80c is read from the image."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _cstr(em, p):
    out = b''
    while len(out) < 40:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g5d95a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    import struct
    ids = r.sample(range(1, 0x10000), 4)
    pool = list(range(1, 9))

    def s288(em, res_):
        a, s = em.arg32(0), em.arg32(1)
        em.calllog.append(('s288', em.reg('ecx'), a, _cstr(em, s)))
        em.ret(eax=0, argbytes=8)
    objs = {}
    for i in pool:
        if r.random() > 0.2:
            objs[i] = obj(c, 0x40, {0x288: e.stub_fn('s288', s288), 0xbc: pystub(c, 1, this=True)})

    def s58(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s58', em.reg('ecx'), a))
        em.ret(eax=objs.get(a, 0), argbytes=4)
    sysobj(c, {}, table_slots={0x58: e.stub_fn('s58', s58)})

    def sprintf(em, res_):
        buf, fmt = em.arg32(0), em.arg32(1)
        n = 2 if fmt == 0x6b64f4 else 1
        vals = tuple(em.arg32(2 + i) for i in range(n))
        em.calllog.append(('sprintf', fmt, vals))
        em.wbytes(buf, (('%x:' % (fmt & 0xff)) + '.'.join('%x' % v for v in vals)).encode()[:11] + b'\0')
        em.ret(eax=0, argbytes=0)
    e.hook(0x42ac56, sprintf)
    me = rnd(c, 0xa0)
    for off, v in zip((0x80, 0x86, 0x82, 0x84), ids):
        e.wbytes(me + off, struct.pack('<H', v))
    for off in (0x60, 0x5c, 0x58, 0x74, 0x78, 0x7c):
        e.w32(me + off, r.choice(pool + [99]))
    idv = r.choice(ids) if r.random() < 0.9 else r.randrange(0x10000)
    if r.random() < 0.3:
        idv |= r.getrandbits(16) << 16
    v = r.choice([0, 1, 2, 3, 5, 7, 8, 9, 50, 99, 100, 0xffffffff, 0xfffffffe, r.getrandbits(32)])
    return [me, idv, v]


S(0x5d95a0, 'GUESS event handler set numbered value', 'thiscall', None, ret='eax', gen=_g5d95a0, note='batch38046')
