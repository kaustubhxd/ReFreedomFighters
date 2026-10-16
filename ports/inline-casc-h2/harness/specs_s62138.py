from pilot import S
from recruits_util import clear_hooks

def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng

    def helper(em, ret):
        em.calllog.append(('H534100', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=ret, argbytes=4)
    helper_ret = r.getrandbits(32)
    e.hook(0x534100, lambda em, _result: helper(em, helper_ret))

    def cb44(em, ret):
        em.calllog.append(('V44', em.reg('ecx'), em.arg32(0)))
        em.ret(argbytes=4)
    def cb3c(em, ret):
        em.calllog.append(('V3c', em.reg('ecx'), em.arg32(0)))
        em.ret(argbytes=4)
    vt = e.fake_vtable('vt5348e0', 0x80, {0x44: cb44, 0x3c: cb3c})
    o = e.alloc(0x40, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(o, vt)
    self = e.alloc(0x400, 4)
    e.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x400)))
    index = r.randint(0, 3)
    if index:
        nodes = r.randint(1, 3)
        for k in range(nodes):
            idx = index + k
            nxt = idx + 1 if k + 1 < nodes else 0x80000000
            e.w32(self + (idx + 1) * 8, r.getrandbits(32))
            e.w32(self + (idx + 1) * 8 + 4, nxt)
    return [self, o, index]

S(0x5348e0, 'GUESS list_walk_with_callbacks', 'thiscall', None, ret=None, gen=gen, note='batch62138')
