"""specs_s66045.py - cascade s4 batch 66045: 0x4273d0 (read a resource through a loader or straight from a file)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4273d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hnd = r.choice([0, 1])
    fok = r.random() < 0.8

    def fopen(em, rr):
        em.calllog.append(('fopen', em.arg32(0), em.arg32(1), bytes(em.rbytes(em.arg32(1), 3))))
        em.ret(eax=0x7777 if fok else 0, argbytes=0)

    def fseek(em, rr):
        em.calllog.append(('fseek', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)

    def fread(em, rr):
        em.calllog.append(('fread', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=r.choice([0, 5, 77]), argbytes=0)

    def fclose(em, rr):
        em.calllog.append(('fclose', em.arg32(0)))
        em.ret(eax=0, argbytes=0)
    e.stub_import('fopen', fopen)
    e.stub_import('fseek', fseek)
    e.stub_import('fread', fread)
    e.stub_import('fclose', fclose)
    o = obj(c, 0x30, {0x1c: pystub(c, 4, this=True, ret=lambda em, k: r.choice([0xffffffff, 0, 9]))})
    x = r.choice([0, rnd(c, 8)])
    t = obj(c, 0x30, {0x130: pystub(c, 1, this=True, ret=r.getrandbits(32)),
                      0x70: pystub(c, 1, this=True, ret=r.choice([o, 0])),
                      8: pystub(c, 1, this=True, ret=x),
                      0x40: pystub(c, 3, this=True, ret=r.getrandbits(32)),
                      0x1c: pystub(c, 1, this=True)})
    return [t, rnd(c, 8), rnd(c, 8), r.choice([0, 4, 100]), r.choice([0, 0, 16, 0x1000]), r.choice([0, 0, 1])]


S(0x4273d0, 'GUESS read a resource through a loader or from a file', 'thiscall', None, ret='eax', gen=_g4273d0, note='batch66045')
