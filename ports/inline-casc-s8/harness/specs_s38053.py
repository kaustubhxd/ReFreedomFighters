"""specs_s38053.py - cascade s8 batch 38053 (0x56f860). Keys drawn from the special values (0x31, 0x32, 0x3e8, 0x7d0, 0xfa0, 0x2b67) and ordinary values below 0x7d0 (so this[0x2ee + 4 * key] stays in the
0x2400-byte object); slot 0xd8 says busy 10% of the time. For key 0x3e8 the text object (this[0x5e2], slot 0x35c) returns a string of 0..0x30 characters; this+0x1e9 is set to the constant string at
0x6a7808 half of the time, by the hook of 0x56f7c0 (which otherwise leaves the old random contents). 0x56ef50 logs either its value or, for the stack pointer case, the word it points at; 0x59cb60 logs the
C string it is given; 0x48aad0 logs the two dwords of its local; every other callee is a recording hook; slots 0x9c / 0xd0 are recorded. Return is bool (AL)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _cstr(em, p):
    out = b''
    while len(out) < 0x60:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g56f860(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cst = bytes(e.rbytes(0x6a7808, 40)).split(b'\0')[0] + b'\0'
    text = obj(c, 0x20, {0x35c: pystub(c, 0, this=True, ret=0)})
    n = r.choice([0, 1, 5, 0x1e, 0x1f, 0x20, 0x21, 0x30])
    sp = e.alloc(0x40, 1)
    e.wbytes(sp, bytes(r.choice(b'abcXYZ') for _ in range(n)) + b'\0')
    text = obj(c, 0x20, {0x35c: pystub(c, 0, this=True, ret=sp)})
    me = obj(c, 0x2400, {0xd8: pystub(c, 0, this=True, ret=lambda em, k: 1 if r.random() < 0.1 else r.choice([0, 0x100])),
                         0x9c: pystub(c, 1, this=True), 0xd0: pystub(c, 1, this=True)})
    e.wbytes(me + 0x2ee, r.randbytes(4 * 0x7d0))
    e.w32(me + 0x5e2, text)
    e.wbytes(me + 0x5e2, text.to_bytes(4, 'little'))
    e.w32(me + 0x94, rnd(c, 0x20))
    e.wbytes(me + 0x1c1, r.randbytes(4))
    if r.random() < 0.5:
        e.wbytes(me + 0x1e9, cst)

    def h7c0(em, res_):
        v = em.reg('ecx')
        em.calllog.append(('f7c0', v))
        if r.random() < 0.5:
            em.wbytes(v + 0x1e9, cst)
        em.ret(eax=0, argbytes=0)
    e.hook(0x56f7c0, h7c0)

    key = r.choice([0x31, 0x32, 0x3e8, 0x3e8, 0x7d0, 0xfa0, 0x2b67, r.randrange(0, 0x7d0), r.randrange(0, 0x7d0)])

    def h56ef50(em, res_):
        a = em.arg32(0)
        em.calllog.append(('ef50', em.reg('ecx'), ('w', em.r32(a) & 0xffffffff) if key == 0x32 else ('v', a)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x56ef50, h56ef50)

    def h59(em, res_):
        em.calllog.append(('cb60', em.reg('ecx'), _cstr(em, em.arg32(0))))
        em.ret(eax=0, argbytes=4)
    e.hook(0x59cb60, h59)

    def h48(em, res_):
        v = em.reg('ecx')
        em.calllog.append(('48aad0', em.r32(v), em.r32(v + 4)))
        em.ret(eax=r.getrandbits(32), argbytes=0)
    e.hook(0x48aad0, h48)
    hook_rec(c, 0x562c20, 1, this=True, pop=4)
    hook_rec(c, 0x56fc20, 0, this=True)
    hook_rec(c, 0x563500, 0, this=True)
    hook_rec(c, 0x561be0, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))
    sysobj(c, {}, table_slots={0x138: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))})
    return [me, key]


S(0x56f860, 'GUESS key dispatch of text input control', 'thiscall', None, ret='al', gen=_g56f860, note='batch38053')
