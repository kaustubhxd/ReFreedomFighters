"""specs_s38048.py - cascade s8 batch 38048. this has slots 0x2e8 (returns a record object with the name pointer at +4, null 25%, and slots 0x300 / 0x308 / 0x330 returning small values), 0x2f8 (1 arg: target or 0),
0x10c (creates a fresh target with byte +4 bit 0 clear: the null-dereference branch of the original, entered when bit 0 is set, is never generated), 0x1e0 (flag tests, random). The engine table's +0xae4 text
object has slot 0 (2 args, returns one of two heap strings by key), the engine's slot 0x190 returns the formatter object whose slot 0x198 (cdecl, 4 args) writes '<val>:<fmt text>' into the stack buffer.
The target slots 0x88 / 0xb0 / 0xb8 are custom stubs logging the C string in the stack buffer. this[0x60] is zero 12% of the time."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _cstr(em, p):
    out = b''
    while len(out) < 0x100:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g46f020(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s1 = e.alloc(16, 1)
    e.wbytes(s1, b'KeyOne\0')
    s2 = e.alloc(16, 1)
    e.wbytes(s2, b'FmtTwo\0')

    def o0(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        em.calllog.append(('o0', em.reg('ecx'), a, b))
        em.ret(eax=s1 if a == 0x68899c else s2, argbytes=8)
    ob = obj(c, 0x20, {0: e.stub_fn('o0', o0)})

    def f198(em, res_):
        buf, fmt, val = em.arg32(1), em.arg32(2), em.arg32(3)
        em.calllog.append(('fmt', em.reg('ecx') != 0, val, _cstr(em, fmt)))
        em.wbytes(buf, ('%x:' % val).encode() + _cstr(em, fmt)[:8] + b'\0')
        em.ret(eax=0, argbytes=0)
    fobj = obj(c, 0x20, {0x198: e.stub_fn('fmt', f198)})
    so = sysobj(c, {0x190: pystub(c, 0, this=True, ret=fobj)}, table_size=0xb00)
    tb = e.r32(so + 0x9b)
    e.w32(tb + 0xae4, ob)

    def logbuf(name, nargs, argb):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx'), _cstr(em, em.arg32(0))) + tuple(em.arg32(i) for i in range(2, nargs)))
            em.ret(eax=0, argbytes=argb)
        return e.stub_fn(name, h)

    def mktarget():
        t = obj(c, 0x60, {0x88: logbuf('t88', 2, 8), 0xb0: logbuf('tb0', 8, 32), 0xb8: pystub(c, 0, this=True),
                          8: pystub(c, 0, this=True), 0xc: pystub(c, 0, this=True)})
        e.wbytes(t + 4, bytes([r.choice([0, 2, 0x10, 0x80])]) + bytes(3))
        return t
    t0 = mktarget() if r.random() < 0.3 else 0
    t10 = mktarget() if r.random() < 0.4 else 0
    tnew = mktarget()

    def s2f8(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s2f8', em.reg('ecx'), a))
        em.ret(eax=t0 if a == 0 else t10, argbytes=4)
    rec = obj(c, 0x20, {0x300: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 2, 3])),
                        0x308: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 2])),
                        0x330: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 5, 100]))})
    nm = e.alloc(8, 1)
    e.wbytes(nm, b'ent\0')
    e.w32(rec + 4, nm if r.random() > 0.25 else 0)
    me = obj(c, 0x80, {0x2e8: pystub(c, 0, this=True, ret=rec), 0x2f8: e.stub_fn('s2f8', s2f8),
                       0x10c: pystub(c, 2, this=True, ret=tnew),
                       0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))})
    e.w32(me + 0x60, 0 if r.random() < 0.12 else 1)
    return [me]


S(0x46f020, 'GUESS show caption for object', 'thiscall', None, ret=None, gen=_g46f020, note='batch38048')
