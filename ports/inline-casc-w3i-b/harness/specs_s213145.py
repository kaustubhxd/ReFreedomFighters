"""specs_s213145.py - batch 213145: entity state setter by this[0x188] name and argument (jump table, formatted name, assert hook), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5672c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def ah(em, res_):
        em.calllog.append(('assert',))
        em.ret(eax=rb())
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    # logger: slot 0x20 -> M, M slot 0x2c is cdecl with ecx = M's vtable
    def mh(em, res_):
        em.calllog.append(('mlog', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('mlog', mh)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    busy = r.random() < 0.15
    X = obj(c, 0x20, {0xb0: pystub(c, 0, ret=lambda emu, k: (rb() & ~0xff) | (1 if busy else 0), this=True)}, nslots=0x40)

    def fmth(em, res_):
        Y_, buf, fm, v = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        em.calllog.append(('fmt', em.reg('ecx'), Y_, fm, v))
        em.wbytes(buf, b'N%08x' % v + b'\0' * 10)
        em.ret(eax=0, argbytes=0)
    Y = obj(c, 0x20, {0x198: e.stub_fn('fmt', fmth)}, nslots=0x70)
    Q = obj(c, 0x20, {0x5c: pystub(c, 3, this=True, side=lambda emu, k: emu.calllog.append(('q5c', bytes(emu.rbytes(emu.arg32(0), 16)), emu.arg32(1), emu.arg32(2))), stackmark=(0,))}, nslots=0x40)
    ent_obj = rnd(c, 0x1000)
    ent = rnd(c, 0x40)
    found = r.random() < 0.8

    def t58(emu, k):
        emu.calllog.append(('t58', emu.arg32(0)))
        return ent if found else 0

    def pair_log(emu, k):
        p = emu.reg('ecx')
        emu.calllog.append(('pair', bytes(emu.rbytes(p, 8))))
    T = obj(c, 0x20, {0x134: pystub(c, 0, ret=Q, this=True), 0x138: pystub(c, 0, ret=lambda emu, k: rb(), this=True),
                      0x58: pystub(c, 1, ret=t58, this=True)}, nslots=0x60)
    # pair_log hook: the pair is on the stack, so log its contents
    hook_rec(c, 0x48aad0, 0, pop=0, this='mark', ret=lambda emu, k: rb(), side=pair_log)
    hook_rec(c, 0x566fa0, 0, pop=0, this=True, ret=ent_obj)
    eng = obj(c, 0x200, {0xbc: pystub(c, 0, ret=X, this=True), 0x190: pystub(c, 0, ret=Y, this=True)}, nslots=0x70)
    w32u(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    self_ = rnd(c, 0x200)
    w32u(self_ + 0x188, r.choice([0, 1, 2, 3, 0, 1, 2, 3, 4, rb()]))
    a = r.choice([0, 1, 2, 3, 0, 1, 2, rb(), 0xffffffff])
    return [self_, a]


S(0x5672c0, 'entity_state_set', 'thiscall', None, ret=None, gen=g5672c0, stack_arg_bytes=4)
