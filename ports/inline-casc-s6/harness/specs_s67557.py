"""specs_s67557.py - cascade s6 batch 67557 (0x506960, thiscall(req) ret 4, no return value). 0x5003d0 (hook) returns the id node; the object table slot 0x58 maps it to an object (or 0, logged through the
logger at 0x700390: slot 0x20 -> object with cdecl slot 0x30, 3 args, and this[0x18] slot 0x20 giving a name block). The object's slot 0x80 writes a 12-dword matrix and a 3-dword vector into stack locals
(stack-marked pointers, contents logged by the consumers), slot 0x1e0 answers per call; 0x5094c0 / 0x4daf90 / 0x4419f0 / 0x441940 are hooks that log contents and rewrite their output."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g506960(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def lg30(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    x = obj(c, 0x20, {0x30: e.stub_fn('recorder', lg30)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=x)}))
    name = rnd(c, 0x10)
    owner = obj(c, 0x40, {0x20: pystub(c, 0, this=True, ret=name),
                          0x370: pystub(c, 2, this=True, deref={0: 12, 1: 3})})

    def s80(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(48)))
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(12)))
    child = rnd(c, 0x20)
    o = obj(c, 0x40, {0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=s80),
                      0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))})
    e.w32(o + 8, child)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice([o, o, o, 0]))})
    n1 = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=n1)
    hook_rec(c, 0x5094c0, 3, this=True, deref={1: 12, 2: 3}, ret=0)

    def d4daf90(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
    hook_rec(c, 0x4daf90, 1, this=True, stackmark=(0,), side=d4daf90)

    def f4419f0(em, res_):
        v, m = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('4419f0', em.rbytes(v, 12), em.rbytes(m, 48)))
        em.wbytes(v, bytes((b ^ 0x3c) for b in em.rbytes(v, 12)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x4419f0, f4419f0)

    def f441940(em, res_):
        v, w = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('441940', em.rbytes(v, 12), em.rbytes(w, 12)))
        em.wbytes(v, bytes((a + b) & 0xff for a, b in zip(em.rbytes(v, 12), em.rbytes(w, 12))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x441940, f441940)
    t = rnd(c, 0x40)
    e.w32(t + 0x18, owner)
    return [t, rnd(c, 0x20)]


S(0x506960, 'GUESS push_object_transform', 'thiscall', None, ret=None, gen=_g506960, note='batch67557')
