"""specs_s34044.py - cascade tier E, batch 34044.
0x427ea0 (stdcall): the five imports ReadFile, GetLastError, FormatMessageA, MessageBoxA and LocalFree are Python stubs that log their value arguments into the call log (stack-pointer arguments are not
logged; ReadFile always writes a random count through its pointer and returns 0/1; FormatMessageA writes a heap message pointer through its output slot); the logger object at 0x700390 is set.
0x453130: byte +0x5a zero in a third; the iterator object at the unaligned +0x52 null in a seventh; slots 0x4c / 0x5c (stack iterator, 0..3 ids), engine table slot 0x58 (null object in a quarter) and the
objects' slot 0x228 are recorders.
0x45a3f0: the iterator object at +0x5c is never null (the original dereferences it unconditionally at the end); objects have slot 0x210 (1 arg); the final slot 0xc is a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g427ea0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def readfile(em, res_):
        em.calllog.append(('ReadFile', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(4)))
        em.w32(em.arg32(3), r.getrandbits(32))
        em.ret(eax=r.choice([0, 1, 1]), argbytes=20)

    def getlasterror(em, res_):
        em.calllog.append(('GetLastError',))
        em.ret(eax=r.getrandbits(32), argbytes=0)
    msgbuf = rnd(c, 0x40)

    def formatmessage(em, res_):
        em.calllog.append(('FormatMessageA', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(5), em.arg32(6)))
        em.w32(em.arg32(4), msgbuf)
        em.ret(eax=r.getrandbits(32), argbytes=28)

    def messagebox(em, res_):
        em.calllog.append(('MessageBoxA', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=r.getrandbits(32), argbytes=16)

    def localfree(em, res_):
        em.calllog.append(('LocalFree', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    e.stub_import('ReadFile', readfile)
    e.stub_import('GetLastError', getlasterror)
    e.stub_import('FormatMessageA', formatmessage)
    e.stub_import('MessageBoxA', messagebox)
    e.stub_import('LocalFree', localfree)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x40 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [r.getrandbits(32), rnd(c, 0x40), r.choice([0, 1, 0x20, r.getrandbits(32)])]


def _iter_obj(c, slots_extra=None):
    r = c.rng
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    return obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                         0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32)),
                         **(slots_extra or {})}, nslots=0x60 // 4)


def _g453130(c):
    clear_hooks(c)
    r = c.rng
    m = 0 if r.random() < 1 / 7 else _iter_obj(c)
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0x228: pystub(c, 0, this=True)}, nslots=0x230 // 4) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 3)], this=True)})
    me = rnd(c, 0x70)
    c.emu.wbytes(me + 0x52, m.to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x5a, bytes([0 if r.random() < 1 / 3 else r.randrange(1, 256)]))
    return [me]


def _g45a3f0(c):
    clear_hooks(c)
    r = c.rng
    m = _iter_obj(c, {0xc: pystub(c, 0, this=True)})
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0x210: pystub(c, 1, this=True)}, nslots=0x220 // 4) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 3)], this=True)})
    me = rnd(c, 0x70)
    c.emu.w32(me + 0x5c, m)
    return [me]


S(0x427ea0, 'GUESS checked ReadFile with error dialog', 'stdcall', None, ret='eax', gen=_g427ea0, note='batch34044')
S(0x453130, 'GUESS poke every object of an id list once flagged', 'thiscall', None, ret=None, gen=_g453130, note='batch34044')
S(0x45a3f0, 'GUESS close every object of an id list then notify', 'thiscall', None, ret=None, gen=_g45a3f0, note='batch34044')
