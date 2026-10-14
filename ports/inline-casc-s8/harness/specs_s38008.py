"""specs_s38008.py - cascade s8 batch 38008: 0x4205f0 (teardown). Owner object with recording vtable (slots 0x1d0, 0x4c, 0x3c, 0x20, plus a list node chain at +0x190f,
held objects at the odd-offset fields and the two globals, buffer at +0x1b4d, embedded container at +0x2191 whose slot 0x14 reports more a few times). 0x4317a0 /
0x634273 / 0x423440 hooked; engine and logger objects are stubs. Held objects are null about 30% of the time."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4205f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def held():
        return 0 if r.random() < 0.3 else obj(c, 0x20, {0x10: pystub(c, 0, this=True)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st2, argbytes=8)
    st2 = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)})
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    sysobj(c, {0x14: pystub(c, 0, this=True), 0x10: pystub(c, 0, this=True)})
    e.w32(0x7003a8, held())
    e.w32(0x7003a4, held())
    nmore = r.choice([0, 1, 2, 3])
    sub_vt = {0x14: pystub(c, 0, this=True, ret=lambda em, k: 1 if k < nmore else 0),
              0x30: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}
    vtm = e.alloc(0x2c0, 4)
    for off, code in sub_vt.items():
        e.w32(vtm + off, code)
    slots = {0x1d0: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True), 0x3c: pystub(c, 0, this=True),
             0x20: pystub(c, 1, this=True)}
    me = obj(c, 0x2300, slots)
    for off in (0x1aa7, 0x1a9f, 0x1aa3, 0x223d):
        e.wbytes(me + off, held().to_bytes(4, 'little'))
    e.wbytes(me + 0x9b, (0 if r.random() < 0.3 else obj(c, 0x20, {0x128: pystub(c, 0, this=True)})).to_bytes(4, 'little'))
    e.wbytes(me + 0x1b4d, (0 if r.random() < 0.3 else rnd(c, 0x20)).to_bytes(4, 'little'))
    e.w32(me + 0x2191, vtm)
    # build a real chain
    head = 0
    for _ in range(r.choice([0, 0, 1, 2, 3])):
        n = obj(c, 0x20, {0x2c: pystub(c, 0, this=True)})
        e.w32(n + 8, head)
        head = n
    e.wbytes(me + 0x190f, head.to_bytes(4, 'little'))
    hook_rec(c, 0x4317a0, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x423440, 0, this=True)
    return [me]


S(0x4205f0, 'GUESS teardown of owned sub-objects', 'thiscall', None, ret=None, gen=_g4205f0, note='batch38008')
